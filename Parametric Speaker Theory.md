## Parametric Speaker Theory

Our project employs parametric speakers, which generate audible sound through the propagation and nonlinear interaction of ultrasonic waves in the air. Unlike conventional loudspeakers that emit sound directly at audible frequencies, parametric speakers produce highly directional, high-intensity ultrasonic carrier waves. As these waves travel through the air, they interact and generate new frequency components within the audible range through a process known as self-demodulation, first described theoretically by Westervelt (1963). This approach enables precise directional audio effects, enabling our spatial audio installation and interactive demonstration.

### Nonlinear Acoustic Interaction and Self-Demodulation

![547940_1_En_149_Fig3_HTML](https://github.com/user-attachments/assets/3bb31134-12c0-4027-996b-f3619409e6de)

The nonlinear interaction that facilitates parametric audio generation arises due to variations in air density and pressure caused by high-intensity ultrasonic waves. According to Westervelt’s equation, the acoustic pressure of an amplitude-modulated ultrasonic carrier wave can be described mathematically as:  

$p(t) = p_0 \cdot [1 + m(t)] \cdot \sin(\omega_c t)$  

where $p_0$ is the amplitude of the ultrasonic carrier, $m(t)$ is the modulating audio signal normalized within ±1, and $\omega_c$ is the angular frequency of the ultrasonic carrier. Nonlinear propagation in air can be modeled using the Khokhlov–Zabolotskaya–Kuznetsov (KZK) equation, which includes diffraction, absorption, and nonlinear effects. The nonlinear term in the KZK equation is primarily responsible for generating audible sound by converting ultrasonic energy into lower-frequency audible sound through self-demodulation:  

$\frac{\partial^2 p}{\partial z \partial \tau} = \frac{\beta}{2\rho_0 c_0^3} \frac{\partial^2 p^2}{\partial \tau^2}$  

where $p$ is the pressure wave amplitude, $z$ is the propagation distance, $\tau$ is the retarded time, $\beta$ is the coefficient of nonlinearity, $\rho_0$ is the ambient air density, and $c_0$ is the speed of sound in air.

### Directional Sound Beam Formation

The directivity of a parametric speaker is substantially greater than conventional audio speakers because the size of the ultrasonic transducer array is significantly larger than the ultrasonic wavelengths emitted. The directivity $D(\theta)$ of a planar ultrasonic transducer array is approximated by:  

$D(\theta) = \frac{2J_1(ka \sin \theta)}{ka \sin \theta}$  

where $J_1$ is the first-order Bessel function, $k$ is the wavenumber, $a$ is the radius of the transducer array, and $\theta$ is the angle off-axis. The resulting beam exhibits pronounced directionality due to constructive interference along the propagation axis, with destructive interference minimizing the sound off-axis. This high directivity results from the ratio of the array size to the wavelength, forming a coherent directional beam.

### Carrier Frequency (40 kHz)

The ultrasonic carrier frequency selected (40 kHz) optimizes the trade-off between directionality and atmospheric absorption. Frequencies higher than 20 kHz ensure inaudibility, while the relatively short wavelengths (approximately 8.5 mm at 40 kHz) facilitate highly directional emission patterns. Higher frequencies provide improved directionality due to shorter wavelengths but experience significantly greater atmospheric absorption, thus limiting effective range and efficiency. Therefore, 40 kHz is a practical compromise that maintains substantial directivity with manageable ultrasonic absorption, providing a sufficient beam length and audible sound level.

### References

- Westervelt, P. J. (1963). "Parametric Acoustic Array," *Journal of the Acoustical Society of America*.
- Pompei, F. J. (2002). "Sound from Ultrasound: The Parametric Array as an Audible Sound Source," *MIT Dissertation*.
