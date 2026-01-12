#include "CWarMap.h"

// Definitions for class CWarMap

// address=[0x131c8e0]
// Decompiled from int __cdecl CWarMap::FirstEntityIdVW(int a1, int a2, int a3)
static int __cdecl CWarMap::FirstEntityIdVW(enum T_WAR_MAP_TYPE,int,int) {
  
  return CWarMap::m_sSquares[640 * a3 + 640 + 10 * a2 + 2 * a1];
}


// address=[0x1351c00]
// Decompiled from int __cdecl CWarMap::NumberOfEntitiesXY(int a1, Squares *a2, Squares *a3)
static unsigned int __cdecl CWarMap::NumberOfEntitiesXY(enum T_WAR_MAP_TYPE,int,int) {
  
  int v3; // esi

  v3 = 640 * (Squares::XYToVW(a3) + 1);
  return CWarMap::m_sSquares[10 * Squares::XYToVW(a2) + 1 + 2 * a1 + v3];
}


// address=[0x14e0030]
// Decompiled from int __cdecl CWarMap::NumberOfEntitiesVW(int a1, int a2, int a3)
static unsigned int __cdecl CWarMap::NumberOfEntitiesVW(enum T_WAR_MAP_TYPE,int,int) {
  
  return CWarMap::m_sSquares[640 * a3 + 641 + 10 * a2 + 2 * a1];
}


// address=[0x152bce0]
// Decompiled from int __cdecl CWarMap::FirstEntityIdXY(int a1, Squares *a2, Squares *a3)
static int __cdecl CWarMap::FirstEntityIdXY(enum T_WAR_MAP_TYPE,int,int) {
  
  int v3; // esi

  v3 = 640 * (Squares::XYToVW(a3) + 1);
  return CWarMap::m_sSquares[10 * Squares::XYToVW(a2) + 2 * a1 + v3];
}


// address=[0x15e2d40]
// Decompiled from int __cdecl CWarMap::SettlerInfluValue(unsigned int a1)
static int __cdecl CWarMap::SettlerInfluValue(int) {
  
  if ( a1 >= 0x46
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\pathing\\WarMap.h",
         135,
         "static_cast<unsigned int>(_iSettlerTypeEx) < SETTLER_MAX_EX") == 1 )
  {
    __debugbreak();
  }
  return CWarMap::m_iSettlerInfluValues[a1];
}


// address=[0x15fb5f0]
// Decompiled from void *__thiscall CWarMap::Init(void *this)
static void __cdecl CWarMap::Init(void) {
  
  void *result; // eax
  int *i; // [esp+0h] [ebp-4h]
  int *j; // [esp+0h] [ebp-4h]

  CWarMap::Done(this);
  memset(CWarMap::m_sSquares, 0, sizeof(CWarMap::m_sSquares));
  memset(dword_45C6B88, 255, 0x40000u);
  memset(CWarMap::m_iSettlerInfluValues, 0, sizeof(CWarMap::m_iSettlerInfluValues));
  memset(dword_45C6B70, 0, sizeof(dword_45C6B70));
  for ( i = (int *)&unk_37E3150; *i >= 0; i += 2 )
  {
    if ( *i >= 70 && BBSupportDbgReport(2, "Pathing\\WarMap.cpp", 212, "pInfuInfo->m_iType < SETTLER_MAX_EX") == 1 )
      __debugbreak();
    if ( i[1] < 0 && BBSupportDbgReport(2, "Pathing\\WarMap.cpp", 214, "pInfuInfo->m_iValue >= 0") == 1 )
      __debugbreak();
    if ( i[1] > 15 && BBSupportDbgReport(2, "Pathing\\WarMap.cpp", 215, "pInfuInfo->m_iValue <= 15") == 1 )
      __debugbreak();
    CWarMap::m_iSettlerInfluValues[*i] = i[1];
  }
  for ( j = (int *)&unk_37E3240; *j >= 0; j += 2 )
  {
    if ( *j >= 6 && BBSupportDbgReport(2, "Pathing\\WarMap.cpp", 222, "pInfuInfo->m_iType < VEHICLE_MAX") == 1 )
      __debugbreak();
    if ( j[1] < 0 && BBSupportDbgReport(2, "Pathing\\WarMap.cpp", 224, "pInfuInfo->m_iValue >= 0") == 1 )
      __debugbreak();
    if ( j[1] > 15 && BBSupportDbgReport(2, "Pathing\\WarMap.cpp", 225, "pInfuInfo->m_iValue <= 15") == 1 )
      __debugbreak();
    dword_45C6B70[*j] = j[1];
  }
  result = CInfluMap::Init();
  CWarMap::m_iInitialized = 1;
  return result;
}


