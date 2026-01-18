#ifndef STORMMANAGER_H
#define STORMMANAGER_H

#include "defines.h"

class StormManager {
public:
    // address=[0x164db60]
    static void __cdecl CreateInstance(void);

    // address=[0x164dc00]
    static void __cdecl DestroyInstance(void);

    // address=[0x164dc40]
    static class StormManager * __cdecl GetInstance(void);

    // address=[0x164dc50]
    void  Initialize(void);

    // address=[0x164ddb0]
    void  UpdateGlobalController(void);

    // address=[0x164de30]
    void  Update(void);

    // address=[0x164dea0]
    void  Shutdown(void);

    // address=[0x164e3d0]
    void  CloseSession(void);

    // address=[0x164e530]
    void  SearchForSessions(void);

    // address=[0x164ea30]
    void  LeaveSession(void);

    // address=[0x164ef80]
    void  SetJoinAndDiscoveryOverride(bool a2);

    // address=[0x164f240]
    void  DeleteSessionHandler(void);

    // address=[0x164fc90]
    void  SetFreeSlotCount(int a2);

    // address=[0x164fd90]
    int  GetLocalPeerId(void)const;

    // address=[0x164fdb0]
    int  GetHostPeerId(void)const;

    // address=[0x164fdd0]
    bool  IsLocalPeerId(int a2)const;

    // address=[0x164fe00]
    bool  IsLoggedIn(void)const;

    // address=[0x164fe40]
    bool  IsNATReady(void)const;

    // address=[0x164fe60]
    enum SESSION_STATE  StormManager::GetSessionState(void)const;

    // address=[0x1682f40]
     StormManager(void);

    // address=[0x1684f90]
     ~StormManager(void);

private:
    // address=[0x164ff50]
    void  InitControllers(void);

    // address=[0x164ffa0]
    void  SetupStormLogs(void);

    // address=[0x1650020]
    void  ShutdownStormLogs(void);

    // address=[0x1650070]
    void  StartupStormCore(void);

    // address=[0x16501d0]
    void  StopStormCore(void);

    // address=[0x1650390]
    void  CreateStormControllers(void);

    // address=[0x1650c50]
    void  DestroyStormControllers(void);

    // address=[0x1650cf0]
    void  RegisterStormControllers(void);

    // address=[0x1650d30]
    void  UnregisterStormControllers(void);

    // address=[0x1650d70]
    void  InitAndStartupEcho(void);

    // address=[0x16513d0]
    void  OnStartEchoFinished(void);

    // address=[0x16513e0]
    void  ShutdownEcho(void);

    // address=[0x462bb88]
    static class StormManager * m_instance;

};


#endif // STORMMANAGER_H
