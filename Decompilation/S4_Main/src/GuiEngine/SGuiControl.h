#ifndef SGUICONTROL_H
#define SGUICONTROL_H

#include "Defines/GUIControl.h"
#include "defines.h"

struct SGuiControl {
    WORD m_iX;
    WORD m_iY;
    WORD m_iWidth;
    WORD m_iHeight;
    WORD m_iMainTexture;
    WORD m_iValueLink;
    BYTE m_iEditProperty1;
    BYTE m_iEditProperty2;
    WORD m_iPressedTexture;
    char *m_spText;
    WORD m_iTooltipLink;
    WORD m_iTooltipLinkExtra;
    T_GUI_CNTRL m_iControlType;
    char m_iId;
    BYTE m_iFontTemplate;
    BYTE m_iEffects;
    WORD m_iShowTexture;
    char m_iParam;
    BYTE m_iParentContainer;
    BYTE m_iTextFormat;
    BYTE m_iUnknown21;
    BYTE m_iTextPosition;
    BYTE m_bDirty;
};

#endif // SGUICONTROL_H
