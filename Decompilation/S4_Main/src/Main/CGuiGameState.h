#ifndef CGUIGAMESTATE_H
#define CGUIGAMESTATE_H

#include "CGameState.h"
#include "defines.h"

class CGuiGameState : public CGameState {
  public:
    // address=[0x1372120]
    virtual bool OnEvent(CEvn_Event &_rEvent);

    // address=[0x149f3e0]
    CGuiGameState(void);

    // address=[0x149f410]
    virtual ~CGuiGameState(void);

  protected:
    // address=[0x1372150]
    void EnsureGfxEngineIsInGuiMode(void);

    // address=[0x1372180]
    void SetupGui(wchar_t const *FileName, int a3, bool(__cdecl *a4)(int, int, int), int a5);

    // address=[0x1372230]
    void SetupGuiWithExtra(wchar_t const *FileName, int a3, bool(__cdecl *a4)(int, int, int), class IExtraCD *pExtraCD);

    // address=[0x13722f0]
    void SetupExtraGui(class IExtraCD *addon, int a3, bool(__cdecl *a4)(int, int, int));

    // address=[0x1372380]
    bool OpenDialog(int a2, bool(__cdecl *a3)(int, int, int));

    // address=[0x14a3530]
    void SetupGui(wchar_t const *a2, int a3, bool(__cdecl *a4)(int, int, int));

  private:
    // address=[0x13723d0]
    bool InitGuiEngine(char *a2, int a3, bool(__cdecl *a4)(int, int, int));

    // address=[0x13724c0]
    void AlignDialogsInScreenCenter(void);
};

#endif // CGUIGAMESTATE_H
