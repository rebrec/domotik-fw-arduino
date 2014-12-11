/*
  Example for different sending methods
  
  http://code.google.com/p/rc-switch/
  
  Need help? http://forum.ardumote.com
*/


#include <RCSwitch.h>

#include "mydef.h"
#include "CmdMgr.h"



RCSwitch mySwitch = RCSwitch();

CmdMgr cmd = CmdMgr(mySwitch);




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






void loop()
{
  cmd.processSerialData();
}
