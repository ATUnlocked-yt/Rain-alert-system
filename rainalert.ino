#include <Servo.h>

Servo rainServo;

int rainSensor = A0;

int buzzer = 8;
int led = 13;      // LED connected to D13
int servoPin = 9;

int sensorValue;


void setup() {

  Serial.begin(9600);

  rainServo.attach(servoPin);

  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  rainServo.write(0);

}


void loop() {

  sensorValue = analogRead(rainSensor);

  Serial.println(sensorValue);


  // RAIN DETECTED

  if(sensorValue < 500)
  {

    digitalWrite(buzzer, HIGH);

    digitalWrite(led, HIGH);

    rainServo.write(90);

  }


  // RAIN STOPPED

  else
  {

    digitalWrite(buzzer, LOW);

    digitalWrite(led, LOW);

    rainServo.write(0);

  }


  delay(200);

}