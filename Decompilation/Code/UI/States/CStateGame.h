#ifndef CSTATEGAME_H
#define CSTATEGAME_H

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
    class CEvn_Logic  PopMessage(void);

    // address=[0x1486df0]
    class CGameData &  GameData(void);

    // address=[0x14a52f0]
    static class CGameState * __cdecl DynamicCreateFunc(void *);

    // address=[0x14a5370]
    void  UpdateToGuiInfoStruct(void);

    // address=[0x14a5950]
    void  UpdateFromGuiInfoStruct(void);

    // address=[0x14a5b90]
    void  UpdateMusicSettings(void);

    // address=[0x14a5d70]
    bool  IsInMinimap(struct tagPOINT *,struct tagPOINT *);

    // address=[0x14a5e00]
    bool  RenderFrame(void);

    // address=[0x14a5e50]
    void  PerformCommand(std::string);

    // address=[0x14a5f80]
    void  SetupGUI(void);

    // address=[0x14a61c0]
    void  ExitGUI(void);

    // address=[0x14a62a0]
    bool  InitGuiEngine(char *);

    // address=[0x14a6430]
    void  EndGame(void);

    // address=[0x14a6900]
    bool  SwitchPause(void);

    // address=[0x14a69e0]
    void  SendLogicMessage(unsigned int,unsigned int,long,unsigned int,unsigned int,unsigned int);

    // address=[0x14a6b40]
    bool  IsCursorChangeAllowed(void);

    // address=[0x14a6b70]
    int  GetModifierState(void);

    // address=[0x14a6c20]
     CStateGame(void *);

    // address=[0x14a7a50]
    virtual  ~CStateGame(void);

    // address=[0x14a7bc0]
    virtual bool  Perform(void);

    // address=[0x14a87c0]
    float  GetZoomFactor(void);

    // address=[0x14a8820]
    void  NotifyGfxEngine(void);

    // address=[0x14a88b0]
    bool  EnableOrDisableDebugString(bool);

    // address=[0x14a8900]
    bool  CanSave(void);

    // address=[0x14a8980]
    void  SaveGame(enum SaveType);

    // address=[0x14ac920]
    void  ZoomIn(int);

    // address=[0x14ac980]
    void  ZoomOut(int);

    // address=[0x14ac9e0]
    void  UpdateTriangleSizePreservingWorldPosition(int);

    // address=[0x14aca40]
    void  UpdateZoomFactor(void);

    // address=[0x14acb10]
    void  VerifyWorldOffset(void);

    // address=[0x14acd30]
    void  HandleBorderScroll(void);

    // address=[0x14acdb0]
    void  ReadyToGo(void);

    // address=[0x14acde0]
    void  SetViewPos(unsigned int,unsigned int);

    // address=[0x14ace40]
    void  UpdateClientSize(void);

    // address=[0x14aceb0]
    virtual bool  OnEvent(class CEvn_Event &);

    // address=[0x14b1950]
    void  GetCenterWorldCoordinate(int &,int &);

    // address=[0x14b4890]
    void  ScrollHorizontal(bool);

    // address=[0x14b48e0]
    void  ScrollVertical(bool);

private:
    // address=[0x14a8a30]
    void  CheckAutosaveTimer(void);

};


#endif // CSTATEGAME_H
