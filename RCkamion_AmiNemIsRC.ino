#include <Servo.h>

#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'
#define CIRCLE 'C'
#define CROSS 'X'
#define TRIANGLE 'T'
#define SQUARE 'S'
#define START 'A'
#define PAUSE 'P'


const int A1A = 2;
const int A1B = 3;
int angle;

Servo myServo;

void setup() {
  Serial.begin(9600); 
  myServo.attach(9);

  pinMode(A1A,OUTPUT);
  pinMode(A1B,OUTPUT); 

  angle = map(150, 0, 1023, 0, 255);
  myServo.write(angle);
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    switch (command) {
    case FORWARD:
      motorA('L');
    break;

    case BACKWARD:
      motorA('R');
    break;

    case CROSS:
      motorA('O');
    break;

    case LEFT:
      angle = map(65, 0, 1023, 0, 255);
      myServo.write(angle);
    break;

    case RIGHT:
      angle = map(255, 0, 1023, 0, 255);
      myServo.write(angle);
    break;

    case TRIANGLE:
      angle = map(150, 0, 1023, 0, 255);
      myServo.write(angle);
    break;
    }
  }

}


void motorA(char d)
{
  if(d =='R'){
    digitalWrite(A1A,LOW);
    digitalWrite(A1B,HIGH); 
  }else if (d =='L'){
    digitalWrite(A1A,HIGH);
    digitalWrite(A1B,LOW);    
  }else if(d == 'O'){
    digitalWrite(A1A,LOW);
    digitalWrite(A1B,LOW);    
  }
}
