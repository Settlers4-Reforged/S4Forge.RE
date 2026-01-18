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
// Decompiled from double __thiscall IGuiEngine::GetDialogsRenderScaleX(IGuiEngine *this)
float  IGuiEngine::GetDialogsRenderScaleX(void)const {
  
  return *((float *)this + 2);
}


// address=[0x13d8bc0]
// Decompiled from double __thiscall IGuiEngine::GetDialogsRenderScaleY(IGuiEngine *this)
float  IGuiEngine::GetDialogsRenderScaleY(void)const {
  
  return *((float *)this + 3);
}


// address=[0x2f9b380]
// Decompiled from char __thiscall IGuiEngine::OpenDialog(IGuiEngine *this, int a2, bool (__cdecl *a3)(int, int, int))
bool  IGuiEngine::OpenDialog(int a2, bool (__cdecl*)(int,int,int) a3) {
  
  int v4; // [esp+4h] [ebp-58h]
  float DialogsRenderScaleY; // [esp+8h] [ebp-54h]
  float DialogsRenderScaleX; // [esp+10h] [ebp-4Ch]
  int i; // [esp+1Ch] [ebp-40h]
  int j; // [esp+1Ch] [ebp-40h]
  bool v10; // [esp+20h] [ebp-3Ch]
  bool v11; // [esp+22h] [ebp-3Ah]
  unsigned __int16 *v12; // [esp+24h] [ebp-38h]
  struct SGuiControl *v13; // [esp+28h] [ebp-34h]
  struct SGuiControl *v14; // [esp+28h] [ebp-34h]
  _DWORD v15[2]; // [esp+2Ch] [ebp-30h] BYREF
  int v16; // [esp+34h] [ebp-28h]
  int v17; // [esp+38h] [ebp-24h]
  int v18; // [esp+3Ch] [ebp-20h]
  int v19; // [esp+40h] [ebp-1Ch]
  char v20; // [esp+44h] [ebp-18h]
  struct SEventStruct v21; // [esp+48h] [ebp-14h] BYREF

  if ( !sub_2F9E8F0() || !a3 )
    return 0;
  if ( !sub_2F9E8B0(a2) )
    return 0;
  v12 = (unsigned __int16 *)sub_2F9E930(a2);
  if ( g_iOpenDialogs[*v12] )
    return 0;
  v13 = (struct SGuiControl *)(v12 + 8);
  for ( i = 0; i < v12[6]; ++i )
  {
    if ( (v13->effects & 1) != 0 )
      v13->effects &= ~1u;
    if ( (v13->controlType == 5 || v13->controlType == 20) && (v13->id & 0x80u) != 0 )
    {
      if ( !IGuiEngine::SetText(this, a2, v13->valueLink, (char *)&byte_3AD1732) )
      {
        BBSupportTracePrintF(0, "GUI ENGINE: Cannot open dialog. Not enough string cache!");
        return 0;
      }
      LOBYTE(g_mbstrTextTable[75 * (char)v13->id]) = 0;
    }
    if ( g_pfSetEnableStatus )
    {
      if ( a2 != g_iDialogToIgnore )
      {
        v11 = (unsigned __int8)g_pfSetEnableStatus(a2, v13->valueLink, v13->controlType, (v13->effects & 4) == 0, 3) == 0;
        SetControlState(v13, 4, v11);
      }
    }
    v13 = (struct SGuiControl *)((char *)v13 + 36);
  }
  v20 = 1;
  v4 = v12[4];
  v15[0] = v12[3];
  v15[1] = v4;
  v16 = v12[1] + IGuiEngine::GetDialogsRenderOffsetX((IGuiEngine *)g_pGUIEngine);
  v17 = v12[2] + IGuiEngine::GetDialogsRenderOffsetY((IGuiEngine *)g_pGUIEngine);
  DialogsRenderScaleX = IGuiEngine::GetDialogsRenderScaleX((IGuiEngine *)g_pGUIEngine);
  v18 = v16 + (int)(float)((float)((float)v15[0] * DialogsRenderScaleX) + 0.5);
  DialogsRenderScaleY = IGuiEngine::GetDialogsRenderScaleY((IGuiEngine *)g_pGUIEngine);
  v19 = v17 + (int)(float)((float)((float)v4 * DialogsRenderScaleY) + 0.5);
  IGfxEngine::CreateGuiSurface((IGfxEngine *)g_pGfxEngine, *v12, (struct GFX_ENGINE_GUI_SURFACE_DESCRIPTION *)v15);
  IGfxEngine::SetVisibilityOfGuiSurface((IGfxEngine *)g_pGfxEngine, *v12, 1);
  g_iOpenDialogs[*v12] = a2 + 1;
  g_pfDialogCallbacks[*v12] = (int)a3;
  a3(0, 0, 0);
  v14 = (struct SGuiControl *)(v12 + 8);
  for ( j = 0; j < v12[6]; ++j )
  {
    if ( g_pfSetEnableStatus && a2 != g_iDialogToIgnore )
    {
      v10 = (unsigned __int8)g_pfSetEnableStatus(a2, v14->valueLink, v14->controlType, (v14->effects & 4) == 0, 1) == 0;
      SetControlState(v14, 4, v10);
    }
    v14 = (struct SGuiControl *)((char *)v14 + 36);
  }
  UpdateGui(*v12);
  v21.event = 5;
  v21.lparam = qword_471F794 + (HIDWORD(qword_471F794) << 16);
  v21.wparam = 0;
  v21.tick = 0;
  GuiEngine2_EventProc(&v21);
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
  for ( i = 0; i < 19; ++i )
    g_hFonts[i] = 0;
  InitTables();
  return this;
}


