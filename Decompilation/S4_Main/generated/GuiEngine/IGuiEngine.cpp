#include "IGuiEngine.h"

// Definitions for class IGuiEngine

// address=[0x13d8b60]
// Decompiled from int __thiscall IGuiEngine::GetDialogsRenderOffsetX(IGuiEngine *this)
int  IGuiEngine::GetDialogsRenderOffsetX(void)const {
  
  return this->m_iDialogsRenderOffsetX;
}


// address=[0x13d8b80]
// Decompiled from int __thiscall IGuiEngine::GetDialogsRenderOffsetY(IGuiEngine *this)
int  IGuiEngine::GetDialogsRenderOffsetY(void)const {
  
  return this->m_iDialogsRenderOffsetY;
}


// address=[0x13d8ba0]
// Decompiled from float __thiscall IGuiEngine::GetDialogsRenderScaleX(IGuiEngine *this)
float  IGuiEngine::GetDialogsRenderScaleX(void)const {
  
  return this->m_fDialogsRenderScaleX;
}


// address=[0x13d8bc0]
// Decompiled from double __thiscall IGuiEngine::GetDialogsRenderScaleY(IGuiEngine *this)
float  IGuiEngine::GetDialogsRenderScaleY(void)const {
  
  return this->m_fDialogsRenderScaleY;
}


// address=[0x2f9b380]
// Decompiled from char __thiscall IGuiEngine::OpenDialog(IGuiEngine *this, int container, bool (__cdecl *a3)(int, int, int))
bool  IGuiEngine::OpenDialog(int a2, bool (__cdecl*)(int,int,int) a3) {
  
  int m_iHeight; // [esp+4h] [ebp-58h]
  float DialogsRenderScaleY; // [esp+8h] [ebp-54h]
  float DialogsRenderScaleX; // [esp+10h] [ebp-4Ch]
  int i; // [esp+1Ch] [ebp-40h]
  int j; // [esp+1Ch] [ebp-40h]
  bool v10; // [esp+20h] [ebp-3Ch]
  bool v11; // [esp+22h] [ebp-3Ah]
  GUI_MENU_DIALOG_HEADER *v12; // [esp+24h] [ebp-38h]
  struct SGuiControl *m_sControls; // [esp+28h] [ebp-34h]
  struct SGuiControl *v14; // [esp+28h] [ebp-34h]
  struct GFX_ENGINE_GUI_SURFACE_DESCRIPTION v15; // [esp+2Ch] [ebp-30h] BYREF
  struct SEventStruct v16; // [esp+48h] [ebp-14h] BYREF

  if ( !IsGuiEngineReady() || !a3 )
  {
    return 0;
  }
  if ( !GuiIsContainerValid(container) )
  {
    return 0;
  }
  v12 = GuiGetContainer(container);
  if ( g_iOpenDialogs[v12->m_iSurfaceType] )
  {
    return 0;
  }
  m_sControls = v12->m_sControls;
  for ( i = 0;
        i < v12->m_iElementCount;
        ++i )
  {
    if ( (m_sControls->m_iEffects & 1) != 0 )
    {
      m_sControls->m_iEffects &= ~1u;
    }
    if ( (m_sControls->m_iControlType == 5 || m_sControls->m_iControlType == 20) && (m_sControls->m_iId & 0x80u) != 0 )
    {
      if ( !IGuiEngine::SetText(this, container, m_sControls->m_iValueLink, (char *)&byte_3AD1732) )
      {
        BBSupportTracePrintF(0, "GUI ENGINE: Cannot open dialog. Not enough string cache!");
        return 0;
      }
      LOBYTE(g_mbstrTextTable[75 * (char)m_sControls->m_iId]) = 0;
    }
    if ( g_pfSetEnableStatus )
    {
      if ( container != g_iDialogToIgnore )
      {
        v11 = (unsigned __int8)g_pfSetEnableStatus(container, m_sControls->m_iValueLink, m_sControls->m_iControlType, (m_sControls->m_iEffects & 4) == 0, 3) == 0;
        SetControlState(m_sControls, 4, v11);
      }
    }
    ++m_sControls;
  }
  v15.m_uU18 = 1;
  m_iHeight = v12->m_iHeight;
  v15.m_iWidth = v12->m_iWidth;
  v15.m_iHeight = m_iHeight;
  v15.m_sDestinationRect.left = v12->m_iX + IGuiEngine::GetDialogsRenderOffsetX(g_pGUIEngine);
  v15.m_sDestinationRect.top = v12->m_iY + IGuiEngine::GetDialogsRenderOffsetY(g_pGUIEngine);
  DialogsRenderScaleX = IGuiEngine::GetDialogsRenderScaleX(g_pGUIEngine);
  v15.m_sDestinationRect.right = v15.m_sDestinationRect.left + (int)(float)((float)((float)v15.m_iWidth * DialogsRenderScaleX) + 0.5);
  DialogsRenderScaleY = IGuiEngine::GetDialogsRenderScaleY(g_pGUIEngine);
  v15.m_sDestinationRect.bottom = v15.m_sDestinationRect.top + (int)(float)((float)((float)m_iHeight * DialogsRenderScaleY) + 0.5);
  IGfxEngine::CreateGuiSurface(g_pGfxEngine, v12->m_iSurfaceType, &v15);
  IGfxEngine::SetVisibilityOfGuiSurface(g_pGfxEngine, v12->m_iSurfaceType, 1);
  g_iOpenDialogs[v12->m_iSurfaceType] = container + 1;
  g_pfDialogCallbacks[v12->m_iSurfaceType] = a3;
  a3(0, 0, 0);
  v14 = v12->m_sControls;
  for ( j = 0;
        j < v12->m_iElementCount;
        ++j )
  {
    if ( g_pfSetEnableStatus && container != g_iDialogToIgnore )
    {
      v10 = (unsigned __int8)g_pfSetEnableStatus(container, v14->m_iValueLink, v14->m_iControlType, (v14->m_iEffects & 4) == 0, 1) == 0;
      SetControlState(v14, 4, v10);
    }
    ++v14;
  }
  UpdateGui(v12->m_iSurfaceType);
  v16.m_iEventId = 5;
  v16.m_lParam = qword_471F794 + (HIDWORD(qword_471F794) << 16);
  v16.m_wParam = 0;
  v16.m_iTick = 0;
  GuiEngine2_EventProc(&v16);
  return 1;
}


// address=[0x2f9fea0]
// Decompiled from IGuiEngine *__thiscall IGuiEngine::IGuiEngine(IGuiEngine *this)
 IGuiEngine::IGuiEngine(void) {
  
  int i; // [esp+0h] [ebp-8h]

  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((float *)this + 2) = FLOAT_1_0;
  *((float *)this + 3) = FLOAT_1_0;
  g_pFileHeader = 0;
  g_pCurrentEditControl = 0;
  g_pCurrentDragControl = 0;
  g_pCurrentSelectedControl = 0;
  g_pCurrentRepeatControl = 0;
  g_pfSetEnableStatus = 0;
  g_bDisableEvents = 1;
  for ( i = 0;
        i < 19;
        ++i )
  {
    g_hFonts[i] = 0;
  }
  InitTables();
  return this;
}


// address=[0x2f9ff60]
// Decompiled from int __thiscall IGuiEngine::~IGuiEngine(IGuiEngine *this)
 IGuiEngine::~IGuiEngine(void) {
  
  int result; // eax
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0;
        i < 19;
        ++i )
  {
    if ( g_hFonts[i] )
    {
      DeleteObject(g_hFonts[i]);
    }
  }
  g_pCurrentEditControl = 0;
  g_pCurrentDragControl = 0;
  g_pCurrentSelectedControl = 0;
  result = 0;
  g_pCurrentRepeatControl = 0;
  g_pfSetEnableStatus = 0;
  g_bDisableEvents = 1;
  return result;
}


