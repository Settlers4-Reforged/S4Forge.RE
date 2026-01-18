#ifndef CGAMESTATEHANDLER_H
#define CGAMESTATEHANDLER_H

#include "defines.h"

class CGameStateHandler {
public:
    // address=[0x148ac10]
    static bool __cdecl Init(void);

    // address=[0x148b240]
    static bool __cdecl Perform(void);

    // address=[0x148b530]
    static bool __cdecl CanProcessInvites(void);

    // address=[0x148b560]
    static void __cdecl Kill(void);

    // address=[0x148b900]
    static bool __cdecl InitGfxEngine(void);

    // address=[0x148ba60]
    static bool __cdecl InitSoundEngine(void);

    // address=[0x148bc10]
    static bool __cdecl InitGfxManager(void);

    // address=[0x148be00]
    static bool __cdecl InitSoundManager(void);

    // address=[0x148bea0]
    static bool __cdecl InitConfigManager(void);

    // address=[0x148c0f0]
    static bool __cdecl InitStringEngine(void);

    // address=[0x148c130]
    static bool __cdecl InitFileLibrary(void);

    // address=[0x148c140]
    static bool __cdecl InitGfxCompiler(void);

    // address=[0x148c1b0]
    static void __cdecl DietmarsGameSettingsDefaults(void);

    // address=[0x148c260]
    static void __cdecl LoadAllConfigFiles(void);

    // address=[0x148c400]
    static bool __cdecl RebuildGfxEngine(bool a1);

    // address=[0x148c590]
    static bool __cdecl CheckGfxRenderQuality(unsigned int a1);

    // address=[0x148c5d0]
    static bool __cdecl CheckGfxHardwareMode(unsigned int a1);

    // address=[0x148c620]
    static bool __cdecl ShowHTMLPage(std::string a1, std::string a2);

    // address=[0x148c880]
    static void __cdecl SetCorrectWindowSize(void);

    // address=[0x148fef0]
    static void __cdecl Queue(class CGameState * (__cdecl*)(void *) a1, void * a2);

    // address=[0x1490010]
    static void __cdecl Switch(class CGameState * (__cdecl*)(void *) a1, void * a2);

    // address=[0x14a1d40]
    static void __cdecl Next(void);

    // address=[0x14aae20]
    static bool __cdecl IsGrabbing(void);

    // address=[0x15c4a10]
    static class CGameState * __cdecl GetCurrentState(void);

private:
    // address=[0x148c9a0]
    static void __cdecl LoadConfigFile(wchar_t const * String, char const * a2);

    // address=[0x148cac0]
    static bool __cdecl StartDummyGame(void);

    // address=[0x148d250]
    static void __cdecl PerformPendingFullScreenEnterOrExit(void a1);

    // address=[0x148d290]
    static bool __cdecl BuildInitRenderCfg(bool a1, bool a2);

    // address=[0x3d89b2c]
    static bool m_bAppActive;

    // address=[0x3f455f8]
    static class CGameState * m_s_pCurrentState;

    // address=[0x3f455fc]
    static unsigned int m_uiLastTime;

    // address=[0x3f45600]
    static bool m_bWantSwitch;

    // address=[0x3f45601]
    static bool m_bQuitApplication;

    // address=[0x3f45602]
    static bool m_bShowLogo;

    // address=[0x3f45603]
    static bool m_bGrab;

    // address=[0x3f45604]
    static struct SGfxRenderConfiguration m_sRenderCfg;

    // address=[0x3f45668]
    static class std::list<struct SStateCommand,class std::allocator<struct SStateCommand> > m_listQueuedStates;

};


#endif // CGAMESTATEHANDLER_H
