/*
 * Configuration Variables
 */

int smsRxPin = 8;
int smsTxPin = 9;

SoftwareSerial smsSerial(smsRxPin,smsTxPin);

/*
 * Variables
 */

String smsText;

/*
 * Functionality
 */

String smsInitialize(){
  
    smsSerial.begin(9600);
    
}

String smsGetTextViaReading(){

    smsSerial.listen();

    smsSerial.println("AT+CMGF=1");
    smsSerial.println("AT+CNMI=1,2,0,0,0");
    Serial.println("Sended Message");
//    smsText = readFromSerial(smsSerial);

    String tempStr = "";
  
    while(smsSerial.available()) {
      Serial.println(smsSerial.read());
      char tempCh = smsSerial.read();
      tempStr.concat(tempCh);
      delay(10);
    }
    
    return tempStr;
    
}

String smsGetText(){
    
  return smsText;
    
}

String smsGetMessageFromText(String text){

  if(text.startsWith("\r\n+CMT: ")) {

      return text.substring(51, text.length()-2);
  }

  return "";
  
}

String smsGetNumberFromText(String text){

  if(text.startsWith("\r\n+CMT: ")) {

      return text.substring(51, text.length()-2);
      return text.substring(9,22);
  }
  
}

String smsSendText(String msisdn,String text){

  smsSerial.listen();

  String sendCommand = "AT+CMGS=\"";
  sendCommand.concat(msisdn);//+989371600514
  sendCommand.concat("\"");
  
  smsSerial.println("AT+CMGF=1");
  smsSerial.println(sendCommand);
  smsSerial.write(26);
    
}