// address=[0x2f9fff0]
// Decompiled from char __thiscall IGuiEngine::Init(IGuiEngine *this, struct IGfxEngine *_pGfxEngine, struct CGfxManager *_pGfxManager, GUI_MENU_FILE_HEADER *_pFileHeader, int _iStartingDialogId, bool (__cdecl *_fpStartingDialogHandler)(int, int, int), int _iLanguage)
bool  IGuiEngine::Init(class IGfxEngine * _pGfxEngine, class CGfxManager * _pGfxManager, void * _pFileHeader, int _iStartingDialogId, bool (__cdecl*)(int,int,int) _fpStartingDialogHandler, int _iLanguage) {
  
  int DeviceCaps; // eax
  HFONT hFont; // eax
  int v10; // [esp+4h] [ebp-20h]
  HDC hdc; // [esp+8h] [ebp-1Ch]
  int iFontHeight; // [esp+Ch] [ebp-18h]
  MACRO_CHARSET iCharSet; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  char v16; // [esp+23h] [ebp-1h]

  if ( !_pGfxEngine || !_pFileHeader || !_pGfxManager )
  {
    return 0;
  }
  g_iDialogToIgnore = -1;
  g_bDisableEvents = 1;
  g_pGfxEngine = _pGfxEngine;
  if ( GetGfxInterfaceVersion() == 229 )
  {
    iCharSet = ANSI_CHARSET;
    v16 = 0;
    g_iAlignMode = 0;
    v10 = 0;
    switch ( _iLanguage )
    {
      case 5:
      case 11:
      case 13:
        iCharSet = EASTEUROPE_CHARSET;
        break;
      case 6:
        iCharSet = HANGEUL_CHARSET;
        v16 = 1;
        v10 = -2;
        break;
      case 7:
        iCharSet = CHINESEBIG5_CHARSET;
        v16 = 1;
        break;
      case 12:
        g_iAlignMode = 1;
        iCharSet = HEBREW_CHARSET;
        v16 = 1;
        break;
      case 16:
        iCharSet = RUSSIAN_CHARSET;
        break;
      case 18:
        iCharSet = SHIFTJIS_CHARSET;
        v16 = 1;
        break;
      default:
        break;
    }
    hdc = GetDC(0);
    if ( hdc )
    {
      for ( i = 0;
            i < 19;
            ++i )
      {
        if ( g_hFonts[i] )
        {
          DeleteObject(g_hFonts[i]);
        }
        iFontHeight = v10 + s_sFontSettings[i].m_iHeight;
        if ( v16 )
        {
          DeviceCaps = GetDeviceCaps(hdc, 90);
          iFontHeight = MulDiv(iFontHeight, 4 * DeviceCaps, 374);
        }
        if ( s_sFontSettings[i].m_bUseQualityFont )
        {
          hFont = CreateFontA(iFontHeight, s_sFontSettings[i].m_iWidth, 0, 0, s_sFontSettings[i].m_iWeight, 0, 0, 0, iCharSet, 0, 0, 4u, 0, s_sFontSettings[i].m_sFontName);
        }
        else
        {
          hFont = CreateFontA(iFontHeight, s_sFontSettings[i].m_iWidth, 0, 0, s_sFontSettings[i].m_iWeight, 0, 0, 0, iCharSet, 0, 0, 0, 0, s_sFontSettings[i].m_sFontName);
        }
        g_hFonts[i] = hFont;
        if ( !g_hFonts[i] )
        {
          BBSupportTracePrintF(0, "GUI ENGINE: Cannot create font!");
        }
      }
      ReleaseDC(0, hdc);
      IGfxEngine::SetWidthOfLeftGuiBorder(g_pGfxEngine, 0);
      g_pGfxManager = _pGfxManager;
      g_pFileHeader = _pFileHeader;
      g_pCurrentSelectedControl = 0;
      g_pCurrentDragControl = 0;
      g_pCurrentEditControl = 0;
      g_pCurrentRepeatControl = 0;
      memset(g_iOpenDialogs, 0, sizeof(g_iOpenDialogs));
      memset(g_mbstrTextTable, 0, sizeof(g_mbstrTextTable));
      memset(g_bUsedTexts, 0, 0x50u);
      IGuiEngine::InitShadeTables(this);
      g_bGuiIsDirty = 1;
      IGuiEngine::OpenDialog(this, _iStartingDialogId, _fpStartingDialogHandler);
      g_bDisableEvents = 0;
      IGuiEngine::SetTooltipID(this, 45, 1441, 1803, 1804);
      IGuiEngine::DisableDialogControls(this, 36);
      return 1;
    }
    else
    {
      BBSupportTracePrintF(0, "GUI ENGINE: No primary DC!");
      return 0;
    }
  }
  else
  {
    BBSupportTracePrintF(0, "GUI ENGINE: Wrong version of gfx engine!");
    return 0;
  }
}


// address=[0x2fa0320]
// Decompiled from void __thiscall IGuiEngine::RefreshAllSurfaces(IGuiEngine *this)
void  IGuiEngine::RefreshAllSurfaces(void) {
  
  struct tagRECT v1; // [esp+8h] [ebp-B0h] BYREF
  struct tagRECT v2; // [esp+18h] [ebp-A0h] BYREF
  int m_iWidth; // [esp+28h] [ebp-90h]
  int m_iHeight; // [esp+2Ch] [ebp-8Ch]
  int j; // [esp+30h] [ebp-88h]
  struct SGuiControl *m_sElements; // [esp+34h] [ebp-84h]
  char GuiSurfaceDescription; // [esp+3Bh] [ebp-7Dh]
  unsigned int i; // [esp+3Ch] [ebp-7Ch]
  bool v10; // [esp+46h] [ebp-72h]
  bool v11; // [esp+47h] [ebp-71h]
  const struct GUI_MENU_DIALOG_HEADER *v12; // [esp+48h] [ebp-70h]
  struct GFX_ENGINE_GUI_SURFACE_DESCRIPTION v13; // [esp+4Ch] [ebp-6Ch] BYREF
  struct GFX_ENGINE_GUI_SURFACE_DESCRIPTION v14; // [esp+68h] [ebp-50h] BYREF
  struct tagRECT v15; // [esp+84h] [ebp-34h] BYREF
  RECT v16; // [esp+94h] [ebp-24h]
  struct tagRECT v17; // [esp+A4h] [ebp-14h]

  if ( g_pGfxEngine && g_pFileHeader && g_pGfxManager )
  {
    for ( i = 0;
          i < 14;
          ++i )
    {
      v12 = (const struct GUI_MENU_DIALOG_HEADER *)((char *)g_pFileHeader + *(&g_pFileHeader->m_iTotalSize + g_iOpenDialogs[i]));
      IGfxEngine::SetVisibilityOfGuiSurface(g_pGfxEngine, i, 0);
      if ( g_iOpenDialogs[i] )
      {
        GuiSurfaceDescription = IGfxEngine::GetGuiSurfaceDescription(g_pGfxEngine, v12->m_iSurfaceType, &v13);
        if ( GuiSurfaceDescription && v13.m_iWidth == v12->m_iWidth && v13.m_iHeight == v12->m_iHeight )
        {
          v17 = *IGuiEngine::GetDialogDestinationRect(&v2, v12, *(_DWORD *)this, *((_DWORD *)this + 1), *((float *)this + 2), *((float *)this + 3));
          v15 = v17;
          IGfxEngine::SetGuiSurfaceDestinationRect(g_pGfxEngine, v12->m_iSurfaceType, &v15);
        }
        else
        {
          IGfxEngine::DestroyGuiSurface(g_pGfxEngine, v12->m_iSurfaceType);
          v14.m_uU18 = 1;
          m_iWidth = v12->m_iWidth;
          m_iHeight = v12->m_iHeight;
          v14.m_iWidth = m_iWidth;
          v14.m_iHeight = m_iHeight;
          v16 = *IGuiEngine::GetDialogDestinationRect(&v1, v12, *(_DWORD *)this, *((_DWORD *)this + 1), *((float *)this + 2), *((float *)this + 3));
          v14.m_sDestinationRect = v16;
          IGfxEngine::CreateGuiSurface(g_pGfxEngine, v12->m_iSurfaceType, &v14);
        }
        IGfxEngine::SetVisibilityOfGuiSurface(g_pGfxEngine, v12->m_iSurfaceType, 1);
        if ( g_pfSetEnableStatus )
        {
          m_sElements = v12->m_sControls;
          for ( j = 0;
                j < v12->m_iElementCount;
                ++j )
          {
            v11 = (m_sElements->m_iEffects & 4) == 0;
            v10 = (unsigned __int8)g_pfSetEnableStatus(g_iOpenDialogs[i] - 1, m_sElements->m_iValueLink, m_sElements->m_iControlType, v11, 4) == 0;
            SetControlState(m_sElements++, 4, v10);
          }
        }
        UpdateGui(i);
        if ( g_pfDialogCallbacks[v12->m_iSurfaceType] )
        {
          ((void (__cdecl *)(int, _DWORD, _DWORD))g_pfDialogCallbacks[v12->m_iSurfaceType])(11, 0, 0);
        }
      }
    }
  }
}


