#include "IGuiEngine.h"

// Definitions for class IGuiEngine

// address=[0x13d8b60]
// Decompiled from int __thiscall IGuiEngine::GetDialogsRenderOffsetX(IGuiEngine *this)
int  IGuiEngine::GetDialogsRenderOffsetX(void)const {
  
  return *(_DWORD *)this;
}


// address=[0x13d8b80]
// Decompiled from int __thiscall IGuiEngine::GetDialogsRenderOffsetY(IGuiEngine *this)
int  IGuiEngine::GetDialogsRenderOffsetY(void)const {
  
  return *((_DWORD *)this + 1);
}


// address=[0x13d8ba0]
// Decompiled from float __thiscall IGuiEngine::GetDialogsRenderScaleX(IGuiEngine *this)
float  IGuiEngine::GetDialogsRenderScaleX(void)const {
  
  return *((float *)this + 2);
}


// address=[0x13d8bc0]
// Decompiled from double __thiscall IGuiEngine::GetDialogsRenderScaleY(IGuiEngine *this)
float  IGuiEngine::GetDialogsRenderScaleY(void)const {
  
  return *((float *)this + 3);
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
  g_pfDialogCallbacks[v12->m_iSurfaceType] = (int)a3;
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
// Decompiled from char __thiscall IGuiEngine::Init(IGuiEngine *this, struct IGfxEngine *a2, struct CGfxManager *a3, int a4, int a5, bool (__cdecl *a6)(int, int, int), int a7)
bool  IGuiEngine::Init(class IGfxEngine * a2, class CGfxManager * a3, void * a4, int a5, bool (__cdecl*)(int,int,int) a6, int _iLanguage) {
  
  int DeviceCaps; // eax
  HFONT FontA; // eax
  int v10; // [esp+4h] [ebp-20h]
  HDC hdc; // [esp+8h] [ebp-1Ch]
  int nNumber; // [esp+Ch] [ebp-18h]
  DWORD iCharSet; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  char v16; // [esp+23h] [ebp-1h]

  if ( !a2 || !a4 || !a3 )
  {
    return 0;
  }
  g_iDialogToIgnore = -1;
  g_bDisableEvents = 1;
  g_pGfxEngine = (int)a2;
  if ( GetGfxInterfaceVersion() == 229 )
  {
    iCharSet = 0;
    v16 = 0;
    g_iAlignMode = 0;
    v10 = 0;
    switch ( a7 )
    {
      case 5:
      case 11:
      case 13:
        iCharSet = 238;
        break;
      case 6:
        iCharSet = 129;
        v16 = 1;
        v10 = -2;
        break;
      case 7:
        iCharSet = 136;
        v16 = 1;
        break;
      case 12:
        g_iAlignMode = 1;
        iCharSet = 177;
        v16 = 1;
        break;
      case 16:
        iCharSet = 204;
        break;
      case 18:
        iCharSet = 128;
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
        nNumber = v10 + dword_3AD2458[21 * i];
        if ( v16 )
        {
          DeviceCaps = GetDeviceCaps(hdc, 90);
          nNumber = MulDiv(nNumber, 4 * DeviceCaps, 374);
        }
        if ( byte_3AD2478[84 * i] )
        {
          FontA = CreateFontA(nNumber, dword_3AD245C[21 * i], 0, 0, dword_3AD2460[21 * i], 0, 0, 0, iCharSet, 0, 0, 4u, 0, &aArial_1[84 * i]);
        }
        else
        {
          FontA = CreateFontA(nNumber, dword_3AD245C[21 * i], 0, 0, dword_3AD2460[21 * i], 0, 0, 0, iCharSet, 0, 0, 0, 0, &aArial_1[84 * i]);
        }
        g_hFonts[i] = FontA;
        if ( !g_hFonts[i] )
        {
          BBSupportTracePrintF(0, "GUI ENGINE: Cannot create font!");
        }
      }
      ReleaseDC(0, hdc);
      IGfxEngine::SetWidthOfLeftGuiBorder((IGfxEngine *)g_pGfxEngine, 0);
      g_pGfxManager = (int)a3;
      g_pFileHeader = a4;
      g_pCurrentSelectedControl = 0;
      g_pCurrentDragControl = 0;
      g_pCurrentEditControl = 0;
      g_pCurrentRepeatControl = 0;
      memset(g_iOpenDialogs, 0, sizeof(g_iOpenDialogs));
      memset(g_mbstrTextTable, 0, 0x5DC0u);
      memset(g_bUsedTexts, 0, 0x50u);
      IGuiEngine::InitShadeTables(this);
      g_bGuiIsDirty = 1;
      IGuiEngine::OpenDialog(this, a5, a6);
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
// Decompiled from BOOL __thiscall IGuiEngine::EnableEventInput(IGuiEngine *this, bool a2)
void  IGuiEngine::EnableEventInput(bool a2) {
  
  BOOL result; // eax

  result = a2;
  g_bDisableEvents = !a2;
  return result;
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
// Decompiled from char __thiscall IGuiEngine::GetDialogRect(IGuiEngine *this, int a2, struct SGuiRect *a3)
bool  IGuiEngine::GetDialogRect(int a2, struct SGuiRect & a3) {
  
  GUI_MENU_DIALOG_HEADER *v4; // eax

  if ( !sub_2FA28C0() )
  {
    return 0;
  }
  if ( !(unsigned __int8)sub_2FA2880(a2) )
  {
    return 0;
  }
  v4 = (GUI_MENU_DIALOG_HEADER *)sub_2FA2900(a2);
  *(_DWORD *)a3 = v4->m_iX;
  *((_DWORD *)a3 + 1) = v4->m_iY;
  *((_DWORD *)a3 + 2) = v4->m_iX + v4->m_iWidth - 1;
  *((_DWORD *)a3 + 3) = v4->m_iY + v4->m_iHeight - 1;
  return 1;
}


// address=[0x2fa1090]
// Decompiled from char __thiscall IGuiEngine::SetDialogRect(_DWORD *this, int a2, int a3, int a4, __int16 a5, __int16 a6)
bool  IGuiEngine::SetDialogRect(int a2, struct SGuiRect a3) {
  
  unsigned __int16 *v8; // [esp+4h] [ebp-4h]

  if ( !sub_2FA28C0() )
  {
    return 0;
  }
  if ( !(unsigned __int8)sub_2FA2880(a2) )
  {
    return 0;
  }
  v8 = (unsigned __int16 *)sub_2FA2900(a2);
  v8[1] = a3;
  v8[2] = a4;
  v8[3] = a5 + 1 - a3;
  v8[4] = a6 + 1 - a4;
  IGfxEngine::SetGuiSurfaceDestinationPosition((IGfxEngine *)g_pGfxEngine, *v8, a3 + *this, a4 + this[1]);
  return 1;
}


// address=[0x2fa1140]
// Decompiled from bool __thiscall IGuiEngine::MoveDialogTo(IGuiEngine *this, int a2, int a3, int a4)
bool  IGuiEngine::MoveDialogTo(int a2, int a3, int a4) {
  
  unsigned __int16 *v6; // [esp+4h] [ebp-4h]

  if ( !sub_2FA28C0() )
  {
    return 0;
  }
  if ( !(unsigned __int8)sub_2FA2880(a2) )
  {
    return 0;
  }
  v6 = (unsigned __int16 *)sub_2FA2900(a2);
  v6[1] = a3;
  v6[2] = a4;
  return IGfxEngine::SetGuiSurfaceDestinationPosition((IGfxEngine *)g_pGfxEngine, *v6, a3 + *(_DWORD *)this, a4 + *((_DWORD *)this + 1));
}


// address=[0x2fa11c0]
// Decompiled from char __thiscall IGuiEngine::GetDialogRenderRect(IGuiEngine *this, int a2, struct SGuiRect *a3)
bool  IGuiEngine::GetDialogRenderRect(int a2, struct SGuiRect & a3) {
  
  struct tagRECT v4; // [esp+8h] [ebp-3Ch] BYREF
  const struct GUI_MENU_DIALOG_HEADER *v5; // [esp+18h] [ebp-2Ch]
  IGuiEngine *v6; // [esp+1Ch] [ebp-28h]
  LONG top; // [esp+24h] [ebp-20h]
  __int64 v8; // [esp+28h] [ebp-1Ch]
  struct tagRECT v9; // [esp+30h] [ebp-14h]

  v6 = this;
  if ( !sub_2FA28C0() )
  {
    return 0;
  }
  if ( !(unsigned __int8)sub_2FA2880(a2) )
  {
    return 0;
  }
  v5 = (const struct GUI_MENU_DIALOG_HEADER *)sub_2FA2900(a2);
  v9 = *IGuiEngine::GetDialogDestinationRect(&v4, v5, *(_DWORD *)v6, *((_DWORD *)v6 + 1), *((float *)v6 + 2), *((float *)v6 + 3));
  top = v9.top;
  v8 = *(_QWORD *)&v9.right;
  *(_DWORD *)a3 = v9.left;
  *((_DWORD *)a3 + 2) = v8;
  *((_DWORD *)a3 + 1) = top;
  *((_DWORD *)a3 + 3) = HIDWORD(v8);
  return 1;
}


// address=[0x2fa12b0]
// Decompiled from bool __thiscall IGuiEngine::SetDialogRenderPos(IGuiEngine *this, int a2, int a3, int a4)
bool  IGuiEngine::SetDialogRenderPos(int a2, int a3, int a4) {
  
  return IGuiEngine::MoveDialogTo(this, a2, a3 - *(_DWORD *)this, a4 - *((_DWORD *)this + 1));
}


// address=[0x2fa12e0]
// Decompiled from char __thiscall IGuiEngine::EnableTooltipsExt(IGuiEngine *this, bool a2)
void  IGuiEngine::EnableTooltipsExt(bool a2) {
  
  char result; // al
  int SurfaceID; // eax
  int v4; // eax
  int v5; // [esp-8h] [ebp-Ch]
  int m_iTooltipLinkExtra; // [esp-4h] [ebp-8h]

  if ( CToolTip::IsOpen((CToolTip *)g_cToolTipExt) && !a2 )
  {
    CToolTip::SetSourceDialogSurfaceID((CToolTip *)g_cToolTipExt, -1);
    CToolTip::CloseTooltip((CToolTip *)g_cToolTipExt);
  }
  CToolTip::SetEnableStatus((CToolTip *)g_cToolTipExt, a2);
  result = a2;
  if ( !a2 )
  {
    return result;
  }
  if ( !g_pCurrentSelectedControl )
  {
    return result;
  }
  m_iTooltipLinkExtra = (__int16)g_pCurrentSelectedControl->m_iTooltipLinkExtra;
  v5 = (g_pCurrentSelectedControl->m_iEffects << 16) + g_pCurrentSelectedControl->m_iValueLink;
  SurfaceID = GetSurfaceID(g_pCurrentSelectedControl);
  ((void (__cdecl *)(int, int, int))g_pfDialogCallbacks[SurfaceID])(9, v5, m_iTooltipLinkExtra);
  v4 = GetSurfaceID(g_pCurrentSelectedControl);
  CToolTip::SetSourceDialogSurfaceID((CToolTip *)g_cToolTipExt, v4);
  return CToolTipExt::OpenTooltip((CToolTipExt *)g_cToolTipExt);
}


// address=[0x2fa13a0]
// Decompiled from int __thiscall IGuiEngine::SetDlgToIgnore(IGuiEngine *this, int a2, bool a3)
void  IGuiEngine::SetDlgToIgnore(int a2, bool a3) {
  
  int result; // eax

  result = sub_2FA28C0();
  if ( !(_BYTE)result )
  {
    return result;
  }
  result = sub_2FA2880(a2);
  if ( !(_BYTE)result )
  {
    return result;
  }
  result = a2;
  g_iDialogToIgnore = a2;
  if ( !a3 )
  {
    g_iDialogToIgnore = -1;
  }
  return result;
}


// address=[0x2fa13f0]
// Decompiled from char __stdcall IGuiEngine::SetTooltip(char *Str)
bool  IGuiEngine::SetTooltip(char const * Str) {
  
  if ( !sub_2FA28C0() || !Str )
  {
    return 0;
  }
  CToolTip::SetTooltipText(Str);
  return 1;
}


// address=[0x2fa1430]
// Decompiled from char __stdcall IGuiEngine::SetTooltipExt(char *Str)
bool  IGuiEngine::SetTooltipExt(char const * Str) {
  
  if ( !sub_2FA28C0() || !Str )
  {
    return 0;
  }
  CToolTip::SetTooltipText(g_cToolTipExt, Str);
  return 1;
}


// address=[0x2fa1470]
// Decompiled from char __thiscall IGuiEngine::SetTooltipID(IGuiEngine *this, int a2, int a3, int a4, int a5)
bool  IGuiEngine::SetTooltipID(int a2, int a3, int a4, int a5) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !sub_2FA28C0() )
  {
    return 0;
  }
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
  {
    return 0;
  }
  if ( a4 >= 0 )
  {
    ControlPtr->m_iTooltipLink = a4;
  }
  if ( a5 >= 0 )
  {
    ControlPtr->m_iTooltipLinkExtra = a5;
  }
  return 1;
}


// address=[0x2fa14d0]
// Decompiled from char __thiscall IGuiEngine::DisableDialogControls(IGuiEngine *this, int a2)
bool  IGuiEngine::DisableDialogControls(int a2) {
  
  char result; // al
  int v3; // [esp+4h] [ebp-4h]

  if ( !(unsigned __int8)sub_2FA2880(a2) )
  {
    return 0;
  }
  v3 = sub_2FA2900(a2);
  if ( !v3 )
  {
    return 0;
  }
  result = 1;
  *(_WORD *)(v3 + 12) = 0;
  return result;
}


// address=[0x2fa1520]
// Decompiled from char __thiscall IGuiEngine::SetText(struct IGuiEngine *this, int _iContainer, int _iControlId, char *Str)
bool  IGuiEngine::SetText(int _iContainer, int _iControlId, char const * Str) {
  
  int v5; // eax
  int v6; // ecx
  unsigned int m_iId; // [esp+4h] [ebp-14h]
  unsigned int v8; // [esp+8h] [ebp-10h]
  int i; // [esp+Ch] [ebp-Ch]
  int Count; // [esp+10h] [ebp-8h]
  struct SGuiControl *ControlPtr; // [esp+14h] [ebp-4h]

  if ( !sub_2FA28C0() || !Str )
  {
    return 0;
  }
  ControlPtr = GetControlPtr(_iContainer, _iControlId);
  if ( !ControlPtr )
  {
    return 0;
  }
  Count = strlen(Str);
  if ( ControlPtr->m_iControlType == 21 )
  {
    ControlPtr->m_iTextOffset = (DWORD)Str;
    if ( !Count )
    {
      ControlPtr->m_iTextOffset = 0;
    }
    ControlPtr->m_iUnknown23 = 1;
    g_bGuiIsDirty = 1;
    return 1;
  }
  else
  {
    if ( (ControlPtr->m_iId & 0x80u) == 0 )
    {
      goto LABEL_41;
    }
    for ( i = 0;
          i < 80;
          ++i )
    {
      if ( !g_bUsedTexts[i] )
      {
        ControlPtr->m_iId = i;
        g_bUsedTexts[i] = 1;
        break;
      }
    }
    if ( (ControlPtr->m_iId & 0x80u) != 0 )
    {
      return 0;
    }
    if ( Count )
    {
LABEL_41:
      if ( j___mbscmp((const unsigned __int8 *)Str, (const unsigned __int8 *)&g_mbstrTextTable[75 * (char)ControlPtr->m_iId]) )
      {
        if ( Count )
        {
          if ( Count >= 299 )
          {
            Count = 299;
          }
          j__strncpy((char *)&g_mbstrTextTable[75 * (char)ControlPtr->m_iId], Str, Count);
          *((_BYTE *)&g_mbstrTextTable[75 * (char)ControlPtr->m_iId] + Count) = 0;
          g_bGuiIsDirty = 1;
          ControlPtr->m_iUnknown23 = 1;
          return 1;
        }
        else
        {
          if ( ControlPtr->m_iControlType == 5 || ControlPtr->m_iControlType == 20 )
          {
            LOBYTE(g_mbstrTextTable[75 * (char)ControlPtr->m_iId]) = 0;
          }
          else
          {
            LOBYTE(g_mbstrTextTable[75 * (char)ControlPtr->m_iId]) = 0;
            m_iId = (char)ControlPtr->m_iId;
            if ( m_iId >= 0x50 )
            {
              report_rangecheckfailure();
            }
            v6 = (char)ControlPtr->m_iId;
            g_bUsedTexts[m_iId] = 0;
            ControlPtr->m_iId = -1;
          }
          g_bGuiIsDirty = 1;
          ControlPtr->m_iUnknown23 = 1;
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
      if ( ControlPtr->m_iControlType == 5 || ControlPtr->m_iControlType == 20 )
      {
        LOBYTE(g_mbstrTextTable[75 * (char)ControlPtr->m_iId]) = 0;
      }
      else
      {
        LOBYTE(g_mbstrTextTable[75 * (char)ControlPtr->m_iId]) = 0;
        v8 = (char)ControlPtr->m_iId;
        if ( v8 >= 0x50 )
        {
          report_rangecheckfailure();
        }
        v5 = (char)ControlPtr->m_iId;
        g_bUsedTexts[v8] = 0;
        ControlPtr->m_iId = -1;
      }
      return 1;
    }
  }
}


// address=[0x2fa17e0]
// Decompiled from char __thiscall IGuiEngine::SetEditProperties(IGuiEngine *this, int a2, int a3, unsigned __int8 a4, unsigned __int8 a5)
bool  IGuiEngine::SetEditProperties(int a2, int a3, unsigned char a4, unsigned char a5) {
  
  unsigned __int8 v6; // [esp+4h] [ebp-8h]
  struct SGuiControl *ControlPtr; // [esp+8h] [ebp-4h]

  if ( !sub_2FA28C0() )
  {
    return 0;
  }
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
  {
    return 0;
  }
  if ( ControlPtr->m_iControlType != 5 && ControlPtr->m_iControlType != 20 )
  {
    return 0;
  }
  if ( a4 >= 0x73u )
  {
    v6 = 115;
  }
  else
  {
    v6 = a4;
  }
  LOBYTE(ControlPtr->unknown) = v6;
  HIBYTE(ControlPtr->unknown) = a5;
  return 1;
}


// address=[0x2fa1870]
// Decompiled from char __thiscall IGuiEngine::SetTypeAsButton(IGuiEngine *this, int a2, int a3)
bool  IGuiEngine::SetTypeAsButton(int a2, int a3) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !sub_2FA28C0() )
  {
    return 0;
  }
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
  {
    return 0;
  }
  ControlPtr->m_iControlType = 13;
  ControlPtr->m_iWidth = 161;
  ControlPtr->m_iHeight = 30;
  ControlPtr->m_iMainTexture = 196;
  ControlPtr->m_iPressedTexture = 197;
  ControlPtr->m_iTextStyle = 6;
  ControlPtr->m_iUnknown1F = 2;
  LOBYTE(ControlPtr->m_iUnknown20[0]) = 4;
  ControlPtr->m_iX = 567;
  ControlPtr->m_iY = 100;
  return 1;
}


// address=[0x2fa1920]
// Decompiled from char __thiscall IGuiEngine::SetTypeAsText(IGuiEngine *this, int a2, int a3)
bool  IGuiEngine::SetTypeAsText(int a2, int a3) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !sub_2FA28C0() )
  {
    return 0;
  }
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
  {
    return 0;
  }
  ControlPtr->m_iControlType = 21;
  return 1;
}


