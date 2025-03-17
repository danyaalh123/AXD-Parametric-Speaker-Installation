## Parametric Speaker Theory

Our project employs parametric speakers, which generate audible sound through the propagation and nonlinear interaction of ultrasonic waves in the air. Unlike conventional loudspeakers that emit sound directly at audible frequencies, parametric speakers produce highly directional, high-intensity ultrasonic carrier waves. As these waves travel through the air, they interact and generate new frequency components within the audible range through a process known as self-demodulation, first described theoretically by Westervelt (1963). This approach enables precise directional audio effects, enabling our spatial audio installation and interactive demonstration.

### Nonlinear Acoustic Interaction and Self-Demodulation

![547940_1_En_149_Fig3_HTML](https://github.com/user-attachments/assets/3bb31134-12c0-4027-996b-f3619409e6de)

The nonlinear interaction that facilitates parametric audio generation arises due to variations in air density and pressure caused by high-intensity ultrasonic waves. According to Westervelt’s equation, the acoustic pressure of an amplitude-modulated ultrasonic carrier wave can be described mathematically as:  

$p(t) = p_0 \cdot [1 + m(t)] \cdot \sin(\omega_c t)$  

where $p_0$ is the amplitude of the ultrasonic carrier, $m(t)$ is the modulating audio signal normalized within ±1, and $\omega_c$ is the angular frequency of the ultrasonic carrier. Nonlinear propagation in air can be modeled using the Khokhlov–Zabolotskaya–Kuznetsov (KZK) equation, which includes diffraction, absorption, and nonlinear effects. The nonlinear term in the KZK equation is primarily responsible for generating audible sound by converting ultrasonic energy into lower-frequency audible sound through self-demodulation:  

$\frac{\partial^2 p}{\partial z \partial \tau} = \frac{\beta}{2\rho_0 c_0^3} \frac{\partial^2 p^2}{\partial \tau^2}$  

where $p$ is the pressure wave amplitude, $z$ is the propagation distance, $\tau$ is the retarded time, $\beta$ is the coefficient of nonlinearity, $\rho_0$ is the ambient air density, and $c_0$ is the speed of sound in air.

### PWM Modulation

In our project, Pulse Width Modulation (PWM) was utilised to modulate the ultrasonic carrier signal at a frequency of 40 kHz. PWM modulation is a technique used to control power delivered to electronic loads by rapidly switching a signal between on (high) and off (low) states, with the proportion of the cycle spent in the high state known as the duty cycle.

Audio signals were sampled through an analog-to-digital converter (ADC) within the Arduino Mega. The digital values obtained from the ADC (ranging from 0 to 1023) directly modulated the duty cycle of the PWM signal. This dynamic modulation varied the amplitude of the ultrasonic carrier wave, encoding audio information onto the ultrasonic carrier.

By continuously adjusting the duty cycle based on the ADC values, the amplitude-modulated ultrasonic wave produced audible sound through nonlinear acoustic interactions in air, achieving precise directional audio.

### Directional Sound Beam Formation

The directivity of a parametric speaker is substantially greater than conventional audio speakers because the size of the ultrasonic transducer array is significantly larger than the ultrasonic wavelengths emitted. The directivity $D(\theta)$ of a planar ultrasonic transducer array is approximated by:  

$D(\theta) = \frac{2J_1(ka \sin \theta)}{ka \sin \theta}$  

where $J_1$ is the first-order Bessel function, $k$ is the wavenumber, $a$ is the radius of the transducer array, and $\theta$ is the angle off-axis. The resulting beam exhibits pronounced directionality due to constructive interference along the propagation axis, with destructive interference minimizing the sound off-axis. This high directivity results from the ratio of the array size to the wavelength, forming a coherent directional beam.

### Carrier Frequency (40 kHz)

We chose a 40 kHz ultrasonic carrier frequency as it strikes a balance between directionality and atmospheric absorption. At this frequency, the short wavelengths (approximately 8.5 mm) enable a highly directional emission pattern. While higher frequencies offer even greater directivity due to their shorter wavelengths, they also suffer from increased atmospheric absorption, reducing their effective range and efficiency. By contrast, 40 kHz provides a practical compromise, maintaining strong directivity while keeping ultrasonic absorption manageable. Additionally, 40 kHz transducers are widely available and cost-effective, making them an accessible choice for our application.

### References

- Westervelt, P. J. (1963). "Parametric Acoustic Array," *Journal of the Acoustical Society of America*.
- Pompei, F. J. (2002). "Sound from Ultrasound: The Parametric Array as an Audible Sound Source," *MIT Dissertation*.