// address=[0x15fb7d0]
// Decompiled from void CWarMap::Done()
static void __cdecl CWarMap::Done(void) {
  
  unsigned int i; // [esp+0h] [ebp-4h]

  if ( CWarMap::m_iInitialized )
  {
    for ( i = 0; i < 0x10000; ++i )
    {
      if ( dword_45C6B88[i] != -1
        && BBSupportDbgReport(2, "Pathing\\WarMap.cpp", 251, "s_iEntityWarMapXYs[i] == -1") == 1 )
      {
        __debugbreak();
      }
    }
    CInfluMap::Done();
    CWarMap::m_iInitialized = 0;
  }
}


// address=[0x15fb840]
// Decompiled from int __cdecl sub_19FB840(CPropertySet *a1)
static void __cdecl CWarMap::AddEntity(class IEntity &) {
  
  int v1; // eax
  int v2; // eax

  if ( *(_DWORD *)IEntity::WarMapNode(a1) != 0xFFFF )
  {
    v1 = IEntity::PackedXY(a1);
    CWarMap::RemoveEntityEx(a1, v1);
  }
  v2 = IEntity::PackedXY(a1);
  return CWarMap::AddEntityEx(a1, v2);
}


// address=[0x15fb880]
// Decompiled from struct CPtrList *__cdecl CWarMap::RemoveEntity(IEntity *a1)
static void __cdecl CWarMap::RemoveEntity(class IEntity &) {
  
  struct CWarMapNode *result; // eax
  int v2; // [esp-4h] [ebp-4h]

  result = IEntity::WarMapNode(a1);
  if ( *(_DWORD *)result == 0xFFFF )
    return result;
  v2 = IEntity::PackedXY(a1);
  CWarMap::RemoveEntityEx(a1, v2);
  return result;
}


