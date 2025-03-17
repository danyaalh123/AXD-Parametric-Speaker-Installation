/*
  40kHz Parametric Speaker on Arduino Mega (16MHz)
  - Timer1 => ~40kHz Fast PWM on pin 11 (OC1A).
  - Read audio samples (8-bit, 0..255) from Serial at ~8kHz.
  - On every 5th Timer1 interrupt (40kHz/5 = 8kHz), set OCR1A => amplitude modulate.
  - volumeScale adjusts max duty cycle.

  Baud rate = 1,000,000
  Ring buffer size = 2048
*/

#include <Arduino.h>

// Simple LED blink pin
#define LED_PIN      13

// -- PWM/Timer1 settings --
#define CARRIER_FREQ  40000       // 40 kHz
#define TIMER1_TOP    399         // 16MHz / 400 = 40kHz
#define SAMPLE_RATE   8000        // 8 kHz audio
const uint8_t skipFactor = (CARRIER_FREQ / SAMPLE_RATE);

// "Volume" factor in [0..1], e.g. 1.0 = 100% duty possible
float volumeScale = 0.70;

// -- Larger ring buffer for serial data --
#define AUDIO_BUFFER_SIZE 2048
volatile uint8_t audioBuffer[AUDIO_BUFFER_SIZE];
volatile uint16_t writeIndex = 0;
volatile uint16_t readIndex = 0;

inline bool bufferIsEmpty() {
  return (writeIndex == readIndex);
}
inline bool bufferIsFull() {
  return ((writeIndex + 1) % AUDIO_BUFFER_SIZE == readIndex);
}

// Timer1 Overflow ISR @ ~40kHz
ISR(TIMER1_OVF_vect)
{
  static uint8_t skipCount = 0;

  // Grab a new sample every 'skipFactor' passes => 8kHz
  if (++skipCount >= skipFactor) {
    skipCount = 0;

    // Default to mid-level (128) if no data available
    uint8_t sample = 128;
    if (!bufferIsEmpty()) {
      sample = audioBuffer[readIndex];
      readIndex = (readIndex + 1) % AUDIO_BUFFER_SIZE;
    }

    // Map 0..255 => 0..(399 * volumeScale)
    uint16_t dutyMax = (uint16_t)(TIMER1_TOP * volumeScale);
    uint16_t duty = map(sample, 0, 255, 0, dutyMax);
    OCR1A = duty;
  }
}

void setup()
{
  pinMode(11, OUTPUT);   // Timer1 OC1A pin
  pinMode(LED_PIN, OUTPUT);

  // Configure Timer1 for 40kHz Fast PWM, top=ICR1
  TCCR1A = 0;
  TCCR1B = 0;
  ICR1 = TIMER1_TOP; // 399 => 40 kHz
  // Non-inverting PWM on OC1A, Fast PWM mode 14
  TCCR1A = (1 << COM1A1) | (1 << WGM11);
  // No prescale, WGM13/12=1 => top=ICR1
  TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS10);

  OCR1A = 0;             // start at 0% duty
  TIMSK1 = (1 << TOIE1); // enable Timer1 overflow interrupt

  // Start Serial at 1,000,000 baud
  Serial.begin(1000000);
}

void loop()
{
  // Read incoming bytes into the ring buffer
  while (Serial.available() > 0 && !bufferIsFull()) {
    uint8_t incoming = (uint8_t)Serial.read();
    audioBuffer[writeIndex] = incoming;
    writeIndex = (writeIndex + 1) % AUDIO_BUFFER_SIZE;
  }

  // Blink LED every 500 ms so we know it's running
  static unsigned long lastBlink = 0;
  if (millis() - lastBlink >= 500) {
    lastBlink = millis();
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  }
}
