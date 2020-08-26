void backLeft(int shoulder, int top, int bottom) {
  backLeftShoulder(shoulder);
  backLeftTop(top);
  backLeftBottom(bottom);
}

void backLeftShoulder(int input) {
  //rest 135
  int corrected = input + 45;
  int upperLimit = 180;
  int lowerLimit = -20;
  if (corrected <= lowerLimit) {
    pwm.setPWM(6, 0, pulseWidth(lowerLimit));
  } else if (corrected >= upperLimit) {
    pwm.setPWM(6, 0, pulseWidth(upperLimit));
  } else {
    pwm.setPWM(6, 0, pulseWidth(corrected));
  }
}

void backLeftTop (int input) {
  //rest 45
  int corrected = -1.33*input +136;
  int upperLimit = 180;
  int lowerLimit = -17;
  if (corrected <= lowerLimit) {
    pwm.setPWM(5, 0, pulseWidth(lowerLimit));
  } else if (corrected >= upperLimit) {
    pwm.setPWM(5, 0, pulseWidth(upperLimit));
  } else {
    pwm.setPWM(5, 0, pulseWidth(corrected));
  }
}

void backLeftBottom (int input) {
  //rest 45
  int corrected = input + 74;
  int upperLimit = 215;
  int lowerLimit = -20;
  if (corrected <= lowerLimit) {
    pwm.setPWM(7, 0, pulseWidth(lowerLimit));
  } else if (corrected >= upperLimit) {
    pwm.setPWM(7, 0, pulseWidth(upperLimit));
  } else {
    pwm.setPWM(7, 0, pulseWidth(corrected));
  }
}
