/*
  Example for different sending methods
  
  http://code.google.com/p/rc-switch/
  
  Need help? http://forum.ardumote.com
*/


#include <RCSwitch.h>
#include "cmdSend.h"

#define TRANSMIT_PIN 10


#define CR 13

RCSwitch mySwitch = RCSwitch();






void setup() {

  Serial.begin(9600);
  
  // Transmitter is connected to Arduino Pin #10  
  mySwitch.enableTransmit(10 );
  
  // Optional set protocol (default is 1, will work for most outlets)
  mySwitch.setProtocol(1);

  // Optional set pulse length.
  mySwitch.setPulseLength(308);
  
  // Optional set number of transmission repetitions.
  // mySwitch.setRepeatTransmit(1);
  
}



void validCMD(String strCmd)
{
    String strChan, strSwitch, strAction;
   //  I A 1 0
    if (strCmd.substring(0,1) == "I" && strCmd.substring(1,2) == " "){
        strChan = strCmd.substring(2,3);
        strSwitch = strCmd.substring(4,5);
        strAction = strCmd.substring(6,7);
        Serial.print("Chan : ");
        Serial.print(strChan);
        Serial.print(" Switch : ");
        Serial.print(strSwitch);
        Serial.print(" Cmd : ");
        Serial.println(strAction);
        
        Serial.println(genCastoTrame(strChan,strSwitch,strAction));
        
    } else {
          Serial.println("Commande inconnue");
    }

    	
}


void loop()
{
	char car;
	String strCmd = "";
	strCmd = "I A 1 1";
        validCMD(strCmd);
	Serial.println(".");
	while(1) {
		while(Serial.available() <= 0);
		car = (char)Serial.read(); // lit un car 
		if (car == CR){
			validCMD(strCmd);
			strCmd = "";
			Serial.println(".");
			break;
		} else {
			strCmd += car;
		}
	}
}
