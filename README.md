# AXD Ultrasonic Parametric Speaker for Spatialised Audio Installation

### Abstract
This repository details the design and prototyping of an ultrasonic parametric speaker array utilising amplitude modulation of a 40 kHz carrier frequency driven by Arduino, with an emphasis on spatial audio applications. Two parametric speaker arrays positioned at slight angles leverage ultrasonic directionality, enabling precise left-right audio panning without widely spaced conventional speakers. This approach creates an immersive spatial audio experience suitable for specialised directional sound applications.

### Introduction
Parametric speakers utilise ultrasonic frequencies to create highly directional audio through nonlinear acoustic interactions. While ultrasonic frequencies themselves are inaudible, they become audible when amplitude-modulated and propagated through air, resulting in directional audible sound. The directionality and spatial precision of parametric speakers offer unique opportunities for spatial audio applications. This project aimed to design, prototype, and evaluate an ultrasonic parametric speaker system driven by an Arduino Mega, specifically focusing on achieving precise spatialised audio by angling two ultrasonic arrays to simulate traditional stereo and panning effects within a compact form factor.

### Initial Plan
The initial concept involved creating an informative installation featuring directional speakers positioned at different locations, narrating various sections of the display. Upon further consideration, the team determined that an interactive spatialised audio demonstration would offer a more engaging and effective user experience. So we changed the direction of our installation while keeping the majority of the project the same. 

In the plan, Danyaal Husain was responsible for electronic circuitry, while Edward Isola focused on building the physical interface, with both collaborating on MAX audio modulation.

[View Initial Plan](AXD-InstallationInitialPlan.pdf) 

### Discussion of Spatial Audio Implementation
By positioning two parametric speaker arrays at a slight angle, the system exploits inherent ultrasonic directionality to create distinct left-right spatial audio effects. By independently modulating each speaker array's ultrasonic carrier amplitude, directional control is precisely managed, allowing realistic stereo imaging without physical separation. This method achieves immersive spatial audio efficiently and compactly, suitable for various applications ranging from targeted advertising to personal listening environments.

### Work Overview and Distribution
The project involved multiple stages, including hardware prototyping, software development, and the creation of an interactive spatialised audio demonstration:

#### Hardware Prototyping - Completed by Danyaal Hussain
- An initial amplifier and driver circuit was designed and prototyped on a breadboard, with a final robust implementation fabricated using stripboard.

#### Software Development - Completed by Danyaal Hussain
- Arduino firmware was written to dynamically modulate PWM signals based on ADC readings from analogue audio inputs, driving the parametric speaker arrays.
- A MAX patch was developed, including a crossover network designed to optimise the audio frequency band for the ultrasonic arrays.

#### Interactive Demonstration - Completed by Edward Isola
- A MAX patch was created for an interactive demonstration utilising amplitude panning to enable users to experience real-time spatial audio control. Users could dynamically pan audio signals, clearly and interactively demonstrating the directional capabilities of the parametric speakers.

### Future Project Applications
The inherent directionality and compactness of parametric speakers offer significant potential for advanced spatial audio systems. Future developments could include:

- **Surround Sound Applications**: Implementing multiple parametric arrays strategically placed to reflect sound off walls or ceilings, creating immersive surround sound environments without conventional speaker placement constraints.
- **Adaptive Beam Steering**: Dynamic adjustment of audio beam directions through phased array techniques, enabling personalised or adaptive listening experiences.
- **Interactive and Immersive Audio Zones**: Creating spatially controlled audio zones for museum exhibits, advertisements, or interactive installations within public spaces.

### Reflection and Conclusion
This project successfully demonstrated an ultrasonic parametric speaker array capable of directional audio, achieving spatialised sound without requiring physically distant speaker placement. Despite altering the application's concept from informational to interactive, the project proceeded as planned, with task distribution remaining the same as outlined in the plan.

Moving forward, further refinements in hardware efficiency, audio quality, and software processing techniques could expand the practical applications and versatility of ultrasonic parametric speakers across personal and commercial environments.