// address=[0x2fa0670]
// Decompiled from char __thiscall IGuiEngine::CloseDialog(IGuiEngine *this, int a2)
bool  IGuiEngine::CloseDialog(int a2) {
  
  unsigned int v3; // [esp+4h] [ebp-14h]
  unsigned __int16 *v4; // [esp+8h] [ebp-10h]
  unsigned int i; // [esp+Ch] [ebp-Ch]
  int j; // [esp+Ch] [ebp-Ch]
  unsigned __int16 *v7; // [esp+10h] [ebp-8h]
  char v8; // [esp+17h] [ebp-1h]

  if ( !g_pFileHeader || !g_pGfxEngine || !g_pGfxManager )
  {
    return 0;
  }
  if ( a2 >= *(_DWORD *)(g_pFileHeader + 4) || a2 < 0 )
  {
    return 0;
  }
  v8 = 0;
  for ( i = 0;
        i < 0xE;
        ++i )
  {
    if ( g_iOpenDialogs[i] == a2 + 1 )
    {
      v8 = 1;
      break;
    }
  }
  if ( !v8 )
  {
    return 0;
  }
  v7 = (unsigned __int16 *)(*(_DWORD *)(g_pFileHeader + 4 * a2 + 16) + g_pFileHeader);
  IGfxEngine::SetVisibilityOfGuiSurface((IGfxEngine *)g_pGfxEngine, *v7, 0);
  v4 = v7 + 8;
  for ( j = 0;
        j < v7[6];
        ++j )
  {
    if ( *((char *)v4 + 25) >= 0 )
    {
      LOBYTE(g_mbstrTextTable[75 * *((char *)v4 + 25)]) = 0;
      v3 = *((char *)v4 + 25);
      if ( v3 >= 0x50 )
      {
        report_rangecheckfailure();
      }
      g_bUsedTexts[v3] = 0;
    }
    *((_BYTE *)v4 + 25) = -1;
    v4 += 18;
  }
  if ( g_pCurrentEditControl && GetSurfaceID((struct SGuiControl *)g_pCurrentEditControl) == *v7 )
  {
    g_pCurrentEditControl = 0;
  }
  if ( g_pCurrentRepeatControl && GetSurfaceID((struct SGuiControl *)g_pCurrentRepeatControl) == *v7 )
  {
    g_pCurrentRepeatControl = 0;
  }
  if ( g_pCurrentSelectedControl && GetSurfaceID((struct SGuiControl *)g_pCurrentSelectedControl) == *v7 )
  {
    g_pCurrentSelectedControl = 0;
  }
  if ( g_pCurrentDragControl && GetSurfaceID((struct SGuiControl *)g_pCurrentDragControl) == *v7 )
  {
    g_pCurrentDragControl = 0;
  }
  if ( CToolTip::IsOpen((CToolTip *)&g_cToolTipExt) && CToolTip::GetSourceDialogSurfaceID((CToolTip *)&g_cToolTipExt) == *v7 )
  {
    CToolTip::CloseTooltip((CToolTip *)&g_cToolTipExt);
  }
  g_iOpenDialogs[*v7] = 0;
  g_pfDialogCallbacks[*v7] = 0;
  IGfxEngine::DestroyGuiSurface((IGfxEngine *)g_pGfxEngine, *v7);
  return 1;
}


// address=[0x2fa08c0]
// Decompiled from char __thiscall IGuiEngine::RenderGui(IGuiEngine *this)
bool  IGuiEngine::RenderGui(void) {
  
  UpdateGui(-1);
  return 1;
}


// address=[0x2fa08e0]
// Decompiled from void __thiscall IGuiEngine::EnableEventInput(IGuiEngine *this, bool a2)
void  IGuiEngine::EnableEventInput(bool a2) {
  
  g_bDisableEvents = !a2;
}


// address=[0x2fa0910]
// Decompiled from void __thiscall IGuiEngine::EnableShortcuts(IGuiEngine *this, bool a2)
void  IGuiEngine::EnableShortcuts(bool a2) {
  
  ;
}


// address=[0x2fa0920]
// Decompiled from bool (__cdecl *__thiscall IGuiEngine::SetCtrlStatusCallback(IGuiEngine *this, bool (__cdecl *a2)(int, int, int, bool, int)))(int, int, int, bool, int)
void  IGuiEngine::SetCtrlStatusCallback(bool (__cdecl*)(int,int,int,bool,int) a2) {
  
  bool (__cdecl *result)(int, int, int, bool, int); // eax

  result = a2;
  g_pfSetEnableStatus = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))a2;
  return result;
}


// address=[0x2fa0fc0]
// Decompiled from int __thiscall IGuiEngine::SetDialogsRenderOffset(IGuiEngine *this, int a2, int a3, float a4, float a5)
void  IGuiEngine::SetDialogsRenderOffset(int a2, int a3, float a4, float a5) {
  
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = a3;
  *((float *)this + 2) = a4;
  *((float *)this + 3) = a5;
  return IGuiEngine::RefreshAllSurfaces(this);
}


// address=[0x2fa1000]
// Decompiled from char __thiscall IGuiEngine::GetDialogRect(IGuiEngine *this, int a1, struct SGuiRect *a3)
bool  IGuiEngine::GetDialogRect(int a1, struct SGuiRect & a3) {
  
  GUI_MENU_DIALOG_HEADER *pContainer; // eax

  if ( !GuiEngineReady() )
  {
    return 0;
  }
  if ( !(unsigned __int8)sub_2FA2880(a1) )
  {
    return 0;
  }
  pContainer = GuiGetContainer2(a1);
  a3->m_iTopLeftX = pContainer->m_iX;
  a3->m_iTopLeftY = pContainer->m_iY;
  a3->m_iBottomRightX = pContainer->m_iX + pContainer->m_iWidth - 1;
  a3->m_iBottomRightY = pContainer->m_iY + pContainer->m_iHeight - 1;
  return 1;
}


