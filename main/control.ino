
/*
 * Variables
 */ 
//pin 0,1 is rx and tx
//pin 2,3 use for interrupt
const int PIN_ELEVATOR = 4;  //purple
const int PIN_AILERON = 5;  //blue
const int PIN_THROTTLE = 6;  //orange
const int PIN_RUDDER = 7;    //green
const int PIN_GEAR = 8;     //yellow

Servo controlThrottleServo;
Servo controlAileronServo;
Servo controlElevatorServo;
Servo controlRudderServo;

struct ControlValues {
  int throttle;
  int aileron;
  int elevator;
  int rudder;
  int gear;
};

void controlInitialize() {
  
  pinMode(PIN_ELEVATOR, INPUT);
  pinMode(PIN_AILERON, INPUT);
  pinMode(PIN_THROTTLE, INPUT);
  pinMode(PIN_RUDDER, INPUT);
  pinMode(PIN_GEAR, INPUT);

  controlThrottleServo.attach(PIN_THROTTLE);
  controlElevatorServo.attach(PIN_ELEVATOR);
  controlAileronServo.attach(PIN_AILERON);
  controlRudderServo.attach(PIN_RUDDER);

}

struct ControlValues controlReadValues(){

  const int timeout = 50000;

  ControlValues controlValues;
  
  controlValues.elevator = pulseIn(PIN_ELEVATOR, HIGH, timeout);
  controlValues.aileron = pulseIn(PIN_AILERON, HIGH, timeout); 
  controlValues.throttle = pulseIn(PIN_THROTTLE, HIGH, timeout);
  controlValues.rudder = pulseIn(PIN_RUDDER, HIGH,timeout);
  controlValues.gear = pulseIn(PIN_GEAR, HIGH, timeout);

  return controlValues;
  
}

bool controlIsAutomated(){
  
  const int MIN_PULSE = 1099;
  return !((pulseIn(PIN_GEAR, HIGH)-MIN_PULSE) <= 0);
  
}

void controlSetAutomation(bool automation){
  
  const int mode = automation ? OUTPUT : INPUT;

  pinMode(PIN_ELEVATOR, mode);
  pinMode(PIN_AILERON, mode);
  pinMode(PIN_THROTTLE, mode);
  pinMode(PIN_RUDDER, mode);
  
}

void controlSetArming(bool automation){

  //ELEVATOR_TO_FC.writeMicroseconds(1115);
  //AILERON_TO_FC.writeMicroseconds(1051);
  
  //for armming with data on monoitor serial 
  controlThrottleServo.writeMicroseconds(1109);
  controlRudderServo.writeMicroseconds(1045);

  Serial.print("the model is armed\n");
  delay(1000);
//  automated = true;
  
}
