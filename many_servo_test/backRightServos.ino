void backRight(int shoulder, int top, int bottom) {
  backRightShoulder(shoulder);
  backRightTop(top);
  backRightBottom(bottom);
}

void backRightShoulder(int input) {
  //rest 135
  int corrected = 180 - (input + 45) + 25;
  int upperLimit = 180;
  int lowerLimit = -20;
  if (corrected <= lowerLimit) {
    pwm.setPWM(8, 0, pulseWidth(lowerLimit));
  } else if (corrected >= upperLimit) {
    pwm.setPWM(8, 0, pulseWidth(upperLimit));
  } else {
    pwm.setPWM(8, 0, pulseWidth(corrected));
  }
}

void backRightTop(int input) {
  //rest 45

 //  pwm.setPWM(9, 0, pulseWidth(235));
  
  
  int corrected = 180 -(-1.33 * input + 136) + 40;
  int upperLimit = 235;
  int lowerLimit = -17;
  if (corrected <= lowerLimit) {
    pwm.setPWM(9, 0, pulseWidth(lowerLimit));
  } else if (corrected >= upperLimit) {
    pwm.setPWM(9, 0, pulseWidth(upperLimit));
  } else {
    pwm.setPWM(9, 0, pulseWidth(corrected));
  }
  
}

void backRightBottom (int input) {
  //rest 45s
  int corrected = 180-(input + 74)+15;
  int upperLimit = 215;
  int lowerLimit = -20;
  if (corrected <= lowerLimit) {
    pwm.setPWM(11, 0, pulseWidth(lowerLimit));
  } else if (corrected >= upperLimit) {
    pwm.setPWM(11, 0, pulseWidth(upperLimit));
  } else {
    pwm.setPWM(11, 0, pulseWidth(corrected));
  }
}
