#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define MIN_PULSE_WIDTH 650
#define MAX_PULSE_WIDTH 2350
#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 50

uint8_t servonum = 0;

int lx, ly, rx, ry, SWD, SWB; // controller variables
bool didMyOneTimeAction = 0;
bool didMyOneTimeAction2 = 0;

void setup()
{
  Serial.begin(115200);
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);

  pinMode(13, INPUT);
  pinMode(11, INPUT);
}

int delayBetween = 100;

int i = 0;
void loop() {
  getControllerInputs();
  allShoulders(90);

  allBottoms(200);
  backTops(180);

  delay(3000);

  allBottoms(100);

  delay(1000);

  allBottoms(50);

  delay(3000);

  allBottoms(100);

  delay(1000);
  
  /*
  if (SWD == 1) {
    if (didMyOneTimeAction == false)
    { // run once
      didMyOneTimeAction = true;
      allShoulders(90);
      delay(1000);
      frontBottoms(75);
      delay(1000);
      frontTops(90);
      delay(1000);

      backTops(150);
      delay(1000);
      backBottoms(75);
      delay(1000);
      backTops(70);
    }
    allShoulders(90);
    allTops(75);
    allBottoms(75);
    didMyOneTimeAction2 = false;
   
  } else {
    if (didMyOneTimeAction2 == false)
    { // run once
    allTops(90);
    delay(2000);
    allBottoms(200);
    delay(2000);
    }
    didMyOneTimeAction = false;
    restPosition();
  }
  */
}

void frontLeftTriangulation (float targetX, float targetZ) {
  // find 3 sides of triangle
  float upperLegLength = 177.69;
  float lowerLegLength  = 217.75;
  float hypotenuse = sqrt(sq(targetX) + sq(targetZ));

  // solve SSS triangle
  float shoulderAngle1 = sq(hypotenuse) + sq(177.69) - sq(217.75);
  float shoulderAngle2 = 2 * hypotenuse * 177.69;
  float shoulderAngle3 = shoulderAngle1 / shoulderAngle2;
  float shoulderAngle4 = acos(shoulderAngle3);
  float shoulderAngleDegrees = (180 / PI) * shoulderAngle4;

  float kneeAngle1 = sq(217.75) + sq(177.69) - sq(hypotenuse);
  float kneeAngle2 = 2 * 217.75 * 177.69;
  float kneeAngle3 = kneeAngle1 / kneeAngle2;
  float kneeAngle4 = acos(kneeAngle3);
  float kneeAngleDegrees = (180 / PI) * kneeAngle4;

  // find difference between original triangle and new triangle

  float servo90 = atan(targetX / targetZ);
  float servo90degrees = (180 / PI) * servo90;
  float shoulderMove = shoulderAngleDegrees - servo90degrees;
  
  frontLeft(0, shoulderMove, kneeAngleDegrees);
  frontRight(9, shoulderMove, kneeAngleDegrees);
  backLeft(0, shoulderMove, kneeAngleDegrees);
  backRight(0, shoulderMove, kneeAngleDegrees);

}