// address=[0x2fa1090]
// Decompiled from char __thiscall IGuiEngine::SetDialogRect(_DWORD *this, int a1, struct SGuiRect a3)
bool  IGuiEngine::SetDialogRect(int a1, struct SGuiRect a3) {
  
  GUI_MENU_DIALOG_HEADER *pContainer; // [esp+4h] [ebp-4h]

  if ( !GuiEngineReady() )
  {
    return 0;
  }
  if ( !sub_2FA2880(a1) )
  {
    return 0;
  }
  pContainer = GuiGetContainer2(a1);
  pContainer->m_iX = a3.m_iTopLeftX;
  pContainer->m_iY = a3.m_iTopLeftY;
  pContainer->m_iWidth = LOWORD(a3.m_iBottomRightX) + 1 - LOWORD(a3.m_iTopLeftX);
  pContainer->m_iHeight = LOWORD(a3.m_iBottomRightY) + 1 - LOWORD(a3.m_iTopLeftY);
  IGfxEngine::SetGuiSurfaceDestinationPosition(g_pGfxEngine, pContainer->m_iSurfaceType, a3.m_iTopLeftX + *this, a3.m_iTopLeftY + this[1]);
  return 1;
}


// address=[0x2fa1140]
// Decompiled from char __thiscall IGuiEngine::MoveDialogTo(IGuiEngine *this, int a1, int a3, int a4)
bool  IGuiEngine::MoveDialogTo(int a2, int a3, int a4) {
  
  GUI_MENU_DIALOG_HEADER *Container2; // [esp+4h] [ebp-4h]

  if ( !GuiEngineReady() )
  {
    return 0;
  }
  if ( !sub_2FA2880(a1) )
  {
    return 0;
  }
  Container2 = GuiGetContainer2(a1);
  Container2->m_iX = a3;
  Container2->m_iY = a4;
  return IGfxEngine::SetGuiSurfaceDestinationPosition(g_pGfxEngine, Container2->m_iSurfaceType, a3 + this->m_iDialogsRenderOffsetX, a4 + this->m_iDialogsRenderOffsetY);
}


// address=[0x2fa11c0]
// Decompiled from char __thiscall IGuiEngine::GetDialogRenderRect(IGuiEngine *this, int a1, struct SGuiRect *a3)
bool  IGuiEngine::GetDialogRenderRect(int a2, struct SGuiRect & a3) {
  
  struct tagRECT v4; // [esp+8h] [ebp-3Ch] BYREF
  const struct GUI_MENU_DIALOG_HEADER *Container2; // [esp+18h] [ebp-2Ch]
  LONG top; // [esp+24h] [ebp-20h]
  __int64 v8; // [esp+28h] [ebp-1Ch]
  struct tagRECT v9; // [esp+30h] [ebp-14h]

  if ( !GuiEngineReady() )
  {
    return 0;
  }
  if ( !sub_2FA2880(a1) )
  {
    return 0;
  }
  Container2 = GuiGetContainer2(a1);
  v9 = *IGuiEngine::GetDialogDestinationRect(&v4, Container2, this->m_iDialogsRenderOffsetX, this->m_iDialogsRenderOffsetY, this->m_fDialogsRenderScaleX, this->m_fDialogsRenderScaleY);
  top = v9.top;
  v8 = *(_QWORD *)&v9.right;
  a3->m_iTopLeftX = v9.left;
  a3->m_iBottomRightX = v8;
  a3->m_iTopLeftY = top;
  a3->m_iBottomRightY = HIDWORD(v8);
  return 1;
}


// address=[0x2fa12b0]
// Decompiled from char __thiscall IGuiEngine::SetDialogRenderPos(IGuiEngine *this, int a2, int a3, int a4)
bool  IGuiEngine::SetDialogRenderPos(int a2, int a3, int a4) {
  
  return IGuiEngine::MoveDialogTo(this, a2, a3 - this->m_iDialogsRenderOffsetX, a4 - this->m_iDialogsRenderOffsetY);
}


// address=[0x2fa12e0]
// Decompiled from void __thiscall IGuiEngine::EnableTooltipsExt(IGuiEngine *this, bool a2)
void  IGuiEngine::EnableTooltipsExt(bool a2) {
  
  int SurfaceID; // eax
  int v3; // eax
  int v4; // [esp-8h] [ebp-Ch]
  int m_iTooltipLinkExtra; // [esp-4h] [ebp-8h]

  if ( CToolTip::IsOpen((CToolTip *)g_cToolTipExt) && !a2 )
  {
    CToolTip::SetSourceDialogSurfaceID((CToolTip *)g_cToolTipExt, -1);
    CToolTip::CloseTooltip((CToolTip *)g_cToolTipExt);
  }
  CToolTip::SetEnableStatus((CToolTip *)g_cToolTipExt, a2);
  if ( a2 )
  {
    if ( g_pCurrentSelectedControl )
    {
      m_iTooltipLinkExtra = (__int16)g_pCurrentSelectedControl->m_iTooltipLinkExtra;
      v4 = (g_pCurrentSelectedControl->m_iEffects << 16) + g_pCurrentSelectedControl->m_iValueLink;
      SurfaceID = GetSurfaceID(g_pCurrentSelectedControl);
      g_pfDialogCallbacks[SurfaceID](9, v4, m_iTooltipLinkExtra);
      v3 = GetSurfaceID(g_pCurrentSelectedControl);
      CToolTip::SetSourceDialogSurfaceID((CToolTip *)g_cToolTipExt, v3);
      CToolTipExt::OpenTooltip((CToolTipExt *)g_cToolTipExt);
    }
  }
}


// address=[0x2fa13a0]
// Decompiled from void __thiscall IGuiEngine::SetDlgToIgnore(IGuiEngine *this, int a2, bool a3)
void  IGuiEngine::SetDlgToIgnore(int a2, bool a3) {
  
  if ( GuiEngineReady() && sub_2FA2880(a2) )
  {
    g_iDialogToIgnore = a2;
    if ( !a3 )
    {
      g_iDialogToIgnore = -1;
    }
  }
}


// address=[0x2fa13f0]
// Decompiled from char __stdcall IGuiEngine::SetTooltip(char *Str)
bool  IGuiEngine::SetTooltip(char const * Str) {
  
  if ( !GuiEngineReady() || !Str )
  {
    return 0;
  }
  CToolTip::SetTooltipText(g_cToolTip, Str);
  return 1;
}


// address=[0x2fa1430]
// Decompiled from char __stdcall IGuiEngine::SetTooltipExt(char *Str)
bool  IGuiEngine::SetTooltipExt(char const * Str) {
  
  if ( !GuiEngineReady() || !Str )
  {
    return 0;
  }
  CToolTip::SetTooltipText(g_cToolTipExt, Str);
  return 1;
}


// address=[0x2fa1470]
// Decompiled from char __thiscall IGuiEngine::SetTooltipID(IGuiEngine *this, int a2, int a3, int a4, int a5)
bool  IGuiEngine::SetTooltipID(int a2, int a3, int a4, int a5) {
  
  struct SGuiControl *pControl; // [esp+4h] [ebp-4h]

  if ( !GuiEngineReady() )
  {
    return 0;
  }
  pControl = GetControlPtr(a2, a3);
  if ( !pControl )
  {
    return 0;
  }
  if ( a4 >= 0 )
  {
    pControl->m_iTooltipLink = a4;
  }
  if ( a5 >= 0 )
  {
    pControl->m_iTooltipLinkExtra = a5;
  }
  return 1;
}


