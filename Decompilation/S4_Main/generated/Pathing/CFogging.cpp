#include "all_headers.h"

// Definitions for class CFogging

// address=[0x15d71d0]
// Decompiled from unsigned int __thiscall CFogging::Load(CFogging *this, struct IS4Chunk *a2)
void  CFogging::Load(class IS4Chunk &) {
  
  unsigned int result; // eax
  bool v3; // [esp+Ch] [ebp-38h]
  unsigned int v4; // [esp+10h] [ebp-34h]
  unsigned int v5; // [esp+14h] [ebp-30h] BYREF
  int v6; // [esp+18h] [ebp-2Ch]
  unsigned int j; // [esp+1Ch] [ebp-28h]
  _BYTE *v8; // [esp+20h] [ebp-24h]
  size_t Size; // [esp+24h] [ebp-20h]
  signed int i; // [esp+28h] [ebp-1Ch]
  CFogging *v11; // [esp+2Ch] [ebp-18h]
  _BYTE v12[16]; // [esp+30h] [ebp-14h] BYREF

  v11 = this;
  v6 = CWorldManager::Width(this);
  Size = v6 * v6;
  v8 = operator new[](v6 * v6);
  (**(void (__thiscall ***)(struct IS4Chunk *, _BYTE *, int))a2)(a2, v8, v6 * v6);
  for ( i = 0; i < (int)Size; ++i )
    *(_BYTE *)(*((_DWORD *)v11 + 2) + 4 * i + 3) |= v8[i];
  operator delete[](v8);
  std::list<SFogSpotInfo>::clear();
  *((_BYTE *)v11 + 76) = 0;
  *((_BYTE *)v11 + 77) = 0;
  *((_BYTE *)v11 + 78) = 0;
  result = (*(int (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 1856752389, 1856752391);
  v4 = result;
  if ( result >= 0x6EABCB06 )
  {
    v5 = 0;
    result = (**(int (__thiscall ***)(struct IS4Chunk *, unsigned int *, int))a2)(a2, &v5, 4);
    for ( j = 0; j < v5; ++j )
    {
      (**(void (__thiscall ***)(struct IS4Chunk *, _BYTE *, int))a2)(a2, v12, 16);
      std::list<SFogSpotInfo>::push_back(v12);
      result = j + 1;
    }
  }
  if ( v4 >= 0x6EABCB07 )
  {
    v3 = (*(int (__thiscall **)(struct IS4Chunk *, _DWORD, int))(*(_DWORD *)a2 + 4))(a2, 0, 1) != 0;
    *((_BYTE *)v11 + 76) = v3;
    *((_BYTE *)v11 + 77) = *((_BYTE *)v11 + 76);
    *((_BYTE *)v11 + 78) = 0;
    result = (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, 1856752639);
  }
  *((_BYTE *)v11 + 4) = 1;
  return result;
}


// address=[0x15d7390]
// Decompiled from int __thiscall CFogging::Save(CFogging *this, struct IS4Chunk *a2)
void  CFogging::Save(class IS4Chunk &) {
  
  _BYTE v3[12]; // [esp+4h] [ebp-74h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-68h] BYREF
  int v5; // [esp+1Ch] [ebp-5Ch]
  std::_Iterator_base12 *v6; // [esp+20h] [ebp-58h]
  std::_Iterator_base12 *v7; // [esp+24h] [ebp-54h]
  int v8; // [esp+28h] [ebp-50h]
  void *C; // [esp+2Ch] [ebp-4Ch]
  _BYTE *v10; // [esp+30h] [ebp-48h]
  _BYTE v11[12]; // [esp+34h] [ebp-44h] BYREF
  int v12; // [esp+40h] [ebp-38h]
  _BYTE *v13; // [esp+44h] [ebp-34h]
  size_t Size; // [esp+48h] [ebp-30h]
  CFogging *v15; // [esp+4Ch] [ebp-2Ch]
  signed int i; // [esp+50h] [ebp-28h]
  char v17; // [esp+57h] [ebp-21h]
  _DWORD v18[3]; // [esp+58h] [ebp-20h] BYREF
  char v19; // [esp+64h] [ebp-14h]
  int v20; // [esp+74h] [ebp-4h]

  v15 = this;
  v12 = CWorldManager::Width(this);
  Size = v12 * v12;
  v10 = operator new[](v12 * v12);
  v13 = v10;
  for ( i = 0; i < (int)Size; ++i )
    v13[i] = *(_BYTE *)(*((_DWORD *)v15 + 2) + 4 * i + 3) & 0x3F;
  (*(void (__thiscall **)(struct IS4Chunk *, _BYTE *, size_t))(*(_DWORD *)a2 + 16))(a2, v13, Size);
  C = v13;
  operator delete[](v13);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, 1856752391);
  v8 = std::list<SFogSpotInfo>::size((char *)v15 + 64);
  v5 = 16;
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, v8);
  std::list<SFogSpotInfo>::begin(v11);
  v20 = 0;
  while ( 1 )
  {
    v7 = (std::_Iterator_base12 *)std::list<SFogSpotInfo>::end(v4);
    v6 = v7;
    LOBYTE(v20) = 1;
    v17 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<SFogSpotInfo>>>::operator!=(v7);
    LOBYTE(v20) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<SFogSpotInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SFogSpotInfo>>>(v4);
    if ( !v17 )
      break;
    v18[0] = *(_DWORD *)std::_List_iterator<std::_List_val<std::_List_simple_types<SFogSpotInfo>>>::operator->(v11);
    v18[1] = *(_DWORD *)(std::_List_iterator<std::_List_val<std::_List_simple_types<SFogSpotInfo>>>::operator->(v11) + 4);
    v18[2] = *(_DWORD *)(std::_List_iterator<std::_List_val<std::_List_simple_types<SFogSpotInfo>>>::operator->(v11) + 8);
    v19 = *(_BYTE *)(std::_List_iterator<std::_List_val<std::_List_simple_types<SFogSpotInfo>>>::operator->(v11) + 12);
    (*(void (__thiscall **)(struct IS4Chunk *, _DWORD *, int))(*(_DWORD *)a2 + 16))(a2, v18, 16);
    std::_List_iterator<std::_List_val<std::_List_simple_types<SFogSpotInfo>>>::operator++(v3, 0);
    std::_List_iterator<std::_List_val<std::_List_simple_types<SFogSpotInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SFogSpotInfo>>>(v3);
  }
  v20 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<SFogSpotInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SFogSpotInfo>>>(v11);
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((unsigned __int8 *)v15 + 77));
  return (*(int (__cdecl **)(int))(*(_DWORD *)a2 + 24))(1856752639);
}


// address=[0x15d7590]
// Decompiled from void *__thiscall CFogging::Init(CFogging *this, struct T_GFX_MAP_ELEMENT *a2, unsigned __int8 *a3)
void  CFogging::Init(struct T_GFX_MAP_ELEMENT *,unsigned char *) {
  
  if ( !a2 && BBSupportDbgReport(2, "Pathing\\Fogging.cpp", 1277, "_pGfxMapElements != 0") == 1 )
    __debugbreak();
  if ( !a3 && BBSupportDbgReport(2, "Pathing\\Fogging.cpp", 1278, "_pFogLayer != 0") == 1 )
    __debugbreak();
  (*(void (__thiscall **)(CFogging *))(*(_DWORD *)this + 12))(this);
  *((_DWORD *)this + 2) = a2;
  *((_DWORD *)this + 3) = a3;
  if ( !*((_DWORD *)this + 10) )
    *((_DWORD *)this + 10) = operator new(8u);
  if ( !*((_DWORD *)this + 11) )
    *((_DWORD *)this + 11) = operator new(8u);
  if ( !*((_DWORD *)this + 10) && BBSupportDbgReport(2, "Pathing\\Fogging.cpp", 1295, "m_pRWM1 != 0") == 1 )
    __debugbreak();
  if ( !*((_DWORD *)this + 11) && BBSupportDbgReport(2, "Pathing\\Fogging.cpp", 1296, "m_pRWM2 != 0") == 1 )
    __debugbreak();
  memset(*((void **)this + 10), 0, 8u);
  return memset(*((void **)this + 11), 0, 8u);
}


