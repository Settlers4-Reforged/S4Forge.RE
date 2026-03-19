#ifndef IEVENTENGINE_H
#define IEVENTENGINE_H

#include "defines.h"

#include "CEvn_HandleList.h"

#include <windef.h>

extern class IEventEngine *g_pEvnEngine;


class IEventEngine {
public:
    // address=[0x1352c00]
    IEventEngine(void);

    // address=[0x1352c90]
    virtual ~IEventEngine(void);

    // address=[0x1352d70]
    void *GetEventFunction(void);

    // address=[0x1352d80]
    bool OnEvent(class CEvn_Event &a2);

    // address=[0x1352f90]
    bool SendRawWindowEvent(unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5);

    // address=[0x1353090]
    bool SendRawLogicEvent(unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7);

    // address=[0x1353190]
    bool SendRawEvent(unsigned int a2, unsigned int a3, unsigned int a4);

    // address=[0x1353280]
    bool RegisterHandle(class IEvn_Handle *a2);

    // address=[0x1353390]
    bool SendAMessage(class CEvn_Event &_rEvent);

    // address=[0x13533b0]
    bool UnRegisterHandle(class IEvn_Handle *a2);

    // address=[0x1353500]
    bool DispatchSystemMessages(void);

    // address=[0x13537d0]
    void SetOSParam(unsigned int a2);

    // address=[0x13537f0]
    bool PlayEvents(std::string const &_pReplayFile, int _iReplayStopOffset);

    // address=[0x1353a60]
    bool RecordEvents(std::string const &_pTargetFile);

    // address=[0x1353b60]
    void SetGuiEventProc(bool (__cdecl *a2)(struct SEventStruct &));

    // address=[0x1355880]
    bool IsEventEngineLocked(void);

    // address=[0x135e0f0]
    void SetOSParam1(unsigned int a2);

    // address=[0x148fed0]
    void LockEventEngine(bool a2);

    // address=[0x14aaba0]
    unsigned int GetCurrentTickCounter(void);

    // address=[0x14ab030]
    void SetTickPointer(unsigned int *a2);

    // address=[0x14b4720]
    bool IsEventPlaying(void);

    // address=[0x14b4740]
    bool IsEventRecording(void);

    // address=[0x1358690]
    static void Init(void);

    // Type information members
public:
    CEvn_HandleList *m_pEventHandleList;
    int              m_pOSParam;
    unsigned int     m_hWnd;
    HANDLE           m_hReplayFile;
    bool             m_bIsEventRecording;
    bool             m_bIsEventPlaying;
    //_BYTE[2] pad_16;
    unsigned int *m_pTick;
    bool          m_bLocked;
    //_BYTE[3] gap_1D;
    uint32_t m_uLastReplayTick;

    bool (__cdecl *m_pGuiEventProc)(struct SEventStruct &);

private:
    static const int replayFileVersion = 0x1C;
};

#endif // IEVENTENGINE_H
