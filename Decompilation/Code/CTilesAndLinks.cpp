#include "CTilesAndLinks.h"

// Definitions for class CTilesAndLinks

// address=[0x15e5000]
// Decompiled from int **CTilesAndLinks::InitTiles()
static void __cdecl CTilesAndLinks::InitTiles(void) {
  
  struct CLinkList *v0; // eax

  v0 = CLinks::LinkList(0);
  return CTilesEx::InitTiles(v0);
}


// address=[0x15e5020]
// Decompiled from int __cdecl CTilesAndLinks::MoveLinkList(int a1, int a2)
static int __cdecl CTilesAndLinks::MoveLinkList(int,int) {
  
  CLink *v2; // eax
  CLink *v3; // eax
  int v4; // esi
  int v5; // eax
  int v7; // [esp+8h] [ebp-10h]
  CLinkList *v8; // [esp+Ch] [ebp-Ch]
  unsigned __int8 *v9; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  if ( a1 >= a2 && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1127, "_iDstLinksId < _iSrcLinksId") == 1 )
    __debugbreak();
  if ( (a1 & 1) != 0 && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1128, "(_iDstLinksId & 1) == 0") == 1 )
    __debugbreak();
  if ( (a2 & 1) != 0 && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1129, "(_iSrcLinksId & 1) == 0") == 1 )
    __debugbreak();
  v2 = CLinks::Link(a1);
  if ( !CLink::Unused(v2)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1130, "Link(_iDstLinksId).Unused()") == 1 )
  {
    __debugbreak();
  }
  v3 = CLinks::Link(a2);
  if ( !CLink::IsHeader(v3)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1131, "Link(_iSrcLinksId).IsHeader()") == 1 )
  {
    __debugbreak();
  }
  v8 = CLinks::LinkList(a1);
  v9 = (unsigned __int8 *)CLinks::LinkList(a2);
  v4 = CLinkList::Size(v9);
  v7 = v4 + (CLinkList::Size(v9) & 1) + 2;
  for ( i = 0; i < v7 >> 1; ++i )
  {
    *((_DWORD *)v8 + i) = *(_DWORD *)&v9[4 * i];
    *(_DWORD *)&v9[4 * i] = -16711936;
  }
  v5 = CLinkList::OwnerTileId(v8);
  CTile::SetLinkList(&CTiles::m_cTiles[v5], v8);
  return v7;
}


