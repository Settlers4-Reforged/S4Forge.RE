#include "CAIResourceMap.h"

// Definitions for class CAIResourceMap

// address=[0x131a8e0]
// Decompiled from bool __cdecl CAIResourceMap::IsOfLandtype(int a1, Squares *a2, Squares *a3)
bool __cdecl CAIResourceMap::IsOfLandtype(enum T_RESOURCE_LANDTYPE a1, int a2, int a3) {
  
  int v4; // eax
  int v5; // [esp+0h] [ebp-28h]
  int v6; // [esp+4h] [ebp-24h]
  unsigned __int16 *v7; // [esp+8h] [ebp-20h]
  int v8; // [esp+Ch] [ebp-1Ch]
  int i; // [esp+14h] [ebp-14h]
  int j; // [esp+18h] [ebp-10h]
  int v11; // [esp+1Ch] [ebp-Ch]
  int v12; // [esp+1Ch] [ebp-Ch]
  int v13; // [esp+1Ch] [ebp-Ch]
  int v14; // [esp+1Ch] [ebp-Ch]
  CAIResourceData *v15; // [esp+20h] [ebp-8h]
  bool v16; // [esp+27h] [ebp-1h]

  if ( !Squares::ValidVW(a2, (unsigned int)a3) )
    return 0;
  v16 = 0;
  v15 = CAIResourceMap::ResourceDataVW(a2, a3);
  switch ( a1 )
  {
    case 1:
      v11 = CAIResourceData::ResourceAmount1(v15, 7);
      v16 = v11 < CStaticConfigVarInt::operator int(&unk_3EC2C88);
      break;
    case 2:
      v12 = CAIResourceData::ResourceAmount1(v15, 7);
      if ( v12 < CStaticConfigVarInt::operator int(&unk_3EC2C94) )
        v16 = v12 >= CStaticConfigVarInt::operator int(&unk_3EC2C88);
      break;
    case 3:
      v13 = CAIResourceData::ResourceAmount1(v15, 7);
      if ( v13 < CStaticConfigVarInt::operator int(&unk_3EC2CA0) )
        v16 = v13 >= CStaticConfigVarInt::operator int(&unk_3EC2C94);
      break;
    case 4:
      v14 = CAIResourceData::ResourceAmount1(v15, 7);
      v16 = v14 >= CStaticConfigVarInt::operator int(&unk_3EC2CA0);
      break;
    case 5:
      v16 = (CAIResourceData::Flags1(v15) & 0x40) != 0;
      break;
    case 6:
      v16 = (CAIResourceData::Flags1(v15) & 0x20) != 0;
      break;
    case 7:
      v16 = (CAIResourceData::Flags1(v15) & 2) != 0;
      break;
    case 8:
      v16 = CAIResourceData::GroundInfo1(v15, 0) > 100;
      break;
    case 9:
      v16 = CWarMap::FirstEntityIdVW(2, a2, a3) > 0;
      break;
    case 10:
    case 11:
      return v16;
    case 12:
      v5 = Squares::VWToXY(a2);
      v6 = Squares::VWToXY(a3);
      for ( i = 0; i < 16; ++i )
      {
        for ( j = 0; j < 16; ++j )
        {
          v8 = CWorldManager::ObjectId(i + v5, j + v6);
          if ( v8 )
          {
            v7 = (unsigned __int16 *)CMapObjectMgr::EntityPtr(v8);
            if ( v7 )
            {
              v4 = IEntity::Type(v7);
              if ( CDecoObjMgr::IsFlower((CDecoObjMgr *)&g_cDecoObjMgr, v4) )
              {
                v16 = 1;
                j = 16;
                i = 16;
              }
            }
          }
        }
      }
      break;
    case 13:
      if ( (CAIResourceData::Flags1(v15) & 2) != 0 )
        v16 = CAIResourceData::GroundInfo1(v15, 1) != 0;
      break;
    case 14:
      v16 = (CAIResourceData::Flags1(v15) & 4) != 0;
      break;
    case 15:
      v16 = (CAIResourceData::Flags1(v15) & 8) != 0;
      break;
    case 16:
      v16 = (CAIResourceData::Flags1(v15) & 0x10) != 0;
      break;
    default:
      v16 = 0;
      break;
  }
  return v16;
}


