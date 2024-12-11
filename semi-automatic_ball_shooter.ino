#include <Servo.h>
#include <Stepper.h>

Servo servo1;  // First servo on pin 12
Servo servo2;  // Second servo on pin 13
const int SERVO_PIN1 = 12;
const int SERVO_PIN2 = 13;
const int STEPPER_PIN1 = 2;
const int STEPPER_PIN2 = 3;
const int JOYSTICK_X_PIN = A0;
const int JOYSTICK_Y_PIN = A1;
const int JOYSTICK_K_PIN = A2;

const int STEPS_PER_REVOLUTION = 6400;  // Number of steps per revolution
const int MICROSTEP_RESOLUTION = 32;    // Microstep resolution
Stepper stepper(STEPS_PER_REVOLUTION * MICROSTEP_RESOLUTION, STEPPER_PIN1, STEPPER_PIN2);

const int JOYSTICK_THRESHOLD = 600;  // Adjust threshold value as needed

bool isDefaultDirection = false;     // Flag to track if joystick is in default direction
bool isSecondServoRotated = false;    // Flag to track the state of the second servo motor

enum ServoState {
  SERVO_IDLE,
  SERVO_ROTATING,
  SERVO_ROTATED
};

ServoState servo2State = SERVO_IDLE;  // Initial state of the second servo motor

void setup() {
  servo1.attach(SERVO_PIN1);
  servo2.attach(SERVO_PIN2);
  stepper.setSpeed(100);
}

void loop() {
  // Read the joystick X-axis value for the stepper motor control
  int joystickX = analogRead(JOYSTICK_X_PIN);

  // Check if joystick value exceeds the threshold or if it's in the default direction
  if (joystickX > JOYSTICK_THRESHOLD || joystickX < (JOYSTICK_THRESHOLD / 2)) {
    // Map the joystick X-axis value to the number of microsteps for stepper motor rotation
    int microsteps = map(joystickX, 0, 1023, -STEPS_PER_REVOLUTION * MICROSTEP_RESOLUTION, STEPS_PER_REVOLUTION * MICROSTEP_RESOLUTION);

    // Rotate the stepper motor
    stepper.step(microsteps);

    // Update the default direction flag based on the joystick value
    if (joystickX > JOYSTICK_THRESHOLD) {
      isDefaultDirection = false;
    } else if (joystickX < (JOYSTICK_THRESHOLD / 2)) {
      isDefaultDirection = true;
    }
  }

  // Read the joystick Y-axis value for the first servo motor control
  int joystickY = analogRead(JOYSTICK_Y_PIN);

  // Read the joystick K direction value
  int joystickK = analogRead(JOYSTICK_K_PIN);

  // Map the joystick Y-axis value to servo angle range (0 to 180 degrees)
  int servoAngle1 = map(joystickY, 0, 1023, 0, 180);

  // Move the first servo to the calculated angle
  servo1.write(servoAngle1);

  // State machine for the second servo motor
  switch (servo2State) {
    case SERVO_IDLE:
      if (joystickK < (JOYSTICK_THRESHOLD / 2)) {
        servo2State = SERVO_ROTATING;
        isSecondServoRotated = !isSecondServoRotated;  // Toggle the rotation state
      }
      break;

    case SERVO_ROTATING:
      if (isSecondServoRotated) {
        servo2.write(90);
      } else {
        servo2.write(0);
      }
      servo2State = SERVO_ROTATED;
      break;

    case SERVO_ROTATED:
      if (joystickK >= (JOYSTICK_THRESHOLD / 2)) {
        servo2State = SERVO_IDLE;
      }
      break;
  }

  // Add a small delay between motor movements
  delay(10);
}
