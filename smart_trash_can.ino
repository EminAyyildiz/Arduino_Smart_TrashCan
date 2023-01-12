// Emin Ayyıldız

#include<Servo.h>    

Servo servo;    
const int eko=10;         
const int trig=9;         
int mesafe;
int sure;
int red_led = 5;
int green_led = 4;

void setup() {
  servo.attach(6);       
  pinMode(trig,OUTPUT); 
  pinMode(eko,INPUT);    
  Serial.begin(9600); 
  pinMode(red_led,OUTPUT);
  pinMode(green_led,OUTPUT);
  servo.write(90);
}     

void loop() {
 
  digitalWrite(eko, LOW); 
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trig, LOW); 

  sure = pulseIn(eko, HIGH);
  
  mesafe = sure / 29.1 / 2; 
   
  if (mesafe<80)
  
  {
    servo.write(175);
    Serial.print("Distance :");
    Serial.println(mesafe);  
    Serial.println("-Opened-"); 
    digitalWrite(red_led, LOW);
    
    digitalWrite(green_led, HIGH);
    delay(500);
    
   
  }
  else
  {
    servo.write(90); 
    Serial.print("Distance :");
    Serial.println(mesafe);
    Serial.println("-Closed-");
    digitalWrite(green_led, LOW);
    digitalWrite(red_led, HIGH);
   
  }

   

}