// address=[0x131abe0]
// Decompiled from int __cdecl CAIResourceMap::GetNumberOfSquaresWithDarkLand(int a1)
int __cdecl CAIResourceMap::GetNumberOfSquaresWithDarkLand(int a1) {
  
  CAIResourceData *v2; // eax
  int v3; // [esp+4h] [ebp-14h]
  int v4; // [esp+8h] [ebp-10h]
  int v5; // [esp+Ch] [ebp-Ch]
  int j; // [esp+10h] [ebp-8h]
  unsigned int i; // [esp+14h] [ebp-4h]

  if ( a1 <= 0 )
    return dword_3EC2CC8 * dword_3EC2CC8;
  if ( a1 == dword_3EC2D1C )
    return dword_3EC2D20;
  v5 = 0;
  for ( i = 0; (int)i < dword_3EC2CC8; ++i )
  {
    if ( byte_3EC2CD8[i] )
    {
      v4 = 0;
      for ( j = 0; j < dword_3EC2CC8; ++j )
      {
        v2 = CAIResourceMap::ResourceDataVW(j, i);
        v3 = CAIResourceData::GroundInfo1(v2, 0);
        v4 += v3;
        if ( v3 >= a1 )
          ++v5;
      }
      if ( !v4 )
      {
        if ( i >= 0x42 )
          j____report_rangecheckfailure();
        byte_3EC2CD8[i] = 0;
      }
    }
  }
  dword_3EC2D1C = a1;
  dword_3EC2D20 = v5;
  return v5;
}


// address=[0x131ca20]
// Decompiled from char *__cdecl CAIResourceMap::ResourceDataVW(int a1, int a2)
class CAIResourceData const & __cdecl CAIResourceMap::ResourceDataVW(int a1, int a2) {
  
  return (char *)&CAIResourceMap::m_cData + 2688 * a2 + 42 * a1 + 2688;
}


// address=[0x1321c10]
// Decompiled from char *__cdecl CAIResourceMap::ResourceDataXY(Squares *a1, Squares *a2)
class CAIResourceData const & __cdecl CAIResourceMap::ResourceDataXY(int a1, int a2) {
  
  int v2; // esi

  v2 = 2688 * (Squares::XYToVW(a2) + 1);
  return (char *)&CAIResourceMap::m_cData + 42 * Squares::XYToVW(a1) + v2;
}


// address=[0x131acf0]
// Decompiled from void CAIResourceMap::Init()
void __cdecl CAIResourceMap::Init(void) {
  
  int v0; // ecx
  int v1; // ecx
  int v2; // esi
  int v3; // edx
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx
  int m; // [esp+4h] [ebp-14h]
  int k; // [esp+8h] [ebp-10h]
  int v9; // [esp+Ch] [ebp-Ch]
  int j; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  dword_3EC2D1C = -1;
  dword_3EC2D20 = 0;
  memset(byte_3EC2CD8, 0, 0x42u);
  CPerformanceCounter::Start((CPerformanceCounter *)&stru_3EC2CB0);
  CAIResourceMap::Done();
  InitResourceGroundInfoMap();
  dword_3EC2CAC = CWorldManager::Width(v0);
  dword_3EC2CC8 = Squares::XYToVW((Squares *)dword_3EC2CAC);
  if ( dword_3EC2CC8 <= 0 && BBSupportDbgReport(2, "AI\\AI_ResourceMap.cpp", 754, "s_iResMapMaxVW > 0") == 1 )
    __debugbreak();
  dword_3EC2CCC = (dword_3EC2CC8 * dword_3EC2CC8 + 47) / 0x30u;
  if ( dword_3EC2CCC < 1 && BBSupportDbgReport(2, "AI\\AI_ResourceMap.cpp", 759, "s_iResMapUpdateSquaresNo >= 1") == 1 )
    __debugbreak();
  dword_3EC2CD0 = 0;
  dword_3EC2CD4 = 0;
  memset(&CAIResourceMap::m_cData, 0, 0x2B500u);
  v2 = CWorldManager::Width(v1);
  if ( v2 == CWorldManager::Height(v4, v3) && CWorldManager::Width(v5) <= 1024 && (CWorldManager::Width(v6) & 0xF) == 0 )
  {
    v9 = dword_3EC2CC8;
    for ( i = 0; i < v9; ++i )
    {
      for ( j = 0; j < v9; ++j )
      {
        sub_131B740(j, i);
        if ( (unsigned __int8)sub_131BA00(j, i) )
          sub_131BE20(j, i);
      }
    }
    for ( k = 0; k < v9; ++k )
    {
      for ( m = 0; m < v9; ++m )
        sub_131B8B0(m, k);
    }
    CAIResourceMap::s_iInitialized = 1;
    CPerformanceCounter::Measure((CPerformanceCounter *)&stru_3EC2CB0);
  }
  else if ( BBSupportDbgReport(1, "AI\\AI_ResourceMap.cpp", 776, "CInit(): Invalid map width or height!") == 1 )
  {
    __debugbreak();
  }
}


