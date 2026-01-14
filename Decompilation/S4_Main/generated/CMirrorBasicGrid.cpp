#include "all_headers.h"

// Definitions for class CMirrorBasicGrid

// address=[0x2fc5fb0]
// Decompiled from CMirrorBasicGrid *__thiscall CMirrorBasicGrid::CMirrorBasicGrid(CMirrorBasicGrid *this, int a2, int a3)
 CMirrorBasicGrid::CMirrorBasicGrid(int,int) {
  
  CBasicGrid::CBasicGrid(this, a2, a3);
  *(_DWORD *)this = &CMirrorBasicGrid::_vftable_;
  return this;
}


// address=[0x2fc5fe0]
// Decompiled from int __thiscall CMirrorBasicGrid::initGrid(CMirrorBasicGrid *this)
void  CMirrorBasicGrid::initGrid(void) {
  
  int result; // eax
  int v2; // [esp+0h] [ebp-CCh]
  int v3; // [esp+4h] [ebp-C8h]
  int v4; // [esp+8h] [ebp-C4h]
  int v5; // [esp+Ch] [ebp-C0h]
  int v6; // [esp+10h] [ebp-BCh]
  int v7; // [esp+14h] [ebp-B8h]
  int j; // [esp+18h] [ebp-B4h]
  int v9; // [esp+1Ch] [ebp-B0h] BYREF
  int v10; // [esp+20h] [ebp-ACh] BYREF
  int v11; // [esp+24h] [ebp-A8h]
  int i; // [esp+28h] [ebp-A4h]
  int m; // [esp+2Ch] [ebp-A0h]
  int k; // [esp+30h] [ebp-9Ch]
  int v15; // [esp+34h] [ebp-98h] BYREF
  int v16; // [esp+38h] [ebp-94h] BYREF
  char v17; // [esp+3Eh] [ebp-8Eh]
  char v18; // [esp+3Fh] [ebp-8Dh]
  CMirrorBasicGrid *v19; // [esp+40h] [ebp-8Ch]
  int v20; // [esp+44h] [ebp-88h]
  _DWORD v21[16]; // [esp+48h] [ebp-84h]
  _DWORD v22[4]; // [esp+88h] [ebp-44h] BYREF
  _DWORD v23[4]; // [esp+98h] [ebp-34h] BYREF
  _DWORD v24[4]; // [esp+A8h] [ebp-24h] BYREF
  _DWORD v25[4]; // [esp+B8h] [ebp-14h] BYREF

  v19 = this;
  v2 = *((_DWORD *)this + 2) * *((_DWORD *)this + 2);
  v11 = 0;
  if ( (g_iFlags & 2) != 0 && (g_iFlags & 1) != 0 )
    v11 = (int)(float)((float)((float)((float)v2 * (float)((float)*((int *)v19 + 3) / 100.0))
                             - (float)(unsigned __int8)g_iNumPlayers)
                     / 4.0);
  else
    v11 = (int)(float)((float)((float)((float)v2 * (float)((float)*((int *)v19 + 3) / 100.0))
                             - (float)(unsigned __int8)g_iNumPlayers)
                     / 2.0);
  for ( i = 0; i < v11; ++i )
  {
    v9 = 0;
    v10 = 0;
    v18 = 0;
    while ( !v18 )
    {
      CMirrorBasicGrid::getMirrorBasisPoint(v19, &v9, &v10, 1);
      if ( !*(_BYTE *)(*((_DWORD *)v19 + 1) + v9 + *((_DWORD *)v19 + 2) * v10) )
        v18 = 1;
    }
    *(_BYTE *)(*((_DWORD *)v19 + 1) + v9 + *((_DWORD *)v19 + 2) * v10) = 1;
  }
  memset(v22, -1, sizeof(v22));
  memset(v23, -1, sizeof(v23));
  memset(v24, -1, sizeof(v24));
  result = (int)memset(v25, -1, sizeof(v25));
  v7 = 0;
  v5 = 0;
  v6 = 0;
  v4 = 0;
  v20 = 0;
  while ( v20 < (unsigned __int8)g_iNumPlayers )
  {
    v17 = 0;
    v16 = 0;
    v15 = 0;
    for ( j = 0; !v17 && j < 40; ++j )
    {
      CMirrorBasicGrid::getMirrorBasisPoint(v19, &v16, &v15, 0);
      if ( *(_BYTE *)(*((_DWORD *)v19 + 1) + v16 + *((_DWORD *)v19 + 2) * v15) != 101
        && *(_BYTE *)(*((_DWORD *)v19 + 1) + v16 + *((_DWORD *)v19 + 2) * v15) != 1 )
      {
        v17 = 1;
      }
    }
    v21[v20] = v16;
    v21[v20 + 8] = v15;
    *(_BYTE *)(*((_DWORD *)v19 + 1) + v16 + *((_DWORD *)v19 + 2) * v15) = 101;
    v22[v7] = v20;
    result = ++v7;
    ++v20;
    if ( (g_iFlags & 2) != 0 )
    {
      result = (unsigned __int8)g_iNumPlayers;
      if ( v20 < (unsigned __int8)g_iNumPlayers )
      {
        v21[v20] = *((_DWORD *)v19 + 2) - v15 - 1;
        v21[v20 + 8] = *((_DWORD *)v19 + 2) - v16 - 1;
        v24[v6++] = v20;
        result = ++v20;
      }
    }
    if ( (g_iFlags & 1) != 0 && v20 < (unsigned __int8)g_iNumPlayers )
    {
      v21[v20] = v15;
      v21[v20 + 8] = v16;
      v23[v5++] = v20;
      result = ++v20;
    }
    if ( (g_iFlags & 1) != 0 && (g_iFlags & 2) != 0 )
    {
      result = (unsigned __int8)g_iNumPlayers;
      if ( v20 < (unsigned __int8)g_iNumPlayers )
      {
        v21[v20] = *((_DWORD *)v19 + 2) - v16 - 1;
        v21[v20 + 8] = *((_DWORD *)v19 + 2) - v15 - 1;
        v25[v4] = v20;
        result = ++v4;
        ++v20;
      }
    }
  }
  v3 = 0;
  for ( k = 0; k < 4; ++k )
  {
    for ( m = 0; m < 4; ++m )
    {
      if ( v22[4 * k + m] != -1 )
        CPlayerData::setStartPos_Basic(
          *(CPlayerData **)(g_pPlayerData + 4 * v3++),
          v21[v22[4 * k + m]],
          v21[v22[4 * k + m] + 8]);
      result = m + 1;
    }
  }
  return result;
}


