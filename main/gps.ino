/*
 * Configuration Variables
 */

int gpsRxPin = 1;
int gpsTxPin = 2;

SoftwareSerial gpsSerial(gpsRxPin,gpsTxPin);

/*
 * Variables
 */
TinyGPSPlus gps;

struct GPSCoordinates {
  String lat;
  String lng;
  double latD;
  double lngD;
};

String gpsInitialize(){
  
    gpsSerial.begin(9600);
    
}

String gpsGetLocationViaReading(){
  
//    smsText = readFromSerial();
//    return smsText;
    
}

struct GPSCoordinates gpsParseCoordinatesFromText(String text){
  
    GPSCoordinates coordinates;

    coordinates.lat = text.substring(0, text.indexOf(','));
    coordinates.lng = text.substring(text.indexOf(',')+1, text.length()-2);

    coordinates.latD = coordinates.lat.toDouble();
    coordinates.lngD = coordinates.lng.toDouble();

    return coordinates;
    
}

TinyGPSPlus gpsGetGpsObjectViaReading(){
  
  TinyGPSPlus gps = readFromSerialGpsEncoded(gpsSerial,gps);
  return gps;
  
}


TinyGPSPlus gpsGet(){
  
  gps = readFromSerialGpsEncoded(gpsSerial,gps);
  return gps;
  
}