// address=[0x15d76c0]
// Decompiled from CFogging *__thiscall CFogging::Done(CFogging *this)
void  CFogging::Done(void) {
  
  CFogging *result; // eax

  *((_BYTE *)this + 4) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  if ( *((_DWORD *)this + 10) )
  {
    operator delete(*((void **)this + 10));
    *((_DWORD *)this + 10) = 0;
  }
  if ( *((_DWORD *)this + 11) )
  {
    operator delete(*((void **)this + 11));
    *((_DWORD *)this + 11) = 0;
  }
  result = this;
  *((_BYTE *)this + 76) = 0;
  *((_BYTE *)this + 77) = 0;
  *((_BYTE *)this + 78) = 0;
  return result;
}


// address=[0x15d7770]
// Decompiled from int __thiscall CFogging::Start(CFogging *this)
void  CFogging::Start(void) {
  
  int v1; // edx
  int v2; // ecx
  int v4; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]

  v4 = CWorldManager::Width(this);
  if ( v4 != CWorldManager::Height(v2, v1)
    && BBSupportDbgReport(2, "Pathing\\Fogging.cpp", 1474, "iWidthHeight == g_cWorld.Height()") == 1 )
  {
    __debugbreak();
  }
  CFogging::ClearDynamicFoggingAndCalcStatic(this);
  CFogging::InitializeDynamicLayer(this, 0, v4);
  for ( i = 0; i < 32; ++i )
    CFogging::CalculateDynamicLayer(this, i);
  if ( !*((_BYTE *)this + 4) )
  {
    CFogging::SetWholeGfxLayerAndInitializeDynamicLayer(this);
    *((_BYTE *)this + 4) = 0;
  }
  if ( g_pGfxEngine )
    IGfxEngine::SetFoggingFadingStep((IGfxEngine *)g_pGfxEngine, 0);
  *((_DWORD *)this + 4) = 1;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 7) = 0;
  (*(void (__thiscall **)(CFogging *, _DWORD))(*(_DWORD *)this + 40))(this, 0);
  CFogging::UpdateRWM(this);
  *((_DWORD *)this + 12) = 0;
  return (*(int (__thiscall **)(CFogging *, _DWORD))(*(_DWORD *)this + 52))(this, 0);
}


// address=[0x15d7870]
// Decompiled from int __fastcall CFogging::Update(CFogging *this)
void  CFogging::Update(void) {
  
  int result; // eax
  _DWORD *v2; // eax
  int v3; // esi
  int v4; // edx
  int v5; // ecx
  int v6; // eax
  int v7; // [esp-8h] [ebp-88h]
  _BYTE v8[12]; // [esp+8h] [ebp-78h] BYREF
  _BYTE v9[12]; // [esp+14h] [ebp-6Ch] BYREF
  _BYTE v10[12]; // [esp+20h] [ebp-60h] BYREF
  int v11[2]; // [esp+2Ch] [ebp-54h] BYREF
  std::_Iterator_base12 *v12; // [esp+34h] [ebp-4Ch]
  int v13; // [esp+38h] [ebp-48h] BYREF
  int v14; // [esp+3Ch] [ebp-44h] BYREF
  int v15; // [esp+40h] [ebp-40h]
  unsigned int v16; // [esp+44h] [ebp-3Ch]
  int v17; // [esp+48h] [ebp-38h] BYREF
  __int64 v18; // [esp+4Ch] [ebp-34h]
  unsigned int v19; // [esp+54h] [ebp-2Ch]
  __int64 v20; // [esp+58h] [ebp-28h]
  __int64 v21; // [esp+60h] [ebp-20h]
  int v22; // [esp+68h] [ebp-18h]
  CFogging *v23; // [esp+6Ch] [ebp-14h]
  bool v24; // [esp+71h] [ebp-Fh]
  char v25; // [esp+72h] [ebp-Eh]
  bool v26; // [esp+73h] [ebp-Dh]
  int v27; // [esp+7Ch] [ebp-4h]

  v23 = this;
  result = (int)this;
  v22 = *((_DWORD *)this + 4);
  if ( v22 == 1 )
  {
    v26 = CFogging::RWMEx(v23);
    if ( !v26 || (HIDWORD(v21) = *((_DWORD *)v23 + 12) == 1, LODWORD(v21) = *((_DWORD *)v23 + 12) == 2, v21) )
    {
      if ( *((_DWORD *)v23 + 7) < 0xFu )
      {
        ++*((_DWORD *)v23 + 7);
        if ( g_pGfxEngine )
        {
          v15 = *((_DWORD *)v23 + 7);
          IGfxEngine::SetFoggingFadingStep((IGfxEngine *)g_pGfxEngine, v15);
        }
      }
    }
    if ( v26 )
    {
      HIDWORD(v20) = *((_DWORD *)v23 + 12) == 1;
      LODWORD(v20) = *((_DWORD *)v23 + 12) == 2;
      if ( v20 )
      {
        CFogging::CalcYRange(v23, *((_DWORD *)v23 + 5), 0x20u, &v13, &v14);
        CFogging::SetDynamicLayerToFullBright(v23, v13, v14);
      }
    }
    else
    {
      CFogging::CalculateDynamicLayer(v23, *((_DWORD *)v23 + 5));
    }
    v19 = *((_DWORD *)v23 + 5) + 1;
    *((_DWORD *)v23 + 5) = v19;
    if ( v19 >= 0x20 )
    {
      *((_DWORD *)v23 + 4) = 2;
      *((_DWORD *)v23 + 5) = 0;
      *((_DWORD *)v23 + 8) = 0x4000;
      *((_DWORD *)v23 + 9) = -1;
    }
    result = std::list<SFogSpotInfo>::empty((char *)v23 + 64);
    if ( !(_BYTE)result )
    {
      std::list<SFogSpotInfo>::begin(v10);
      v27 = 0;
      while ( 1 )
      {
        v12 = (std::_Iterator_base12 *)std::list<SFogSpotInfo>::end(v9);
        v11[1] = (int)v12;
        LOBYTE(v27) = 1;
        v25 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<SFogSpotInfo>>>::operator!=(v12);
        LOBYTE(v27) = 0;
        std::_List_iterator<std::_List_val<std::_List_simple_types<SFogSpotInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SFogSpotInfo>>>(v9);
        if ( !v25 )
          break;
        v7 = *(_DWORD *)(std::_List_iterator<std::_List_val<std::_List_simple_types<SFogSpotInfo>>>::operator->(v10) + 4);
        v2 = (_DWORD *)std::_List_iterator<std::_List_val<std::_List_simple_types<SFogSpotInfo>>>::operator->(v10);
        CFogging::UpdateEntityFogging(v23, *v2, v7, 35);
        std::_List_iterator<std::_List_val<std::_List_simple_types<SFogSpotInfo>>>::operator++(v8, 0);
        std::_List_iterator<std::_List_val<std::_List_simple_types<SFogSpotInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SFogSpotInfo>>>(v8);
      }
      v3 = std::list<SFogSpotInfo>::front();
      if ( *(_DWORD *)(v3 + 8) <= (unsigned int)CStateGame::GetTickCounter(g_pGame) )
        std::list<SFogSpotInfo>::pop_front();
      v27 = -1;
      return std::_List_iterator<std::_List_val<std::_List_simple_types<SFogSpotInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SFogSpotInfo>>>(v10);
    }
  }
  else if ( v22 == 2 )
  {
    v24 = CFogging::RWMEx(v23);
    if ( !v24 || (HIDWORD(v18) = *((_DWORD *)v23 + 12) == 1, LODWORD(v18) = *((_DWORD *)v23 + 12) == 2, v18) )
    {
      CFogging::CalcYRange(v23, *((_DWORD *)v23 + 5), 8u, v11, &v17);
      CFogging::UpdateGfxLayerAndInitializeDynamicLayer(v23, v11[0], v17);
      if ( g_pGfxEngine )
        IGfxEngine::SetFoggingUpdateMode((IGfxEngine *)g_pGfxEngine, v17);
    }
    v16 = *((_DWORD *)v23 + 5) + 1;
    result = v16;
    *((_DWORD *)v23 + 5) = v16;
    if ( v16 >= 8 )
    {
      if ( *((_BYTE *)v23 + 78) )
      {
        *((_BYTE *)v23 + 78) = 0;
        *((_BYTE *)v23 + 76) = *((_BYTE *)v23 + 77);
        CFogging::ClearDynamicFoggingAndCalcStatic(v23);
        v6 = CWorldManager::Height(v5, v4);
        CFogging::InitializeDynamicLayer(v23, 0, v6);
      }
      CFogging::UpdateLandExplorationState(v23);
      if ( g_pGfxEngine )
      {
        if ( *((int *)v23 + 9) < 0 )
        {
          if ( *((_DWORD *)v23 + 8) != 0x4000
            && BBSupportDbgReport(2, "Pathing\\Fogging.cpp", 1644, "m_iFoggingUpdateYFirst == 16384") == 1 )
          {
            __debugbreak();
          }
          IGfxEngine::SetFoggingRange((IGfxEngine *)g_pGfxEngine, 0, -1);
        }
        else
        {
          if ( *((_DWORD *)v23 + 8) > *((_DWORD *)v23 + 9)
            && BBSupportDbgReport(2, "Pathing\\Fogging.cpp", 1638, "m_iFoggingUpdateYFirst <= m_iFoggingUpdateYLast") == 1 )
          {
            __debugbreak();
          }
          IGfxEngine::SetFoggingRange((IGfxEngine *)g_pGfxEngine, *((_DWORD *)v23 + 8), *((_DWORD *)v23 + 9));
        }
      }
      *((_DWORD *)v23 + 4) = 1;
      *((_DWORD *)v23 + 5) = 0;
      *((_DWORD *)v23 + 7) = 0;
      CFogging::UpdateRWM(v23);
      result = CFogging::RWMEx(v23);
      if ( (_BYTE)result )
      {
        result = (int)v23;
        ++*((_DWORD *)v23 + 12);
      }
      else
      {
        *((_DWORD *)v23 + 12) = 0;
      }
    }
  }
  return result;
}


