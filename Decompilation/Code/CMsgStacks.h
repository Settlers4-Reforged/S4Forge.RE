#ifndef CMSGSTACKS_H
#define CMSGSTACKS_H

class CMsgStacks {
public:
    // address=[0x15c4910]
    void  AdvanceValidTick(void);

    // address=[0x15c4940]
    void  AdvanceVirtualTick(void);

    // address=[0x15c4a20]
    unsigned int  GetLastMsgTime(unsigned int);

    // address=[0x15c4aa0]
    int  GetNumberOfStacks(void);

    // address=[0x15c4ca0]
    int  GetValidTick(void);

    // address=[0x15c4cc0]
    int  GetVirtualTick(void);

    // address=[0x15c4ce0]
    int  Getdt(void);

    // address=[0x15c4d60]
    bool  IsStackAI(unsigned int);

    // address=[0x15c4e10]
    void  SetLastMsgTime(unsigned int,unsigned int,bool);

    // address=[0x15cb660]
    bool  TriggerTime(void);

    // address=[0x15cb780]
     CMsgStacks(int,int,int);

    // address=[0x15cb850]
    virtual  ~CMsgStacks(void);

    // address=[0x15cb920]
    bool  PushMsg(class CNet_Event &);

    // address=[0x15cba00]
    class CNet_Event  PopMsg(void);

    // address=[0x15cbae0]
    bool  AddNewPlayer(void);

    // address=[0x15cbba0]
    int  GetNumPlayers(void);

    // address=[0x15cbbc0]
    bool  SetNumberOfClients(unsigned int);

    // address=[0x15cbc00]
    class CMsgStack *  Get(unsigned int,unsigned char);

    // address=[0x15cbc30]
    bool  IsEmpty(unsigned int);

    // address=[0x15cbc90]
    class CNet_Event  GetMsgToSend(void);

    // address=[0x15cbd50]
    void  SetNumberOfExpectedMsgs(unsigned int,unsigned char,unsigned char);

    // address=[0x15cbe20]
    bool  IsSizeAlreadySet(unsigned int,unsigned char);

    // address=[0x15cbe90]
    bool  IsMsgStackValid(unsigned int,unsigned int &);

    // address=[0x15cbf80]
    void  SetStackAI(unsigned int,bool);

    // address=[0x15cc000]
    bool  IsInStack(class CNet_Event &);

    // address=[0x15cc0a0]
    void  ClearAndValidate(int);

    // address=[0x15cc0f0]
    void  OnEndSaving(int,int);

private:
    // address=[0x15cc140]
    bool  InitStacks(void);

};


#endif // CMSGSTACKS_H