// address=[0x2f9ff60]
// Decompiled from int __thiscall IGuiEngine::~IGuiEngine(IGuiEngine *this)
 IGuiEngine::~IGuiEngine(void) {
  
  int result; // eax
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 19; ++i )
  {
    if ( g_hFonts[i] )
      DeleteObject(g_hFonts[i]);
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
// Decompiled from char __thiscall IGuiEngine::Init(  IGuiEngine *this,  struct IGfxEngine *a2,  struct CGfxManager *a3,  int a4,  int a5,  bool (__cdecl *a6)(int, int, int),  int a7)
bool  IGuiEngine::Init(class IGfxEngine * a2, class CGfxManager * a3, void * a4, int a5, bool (__cdecl*)(int,int,int) a6, int a7) {
  
  int DeviceCaps; // eax
  HFONT FontA; // eax
  int v10; // [esp+4h] [ebp-20h]
  HDC hdc; // [esp+8h] [ebp-1Ch]
  int nNumber; // [esp+Ch] [ebp-18h]
  DWORD iCharSet; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  char v16; // [esp+23h] [ebp-1h]

  if ( !a2 || !a4 || !a3 )
    return 0;
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
      for ( i = 0; i < 19; ++i )
      {
        if ( g_hFonts[i] )
          DeleteObject(g_hFonts[i]);
        nNumber = v10 + dword_3AD2458[21 * i];
        if ( v16 )
        {
          DeviceCaps = GetDeviceCaps(hdc, 90);
          nNumber = MulDiv(nNumber, 4 * DeviceCaps, 374);
        }
        if ( byte_3AD2478[84 * i] )
          FontA = CreateFontA(
                    nNumber,
                    dword_3AD245C[21 * i],
                    0,
                    0,
                    dword_3AD2460[21 * i],
                    0,
                    0,
                    0,
                    iCharSet,
                    0,
                    0,
                    4u,
                    0,
                    &aArial_1[84 * i]);
        else
          FontA = CreateFontA(
                    nNumber,
                    dword_3AD245C[21 * i],
                    0,
                    0,
                    dword_3AD2460[21 * i],
                    0,
                    0,
                    0,
                    iCharSet,
                    0,
                    0,
                    0,
                    0,
                    &aArial_1[84 * i]);
        g_hFonts[i] = FontA;
        if ( !g_hFonts[i] )
          BBSupportTracePrintF(0, "GUI ENGINE: Cannot create font!");
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
  int v3; // [esp+28h] [ebp-90h]
  int v4; // [esp+2Ch] [ebp-8Ch]
  int j; // [esp+30h] [ebp-88h]
  struct SGuiControl *v6; // [esp+34h] [ebp-84h]
  bool GuiSurfaceDescription; // [esp+3Bh] [ebp-7Dh]
  unsigned int i; // [esp+3Ch] [ebp-7Ch]
  IGuiEngine *v9; // [esp+40h] [ebp-78h]
  bool v10; // [esp+46h] [ebp-72h]
  bool v11; // [esp+47h] [ebp-71h]
  const struct GUI_MENU_DIALOG_HEADER *v12; // [esp+48h] [ebp-70h]
  _DWORD v13[7]; // [esp+4Ch] [ebp-6Ch] BYREF
  _DWORD v14[2]; // [esp+68h] [ebp-50h] BYREF
  struct tagRECT v15; // [esp+70h] [ebp-48h]
  char v16; // [esp+80h] [ebp-38h]
  struct tagRECT v17; // [esp+84h] [ebp-34h] BYREF
  struct tagRECT v18; // [esp+94h] [ebp-24h]
  struct tagRECT v19; // [esp+A4h] [ebp-14h]

  v9 = this;
  if ( g_pGfxEngine && g_pFileHeader && g_pGfxManager )
  {
    for ( i = 0; i < 0xE; ++i )
    {
      v12 = (const struct GUI_MENU_DIALOG_HEADER *)(*(_DWORD *)(g_pFileHeader + 4 * g_iOpenDialogs[i] + 12)
                                                  + g_pFileHeader);
      IGfxEngine::SetVisibilityOfGuiSurface((IGfxEngine *)g_pGfxEngine, i, 0);
      if ( g_iOpenDialogs[i] )
      {
        GuiSurfaceDescription = IGfxEngine::GetGuiSurfaceDescription(
                                  (IGfxEngine *)g_pGfxEngine,
                                  *(unsigned __int16 *)v12,
                                  (struct GFX_ENGINE_GUI_SURFACE_DESCRIPTION *)v13);
        if ( GuiSurfaceDescription
          && v13[0] == *((unsigned __int16 *)v12 + 3)
          && v13[1] == *((unsigned __int16 *)v12 + 4) )
        {
          v19 = *IGuiEngine::GetDialogDestinationRect(
                   &v2,
                   v12,
                   *(_DWORD *)v9,
                   *((_DWORD *)v9 + 1),
                   *((float *)v9 + 2),
                   *((float *)v9 + 3));
          v17 = v19;
          IGfxEngine::SetGuiSurfaceDestinationRect((IGfxEngine *)g_pGfxEngine, *(unsigned __int16 *)v12, &v17);
        }
        else
        {
          IGfxEngine::DestroyGuiSurface((IGfxEngine *)g_pGfxEngine, *(unsigned __int16 *)v12);
          v16 = 1;
          v3 = *((unsigned __int16 *)v12 + 3);
          v4 = *((unsigned __int16 *)v12 + 4);
          v14[0] = v3;
          v14[1] = v4;
          v18 = *IGuiEngine::GetDialogDestinationRect(
                   &v1,
                   v12,
                   *(_DWORD *)v9,
                   *((_DWORD *)v9 + 1),
                   *((float *)v9 + 2),
                   *((float *)v9 + 3));
          v15 = v18;
          IGfxEngine::CreateGuiSurface(
            (IGfxEngine *)g_pGfxEngine,
            *(unsigned __int16 *)v12,
            (struct GFX_ENGINE_GUI_SURFACE_DESCRIPTION *)v14);
        }
        IGfxEngine::SetVisibilityOfGuiSurface((IGfxEngine *)g_pGfxEngine, *(unsigned __int16 *)v12, 1);
        if ( g_pfSetEnableStatus )
        {
          v6 = (struct SGuiControl *)((char *)v12 + 16);
          for ( j = 0; j < *((unsigned __int16 *)v12 + 6); ++j )
          {
            v11 = (v6->effects & 4) == 0;
            v10 = (unsigned __int8)g_pfSetEnableStatus(g_iOpenDialogs[i] - 1, v6->valueLink, v6->controlType, v11, 4) == 0;
            SetControlState(v6, 4, v10);
            v6 = (struct SGuiControl *)((char *)v6 + 36);
          }
        }
        UpdateGui(i);
        if ( g_pfDialogCallbacks[*(unsigned __int16 *)v12] )
          ((void (__cdecl *)(int, _DWORD, _DWORD))g_pfDialogCallbacks[*(unsigned __int16 *)v12])(11, 0, 0);
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
    return 0;
  if ( a2 >= *(_DWORD *)(g_pFileHeader + 4) || a2 < 0 )
    return 0;
  v8 = 0;
  for ( i = 0; i < 0xE; ++i )
  {
    if ( g_iOpenDialogs[i] == a2 + 1 )
    {
      v8 = 1;
      break;
    }
  }
  if ( !v8 )
    return 0;
  v7 = (unsigned __int16 *)(*(_DWORD *)(g_pFileHeader + 4 * a2 + 16) + g_pFileHeader);
  IGfxEngine::SetVisibilityOfGuiSurface((IGfxEngine *)g_pGfxEngine, *v7, 0);
  v4 = v7 + 8;
  for ( j = 0; j < v7[6]; ++j )
  {
    if ( *((char *)v4 + 25) >= 0 )
    {
      LOBYTE(g_mbstrTextTable[75 * *((char *)v4 + 25)]) = 0;
      v3 = *((char *)v4 + 25);
      if ( v3 >= 0x50 )
        j____report_rangecheckfailure();
      g_bUsedTexts[v3] = 0;
    }
    *((_BYTE *)v4 + 25) = -1;
    v4 += 18;
  }
  if ( g_pCurrentEditControl && GetSurfaceID((struct SGuiControl *)g_pCurrentEditControl) == *v7 )
    g_pCurrentEditControl = 0;
  if ( g_pCurrentRepeatControl && GetSurfaceID((struct SGuiControl *)g_pCurrentRepeatControl) == *v7 )
    g_pCurrentRepeatControl = 0;
  if ( g_pCurrentSelectedControl && GetSurfaceID((struct SGuiControl *)g_pCurrentSelectedControl) == *v7 )
    g_pCurrentSelectedControl = 0;
  if ( g_pCurrentDragControl && GetSurfaceID((struct SGuiControl *)g_pCurrentDragControl) == *v7 )
    g_pCurrentDragControl = 0;
  if ( CToolTip::IsOpen((CToolTip *)&g_cToolTipExt)
    && CToolTip::GetSourceDialogSurfaceID((CToolTip *)&g_cToolTipExt) == *v7 )
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
void  IGuiEngine::EnableShortcuts(bool) {
  
  ;
}


// address=[0x2fa0920]
// Decompiled from bool (__cdecl *__thiscall IGuiEngine::SetCtrlStatusCallback(  IGuiEngine *this,  bool (__cdecl *a2)(int, int, int, bool, int)))(int, int, int, bool, int)
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
  
  unsigned __int16 *v4; // eax

  if ( !sub_2FA28C0() )
    return 0;
  if ( !(unsigned __int8)sub_2FA2880(a2) )
    return 0;
  v4 = (unsigned __int16 *)sub_2FA2900(a2);
  *(_DWORD *)a3 = v4[1];
  *((_DWORD *)a3 + 1) = v4[2];
  *((_DWORD *)a3 + 2) = v4[1] + v4[3] - 1;
  *((_DWORD *)a3 + 3) = v4[2] + v4[4] - 1;
  return 1;
}


// address=[0x2fa1090]
// Decompiled from char __thiscall IGuiEngine::SetDialogRect(_DWORD *this, int a2, int a3, int a4, __int16 a5, __int16 a6)
bool  IGuiEngine::SetDialogRect(int a2, struct SGuiRect a3) {
  
  unsigned __int16 *v8; // [esp+4h] [ebp-4h]

  if ( !sub_2FA28C0() )
    return 0;
  if ( !(unsigned __int8)sub_2FA2880(a2) )
    return 0;
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
    return 0;
  if ( !(unsigned __int8)sub_2FA2880(a2) )
    return 0;
  v6 = (unsigned __int16 *)sub_2FA2900(a2);
  v6[1] = a3;
  v6[2] = a4;
  return IGfxEngine::SetGuiSurfaceDestinationPosition(
           (IGfxEngine *)g_pGfxEngine,
           *v6,
           a3 + *(_DWORD *)this,
           a4 + *((_DWORD *)this + 1));
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
    return 0;
  if ( !(unsigned __int8)sub_2FA2880(a2) )
    return 0;
  v5 = (const struct GUI_MENU_DIALOG_HEADER *)sub_2FA2900(a2);
  v9 = *IGuiEngine::GetDialogDestinationRect(
          &v4,
          v5,
          *(_DWORD *)v6,
          *((_DWORD *)v6 + 1),
          *((float *)v6 + 2),
          *((float *)v6 + 3));
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
  int v6; // [esp-4h] [ebp-8h]

  if ( CToolTip::IsOpen((CToolTip *)&g_cToolTipExt) && !a2 )
  {
    CToolTip::SetSourceDialogSurfaceID((CToolTip *)&g_cToolTipExt, -1);
    CToolTip::CloseTooltip((CToolTip *)&g_cToolTipExt);
  }
  CToolTip::SetEnableStatus((CToolTip *)&g_cToolTipExt, a2);
  result = a2;
  if ( !a2 )
    return result;
  if ( !g_pCurrentSelectedControl )
    return result;
  v6 = *(__int16 *)(g_pCurrentSelectedControl + 22);
  v5 = (*(unsigned __int8 *)(g_pCurrentSelectedControl + 27) << 16)
     + *(unsigned __int16 *)(g_pCurrentSelectedControl + 10);
  SurfaceID = GetSurfaceID((struct SGuiControl *)g_pCurrentSelectedControl);
  ((void (__cdecl *)(int, int, int))g_pfDialogCallbacks[SurfaceID])(9, v5, v6);
  v4 = GetSurfaceID((struct SGuiControl *)g_pCurrentSelectedControl);
  CToolTip::SetSourceDialogSurfaceID((CToolTip *)&g_cToolTipExt, v4);
  return CToolTipExt::OpenTooltip((CToolTipExt *)&g_cToolTipExt);
}


// address=[0x2fa13a0]
// Decompiled from int __thiscall IGuiEngine::SetDlgToIgnore(IGuiEngine *this, int a2, bool a3)
void  IGuiEngine::SetDlgToIgnore(int a2, bool a3) {
  
  int result; // eax

  result = sub_2FA28C0();
  if ( !(_BYTE)result )
    return result;
  result = sub_2FA2880(a2);
  if ( !(_BYTE)result )
    return result;
  result = a2;
  g_iDialogToIgnore = a2;
  if ( !a3 )
    g_iDialogToIgnore = -1;
  return result;
}


// address=[0x2fa13f0]
// Decompiled from char __stdcall IGuiEngine::SetTooltip(char *Str)
bool  IGuiEngine::SetTooltip(char const * Str) {
  
  if ( !sub_2FA28C0() || !Str )
    return 0;
  CToolTip::SetTooltipText(Str);
  return 1;
}


// address=[0x2fa1430]
// Decompiled from char __stdcall IGuiEngine::SetTooltipExt(char *Str)
bool  IGuiEngine::SetTooltipExt(char const * Str) {
  
  if ( !sub_2FA28C0() || !Str )
    return 0;
  CToolTip::SetTooltipText(Str);
  return 1;
}


// address=[0x2fa1470]
// Decompiled from char __thiscall IGuiEngine::SetTooltipID(IGuiEngine *this, int a2, int a3, int a4, int a5)
bool  IGuiEngine::SetTooltipID(int a2, int a3, int a4, int a5) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !sub_2FA28C0() )
    return 0;
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
    return 0;
  if ( a4 >= 0 )
    ControlPtr->tooltipLink = a4;
  if ( a5 >= 0 )
    ControlPtr->tooltipLinkExtra = a5;
  return 1;
}


// address=[0x2fa14d0]
// Decompiled from char __thiscall IGuiEngine::DisableDialogControls(IGuiEngine *this, int a2)
bool  IGuiEngine::DisableDialogControls(int a2) {
  
  char result; // al
  int v3; // [esp+4h] [ebp-4h]

  if ( !(unsigned __int8)sub_2FA2880(a2) )
    return 0;
  v3 = sub_2FA2900(a2);
  if ( !v3 )
    return 0;
  result = 1;
  *(_WORD *)(v3 + 12) = 0;
  return result;
}


// address=[0x2fa1520]
// Decompiled from char __thiscall IGuiEngine::SetText(void *this, int a2, int a3, char *Str)
bool  IGuiEngine::SetText(int a2, int a3, char const * Str) {
  
  unsigned int v5; // [esp+4h] [ebp-14h]
  unsigned int v6; // [esp+8h] [ebp-10h]
  int i; // [esp+Ch] [ebp-Ch]
  int Count; // [esp+10h] [ebp-8h]
  struct SGuiControl *ControlPtr; // [esp+14h] [ebp-4h]

  if ( !(unsigned __int8)sub_2FA28C0(this) || !Str )
    return 0;
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
    return 0;
  Count = j__strlen(Str);
  if ( *((_BYTE *)ControlPtr + 24) == 21 )
  {
    *((_DWORD *)ControlPtr + 4) = Str;
    if ( !Count )
      *((_DWORD *)ControlPtr + 4) = 0;
    *((_BYTE *)ControlPtr + 35) = 1;
    g_bGuiIsDirty = 1;
    return 1;
  }
  else
  {
    if ( *((char *)ControlPtr + 25) >= 0 )
      goto LABEL_41;
    for ( i = 0; i < 80; ++i )
    {
      if ( !g_bUsedTexts[i] )
      {
        *((_BYTE *)ControlPtr + 25) = i;
        g_bUsedTexts[i] = 1;
        break;
      }
    }
    if ( *((char *)ControlPtr + 25) < 0 )
      return 0;
    if ( Count )
    {
LABEL_41:
      if ( j___mbscmp(
             (const unsigned __int8 *)Str,
             (const unsigned __int8 *)&g_mbstrTextTable[300 * *((char *)ControlPtr + 25)]) )
      {
        if ( Count )
        {
          if ( Count >= 299 )
            Count = 299;
          j__strncpy(&g_mbstrTextTable[300 * *((char *)ControlPtr + 25)], Str, Count);
          g_mbstrTextTable[300 * *((char *)ControlPtr + 25) + Count] = 0;
          g_bGuiIsDirty = 1;
          *((_BYTE *)ControlPtr + 35) = 1;
          return 1;
        }
        else
        {
          if ( *((_BYTE *)ControlPtr + 24) == 5 || *((_BYTE *)ControlPtr + 24) == 20 )
          {
            g_mbstrTextTable[300 * *((char *)ControlPtr + 25)] = 0;
          }
          else
          {
            g_mbstrTextTable[300 * *((char *)ControlPtr + 25)] = 0;
            v5 = *((char *)ControlPtr + 25);
            if ( v5 >= 0x50 )
              j____report_rangecheckfailure();
            g_bUsedTexts[v5] = 0;
            *((_BYTE *)ControlPtr + 25) = -1;
          }
          g_bGuiIsDirty = 1;
          *((_BYTE *)ControlPtr + 35) = 1;
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
      if ( *((_BYTE *)ControlPtr + 24) == 5 || *((_BYTE *)ControlPtr + 24) == 20 )
      {
        g_mbstrTextTable[300 * *((char *)ControlPtr + 25)] = 0;
      }
      else
      {
        g_mbstrTextTable[300 * *((char *)ControlPtr + 25)] = 0;
        v6 = *((char *)ControlPtr + 25);
        if ( v6 >= 0x50 )
          j____report_rangecheckfailure();
        g_bUsedTexts[v6] = 0;
        *((_BYTE *)ControlPtr + 25) = -1;
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
    return 0;
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
    return 0;
  if ( ControlPtr->controlType != 5 && ControlPtr->controlType != 20 )
    return 0;
  if ( a4 >= 0x73u )
    v6 = 115;
  else
    v6 = a4;
  LOBYTE(ControlPtr->unknown) = v6;
  HIBYTE(ControlPtr->unknown) = a5;
  return 1;
}


// address=[0x2fa1870]
// Decompiled from char __thiscall IGuiEngine::SetTypeAsButton(IGuiEngine *this, int a2, int a3)
bool  IGuiEngine::SetTypeAsButton(int a2, int a3) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !sub_2FA28C0() )
    return 0;
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
    return 0;
  ControlPtr->controlType = 13;
  ControlPtr->width = 161;
  ControlPtr->height = 30;
  ControlPtr->mainTexture = 196;
  ControlPtr->buttonPressedTexture = 197;
  ControlPtr->textStyle = 6;
  ControlPtr->unknownId = 2;
  LOBYTE(ControlPtr->unknownData[0]) = 4;
  ControlPtr->x = 567;
  ControlPtr->y = 100;
  return 1;
}


// address=[0x2fa1920]
// Decompiled from char __thiscall IGuiEngine::SetTypeAsText(IGuiEngine *this, int a2, int a3)
bool  IGuiEngine::SetTypeAsText(int a2, int a3) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !sub_2FA28C0() )
    return 0;
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
    return 0;
  ControlPtr->controlType = 21;
  return 1;
}


// address=[0x2fa1970]
// Decompiled from char __thiscall IGuiEngine::SetTypeAsRadio(IGuiEngine *this, int a2, int a3, WORD a4, WORD a5)
bool  IGuiEngine::SetTypeAsRadio(int a2, int a3, int a4, int a5) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !sub_2FA28C0() )
    return 0;
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
    return 0;
  ControlPtr->controlType = 3;
  ControlPtr->mainTexture = a4;
  ControlPtr->buttonPressedTexture = a5;
  ControlPtr->width = 20;
  ControlPtr->height = 20;
  ControlPtr->tooltipLink = -1;
  ControlPtr->tooltipLinkExtra = -1;
  return 1;
}


// address=[0x2fa1a00]
// Decompiled from bool __thiscall IGuiEngine::SetRadioCheckPressedState(IGuiEngine *this, int a2, int a3, bool a4)
bool  IGuiEngine::SetRadioCheckPressedState(int a2, int a3, bool a4) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !sub_2FA28C0() )
    return 0;
  ControlPtr = GetControlPtr(a2, a3);
  return ControlPtr && SetControlState(ControlPtr, 1, a4);
}