// address=[0x15d7ce0]
// Decompiled from char __thiscall CFogging::ResetGfxFogLayer(CFogging *this, bool a2)
void  CFogging::ResetGfxFogLayer(bool) {
  
  int v2; // edx
  int v3; // ecx
  char result; // al
  char v6; // [esp+8h] [ebp-10h]
  int v7; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]

  v7 = CWorldManager::Width(this);
  if ( v7 != CWorldManager::Height(v3, v2)
    && BBSupportDbgReport(2, "Pathing\\Fogging.cpp", 582, "iWidthHeight == g_cWorld.Height()") == 1 )
  {
    __debugbreak();
  }
  if ( a2 )
    v6 = 0;
  else
    v6 = 7;
  result = v6;
  for ( i = 0; i < v7 * v7; ++i )
  {
    *(_BYTE *)(*((_DWORD *)this + 2) + 4 * i + 3) = (8 * v6) | v6 | *(_BYTE *)(*((_DWORD *)this + 2) + 4 * i + 3) & 0xC0;
    result = i + 1;
  }
  return result;
}


// address=[0x15d7da0]
// Decompiled from void __thiscall CFogging::UpdateOwnerFogging(CFogging *this, int a2, int a3, int a4)
void  CFogging::UpdateOwnerFogging(int,int,int) {
  
  int v4; // [esp+0h] [ebp-48h]
  int v5; // [esp+4h] [ebp-44h]
  int v6; // [esp+8h] [ebp-40h]
  int v7; // [esp+14h] [ebp-34h]
  int v8; // [esp+18h] [ebp-30h]
  int v9; // [esp+1Ch] [ebp-2Ch]
  int LocalPlayerId; // [esp+20h] [ebp-28h]
  int v11; // [esp+24h] [ebp-24h]
  int v12; // [esp+28h] [ebp-20h]
  int i; // [esp+2Ch] [ebp-1Ch]
  int j; // [esp+30h] [ebp-18h]
  int v15; // [esp+34h] [ebp-14h]
  bool v17; // [esp+42h] [ebp-6h]

  if ( !CWorldManager::InInnerWorld2(a2, a3)
    && BBSupportDbgReport(2, "Pathing\\Fogging.cpp", 1679, "g_cWorld.InInnerWorld2(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( !g_pGfxEngine && BBSupportDbgReport(2, "Pathing\\Fogging.cpp", 1681, "g_pGfxEngine != 0") == 1 )
    __debugbreak();
  if ( !*((_DWORD *)this + 3) && BBSupportDbgReport(2, "Pathing\\Fogging.cpp", 1682, "m_pFogLayer != 0") == 1 )
    __debugbreak();
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(v4);
  if ( *((_BYTE *)this + 76) )
    v9 = CAlliances::PlayerBit(LocalPlayerId);
  else
    v9 = CAlliances::PlayerAllyBits(LocalPlayerId);
  v17 = (v9 & CAlliances::PlayerBit(a4)) != 0;
  v15 = CWorldManager::Index(a2, a3);
  if ( v17 )
  {
    if ( (*(_BYTE *)(*((_DWORD *)this + 3) + v15) & 7) != 0 )
    {
      *(_BYTE *)(*((_DWORD *)this + 3) + v15) &= 0x38u;
      CFogging::SmoothFullBrightStaticFog(this, a2, a3);
    }
  }
  else if ( (*(_BYTE *)(*((_DWORD *)this + 3) + v15) & 7u) < 3 )
  {
    *(_BYTE *)(*((_DWORD *)this + 3) + v15) = *(_BYTE *)(*((_DWORD *)this + 3) + v15) & 0x38 | 3;
    for ( i = 0; i < 19; ++i )
    {
      v8 = a2 + CSpiralOffsets::DeltaX(i);
      v7 = a3 + CSpiralOffsets::DeltaY(i);
      v11 = CWorldManager::Index(v8, v7);
      if ( (*(_BYTE *)(*((_DWORD *)this + 3) + v11) & 7) != 0 )
      {
        v12 = 3;
        for ( j = 1; j < 19; ++j )
        {
          v5 = v8 + CSpiralOffsets::DeltaX(j);
          v6 = v7 + CSpiralOffsets::DeltaY(j);
          if ( (*(_BYTE *)(*((_DWORD *)this + 3) + CWorldManager::Index(v5, v6)) & 7) == 0 )
          {
            v12 = CSpiralOffsets::Radius(j);
            break;
          }
        }
        if ( (v12 < 1 || v12 > 3)
          && BBSupportDbgReport(2, "Pathing\\Fogging.cpp", 1741, "(iNearest >= 1) && (iNearest <= 3)") == 1 )
        {
          __debugbreak();
        }
        *(_BYTE *)(*((_DWORD *)this + 3) + v11) = v12 | *(_BYTE *)(*((_DWORD *)this + 3) + v11) & 0x38;
      }
    }
  }
}


// address=[0x15d80d0]
// Decompiled from bool __thiscall CFogging::IsPositionVisible(CFogging *this, int a2, int a3)
bool  CFogging::IsPositionVisible(int,int)const {
  
  int v4; // [esp+0h] [ebp-24h]
  int NewFogging; // [esp+4h] [ebp-20h]
  int OldFogging; // [esp+8h] [ebp-1Ch]
  int v7; // [esp+Ch] [ebp-18h]
  int v8; // [esp+10h] [ebp-14h]
  int v9; // [esp+14h] [ebp-10h]
  int v10; // [esp+18h] [ebp-Ch]

  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3) )
    return 0;
  if ( !*((_DWORD *)this + 2) )
    return 0;
  v9 = CWorldManager::Index(a2, a3);
  OldFogging = T_GFX_MAP_ELEMENT::GetOldFogging((T_GFX_MAP_ELEMENT *)(*((_DWORD *)this + 2) + 4 * v9));
  NewFogging = T_GFX_MAP_ELEMENT::GetNewFogging((T_GFX_MAP_ELEMENT *)(*((_DWORD *)this + 2) + 4 * v9));
  v10 = 0;
  v8 = *((_DWORD *)this + 4);
  if ( v8 == 1 )
  {
    if ( *((_DWORD *)this + 7) >= 0xFu )
      v7 = NewFogging;
    else
      v7 = OldFogging;
    v10 = v7;
  }
  else if ( v8 == 2 )
  {
    if ( a3 > *((_DWORD *)this + 9) )
      v4 = NewFogging;
    else
      v4 = OldFogging;
    v10 = v4;
  }
  return v10 < 3;
}


