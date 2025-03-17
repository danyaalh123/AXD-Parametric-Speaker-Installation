## System Design

#### Hardware Configuration
The system comprises:

1. **Input Audio Signal Conditioning**:
   - Audio signals are AC-coupled to remove DC offset and biased at 2.5 V, aligning with Arduino’s ADC input range.
   - Operational amplifier (LM358) boosts audio signal level to optimize ADC resolution.

2. **Microcontroller PWM Modulation**:
   - Arduino Mega samples audio using a 10-bit ADC at approximately 9.6 kHz.
   - Timer1 generates a stable 40 kHz PWM carrier whose duty cycle is modulated by ADC readings.

3. **Ultrasonic Transducer Array**:
   - An array of ten 40 kHz ultrasonic transducers driven by the PWM-modulated signal.

### Initial Digital Sampling Approach
Initially, audio signals were captured digitally via a Python script running PyAudio at a sampling rate of 44.1 kHz. Signals were then downsampled to 8 kHz using polyphase filtering to minimize aliasing and transmitted over serial communication to the Arduino. This method introduced noticeable latency and complexity, limiting real-time responsiveness and audio clarity.

### Optimized Analog Sampling Approach
Transitioning to direct analog sampling via Arduino's ADC improved system latency and audio responsiveness significantly. ADC readings directly controlled PWM modulation, simplifying signal flow and maximizing system efficiency.

### ADC and Signal Processing
The Nyquist-Shannon sampling theorem was applied, ensuring a sampling frequency at least twice the highest audible frequency intended for reproduction. Sampling at 9.6 kHz provided a theoretical bandwidth sufficient for clear speech and moderate-quality audio reproduction.

Advanced filtering methods tested include exponential moving average (EMA), moving average, median, and FIR filters. However, direct ADC-to-PWM mapping offered superior performance by minimizing latency and processing load, essential given the limited computational resources of the Arduino.

### Prototyping and Implementation
Prototypes were built on breadboards initially for flexibility, then finalized on stripboards for robustness. KiCad was used for schematic design and documentation.