// address=[0x2fa14d0]
// Decompiled from char __thiscall IGuiEngine::DisableDialogControls(IGuiEngine *this, int a1)
bool  IGuiEngine::DisableDialogControls(int a2) {
  
  char result; // al
  GUI_MENU_DIALOG_HEADER *Container2; // [esp+4h] [ebp-4h]

  if ( !sub_2FA2880(a1) )
  {
    return 0;
  }
  Container2 = GuiGetContainer2(a1);
  if ( !Container2 )
  {
    return 0;
  }
  result = 1;
  Container2->m_iElementCount = 0;
  return result;
}


// address=[0x2fa1520]
// Decompiled from char __thiscall IGuiEngine::SetText(struct IGuiEngine *this, int _iContainer, int _iControlId, char *_spText)
bool  IGuiEngine::SetText(int _iContainer, int _iControlId, char const * _spText) {
  
  int v5; // eax
  int v6; // ecx
  unsigned int m_iId; // [esp+4h] [ebp-14h]
  unsigned int v8; // [esp+8h] [ebp-10h]
  int i; // [esp+Ch] [ebp-Ch]
  int iTextLength; // [esp+10h] [ebp-8h]
  struct SGuiControl *pControl; // [esp+14h] [ebp-4h]

  if ( !GuiEngineReady() || !_spText )
  {
    return 0;
  }
  pControl = GetControlPtr(_iContainer, _iControlId);
  if ( !pControl )
  {
    return 0;
  }
  iTextLength = strlen(_spText);
  if ( pControl->m_iControlType == 21 )
  {
    pControl->m_spText = (DWORD)_spText;
    if ( !iTextLength )
    {
      pControl->m_spText = 0;
    }
    pControl->m_bDirty = 1;
    g_bGuiIsDirty = 1;
    return 1;
  }
  else
  {
    if ( pControl->m_iId >= 0 )
    {
      goto LABEL_41;
    }
    for ( i = 0;
          i < 80;
          ++i )
    {
      if ( !g_bUsedTexts[i] )
      {
        pControl->m_iId = i;
        g_bUsedTexts[i] = 1;
        break;
      }
    }
    if ( pControl->m_iId < 0 )
    {
      return 0;
    }
    if ( iTextLength )
    {
LABEL_41:
      if ( j___mbscmp(_spText, g_mbstrTextTable[pControl->m_iId]) )
      {
        if ( iTextLength )
        {
          if ( iTextLength >= 299 )
          {
            iTextLength = 299;
          }
          j__strncpy(g_mbstrTextTable[pControl->m_iId], _spText, iTextLength);
          g_mbstrTextTable[pControl->m_iId][iTextLength] = 0;
          g_bGuiIsDirty = 1;
          pControl->m_bDirty = 1;
          return 1;
        }
        else
        {
          if ( pControl->m_iControlType == 5 || pControl->m_iControlType == 20 )
          {
            g_mbstrTextTable[pControl->m_iId][0] = 0;
          }
          else
          {
            g_mbstrTextTable[pControl->m_iId][0] = 0;
            m_iId = pControl->m_iId;
            if ( m_iId >= 0x50 )
            {
              report_rangecheckfailure();
            }
            v6 = pControl->m_iId;
            g_bUsedTexts[m_iId] = 0;
            pControl->m_iId = -1;
          }
          g_bGuiIsDirty = 1;
          pControl->m_bDirty = 1;
          return 1;
        }
      }
      else
      {
        return 1;
      }
    }
    else
    {
      if ( pControl->m_iControlType == 5 || pControl->m_iControlType == 20 )
      {
        g_mbstrTextTable[pControl->m_iId][0] = 0;
      }
      else
      {
        g_mbstrTextTable[pControl->m_iId][0] = 0;
        v8 = pControl->m_iId;
        if ( v8 >= 0x50 )
        {
          report_rangecheckfailure();
        }
        v5 = pControl->m_iId;
        g_bUsedTexts[v8] = 0;
        pControl->m_iId = -1;
      }
      return 1;
    }
  }
}


// address=[0x2fa17e0]
// Decompiled from char __thiscall IGuiEngine::SetEditProperties(IGuiEngine *this, int _iContainer, int _iControl, unsigned __int8 _iProp1, BYTE _iProp2)
bool  IGuiEngine::SetEditProperties(int _iContainer, int _iControl, unsigned char _iProp1, unsigned char _iProp2) {
  
  unsigned __int8 iProp1; // [esp+4h] [ebp-8h]
  struct SGuiControl *pControl; // [esp+8h] [ebp-4h]

  if ( !GuiEngineReady() )
  {
    return 0;
  }
  pControl = GetControlPtr(_iContainer, _iControl);
  if ( !pControl )
  {
    return 0;
  }
  if ( pControl->m_iControlType != 5 && pControl->m_iControlType != 20 )
  {
    return 0;
  }
  if ( _iProp1 >= 115u )
  {
    iProp1 = 115;
  }
  else
  {
    iProp1 = _iProp1;
  }
  pControl->m_iEditProperty1 = iProp1;
  pControl->m_iEditProperty2 = _iProp2;
  return 1;
}


// address=[0x2fa1870]
// Decompiled from char __thiscall IGuiEngine::SetTypeAsButton(IGuiEngine *this, int _iContainer, int _iControl)
bool  IGuiEngine::SetTypeAsButton(int _iContainer, int _iControl) {
  
  struct SGuiControl *pControl; // [esp+4h] [ebp-4h]

  if ( !GuiEngineReady() )
  {
    return 0;
  }
  pControl = GetControlPtr(_iContainer, _iControl);
  if ( !pControl )
  {
    return 0;
  }
  pControl->m_iControlType = GUI_CNTRL_BUTTON;
  pControl->m_iWidth = 161;
  pControl->m_iHeight = 30;
  pControl->m_iMainTexture = 196;
  pControl->m_iPressedTexture = 197;
  pControl->m_iTextStyle = 6;
  pControl->m_iParentContainer = 2;
  pControl->m_iTextFormat = 4;
  pControl->m_iX = 567;
  pControl->m_iY = 100;
  return 1;
}


// address=[0x2fa1920]
// Decompiled from char __thiscall IGuiEngine::SetTypeAsText(IGuiEngine *this, int _iContainer, int _iControl)
bool  IGuiEngine::SetTypeAsText(int _iContainer, int _iControl) {
  
  struct SGuiControl *pControl; // [esp+4h] [ebp-4h]

  if ( !GuiEngineReady() )
  {
    return 0;
  }
  pControl = GetControlPtr(_iContainer, _iControl);
  if ( !pControl )
  {
    return 0;
  }
  pControl->m_iControlType = GUI_CNTRL_TEXT;
  return 1;
}


// address=[0x2fa1970]
// Decompiled from char __thiscall IGuiEngine::SetTypeAsRadio(IGuiEngine *this, int a2, int a3, WORD a4, WORD a5)
bool  IGuiEngine::SetTypeAsRadio(int a2, int a3, int a4, int a5) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !GuiEngineReady() )
  {
    return 0;
  }
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
  {
    return 0;
  }
  ControlPtr->m_iControlType = GUI_CNTRL_RADIO;
  ControlPtr->m_iMainTexture = a4;
  ControlPtr->m_iPressedTexture = a5;
  ControlPtr->m_iWidth = 20;
  ControlPtr->m_iHeight = 20;
  ControlPtr->m_iTooltipLink = -1;
  ControlPtr->m_iTooltipLinkExtra = -1;
  return 1;
}