// address=[0x15d81c0]
// Decompiled from bool __thiscall CFogging::RWM(CFogging *this)
bool  CFogging::RWM(void)const {
  
  return *((_DWORD *)this + 10) && (**((_DWORD **)this + 10) & 1) != 0;
}


// address=[0x15d8200]
// Decompiled from CFogging *__thiscall CFogging::SetRWM(CFogging **this, bool a2)
void  CFogging::SetRWM(bool) {
  
  CFogging *result; // eax
  int v3; // esi

  result = (CFogging *)this;
  if ( !this[10] )
    return result;
  v3 = CWorldManager::Width(this) << 8;
  *(_DWORD *)this[10] = 158619957 * a2 + 16 * CAlliances::NumberOfPlayers() + v3;
  result = this[10];
  *((_DWORD *)result + 1) = ((unsigned int)&unk_3954857 + (*(_DWORD *)result >> 2)) ^ 0x865F5F29;
  return result;
}


// address=[0x15d8260]
// Decompiled from CFogging *__thiscall CFogging::SetAlliesDontRevealFog(CFogging *this, bool a2)
void  CFogging::SetAlliesDontRevealFog(bool) {
  
  CFogging *result; // eax

  result = this;
  if ( *((_BYTE *)this + 77) == a2 )
    return result;
  result = this;
  *((_BYTE *)this + 77) = a2;
  *((_BYTE *)this + 78) = 1;
  return result;
}


// address=[0x15d8290]
// Decompiled from int __thiscall CFogging::ResetFogging(CFogging *this)
void  CFogging::ResetFogging(void) {
  
  *((_BYTE *)this + 4) = 0;
  *((_BYTE *)this + 76) = *((_BYTE *)this + 77);
  *((_BYTE *)this + 78) = 0;
  return (*(int (__thiscall **)(CFogging *, CFogging *))(*(_DWORD *)this + 16))(this, this);
}


// address=[0x15d82d0]
// Decompiled from CFogging *__thiscall CFogging::EnableOrDisableLandExploredCheck(CFogging *this, bool a2)
void  CFogging::EnableOrDisableLandExploredCheck(bool) {
  
  CFogging *result; // eax

  *((_BYTE *)this + 52) = a2;
  *((_DWORD *)this + 14) = 0;
  result = this;
  *((_DWORD *)this + 15) = 0;
  return result;
}


// address=[0x15d8300]
// Decompiled from bool __thiscall CFogging::IsAlmostAllLandExplored(CFogging *this)
bool  CFogging::IsAlmostAllLandExplored(void) {
  
  Squares *v3; // [esp+8h] [ebp-8h]

  v3 = (Squares *)CWorldManager::Width(this);
  return *((_DWORD *)this + 15) >= Squares::XYToVW(v3);
}


// address=[0x15d8350]
// Decompiled from char __thiscall CFogging::LiftFogAtSpot(CFogging *this, int a2, int a3, unsigned int a4, int a5)
void  CFogging::LiftFogAtSpot(int,int,unsigned int,int) {
  
  char result; // al
  int v7; // [esp+8h] [ebp-20h]
  int LocalPlayerId; // [esp+Ch] [ebp-1Ch]
  _DWORD v9[3]; // [esp+14h] [ebp-14h] BYREF
  char v10; // [esp+20h] [ebp-8h]

  v7 = CAlliances::PlayerBit(a5);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(this);
  result = (CAlliances::PlayerAllyBits(LocalPlayerId) & v7) != 0;
  if ( !result )
    return result;
  v9[2] = a4;
  v10 = a5;
  v9[0] = a2;
  v9[1] = a3;
  return std::list<SFogSpotInfo>::push_back(v9);
}


// address=[0x15d83e0]
// Decompiled from int __thiscall CFogging::DbgStaticFogValue(CFogging *this, int a2)
int  CFogging::DbgStaticFogValue(int)const {
  
  return *(_BYTE *)(*((_DWORD *)this + 3) + a2) & 7;
}


// address=[0x15d8400]
// Decompiled from int __thiscall CFogging::DbgDynamicFogValue(CFogging *this, int a2)
int  CFogging::DbgDynamicFogValue(int)const {
  
  return (*(_BYTE *)(*((_DWORD *)this + 3) + a2) & 0x38) >> 3;
}


// address=[0x15d8420]
// Decompiled from int __thiscall CFogging::DbgOldFogValue(CFogging *this, int a2)
int  CFogging::DbgOldFogValue(int)const {
  
  return T_GFX_MAP_ELEMENT::GetOldFogging((T_GFX_MAP_ELEMENT *)(*((_DWORD *)this + 2) + 4 * a2));
}


// address=[0x15d8440]
// Decompiled from int __thiscall CFogging::DbgNewFogValue(CFogging *this, int a2)
int  CFogging::DbgNewFogValue(int)const {
  
  return T_GFX_MAP_ELEMENT::GetNewFogging((T_GFX_MAP_ELEMENT *)(*((_DWORD *)this + 2) + 4 * a2));
}


// address=[0x15d8460]
// Decompiled from CFogging *__thiscall CFogging::CFogging(CFogging *this)
 CFogging::CFogging(void) {
  
  IFogging::IFogging(this);
  *(_DWORD *)this = CFogging::_vftable_;
  std::list<SFogSpotInfo>::list<SFogSpotInfo>((char *)this + 64);
  *((_BYTE *)this + 4) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_BYTE *)this + 52) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_BYTE *)this + 76) = 0;
  *((_BYTE *)this + 77) = 0;
  *((_BYTE *)this + 78) = 0;
  return this;
}


// address=[0x15dacc0]
// Decompiled from int __thiscall CFogging::~CFogging(CFogging *this)
 CFogging::~CFogging(void) {
  
  return std::list<SFogSpotInfo>::~list<SFogSpotInfo>(this);
}


