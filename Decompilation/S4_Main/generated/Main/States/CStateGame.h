#ifndef CSTATEGAME_H
#define CSTATEGAME_H

#include "defines.h"

class CStateGame : public CGameState {
public:
    // address=[0x1303890]
    unsigned int  GetTickCounter(void);

    // address=[0x130f320]
    class CRandom16 &  Random16(void);

    // address=[0x1326f20]
    unsigned int  Rand(void);

    // address=[0x14606d0]
    bool  IsMessage(void);

    // address=[0x14607a0]
    class CEvn_Logic  PopMessage(void retstr);

    // address=[0x1486df0]
    class CGameData &  GameData(void);

    // address=[0x14a52f0]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14a5370]
    void  UpdateToGuiInfoStruct(void);

    // address=[0x14a5950]
    void  UpdateFromGuiInfoStruct(void);

    // address=[0x14a5b90]
    void  UpdateMusicSettings(void);

    // address=[0x14a5d70]
    bool  IsInMinimap(struct tagPOINT * a2, struct tagPOINT * a3);

    // address=[0x14a5e00]
    bool  RenderFrame(void);

    // address=[0x14a5e50]
    void  PerformCommand(std::string a1);

    // address=[0x14a5f80]
    void  SetupGUI(void);

    // address=[0x14a61c0]
    void  ExitGUI(void);

    // address=[0x14a62a0]
    bool  InitGuiEngine(char * a2);

    // address=[0x14a6430]
    void  EndGame(void);

    // address=[0x14a6900]
    bool  SwitchPause(void);

    // address=[0x14a69e0]
    void  SendLogicMessage(unsigned int a2, unsigned int a3, long a4, unsigned int a5, unsigned int a6, unsigned int a7);

    // address=[0x14a6b40]
    bool  IsCursorChangeAllowed(void);

    // address=[0x14a6b70]
    int  GetModifierState(void);

    // address=[0x14a6c20]
     CStateGame(void * a2);

    // address=[0x14a7a50]
    virtual  ~CStateGame(void);

    // address=[0x14a7bc0]
    virtual bool  Perform(void);

    // address=[0x14a87c0]
    float  GetZoomFactor(void);

    // address=[0x14a8820]
    void  NotifyGfxEngine(void);

    // address=[0x14a88b0]
    bool  EnableOrDisableDebugString(bool a2);

    // address=[0x14a8900]
    bool  CanSave(void);

    // address=[0x14a8980]
    void  SaveGame(enum SaveType a2);

    // address=[0x14ac920]
    void  ZoomIn(int a2);

    // address=[0x14ac980]
    void  ZoomOut(int a2);

    // address=[0x14ac9e0]
    void  UpdateTriangleSizePreservingWorldPosition(int a2);

    // address=[0x14aca40]
    void  UpdateZoomFactor(void);

    // address=[0x14acb10]
    void  VerifyWorldOffset(void);

    // address=[0x14acd30]
    void  HandleBorderScroll(void);

    // address=[0x14acdb0]
    void  ReadyToGo(void);

    // address=[0x14acde0]
    void  SetViewPos(unsigned int a2, unsigned int a3);

    // address=[0x14ace40]
    void  UpdateClientSize(void);

    // address=[0x14aceb0]
    virtual bool  OnEvent(class CEvn_Event & _sEvent);

    // address=[0x14b1950]
    void  GetCenterWorldCoordinate(int & a2, int & a3);

    // address=[0x14b4890]
    void  ScrollHorizontal(bool a2);

    // address=[0x14b48e0]
    void  ScrollVertical(bool a2);

private:
    // address=[0x14a8a30]
    void  CheckAutosaveTimer(void);

    // Type information members
public:
    _DWORD dword4;
    _DWORD m_uLastRenderTime;
    _DWORD dwordC;
    _DWORD dword10;
    std::vector m_vCRCHistory;
    std::vector m_vRandomHistory;
    _DWORD dword34;
    _DWORD dword38;
    _DWORD dword3C;
    _DWORD dword40;
    _BYTE m_bAllowDebugString;
    _BYTE byte45;
    _BYTE byte46;
    _BYTE byte47;
    _BYTE byte48;
    _BYTE byte49;
    _BYTE byte4A;
    _BYTE byte4C;
    CGameData m_sGameData;
    _BYTE[32] gapD4;
    _BYTE byteF4;
    _BYTE byteF5;
    _BYTE byteF6;
    _BYTE byteF7;
    _BYTE byteF8;
    CLogicRingBuffer * m_sLogicRingBuffer;
    _DWORD dword100;
    _DWORD dword104;
    _DWORD m_uClientSizeRelated210;
    _DWORD m_uClientSizeRelated;
    _DWORD m_uClientWidth;
    _DWORD m_uClientHeight;
    _DWORD dword118;
    _DWORD dword11C;
    _DWORD dword120;
    _BYTE byte124;
    _BYTE byte125;
    _BYTE byte126;
    _BYTE byte127;
    _DWORD m_uValidTick;
    _BYTE byte12C;
    _DWORD dword130;
    _DWORD field_134;
    _DWORD m_uGfxHighestResolution;
    _DWORD m_uGfxTextureQuality;
    BYTE field_140;
    _BYTE field_141;
    _BYTE[2] gap_142;
    _DWORD m_uGfxFiltering;
    BYTE field_148;
    _BYTE field_149;
    _BYTE[2] gap_14A;
    _DWORD field_14C;
    _DWORD m_uSoundFXVolume;
    _DWORD m_uMusicVolume;
    _DWORD m_uVoiceChatVolume;
    _DWORD m_uVoiceChatMicro;
    BYTE m_bMusicOn;
    _BYTE m_bSoundFxOn;
    BYTE m_bVoiceChatOn;
    _BYTE m_bUserMP3;
    _DWORD field_164;
    _DWORD m_bExtendedTooltip;
    BYTE m_bBorderScrollEnabled;
    _DWORD m_uScrollStepValue;
    BYTE m_bAlwaysUrgentMsg;
    _DWORD field_178;
    _DWORD m_uMsgLevelMask;
    _DWORD m_uMsgHistory;
    CChatInfo m_sChatInfo;

};


#endif // CSTATEGAME_H
