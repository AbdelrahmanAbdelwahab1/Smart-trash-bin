#include <Servo.h>

Servo myservo;
Servo myservo2;
String receivedData = ""; 

void setup() {
  Serial.begin(9600);
  myservo.attach(6);
  myservo2.attach(9);
  pinMode(13, INPUT);
  myservo2.write(100);
}

void loop() {
  if (digitalRead(13) == 0) {
    myservo2.write(70); 
    delay(5000);
    Serial.println("close");
  }
  
  if (Serial.available() > 0) {
    char c = Serial.read();
    receivedData += c;
    if (c == '\n') {
      receivedData.trim();
      if (receivedData == "can") {
        myservo.write(0);
      } else if (receivedData == "glass") {
        myservo.write(90);
      } else if (receivedData == "paper") {
        myservo.write(90);
      } else if (receivedData == "plastic") {
        myservo.write(180);
      }
      delay(1000);
      receivedData = "";
      myservo2.write(100);
      Serial.println("open");
      Serial.flush();
    }
  }
}