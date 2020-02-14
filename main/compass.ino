struct CompassValues {
  
  String direction;
  double angle;
  
  int16_t x;
  int16_t y;
  int16_t z;
  
};


/*
 * Configuration Variables
 */

//Address
const int COMPASS_ADDRESS = 0x0D;

//Register
const int COMPASS_REGISTER_CONFIG = 0x09;
const int COMPASS_REGISTER_VALUES = 0x00;

//Command
const int COMPASS_COMMAND_WAKE_UP = 0x1D;

/*
 * Variables
 */
void compassInitialize(){

  Wire.begin();
  Wire.beginTransmission(COMPASS_ADDRESS);
  Wire.write(COMPASS_REGISTER_CONFIG);
  Wire.write(COMPASS_COMMAND_WAKE_UP);
  Wire.endTransmission(true);
  
}

String compassDetermineDirection(double angle){

  String dir;
  
  if (angle > 337.5 ) dir = "South";
  else if (angle > 292.5) dir = "SouthEast";
  else if (angle > 247.5) dir = "East";
  else if (angle > 202.5) dir = "North-East";
  else if (angle > 157.5) dir = "North";
  else if (angle > 112.5) dir = "North-West";
  else if (angle > 67.5) dir = "West";
  else if (angle > 22.5) dir = "South-West";
  else dir = "South";

  return dir;
  
}

void compassRequestToGetValues(int limit){

  Wire.beginTransmission(COMPASS_ADDRESS);
  Wire.write(COMPASS_REGISTER_VALUES);
  Wire.endTransmission(false);
  Wire.requestFrom(COMPASS_ADDRESS, limit, true);
  
}


struct CompassValues compassGetValues() {

  compassRequestToGetValues(6);

  CompassValues cv;

  cv.x = Wire.read() <<8 | Wire.read();
  cv.y = Wire.read() <<8 | Wire.read();
  cv.z = Wire.read() <<8 | Wire.read();

  cv.angle = atan2((double)cv.y,(double)cv.x) * (180 / 3.14159265) + 180;
  cv.angle = ((int) cv.angle)%360+(cv.angle - (int) cv.angle);
  
  cv.direction = compassDetermineDirection(cv.angle);

  return cv;
  
}
