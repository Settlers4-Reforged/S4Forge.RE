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

#endif // GUIMENU_H