// address=[0x2fa1a50]
// Decompiled from char *__thiscall IGuiEngine::GetText(IGuiEngine *this, int container, int valueLink)
char const *  IGuiEngine::GetText(int container, int valueLink) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !sub_2FA28C0() )
    return 0;
  ControlPtr = GetControlPtr(container, valueLink);
  if ( !ControlPtr )
    return 0;
  if ( (ControlPtr->id & 0x80u) == 0 )          // id >= 0
    return (char *)&g_mbstrTextTable[75 * (char)ControlPtr->id];
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
    return -1;
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
    return -1;
  if ( (ControlPtr->id & 0x80u) != 0 )
    return -1;
  if ( !LOBYTE(g_mbstrTextTable[75 * (char)ControlPtr->id]) )
    return -1;
  if ( !CalcTextSize(
          ControlPtr->textStyle,
          (const unsigned __int8 *)&g_mbstrTextTable[75 * (char)ControlPtr->id],
          &psizl,
          0,
          -1) )
    return -1;
  if ( psizl.cx <= ControlPtr->width - 4 )
    return -1;
  v7 = 0;
  CalcTextSize(
    ControlPtr->textStyle,
    (const unsigned __int8 *)&g_mbstrTextTable[75 * (char)ControlPtr->id],
    &psizl,
    0,
    0);
  v6 = 251;
  while ( psizl.cx <= ControlPtr->width - 4 )
  {
    if ( --v6 < 0 )
      break;
    CalcTextSize(
      ControlPtr->textStyle,
      (const unsigned __int8 *)&g_mbstrTextTable[75 * (char)ControlPtr->id],
      &psizl,
      0,
      ++v7);
  }
  if ( v6 > 0 )
    return v7 - 1;
  else
    return -1;
}