// address=[0x2fa1970]
// Decompiled from char __thiscall IGuiEngine::SetTypeAsRadio(IGuiEngine *this, int a2, int a3, WORD a4, WORD a5)
bool  IGuiEngine::SetTypeAsRadio(int a2, int a3, int a4, int a5) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !sub_2FA28C0() )
  {
    return 0;
  }
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
  {
    return 0;
  }
  ControlPtr->m_iControlType = 3;
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

  if ( !sub_2FA28C0() )
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

  if ( !sub_2FA28C0() )
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
  if ( !sub_2FA28C0() )
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

  if ( !sub_2FA28C0() )
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
  HIBYTE(ControlPtr->m_iUnknown20[1]) = 1;
  return 1;
}


// address=[0x2fa1ce0]
// Decompiled from bool __thiscall IGuiEngine::EnableControl(IGuiEngine *this, int a2, int a3, bool a4)
bool  IGuiEngine::EnableControl(int a2, int a3, bool a4) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-8h]
  bool v6; // [esp+Bh] [ebp-1h]

  if ( !sub_2FA28C0() )
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

  if ( !sub_2FA28C0() )
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
// Decompiled from char __thiscall IGuiEngine::SetImages(void *this, int a2, int a3, int a4, int a5)
bool  IGuiEngine::SetImages(int a2, int a3, int a4, int a5) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !sub_2FA28C0() )
  {
    return 0;
  }
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
  {
    return 0;
  }
  if ( ControlPtr->m_iMainTexture == a4 && ControlPtr->m_iPressedTexture == a5 )
  {
    return 1;
  }
  ControlPtr->m_iMainTexture = a4;
  ControlPtr->m_iPressedTexture = a5;
  g_bGuiIsDirty = 1;
  HIBYTE(ControlPtr->m_iUnknown20[1]) = 1;
  return 1;
}