// address=[0x2fa1a00]
// Decompiled from bool __thiscall IGuiEngine::SetRadioCheckPressedState(IGuiEngine *this, int a2, int a3, bool a4)
bool  IGuiEngine::SetRadioCheckPressedState(int a2, int a3, bool a4) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !GuiEngineReady() )
  {
    return 0;
  }
  ControlPtr = GetControlPtr(a2, a3);
  return ControlPtr && SetControlState(ControlPtr, 1, a4);
}


// address=[0x2fa1a50]
// Decompiled from char *__thiscall IGuiEngine::GetText(IGuiEngine *this, int container, int valueLink)
char const *  IGuiEngine::GetText(int container, int valueLink) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !GuiEngineReady() )
  {
    return 0;
  }
  ControlPtr = GetControlPtr(container, valueLink);
  if ( !ControlPtr )
  {
    return 0;
  }
  if ( (ControlPtr->m_iId & 0x80u) == 0 )       // id >= 0
  {
    return (char *)&g_mbstrTextTable[75 * (char)ControlPtr->m_iId];
  }
  return 0;
}


// address=[0x2fa1ac0]
// Decompiled from int __thiscall IGuiEngine::GetWrapPosition(IGuiEngine *this, int a2, int a3)
int  IGuiEngine::GetWrapPosition(int a2, int a3) {
  
  struct tagSIZE psizl; // [esp+0h] [ebp-1Ch] BYREF
  IGuiEngine *v5; // [esp+8h] [ebp-14h]
  int v6; // [esp+Ch] [ebp-10h]
  int v7; // [esp+10h] [ebp-Ch]
  struct SGuiControl *ControlPtr; // [esp+14h] [ebp-8h]

  v5 = this;
  if ( !GuiEngineReady() )
  {
    return -1;
  }
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
  {
    return -1;
  }
  if ( (ControlPtr->m_iId & 0x80u) != 0 )
  {
    return -1;
  }
  if ( !LOBYTE(g_mbstrTextTable[75 * (char)ControlPtr->m_iId]) )
  {
    return -1;
  }
  if ( !CalcTextSize(ControlPtr->m_iTextStyle, (const unsigned __int8 *)&g_mbstrTextTable[75 * (char)ControlPtr->m_iId], &psizl, 0, -1) )
  {
    return -1;
  }
  if ( psizl.cx <= ControlPtr->m_iWidth - 4 )
  {
    return -1;
  }
  v7 = 0;
  CalcTextSize(ControlPtr->m_iTextStyle, (const unsigned __int8 *)&g_mbstrTextTable[75 * (char)ControlPtr->m_iId], &psizl, 0, 0);
  v6 = 251;
  while ( psizl.cx <= ControlPtr->m_iWidth - 4 )
  {
    if ( --v6 < 0 )
    {
      break;
    }
    CalcTextSize(ControlPtr->m_iTextStyle, (const unsigned __int8 *)&g_mbstrTextTable[75 * (char)ControlPtr->m_iId], &psizl, 0, ++v7);
  }
  if ( v6 > 0 )
  {
    return v7 - 1;
  }
  else
  {
    return -1;
  }
}


// address=[0x2fa1c60]
// Decompiled from char __thiscall IGuiEngine::SetFontTemplate(IGuiEngine *this, int a2, int a3, int a4)
bool  IGuiEngine::SetFontTemplate(int a2, int a3, int a4) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !GuiEngineReady() )
  {
    return 0;
  }
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
  {
    return 0;
  }
  if ( a4 >= 19 )
  {
    return 0;
  }
  if ( ControlPtr->m_iTextStyle == a4 )
  {
    return 1;
  }
  ControlPtr->m_iTextStyle = a4;
  g_bGuiIsDirty = 1;
  HIBYTE(ControlPtr->m_iTextFormat[1]) = 1;
  return 1;
}


// address=[0x2fa1ce0]
// Decompiled from bool __thiscall IGuiEngine::EnableControl(IGuiEngine *this, int a2, int a3, bool a4)
bool  IGuiEngine::EnableControl(int a2, int a3, bool a4) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-8h]
  bool v6; // [esp+Bh] [ebp-1h]

  if ( !GuiEngineReady() )
  {
    return 0;
  }
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
  {
    return 0;
  }
  if ( !g_pfSetEnableStatus )
  {
    return SetControlState(ControlPtr, 4, !a4);
  }
  v6 = (unsigned __int8)g_pfSetEnableStatus(a2, ControlPtr->m_iValueLink, ControlPtr->m_iControlType, a4, 8) == 0;
  return SetControlState(ControlPtr, 4, v6);
}


// address=[0x2fa1da0]
// Decompiled from char __thiscall IGuiEngine::SetControlVisibility(struct IGuiEngine *this, int a2, int a3, char a4)
bool  IGuiEngine::SetControlVisibility(int a2, int a3, bool a4) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-8h]

  if ( !GuiEngineReady() )
  {
    return 0;
  }
  ControlPtr = GetControlPtr(a2, a3);
  if ( ControlPtr )
  {
    return SetControlState(ControlPtr, 8, a4 == 0);
  }
  else
  {
    return 0;
  }
}


// address=[0x2fa1e10]
// Decompiled from char __thiscall IGuiEngine::SetImages(void *this, int _iContainer, int _iControl, int _iMainTextureId, int _iPressedTextureId)
bool  IGuiEngine::SetImages(int _iContainer, int _iControl, int _iMainTextureId, int _iPressedTextureId) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !GuiEngineReady() )
  {
    return 0;
  }
  ControlPtr = GetControlPtr(_iContainer, _iControl);
  if ( !ControlPtr )
  {
    return 0;
  }
  if ( ControlPtr->m_iMainTexture == _iMainTextureId && ControlPtr->m_iPressedTexture == _iPressedTextureId )
  {
    return 1;
  }
  ControlPtr->m_iMainTexture = _iMainTextureId;
  ControlPtr->m_iPressedTexture = _iPressedTextureId;
  g_bGuiIsDirty = 1;
  ControlPtr->m_bDirty = 1;
  return 1;
}


// address=[0x2fa1ea0]
// Decompiled from char __thiscall IGuiEngine::SetUserLogoImage(IGuiEngine *this, int a2, int a3, WORD a4)
bool  IGuiEngine::SetUserLogoImage(int a2, int a3, int a4) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !GuiEngineReady() )
  {
    return 0;
  }
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
  {
    return 0;
  }
  ControlPtr->m_iMainTexture = a4;
  ControlPtr->m_iParam = -10;
  g_bGuiIsDirty = 1;
  ControlPtr->m_bDirty = 1;
  return 1;
}


