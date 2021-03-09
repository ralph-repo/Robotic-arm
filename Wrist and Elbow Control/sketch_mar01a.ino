#include <Servo.h>

Servo myservo;

int pos = 0;

const int dirPin  = 5;
const int stepPin = 4; 
const int enPin   = 3;

const int pinX = A1; // Joystick X axis
const int pinY = A0; // Joystick Y axis
 
void setup() {
  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT); 

  myservo.attach(9);

  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(enPin,OUTPUT);
  Serial.begin(9600);
  
  digitalWrite(enPin,LOW);
}
 
void loop() {
  int X = analogRead(pinX);
  int Y = analogRead(pinY);
  Serial.print(X);
  Serial.print("\t"); 
  Serial.println(Y);
  
  if(Y < 500){
    stepper_mov_1();
  }

  if(Y > 515){
    stepper_mov_2();
  }

    if(X < 470){
    servo_mov_1();
  }

  if(X > 520){
    servo_mov_2();
  }

}

//ANTI-CLOCKWISE MOVEMENT of ELBOW
void stepper_mov_1(){
  digitalWrite(dirPin,LOW);

  while(1){
    int Y = analogRead(pinY);
     
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000); 

    if(Y > 500){
      break;
      }
    }
  }

//CLOCK-WISE MOVEMENT of ELBOW
void stepper_mov_2(){
    digitalWrite(dirPin,HIGH);
   
    while(1) {
    int Y = analogRead(pinY);
    
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000); 

    if(Y < 515){
      break;
      }
    }
  }

// CLOCK-WISE MOVEMENT OF SERVO
void servo_mov_1(){
  while (pos <= 180) { // goes from 0 degrees to 180 degrees
    int X = analogRead(pinX);
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);      // waits 15ms for the servo to reach the position
    pos=pos+1;
    if(X>470){
      break;
      }
    }
  }

//ANTI-CLOCKWISE MOVEMENT OF SERVO
void servo_mov_2(){
    while (pos >= 0) { // goes from 180 degrees to 0 degrees
    int X = analogRead(pinX);
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    pos=pos-1;
    if(X<520){
      break;
      }
    }
  }