// address=[0x2fa1ea0]
// Decompiled from char __thiscall IGuiEngine::SetUserLogoImage(IGuiEngine *this, int a2, int a3, WORD a4)
bool  IGuiEngine::SetUserLogoImage(int a2, int a3, int a4) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !sub_2FA28C0() )
  {
    return 0;
  }
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
  {
    return 0;
  }
  ControlPtr->m_iMainTexture = a4;
  ControlPtr->m_iSliderPosition = -10;
  g_bGuiIsDirty = 1;
  HIBYTE(ControlPtr->m_iUnknown20[1]) = 1;
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
  if ( !sub_2FA28C0() )
  {
    return 0;
  }
  if ( !(unsigned __int8)sub_2FA2880(a2) )
  {
    return 0;
  }
  v7 = (unsigned __int16 *)sub_2FA2900(a2);
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

  if ( !sub_2FA28C0() )
  {
    return 0;
  }
  if ( !(unsigned __int8)sub_2FA2880(a2) )
  {
    return 0;
  }
  v4 = (unsigned __int16 *)sub_2FA2900(a2);
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

  if ( !sub_2FA28C0() )
  {
    return 0;
  }
  if ( !(unsigned __int8)sub_2FA2880(a2) )
  {
    return 0;
  }
  v6 = (unsigned __int16 *)sub_2FA2900(a2);
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
// Decompiled from char __thiscall IGuiEngine::SetSliderPosition(IGuiEngine *this, int a2, int a3, unsigned int a4)
bool  IGuiEngine::SetSliderPosition(int a2, int a3, int a4) {
  
  struct SGuiControl *v5; // [esp+4h] [ebp-8h]
  struct SGuiControl *ControlPtr; // [esp+8h] [ebp-4h]

  if ( !sub_2FA28C0() )
  {
    return 0;
  }
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
  {
    return 0;
  }
  if ( a4 > 0x64 )
  {
    return 0;
  }
  if ( ControlPtr->m_iControlType == 8 && g_pCurrentDragControl && *(unsigned __int8 *)(g_pCurrentDragControl + 28) == LOBYTE(ControlPtr->m_iShowTexture) )
  {
    return 0;
  }
  if ( (ControlPtr->m_iEffects & 1) != 0 )
  {
    ControlPtr->m_iEffects &= ~1u;
  }
  if ( ControlPtr->m_iControlType == 7 && g_pCurrentDragControl && (struct SGuiControl *)g_pCurrentDragControl == ControlPtr )
  {
    return 0;
  }
  if ( (char)ControlPtr->m_iSliderPosition == a4 )
  {
    return 1;
  }
  ControlPtr->m_iSliderPosition = a4;
  g_bGuiIsDirty = 1;
  ControlPtr->m_iUnknown23 = 1;
  if ( ControlPtr->m_iControlType != 7 && ControlPtr->m_iControlType != 8 )
  {
    return 1;
  }
  v5 = ControlPtr - 1;
  if ( ControlPtr[-1].m_iControlType != 16 )
  {
    BBSupportTracePrintF(0, "GUI ENGINE: No previous control GUI_CNTRL_SLIDERAREA of GUI_CNTRL_SLIDER!");
    return 0;
  }
  ControlPtr->m_iX = CalcSliderPosition(v5->m_iX, v5->m_iWidth + v5->m_iX - ControlPtr->m_iWidth, (char)ControlPtr->m_iSliderPosition, 0);
  v5->m_iUnknown23 = 1;
  return 1;
}