// address=[0x131af30]
// Decompiled from void CAIResourceMap::Done()
void __cdecl CAIResourceMap::Done(void) {
  
  CAIResourceMap::s_iInitialized = 0;
}


// address=[0x131af40]
// Decompiled from int __thiscall CAIResourceMap::Update(void *this)
void __cdecl CAIResourceMap::Update(void) {
  
  int v1; // edx
  int v2; // ecx
  int result; // eax
  int v4; // [esp+0h] [ebp-10h]
  int v5; // [esp+4h] [ebp-Ch]
  int v6; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( CAIResourceMap::s_iInitialized )
  {
    if ( CWorldManager::Width(this) != dword_3EC2CAC
      && BBSupportDbgReport(2, "AI\\AI_ResourceMap.cpp", 836, "g_cWorld.Width() == s_iWidthHeight") == 1 )
    {
      __debugbreak();
    }
    result = CWorldManager::Height(v2, v1);
    if ( result != dword_3EC2CAC )
    {
      result = BBSupportDbgReport(2, "AI\\AI_ResourceMap.cpp", 837, "g_cWorld.Height() == s_iWidthHeight");
      if ( result == 1 )
        __debugbreak();
    }
    v4 = dword_3EC2CCC;
    for ( i = 0; i < v4; ++i )
    {
      sub_131C060(dword_3EC2CD0, dword_3EC2CD4);
      v5 = dword_3EC2CD0 + 1;
      if ( dword_3EC2CD0 + 1 >= dword_3EC2CC8 )
      {
        v5 = 0;
        v6 = dword_3EC2CD4 + 1;
        if ( dword_3EC2CD4 + 1 >= dword_3EC2CC8 )
        {
          v6 = 0;
          dword_3EC2D1C = -1;
        }
        dword_3EC2CD4 = v6;
      }
      dword_3EC2CD0 = v5;
      result = i + 1;
    }
  }
  else
  {
    result = BBSupportDbgReport(1, "AI\\AI_ResourceMap.cpp", 882, "CAIResourceMap::Update(): Not initialized!");
    if ( result == 1 )
      __debugbreak();
  }
  return result;
}


// address=[0x131b070]
// Decompiled from int __cdecl CAIResourceMap::NotifyChange(Squares *a1, Squares *a2)
void __cdecl CAIResourceMap::NotifyChange(int a1, int a2) {
  
  int v2; // ecx
  int v3; // edx
  int v5; // [esp+0h] [ebp-8h]
  int v6; // [esp+4h] [ebp-4h]

  if ( !CAIResourceMap::s_iInitialized && BBSupportDbgReport(2, "AI\\AI_ResourceMap.cpp", 893, "s_iInitialized") == 1 )
    __debugbreak();
  if ( CWorldManager::Width(v2) != dword_3EC2CAC
    && BBSupportDbgReport(2, "AI\\AI_ResourceMap.cpp", 895, "g_cWorld.Width() == s_iWidthHeight") == 1 )
  {
    __debugbreak();
  }
  if ( CWorldManager::Height(0, v3) != dword_3EC2CAC
    && BBSupportDbgReport(2, "AI\\AI_ResourceMap.cpp", 896, "g_cWorld.Height() == s_iWidthHeight") == 1 )
  {
    __debugbreak();
  }
  v5 = Squares::XYToVW(a1);
  v6 = Squares::XYToVW(a2);
  if ( v5 >= dword_3EC2CC8 && BBSupportDbgReport(2, "AI\\AI_ResourceMap.cpp", 901, "iV < s_iResMapMaxVW") == 1 )
    __debugbreak();
  if ( v6 >= dword_3EC2CC8 && BBSupportDbgReport(2, "AI\\AI_ResourceMap.cpp", 902, "iW < s_iResMapMaxVW") == 1 )
    __debugbreak();
  return sub_131C060(v5, v6);
}


