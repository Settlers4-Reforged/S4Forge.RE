#ifndef GUIMENU_H
#define GUIMENU_H

#include "SGuiControl.h"
#include "defines.h"

struct GUI_MENU_DIALOG_HEADER {
    WORD m_iSurfaceType;
    WORD m_iX;
    WORD m_iY;
    WORD m_iWidth;
    WORD m_iHeight;
    WORD m_iMainTexture;
    WORD m_iElementCount;
    WORD m_iTransparency;
    SGuiControl m_sControls[/*m_iElementCount*/];
};

struct GUI_MENU_FILE_HEADER {
    int m_iUnknown;
    int m_iContainerCount;
    int m_iUnknown2;
    int m_iTotalSize;
    int m_iContainerMap[/*m_iContainerCount*/];
};

struct GUI_MENU_ELEMENT {
    WORD m_iX;
    WORD m_iY;
    WORD m_iWidth;
    WORD m_iHeight;
    WORD m_iMainTexture;
    WORD m_iValueLink;
    WORD unknown;
    WORD m_iPressedTexture;
    DWORD m_iTextOffset;
    WORD m_iTooltipLink;
    WORD m_iTooltipLinkExtra;
    BYTE m_iImageStyle;
    BYTE m_iId;
    BYTE m_iTextStyle;
    BYTE m_iEffects;
    WORD m_iShowTexture;
    WORD unknownData[3];
};

#endif // GUIMENU_H