// address=[0x15e51c0]
// Decompiled from char __cdecl CTilesAndLinks::LinksGarbageCollection(int a1)
static void __cdecl CTilesAndLinks::LinksGarbageCollection(int) {
  
  CLink *v1; // eax
  CLink *v2; // eax
  int v3; // eax
  CLink *v4; // eax
  CLink *v5; // eax
  CLink *v6; // eax
  CLink *v7; // eax
  CLink *v8; // eax
  CLink *v9; // eax
  CLink *v10; // eax
  CLink *v11; // eax
  CLink *v12; // eax
  CLink *v13; // eax
  CLink *v14; // eax
  CLink *v15; // eax
  CLink *v16; // eax
  CLink *v17; // eax
  CLink *v18; // eax
  CLink *v19; // eax
  CLink *v20; // eax
  int v22; // [esp+4h] [ebp-30h]
  int v23; // [esp+8h] [ebp-2Ch]
  int v24; // [esp+Ch] [ebp-28h]
  int v25; // [esp+10h] [ebp-24h]
  int ii; // [esp+18h] [ebp-1Ch]
  int n; // [esp+1Ch] [ebp-18h]
  int m; // [esp+20h] [ebp-14h]
  int j; // [esp+24h] [ebp-10h]
  int i; // [esp+28h] [ebp-Ch]
  int k; // [esp+2Ch] [ebp-8h]
  int v32; // [esp+30h] [ebp-4h]

  if ( CLinks::m_iMaxUsedLinksId < 2
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1157, "m_iMaxUsedLinksId >= LINK_FIRST_REAL") == 1 )
  {
    __debugbreak();
  }
  if ( CLinks::m_iMaxUsedLinksId > 262142
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1158, "m_iMaxUsedLinksId <= (LINK_LAST_REAL + 1)") == 1 )
  {
    __debugbreak();
  }
  if ( (CLinks::m_iMaxUsedLinksId & 1) != 0
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1159, "(m_iMaxUsedLinksId & 1) == 0") == 1 )
  {
    __debugbreak();
  }
  v1 = CLinks::Link(CLinks::m_iMaxUsedLinksId);
  if ( CLink::Used(v1)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1160, "!Link(m_iMaxUsedLinksId).Used()") == 1 )
  {
    __debugbreak();
  }
  if ( CLinks::m_iMinFreeLinksId < 2
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1162, "m_iMinFreeLinksId >= LINK_FIRST_REAL") == 1 )
  {
    __debugbreak();
  }
  if ( CLinks::m_iMinFreeLinksId > 262142
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1163, "m_iMinFreeLinksId <= (LINK_LAST_REAL + 1)") == 1 )
  {
    __debugbreak();
  }
  if ( (CLinks::m_iMinFreeLinksId & 1) != 0
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1164, "(m_iMinFreeLinksId & 1) == 0") == 1 )
  {
    __debugbreak();
  }
  v2 = CLinks::Link(CLinks::m_iMinFreeLinksId - 2);
  if ( !CLink::Used(v2)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1165, "Link(m_iMinFreeLinksId - 2).Used()") == 1 )
  {
    __debugbreak();
  }
  if ( CLinks::m_iMinFreeLinksId > CLinks::m_iMaxUsedLinksId
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1167, "m_iMinFreeLinksId <= m_iMaxUsedLinksId") == 1 )
  {
    __debugbreak();
  }
  for ( LOBYTE(v3) = 0; ; LOBYTE(v3) = 0 )
  {
    v23 = a1--;
    if ( v23 < 0 )
      break;
    for ( i = CLinks::m_iMaxUsedLinksId; ; i -= 2 )
    {
      v4 = CLinks::Link(i - 2);
      LOBYTE(v3) = CLink::Unused(v4);
      if ( !(_BYTE)v3 )
        break;
    }
    CLinks::m_iMaxUsedLinksId = i;
    if ( i <= 2 )
      return v3;
    if ( CLinks::m_iMaxUsedLinksId < 2
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1192, "m_iMaxUsedLinksId >= LINK_FIRST_REAL") == 1 )
    {
      __debugbreak();
    }
    if ( CLinks::m_iMaxUsedLinksId > 262142
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1193, "m_iMaxUsedLinksId <= (LINK_LAST_REAL + 1)") == 1 )
    {
      __debugbreak();
    }
    if ( (CLinks::m_iMaxUsedLinksId & 1) != 0
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1194, "(m_iMaxUsedLinksId & 1) == 0") == 1 )
    {
      __debugbreak();
    }
    v5 = CLinks::Link(CLinks::m_iMaxUsedLinksId - 2);
    if ( !CLink::Used(v5)
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1195, "Link(m_iMaxUsedLinksId - 2).Used()") == 1 )
    {
      __debugbreak();
    }
    v6 = CLinks::Link(CLinks::m_iMaxUsedLinksId);
    if ( CLink::Used(v6)
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1196, "!Link(m_iMaxUsedLinksId).Used()") == 1 )
    {
      __debugbreak();
    }
    for ( j = CLinks::m_iMinFreeLinksId; ; j += 2 )
    {
      v7 = CLinks::Link(j);
      LOBYTE(v3) = CLink::Used(v7);
      if ( !(_BYTE)v3 )
        break;
    }
    CLinks::m_iMinFreeLinksId = j;
    if ( j >= CLinks::m_iMaxUsedLinksId )
      return v3;
    if ( CLinks::m_iMinFreeLinksId < 2
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1216, "m_iMinFreeLinksId >= LINK_FIRST_REAL") == 1 )
    {
      __debugbreak();
    }
    if ( CLinks::m_iMinFreeLinksId > 262142
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1217, "m_iMinFreeLinksId <= (LINK_LAST_REAL + 1)") == 1 )
    {
      __debugbreak();
    }
    if ( (CLinks::m_iMinFreeLinksId & 1) != 0
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1218, "(m_iMinFreeLinksId & 1) == 0") == 1 )
    {
      __debugbreak();
    }
    v8 = CLinks::Link(CLinks::m_iMinFreeLinksId - 2);
    if ( !CLink::Used(v8)
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1219, "Link(m_iMinFreeLinksId - 2).Used()") == 1 )
    {
      __debugbreak();
    }
    v9 = CLinks::Link(CLinks::m_iMinFreeLinksId);
    if ( CLink::Used(v9)
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1220, "!Link(m_iMinFreeLinksId).Used()") == 1 )
    {
      __debugbreak();
    }
    if ( CLinks::m_iMinFreeLinksId > CLinks::m_iMaxUsedLinksId
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1222, "m_iMinFreeLinksId <= m_iMaxUsedLinksId") == 1 )
    {
      __debugbreak();
    }
    for ( k = CLinks::m_iMaxUsedLinksId - 2; ; k -= 2 )
    {
      v10 = CLinks::Link(k);
      if ( CLink::IsHeader(v10) )
        break;
    }
    if ( k < 2
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1233, "iLastHeaderLinksId >= LINK_FIRST_REAL") == 1 )
    {
      __debugbreak();
    }
    v32 = CLinks::m_iMinFreeLinksId;
    v25 = CLinks::m_iMinFreeLinksId + CLinks::m_iMaxUsedLinksId - k;
    while ( 1 )
    {
      v11 = CLinks::Link(v32);
      v3 = (v32 < v25) & CLink::Unused(v11);
      if ( !v3 )
        break;
      v32 += 2;
    }
    if ( v32 < v25 )
      break;
    v24 = CTilesAndLinks::MoveLinkList(CLinks::m_iMinFreeLinksId, k);
    CLinks::m_iMinFreeLinksId += v24;
    CLinks::m_iMaxUsedLinksId -= v24;
    v12 = CLinks::Link(CLinks::m_iMaxUsedLinksId);
    if ( CLink::Used(v12)
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1259, "!Link(m_iMaxUsedLinksId).Used()") == 1 )
    {
      __debugbreak();
    }
  }
  while ( 1 )
  {
    v22 = a1--;
    if ( v22 < 0 )
      break;
    for ( m = CLinks::m_iMaxUsedLinksId; ; m -= 2 )
    {
      v13 = CLinks::Link(m - 2);
      LOBYTE(v3) = CLink::Unused(v13);
      if ( !(_BYTE)v3 )
        break;
    }
    CLinks::m_iMaxUsedLinksId = m;
    if ( m <= 2 )
      break;
    if ( CLinks::m_iMaxUsedLinksId < 2
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1285, "m_iMaxUsedLinksId >= LINK_FIRST_REAL") == 1 )
    {
      __debugbreak();
    }
    if ( CLinks::m_iMaxUsedLinksId > 262142
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1286, "m_iMaxUsedLinksId <= (LINK_LAST_REAL + 1)") == 1 )
    {
      __debugbreak();
    }
    if ( (CLinks::m_iMaxUsedLinksId & 1) != 0
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1287, "(m_iMaxUsedLinksId & 1) == 0") == 1 )
    {
      __debugbreak();
    }
    v14 = CLinks::Link(CLinks::m_iMaxUsedLinksId - 2);
    if ( !CLink::Used(v14)
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1288, "Link(m_iMaxUsedLinksId - 2).Used()") == 1 )
    {
      __debugbreak();
    }
    v15 = CLinks::Link(CLinks::m_iMaxUsedLinksId);
    if ( CLink::Used(v15)
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1289, "!Link(m_iMaxUsedLinksId).Used()") == 1 )
    {
      __debugbreak();
    }
    for ( n = CLinks::m_iMinFreeLinksId; ; n += 2 )
    {
      v16 = CLinks::Link(n);
      LOBYTE(v3) = CLink::Used(v16);
      if ( !(_BYTE)v3 )
        break;
    }
    CLinks::m_iMinFreeLinksId = n;
    if ( n >= CLinks::m_iMaxUsedLinksId )
      break;
    if ( CLinks::m_iMinFreeLinksId < 2
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1309, "m_iMinFreeLinksId >= LINK_FIRST_REAL") == 1 )
    {
      __debugbreak();
    }
    if ( CLinks::m_iMinFreeLinksId > 262142
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1310, "m_iMinFreeLinksId <= (LINK_LAST_REAL + 1)") == 1 )
    {
      __debugbreak();
    }
    if ( (CLinks::m_iMinFreeLinksId & 1) != 0
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1311, "(m_iMinFreeLinksId & 1) == 0") == 1 )
    {
      __debugbreak();
    }
    v17 = CLinks::Link(CLinks::m_iMinFreeLinksId - 2);
    if ( !CLink::Used(v17)
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1312, "Link(m_iMinFreeLinksId - 2).Used()") == 1 )
    {
      __debugbreak();
    }
    v18 = CLinks::Link(CLinks::m_iMinFreeLinksId);
    if ( CLink::Used(v18)
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1313, "!Link(m_iMinFreeLinksId).Used()") == 1 )
    {
      __debugbreak();
    }
    if ( CLinks::m_iMinFreeLinksId > CLinks::m_iMaxUsedLinksId
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1315, "m_iMinFreeLinksId <= m_iMaxUsedLinksId") == 1 )
    {
      __debugbreak();
    }
    for ( ii = CLinks::m_iMinFreeLinksId; ; ii += 2 )
    {
      v19 = CLinks::Link(ii);
      if ( !CLink::Unused(v19) )
        break;
    }
    v20 = CLinks::Link(ii);
    if ( !CLink::IsHeader(v20)
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1326, "Link(iNextUsedLinksId).IsHeader()") == 1 )
    {
      __debugbreak();
    }
    v3 = CTilesAndLinks::MoveLinkList(CLinks::m_iMinFreeLinksId, ii) + CLinks::m_iMinFreeLinksId;
    CLinks::m_iMinFreeLinksId = v3;
  }
  return v3;
}