// address=[0x15d8530]
// Decompiled from char *__thiscall CFogging::ClearDynamicFoggingAndCalcStatic(CFogging *this)
void  CFogging::ClearDynamicFoggingAndCalcStatic(void) {
  
  int v1; // edx
  int v2; // ecx
  char *result; // eax
  int v4; // [esp+0h] [ebp-9Ch]
  int v5; // [esp+10h] [ebp-8Ch]
  int v6; // [esp+18h] [ebp-84h]
  int v7; // [esp+28h] [ebp-74h]
  int v8; // [esp+2Ch] [ebp-70h]
  int v9; // [esp+38h] [ebp-64h]
  int v10; // [esp+3Ch] [ebp-60h]
  int v11; // [esp+40h] [ebp-5Ch]
  int v12; // [esp+48h] [ebp-54h]
  int v13; // [esp+4Ch] [ebp-50h]
  char *v14; // [esp+54h] [ebp-48h]
  int LocalPlayerId; // [esp+58h] [ebp-44h]
  int m; // [esp+5Ch] [ebp-40h]
  int k; // [esp+60h] [ebp-3Ch]
  int mm; // [esp+64h] [ebp-38h]
  int v19; // [esp+68h] [ebp-34h]
  int jj; // [esp+6Ch] [ebp-30h]
  int kk; // [esp+70h] [ebp-2Ch]
  Squares *n; // [esp+74h] [ebp-28h]
  Squares *ii; // [esp+78h] [ebp-24h]
  Squares *i; // [esp+7Ch] [ebp-20h]
  Squares *j; // [esp+80h] [ebp-1Ch]
  int nn; // [esp+84h] [ebp-18h]
  int v27; // [esp+88h] [ebp-14h]
  Squares *v28; // [esp+90h] [ebp-Ch]
  char v30; // [esp+9Ah] [ebp-2h]

  if ( !*((_DWORD *)this + 3) && BBSupportDbgReport(2, "Pathing\\Fogging.cpp", 1343, "m_pFogLayer != 0") == 1 )
    __debugbreak();
  v28 = (Squares *)CWorldManager::Width(0);
  v19 = Squares::XYToVW(v28);
  if ( v28 != (Squares *)CWorldManager::Height(v2, v1)
    && BBSupportDbgReport(2, "Pathing\\Fogging.cpp", 1353, "iWidthHeight == g_cWorld.Height()") == 1 )
  {
    __debugbreak();
  }
  memset(*((void **)this + 3), 7, (_DWORD)v28 * (_DWORD)v28);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(v4);
  if ( *((_BYTE *)this + 76) )
    v14 = (char *)CAlliances::PlayerBit(LocalPlayerId);
  else
    v14 = (char *)CAlliances::PlayerAllyBits(LocalPlayerId);
  result = v14;
  for ( i = 0; (int)i < v19; i = (Squares *)((char *)i + 1) )
  {
    for ( j = 0; (int)j < v19; j = (Squares *)((char *)j + 1) )
    {
      if ( ((unsigned int)v14 & COwnerMap::OwnerBits1VW(j, i)) != 0 )
      {
        v8 = Squares::VWToXY(j);
        v27 = v8 + (_DWORD)v28 * Squares::VWToXY(i);
        for ( k = 0; k < 16; ++k )
        {
          for ( m = 0; m < 16; ++m )
          {
            v7 = ITiling::OwnerId(v27);
            if ( ((unsigned int)v14 & CAlliances::PlayerBit(v7)) != 0 )
              *(_BYTE *)(*((_DWORD *)this + 3) + v27) = 0;
            ++v27;
          }
          v27 = (int)v28 + v27 - 16;
        }
      }
      result = (char *)j + 1;
    }
  }
  for ( n = 0; (int)n < v19; n = (Squares *)((char *)n + 1) )
  {
    for ( ii = 0; (int)ii < v19; ii = (Squares *)((char *)ii + 1) )
    {
      if ( COwnerMap::OwnerBits1VW(ii, n) )
      {
        v12 = Squares::VWToXY(ii);
        v13 = Squares::VWToXY(n);
        for ( jj = v13; jj < v13 + 16; ++jj )
        {
          for ( kk = v12; kk < v12 + 16; ++kk )
          {
            if ( !*(_BYTE *)(*((_DWORD *)this + 3) + kk + (_DWORD)v28 * jj) )
            {
              v30 = 0;
              for ( mm = 0; mm < 6; ++mm )
              {
                v11 = kk + (_DWORD)v28 * jj + CWorldManager::NeighborRelIndex(mm);
                if ( *(unsigned __int8 *)(*((_DWORD *)this + 3) + v11) > 1u )
                {
                  *(_BYTE *)(*((_DWORD *)this + 3) + v11) = 1;
                  v30 = 1;
                }
              }
              if ( v30 )
              {
                v6 = CSpiralOffsets::Last(6);
                for ( nn = 7; nn <= v6; ++nn )
                {
                  v5 = kk + CSpiralOffsets::DeltaX(nn);
                  v10 = v5 + (_DWORD)v28 * (jj + CSpiralOffsets::DeltaY(nn));
                  v9 = CSpiralOffsets::Radius(nn);
                  if ( *(unsigned __int8 *)(*((_DWORD *)this + 3) + v10) > v9 )
                    *(_BYTE *)(*((_DWORD *)this + 3) + v10) = v9;
                }
              }
            }
          }
        }
      }
    }
    result = (char *)n + 1;
  }
  return result;
}


// address=[0x15d8950]
// Decompiled from int __thiscall CFogging::UpdateEntityFogging(CFogging *this, int a2, int a3, int a4)
void  CFogging::UpdateEntityFogging(int,int,int) {
  
  int result; // eax
  int v5; // [esp+4h] [ebp-3Ch]
  int v6; // [esp+8h] [ebp-38h]
  int v7; // [esp+10h] [ebp-30h]
  int v8; // [esp+14h] [ebp-2Ch]
  int v9; // [esp+18h] [ebp-28h]
  int v10; // [esp+1Ch] [ebp-24h]
  int v11; // [esp+20h] [ebp-20h]
  int v12; // [esp+24h] [ebp-1Ch]
  int v13; // [esp+28h] [ebp-18h]
  int k; // [esp+30h] [ebp-10h]
  int j; // [esp+34h] [ebp-Ch]
  int i; // [esp+38h] [ebp-8h]
  char v18; // [esp+3Dh] [ebp-3h]
  char v19; // [esp+3Eh] [ebp-2h]
  unsigned __int8 v20; // [esp+3Fh] [ebp-1h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "Pathing\\Fogging.cpp", 694, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( a4 < 8 && BBSupportDbgReport(2, "Pathing\\Fogging.cpp", 695, "_iFogRadius >= 8") == 1 )
    __debugbreak();
  result = CSpiralOffsets::Last(a4);
  v7 = result;
  for ( i = 0; i <= v7; ++i )
  {
    v12 = a2 + CSpiralOffsets::DeltaX(i);
    v13 = a3 + CSpiralOffsets::DeltaY(i);
    if ( (unsigned __int8)CWorldManager::InWorld(v12, v13) )
    {
      v11 = CWorldManager::Index(v12, v13);
      v19 = *(_BYTE *)(*((_DWORD *)this + 3) + v11);
      if ( (v19 & 0x38) != 0 )
        *(_BYTE *)(*((_DWORD *)this + 3) + v11) = v19 & 0xC7;
    }
    result = i + 1;
  }
  v20 = 0;
  for ( j = a4 + 1; j <= a4 + 6; ++j )
  {
    v20 += 8;
    v6 = CSpiralOffsets::Last(j - 1);
    v5 = CSpiralOffsets::Last(j);
    for ( k = v6; k <= v5; ++k )
    {
      v9 = a2 + CSpiralOffsets::DeltaX(k);
      v10 = a3 + CSpiralOffsets::DeltaY(k);
      if ( (unsigned __int8)CWorldManager::InWorld(v9, v10) )
      {
        v8 = CWorldManager::Index(v9, v10);
        v18 = *(_BYTE *)(*((_DWORD *)this + 3) + v8);
        if ( v20 < (v18 & 0x38) )
          *(_BYTE *)(*((_DWORD *)this + 3) + v8) = v20 | v18 & 0xC7;
      }
    }
    result = j + 1;
  }
  return result;
}


