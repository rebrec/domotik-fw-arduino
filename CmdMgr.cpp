#include "Arduino.h"
#include "CmdMgr.h"
#include "mydef.h"
#include "cmdSend.h"

CmdMgr::CmdMgr(RCSwitch rc){
  this->resetCmd();
  this->rcsw = rc;
}

void CmdMgr::init(){
  this->resetCmd();
}

void CmdMgr::resetCmd(){
  this->state = WAITING;
}

void CmdMgr::processSerialData() {
	char car;
	String strCmd = "";
	Serial.println("SALUT Attente Commande (ON/OFF)");
	while(1) {
		while(Serial.available() <= 0);
		car = (char)Serial.read(); // lit un car 
		if (car == CR){
			this->validCMD(strCmd);
			strCmd = "";
			Serial.println("SALUT Attente Commande (ON/OFF)");
			break;
		} else {
			strCmd += car;
		}
	}
}

void CmdMgr::validCMD(String strCmd)
{
	  if (strCmd == "ON"){ 
		  Serial.println("Commandessss : ON");
		  Serial.println(genCastoTrame(3,1,true));
		  this->rcsw.send(genCastoTrame(3,1,true));// envoie ON sur le Chanel C (3) prise 2
		  this->rcsw.send(genCastoTrame(3,2,true));// envoie ON sur le Chanel C (3) prise 2
		  this->rcsw.send(genCastoTrame(3,3,true));// envoie ON sur le Chanel C (3) prise 2
	  } else if (strCmd == "OFF"){
		  Serial.println("Commande : OFF");
		  Serial.println(genCastoTrame(3,1,false));
		  this->rcsw.send(genCastoTrame(3,1,false));// envoie OFF sur le Chanel C (3) prise 2
		  this->rcsw.send(genCastoTrame(3,2,false));// envoie OFF sur le Chanel C (3) prise 2
		  this->rcsw.send(genCastoTrame(3,3,false));// envoie OFF sur le Chanel C (3) prise 2
	  } else {
	  	Serial.println("Commande inconnue");
	  }
	
}