// address=[0x2fa1f10]
// Decompiled from char __thiscall IGuiEngine::LockOwnerImage(IGuiEngine *this, int a2, int a3, struct SGuiRect *a4, unsigned __int16 **a5, unsigned int *a6)
bool  IGuiEngine::LockOwnerImage(int a2, int a3, struct SGuiRect & a4, unsigned short * & a5, unsigned int & a6) {
  
  unsigned __int16 *v7; // [esp+4h] [ebp-2DCh]
  struct SGuiControl *ControlPtr; // [esp+8h] [ebp-2D8h]
  int v9; // [esp+Ch] [ebp-2D4h] BYREF
  void *v10; // [esp+10h] [ebp-2D0h]

  *a5 = 0;
  *a6 = 0;
  *((_DWORD *)a4 + 2) = 0;
  *(_DWORD *)a4 = 0;
  *((_DWORD *)a4 + 1) = 0;
  *((_DWORD *)a4 + 3) = 0;
  if ( !GuiEngineReady() )
  {
    return 0;
  }
  if ( !(unsigned __int8)sub_2FA2880(a2) )
  {
    return 0;
  }
  v7 = (unsigned __int16 *)GuiGetContainer2(a2);
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
  {
    return 0;
  }
  if ( ControlPtr->m_iControlType != 9 )
  {
    return 0;
  }
  if ( dword_3E2F134 >= 0 )
  {
    return 0;
  }
  (**(void (__thiscall ***)(int, int *, _DWORD))g_pGfxManager)(g_pGfxManager, &v9, v7[5]);
  if ( v9 && v10 )
  {
    *a5 = IGfxEngine::BeginWriteToSurface((IGfxEngine *)g_pGfxEngine, *v7, a6);
    if ( *a5 )
    {
      dword_3E2F134 = *v7;
      FastBlit8Bit((void *)(v9 + 12), v7[3], ControlPtr->m_iX, ControlPtr->m_iY, ControlPtr->m_iWidth, ControlPtr->m_iHeight, *a5, *a6, ControlPtr->m_iX, ControlPtr->m_iY, v10);
      *a5 += (*a6 >> 1) * ControlPtr->m_iY;
      *a5 += ControlPtr->m_iX;
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    BBSupportTracePrintF(0, "GUI ENGINE: Background gfx in owner draw control not accessible!");
    return 0;
  }
}


// address=[0x2fa2130]
// Decompiled from char __thiscall IGuiEngine::UnlockOwnerImage(IGuiEngine *this, int a2, int a3)
bool  IGuiEngine::UnlockOwnerImage(int a2, int a3) {
  
  unsigned __int16 *v4; // [esp+4h] [ebp-8h]
  struct SGuiControl *ControlPtr; // [esp+8h] [ebp-4h]

  if ( !GuiEngineReady() )
  {
    return 0;
  }
  if ( !(unsigned __int8)sub_2FA2880(a2) )
  {
    return 0;
  }
  v4 = (unsigned __int16 *)GuiGetContainer2(a2);
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
  {
    return 0;
  }
  if ( ControlPtr->m_iControlType != 9 )
  {
    return 0;
  }
  if ( dword_3E2F134 < 0 )
  {
    return 0;
  }
  dword_3E2F134 = -1;
  return IGfxEngine::EndWriteToSurface(g_pGfxEngine, *v4);
}


// address=[0x2fa21d0]
// Decompiled from bool __thiscall IGuiEngine::EraseOwnerImage(IGuiEngine *this, int a2, int a3)
bool  IGuiEngine::EraseOwnerImage(int a2, int a3) {
  
  unsigned int v4; // [esp+4h] [ebp-2E4h] BYREF
  unsigned __int16 *v5; // [esp+8h] [ebp-2E0h]
  unsigned __int16 *v6; // [esp+Ch] [ebp-2DCh]
  struct SGuiControl *ControlPtr; // [esp+10h] [ebp-2D8h]
  int v8; // [esp+14h] [ebp-2D4h] BYREF
  void *v9; // [esp+18h] [ebp-2D0h]

  if ( !GuiEngineReady() )
  {
    return 0;
  }
  if ( !(unsigned __int8)sub_2FA2880(a2) )
  {
    return 0;
  }
  v6 = (unsigned __int16 *)GuiGetContainer2(a2);
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
  {
    return 0;
  }
  if ( ControlPtr->m_iControlType != 9 )
  {
    return 0;
  }
  if ( dword_3E2F134 >= 0 )
  {
    return 0;
  }
  (**(void (__thiscall ***)(int, int *, _DWORD))g_pGfxManager)(g_pGfxManager, &v8, v6[5]);
  if ( v8 && v9 )
  {
    v5 = IGfxEngine::BeginWriteToSurface((IGfxEngine *)g_pGfxEngine, *v6, &v4);
    if ( v5 )
    {
      FastBlit8Bit((void *)(v8 + 12), v6[3], ControlPtr->m_iX, ControlPtr->m_iY, ControlPtr->m_iWidth, ControlPtr->m_iHeight, v5, v4, ControlPtr->m_iX, ControlPtr->m_iY, v9);
      return IGfxEngine::EndWriteToSurface((IGfxEngine *)g_pGfxEngine, *v6);
    }
    else
    {
      return 0;
    }
  }
  else
  {
    BBSupportTracePrintF(0, "GUI ENGINE: Background gfx in owner draw control not accessible!");
    return 0;
  }
}


// address=[0x2fa2390]
// Decompiled from char __thiscall IGuiEngine::SetSliderPosition(IGuiEngine *this, int _iContainer, int _iControl, unsigned int _iSliderPos)
bool  IGuiEngine::SetSliderPosition(int _iContainer, int _iControl, int _iSliderPos) {
  
  struct SGuiControl *v5; // [esp+4h] [ebp-8h]
  struct SGuiControl *pControl; // [esp+8h] [ebp-4h]

  if ( !GuiEngineReady() )
  {
    return 0;
  }
  pControl = GetControlPtr(_iContainer, _iControl);
  if ( !pControl )
  {
    return 0;
  }
  if ( _iSliderPos > 0x64 )
  {
    return 0;
  }
  if ( pControl->m_iControlType == GUI_CNTRL_SLIDER2 && g_pCurrentDragControl && LOBYTE(g_pCurrentDragControl->m_iShowTexture) == LOBYTE(pControl->m_iShowTexture) )
  {
    return 0;
  }
  if ( (pControl->m_iEffects & 1) != 0 )
  {
    pControl->m_iEffects &= ~1u;
  }
  if ( pControl->m_iControlType == GUI_CNTRL_SLIDER && g_pCurrentDragControl && g_pCurrentDragControl == pControl )
  {
    return 0;
  }
  if ( pControl->m_iParam == _iSliderPos )
  {
    return 1;
  }
  pControl->m_iParam = _iSliderPos;
  g_bGuiIsDirty = 1;
  pControl->m_bDirty = 1;
  if ( pControl->m_iControlType != GUI_CNTRL_SLIDER && pControl->m_iControlType != GUI_CNTRL_SLIDER2 )
  {
    return 1;
  }
  v5 = pControl - 1;
  if ( pControl[-1].m_iControlType != GUI_CNTRL_SLIDERAREA )
  {
    BBSupportTracePrintF(0, "GUI ENGINE: No previous control GUI_CNTRL_SLIDERAREA of GUI_CNTRL_SLIDER!");
    return 0;
  }
  pControl->m_iX = CalcSliderPosition(v5->m_iX, v5->m_iWidth + v5->m_iX - pControl->m_iWidth, pControl->m_iParam, 0);
  v5->m_bDirty = 1;
  return 1;
}


// address=[0x2fa2510]
// Decompiled from int __thiscall IGuiEngine::GetSliderPosition(IGuiEngine *this, int _iContainer, int _iControl)
int  IGuiEngine::GetSliderPosition(int _iContainer, int _iControl) {
  
  struct SGuiControl *pControl; // [esp+4h] [ebp-4h]

  if ( !GuiEngineReady() )
  {
    return -1;
  }
  pControl = GetControlPtr(_iContainer, _iControl);
  if ( !pControl )
  {
    return -1;
  }
  if ( pControl->m_iControlType == GUI_CNTRL_SLIDER || pControl->m_iControlType == GUI_CNTRL_SLIDER2 )
  {
    return pControl->m_iParam;
  }
  return -1;
}


// address=[0x2fa2580]
// Decompiled from char __thiscall IGuiEngine::SelectControl(IGuiEngine *this, int _iContainer, int _iControlId, bool a4)
bool  IGuiEngine::SelectControl(int _iContainer, int _iControlId, bool a4) {
  
  int SurfaceID; // eax
  int v6; // [esp-8h] [ebp-10h]
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !GuiEngineReady() )
  {
    return 0;
  }
  ControlPtr = GetControlPtr(_iContainer, _iControlId);
  if ( !ControlPtr )
  {
    return 0;
  }
  if ( ((ControlPtr->m_iEffects & 1) == 0 || a4) && ((ControlPtr->m_iEffects & 1) != 0 || !a4) )
  {
    return 1;
  }
  if ( ControlPtr->m_iControlType == 2 && a4 || ControlPtr->m_iControlType == GUI_CNTRL_RADIO )
  {
    SelectRadioGroup(ControlPtr);
  }
  else if ( ControlPtr->m_iControlType == 1 )
  {
    SetControlState(ControlPtr, 1, a4);
  }
  else if ( (!ControlPtr->m_iControlType || ControlPtr->m_iControlType == GUI_CNTRL_BUTTON) && a4 )
  {
    if ( g_pfDialogCallbacks[GetSurfaceID(ControlPtr)] )
    {
      v6 = (ControlPtr->m_iEffects << 16) + ControlPtr->m_iValueLink;
      SurfaceID = GetSurfaceID(ControlPtr);
      g_pfDialogCallbacks[SurfaceID](3, v6, 0);
    }
  }
  else if ( (ControlPtr->m_iControlType == 5 || ControlPtr->m_iControlType == 20) && a4 )
  {
    g_pCurrentEditControl = (int)ControlPtr;
    SelectEditControl(ControlPtr, 0xF00000);
  }
  return 1;
}


