#ifndef CmdMgr_h
#define CmdMgr_h
#include "Arduino.h"


#define WAITING 1
#define RECEIVING 2
#define RECEIVED 3
#include <RCSwitch.h>


class CmdMgr{
  public:
    int state;
    RCSwitch rcsw;
    CmdMgr(RCSwitch);
    void init();
    void processSerialData();
    void resetCmd();
    void validCMD(String);
  

};




#endif
