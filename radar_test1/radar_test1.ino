#include <LiquidCrystal.h>
#include <Servo.h>
Servo myservo;

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const  int trig=A5;
const  int echo=A4;
float Time=0,distance;
int value=0;

void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(A0,INPUT);
  pinMode(8,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  myservo.attach(11);
  
  lcd.begin(16, 2);
  lcd.print("Arduino Radar.");
  delay(2000);
  
}

void loop() {
   //sonar();

   for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);// tell servo to go to position in variable 'pos'
    sonar();
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (int pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    sonar();
    delay(15);                       // waits 15ms for the servo to reach the position
  }
   
}

void sonar ()
{
  int value = analogRead(A0);
   distance = (2.00*value) / 10.00;

   if(distance<50)
   {
    digitalWrite(8,1);
    digitalWrite(A1,1);
    digitalWrite(A2,0);
    }
   else if(distance<100)
   {
    digitalWrite(8,1);
    digitalWrite(A1,0);
    digitalWrite(A2,1);
    }
   else
   {
    digitalWrite(8,0);
    digitalWrite(A1,0);
    digitalWrite(A2,0);
   }
   

   lcd.clear();
   lcd.print(distance);
   lcd.setCursor(6, 0);
   lcd.print("inch");
   delay(50);
}

