void setupMotorshield() {
  DEBUG_PRINTLN("INFO: Setting up motorshield ...");
  pinMode(LEFT_PWM_PIN, OUTPUT);
  pinMode(RIGHT_PWM_PIN, OUTPUT);
  pinMode(LEFT_DIRECTION_PIN, OUTPUT);
  pinMode(RIGHT_DIRECTION_PIN, OUTPUT);

  analogWrite(LEFT_PWM_PIN, 0);
  analogWrite(RIGHT_PWM_PIN, 0);
  digitalWrite(LEFT_DIRECTION_PIN, LOW);
  digitalWrite(RIGHT_DIRECTION_PIN, LOW);
}


void driveMotorshield(byte motor, byte dir, byte spd) {
  if (motor == LEFT_MOTOR) {
    digitalWrite(LEFT_DIRECTION_PIN, dir);
    analogWrite(LEFT_PWM_PIN, spd);
  } else if (motor == RIGHT_MOTOR) {
    digitalWrite(RIGHT_DIRECTION_PIN, dir);
    analogWrite(RIGHT_PWM_PIN, spd);
  }
}


void pw2speed() {
    leftPulsewidth = pulseIn(LEFT_CHANNEL_PIN, HIGH, PULSEIN_TIMEOUT_MICROSEC);  // The pulseIn function measures the width of the Frsky PPM signal
  rightPulsewidth = pulseIn(RIGHT_CHANNEL_PIN, HIGH, PULSEIN_TIMEOUT_MICROSEC);
    if ((leftPulsewidth < PPM_PIXHAWK_MIN) || (leftPulsewidth > PPM_PIXHAWK_MAX)) {
      // Skip this invalid pulse width.  Do not remove this if block!
    } else {
      leftSpeed = map(leftPulsewidth, PPM_PIXHAWK_MIN, PPM_PIXHAWK_MAX, -255, 255);
      leftSpeed = constrain(leftSpeed, -255, 255);
      if (leftSpeed > IDLE_SPEED_LAG) {
        driveMotorshield(LEFT_MOTOR, LEFT_FORWARD, leftSpeed);
      } else if (leftSpeed < -IDLE_SPEED_LAG) {
        driveMotorshield(LEFT_MOTOR, LEFT_REVERSE, -leftSpeed);
      } else {
        driveMotorshield(LEFT_MOTOR, LEFT_REVERSE, 0);
      };
    };

    if ((rightPulsewidth < PPM_PIXHAWK_MIN) || (rightPulsewidth > PPM_PIXHAWK_MAX)) {
      // Skip this invalid pulse width
    } else {
      rightSpeed = map(rightPulsewidth, PPM_PIXHAWK_MIN, PPM_PIXHAWK_MAX, -255, 255);
      rightSpeed = constrain(rightSpeed, -255, 255);
      if (rightSpeed > IDLE_SPEED_LAG) {
        driveMotorshield(RIGHT_MOTOR, RIGHT_FORWARD, rightSpeed);
      } else if (rightSpeed < -IDLE_SPEED_LAG) {
        driveMotorshield(RIGHT_MOTOR, RIGHT_REVERSE, -rightSpeed);
      } else {
        driveMotorshield(RIGHT_MOTOR, RIGHT_REVERSE, 0);
      };
    };
}


void printSpeeds() {
  DEBUG_PRINT("leftSpeed: ");
  DEBUG_PRINT(leftSpeed);
  DEBUG_PRINT(" | ");
  DEBUG_PRINT("rightSpeed: ");
  DEBUG_PRINT(rightSpeed);
  DEBUG_PRINT(" | ");
}