// address=[0x131b190]
// Decompiled from int __cdecl CAIResourceMap::NotifyResourceChange(Squares *a1, Squares *a2, int a3, int a4)
void __cdecl CAIResourceMap::NotifyResourceChange(int a1, int a2, int a3, int a4) {
  
  int v4; // ecx
  int v5; // edx
  int result; // eax
  __int16 v7; // [esp+0h] [ebp-2Ch]
  int v8; // [esp+4h] [ebp-28h]
  int v9; // [esp+8h] [ebp-24h]
  int i; // [esp+Ch] [ebp-20h]
  int v11; // [esp+10h] [ebp-1Ch]
  int v12; // [esp+14h] [ebp-18h]
  int j; // [esp+18h] [ebp-14h]
  int v14; // [esp+1Ch] [ebp-10h]
  int v15; // [esp+20h] [ebp-Ch]
  int v16; // [esp+24h] [ebp-8h]
  unsigned __int8 v17; // [esp+2Bh] [ebp-1h]

  if ( !CAIResourceMap::s_iInitialized && BBSupportDbgReport(2, "AI\\AI_ResourceMap.cpp", 914, "s_iInitialized") == 1 )
    __debugbreak();
  if ( CWorldManager::Width(v4) != dword_3EC2CAC
    && BBSupportDbgReport(2, "AI\\AI_ResourceMap.cpp", 916, "g_cWorld.Width() == s_iWidthHeight") == 1 )
  {
    __debugbreak();
  }
  if ( CWorldManager::Height(0, v5) != dword_3EC2CAC
    && BBSupportDbgReport(2, "AI\\AI_ResourceMap.cpp", 917, "g_cWorld.Height() == s_iWidthHeight") == 1 )
  {
    __debugbreak();
  }
  v15 = Squares::XYToVW(a1);
  v11 = Squares::XYToVW(a2);
  if ( v15 >= dword_3EC2CC8 && BBSupportDbgReport(2, "AI\\AI_ResourceMap.cpp", 922, "iV < s_iResMapMaxVW") == 1 )
    __debugbreak();
  if ( v11 >= dword_3EC2CC8 && BBSupportDbgReport(2, "AI\\AI_ResourceMap.cpp", 923, "iW < s_iResMapMaxVW") == 1 )
    __debugbreak();
  v16 = sub_131B720(a3);
  v9 = sub_131B730(a3);
  v8 = sub_131B720(a4);
  v7 = sub_131B730(a4);
  v17 = 0;
  v14 = sub_131A7E0(v15, v11);
  if ( *(unsigned __int16 *)(v14 + 2 * v16) >= v9 )
  {
    v17 = 1;
    *(_WORD *)(v14 + 2 * v16) -= v9;
    *(_WORD *)(v14 + 2 * v8) += v7;
    for ( i = -1; i <= 1; ++i )
    {
      for ( j = -1; j <= 1; ++j )
      {
        if ( j + v15 < (unsigned int)dword_3EC2CC8 )
        {
          v12 = sub_131A7E0(j + v15, i + v11);
          if ( *(unsigned __int16 *)(v12 + 2 * v16 + 16) < v9 )
          {
            v17 = 0;
            break;
          }
          *(_WORD *)(v12 + 2 * v16 + 16) -= v9;
          *(_WORD *)(v12 + 2 * v8 + 16) += v7;
        }
      }
    }
    sub_131C180(v15, v11);
  }
  result = v17;
  if ( v17 )
    return result;
  if ( BBSupportDbgReport(
         1,
         "AI\\AI_ResourceMap.cpp",
         973,
         "CAIResourceMap::NotifyResourceChange(): Invalid ResourceMap entry [may be ignored!]") == 1 )
    __debugbreak();
  return sub_131C060(v15, v11);
}


// address=[0x131b420]
// Decompiled from int __cdecl CAIResourceMap::NotifyDarkLandChange(Squares *a1, Squares *a2)
void __cdecl CAIResourceMap::NotifyDarkLandChange(int a1, int a2, bool a3) {
  
  CAIResourceData *v2; // eax
  int result; // eax
  CAIResourceData *v4; // eax
  int v5; // [esp+4h] [ebp-Ch]
  int v6; // [esp+8h] [ebp-8h]
  int v7; // [esp+Ch] [ebp-4h]

  if ( !(unsigned __int8)CWorldManager::InWorld((int)a1, (int)a2)
    && BBSupportDbgReport(2, "AI\\AI_ResourceMap.cpp", 986, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  v6 = Squares::XYToVW(a1);
  v7 = Squares::XYToVW(a2);
  v2 = CAIResourceMap::ResourceDataVW(v6, v7);
  v5 = CAIResourceData::GroundInfo1(v2, 0);
  sub_131BE20(v6, v7);
  result = sub_131BA00(v6, v7);
  if ( dword_3EC2D1C <= 0 )
    return result;
  if ( (v4 = CAIResourceMap::ResourceDataVW(v6, v7), result = CAIResourceData::GroundInfo1(v4, 0), v5 < dword_3EC2D1C)
    && result >= dword_3EC2D1C
    || v5 >= dword_3EC2D1C && result < dword_3EC2D1C )
  {
    dword_3EC2D1C = -1;
  }
  return result;
}


// address=[0x3e97784]
// [Decompilation failed for static int CAIResourceMap::s_iInitialized]

// address=[0x3e97788]
// [Decompilation failed for static class CAIResourceData (* CAIResourceMap::m_cData)[64]]

