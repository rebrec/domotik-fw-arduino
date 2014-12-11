#ifndef CmdMgr_h
#define CmdMgr_h
#include "Arduino.h"

#define WAITING 1
#define RECEIVING 2
#define RECEIVED 3



class CmdMgr{
  public:
    int state;
    CmdMgr();
    void init();
    void processSerialData();
    void resetCmd();

  

};




#endif
