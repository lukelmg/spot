void frontRight(int shoulder, int top, int bottom) {
  frontRightShoulder(shoulder);
  frontRightTop(top);
  frontRightBottom(bottom);
}

void frontRightShoulder(int input) {
  //rest 135
  int corrected = 180 - (input + 45) + 15;
  int upperLimit = 180;
  int lowerLimit = -20;
  if (corrected <= lowerLimit) {
    pwm.setPWM(12, 0, pulseWidth(lowerLimit));
  } else if (corrected >= upperLimit) {
    pwm.setPWM(12, 0, pulseWidth(upperLimit));
  } else {
    pwm.setPWM(12, 0, pulseWidth(corrected));
  }
}

void frontRightTop(int input) {
  //rest 45
  int corrected = 180 -(-1.33 * input + 136) + 45;
  int upperLimit = 235;
  int lowerLimit = -17;
  if (corrected <= lowerLimit) {
    pwm.setPWM(15, 0, pulseWidth(lowerLimit));
  } else if (corrected >= upperLimit) {
    pwm.setPWM(15, 0, pulseWidth(upperLimit));
  } else {
    pwm.setPWM(15, 0, pulseWidth(corrected));
  }
}

void frontRightBottom (int input) {
  //rest 45
  int corrected = 180-(input + 74)+15;
  int upperLimit = 215;
  int lowerLimit = -20;
  if (corrected <= lowerLimit) {
    pwm.setPWM(13, 0, pulseWidth(lowerLimit));
  } else if (corrected >= upperLimit) {
    pwm.setPWM(13, 0, pulseWidth(upperLimit));
  } else {
    pwm.setPWM(13, 0, pulseWidth(corrected));
  }
}
