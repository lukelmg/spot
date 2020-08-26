void getControllerInputs() {
  rx = map(pulseIn(13, HIGH), 1000, 2000, 5, 262);
  ry = map(pulseIn(11, HIGH), 1000, 2000, 5, 255);
  lx = map(pulseIn(10, HIGH), 1000, 2000, 5, 262);
  ly = map(pulseIn(12, HIGH), 1000, 2000, 255, 5);
  SWD = map(pulseIn(9, HIGH), 900, 1900, 1, 0);
  SWB = map(pulseIn(8, HIGH), 900, 1900, 0, 1);
  outputInputValues();
}

void outputInputValues() {
  Serial.print("rightStickX: "); Serial.print(rx);
  Serial.print("  rightStickY: "); Serial.print(ry);
  Serial.print("  lefttStickX: "); Serial.print(lx);
  Serial.print("  leftStickY: "); Serial.print(ly);
  Serial.print("  SWD: "); Serial.print(SWD);
  Serial.print("  SWB: "); Serial.println(SWB);
}
