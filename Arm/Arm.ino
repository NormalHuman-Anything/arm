#include <Servo.h>

Servo myservo; 
Servo myservo2;
Servo myservo3;
Servo myservo4;

int joyX = 0;
int joyY = 0;
int btn = 0;
int X = 0;
int Y = 0;
int joyR = 0;
bool B = false;

int Xpos = 0;
int YPos = 0;
int claw = 0;
int rotate = 0;
void setup() {
  myservo.attach(2);
  myservo2.attach(3);
  myservo3.attach(4);
  myservo4.attach(5);
  Serial.begin(9600);
}

void loop() {
  joyX = analogRead(A0);
  joyY = analogRead(A1);
  btn = analogRead(A2);
  joyR = analogRead(A3);
  
  X = map(joyX, 0, 1023, 0, 180);
  Y = map(joyY, 0, 1023, 0, 180);
  rotate = map(joyR, 0, 1023, 0, 180);

  if(B >= 100){
    claw = 0;
  }else{
    claw = 180;
  }

  myservo.write(rotate);
  myservo2.write(X);
  myservo3.write(Y);
  myservo4.write(claw);
}