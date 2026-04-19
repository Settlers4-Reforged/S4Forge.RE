#ifndef SGFXRENDERCONFIGURATION_H
#define SGFXRENDERCONFIGURATION_H

#include "defines.h"

class SGfxRenderConfiguration {
public:
    // address=[0x148fbd0]
    void EnableFiltering(bool a2);

    // address=[0x148fc20]
    void EnableHQTextureSet(bool a2);

    // address=[0x148fc70]
    void EnableHardwareLandscapeEngine(bool a2);

    // address=[0x148fcc0]
    void EnableHardwareObjectEngine(bool a2);

    // address=[0x148fd10]
    void ForceBlit(bool a2);

    // address=[0x148fe40]
    bool IsFiltering(void) const;

    // address=[0x148fe80]
    bool IsHQTextureSet(void) const;

    // address=[0x148fec0]
    bool IsHardwareObjectEngine(void) const;

    // address=[0x148ffc0]
    void SetPureSoftwareMode(bool a2);

    // address=[0x2f5f3d0]
    bool IsEditorMode(void) const;

    // address=[0x2f5f410]
    bool IsHardwareLandscapeEngine(void) const;

    // address=[0x2f69920]
    bool IsForceBlit(void) const;

    // Type information members
public:
    bool m_uUnkConf0;
    bool m_bGuiOnly;
    bool m_bD3DInterface;
    int  m_uFlags;
    HWND m_hWnd;
    int  m_uWidth;
    int  m_uHeight;
    int  m_uX;
    int  m_uY;
    int  m_uUnkConf1C;
    int  m_uUnkConf20;
};


#endif // SGFXRENDERCONFIGURATION_H