// address=[0x2fa1c60]
// Decompiled from char __thiscall IGuiEngine::SetFontTemplate(IGuiEngine *this, int a2, int a3, int a4)
bool  IGuiEngine::SetFontTemplate(int a2, int a3, int a4) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !sub_2FA28C0() )
    return 0;
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
    return 0;
  if ( a4 >= 19 )
    return 0;
  if ( ControlPtr->textStyle == a4 )
    return 1;
  ControlPtr->textStyle = a4;
  g_bGuiIsDirty = 1;
  HIBYTE(ControlPtr->unknownData[1]) = 1;
  return 1;
}


// address=[0x2fa1ce0]
// Decompiled from bool __thiscall IGuiEngine::EnableControl(IGuiEngine *this, int a2, int a3, bool a4)
bool  IGuiEngine::EnableControl(int a2, int a3, bool a4) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-8h]
  bool v6; // [esp+Bh] [ebp-1h]

  if ( !sub_2FA28C0() )
    return 0;
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
    return 0;
  if ( !g_pfSetEnableStatus )
    return SetControlState(ControlPtr, 4, !a4);
  v6 = (unsigned __int8)g_pfSetEnableStatus(a2, ControlPtr->valueLink, ControlPtr->controlType, a4, 8) == 0;
  return SetControlState(ControlPtr, 4, v6);
}