// address=[0x15fb8b0]
// Decompiled from int __cdecl CWarMap::NotifyMove(CPropertySet *a1, int a2)
static void __cdecl CWarMap::NotifyMove(class IEntity &,int) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  Squares *v8; // eax
  Squares *v9; // eax
  Squares *v10; // eax
  Squares *v11; // eax
  int result; // eax
  int v13; // eax
  int v14; // eax
  int v15; // [esp-10h] [ebp-24h]
  int v16; // [esp-Ch] [ebp-20h]
  int v17; // [esp-8h] [ebp-1Ch]
  int v18; // [esp-4h] [ebp-18h]
  int v19; // [esp+4h] [ebp-10h]
  int v20; // [esp+8h] [ebp-Ch]
  int v21; // [esp+Ch] [ebp-8h]
  int v22; // [esp+10h] [ebp-4h]

  if ( !CWarMap::m_iInitialized && BBSupportDbgReport(2, "Pathing\\WarMap.cpp", 505, "m_iInitialized") == 1 )
    __debugbreak();
  if ( (IEntity::ObjType((unsigned __int8 *)a1) & 0xDF) != 0 )
  {
    if ( *(unsigned __int16 *)IEntity::WarMapNode(a1) == 0xFFFF )
    {
      v13 = IEntity::ID();
      BBSupportTracePrintF(
        6,
        "### ERROR !! CWarMap::NotifyMove(): Entity %i not in war map (Prev == PREV_NOT_IN_LIST) !! ERROR ###",
        v13);
      v14 = IEntity::ID();
      return CMapObjectMgr::DbgPrintEntity(g_pMapObjectMgr, v14, 6, 0);
    }
    else
    {
      if ( IEntity::ID() <= 0 && BBSupportDbgReport(2, "Pathing\\WarMap.cpp", 511, "_rEntity.ID() > 0") == 1 )
        __debugbreak();
      if ( *(unsigned __int16 *)IEntity::WarMapNode(a1) == 0xFFFF
        && BBSupportDbgReport(
             2,
             "Pathing\\WarMap.cpp",
             512,
             "_rEntity.WarMapNode().m_uPrev != CWarMapNode::PREV_NOT_IN_LIST") == 1 )
      {
        __debugbreak();
      }
      if ( dword_45C6B88[IEntity::ID()] >= 0 )
      {
        if ( dword_45C6B88[IEntity::ID()] != a2 )
        {
          v4 = IEntity::ID();
          v18 = Y16X16::UnpackYFast(dword_45C6B88[v4]);
          v5 = IEntity::ID();
          v17 = Y16X16::UnpackXFast(dword_45C6B88[v5]);
          v16 = Y16X16::UnpackYFast(a2);
          v15 = Y16X16::UnpackXFast(a2);
          v6 = IEntity::ID();
          BBSupportTracePrintF(
            6,
            "### ERROR !! CWarMap::NotifyMove(): Wrong old (X, Y) for entity %5i. Is (%4i, %4i), should be (%4i, %4i). !! ERROR ###",
            v6,
            v15,
            v16,
            v17,
            v18);
          v7 = IEntity::ID();
          CMapObjectMgr::DbgPrintEntity(g_pMapObjectMgr, v7, 6, 0);
          a2 = dword_45C6B88[IEntity::ID()];
        }
      }
      else
      {
        v2 = IEntity::ID();
        BBSupportTracePrintF(6, "### ERROR !! CWarMap::NotifyMove(): Entity %i not in war map !! ERROR ###", v2);
        v3 = IEntity::ID();
        CMapObjectMgr::DbgPrintEntity(g_pMapObjectMgr, v3, 6, 0);
        CWarMap::AddEntityEx(a1, a2);
      }
      v8 = (Squares *)Y16X16::UnpackXFast(a2);
      v21 = Squares::XYToVW(v8);
      v9 = (Squares *)Y16X16::UnpackYFast(a2);
      v19 = Squares::XYToVW(v9);
      v22 = IEntity::PackedXY(a1);
      v10 = (Squares *)Y16X16::UnpackXFast(v22);
      v20 = Squares::XYToVW(v10);
      v11 = (Squares *)Y16X16::UnpackYFast(v22);
      if ( (v19 - Squares::XYToVW(v11)) | (v21 - v20) )
      {
        CWarMap::RemoveEntityEx(a1, a2);
        return CWarMap::AddEntity(a1);
      }
      else
      {
        result = IEntity::ID();
        dword_45C6B88[result] = v22;
      }
    }
  }
  else
  {
    result = (int)IEntity::WarMapNode(a1);
    if ( *(_DWORD *)result != 0xFFFF )
    {
      result = BBSupportDbgReport(
                 2,
                 "Pathing\\WarMap.cpp",
                 563,
                 "_rEntity.WarMapNode().m_uNextPrev == CWarMapNode::NEXT_PREV_NOT_IN_LIST");
      if ( result == 1 )
        __debugbreak();
    }
  }
  return result;
}


// address=[0x15fc6b0]
// Decompiled from int __cdecl CWarMap::ObjectTypeToWarMapType(char a1)
static enum T_WAR_MAP_TYPE __cdecl CWarMap::ObjectTypeToWarMapType(int) {
  
  return (4 * ((a1 & 0x50) != 0)) | ((a1 & 0x86) != 0) | (2 * ((a1 & 0x88) != 0));
}


