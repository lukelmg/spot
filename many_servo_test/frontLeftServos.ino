void frontLeft(int shoulder, int top, int bottom) {
  frontLeftShoulder(shoulder);
  frontLeftTop(top);
  frontLeftBottom(bottom);
}

void frontLeftShoulder(int input) {
  //rest 135
  int corrected = input + 45;
  int upperLimit = 180;
  int lowerLimit = -20;
  if (corrected <= lowerLimit) {
    pwm.setPWM(0, 0, pulseWidth(lowerLimit));
  } else if (corrected >= upperLimit) {
    pwm.setPWM(0, 0, pulseWidth(upperLimit));
  } else {
    pwm.setPWM(0, 0, pulseWidth(corrected));
  }
}

void frontLeftTop (int input) {
  //rest 45
  int corrected = -1.33*input +136;
  int upperLimit = 180;
  int lowerLimit = -17;
  if (corrected <= lowerLimit) {
    pwm.setPWM(1, 0, pulseWidth(lowerLimit));
  } else if (corrected >= upperLimit) {
    pwm.setPWM(1, 0, pulseWidth(upperLimit));
  } else {
    pwm.setPWM(1, 0, pulseWidth(corrected));
  }
}

void frontLeftBottom (int input) {
  //rest 45
  int corrected = input + 74;
  int upperLimit = 215;
  int lowerLimit = -20;
  if (corrected <= lowerLimit) {
    pwm.setPWM(2, 0, pulseWidth(lowerLimit));
  } else if (corrected >= upperLimit) {
    pwm.setPWM(2, 0, pulseWidth(upperLimit));
  } else {
    pwm.setPWM(2, 0, pulseWidth(corrected));
  }
}