// address=[0x2fa2510]
// Decompiled from int __thiscall IGuiEngine::GetSliderPosition(IGuiEngine *this, int a2, int a3)
int  IGuiEngine::GetSliderPosition(int a2, int a3) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !sub_2FA28C0() )
  {
    return -1;
  }
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
  {
    return -1;
  }
  if ( ControlPtr->m_iControlType == 7 || ControlPtr->m_iControlType == 8 )
  {
    return (char)ControlPtr->m_iSliderPosition;
  }
  return -1;
}


// address=[0x2fa2580]
// Decompiled from char __thiscall IGuiEngine::SelectControl(IGuiEngine *this, int a2, int _iControlId, bool a4)
bool  IGuiEngine::SelectControl(int a2, int _iControlId, bool a4) {
  
  int SurfaceID; // eax
  int v6; // [esp-8h] [ebp-10h]
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !sub_2FA28C0() )
  {
    return 0;
  }
  ControlPtr = GetControlPtr(a2, _iControlId);
  if ( !ControlPtr )
  {
    return 0;
  }
  if ( ((ControlPtr->m_iEffects & 1) == 0 || a4) && ((ControlPtr->m_iEffects & 1) != 0 || !a4) )
  {
    return 1;
  }
  if ( ControlPtr->m_iControlType == 2 && a4 || ControlPtr->m_iControlType == 3 )
  {
    SelectRadioGroup(ControlPtr);
  }
  else if ( ControlPtr->m_iControlType == 1 )
  {
    SetControlState(ControlPtr, 1, a4);
  }
  else if ( (!ControlPtr->m_iControlType || ControlPtr->m_iControlType == 13) && a4 )
  {
    if ( g_pfDialogCallbacks[GetSurfaceID(ControlPtr)] )
    {
      v6 = (ControlPtr->m_iEffects << 16) + ControlPtr->m_iValueLink;
      SurfaceID = GetSurfaceID(ControlPtr);
      ((void (__cdecl *)(int, int, _DWORD))g_pfDialogCallbacks[SurfaceID])(3, v6, 0);
    }
  }
  else if ( (ControlPtr->m_iControlType == 5 || ControlPtr->m_iControlType == 20) && a4 )
  {
    g_pCurrentEditControl = (int)ControlPtr;
    SelectEditControl(ControlPtr, (int)&dword_ECC2A8[53078]);
  }
  return 1;
}


