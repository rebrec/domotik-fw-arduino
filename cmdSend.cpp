#include "cmdSend.h"
#include "Arduino.h"
// genere la trame au format binaire à passer à RCSwitch.send(char*) 
// sChan correspond au Channel paramétré sur la prise ("A","B","C","D")    a=1,b=2 etc car je n'arrive pas à le faire avec des char...
// nPrise correspond au numero de la prise (1,2,3)

char* genCastoTrame(String strChan, String strPrise, String strStatus){ 
  static char sReturn[25];
  unsigned char cChan[1];
  strChan.getBytes(cChan,1);
  char c;
  c = cChan[0];
  Serial.println(c);
  int intChan = cChan[0] - (int)'A' + 1; // A-D become 1-4
  Serial.println(cChan[0]);
  Serial.println('A');
  Serial.println((int)'A');
  Serial.println(intChan);
  int intPrise = strPrise.toInt();
  int bStatus = strStatus.toInt();
  String res;
  
  
  
  res = String();
  res = PADDING_START;

  switch(intChan){
      case 1:
          res = res + CHAN_A; break;
      case 2:
          res = res +  CHAN_B; break;
      case 3:
          res = res + CHAN_C; break;
      case 4:
          res = res +  CHAN_D; break;
      default:
          return '\0';
  }
  switch (intPrise){
      case 1:
          res = res + PRISE_1; break;
      case 2:
          res = res +  PRISE_2; break;
      case 3:
          res = res + PRISE_3; break;
      default:
          return '\0';
  }
  res = res + PADDING_MIDDLE;
  switch(bStatus){
      case true:
          res = res + CMD_ON; break;
      case false:
          res = res +  CMD_OFF; break;
      default:
          return '\0';
  }
  res.toCharArray(sReturn,25);
  return sReturn;  


}
