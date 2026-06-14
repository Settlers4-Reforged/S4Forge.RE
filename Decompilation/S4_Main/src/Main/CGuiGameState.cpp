#include "CGuiGameState.h"

#include "CBB/CBBSupport.h"
#include "CGameSettings.h"
#include "CGameStateHandler.h"
#include "Debug/CTrace.h"
#include "File/CFile.h"
#include "File/CFileEx.h"
#include "Framework.h"
#include "Logic/Events/CEvn_Event.h"

// Definitions for class CGuiGameState

// address=[0x1372120]
// Decompiled from int __thiscall CGuiGameState::OnEvent(CGuiGameState *this, struct CEvn_Event *a2)
bool CGuiGameState::OnEvent(class CEvn_Event &_rEvent) {
    if(_rEvent.m_iEventId == 3)
        CGuiGameState::AlignDialogsInScreenCenter();
    return CGameState::OnEvent(_rEvent);
}

// address=[0x149f3e0]
// Decompiled from CGuiGameState *__thiscall CGuiGameState::CGuiGameState(CGuiGameState *this)
CGuiGameState::CGuiGameState(void) : CGameState() {
}

// address=[0x149f410]
// Decompiled from void __thiscall CGuiGameState::~CGuiGameState(CGuiGameState *this)
CGuiGameState::~CGuiGameState(void) = default;

// address=[0x1372150]
// Decompiled from char __thiscall CGuiGameState::EnsureGfxEngineIsInGuiMode(void *this)
void CGuiGameState::EnsureGfxEngineIsInGuiMode(void) {
    if(!g_pGfxEngine) {
        CGameStateHandler::RebuildGfxEngine(1);
        return;
    }

    if(!g_pGfxEngine->IsGuiMode(this))
        CGameStateHandler::RebuildGfxEngine(1);
}

// address=[0x4031D10]
char *g_pDialogData;

void __cdecl ReadDialogData(wchar_t const *FileName) {
    // eax
    // eax
    // [esp+4h] [ebp-84h]

    if(!g_pDialogData) {
        CFileEx file{};
        file.Open(FileName, CFile::CFile_BINARY | CFile::CFile_READ, 0, CFileLog);
        size_t iFileSize = file.Size();
        g_pDialogData = new char[iFileSize];
        int iSize = file.Read(g_pDialogData, 1, file.Size(), CFileLog);
        BB_ASSERT(iSize == file.Size())
        file.Close(CFileLog);
    }
}

// address=[0x1372180]
// Decompiled from void __thiscall CGuiGameState::SetupGui(  CGuiGameState *this,  wchar_t *FileName,  int a3,  bool (__cdecl *a4)(int, int, int),  int a5)
void CGuiGameState::SetupGui(wchar_t const *FileName, int a3, bool(__cdecl *a4)(int, int, int), int a5) {
    ReadDialogData(FileName);
    if(g_pGUIEngine) {
        bool bRet = g_pGUIEngine->OpenDialog(a5, a4);
        BB_ASSERT(bRet)
    } else if(!CGuiGameState::InitGuiEngine(g_pDialogData, a3, a4)) {
        MessageBoxA(g_hWnd, "Error initializing User Interface!\nFehler beim Erstellen des User Interfaces!", "S4", 0x30u);
        exit(0);
    }
    CGuiGameState::AlignDialogsInScreenCenter();
}

// address=[0x1372230]
// Decompiled from void __thiscall CGuiGameState::SetupGuiWithExtra(  CGuiGameState *this,  wchar_t *FileName,  int a3,  bool (__cdecl *a4)(int, int, int),  struct IExtraCD *pExtraCD)
void CGuiGameState::SetupGuiWithExtra(wchar_t const *FileName, int a3, bool(__cdecl *a4)(int, int, int), class IExtraCD *pExtraCD) {

    ReadDialogData(FileName);
    if(g_pGUIEngine) {
        pExtraCD->EnsureExtraGUI(pExtraCD, a3, a4);
        if(!g_pGUIEngine->OpenDialog(a3, a4) && BBSupportDbgReport(2, "Main\\States\\GuiGameState.cpp", 94, "bRet") == 1) {
            __debugbreak();
        }
    } else if(!CGuiGameState::InitGuiEngine(g_pDialogData, a3, a4)) {
        MessageBoxA(g_hWnd, "Error initializing User Interface!\nFehler beim Erstellen des User Interfaces!", "S4", 0x30u);
        exit(0);
    }
    CGuiGameState::AlignDialogsInScreenCenter();
}