// address=[0x15d8b70]
// Decompiled from unsigned int __thiscall CFogging::CalcYRange(  CFogging *this,  unsigned int a2,  unsigned int a3,  unsigned int *a4,  unsigned int *a5)
void  CFogging::CalcYRange(unsigned int,unsigned int,int &,int &) {
  
  unsigned int result; // eax
  unsigned int v6; // [esp+Ch] [ebp-8h]
  unsigned int v7; // [esp+10h] [ebp-4h]

  if ( !a3 && BBSupportDbgReport(2, "Pathing\\Fogging.cpp", 600, "_uNumberOfSteps > 0") == 1 )
    __debugbreak();
  v7 = CWorldManager::Width(this);
  v6 = v7 / a3 + v7 / a3 * a2;
  if ( v6 > v7 )
    v6 = v7;
  result = v7 / a3 * a2;
  *a4 = result;
  *a5 = v6;
  return result;
}


// address=[0x15d8bf0]
// Decompiled from int __thiscall CFogging::InitializeDynamicLayer(CFogging *this, int a2, int a3)
void  CFogging::InitializeDynamicLayer(int,int) {
  
  int result; // eax
  int v4; // [esp+0h] [ebp-14h]
  int v5; // [esp+4h] [ebp-10h]
  int i; // [esp+Ch] [ebp-8h]

  v5 = CWorldManager::Index(0, a2);
  v4 = CWorldManager::Index(0, a3);
  for ( i = v5; ; ++i )
  {
    result = i;
    if ( i >= v4 )
      break;
    *(_BYTE *)(*((_DWORD *)this + 3) + i) = *(_BYTE *)(*((_DWORD *)this + 3) + i) & 7 | (8
                                                                                       * *(_BYTE *)(*((_DWORD *)this + 3)
                                                                                                  + i));
  }
  return result;
}


// address=[0x15d8c90]
// Decompiled from int __thiscall CFogging::SetDynamicLayerToFullBright(CFogging *this, int a2, int a3)
void  CFogging::SetDynamicLayerToFullBright(int,int) {
  
  int result; // eax
  int v4; // [esp+0h] [ebp-14h]
  int v5; // [esp+4h] [ebp-10h]
  int i; // [esp+Ch] [ebp-8h]

  v5 = CWorldManager::Index(0, a2);
  result = CWorldManager::Index(0, a3);
  v4 = result;
  for ( i = v5; i < v4; ++i )
  {
    *(_BYTE *)(*((_DWORD *)this + 3) + i) &= 0xC7u;
    result = i + 1;
  }
  return result;
}


// address=[0x15d8d00]
// Decompiled from unsigned int __thiscall CFogging::CalculateDynamicLayer(CFogging *this, int a2)
void  CFogging::CalculateDynamicLayer(int) {
  
  unsigned int result; // eax
  int v3; // [esp+0h] [ebp-64h]
  int v4; // [esp+10h] [ebp-54h]
  int v5; // [esp+1Ch] [ebp-48h]
  int v6; // [esp+20h] [ebp-44h]
  int v7; // [esp+24h] [ebp-40h]
  int v8; // [esp+28h] [ebp-3Ch]
  int v9; // [esp+2Ch] [ebp-38h]
  int v10; // [esp+30h] [ebp-34h]
  int v11; // [esp+34h] [ebp-30h]
  int LocalPlayerId; // [esp+38h] [ebp-2Ch]
  int v13; // [esp+3Ch] [ebp-28h]
  unsigned int UsedId; // [esp+40h] [ebp-24h]
  unsigned int v15; // [esp+44h] [ebp-20h]
  unsigned int i; // [esp+50h] [ebp-14h]
  int v18; // [esp+58h] [ebp-Ch]
  void **v19; // [esp+5Ch] [ebp-8h]

  if ( a2 < 0 && BBSupportDbgReport(2, "Pathing\\Fogging.cpp", 763, "_iStep >= 0") == 1 )
    __debugbreak();
  if ( a2 <= 0 )
    *((_DWORD *)this + 6) = 0;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId(v3);
  if ( *((_BYTE *)this + 76) )
    v11 = CAlliances::PlayerBit(LocalPlayerId);
  else
    v11 = CAlliances::PlayerAllyBits(LocalPlayerId);
  UsedId = CMapObjectMgr::LastUsedId();
  result = (a2 + 1) * ((UsedId + 31) >> 5);
  v15 = result;
  if ( result > UsedId )
  {
    result = UsedId;
    v15 = UsedId;
  }
  for ( i = *((_DWORD *)this + 6); i <= v15; ++i )
  {
    v19 = (void **)CMapObjectMgr::EntityPtr(i);
    if ( v19 )
    {
      if ( IEntity::ObjType((unsigned __int8 *)v19) == 8
        && (IEntity::Type((unsigned __int16 *)v19) == 50 || IEntity::Type((unsigned __int16 *)v19) == 51) )
      {
        if ( IEntity::FlagBits(v19, (EntityFlag)0x200000u) )
        {
          v6 = IEntity::X(v19);
          v7 = IEntity::Y(v19);
          CFogging::UpdateEntityFogging(this, v6, v7, 25);
        }
      }
      else
      {
        v5 = IEntity::OwnerId((unsigned __int8 *)v19);
        if ( (v11 & CAlliances::PlayerBit(v5)) != 0 )
        {
          v13 = IEntity::Flags(v19);
          if ( (((unsigned int)&loc_1FFFFFF + 1) & v13) != 0 )
          {
            v18 = 0;
            v4 = IEntity::ObjType((unsigned __int8 *)v19);
            v10 = IEntity::Type((unsigned __int16 *)v19);
            switch ( v4 )
            {
              case 1:
                if ( (v13 & 0xF) != 0 && (v13 & 0x8000) == 0 )
                {
                  if ( v10 == 48 )
                    v18 = 25;
                  else
                    v18 = 15;
                }
                break;
              case 2:
                v18 = 25;
                break;
              case 4:
                v18 = 20;
                break;
              case 8:
                switch ( v10 )
                {
                  case 31:
                  case 32:
                    v18 = 20;
                    break;
                  case 45:
                    v18 = 45;
                    break;
                  case 46:
                    if ( !j____RTDynamicCast(
                            v19,
                            0,
                            &IEntity__RTTI_Type_Descriptor_,
                            &CBuilding__RTTI_Type_Descriptor_,
                            0)
                      && BBSupportDbgReport(
                           2,
                           "Pathing\\Fogging.cpp",
                           868,
                           "dynamic_cast<const CBuilding*>(pEntity) != 0") == 1 )
                    {
                      __debugbreak();
                    }
                    if ( (unsigned __int8)CBuilding::HaveInhabitant() )
                      v18 = 35;
                    break;
                  case 47:
                    if ( !j____RTDynamicCast(
                            v19,
                            0,
                            &IEntity__RTTI_Type_Descriptor_,
                            &CBuilding__RTTI_Type_Descriptor_,
                            0)
                      && BBSupportDbgReport(
                           2,
                           "Pathing\\Fogging.cpp",
                           882,
                           "dynamic_cast<const CBuilding*>(pEntity) != 0") == 1 )
                    {
                      __debugbreak();
                    }
                    if ( (unsigned __int8)CBuilding::HaveInhabitant() )
                      v18 = 40;
                    break;
                  case 48:
                    if ( !j____RTDynamicCast(
                            v19,
                            0,
                            &IEntity__RTTI_Type_Descriptor_,
                            &CBuilding__RTTI_Type_Descriptor_,
                            0)
                      && BBSupportDbgReport(
                           2,
                           "Pathing\\Fogging.cpp",
                           896,
                           "dynamic_cast<const CBuilding*>(pEntity) != 0") == 1 )
                    {
                      __debugbreak();
                    }
                    if ( (unsigned __int8)CBuilding::HaveInhabitant() )
                      v18 = 45;
                    break;
                  default:
                    goto CFogging__CalculateDynamicLayer___def_19D8EDA;
                }
                break;
              default:
                break;
            }
CFogging__CalculateDynamicLayer___def_19D8EDA:
            if ( v18 > 0 )
            {
              v8 = IEntity::X(v19);
              v9 = IEntity::Y(v19);
              if ( v8 >= 2 && v9 >= 2 )
                CFogging::UpdateEntityFogging(this, v8, v9, v18);
            }
          }
        }
      }
    }
    result = i + 1;
  }
  *((_DWORD *)this + 6) = v15 + 1;
  return result;
}


