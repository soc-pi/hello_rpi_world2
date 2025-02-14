GPIO PWM Project Overview
This appears to be a Raspberry Pi GPIO PWM control project structured as follows:

Project Structure
Purpose
The project is designed to:

Control Raspberry Pi GPIO pins
Generate PWM (Pulse Width Modulation) signals
Directly access hardware registers without using libraries like WiringPi
Key Features
Uses memory-mapped I/O for direct hardware access
Configurable PWM frequency (currently set to 50Hz)
Adjustable duty cycle control
Runs on various Raspberry Pi models (with different base addresses)
Technical Details
Uses GPIO18 (Physical Pin 12) for PWM output
Direct register manipulation for precise control
PWM Range: 0-1000 (0-100% duty cycle)
Requires root privileges for GPIO access
Build System
Uses CMake for build configuration
Produces a single executable
No external library dependencies
Usage
To build and run the project:

Safety Considerations
Requires careful handling of GPIO pins
Needs proper voltage levels (3.3V max)
Must run with root privileges
Different base addresses for different Raspberry Pi models
Would you like me to elaborate on any specific aspect of the project?
