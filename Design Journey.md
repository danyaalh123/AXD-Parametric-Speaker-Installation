## Design Journey

![IMG_5583-2-2](https://github.com/user-attachments/assets/22096e95-4d62-4635-a6c1-b8ef8e7a7f68)

#### Hardware Overview:

1. **Input Audio Signal Conditioning**:
   - Audio signals are AC-coupled to remove DC offset and biased at 2.5 V, aligning with Arduino’s ADC input range.
   - Operational amplifier (LM358) boosts audio signal level to optimize ADC resolution.

2. **Microcontroller PWM Modulation**:
   - Arduino Mega samples audio using a 10-bit ADC at approximately 9.6 kHz.
   - A stable 40 kHz PWM carrier signal is generated for each transducer array where the duty cycles are modulated by ADC readings.

3. **Ultrasonic Transducer Arrays**:
   - Two array of ten 40 kHz ultrasonic transducers driven by the PWM-modulated signal, amplified by TC4427A MOSFET drivers to 15v.

[View Full Circuit Schematic](Hardware/Schematic.pdf) 

### Initial Digital Sampling Approach
Initially, audio signals were captured digitally via a Python script running PyAudio at a sampling rate of 44.1 kHz. Signals were then downsampled to 8 kHz using polyphase filtering to minimize aliasing and transmitted over serial communication to the Arduino.

Although this method provided allowed flexible digital preprocessing, it suffered from latency and performance limitations due to the inherent delay of serial communication and processing overhead on both the computer and the Arduino.

### Analog-to-digital Converter Approach
Transitioning to direct analog sampling via Arduino's ADC improved system latency and audio responsiveness significantly. ADC readings directly controlled PWM modulation, simplifying signal flow and maximizing system efficiency.

The Nyquist-Shannon sampling theorem was applied, ensuring a sampling frequency at least twice the highest audible frequency intended for reproduction. Sampling at 9.6 kHz provided a theoretical bandwidth sufficient for clear speech and moderate-quality audio reproduction. Given the sampling frequency, the Arduino is theoretically capable of accurately capturing audio signals up to approximately 4.8 kHz, sufficient for typical speech and basic audio fidelity. This was used by a lowpass filter in the MAX Crossover to improve quality.

To improve the audio quality and reduce signal noise, advanced filtering methods were tested including exponential moving average (EMA), moving average, median, and FIR filters. After testing these various methods, It was found that whilst they managed to reduce signal noise, they also reduced clarity. In the end direct ADC-to-PWM mapping was used as it offered the best audio quality, while also minimising latency and processing load.

### Prototyping and Implementation
Prototypes were built on breadboards initially for flexibility, then finalized on stripboards for robustness.