// address=[0x2fa2700]
// Decompiled from char __thiscall IGuiEngine::ResetRadioGroup(IGuiEngine *this, int _iContainer, int _iControlId)
bool  IGuiEngine::ResetRadioGroup(int _iContainer, int _iControlId) {
  
  int unknown4_low; // [esp+4h] [ebp-10h]
  int v5; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  struct SGuiControl *ControlPtr; // [esp+10h] [ebp-4h]
  int v8; // [esp+10h] [ebp-4h]

  if ( !sub_2FA28C0() )
  {
    return 0;
  }
  ControlPtr = GetControlPtr(_iContainer, _iControlId);
  if ( !ControlPtr )
  {
    return 0;
  }
  unknown4_low = LOBYTE(ControlPtr->m_iShowTexture);
  v5 = *(_DWORD *)(g_pFileHeader + 4 * ControlPtr->m_iUnknown1F + 16) + g_pFileHeader;
  v8 = v5 + 16;
  for ( i = 0;
        i < *(unsigned __int16 *)(v5 + 12);
        ++i )
  {
    if ( (*(_BYTE *)(v8 + 27) & 1) != 0 && *(unsigned __int8 *)(v8 + 28) == unknown4_low )
    {
      SetControlState((struct SGuiControl *)v8, 1, 0);
    }
    v8 += 36;
  }
  return 1;
}


