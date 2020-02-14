#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <Servo.h>
#include <Wire.h>

void setup(){
  
  Serial.begin(9600);

  //Initialization
  smsInitialize();
//  gpsInitialize();
//  controlInitialize();
//  compassInitialize();
//  
}

void loop(){

  Serial.println("Get SMS");

  String message = smsGetTextViaReading();
  Serial.println(message);
  
  delay(200);
  
}

//if(pureMessage == "On") {
//  Serial.println("turn on Quad");
//  turnOn = true; //for arming and constant throttle
//  getGPS();
// } else {
//  Serial.print("where you want i go?");
//  locationRead(pureMessage, len);
// }