// address=[0x15fbb80]
// Decompiled from __int16 __cdecl CWarMap::AddEntityEx(CPropertySet *a1, int a2)
static void __cdecl CWarMap::AddEntityEx(class IEntity &,int) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  Squares *v5; // eax
  Squares *v6; // eax
  int v7; // eax
  char v8; // al
  Squares *v9; // eax
  Squares *v10; // eax
  CWarMapNode *v11; // eax
  struct CPtrList *v12; // eax
  int v14; // [esp-4h] [ebp-2Ch]
  int v15; // [esp+0h] [ebp-28h]
  int v16; // [esp+4h] [ebp-24h]
  int v17; // [esp+8h] [ebp-20h]
  int v18; // [esp+Ch] [ebp-1Ch]
  int v19; // [esp+10h] [ebp-18h]
  CWarMapNode *v20; // [esp+14h] [ebp-14h]
  int v21; // [esp+18h] [ebp-10h]
  int v22; // [esp+1Ch] [ebp-Ch]
  int v23; // [esp+20h] [ebp-8h]
  unsigned __int16 *v24; // [esp+24h] [ebp-4h]

  if ( !CWarMap::m_iInitialized && BBSupportDbgReport(2, "Pathing\\WarMap.cpp", 271, "m_iInitialized") == 1 )
    __debugbreak();
  if ( *(_DWORD *)IEntity::WarMapNode(a1) != 0xFFFF
    && BBSupportDbgReport(
         2,
         "Pathing\\WarMap.cpp",
         272,
         "_rEntity.WarMapNode().m_uNextPrev == CWarMapNode::NEXT_PREV_NOT_IN_LIST") == 1 )
  {
    __debugbreak();
  }
  if ( (IEntity::ObjType((unsigned __int8 *)a1) & 0xDF) != 0 )
  {
    if ( dword_45C6B88[IEntity::ID()] >= 0 )
    {
      v2 = IEntity::ID();
      BBSupportTracePrintF(6, "### ERROR !! CWarMap::AddEntityEx(): Entity %i already in war map !! ERROR ###", v2);
      v3 = IEntity::ID();
      CMapObjectMgr::DbgPrintEntity(g_pMapObjectMgr, v3, 6, 0);
      CWarMap::RemoveEntity(a1);
    }
    if ( dword_45C6B88[IEntity::ID()] != -1
      && BBSupportDbgReport(2, "Pathing\\WarMap.cpp", 286, "s_iEntityWarMapXYs[_rEntity.ID()] == -1") == 1 )
    {
      __debugbreak();
    }
    dword_45C6B88[IEntity::ID()] = a2;
    if ( IEntity::ID() <= 0 && BBSupportDbgReport(2, "Pathing\\WarMap.cpp", 292, "_rEntity.ID() > 0") == 1 )
      __debugbreak();
    if ( *(_DWORD *)IEntity::WarMapNode(a1) != 0xFFFF
      && BBSupportDbgReport(
           2,
           "Pathing\\WarMap.cpp",
           293,
           "_rEntity.WarMapNode().m_uNextPrev == CWarMapNode::NEXT_PREV_NOT_IN_LIST") == 1 )
    {
      __debugbreak();
    }
    if ( IEntity::WarriorType() )
    {
      v14 = IEntity::Type((unsigned __int16 *)a1);
      v4 = IEntity::ObjType((unsigned __int8 *)a1);
      v21 = sub_15FC2F0(v4, v14);
      if ( v21 )
      {
        v5 = (Squares *)Y16X16::UnpackXFast(a2);
        v18 = Squares::XYToVW(v5);
        v6 = (Squares *)Y16X16::UnpackYFast(a2);
        v19 = Squares::XYToVW(v6);
        v7 = IEntity::OwnerId((unsigned __int8 *)a1);
        CInfluMap::ModifyInfluenceMapVW(v18, v19, v7, v21);
      }
    }
    v22 = IEntity::ID();
    v8 = IEntity::ObjType((unsigned __int8 *)a1);
    v15 = CWarMap::ObjectTypeToWarMapType(v8);
    if ( !v22 && BBSupportDbgReport(2, "Pathing\\WarMap.cpp", 313, "uEntityId > 0") == 1 )
      __debugbreak();
    v9 = (Squares *)Y16X16::UnpackXFast(a2);
    v16 = Squares::XYToVW(v9);
    v10 = (Squares *)Y16X16::UnpackYFast(a2);
    v17 = Squares::XYToVW(v10);
    v24 = (unsigned __int16 *)CWarMap::WarMapTypeSquareDataVW(v15, v16, v17);
    v23 = *v24;
    v11 = IEntity::WarMapNode(a1);
    CWarMapNode::SetPrevNext(v11, 0, v23);
    *v24 = v22;
    if ( v23 )
    {
      v20 = (CWarMapNode *)CWarMapNode::GetFromPrev(v23);
      if ( CWarMapNode::Prev(v20) && BBSupportDbgReport(2, "Pathing\\WarMap.cpp", 334, "rNextNode.Prev() == 0") == 1 )
        __debugbreak();
      CWarMapNode::SetPrev(v20, v22);
    }
    LOWORD(v12) = v24[1] + 1;
    v24[1] = (unsigned __int16)v12;
  }
  else
  {
    v12 = IEntity::WarMapNode(a1);
    if ( *(_DWORD *)v12 != 0xFFFF )
    {
      v12 = (struct CPtrList *)BBSupportDbgReport(
                                 2,
                                 "Pathing\\WarMap.cpp",
                                 345,
                                 "_rEntity.WarMapNode().m_uNextPrev == CWarMapNode::NEXT_PREV_NOT_IN_LIST");
      if ( v12 == (struct CPtrList *)1 )
        __debugbreak();
    }
  }
  return (__int16)v12;
}