// address=[0x15e5ac0]
// Decompiled from struct CLinkList *__cdecl CTilesAndLinks::PushLinksUndef(int a1)
static class CLinkList & __cdecl CTilesAndLinks::PushLinksUndef(int) {
  
  int v2; // [esp+0h] [ebp-4h]

  v2 = CLinks::PushLinksUndef(a1);
  if ( v2 )
    return CLinks::LinkList(v2);
  CTilesAndLinks::LinksGarbageCollection(16);
  if ( CLinks::PushLinksUndef(a1) )
    CTilesAndLinks::LinksGarbageCollection(0x7FFFFFFF);
  v2 = CLinks::PushLinksUndef(a1);
  if ( v2 )
    return CLinks::LinkList(v2);
  if ( BBSupportDbgReport(1, "Pathing\\TilesAndLinks.cpp", 1368, "Tiling: Out of links!") == 1 )
    __debugbreak();
  return CLinks::LinkList(0);
}


// address=[0x15e5b70]
// Decompiled from struct CLinkList *__cdecl CTilesAndLinks::PushLinks(const struct CIntLinkList *a1)
static class CLinkList & __cdecl CTilesAndLinks::PushLinks(class CIntLinkList const &) {
  
  int v1; // eax
  struct CLinkList *v3; // [esp+0h] [ebp-4h]

