# AXD-Parametric-Speaker-Installation

## Design and Implementation of an Ultrasonic Parametric Speaker Array

### Abstract
This paper outlines the design, prototyping, and implementation of an ultrasonic parametric speaker array utilizing amplitude modulation of a 40 kHz carrier frequency driven by Arduino. The designed system accepts audio input signals, performs necessary signal conditioning and amplification, and employs pulse-width modulation (PWM) techniques to modulate an ultrasonic carrier, driving an array of ultrasonic transducers. Various filtering and signal processing methods were evaluated for improving audio quality, with the fundamental direct mapping of ADC readings found to provide optimal performance given the hardware constraints.

### Introduction
Parametric speakers leverage ultrasonic frequencies to create directional audio through nonlinear acoustic interactions. The ultrasonic frequencies themselves are inaudible but can create audible frequencies through amplitude modulation. This results in precise spatial audio control with minimal spillover. The project aimed to design, prototype, and evaluate an ultrasonic parametric speaker system driven by a microcontroller-based architecture (Arduino Mega), focusing on modulation strategies and audio preprocessing techniques to maximize sound quality and clarity.

### Theoretical Background
Parametric acoustic arrays operate by exploiting nonlinear acoustic interactions that occur during the propagation of ultrasonic waves through a medium, typically air. Unlike conventional loudspeakers, which directly radiate sound waves at audible frequencies, parametric speakers emit intense, highly directional ultrasonic carrier waves. These waves interact nonlinearly in air, producing new frequency components, some of which fall within the audible range. This phenomenon is known as self-demodulation and was first theoretically described by Westervelt (1963).

#### Nonlinear Acoustic Interaction and Self-Demodulation
The nonlinear interaction that facilitates parametric audio generation arises due to variations in air density and pressure caused by high-intensity ultrasonic waves. According to Westervelt’s equation, the acoustic pressure of an amplitude-modulated ultrasonic carrier wave can be described mathematically as:

\[
p(t) = p_0 \cdot [1 + m(t)] \cdot \sin(\omega_c t)
\]

where \( p_0 \) is the amplitude of the ultrasonic carrier, \( m(t) \) is the modulating audio signal normalized within ±1, and \( \omega_c \) is the angular frequency of the ultrasonic carrier. Nonlinear propagation in air can be modeled using the Khokhlov–Zabolotskaya–Kuznetsov (KZK) equation, which includes diffraction, absorption, and nonlinear effects. The nonlinear term in the KZK equation is primarily responsible for generating audible sound by converting ultrasonic energy into lower-frequency audible sound through self-demodulation:

\[
\frac{\partial^2 p}{\partial z \partial \tau} = \frac{\beta}{2\rho_0 c_0^3} \frac{\partial^2 p^2}{\partial \tau^2}
\]

where \( p \) is the pressure wave amplitude, \( z \) is the propagation distance, \( \tau \) is the retarded time, \( \beta \) is the coefficient of nonlinearity, \( \rho_0 \) is the ambient air density, and \( c_0 \) is the speed of sound in air.

#### Selection of Carrier Frequency (40 kHz)
The ultrasonic carrier frequency selected (40 kHz) optimizes the trade-off between directionality and atmospheric absorption. Frequencies higher than 20 kHz ensure inaudibility, while the relatively short wavelengths (approximately 8.5 mm at 40 kHz) facilitate highly directional emission patterns. Higher frequencies provide improved directionality due to shorter wavelengths but experience significantly greater atmospheric absorption, thus limiting effective range and efficiency. Therefore, 40 kHz is a practical compromise that maintains substantial directivity with manageable ultrasonic absorption, providing a sufficient beam length and audible sound level.

#### Directional Sound Beam Formation
The directivity of a parametric speaker is substantially greater than conventional audio speakers because the size of the ultrasonic transducer array is significantly larger than the ultrasonic wavelengths emitted. The directivity \(D(\theta)\) of a planar ultrasonic transducer array is approximated by:

\[
D(\theta) = \frac{2J_1(ka \sin \theta)}{ka \sin \theta}
\]

where \(J_1\) is the first-order Bessel function, \(k\) is the wavenumber, \(a\) is the radius of the transducer array, and \(\theta\) is the angle off-axis. The resulting beam exhibits pronounced directionality due to constructive interference along the propagation axis, with destructive interference minimizing the sound off-axis. This high directivity results from the ratio of the array size to the wavelength, forming a coherent directional beam that closely resembles a beam of light from a spotlight.

### System Design
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

### Parameter Tuning and Optimization
Iterative optimization addressed bias voltage, PWM frequency accuracy, sampling rate balance, and amplifier gain, ensuring optimal performance and signal integrity.

### Discussion and Conclusion
This ultrasonic parametric speaker effectively demonstrated highly directional audio generation through ultrasonic PWM modulation. Limitations imposed by hardware necessitated straightforward ADC-to-PWM mapping over more advanced filtering methods. Future implementations could incorporate more powerful DSP hardware for enhanced audio quality.

### References
- Westervelt, P. J. (1963). "Parametric Acoustic Array," Journal of the Acoustical Society of America.
- Pompei, F. J. (2002). "Sound from Ultrasound: The Parametric Array as an Audible Sound Source," MIT Dissertation.