// address=[0x2fa27d0]
// Decompiled from char __thiscall IGuiEngine::SetWidth(IGuiEngine *this, int a2, int a3, WORD a4)
bool  IGuiEngine::SetWidth(int a2, int a3, int a4) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !sub_2FA28C0() )
  {
    return 0;
  }
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
  {
    return 0;
  }
  ControlPtr->m_iWidth = a4;
  return 1;
}


// address=[0x2fa2820]
// Decompiled from char __thiscall IGuiEngine::SetPosition(IGuiEngine *this, int a2, int a3, WORD a4, WORD a5)
bool  IGuiEngine::SetPosition(int a2, int a3, int a4, int a5) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !sub_2FA28C0() )
  {
    return 0;
  }
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
  {
    return 0;
  }
  ControlPtr->m_iX = a4;
  ControlPtr->m_iY = a5;
  return 1;
}


// address=[0x2fa0940]
// Decompiled from unsigned __int16 __thiscall IGuiEngine::InitShadeTables(IGuiEngine *this)
void  IGuiEngine::InitShadeTables(void) {
  
  unsigned __int16 result; // ax
  int j; // [esp+4h] [ebp-14h]
  int i; // [esp+8h] [ebp-10h]
  int v4; // [esp+Ch] [ebp-Ch]
  int v5; // [esp+Ch] [ebp-Ch]
  int v6; // [esp+10h] [ebp-8h]
  int v7; // [esp+10h] [ebp-8h]
  int v8; // [esp+14h] [ebp-4h]
  int v9; // [esp+14h] [ebp-4h]

  v8 = 150;
  v6 = 4;
  v4 = 12;
  for ( i = 0;
        i < 16;
        ++i )
  {
    g_uShadeTable1[i] = IGfxEngine::ConvertRgbToHicol(v8, v6, v4);
    v8 = (int)(float)((float)((float)((float)i * 0.079999998) + 1.0) * 150.0);
    v6 = (int)(float)((float)((float)((float)i * 0.079999998) + 1.0) * 4.0);
    v4 = (int)(float)((float)((float)((float)i * 0.079999998) + 1.0) * 12.0);
    if ( v8 > 255 )
    {
      v8 = 255;
    }
    if ( v6 > 255 )
    {
      v6 = 255;
    }
    if ( v4 > 255 )
    {
      v4 = 255;
    }
  }
  v9 = 10;
  v7 = 150;
  v5 = 3;
  for ( j = 0;
        j < 16;
        ++j )
  {
    g_uShadeTable2[j] = IGfxEngine::ConvertRgbToHicol(v9, v7, v5);
    v9 = (int)(float)((float)((float)((float)j * 0.079999998) + 1.0) * 10.0);
    v7 = (int)(float)((float)((float)((float)j * 0.079999998) + 1.0) * 150.0);
    v5 = (int)(float)((float)((float)((float)j * 0.079999998) + 1.0) * 3.0);
    if ( v9 > 255 )
    {
      v9 = 255;
    }
    if ( v7 > 255 )
    {
      v7 = 255;
    }
    if ( v5 > 255 )
    {
      v5 = 255;
    }
  }
  g_iLeftShadeColor = IGfxEngine::ConvertRgbToHicol(199, 178, 111);
  g_iRightShadeColor = IGfxEngine::ConvertRgbToHicol(50, 41, 45);
  result = IGfxEngine::ConvertRgbToHicol(50, 50, 50);
  g_iStdShadeColor = result;
  return result;
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