// address=[0x15d9120]
// Decompiled from signed int __thiscall CFogging::UpdateGfxLayerAndInitializeDynamicLayer(CFogging *this, int a2, unsigned int a3)
void  CFogging::UpdateGfxLayerAndInitializeDynamicLayer(int,int) {
  
  int v3; // ecx
  __m64 *v4; // esi
  _BYTE *v5; // edi
  __m64 v6; // mm6
  __m64 v7; // mm7
  int v8; // ecx
  __m64 v9; // mm5
  __m64 v10; // mm2
  __m64 v11; // mm3
  __m64 v12; // mm0
  __m64 v13; // mm2
  __m64 v14; // mm3
  __m64 v15; // mm1
  __m64 v16; // mm3
  unsigned __int16 v17; // ax
  unsigned __int16 v18; // bx
  __m64 v19; // mm1
  __m64 v20; // mm2
  __m64 v21; // mm1
  __m64 v22; // mm3
  __m64 v23; // mm0
  __m64 v24; // mm0
  unsigned int v25; // eax
  unsigned int v26; // eax
  signed int result; // eax
  int v28; // [esp+18h] [ebp-20h]
  int v29; // [esp+1Ch] [ebp-1Ch]
  __m64 *v30; // [esp+20h] [ebp-18h]
  unsigned int v31; // [esp+24h] [ebp-14h]
  int v32; // [esp+28h] [ebp-10h]
  int v33; // [esp+2Ch] [ebp-Ch]
  signed int v34; // [esp+30h] [ebp-8h]

  v32 = CWorldManager::Index(0, a2);
  CWorldManager::Index(0, a3);
  v28 = CWorldManager::Width(v3) >> 3;
  v30 = (__m64 *)(v32 + *((_DWORD *)this + 3));
  v29 = *((_DWORD *)this + 2) + 4 * v32;
  v34 = *((_DWORD *)this + 8);
  v33 = *((_DWORD *)this + 9);
  if ( v33 >= a2 && BBSupportDbgReport(2, "Pathing\\Fogging.cpp", 1031, "iChangeYLast < _iYMin") == 1 )
    __debugbreak();
  v31 = a2;
  __asm { pushaw }
  v4 = v30;
  v5 = (_BYTE *)v29;
  v6 = qword_37D8468[3];
  v7 = qword_37D8468[4];
  do
  {
    v8 = v28;
    v9.m64_u64 = -1LL;
    do
    {
      v10 = _m_pand((__m64)v4->m64_u64, qword_37D8468[2]);
      v11 = _m_psllqi(v10, 3u);
      v12 = _m_pand((__m64)v4->m64_u64, v6);
      v13 = _m_por(v10, v11);
      v14 = _m_pcmpeqb(v11, v12);
      v15 = _m_pand(_m_paddusb(_m_pand((__m64)v4->m64_u64, v14), _m_pand(v14, qword_37D8468[0])), v7);
      v16 = _m_pcmpeqb(v7, v15);
      v4->m64_u64 = (unsigned __int64)_m_por(v15, v13);
      if ( (_mm_cvtsi64_si32(_m_psrlqi(v16, 0x20u)) & _mm_cvtsi64_si32(v16)) != 0xFFFFFFFF )
      {
        LOBYTE(v17) = v5[3];
        HIBYTE(v17) = v5[7];
        LOBYTE(v18) = v5[11];
        HIBYTE(v18) = v5[15];
        v19 = _mm_cvtsi32_si64((v18 << 16) | (unsigned int)v17);
        LOBYTE(v17) = v5[19];
        HIBYTE(v17) = v5[23];
        LOBYTE(v18) = v5[27];
        HIBYTE(v18) = v5[31];
        v20 = _m_por(v19, _m_psllqi(_mm_cvtsi32_si64((v18 << 16) | (unsigned int)v17), 0x20u));
        v21 = _m_pand(v20, v6);
        v22 = _m_por(qword_37D8468[1], _m_pand(_m_pcmpeqb(v21, v6), v6));
        v23 = _m_psubb(v12, _m_psubusb(v12, _m_paddb(v22, _m_psubusb(v21, v22))));
        v9 = _m_pand(v9, _m_pcmpeqb(v23, v21));
        v24 = _m_por(_m_por(v23, _m_pand(v20, v7)), _m_psrlqi(v21, 3u));
        v25 = _mm_cvtsi64_si32(v24);
        v5[3] = v25;
        v5[7] = BYTE1(v25);
        v25 >>= 16;
        v5[11] = v25;
        v5[15] = BYTE1(v25);
        v26 = _mm_cvtsi64_si32(_m_psrlqi(v24, 0x20u));
        v5[19] = v26;
        v5[23] = BYTE1(v26);
        v26 >>= 16;
        v5[27] = v26;
        v5[31] = BYTE1(v26);
      }
      ++v4;
      v5 += 32;
      --v8;
    }
    while ( v8 );
    if ( (_mm_cvtsi64_si32(_m_psrlqi(v9, 0x20u)) & _mm_cvtsi64_si32(v9)) != 0xFFFFFFFF )
    {
      if ( (int)v31 < v34 )
        v34 = v31;
      v33 = v31;
    }
    ++v31;
  }
  while ( v31 < a3 );
  _m_empty();
  __asm { popaw }
  result = v34;
  *((_DWORD *)this + 8) = v34;
  *((_DWORD *)this + 9) = v33;
  return result;
}


// address=[0x15d93d0]
// Decompiled from int __thiscall CFogging::SetWholeGfxLayerAndInitializeDynamicLayer(CFogging *this)
void  CFogging::SetWholeGfxLayerAndInitializeDynamicLayer(void) {
  
  int v1; // esi
  int v2; // edx
  int v3; // ecx
  int result; // eax
  int v5; // [esp+4h] [ebp-10h]
  int i; // [esp+Ch] [ebp-8h]
  char v8; // [esp+13h] [ebp-1h]

  v1 = CWorldManager::Width(0);
  result = CWorldManager::Height(v3, v2);
  v5 = result * v1;
  for ( i = 0; i < v5; ++i )
  {
    v8 = *(_BYTE *)(*((_DWORD *)this + 3) + i);
    *(_BYTE *)(*((_DWORD *)this + 3) + i) = v8 & 7 | (8 * v8);
    *(_BYTE *)(*((_DWORD *)this + 2) + 4 * i + 3) = ((v8 & 0x38) >> 3) | v8 & 0x38 | *(_BYTE *)(*((_DWORD *)this + 2)
                                                                                              + 4 * i
                                                                                              + 3) & 0xC0;
    result = i + 1;
  }
  return result;
}


