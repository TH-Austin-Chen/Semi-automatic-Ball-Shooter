# Semi-Automatic Ball Shooter

## Introduction
This project involves designing and building a semi-automatic ball shooter. The shooting mechanism is automated, while balls are loaded manually. The objective is to shoot three baskets within 5 minutes, with the team achieving the fastest completion time declared the winner.

### Game Setup
- **Target**: Toy basketball hoop 1.5m away with varying heights.
- **Robot Constraints**: Maximum dimensions of 42 × 29.7 × 25 cm.
- **Materials Provided**: Motors, controller boards, wires, plywood, aluminum profiles, and an additional budget of HK $1500 for extra materials.
---
## Aims
The goal is to achieve speed and accuracy through:
- **Counter-rotating wheel mechanism** for consistent and efficient shooting.
- Automated **vertical and horizontal angle adjustments** using servo and stepper motors.
- Reduced manual intervention to minimize time delays and enhance precision.
---
## Design Overview
### Shooting Mechanism
- **Counter-rotating Wheels**: High-speed and consistent shooting achieved using two DC motors with 84mm diameter wheels.

### Horizontal Angle Control
- **Gear System**: A stepper motor drives a 56-tooth gear, interlocked with a 180-tooth gear to rotate the launching system.

### Vertical Angle Control
- **Linkage System**: Three linkages adjust the pipe's vertical angle, connected to a servo motor and rotating shaft for smooth motion.

### Other Key Components
- **Motor Mounts**: Custom 3D-printed stands for securing motors.
- **Ball Pusher**: Servo-driven mechanism ensures consistent ball trajectory.
- **PVC Pipe System**: Supports motors and allows vertical angle adjustments.
---
## Electronics
The launcher integrates various electronic components for precise control:

### Components
- **Microcontroller**: Arduino board for motor control.
- **Joystick**: Enables manual adjustments to shooting angles and functions.
- **Receiver and Transmitter**: Wireless control for simultaneous motor operation.

### Controls
#### Joystick Functions:
- **Left Joystick X**: Horizontal angle adjustment (stepper motor).
- **Left Joystick Y**: Vertical angle adjustment (servo motor).
- **Left Joystick Button**: Ball pusher control.
- **Right Joystick Button**: Automation for pre-set positions.

### Wireless Control
- **Receiver**: Relays signals to components for remote operation.
- **Transmitter**: Provides wireless control using joysticks, switches, and knobs.
---
## Features
1. **Automated Shooting**: Precision and speed with counter-rotating wheels.
2. **Angle Adjustments**: Automated and manual controls for horizontal and vertical angles.
3. **Compact Design**: Meets size constraints with robust mounting and efficient layout.
4. **Wireless Operation**: Flexible and multi-user control from a distance.

---

