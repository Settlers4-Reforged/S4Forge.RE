#ifndef CGUIGAMESTATE_H
#define CGUIGAMESTATE_H

class CGuiGameState : public CGameState {
public:
    // address=[0x1372120]
    virtual bool  OnEvent(class CEvn_Event &);

    // address=[0x149f3e0]
     CGuiGameState(void);

    // address=[0x149f410]
    virtual  ~CGuiGameState(void);

protected:
    // address=[0x1372150]
    void  EnsureGfxEngineIsInGuiMode(void);

    // address=[0x1372180]
    void  SetupGui(wchar_t const *,int,bool (__cdecl*)(int,int,int),int);

    // address=[0x1372230]
    void  SetupGuiWithExtra(wchar_t const *,int,bool (__cdecl*)(int,int,int),class IExtraCD *);

    // address=[0x13722f0]
    void  SetupExtraGui(class IExtraCD *,int,bool (__cdecl*)(int,int,int));

    // address=[0x1372380]
    bool  OpenDialog(int,bool (__cdecl*)(int,int,int));

    // address=[0x14a3530]
    void  SetupGui(wchar_t const *,int,bool (__cdecl*)(int,int,int));

private:
    // address=[0x13723d0]
    bool  InitGuiEngine(char *,int,bool (__cdecl*)(int,int,int));

    // address=[0x13724c0]
    void  AlignDialogsInScreenCenter(void);

};


#endif // CGUIGAMESTATE_H