// address=[0x2fa1da0]
// Decompiled from char __thiscall IGuiEngine::SetControlVisibility(void *this, int a2, int a3, char a4)
bool  IGuiEngine::SetControlVisibility(int a2, int a3, bool a4) {
  
  int ControlPtr; // [esp+4h] [ebp-8h]

  if ( !(unsigned __int8)sub_2FA28C0(this) )
    return 0;
  ControlPtr = GetControlPtr(a2, a3);
  if ( ControlPtr )
    return SetControlState(ControlPtr, 8, a4 == 0);
  else
    return 0;
}


// address=[0x2fa1e10]
// Decompiled from char __thiscall IGuiEngine::SetImages(void *this, int a2, int a3, int a4, int a5)
bool  IGuiEngine::SetImages(int a2, int a3, int a4, int a5) {
  
  int ControlPtr; // [esp+4h] [ebp-4h]

  if ( !(unsigned __int8)sub_2FA28C0(this) )
    return 0;
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
    return 0;
  if ( *(unsigned __int16 *)(ControlPtr + 8) == a4 && *(unsigned __int16 *)(ControlPtr + 14) == a5 )
    return 1;
  *(_WORD *)(ControlPtr + 8) = a4;
  *(_WORD *)(ControlPtr + 14) = a5;
  g_bGuiIsDirty = 1;
  *(_BYTE *)(ControlPtr + 35) = 1;
  return 1;
}


