/*
  Ultrasonic Parametric Speaker for Arduino Mega

  This sketch generates a 40kHz PWM signal on Timer1 (pins 11 & 12)
  and modulates its duty cycle based on the analog input from A0 using
  modulation with an Exponential Moving Average (EMA) filter to reduce noise.

  In this method, the ADC reading (0-1023) is first smoothed using EMA, then
  mapped directly to the PWM duty cycle range (0 to PWM_OVERFLOW).

  The PWM carrier is generated using Timer1 in Fast PWM mode (mode 14)
  with ICR1 set to 399, yielding a 40kHz frequency.
*/

#include <Arduino.h>

#define PWM_OVERFLOW 399           // ICR1 value for 40kHz PWM

// Smoothing factor for the EMA (0.0 to 1.0). Lower values give more smoothing.
const float alpha = 0.8;
const float adc_scaling = 1.1;

// Global variables for debugging and filtering
volatile uint16_t adcVal = 0;      // Last ADC reading for debugging
volatile float filteredADC = 0.0;  // Filtered ADC value

// ADC Conversion Complete Interrupt Service Routine
ISR(ADC_vect) {
  uint16_t reading = ADC*adc_scaling;  // Get ADC reading (0-1023)
  
  // Apply Exponential Moving Average (EMA) filter:
  // filteredADC = filteredADC + alpha * (new_reading - filteredADC)
  filteredADC = filteredADC + alpha * (reading - filteredADC);
  
  // Map the filtered ADC value directly to the PWM duty cycle range (0 to PWM_OVERFLOW)
  // then subtract 1 to adjust the duty cycle.
  int16_t newDuty = map((uint16_t)filteredADC, 0, 1023, 0, PWM_OVERFLOW) - 1;
  
  // Clamp newDuty to the valid range [0, PWM_OVERFLOW]
  if (newDuty < 0)
    newDuty = 0;
  if (newDuty > PWM_OVERFLOW)
    newDuty = PWM_OVERFLOW;
    
  // Update PWM duty cycle on both channels (pins 11 and 12)
  OCR1A = newDuty;
  OCR1B = newDuty;
  
  adcVal = reading;  // Save raw ADC reading for debugging (optional)
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
}

void loop() {
  // The loop is empty because all modulation happens in the ADC ISR.
}
