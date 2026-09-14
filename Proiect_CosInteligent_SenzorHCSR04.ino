#include <ESP32Servo.h>
Servo myServo;
int servoPin = 18;
int trigPin = 16;
int echoPin = 17;
void setup() {
  Serial.begin(115200);
  myServo.attach(servoPin, 500, 2400);
  myServo.write(180);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);
  
  long durata = pulseIn(echoPin, HIGH);
  int distanta = durata*0.034/2;

  if(distanta>=0 && distanta <=10)
  {
    myServo.write(0);
    delay(3000);

    myServo.write(180);
    delay(500);
  }
  delay(100);
}
