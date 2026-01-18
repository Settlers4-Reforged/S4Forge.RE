#ifndef IEVENTENGINE_H
#define IEVENTENGINE_H

#include "defines.h"

class IEventEngine {
public:
    // address=[0x1352c00]
     IEventEngine(void);

    // address=[0x1352c90]
    virtual  ~IEventEngine(void);

    // address=[0x1352d70]
    void *  GetEventFunction(void);

    // address=[0x1352d80]
    bool  OnEvent(class CEvn_Event & a2);

    // address=[0x1352f90]
    bool  SendRawWindowEvent(unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5);

    // address=[0x1353090]
    bool  SendRawLogicEvent(unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7);

    // address=[0x1353190]
    bool  SendRawEvent(unsigned int a2, unsigned int a3, unsigned int a4);

    // address=[0x1353280]
    bool  RegisterHandle(class IEvn_Handle * a2);

    // address=[0x1353390]
    bool  SendAMessage(class CEvn_Event & a2);

    // address=[0x13533b0]
    bool  UnRegisterHandle(class IEvn_Handle * a2);

    // address=[0x1353500]
    bool  DispatchSystemMessages(void);

    // address=[0x13537d0]
    void  SetOSParam(unsigned int a2);

    // address=[0x13537f0]
    bool  PlayEvents(std::string const & a2, int a3);

    // address=[0x1353a60]
    bool  RecordEvents(std::string const & a2);

    // address=[0x1353b60]
    void  SetGuiEventProc(bool (__cdecl*)(struct SEventStruct &) a2);

    // address=[0x1355880]
    bool  IsEventEngineLocked(void);

    // address=[0x135e0f0]
    void  SetOSParam1(unsigned int a2);

    // address=[0x148fed0]
    void  LockEventEngine(bool a2);

    // address=[0x14aaba0]
    unsigned int  GetCurrentTickCounter(void);

    // address=[0x14ab030]
    void  SetTickPointer(unsigned int * a2);

    // address=[0x14b4720]
    bool  IsEventPlaying(void);

    // address=[0x14b4740]
    bool  IsEventRecording(void);

    // Type information members
private:
    struct CEvn_HandleList * EventHandleList;
    _BYTE[4] gap_8;
    _DWORD hwnd;
    int logFileHandle;
    BYTE loggingEnabled;
    _BYTE[3] pad_15;
    int tick;
    char m_bLocked;
    _BYTE[3] gap_1D;
    int field_20;
    unsigned __int8 (__cdecl *)(struct SEventStruct *) activePrimaryHandler;

};


#endif // IEVENTENGINE_H