// address=[0x2fa1ea0]
// Decompiled from char __thiscall IGuiEngine::SetUserLogoImage(IGuiEngine *this, int a2, int a3, WORD a4)
bool  IGuiEngine::SetUserLogoImage(int a2, int a3, int a4) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !sub_2FA28C0() )
    return 0;
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
    return 0;
  ControlPtr->mainTexture = a4;
  ControlPtr->showTexture = -10;
  g_bGuiIsDirty = 1;
  HIBYTE(ControlPtr->unknownData[1]) = 1;
  return 1;
}


// address=[0x2fa1f10]
// Decompiled from char __thiscall IGuiEngine::LockOwnerImage(  IGuiEngine *this,  int a2,  int a3,  struct SGuiRect *a4,  unsigned __int16 **a5,  unsigned int *a6)
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
    return 0;
  if ( !(unsigned __int8)sub_2FA2880(a2) )
    return 0;
  v7 = (unsigned __int16 *)sub_2FA2900(a2);
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
    return 0;
  if ( ControlPtr->controlType != 9 )
    return 0;
  if ( dword_3E2F134 >= 0 )
    return 0;
  (**(void (__thiscall ***)(int, int *, _DWORD))g_pGfxManager)(g_pGfxManager, &v9, v7[5]);
  if ( v9 && v10 )
  {
    *a5 = IGfxEngine::BeginWriteToSurface((IGfxEngine *)g_pGfxEngine, *v7, a6);
    if ( *a5 )
    {
      dword_3E2F134 = *v7;
      FastBlit8Bit(
        (void *)(v9 + 12),
        v7[3],
        ControlPtr->x,
        ControlPtr->y,
        ControlPtr->width,
        ControlPtr->height,
        *a5,
        *a6,
        ControlPtr->x,
        ControlPtr->y,
        v10);
      *a5 += (*a6 >> 1) * ControlPtr->y;
      *a5 += ControlPtr->x;
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
// Decompiled from bool __thiscall IGuiEngine::UnlockOwnerImage(IGuiEngine *this, int a2, int a3)
bool  IGuiEngine::UnlockOwnerImage(int a2, int a3) {
  
  unsigned __int16 *v4; // [esp+4h] [ebp-8h]
  struct SGuiControl *ControlPtr; // [esp+8h] [ebp-4h]

  if ( !sub_2FA28C0() )
    return 0;
  if ( !(unsigned __int8)sub_2FA2880(a2) )
    return 0;
  v4 = (unsigned __int16 *)sub_2FA2900(a2);
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
    return 0;
  if ( ControlPtr->controlType != 9 )
    return 0;
  if ( dword_3E2F134 < 0 )
    return 0;
  dword_3E2F134 = -1;
  return IGfxEngine::EndWriteToSurface((IGfxEngine *)g_pGfxEngine, *v4);
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
    return 0;
  if ( !(unsigned __int8)sub_2FA2880(a2) )
    return 0;
  v6 = (unsigned __int16 *)sub_2FA2900(a2);
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
    return 0;
  if ( ControlPtr->controlType != 9 )
    return 0;
  if ( dword_3E2F134 >= 0 )
    return 0;
  (**(void (__thiscall ***)(int, int *, _DWORD))g_pGfxManager)(g_pGfxManager, &v8, v6[5]);
  if ( v8 && v9 )
  {
    v5 = IGfxEngine::BeginWriteToSurface((IGfxEngine *)g_pGfxEngine, *v6, &v4);
    if ( v5 )
    {
      FastBlit8Bit(
        (void *)(v8 + 12),
        v6[3],
        ControlPtr->x,
        ControlPtr->y,
        ControlPtr->width,
        ControlPtr->height,
        v5,
        v4,
        ControlPtr->x,
        ControlPtr->y,
        v9);
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
  
  WORD *p_width; // [esp+4h] [ebp-8h]
  struct SGuiControl *ControlPtr; // [esp+8h] [ebp-4h]

  if ( !sub_2FA28C0() )
    return 0;
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
    return 0;
  if ( a4 > 0x64 )
    return 0;
  if ( ControlPtr->controlType == 8
    && g_pCurrentDragControl
    && *(unsigned __int8 *)(g_pCurrentDragControl + 28) == LOBYTE(ControlPtr->unknown4) )
  {
    return 0;
  }
  if ( (ControlPtr->effects & 1) != 0 )
    ControlPtr->effects &= ~1u;
  if ( ControlPtr->controlType == 7
    && g_pCurrentDragControl
    && (struct SGuiControl *)g_pCurrentDragControl == ControlPtr )
  {
    return 0;
  }
  if ( (char)ControlPtr->showTexture == a4 )
    return 1;
  ControlPtr->showTexture = a4;
  g_bGuiIsDirty = 1;
  HIBYTE(ControlPtr->unknownData[1]) = 1;
  if ( ControlPtr->controlType != 7 && ControlPtr->controlType != 8 )
    return 1;
  p_width = &ControlPtr[-1].width;
  if ( LOBYTE(ControlPtr[-1].unknown4) != 16 )
  {
    BBSupportTracePrintF(0, "GUI ENGINE: No previous control GUI_CNTRL_SLIDERAREA of GUI_CNTRL_SLIDER!");
    return 0;
  }
  ControlPtr->x = CalcSliderPosition(
                    *p_width,
                    p_width[2] + *p_width - ControlPtr->width,
                    (char)ControlPtr->showTexture,
                    0);
  *((_BYTE *)p_width + 35) = 1;
  return 1;
}


// address=[0x2fa2510]
// Decompiled from int __thiscall IGuiEngine::GetSliderPosition(IGuiEngine *this, int a2, int a3)
int  IGuiEngine::GetSliderPosition(int a2, int a3) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !sub_2FA28C0() )
    return -1;
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
    return -1;
  if ( ControlPtr->controlType == 7 || ControlPtr->controlType == 8 )
    return (char)ControlPtr->showTexture;
  return -1;
}


// address=[0x2fa2580]
// Decompiled from char __thiscall IGuiEngine::SelectControl(IGuiEngine *this, int a2, int a3, bool a4)
bool  IGuiEngine::SelectControl(int a2, int a3, bool a4) {
  
  int SurfaceID; // eax
  int v6; // [esp-8h] [ebp-10h]
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !sub_2FA28C0() )
    return 0;
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
    return 0;
  if ( ((ControlPtr->effects & 1) == 0 || a4) && ((ControlPtr->effects & 1) != 0 || !a4) )
    return 1;
  if ( ControlPtr->controlType == 2 && a4 || ControlPtr->controlType == 3 )
  {
    SelectRadioGroup(ControlPtr);
  }
  else if ( ControlPtr->controlType == 1 )
  {
    SetControlState(ControlPtr, 1, a4);
  }
  else if ( (!ControlPtr->controlType || ControlPtr->controlType == 13) && a4 )
  {
    if ( g_pfDialogCallbacks[GetSurfaceID(ControlPtr)] )
    {
      v6 = (ControlPtr->effects << 16) + ControlPtr->valueLink;
      SurfaceID = GetSurfaceID(ControlPtr);
      ((void (__cdecl *)(int, int, _DWORD))g_pfDialogCallbacks[SurfaceID])(3, v6, 0);
    }
  }
  else if ( (ControlPtr->controlType == 5 || ControlPtr->controlType == 20) && a4 )
  {
    g_pCurrentEditControl = (int)ControlPtr;
    SelectEditControl(ControlPtr, &dword_ECC2A8[53078]);
  }
  return 1;
}


// address=[0x2fa2700]
// Decompiled from char __thiscall IGuiEngine::ResetRadioGroup(IGuiEngine *this, int a2, int a3)
bool  IGuiEngine::ResetRadioGroup(int a2, int a3) {
  
  int unknown4_low; // [esp+4h] [ebp-10h]
  int v5; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  struct SGuiControl *ControlPtr; // [esp+10h] [ebp-4h]
  int v8; // [esp+10h] [ebp-4h]

  if ( !sub_2FA28C0() )
    return 0;
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
    return 0;
  unknown4_low = LOBYTE(ControlPtr->unknown4);
  v5 = *(_DWORD *)(g_pFileHeader + 4 * ControlPtr->unknownId + 16) + g_pFileHeader;
  v8 = v5 + 16;
  for ( i = 0; i < *(unsigned __int16 *)(v5 + 12); ++i )
  {
    if ( (*(_BYTE *)(v8 + 27) & 1) != 0 && *(unsigned __int8 *)(v8 + 28) == unknown4_low )
      SetControlState((struct SGuiControl *)v8, 1, 0);
    v8 += 36;
  }
  return 1;
}


// address=[0x2fa27d0]
// Decompiled from char __thiscall IGuiEngine::SetWidth(IGuiEngine *this, int a2, int a3, WORD a4)
bool  IGuiEngine::SetWidth(int a2, int a3, int a4) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !sub_2FA28C0() )
    return 0;
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
    return 0;
  ControlPtr->width = a4;
  return 1;
}


