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
	  if (strCmd == "ON"){
		  Serial.println("Commande : ON");
		  mySwitch.send(genCastoTrame(3,1,true));// envoie ON sur le Chanel C (3) prise 2
		  mySwitch.send(genCastoTrame(3,2,true));// envoie ON sur le Chanel C (3) prise 2
		  mySwitch.send(genCastoTrame(3,3,true));// envoie ON sur le Chanel C (3) prise 2
	  } else if (strCmd == "OFF"){
		  Serial.println("Commande : OFF");
		  mySwitch.send(genCastoTrame(3,1,false));// envoie OFF sur le Chanel C (3) prise 2
		  mySwitch.send(genCastoTrame(3,2,false));// envoie OFF sur le Chanel C (3) prise 2
		  mySwitch.send(genCastoTrame(3,3,false));// envoie OFF sur le Chanel C (3) prise 2
	  } else {
	  	Serial.println("Commande inconnue");
	  }
	
}


void loop()
{
	char car;
	String strCmd = "";
	Serial.println("Attente Commande (ON/OFF)");
	while(1) {
		while(Serial.available() <= 0);
		car = (char)Serial.read(); // lit un car 
		if (car == CR){
			validCMD(strCmd);
			strCmd = "";
			Serial.println("Attente Commande (ON/OFF)");
			break;
		} else {
			strCmd += car;
		}
	}
}
