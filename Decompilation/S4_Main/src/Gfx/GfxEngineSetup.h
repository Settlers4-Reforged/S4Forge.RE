#ifndef GFXENGINESETUP_H
#define GFXENGINESETUP_H

#include "./D3D/CSurfaceDescription.h"
#include "CBlitFX.h"
#include "MapObjects/T_GFX_MAP_ELEMENT.h" //TODO: move
#include "Render/SGfxRenderConfiguration.h"

extern CBlitFX s_cBlitFx;
extern CBlitFX s_cBlitFxAlpha;
extern CBlitFX s_cBlitFxAlphaDebug;

extern CSurfaceDescription s_cSurfaceDescription;

extern int s_iObjectOffsetX;
extern int s_iObjectOffsetY;

struct GFX_ENGINE_SETUP {
    SGfxRenderConfiguration sRenderSetup;
    int iCamFollowX;
    int iCamFollowY;
    int iVertexSize;
    int iVertexHeight;
    int iCamVertexSize;
    int iCamVertexHeight;
    int iSizeOfMap;
    T_GFX_MAP_ELEMENT *psMapElement;
    HBITMAP__ *hOutputBitmap;
    int iScrollOffsetX;
    int iScrollOffsetY;
    int iSoftOffsetX;
    int iSoftOffsetY;
    int iCurrentGfxMode;
    int iWidthOfBorder;
    int iCamWidthOfBorder;
    int iCamScrollOffsetX;
    int iCamScrollOffsetY;
    int iCamSoftOffsetX;
    int iCamSoftOffsetY;
    int iCamX;
    int iCamY;
    int iCamWidth;
    int iCamHeigth;
    HWND *pMiniMapHwnd;
    unsigned __int16 *pObjectLayer;
    unsigned __int16 *pDecoLayer;
    tagRECT *psSelectionRect;
    float fZoomFactor;
    float fCamZoomFactor;
    unsigned __int16 uSelectionColor;
    unsigned __int8 bUpdateCamLandscape;
    unsigned __int8 bLandscapeDeltaScroll;
    unsigned __int8 bUpdateLandscapeDelta;
    unsigned __int8 bDrawMiniMap;
    unsigned __int8 bUpdateLandscape;
    int iMiniMapX;
    int iMiniMapY;
    unsigned __int8 bMiniMapRefresh;
    unsigned __int8 bShowIconLayer;
    unsigned __int8 bHardwareObjects;
    int iShowCachePage;
};

extern GFX_ENGINE_SETUP GfxEngineSetup;

#endif // GFXENGINESETUP_H