// address=[0x15fbeb0]
// Decompiled from void __cdecl CWarMap::RemoveEntityEx(IEntity *a1, int a2)
static void __cdecl CWarMap::RemoveEntityEx(class IEntity &,int) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  Squares *v8; // eax
  Squares *v9; // eax
  int v10; // eax
  int v11; // eax
  char v12; // al
  int prevWarMapNode; // eax
  int v14; // esi
  WORD v15; // ax
  int v16; // esi
  int v17; // eax
  int v18; // esi
  int v19; // eax
  int v20; // [esp-10h] [ebp-34h]
  int v21; // [esp-Ch] [ebp-30h]
  int v22; // [esp-8h] [ebp-2Ch]
  int v23; // [esp-4h] [ebp-28h]
  int v24; // [esp-4h] [ebp-28h]
  int v25; // [esp+4h] [ebp-20h]
  CWarMapNode *v26; // [esp+8h] [ebp-1Ch]
  CWarMapNode *v27; // [esp+Ch] [ebp-18h]
  int v28; // [esp+10h] [ebp-14h]
  int v29; // [esp+14h] [ebp-10h]
  int v30; // [esp+18h] [ebp-Ch]
  unsigned __int16 *v31; // [esp+1Ch] [ebp-8h]
  CWarMapNode *v32; // [esp+20h] [ebp-4h]

  if ( !CWarMap::m_iInitialized && BBSupportDbgReport(2, "Pathing\\WarMap.cpp", 358, "m_iInitialized") == 1 )
    __debugbreak();
  if ( *IEntity::WarMapNode(a1) == 0xFFFF
    && BBSupportDbgReport(
         2,
         "Pathing\\WarMap.cpp",
         359,
         "_rEntity.WarMapNode().m_uNextPrev != CWarMapNode::NEXT_PREV_NOT_IN_LIST") == 1 )
  {
    __debugbreak();
  }
  if ( (IEntity::ObjType(a1) & 0xDF) != 0 )
  {
    if ( dword_45C6B88[IEntity::ID(a1)] >= 0 )
    {
      if ( dword_45C6B88[IEntity::ID(a1)] != a2 )
      {
        v4 = IEntity::ID(a1);
        v23 = Y16X16::UnpackYFast(dword_45C6B88[v4]);
        v5 = IEntity::ID(a1);
        v22 = Y16X16::UnpackXFast(dword_45C6B88[v5]);
        v21 = Y16X16::UnpackYFast(a2);
        v20 = Y16X16::UnpackXFast(a2);
        v6 = IEntity::ID(a1);
        BBSupportTracePrintF(
          6,
          "### ERROR !! CWarMap::RemoveEntityEx(): Wrong (X, Y) for entity %5i. Is (%4i, %4i), should be (%4i, %4i) !! ERROR ###",
          v6,
          v20,
          v21,
          v22,
          v23);
        v7 = IEntity::ID(a1);
        CMapObjectMgr::DbgPrintEntity(g_pMapObjectMgr, v7, 6, 0);
        a2 = dword_45C6B88[IEntity::ID(a1)];
      }
      dword_45C6B88[IEntity::ID(a1)] = -1;
      if ( IEntity::ID(a1) <= 0 && BBSupportDbgReport(2, "Pathing\\WarMap.cpp", 385, "_rEntity.ID() > 0") == 1 )
        __debugbreak();
      if ( *(unsigned __int16 *)&IEntity::WarMapNode(a1)->prev == 0xFFFF
        && BBSupportDbgReport(
             2,
             "Pathing\\WarMap.cpp",
             386,
             "_rEntity.WarMapNode().m_uPrev != CWarMapNode::PREV_NOT_IN_LIST") == 1 )
      {
        __debugbreak();
      }
      v8 = (Squares *)Y16X16::UnpackXFast(a2);
      v28 = Squares::XYToVW(v8);
      v9 = (Squares *)Y16X16::UnpackYFast(a2);
      v29 = Squares::XYToVW(v9);
      if ( IEntity::WarriorType() )
      {
        v24 = IEntity::Type(a1);
        v10 = IEntity::ObjType(a1);
        v30 = sub_15FC2F0(v10, v24);
        if ( v30 )
        {
          v11 = IEntity::OwnerId(a1);
          CInfluMap::ModifyInfluenceMapVW(v28, v29, v11, -v30);
        }
      }
      v32 = IEntity::WarMapNode(a1);
      v12 = IEntity::ObjType(a1);
      v25 = CWarMap::ObjectTypeToWarMapType(v12);
      v31 = (unsigned __int16 *)CWarMap::WarMapTypeSquareDataVW(v25, v28, v29);
      if ( !v31[1] && BBSupportDbgReport(2, "Pathing\\WarMap.cpp", 413, "rWarMapTypeSquareData.m_uNumber > 0") == 1 )
        __debugbreak();
      --v31[1];
      if ( CWarMapNode::Prev(v32) )
      {
        prevWarMapNode = CWarMapNode::Prev(v32);
        v27 = CWarMapNode::GetFromPrev(prevWarMapNode);
        v14 = CWarMapNode::Next(v27);
        if ( v14 != IEntity::ID(a1)
          && BBSupportDbgReport(2, "Pathing\\WarMap.cpp", 423, "rPrevNode.Next() == _rEntity.ID()") == 1 )
        {
          __debugbreak();
        }
        v15 = CWarMapNode::Next(v32);
        CWarMapNode::SetNext(v27, v15);
      }
      else
      {
        v16 = *v31;
        if ( v16 != IEntity::ID(a1)
          && BBSupportDbgReport(2, "Pathing\\WarMap.cpp", 429, "rWarMapTypeSquareData.m_uFirst == _rEntity.ID()") == 1 )
        {
          __debugbreak();
        }
        *v31 = CWarMapNode::Next(v32);
      }
      if ( CWarMapNode::Next(v32) )
      {
        v17 = CWarMapNode::Next(v32);
        v26 = CWarMapNode::GetFromPrev(v17);
        v18 = CWarMapNode::Prev(v26);
        if ( v18 != IEntity::ID(a1)
          && BBSupportDbgReport(2, "Pathing\\WarMap.cpp", 440, "rNextNode.Prev() == _rEntity.ID()") == 1 )
        {
          __debugbreak();
        }
        v19 = CWarMapNode::Prev(v32);
        CWarMapNode::SetPrev(v26, v19);
      }
      *v32 = (CWarMapNode)0xFFFF;
    }
    else
    {
      v2 = IEntity::ID(a1);
      BBSupportTracePrintF(6, "### ERROR !! CWarMap::RemoveEntityEx(): Entity %i not in war map !! ERROR ###", v2);
      v3 = IEntity::ID(a1);
      CMapObjectMgr::DbgPrintEntity(g_pMapObjectMgr, v3, 6, 0);
    }
  }
  else if ( *IEntity::WarMapNode(a1) != 0xFFFF
         && BBSupportDbgReport(
              2,
              "Pathing\\WarMap.cpp",
              452,
              "_rEntity.WarMapNode().m_uNextPrev == CWarMapNode::NEXT_PREV_NOT_IN_LIST") == 1 )
  {
    __debugbreak();
  }
}


// address=[0x15fc7c0]
// Decompiled from unsigned __int16 *__cdecl CWarMap::WarMapTypeSquareDataVW(int a1, int a2, int a3)
static struct CWarMap::SWarMapTypeSquareData & __cdecl CWarMap::WarMapTypeSquareDataVW(enum T_WAR_MAP_TYPE,int,int) {
  
  return &CWarMap::m_sSquares[640 * a3 + 640 + 10 * a2 + 2 * a1];
}


// address=[0x45b2050]
// [Decompilation failed for static int * CWarMap::m_iSettlerInfluValues]

// address=[0x45b2168]
// [Decompilation failed for static int CWarMap::m_iInitialized]

// address=[0x45b2170]
// [Decompilation failed for static struct CWarMap::SWarMapSquare (* CWarMap::m_sSquares)[64]]