// address=[0x15d9490]
// Decompiled from int __thiscall CFogging::SmoothFullBrightStaticFog(CFogging *this, int a2, int a3)
void  CFogging::SmoothFullBrightStaticFog(int,int) {
  
  int result; // eax
  int v4; // [esp+0h] [ebp-24h]
  int v5; // [esp+4h] [ebp-20h]
  int v6; // [esp+Ch] [ebp-18h]
  int v7; // [esp+10h] [ebp-14h]
  int v9; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  char v11; // [esp+23h] [ebp-1h]

  v5 = CWorldManager::Width(this);
  result = CSpiralOffsets::Last(6);
  v6 = result;
  for ( i = 1; i <= v6; ++i )
  {
    v4 = a2 + CSpiralOffsets::DeltaX(i);
    v7 = v4 + v5 * (a3 + CSpiralOffsets::DeltaY(i));
    v9 = CSpiralOffsets::Radius(i);
    v11 = *(_BYTE *)(*((_DWORD *)this + 3) + v7);
    if ( (v11 & 7) > v9 )
      *(_BYTE *)(*((_DWORD *)this + 3) + v7) = v9 | v11 & 0x38;
    result = i + 1;
  }
  return result;
}


// address=[0x15d9550]
// Decompiled from CFogging *__fastcall CFogging::UpdateLandExplorationState(CFogging *this)
void  CFogging::UpdateLandExplorationState(void) {
  
  CFogging *result; // eax
  int v2; // ecx
  Squares *v3; // [esp+0h] [ebp-10h]
  int v4; // [esp+4h] [ebp-Ch]
  int v5; // [esp+8h] [ebp-8h]

  result = this;
  v2 = *((unsigned __int8 *)this + 52);
  if ( !v2 )
    return result;
  v3 = (Squares *)CWorldManager::Width(v2);
  v4 = Squares::XYToVW(v3);
  while ( 1 )
  {
    result = this;
    if ( *((_DWORD *)this + 15) >= v4 )
      break;
    result = (CFogging *)CFogging::IsSquareLandExploredVW(this, *((_DWORD *)this + 14), *((_DWORD *)this + 15));
    if ( !(_BYTE)result )
      break;
    v5 = *((_DWORD *)this + 14) + 1;
    *((_DWORD *)this + 14) = v5;
    if ( v5 >= v4 )
    {
      *((_DWORD *)this + 14) = 0;
      ++*((_DWORD *)this + 15);
    }
  }
  return result;
}


// address=[0x15d95f0]
// Decompiled from char __thiscall CFogging::IsSquareLandExploredVW(CFogging *this, Squares *a2, Squares *a3)
bool  CFogging::IsSquareLandExploredVW(int,int) {
  
  int v3; // ecx
  int v4; // eax
  int v6; // [esp-4h] [ebp-60h]
  int v7; // [esp+0h] [ebp-5Ch]
  char v9; // [esp+Ch] [ebp-50h]
  char v10; // [esp+10h] [ebp-4Ch]
  int v11; // [esp+14h] [ebp-48h]
  int v12; // [esp+18h] [ebp-44h]
  int v13; // [esp+1Ch] [ebp-40h]
  int v14; // [esp+20h] [ebp-3Ch] BYREF
  int v15; // [esp+24h] [ebp-38h] BYREF
  char *v16; // [esp+28h] [ebp-34h] BYREF
  int v17; // [esp+2Ch] [ebp-30h] BYREF
  char *v18; // [esp+30h] [ebp-2Ch] BYREF
  int v19; // [esp+34h] [ebp-28h] BYREF
  Squares *v20; // [esp+38h] [ebp-24h]
  int v21; // [esp+3Ch] [ebp-20h]
  int v22; // [esp+40h] [ebp-1Ch]
  int v23; // [esp+44h] [ebp-18h]
  int v24; // [esp+48h] [ebp-14h]
  int v25; // [esp+4Ch] [ebp-10h]
  int v26; // [esp+50h] [ebp-Ch]
  int j; // [esp+54h] [ebp-8h]
  int i; // [esp+58h] [ebp-4h]

  if ( !Squares::ValidVW(a2, (unsigned int)a3)
    && BBSupportDbgReport(2, "Pathing\\Fogging.cpp", 521, "Squares::ValidVW(_iV, _iW)") == 1 )
  {
    __debugbreak();
  }
  v20 = (Squares *)CWorldManager::Width(v3);
  v24 = Squares::XYToVW(v20);
  v19 = v24 - (_DWORD)a3;
  v18 = (char *)a3 + 1;
  v17 = v24 - (_DWORD)a2;
  v16 = (char *)a2 + 1;
  v6 = BB::Min<int>(&v18, &v19);
  v4 = BB::Min<int>(&v16, &v17);
  v23 = *(_DWORD *)BB::Min<int>(v4, v6);
  if ( v23 <= 2 )
    return 1;
  v15 = 176 - 16 * v23;
  v14 = 80;
  v7 = *(_DWORD *)BB::Min<int>(&v14, &v15);
  v21 = Squares::VWToXY(a2);
  v22 = Squares::VWToXY(a3);
  v12 = v21 + 16;
  v13 = v22 + 16;
  v25 = 0;
  for ( i = v22; i < v13; ++i )
  {
    v11 = CWorldManager::Index(0, i);
    for ( j = v21; j < v12; ++j )
    {
      v26 = j + v11;
      v10 = CWorldManager::Ground(j + v11);
      v9 = CWorldManager::Flags(v26);
      if ( ((v10 & 0xF0) == 0x10 || (v9 & 1) == 0)
        && T_GFX_MAP_ELEMENT::GetNewFogging((T_GFX_MAP_ELEMENT *)(*((_DWORD *)this + 2) + 4 * v26)) > 3
        && ++v25 >= v7 )
      {
        return 0;
      }
    }
  }
  return 1;
}


// address=[0x15db200]
// Decompiled from bool __thiscall CFogging::RWMEx(CFogging *this)
bool  CFogging::RWMEx(void) {
  
  int v1; // esi
  int v3; // [esp+8h] [ebp-20h]
  BOOL v4; // [esp+14h] [ebp-14h]
  unsigned int v5; // [esp+1Ch] [ebp-Ch]

  if ( !*((_DWORD *)this + 11) )
    return 0;
  v5 = **((_DWORD **)this + 11) ^ 0x90909090;
  v3 = *(_DWORD *)(*((_DWORD *)this + 11) + 4) - 168430090;
  v1 = CWorldManager::Width(this) << 8;
  v4 = v5 == v1 + 16 * CAlliances::NumberOfPlayers() + 158619957;
  return (unsigned __int8)(v3 == ((60115031 * v4 + (v5 >> 2)) ^ 0x865F5F29)) <= 1u && v4;
}


// address=[0x15db310]
// Decompiled from CFogging *__thiscall CFogging::UpdateRWM(CFogging **this)
void  CFogging::UpdateRWM(void) {
  
  CFogging *result; // eax

  result = (CFogging *)this;
  if ( this[11] == 0 || this[10] == 0 )
    return result;
  *(_DWORD *)this[11] = *(_DWORD *)this[10] ^ 0x90909090;
  result = this[11];
  *((_DWORD *)result + 1) = *((_DWORD *)this[10] + 1) + 168430090;
  return result;
}


