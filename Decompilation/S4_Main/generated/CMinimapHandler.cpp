#include "all_headers.h"

// Definitions for class CMinimapHandler

// address=[0x15b1490]
// Decompiled from int __cdecl CMinimapHandler::FilterKeyPressed(int a1)
static void __cdecl CMinimapHandler::FilterKeyPressed(int) {
  
  int result; // eax
  int v2; // [esp+0h] [ebp-Ch]
  int v3; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < 11; ++i )
  {
    v2 = CMinimapHandler::m_iObjectType[i];
    v3 = CMinimapHandler::m_iObjectGroups[v2];
    if ( v3 != 5 )
      CMinimapHandler::m_iGroupEnabled[v3] = (CMinimapHandler::m_iObjectBitMask[v2] & a1) != 0;
    result = i + 1;
  }
  return result;
}


// address=[0x15b1510]
// Decompiled from int CMinimapHandler::Init()
static void __cdecl CMinimapHandler::Init(void) {
  
  int result; // eax
  int v1; // eax
  int i; // [esp+0h] [ebp-4h]
  int j; // [esp+0h] [ebp-4h]
  int k; // [esp+0h] [ebp-4h]

  memset(CMinimapHandler::m_iGroupEnabled, 0, sizeof(CMinimapHandler::m_iGroupEnabled));
  memset(CMinimapHandler::m_sObjectColor, 255, 0x48u);
  memset(CMinimapHandler::m_iObjectBitMask, 0, sizeof(CMinimapHandler::m_iObjectBitMask));
  for ( i = 0; i < 132; ++i )
    CMinimapHandler::m_iObjectGroups[i] = 5;
  CMinimapHandler::m_iObjectGroups[8] = 0;
  CMinimapHandler::m_iObjectGroups[10] = 0;
  CMinimapHandler::m_iObjectGroups[22] = 1;
  CMinimapHandler::m_iObjectGroups[2] = 1;
  CMinimapHandler::m_iObjectGroups[4] = 1;
  CMinimapHandler::m_iObjectGroups[1] = 2;
  CMinimapHandler::m_iObjectGroups[127] = 3;
  CMinimapHandler::m_iObjectBitMask[8] = 1;
  CMinimapHandler::m_iObjectBitMask[10] = 1;
  CMinimapHandler::m_iObjectBitMask[22] = 2;
  CMinimapHandler::m_iObjectBitMask[2] = 2;
  CMinimapHandler::m_iObjectBitMask[4] = 2;
  CMinimapHandler::m_iObjectBitMask[1] = 4;
  CMinimapHandler::m_iObjectBitMask[127] = 8;
  for ( j = 0; j < 4; ++j )
  {
    CMinimapHandler::m_sObjectColor[3 * j] = *(_DWORD *)TStaticConfigIntArrayBase<4>::operator[](j);
    dword_415AB0C[3 * j] = *(_DWORD *)TStaticConfigIntArrayBase<4>::operator[](j);
    dword_415AB10[3 * j] = *(_DWORD *)TStaticConfigIntArrayBase<4>::operator[](j);
  }
  CMinimapHandler::UpdateAlliances();
  for ( k = 1; ; ++k )
  {
    result = CPlayerManager::LastPlayerId();
    if ( k > result )
      break;
    v1 = CPlayerManager::Color(k);
    IGfxEngine::GetPlayerColor(
      (IGfxEngine *)g_pGfxEngine,
      v1,
      (struct SGfxColor *)((char *)&CMinimapHandler::m_sOwnerColor + 12 * k));
  }
  return result;
}


