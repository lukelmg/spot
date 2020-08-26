void allShoulders(int input) {
  frontLeftShoulder(input);
  frontRightShoulder(input);
  backLeftShoulder(input);
  backRightShoulder(input);
}

void allTops (int input) {
  frontLeftTop(input);
  frontRightTop(input);
  backLeftTop(input);
  backRightTop(input);
}

void allBottoms (int input) {
  frontLeftBottom(input);
  frontRightBottom(input);
  backLeftBottom(input);
  backRightBottom(input);
}

void restPosition() {
  allShoulders(0);
  allTops(90);
  allBottoms(200);
}
