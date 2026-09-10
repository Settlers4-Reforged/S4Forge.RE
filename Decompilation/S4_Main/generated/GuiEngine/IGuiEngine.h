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
    bool  Init(class IGfxEngine * _pGfxEngine, class CGfxManager * _pGfxManager, void * _pFileHeader, int _iStartingDialogId, bool (__cdecl*)(int,int,int) _fpStartingDialogHandler, int _iLanguage);

    // address=[0x2fa0320]
    void  RefreshAllSurfaces(void);

    // address=[0x2fa0670]
    bool  CloseDialog(int _iContainer);

    // address=[0x2fa08c0]
    bool  RenderGui(void);

    // address=[0x2fa08e0]
    void  EnableEventInput(bool a2);

    // address=[0x2fa0910]
    void  EnableShortcuts(bool a2);

    // address=[0x2fa0920]
    void  SetCtrlStatusCallback(bool (__cdecl*)(int,int,int,bool,int) _fpCallback);

    // address=[0x2fa0fc0]
    void  SetDialogsRenderOffset(int a2, int a3, float a4, float a5);

    // address=[0x2fa1000]
    bool  GetDialogRect(int _iContainerId, struct SGuiRect & _rRect);

    // address=[0x2fa1090]
    bool  SetDialogRect(int a1, struct SGuiRect a3);

    // address=[0x2fa1140]
    bool  MoveDialogTo(int _iContainerId, int _iX, int _iY);

    // address=[0x2fa11c0]
    bool  GetDialogRenderRect(int _iContainerId, struct SGuiRect & _rRect);

    // address=[0x2fa12b0]
    bool  SetDialogRenderPos(int a2, int a3, int a4);

    // address=[0x2fa12e0]
    void  EnableTooltipsExt(bool _bEnabled);

    // address=[0x2fa13a0]
    void  SetDlgToIgnore(int _iContainerId, bool _bIgnore);

    // address=[0x2fa13f0]
    bool  SetTooltip(char const * _spText);

    // address=[0x2fa1430]
    bool  SetTooltipExt(char const * _spText);

    // address=[0x2fa1470]
    bool  SetTooltipID(int _iContainerId, int _iControlId, int _iTooltip, int _iTooltipExtra);

    // address=[0x2fa14d0]
    bool  DisableDialogControls(int _iContainerId);

    // address=[0x2fa1520]
    bool  SetText(int _iContainer, int _iControlId, char const * _spText);

    // address=[0x2fa17e0]
    bool  SetEditProperties(int _iContainer, int _iControl, unsigned char _iProp1, unsigned char _iProp2);

    // address=[0x2fa1870]
    bool  SetTypeAsButton(int _iContainer, int _iControl);

    // address=[0x2fa1920]
    bool  SetTypeAsText(int _iContainer, int _iControl);

    // address=[0x2fa1970]
    bool  SetTypeAsRadio(int a2, int a3, int a4, int a5);

    // address=[0x2fa1a00]
    bool  SetRadioCheckPressedState(int a2, int a3, bool a4);

    // address=[0x2fa1a50]
    char const *  GetText(int container, int valueLink);

    // address=[0x2fa1ac0]
    int  GetWrapPosition(int _iContainerId, int _iControlId);

    // address=[0x2fa1c60]
    bool  SetFontTemplate(int _iContainerId, int _iControlId, int _iTemplate);

    // address=[0x2fa1ce0]
    bool  EnableControl(int _iContainerId, int _iControlId, bool a4);

    // address=[0x2fa1da0]
    bool  SetControlVisibility(int _iContainerId, int _iControlId, bool _bVisible);

    // address=[0x2fa1e10]
    bool  SetImages(int _iContainer, int _iControl, int _iMainTextureId, int _iPressedTextureId);

    // address=[0x2fa1ea0]
    bool  SetUserLogoImage(int _iContainerId, int _iControlId, int _iImageId);

    // address=[0x2fa1f10]
    bool  LockOwnerImage(int _iContainerId, int _iControlId, struct SGuiRect & _rRect, unsigned short * & _rSurface, unsigned int & _rPitch);

    // address=[0x2fa2130]
    bool  UnlockOwnerImage(int _iContainerId, int _iControlId);

    // address=[0x2fa21d0]
    bool  EraseOwnerImage(int _iContainerId, int _iControlId);

    // address=[0x2fa2390]
    bool  SetSliderPosition(int _iContainer, int _iControl, int _iSliderPos);

    // address=[0x2fa2510]
    int  GetSliderPosition(int _iContainer, int _iControl);

    // address=[0x2fa2580]
    bool  SelectControl(int _iContainer, int _iControlId, bool a4);

    // address=[0x2fa2700]
    bool  ResetRadioGroup(int _iContainer, int _iControlId);

    // address=[0x2fa27d0]
    bool  SetWidth(int _iContainer, int _iControl, int _iWidth);

    // address=[0x2fa2820]
    bool  SetPosition(int _iContainer, int _iControl, int _iX, int _iY);

private:
    // address=[0x2fa0940]
    void  InitShadeTables(void);

    // address=[0x2fa0b80]
    static struct tagRECT __cdecl GetDialogDestinationRect(struct GUI_MENU_DIALOG_HEADER const & retstr, int a2, int a3, float a4, float a5);

    // Type information members
public:
    int m_iDialogsRenderOffsetX;
    int m_iDialogsRenderOffsetY;
    float m_fDialogsRenderScaleX;
    float m_fDialogsRenderScaleY;

};


#endif // IGUIENGINE_H
