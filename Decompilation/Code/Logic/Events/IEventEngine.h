#ifndef IEVENTENGINE_H
#define IEVENTENGINE_H

class IEventEngine {
public:
    // address=[0x1352c00]
     IEventEngine(void);

    // address=[0x1352c90]
    virtual  ~IEventEngine(void);

    // address=[0x1352d70]
    void *  GetEventFunction(void);

    // address=[0x1352d80]
    bool  OnEvent(class CEvn_Event &);

    // address=[0x1352f90]
    bool  SendRawWindowEvent(unsigned int,unsigned int,unsigned int,unsigned int);

    // address=[0x1353090]
    bool  SendRawLogicEvent(unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int);

    // address=[0x1353190]
    bool  SendRawEvent(unsigned int,unsigned int,unsigned int);

    // address=[0x1353280]
    bool  RegisterHandle(class IEvn_Handle *);

    // address=[0x1353390]
    bool  SendAMessage(class CEvn_Event &);

    // address=[0x13533b0]
    bool  UnRegisterHandle(class IEvn_Handle *);

    // address=[0x1353500]
    bool  DispatchSystemMessages(void);

    // address=[0x13537d0]
    void  SetOSParam(unsigned int);

    // address=[0x13537f0]
    bool  PlayEvents(std::string const &,int);

    // address=[0x1353a60]
    bool  RecordEvents(std::string const &);

    // address=[0x1353b60]
    void  SetGuiEventProc(bool (__cdecl*)(struct SEventStruct &));

    // address=[0x1355880]
    bool  IsEventEngineLocked(void);

    // address=[0x135e0f0]
    void  SetOSParam1(unsigned int);

    // address=[0x148fed0]
    void  LockEventEngine(bool);

    // address=[0x14aaba0]
    unsigned int  GetCurrentTickCounter(void);

    // address=[0x14ab030]
    void  SetTickPointer(unsigned int *);

    // address=[0x14b4720]
    bool  IsEventPlaying(void);

    // address=[0x14b4740]
    bool  IsEventRecording(void);

};


#endif // IEVENTENGINE_H
