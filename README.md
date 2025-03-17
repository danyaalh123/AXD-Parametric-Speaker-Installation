# AXD Ultrasonic Parametric Speaker For Spacialised Audio Installation

### Abstract
This repository outlines the design, prototyping, and implementation of an ultrasonic parametric speaker array utilizing amplitude modulation of a 40 kHz carrier frequency driven by Arduino. The designed system accepts audio input signals, performs necessary signal conditioning and amplification, and employs pulse-width modulation (PWM) techniques to modulate an ultrasonic carrier, driving an array of ultrasonic transducers. Various filtering and signal processing methods were evaluated for improving audio quality, with the fundamental direct mapping of ADC readings found to provide optimal performance given the hardware constraints.

### Introduction
Parametric speakers leverage ultrasonic frequencies to create directional audio through nonlinear acoustic interactions. The ultrasonic frequencies themselves are inaudible but can create audible frequencies through amplitude modulation. This results in precise spatial audio control with minimal spillover. The project aimed to design, prototype, and evaluate an ultrasonic parametric speaker system driven by a microcontroller-based architecture (Arduino Mega), focusing on modulation strategies and audio preprocessing techniques to maximize sound quality and clarity.

### Discussion and Conclusion
This ultrasonic parametric speaker effectively demonstrated highly directional audio generation through ultrasonic PWM modulation. Limitations imposed by hardware necessitated straightforward ADC-to-PWM mapping over more advanced filtering methods. Future implementations could incorporate more powerful DSP hardware for enhanced audio quality.

### References
- Westervelt, P. J. (1963). "Parametric Acoustic Array," Journal of the Acoustical Society of America.
- Pompei, F. J. (2002). "Sound from Ultrasound: The Parametric Array as an Audible Sound Source," MIT Dissertation.

