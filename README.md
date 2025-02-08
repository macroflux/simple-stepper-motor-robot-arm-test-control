# Stepper Motor Control for Robotic Elbow Joint
![Stepper Motor Robot Arm](https://raw.githubusercontent.com/macroflux/simple-stepper-motor-robot-arm-test-control/main/arduino%20robot%20arm.webp)
## Overview
This Arduino project provides manual and automated control for a stepper motor attached to a robotic elbow joint. It allows users to:
- Manually adjust the motor's position via serial commands.
- Set a zero reference position.
- Set a maximum position for movement.
- Oscillate between the zero and maximum positions.
- Adjust step size for fine-tuned movement.
- Stop movement at any time.

## Hardware Requirements
- Arduino board
- Stepper motor (compatible with the Stepper library)
- Motor driver (e.g., L298N or ULN2003)
- Power supply suitable for the stepper motor
- Serial Monitor for input commands

## Installation
1. Clone this repository or download the files.
2. Open the `.ino` file in the Arduino IDE.
3. Connect your Arduino board and upload the code.
4. Open the Serial Monitor (9600 baud rate) to control the stepper motor.

## Commands
Use the Serial Monitor to input commands:

| Command     | Action |
|------------|-------------------------------------------------|
| `+`        | Move the motor forward by the current step size |
| `-`        | Move the motor backward by the current step size |
| `z`        | Set the current position as zero |
| `x`        | Set the current position as the maximum range |
| `o`        | Start oscillation between zero and max |
| `s`        | Stop movement |
| `step N`   | Set step increment size to `N` (e.g., `step 20`) |

## Usage Instructions
1. **Position the Motor**
   - Use `+` and `-` to manually move the motor.
   - Once at the desired starting position, type `z` to set zero.
   - Move to the maximum allowable position and type `x` to set the max.

2. **Start Oscillation**
   - Type `o` to start oscillation between zero and max.

3. **Adjust Step Size**
   - Use `step N` to fine-tune the manual movement step size.

4. **Stop Motion**
   - Type `s` to stop movement at any time.

## Notes
- Ensure that zero and max positions are set before starting oscillation.
- The step size should be adjusted based on the motor and gear ratio.
- Adjust `stepsPerRevolution` and `setSpeed()` values as needed for your motor.

## License
This project is open-source and available under the MIT License.

## Contributions
Feel free to fork the repository and submit pull requests with improvements or fixes.

## Author
Developed by Chris Cole
