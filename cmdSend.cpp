#include "cmdSend.h"
#include "Arduino.h"
// genere la trame au format binaire à passer à RCSwitch.send(char*) 
// sChan correspond au Channel paramétré sur la prise ("A","B","C","D")    a=1,b=2 etc car je n'arrive pas à le faire avec des char...
// nPrise correspond au numero de la prise (1,2,3)

char* genCastoTrame(int sChan, int nPrise, boolean bStatus){ 
  static char sReturn[25];
  String res;
  res = String();
  res = PADDING_START;

  switch(sChan){
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
  switch (nPrise){
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
