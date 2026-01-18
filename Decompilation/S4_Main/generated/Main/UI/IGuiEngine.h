#ifndef IGUIENGINE_H
#define IGUIENGINE_H

#include "defines.h"

class IGuiEngine {
public:
    // address=[0x13d8b60]
    int  GetDialogsRenderOffsetX(void)const;

    // address=[0x13d8b80]
    int  GetDialogsRenderOffsetY(void)const;

    // address=[0x13d8ba0]
    float  GetDialogsRenderScaleX(void)const;

    // address=[0x13d8bc0]
    float  GetDialogsRenderScaleY(void)const;

    // address=[0x2f9b380]
    bool  OpenDialog(int a2, bool (__cdecl*)(int,int,int) a3);

    // address=[0x2f9fea0]
     IGuiEngine(void);

    // address=[0x2f9ff60]
     ~IGuiEngine(void);

    // address=[0x2f9fff0]
    bool  Init(class IGfxEngine * a2, class CGfxManager * a3, void * a4, int a5, bool (__cdecl*)(int,int,int) a6, int a7);

    // address=[0x2fa0320]
    void  RefreshAllSurfaces(void);

    // address=[0x2fa0670]
    bool  CloseDialog(int a2);

    // address=[0x2fa08c0]
    bool  RenderGui(void);

    // address=[0x2fa08e0]
    void  EnableEventInput(bool a2);

    // address=[0x2fa0910]
    void  EnableShortcuts(bool a2);

    // address=[0x2fa0920]
    void  SetCtrlStatusCallback(bool (__cdecl*)(int,int,int,bool,int) a2);

    // address=[0x2fa0fc0]
    void  SetDialogsRenderOffset(int a2, int a3, float a4, float a5);

    // address=[0x2fa1000]
    bool  GetDialogRect(int a2, struct SGuiRect & a3);

    // address=[0x2fa1090]
    bool  SetDialogRect(int a2, struct SGuiRect a3);

    // address=[0x2fa1140]
    bool  MoveDialogTo(int a2, int a3, int a4);

    // address=[0x2fa11c0]
    bool  GetDialogRenderRect(int a2, struct SGuiRect & a3);

    // address=[0x2fa12b0]
    bool  SetDialogRenderPos(int a2, int a3, int a4);

    // address=[0x2fa12e0]
    void  EnableTooltipsExt(bool a2);

    // address=[0x2fa13a0]
    void  SetDlgToIgnore(int a2, bool a3);

    // address=[0x2fa13f0]
    bool  SetTooltip(char const * Str);

    // address=[0x2fa1430]
    bool  SetTooltipExt(char const * Str);

    // address=[0x2fa1470]
    bool  SetTooltipID(int a2, int a3, int a4, int a5);

    // address=[0x2fa14d0]
    bool  DisableDialogControls(int a2);

    // address=[0x2fa1520]
    bool  SetText(int a2, int a3, char const * Str);

    // address=[0x2fa17e0]
    bool  SetEditProperties(int a2, int a3, unsigned char a4, unsigned char a5);

    // address=[0x2fa1870]
    bool  SetTypeAsButton(int a2, int a3);

    // address=[0x2fa1920]
    bool  SetTypeAsText(int a2, int a3);

    // address=[0x2fa1970]
    bool  SetTypeAsRadio(int a2, int a3, int a4, int a5);

    // address=[0x2fa1a00]
    bool  SetRadioCheckPressedState(int a2, int a3, bool a4);

    // address=[0x2fa1a50]
    char const *  GetText(int container, int valueLink);

    // address=[0x2fa1ac0]
    int  GetWrapPosition(int a2, int a3);

    // address=[0x2fa1c60]
    bool  SetFontTemplate(int a2, int a3, int a4);

    // address=[0x2fa1ce0]
    bool  EnableControl(int a2, int a3, bool a4);

    // address=[0x2fa1da0]
    bool  SetControlVisibility(int a2, int a3, bool a4);

    // address=[0x2fa1e10]
    bool  SetImages(int a2, int a3, int a4, int a5);

    // address=[0x2fa1ea0]
    bool  SetUserLogoImage(int a2, int a3, int a4);

    // address=[0x2fa1f10]
    bool  LockOwnerImage(int a2, int a3, struct SGuiRect & a4, unsigned short * & a5, unsigned int & a6);

    // address=[0x2fa2130]
    bool  UnlockOwnerImage(int a2, int a3);

    // address=[0x2fa21d0]
    bool  EraseOwnerImage(int a2, int a3);

    // address=[0x2fa2390]
    bool  SetSliderPosition(int a2, int a3, int a4);

    // address=[0x2fa2510]
    int  GetSliderPosition(int a2, int a3);

    // address=[0x2fa2580]
    bool  SelectControl(int a2, int a3, bool a4);

    // address=[0x2fa2700]
    bool  ResetRadioGroup(int a2, int a3);

    // address=[0x2fa27d0]
    bool  SetWidth(int a2, int a3, int a4);

    // address=[0x2fa2820]
    bool  SetPosition(int a2, int a3, int a4, int a5);

private:
    // address=[0x2fa0940]
    void  InitShadeTables(void);

    // address=[0x2fa0b80]
    static struct tagRECT __cdecl GetDialogDestinationRect(struct GUI_MENU_DIALOG_HEADER const & retstr, int a2, int a3, float a4, float a5);

};


#endif // IGUIENGINE_H