  v1 = CIntLinkList::Size(a1);
  v3 = CTilesAndLinks::PushLinksUndef(v1);
  CLinkList::operator=(v3, a1);
  CLinks::CheckLinksInfo();
  return v3;
}


// address=[0x15e5ba0]
// Decompiled from int __cdecl CTilesAndLinks::AddLink(int a1, int a2)
static void __cdecl CTilesAndLinks::AddLink(int,int) {
  
  int **v2; // eax
  char *v3; // eax
  int **v4; // eax
  unsigned __int8 *v6; // [esp+0h] [ebp-Ch]
  int v7; // [esp+4h] [ebp-8h]
  const struct CLinkList *v8; // [esp+8h] [ebp-4h]

  if ( !CTilesEx::IsUsedRealTile(a1)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1400, "IsUsedRealTile(_iOwnerTileId)") == 1 )
  {
    __debugbreak();
  }
  if ( a1 == a2 && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1401, "_iOwnerTileId != _iLinkTileId") == 1 )
    __debugbreak();
  v2 = CTiles::TileEx(a1);
  v8 = (const struct CLinkList *)CTile::LinkList(v2);
  if ( !(unsigned __int8)CLinks::IsValidUsedLinkList(v8)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1405, "IsValidUsedLinkList(*pLinkList)") == 1 )
  {
    __debugbreak();
  }
  if ( CLinkList::SearchForLinkTileId(v8, a2) )
  {
    CTrace::Print("CTilesAndLinks::AddLink: TileEx %i found in link list 0x%08x!", a2, v8);
    return CLinkList::DbgPrint(v8);
  }
  else
  {
    v7 = CLinkList::Size((unsigned __int8 *)v8);
    v3 = CLinkList::Link(v8, v7);
    if ( !CLink::Unused((CLink *)v3) )
    {
      v6 = (unsigned __int8 *)v8;
      v8 = CTilesAndLinks::PushLinksUndef(v7 + 1);
      if ( !CLinks::IsValidRealLinkList(v8)
        && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1417, "IsValidRealLinkList(*pLinkList)") == 1 )
      {
        __debugbreak();
      }
      v4 = CTiles::TileEx(a1);
      CTile::SetLinkList((CTile *)v4, v8);
      CLinkList::operator=(v8, v6);
      CLinks::LinkListMarkAsUnused((struct CLinkList *)v6);
    }
    CLinks::LinkListPushLinkTileId(v8, a2);
    return CLinks::CheckLinksInfo();
  }
}