// address=[0x2fa2820]
// Decompiled from char __thiscall IGuiEngine::SetPosition(IGuiEngine *this, int a2, int a3, WORD a4, WORD a5)
bool  IGuiEngine::SetPosition(int a2, int a3, int a4, int a5) {
  
  struct SGuiControl *ControlPtr; // [esp+4h] [ebp-4h]

  if ( !sub_2FA28C0() )
    return 0;
  ControlPtr = GetControlPtr(a2, a3);
  if ( !ControlPtr )
    return 0;
  ControlPtr->x = a4;
  ControlPtr->y = a5;
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
  for ( i = 0; i < 16; ++i )
  {
    g_uShadeTable1[i] = IGfxEngine::ConvertRgbToHicol(v8, v6, v4);
    v8 = (int)(float)((float)((float)((float)i * 0.079999998) + 1.0) * 150.0);
    v6 = (int)(float)((float)((float)((float)i * 0.079999998) + 1.0) * 4.0);
    v4 = (int)(float)((float)((float)((float)i * 0.079999998) + 1.0) * 12.0);
    if ( v8 > 255 )
      v8 = 255;
    if ( v6 > 255 )
      v6 = 255;
    if ( v4 > 255 )
      v4 = 255;
  }
  v9 = 10;
  v7 = 150;
  v5 = 3;
  for ( j = 0; j < 16; ++j )
  {
    g_uShadeTable2[j] = IGfxEngine::ConvertRgbToHicol(v9, v7, v5);
    v9 = (int)(float)((float)((float)((float)j * 0.079999998) + 1.0) * 10.0);
    v7 = (int)(float)((float)((float)((float)j * 0.079999998) + 1.0) * 150.0);
    v5 = (int)(float)((float)((float)((float)j * 0.079999998) + 1.0) * 3.0);
    if ( v9 > 255 )
      v9 = 255;
    if ( v7 > 255 )
      v7 = 255;
    if ( v5 > 255 )
      v5 = 255;
  }
  g_iLeftShadeColor = IGfxEngine::ConvertRgbToHicol(199, 178, 111);
  g_iRightShadeColor = IGfxEngine::ConvertRgbToHicol(50, 41, 45);
  result = IGfxEngine::ConvertRgbToHicol(50, 50, 50);
  g_iStdShadeColor = result;
  return result;
}


// address=[0x2fa0b80]
// Decompiled from struct tagRECT *__cdecl IGuiEngine::GetDialogDestinationRect(  struct tagRECT *retstr,  const struct GUI_MENU_DIALOG_HEADER *a2,  int a3,  int a4,  float a5,  float a6)
struct tagRECT __cdecl IGuiEngine::GetDialogDestinationRect(struct GUI_MENU_DIALOG_HEADER const & retstr, int a2, int a3, float a4, float a5) {
  
  LONG v7; // [esp+4h] [ebp-10h]
  LONG v8; // [esp+8h] [ebp-Ch]
  LONG v9; // [esp+Ch] [ebp-8h]

  v7 = a4 + *((unsigned __int16 *)a2 + 2);
  v8 = (int)(float)((float)((float)*((unsigned __int16 *)a2 + 3) * a5) + 0.5) + a3 + *((unsigned __int16 *)a2 + 1);
  v9 = (int)(float)((float)((float)*((unsigned __int16 *)a2 + 4) * a6) + 0.5) + v7;
  retstr->left = a3 + *((unsigned __int16 *)a2 + 1);
  retstr->top = v7;
  retstr->right = v8;
  retstr->bottom = v9;
  return retstr;
}


