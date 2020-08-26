
void translateUpDown(float z3) {

  float thighLength = 177.69;
  float shinLength = 217.75;
  float testShin = 114;

  //acb solving for A
  float shoulderAngle1a = sq(shinLength) + sq(z3) - sq(thighLength);
  float shoulderAngle1b = 2 * z3 * shinLength;
  float shoulderAngle1c = shoulderAngle1a / shoulderAngle1b;
  float shoulderAngle1 = acos(shoulderAngle1c);     // radians

  //sovling for C
  float kneeAngle1a = sq(thighLength) + sq(shinLength) - sq(z3);
  float kneeAngle1b = 2 * thighLength * shinLength;
  /* Serial.print(sq(thighLength)); Serial.print(" + ");
    Serial.print(sq(shinLength)); Serial.print(" - ");
    Serial.print(sq(z3)); Serial.print(" = ");
    Serial.println(kneeAngle1a);*/
  float kneeAngle1c = kneeAngle1a / kneeAngle1b;
  float kneeAngle = acos(kneeAngle1c);     // radians

  //calc degrees from angles
  float shoulderAngle1Degrees = shoulderAngle1 * (180 / PI);  // degrees
  float kneeAngleDegrees = kneeAngle * (180 / PI);            // degrees

  if (kneeAngleDegrees < 0) {
    kneeAngleDegrees = kneeAngleDegrees * -1;
  }

  if (isnan(kneeAngleDegrees)) {
    delay(5000);
  }
  /*
    Serial.print("shoulder = ");
    Serial.print(90-(shoulderAngle1Degrees+1), 5);
    Serial.print("  knee = ");
    Serial.println((kneeAngleDegrees-100), 5);
  */
  frontLeftTop((shoulderAngle1Degrees + 1));
  backLeftTop((shoulderAngle1Degrees + 1));
  frontRightTop((shoulderAngle1Degrees + 1));
  backRightTop((shoulderAngle1Degrees + 1));

  frontLeftBottom((kneeAngleDegrees));
  backLeftBottom((kneeAngleDegrees));
  frontRightBottom((kneeAngleDegrees));
  backRightBottom((kneeAngleDegrees));
}