// address=[0x15b1730]
// Decompiled from _DWORD *CMinimapHandler::UpdateAlliances()
static void __cdecl CMinimapHandler::UpdateAlliances(void) {
  
  _DWORD *result; // eax
  _DWORD *v1; // ecx
  _DWORD *v2; // ecx
  int v3; // [esp+0h] [ebp-10h]
  int v4; // [esp+0h] [ebp-10h]
  _DWORD *v5; // [esp+4h] [ebp-Ch]
  int LocalPlayerId; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  LocalPlayerId = CPlayerManager::GetLocalPlayerId(v3);
  v4 = CAlliances::AllianceId(LocalPlayerId);
  result = (_DWORD *)CPlayerManager::LastPlayerId();
  v5 = result;
  for ( i = 1; i <= (int)v5; ++i )
  {
    if ( i == LocalPlayerId )
    {
      v1 = (_DWORD *)((char *)&CMinimapHandler::m_sOwnerColorAlly + 12 * i - 12);
      *v1 = CMinimapHandler::m_sObjectColor[0];
      result = (_DWORD *)CMinimapHandler::m_sObjectColor[1];
      v1[1] = result;
      v1[2] = CMinimapHandler::m_sObjectColor[2];
    }
    else if ( CAlliances::AllianceId(i) == v4 )
    {
      result = (_DWORD *)((char *)&CMinimapHandler::m_sOwnerColorAlly + 12 * i - 12);
      *result = CMinimapHandler::m_sObjectColor[3];
      result[1] = CMinimapHandler::m_sObjectColor[4];
      result[2] = CMinimapHandler::m_sObjectColor[5];
    }
    else
    {
      v2 = (_DWORD *)((char *)&CMinimapHandler::m_sOwnerColorAlly + 12 * i - 12);
      *v2 = CMinimapHandler::m_sObjectColor[6];
      result = (_DWORD *)CMinimapHandler::m_sObjectColor[7];
      v2[1] = result;
      v2[2] = CMinimapHandler::m_sObjectColor[8];
    }
  }
  return result;
}


// address=[0x16a6ef0]
// Decompiled from int __cdecl CMinimapHandler::GetEcoSectorColor(int a1, struct SGfxColor *a2)
static void __cdecl CMinimapHandler::GetEcoSectorColor(int,struct SGfxColor &) {
  
  _DWORD *v2; // eax
  int result; // eax

  v2 = (_DWORD *)((char *)&CMinimapHandler::m_sOwnerColor + 12 * a1);
  *(_DWORD *)a2 = *v2;
  *((_DWORD *)a2 + 1) = v2[1];
  result = v2[2];
  *((_DWORD *)a2 + 2) = result;
  return result;
}


// address=[0x16a6f20]
// Decompiled from char __cdecl CMinimapHandler::GetObjectColor(int a1, struct SGfxColor *a2, int a3, int a4)
static bool __cdecl CMinimapHandler::GetObjectColor(int,struct SGfxColor &,int,int) {
  
  _DWORD *v5; // eax
  int v6; // [esp+4h] [ebp-4h]

  if ( a3 && a1 == 1 )
    a1 = 22;
  v6 = CMinimapHandler::m_iObjectGroups[a1];
  if ( !CMinimapHandler::m_iGroupEnabled[v6] )
    return 0;
  if ( v6 == 1 )
  {
    v5 = (_DWORD *)((char *)&CMinimapHandler::m_sOwnerColorAlly + 12 * a4 - 12);
    *(_DWORD *)a2 = *v5;
    *((_DWORD *)a2 + 1) = v5[1];
    *((_DWORD *)a2 + 2) = v5[2];
  }
  else
  {
    *(_DWORD *)a2 = CMinimapHandler::m_sObjectColor[9];
    *((_DWORD *)a2 + 1) = CMinimapHandler::m_sObjectColor[10];
    *((_DWORD *)a2 + 2) = CMinimapHandler::m_sObjectColor[11];
  }
  return 1;
}


// address=[0x16a71c0]
// Decompiled from bool CMinimapHandler::IsEcoSectorEnabled()
static bool __cdecl CMinimapHandler::IsEcoSectorEnabled(void) {
  
  return CMinimapHandler::m_iGroupEnabled[3] != 0;
}


// address=[0x3d8c080]
// [Decompilation failed for static int * CMinimapHandler::m_iObjectType]

// address=[0x415a610]
// [Decompilation failed for static struct SGfxColor * CMinimapHandler::m_sOwnerColorAlly]

// address=[0x415a670]
// [Decompilation failed for static struct SGfxColor * CMinimapHandler::m_sOwnerColor]

// address=[0x415a6d0]
// [Decompilation failed for static int * CMinimapHandler::m_iObjectGroups]

// address=[0x415a8e0]
// [Decompilation failed for static int * CMinimapHandler::m_iGroupEnabled]

// address=[0x415a8f8]
// [Decompilation failed for static int * CMinimapHandler::m_iObjectBitMask]

// address=[0x415ab08]
// [Decompilation failed for static struct SGfxColor * CMinimapHandler::m_sObjectColor]

