# AXD Ultrasonic Parametric Speaker for Spatialised Audio Installation

![IMG_5585-2](https://github.com/user-attachments/assets/44825533-8027-448e-ba40-734f7b2ee0f4)

### Abstract
This repository details the design and prototyping of an ultrasonic parametric speaker array utilising amplitude modulation of a 40 kHz carrier frequency driven by Arduino, to create and demonstrate directional speakers for spatial audio applications. Two directional parametric speaker arrays were created and positioned at slight angles to enable precise left-right audio panning without the need for widely spaced conventional speakers. This was demonstrated in our interactive spatial audio installation.

### Overview
Parametric speakers utilise ultrasonic frequencies to create highly directional audio through nonlinear acoustic interactions. While ultrasonic frequencies themselves are inaudible, they become audible when amplitude-modulated and propagated through air, resulting in directional audible sound. This project aimed to design, prototype, and evaluate an ultrasonic parametric speaker system driven by an Arduino Mega, specifically focusing on achieving precise spatialised audio by angling two ultrasonic arrays to simulate traditional stereo and panning effects within a compact form factor.

[Explanation of Parametric Speaker Theory](Parametric%20Speaker%20Theory.md) 

[Detailed Design Journey and Process](Design%Journey.md) 

### Initial Plan

The initial concept involved creating an informative installation featuring directional speakers positioned at different locations, narrating various sections of the display. Upon further consideration, the team determined that an interactive spatialised audio demonstration would offer a more engaging and effective user experience. So we changed the direction of our installation while keeping the majority of the project the same. 

[View Initial Plan](AXD-InstallationInitialPlan.pdf) 

In the inital plan, Danyaal Husain was responsible for electronic circuitry, while Edward Isola focused on building the physical interface, with both collaborating on MAX audio modulation. Details on how work was distributed in practice is listed below.

### Spatial Audio Installation

![WhatsApp Image 2025-03-18 at 00 25 50](https://github.com/user-attachments/assets/bbc7f950-0914-40f0-9461-b950306ba9c1)

After successfully designing and fabricating the parametric speakers, we had the idea to use them for spatialised audio. Unlike conventional stereo speakers, which require significant physical separation to achieve spatial effects, our approach utilises the directionality of parametric speakers to create an immersive sound experience within a compact setup.

For our AXD demonstration, we positioned two ultrasonic speaker arrays at a slight angle to each other, allowing controlled panning between left and right channels. By modulating the amplitude of each speaker independently, we could achieve realistic stereo imaging and spatial positioning without crosstalk. This design enables users to experience directional audio without requiring widely spaced speakers, making it a more efficient and interactive solution.

The installation allows participants to manipulate the spatial positioning of audio in real time using a custom MAX interface. This interactive setup enables users to pan sound between the left and right speakers dynamically, providing an intuitive and engaging way to experience spatialised sound. The compact and directional nature of this system opens up new possibilities for immersive audio demonstrations in various applications.

### Work Overview and Distribution
The project involved multiple stages, including hardware prototyping, software development, and the creation of an interactive spatialised audio demonstration, the distribution of work mostly stayed the same as the plan. The different parts of the work are below.

#### Hardware Prototyping - Completed by Danyaal Hussain
- Two ultrasonic transducer arrays were created to produce the directional audio.
- An amplifier and driver circuit was designed, prototyped and tested on a breadboard, with a final robust implementation fabricated using stripboard.

#### Software Development - Completed by Danyaal Hussain
- Arduino code was written to dynamically modulate PWM signals based on ADC readings from analogue audio inputs, driving the parametric speaker arrays.
- A MAX patch was developed, including a crossover network designed to optimise the audio frequency band for the ultrasonic arrays.

#### Interactive Demonstration - Completed by Edward Isola
- A MAX patch was created for an interactive demonstration utilising amplitude panning to enable users to experience real-time spatial audio control. Users could dynamically pan audio signals, clearly and interactively demonstrating the directional capabilities of the parametric speakers.

### Reflection 
Reviewing the project, we highlighted potential limitations, particularly in audio quality and system performance, which provide opportunities for significant improvement.

#### Audio Quality Issues
While the parametric speakers functioned as expected, the overall audio quality was notably poor. The sound was often distorted, lacked clarity, and suffered from low signal strength. These issues can be attributed to several factors, including non-ideal amplitude modulation, limited frequency response, and insufficient power handling of the ultrasonic transducers.

#### Arduino’s Poor ADC Performance
A major limitation of the system is the poor performance of the Arduino Mega’s ADC (Analog-to-Digital Converter). The Arduino Mega's 10-bit ADC with a sampling rate of ~9.6kHz is insufficient for high-fidelity audio processing. This results in low-resolution sampling, noticeable quantization noise, and poor frequency response, contributing to distorted and low-quality sound output. Improvements could be made by upgrading to a more capable microcontroller or using external ADC hardware. By improving the ADC performance, the system could achieve smoother amplitude modulation, reduced noise, and significantly enhanced audio clarity.

#### Future Applications 
Further improvements could expand the practical applications of this technology:
- **Beamforming**: Implementing a phased array system to dynamically steer sound could enable personalized, adaptive listening experiences.
- **Surround Sound Applications**: Implementing multiple parametric arrays strategically placed to reflect sound off walls or ceilings, creating immersive surround sound environments without conventional speaker placement constraints.
- **Interactive and Immersive Audio Zones**: Creating spatially controlled audio zones for museum exhibits, advertisements, or interactive installations within public spaces.

### Conclusion
This project successfully demonstrated the use of ultrasonic parametric speakers for spatialised audio, achieving precise directional sound within a compact setup. Despite limitations in audio quality due to hardware constraints, the system proved effective for our interactive installation. Despite altering the directional speaker application for the installation, the project proceeded as planned, with task distribution remaining similar to what was outlined in the plan.