// address=[0x15e5d40]
// Decompiled from char __cdecl CTilesAndLinks::DeleteLink(int a1, int a2)
static void __cdecl CTilesAndLinks::DeleteLink(int,int) {
  
  int **v2; // eax
  const struct CLinkList *v4; // [esp+0h] [ebp-4h]

  if ( !CTilesEx::IsUsedRealTile(a1)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1484, "IsUsedRealTile(_iOwnerTileId)") == 1 )
  {
    __debugbreak();
  }
  if ( !CTiles::IsValidRealTile(a2)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1485, "IsValidRealTile(_iLinkTileId)") == 1 )
  {
    __debugbreak();
  }
  if ( a1 == a2 && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1487, "_iOwnerTileId != _iLinkTileId") == 1 )
    __debugbreak();
  v2 = CTiles::TileEx(a1);
  v4 = (const struct CLinkList *)CTile::LinkList(v2);
  if ( !(unsigned __int8)CLinks::IsValidUsedLinkList(v4)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1491, "IsValidUsedLinkList(rLinkList)") == 1 )
  {
    __debugbreak();
  }
  return CLinks::LinkListRemoveLinkTileId(v4, a2);
}


// address=[0x15e5e30]
// Decompiled from char __cdecl CTilesAndLinks::ReplaceLink(int a1, int a2, int a3)
static void __cdecl CTilesAndLinks::ReplaceLink(int,int,int) {
  
  int **v3; // eax
  char result; // al
  struct CLinkList *v5; // [esp+0h] [ebp-4h]

  if ( !CTilesEx::IsUsedRealTile(a1)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1454, "IsUsedRealTile(_iOwnerTileId)") == 1 )
  {
    __debugbreak();
  }
  v3 = CTiles::TileEx(a1);
  v5 = (struct CLinkList *)CTile::LinkList(v3);
  result = CLinks::LinkListReplaceLink(v5, a2, a3);
  if ( result )
    return result;
  CTrace::Print("CTilesAndLinks::ReplaceLink(): Old tile %i not found in link list 0x%08x!", a2, v5);
  CLinkList::DbgPrint(v5);
  if ( BBSupportDbgReport(
         1,
         "Pathing\\TilesAndLinks.cpp",
         1467,
         "CTilesAndLinks::ReplaceLink(): OldLinkTileId not found [may be ignored]!") == 1 )
    __debugbreak();
  return CTilesAndLinks::AddLink(a1, a3);
}


