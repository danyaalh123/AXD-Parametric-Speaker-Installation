/*
  Ultrasonic Parametric Array Driver for Arduino Mega

  This sketch generates a 40kHz PWM signal on Timer1 (pins 11 & 12)
  and modulates its duty cycle based on the analog input.
  
  In this method, the ADC reading (0-1023) is mapped directly to the PWM duty
  cycle range (0 to PWM_OVERFLOW). 

  The PWM carrier is generated using Timer1 in Fast PWM mode (mode 14)
  with ICR1 set to 399, yielding a 40kHz frequency.
*/

#include <Arduino.h>

#define PWM_OVERFLOW 399           // ICR1 value for 40kHz PWM

// Global variable for debugging (last ADC reading)
volatile uint16_t adcVal = 0;

// ADC Conversion Complete Interrupt Service Routine
ISR(ADC_vect) {
  uint16_t reading = ADC;  // Get ADC reading (0-1023)
  
  // Modulation:
  // Map the ADC value (0 to 1023) directly to the PWM duty cycle range (0 to PWM_OVERFLOW)
  // then subtract 1 to adjust the duty cycle.
  int16_t newDuty = map(reading, 0, 1023, 0, PWM_OVERFLOW);
  newDuty = newDuty - 1;
  
  // Clamp newDuty to the valid range [0, PWM_OVERFLOW]
  if (newDuty < 0)
    newDuty = 0;
  if (newDuty > PWM_OVERFLOW)
    newDuty = PWM_OVERFLOW;
    
  // Update PWM duty cycle on both channels (pins 11 and 12)
  OCR1A = newDuty;
  OCR1B = newDuty;
  
  adcVal = reading;  // Save ADC reading for debugging (optional)
}

// Setup Timer1 for 40kHz PWM output on pins 11 (OC1A) and 12 (OC1B)
void setupTimer1PWM() {
  // Set PWM output pins as outputs
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  
  // Stop Timer1 before configuring
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  
  // Configure Timer1 for Fast PWM, mode 14 (WGM13:0 = 14, using ICR1 as TOP)
  TCCR1A = (1 << WGM11);
  TCCR1B = (1 << WGM13) | (1 << WGM12);
  
  // Set non-inverting mode for OC1A (pin 11)
  TCCR1A |= (1 << COM1A1);
  
  // For OC1B (pin 12), set inverting mode to provide a complementary output
  TCCR1A |= (1 << COM1B1) | (1 << COM1B0);
  
  // Start Timer1 with no prescaler (CS10 = 1)
  TCCR1B |= (1 << CS10);
  
  // Set TOP value for 40kHz PWM frequency
  ICR1 = PWM_OVERFLOW;
  
  // Initialize duty cycle to 50%
  OCR1A = PWM_OVERFLOW / 2;
  OCR1B = PWM_OVERFLOW / 2;
}

// Setup the ADC in free running mode on A0
void setupADC() {
  // Select AVcc as reference and choose channel A0 (MUX[3:0]=0)
  ADMUX = (1 << REFS0);
  
  // Enable ADC, Auto Trigger, and ADC Interrupt
  // Set prescaler to 128 for a 125kHz ADC clock (~9.6kHz sampling rate)
  ADCSRA = (1 << ADEN) | (1 << ADATE) | (1 << ADIE)
         | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
  
  // Start the first conversion; subsequent conversions will start automatically.
  ADCSRA |= (1 << ADSC);
}

void setup() {
  cli();              // Disable interrupts during setup
  setupTimer1PWM();   // Configure Timer1 for ultrasonic PWM
  setupADC();         // Configure the ADC for free running mode
  sei();              // Re-enable interrupts
  
  Serial.begin(115200); // For debugging
}

void loop() {
  // Print the last ADC reading every 100ms for debugging.
  static unsigned long lastPrintTime = 0;
  if (millis() - lastPrintTime > 100) {
    lastPrintTime = millis();
    Serial.println(adcVal);
  }
}