// address=[0x13722f0]
// Decompiled from void __thiscall CGuiGameState::SetupExtraGui(  CGuiGameState *this,  struct IExtraCD *addon,  int a3,  bool (__cdecl *a4)(int, int, int))
void CGuiGameState::SetupExtraGui(class IExtraCD *addon, int a3, bool(__cdecl *a4)(int, int, int)) {
    if(!addon && BBSupportDbgReport(2, "Main\\States\\GuiGameState.cpp", 126, "addon") == 1)
        __debugbreak();
    addon->EnsureExtraGUI(addon, a3, a4);
    if(!g_pGfxEngine->IsGuiMode()) {
        BB_REPORT("GfxEngine not in GUI Mode after GFX switch!")
    }
    CGuiGameState::AlignDialogsInScreenCenter();
}

// address=[0x1372380]
// Decompiled from char __thiscall CGuiGameState::OpenDialog(CGuiGameState *this, int a2, bool (__cdecl *a3)(int, int, int))
bool CGuiGameState::OpenDialog(int a2, bool(__cdecl *a3)(int, int, int)) {

    // [esp+7h] [ebp-1h]

    char bRet = g_pGUIEngine->OpenDialog(a2, a3);
    BB_ASSERT(bRet)
    return bRet;
}

// address=[0x14a3530]
// Decompiled from void __thiscall CGuiGameState::SetupGui(  CGuiGameState *this,  const wchar_t *a2,  int a3,  bool (__cdecl *a4)(int, int, int))
void CGuiGameState::SetupGui(wchar_t const *a2, int a3, bool(__cdecl *a4)(int, int, int)) {

    CGuiGameState::SetupGui(this, a2, a3, a4, a3);
}

// TODO: Move to IGuiEngine
int GetGuiInterfaceVersion() {
    return 120;
}

// address=[0x13723d0]
// Decompiled from char __thiscall CGuiGameState::InitGuiEngine(CGuiGameState *this, char *a2, int a3, bool (__cdecl *a4)(int, int, int))
bool CGuiGameState::InitGuiEngine(char *a2, int a3, bool(__cdecl *a4)(int, int, int)) {
    if(g_pGUIEngine)
        return 0;
    if(GetGuiInterfaceVersion() == 120) {
        g_pGUIEngine = new IGuiEngine();
        int Language = CGameSettings::GetLanguage();
        g_pGUIEngine->Init(g_pGfxEngine, g_pGfxManager, a2, a3, a4, Language);
        return 1;
    } else {
        MessageBoxA(g_hWnd, "Wrong version of GUI engine!", "Error:", 0x30u);
        CTrace::Print("Wrong version of GUI engine!");
        return 0;
    }
}

// address=[0x13724c0]
// Decompiled from void __thiscall CGuiGameState::AlignDialogsInScreenCenter(CGuiGameState *this)
void CGuiGameState::AlignDialogsInScreenCenter(void) {

    // [esp+10h] [ebp-28h]
    // [esp+14h] [ebp-24h]
    // [esp+18h] [ebp-20h]
    // [esp+1Ch] [ebp-1Ch]
    // [esp+28h] [ebp-10h]
    // [esp+2Ch] [ebp-Ch]
    // [esp+30h] [ebp-8h]

    BB_ASSERT(g_pGfxEngine != nullptr)
    if(!g_pGfxEngine)
        return;

    BB_ASSERT(g_pGUIEngine != nullptr)
    if(!g_pGUIEngine)
        return;

    float v5 = (float)g_pResolutions[1].m_iWidth / (float)g_pResolutions[1].m_iHeight;
    IGfxEngine::GetOutputWidth(g_pGfxEngine);
    int OutputHeight = IGfxEngine::GetOutputHeight(g_pGfxEngine);
    int v6 = (int)(float)((float)OutputHeight * v5);
    float v3 = (float)v6 / (float)g_pResolutions[1].m_iWidth;
    float v4 = (float)OutputHeight / (float)g_pResolutions[1].m_iHeight;
    int v1 = (int)((double)(IGfxEngine::GetOutputWidth(g_pGfxEngine) - v6) * 0.5);
    int v2 = (int)((double)(IGfxEngine::GetOutputHeight(g_pGfxEngine) - OutputHeight) * 0.5);
    g_pGUIEngine->SetDialogsRenderOffset(v1, v2, v3, v4);
}
