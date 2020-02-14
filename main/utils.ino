String readFromSerial(SoftwareSerial serial){
    
  String tempStr;

  serial.listen();

  while(serial.available()) {
    char tempCh = serial.read();
    tempStr.concat(tempCh);
    delay(10);
  }
  
  return tempStr;
     
}

TinyGPSPlus readFromSerialGpsEncoded(SoftwareSerial serial,TinyGPSPlus gps){

  serial.listen();
  
  while(serial.available() > 0) {
      gps.encode(serial.read());    
  }

  return gps;
    
}
