#ifndef CMSGSTACKS_H
#define CMSGSTACKS_H

#include "defines.h"

class CMsgStacks {
public:
    // address=[0x15c4910]
    void  AdvanceValidTick(void);

    // address=[0x15c4940]
    void  AdvanceVirtualTick(void);

    // address=[0x15c4a20]
    unsigned int  GetLastMsgTime(unsigned int a2);

    // address=[0x15c4aa0]
    int  GetNumberOfStacks(void);

    // address=[0x15c4ca0]
    int  GetValidTick(void);

    // address=[0x15c4cc0]
    int  GetVirtualTick(void);

    // address=[0x15c4ce0]
    int  Getdt(void);

    // address=[0x15c4d60]
    bool  IsStackAI(unsigned int a2);

    // address=[0x15c4e10]
    void  SetLastMsgTime(unsigned int a2, unsigned int a3, bool a4);

    // address=[0x15cb660]
    bool  TriggerTime(void);

    // address=[0x15cb780]
     CMsgStacks(int a2, int a3, int a4);

    // address=[0x15cb850]
    virtual  ~CMsgStacks(void);

    // address=[0x15cb920]
    bool  PushMsg(class CNet_Event & a2);

    // address=[0x15cba00]
    class CNet_Event  PopMsg(void a2);

    // address=[0x15cbae0]
    bool  AddNewPlayer(void);

    // address=[0x15cbba0]
    int  GetNumPlayers(void);

    // address=[0x15cbbc0]
    bool  SetNumberOfClients(unsigned int a2);

    // address=[0x15cbc00]
    class CMsgStack *  Get(unsigned int a2, unsigned char a3);

    // address=[0x15cbc30]
    bool  IsEmpty(unsigned int a2);

    // address=[0x15cbc90]
    class CNet_Event  GetMsgToSend(void a2);

    // address=[0x15cbd50]
    void  SetNumberOfExpectedMsgs(unsigned int a2, unsigned char a3, unsigned char a4);

    // address=[0x15cbe20]
    bool  IsSizeAlreadySet(unsigned int a2, unsigned char a3);

    // address=[0x15cbe90]
    bool  IsMsgStackValid(unsigned int a2, unsigned int & a3);

    // address=[0x15cbf80]
    void  SetStackAI(unsigned int a2, bool a3);

    // address=[0x15cc000]
    bool  IsInStack(class CNet_Event & a2);

    // address=[0x15cc0a0]
    void  ClearAndValidate(int a2);

    // address=[0x15cc0f0]
    void  OnEndSaving(int a2, int a3);

private:
    // address=[0x15cc140]
    bool  InitStacks(void);

};


#endif // CMSGSTACKS_H