// address=[0x15e5ef0]
// Decompiled from int __cdecl CTilesAndLinks::AddLinkList(const struct CLinkList *a1)
static void __cdecl CTilesAndLinks::AddLinkList(class CLinkList const &) {
  
  int result; // eax
  unsigned __int16 *v2; // eax
  int v3; // [esp+0h] [ebp-Ch]
  int v4; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  if ( !(unsigned __int8)CLinks::IsValidUsedLinkList(a1)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1528, "IsValidUsedLinkList(_rLinkList)") == 1 )
  {
    __debugbreak();
  }
  v4 = CLinkList::Size((unsigned __int8 *)a1);
  result = CLinkList::OwnerTileId(a1);
  v3 = result;
  for ( i = 0; i < v4; ++i )
  {
    v2 = (unsigned __int16 *)CLinkList::operator[](a1, i);
    CTilesAndLinks::AddLink(*v2, v3);
    result = i + 1;
  }
  return result;
}


// address=[0x15e5f80]
// Decompiled from int __cdecl CTilesAndLinks::DeleteLinkList(struct CLinkList *a1)
static void __cdecl CTilesAndLinks::DeleteLinkList(class CLinkList &) {
  
  unsigned __int16 *v1; // eax
  int v3; // [esp+0h] [ebp-Ch]
  int v4; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  if ( !(unsigned __int8)CLinks::IsValidUsedLinkList(a1)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1506, "IsValidUsedLinkList(_rLinkList)") == 1 )
  {
    __debugbreak();
  }
  v4 = CLinkList::Size((unsigned __int8 *)a1);
  v3 = CLinkList::OwnerTileId(a1);
  for ( i = 0; i < v4; ++i )
  {
    v1 = (unsigned __int16 *)CLinkList::operator[](a1, i);
    CTilesAndLinks::DeleteLink(*v1, v3);
  }
  return CLinks::LinkListMarkAsUnused(a1);
}


// address=[0x15e6020]
// Decompiled from int __cdecl CTilesAndLinks::DeleteTile(int *a1)
static void __cdecl CTilesAndLinks::DeleteTile(int) {
  
  int **v2; // eax
  struct CLinkList *v3; // eax

  if ( CTilesEx::IsUsedRealTile((int)a1) )
  {
    v2 = CTiles::TileEx((int)a1);
    v3 = (struct CLinkList *)CTile::LinkList(v2);
    CTilesAndLinks::DeleteLinkList(v3);
    return CTilesEx::DeleteTile(a1);
  }
  else
  {
    if ( !"DeleteTile(): Not a used real tile!"
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1551, "\"DeleteTile(): Not a used real tile!\"") == 1 )
    {
      __debugbreak();
    }
    return 0;
  }
}


// address=[0x15e6090]
// Decompiled from int __cdecl CTilesAndLinks::MergeTileLinkLists(int a1, int a2)
static void __cdecl CTilesAndLinks::MergeTileLinkLists(int,int) {
  
  int **v2; // eax
  int result; // eax
  int **v4; // eax
  CLinkList *v5; // eax
  unsigned __int8 *v6; // [esp+8h] [ebp-Ch]
  int v7; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h]

  if ( a1 == a2 && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1575, "_iDstTileId != _iSrcTileId") == 1 )
    __debugbreak();
  v2 = CTiles::TileEx(a2);
  v6 = (unsigned __int8 *)CTile::LinkList(v2);
  v8 = 0;
  for ( result = CLinkList::Size(v6); v8 < result; result = CLinkList::Size(v6) )
  {
    v7 = *(unsigned __int16 *)CLinkList::operator[](v6, v8);
    v4 = CTiles::TileEx(a1);
    v5 = (CLinkList *)CTile::LinkList(v4);
    if ( CLinkList::SearchForLinkTileId(v5, v7) == 0 && v7 != a1 )
    {
      CTilesAndLinks::AddLink(a1, v7);
      CTilesAndLinks::ReplaceLink(v7, a2, a1);
    }
    ++v8;
  }
  return result;
}