// address=[0x2fc6600]
// Decompiled from int *__thiscall CMirrorBasicGrid::getMirrorBasisPoint(CMirrorBasicGrid *this, unsigned int *a2, int *a3, bool a4)
void  CMirrorBasicGrid::getMirrorBasisPoint(int &,int &,bool) {
  
  int *result; // eax
  unsigned int v5; // edx
  unsigned int v6; // edx
  unsigned int v7; // edx
  unsigned int v8; // edx
  unsigned int v9; // edx

  result = (int *)(g_iFlags & 1);
  if ( (g_iFlags & 1) != 0 && (g_iFlags & 2) == 0 )
  {
    if ( a4 )
    {
      *a2 = CRandom16::Rand((CRandom16 *)g_pRand) % *((_DWORD *)this + 2);
      v5 = CRandom16::Rand((CRandom16 *)g_pRand) % (*((_DWORD *)this + 2) - *a2);
      result = (int *)a2;
      *a3 = *a2 + v5;
    }
    else
    {
      *a2 = CRandom16::Rand((CRandom16 *)g_pRand) % (*((_DWORD *)this + 2) - 1);
      v6 = CRandom16::Rand((CRandom16 *)g_pRand) % (*((_DWORD *)this + 2) - *a2 - 1) + *a2 + 1;
      result = a3;
      *a3 = v6;
    }
  }
  if ( (g_iFlags & 2) != 0 && (g_iFlags & 1) == 0 )
  {
    if ( a4 )
    {
      *a2 = CRandom16::Rand((CRandom16 *)g_pRand) % *((_DWORD *)this + 2);
      v7 = CRandom16::Rand((CRandom16 *)g_pRand) % (*((_DWORD *)this + 2) - *a2);
    }
    else
    {
      *a2 = CRandom16::Rand((CRandom16 *)g_pRand) % (*((_DWORD *)this + 2) - 1);
      v7 = CRandom16::Rand((CRandom16 *)g_pRand) % (*((_DWORD *)this + 2) - *a2 - 1);
    }
    result = a3;
    *a3 = v7;
  }
  if ( (g_iFlags & 2) == 0 || (g_iFlags & 1) == 0 )
    return result;
  if ( a4 )
  {
    *a2 = CRandom16::Rand((CRandom16 *)g_pRand) % (*((_DWORD *)this + 2) / 2);
    v8 = CRandom16::Rand((CRandom16 *)g_pRand) % (*((_DWORD *)this + 2) - 2 * *a2);
    result = (int *)a2;
    *a3 = *a2 + v8;
  }
  else
  {
    *a2 = CRandom16::Rand((CRandom16 *)g_pRand) % ((*((_DWORD *)this + 2) - 1) / 2);
    v9 = CRandom16::Rand((CRandom16 *)g_pRand) % (*((_DWORD *)this + 2) - (2 * *a2 + 2)) + *a2 + 1;
    result = a3;
    *a3 = v9;
  }
  return result;
}


