#include "Arduino.h"
#include "CmdMgr.h"

CmdMgr:CmdMgr(){
  this->resetCmd();
}

void init(){
  this->resetCmd();
}

void resetCmd(){
  this->state = WAITING;
}

void processSerialData() {
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
