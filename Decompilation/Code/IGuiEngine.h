#ifndef IGUIENGINE_H
#define IGUIENGINE_H

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
    bool  OpenDialog(int,bool (__cdecl*)(int,int,int));

    // address=[0x2f9fea0]
     IGuiEngine(void);

    // address=[0x2f9ff60]
     ~IGuiEngine(void);

    // address=[0x2f9fff0]
    bool  Init(class IGfxEngine *,class CGfxManager *,void *,int,bool (__cdecl*)(int,int,int),int);

    // address=[0x2fa0320]
    void  RefreshAllSurfaces(void);

    // address=[0x2fa0670]
    bool  CloseDialog(int);

    // address=[0x2fa08c0]
    bool  RenderGui(void);

    // address=[0x2fa08e0]
    void  EnableEventInput(bool);

    // address=[0x2fa0910]
    void  EnableShortcuts(bool);

    // address=[0x2fa0920]
    void  SetCtrlStatusCallback(bool (__cdecl*)(int,int,int,bool,int));

    // address=[0x2fa0fc0]
    void  SetDialogsRenderOffset(int,int,float,float);

    // address=[0x2fa1000]
    bool  GetDialogRect(int,struct SGuiRect &);

    // address=[0x2fa1090]
    bool  SetDialogRect(int,struct SGuiRect);

    // address=[0x2fa1140]
    bool  MoveDialogTo(int,int,int);

    // address=[0x2fa11c0]
    bool  GetDialogRenderRect(int,struct SGuiRect &);

    // address=[0x2fa12b0]
    bool  SetDialogRenderPos(int,int,int);

    // address=[0x2fa12e0]
    void  EnableTooltipsExt(bool);

    // address=[0x2fa13a0]
    void  SetDlgToIgnore(int,bool);

    // address=[0x2fa13f0]
    bool  SetTooltip(char const *);

    // address=[0x2fa1430]
    bool  SetTooltipExt(char const *);

    // address=[0x2fa1470]
    bool  SetTooltipID(int,int,int,int);

    // address=[0x2fa14d0]
    bool  DisableDialogControls(int);

    // address=[0x2fa1520]
    bool  SetText(int,int,char const *);

    // address=[0x2fa17e0]
    bool  SetEditProperties(int,int,unsigned char,unsigned char);

    // address=[0x2fa1870]
    bool  SetTypeAsButton(int,int);

    // address=[0x2fa1920]
    bool  SetTypeAsText(int,int);

    // address=[0x2fa1970]
    bool  SetTypeAsRadio(int,int,int,int);

    // address=[0x2fa1a00]
    bool  SetRadioCheckPressedState(int,int,bool);

    // address=[0x2fa1a50]
    char const *  GetText(int,int);

    // address=[0x2fa1ac0]
    int  GetWrapPosition(int,int);

    // address=[0x2fa1c60]
    bool  SetFontTemplate(int,int,int);

    // address=[0x2fa1ce0]
    bool  EnableControl(int,int,bool);

    // address=[0x2fa1da0]
    bool  SetControlVisibility(int,int,bool);

    // address=[0x2fa1e10]
    bool  SetImages(int,int,int,int);

    // address=[0x2fa1ea0]
    bool  SetUserLogoImage(int,int,int);

    // address=[0x2fa1f10]
    bool  LockOwnerImage(int,int,struct SGuiRect &,unsigned short * &,unsigned int &);

    // address=[0x2fa2130]
    bool  UnlockOwnerImage(int,int);

    // address=[0x2fa21d0]
    bool  EraseOwnerImage(int,int);

    // address=[0x2fa2390]
    bool  SetSliderPosition(int,int,int);

    // address=[0x2fa2510]
    int  GetSliderPosition(int,int);

    // address=[0x2fa2580]
    bool  SelectControl(int,int,bool);

    // address=[0x2fa2700]
    bool  ResetRadioGroup(int,int);

    // address=[0x2fa27d0]
    bool  SetWidth(int,int,int);

    // address=[0x2fa2820]
    bool  SetPosition(int,int,int,int);

private:
    // address=[0x2fa0940]
    void  InitShadeTables(void);

    // address=[0x2fa0b80]
    static struct tagRECT __cdecl GetDialogDestinationRect(struct GUI_MENU_DIALOG_HEADER const &,int,int,float,float);

};


#endif // IGUIENGINE_H