// address=[0x2fa2700]
// Decompiled from char __thiscall IGuiEngine::ResetRadioGroup(IGuiEngine *this, int _iContainer, int _iControlId)
bool  IGuiEngine::ResetRadioGroup(int _iContainer, int _iControlId) {
  
  int m_iShowTexture_low; // [esp+4h] [ebp-10h]
  struct SGuiControl *v5; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  struct SGuiControl *pControl; // [esp+10h] [ebp-4h]
  char *v8; // [esp+10h] [ebp-4h]

  if ( !GuiEngineReady() )
  {
    return 0;
  }
  pControl = GetControlPtr(_iContainer, _iControlId);
  if ( !pControl )
  {
    return 0;
  }
  m_iShowTexture_low = LOBYTE(pControl->m_iShowTexture);
  v5 = (struct SGuiControl *)((char *)g_pFileHeader + g_pFileHeader->m_iContainerMap[pControl->m_iParentContainer]);
  v8 = (char *)&v5->m_spText;
  for ( i = 0;
        i < *(unsigned __int16 *)&v5->m_iEditProperty1;
        ++i )
  {
    if ( (v8[27] & 1) != 0 && (unsigned __int8)v8[28] == m_iShowTexture_low )
    {
      SetControlState((struct SGuiControl *)v8, 1, 0);
    }
    v8 += 36;
  }
  return 1;
}


// address=[0x2fa27d0]
// Decompiled from char __thiscall IGuiEngine::SetWidth(IGuiEngine *this, int _iContainer, int _iControl, WORD _iWidth)
bool  IGuiEngine::SetWidth(int _iContainer, int _iControl, int _iWidth) {
  
  struct SGuiControl *pControl; // [esp+4h] [ebp-4h]

  if ( !GuiEngineReady() )
  {
    return 0;
  }
  pControl = GetControlPtr(_iContainer, _iControl);
  if ( !pControl )
  {
    return 0;
  }
  pControl->m_iWidth = _iWidth;
  return 1;
}


// address=[0x2fa2820]
// Decompiled from char __thiscall IGuiEngine::SetPosition(IGuiEngine *this, int _iContainer, int _iControl, WORD _iX, WORD _iY)
bool  IGuiEngine::SetPosition(int _iContainer, int _iControl, int _iX, int _iY) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !GuiEngineReady() )
  {
    return 0;
  }
  ControlPtr = GetControlPtr(_iContainer, _iControl);
  if ( !ControlPtr )
  {
    return 0;
  }
  ControlPtr->m_iX = _iX;
  ControlPtr->m_iY = _iY;
  return 1;
}


// address=[0x2fa0940]
// Decompiled from void __thiscall IGuiEngine::InitShadeTables(IGuiEngine *this)
void  IGuiEngine::InitShadeTables(void) {
  
  int j; // [esp+4h] [ebp-14h]
  int i; // [esp+8h] [ebp-10h]
  int iB; // [esp+Ch] [ebp-Ch] MAPDST
  int iG; // [esp+10h] [ebp-8h] MAPDST
  int iR; // [esp+14h] [ebp-4h] MAPDST

  iR = 150;
  iG = 4;
  iB = 12;
  for ( i = 0;
        i < 16;
        ++i )
  {
    g_uShadeTable1[i] = IGfxEngine::ConvertRgbToHicol(iR, iG, iB);
    iR = (int)(float)((float)((float)((float)i * 0.079999998) + 1.0) * 150.0);
    iG = (int)(float)((float)((float)((float)i * 0.079999998) + 1.0) * 4.0);
    iB = (int)(float)((float)((float)((float)i * 0.079999998) + 1.0) * 12.0);
    if ( iR > 255 )
    {
      iR = 255;
    }
    if ( iG > 255 )
    {
      iG = 255;
    }
    if ( iB > 255 )
    {
      iB = 255;
    }
  }
  iR = 10;
  iG = 150;
  iB = 3;
  for ( j = 0;
        j < 16;
        ++j )
  {
    g_uShadeTable2[j] = IGfxEngine::ConvertRgbToHicol(iR, iG, iB);
    iR = (int)(float)((float)((float)((float)j * 0.079999998) + 1.0) * 10.0);
    iG = (int)(float)((float)((float)((float)j * 0.079999998) + 1.0) * 150.0);
    iB = (int)(float)((float)((float)((float)j * 0.079999998) + 1.0) * 3.0);
    if ( iR > 255 )
    {
      iR = 255;
    }
    if ( iG > 255 )
    {
      iG = 255;
    }
    if ( iB > 255 )
    {
      iB = 255;
    }
  }
  g_iLeftShadeColor = IGfxEngine::ConvertRgbToHicol(199, 178, 111);
  g_iRightShadeColor = IGfxEngine::ConvertRgbToHicol(50, 41, 45);
  g_iStdShadeColor = IGfxEngine::ConvertRgbToHicol(50, 50, 50);
}


// address=[0x2fa0b80]
// Decompiled from struct tagRECT *__cdecl IGuiEngine::GetDialogDestinationRect(struct tagRECT *retstr, const struct GUI_MENU_DIALOG_HEADER *a2, int a3, int a4, float a5, float a6)
struct tagRECT __cdecl IGuiEngine::GetDialogDestinationRect(struct GUI_MENU_DIALOG_HEADER const & retstr, int a2, int a3, float a4, float a5) {
  
  LONG v7; // [esp+4h] [ebp-10h]
  LONG v8; // [esp+8h] [ebp-Ch]
  LONG v9; // [esp+Ch] [ebp-8h]

  v7 = a4 + a2->m_iY;
  v8 = (int)(float)((float)((float)a2->m_iWidth * a5) + 0.5) + a3 + a2->m_iX;
  v9 = (int)(float)((float)((float)a2->m_iHeight * a6) + 0.5) + v7;
  retstr->left = a3 + a2->m_iX;
  retstr->top = v7;
  retstr->right = v8;
  retstr->bottom = v9;
  return retstr;
}


