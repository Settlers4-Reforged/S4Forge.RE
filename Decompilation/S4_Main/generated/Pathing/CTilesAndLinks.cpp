#if FALSE
#include "CTilesAndLinks.h"

// Definitions for class CTilesAndLinks

// address=[0x15e5000]
// Decompiled from void CTilesAndLinks::InitTiles()
void __cdecl CTilesAndLinks::InitTiles(void) {
  
  struct CLinkList *v0; // eax

  v0 = CLinks::LinkList(0);
  CTilesEx::InitTiles(v0);
}


// address=[0x15e5020]
// Decompiled from int __cdecl CTilesAndLinks::MoveLinkList(int _iDstLinksId, int _iSrcLinksId)
int __cdecl CTilesAndLinks::MoveLinkList(int _iDstLinksId, int _iSrcLinksId) {
  
  CLink *v2; // eax
  CLink *v3; // eax
  int v4; // esi
  int v5; // eax
  int v7; // [esp+8h] [ebp-10h]
  CLinkList *v8; // [esp+Ch] [ebp-Ch]
  struct CLinkList *v9; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  if ( _iDstLinksId >= _iSrcLinksId
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1127, "_iDstLinksId < _iSrcLinksId") == 1 )
  {
    __debugbreak();
  }
  if ( (_iDstLinksId & 1) != 0
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1128, "(_iDstLinksId & 1) == 0") == 1 )
  {
    __debugbreak();
  }
  if ( (_iSrcLinksId & 1) != 0
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1129, "(_iSrcLinksId & 1) == 0") == 1 )
  {
    __debugbreak();
  }
  v2 = CLinks::Link(_iDstLinksId);
  if ( !CLink::Unused(v2)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1130, "Link(_iDstLinksId).Unused()") == 1 )
  {
    __debugbreak();
  }
  v3 = CLinks::Link(_iSrcLinksId);
  if ( !CLink::IsHeader(v3)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1131, "Link(_iSrcLinksId).IsHeader()") == 1 )
  {
    __debugbreak();
  }
  v8 = CLinks::LinkList(_iDstLinksId);
  v9 = CLinks::LinkList(_iSrcLinksId);
  v4 = CLinkList::Size(v9);
  v7 = v4 + (CLinkList::Size(v9) & 1) + 2;
  for ( i = 0; i < v7 >> 1; ++i )
  {
    v8[i] = v9[i];
    *((_DWORD *)v9 + i) = -16711936;
  }
  v5 = CLinkList::OwnerTileId(v8);
  CTile::SetLinkList(&CTiles::m_cTiles[v5], v8);
  return v7;
}


// address=[0x15e51c0]
// Decompiled from void __cdecl CTilesAndLinks::LinksGarbageCollection(int a1)
void __cdecl CTilesAndLinks::LinksGarbageCollection(int a1) {
  
  CLink *v1; // eax
  CLink *v2; // eax
  CLink *v3; // eax
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
  int v20; // [esp+4h] [ebp-30h]
  int v21; // [esp+8h] [ebp-2Ch]
  int v22; // [esp+Ch] [ebp-28h]
  int v23; // [esp+10h] [ebp-24h]
  int iNextUsedLinksId; // [esp+18h] [ebp-1Ch]
  int m; // [esp+1Ch] [ebp-18h]
  int k; // [esp+20h] [ebp-14h]
  int j; // [esp+24h] [ebp-10h]
  int i; // [esp+28h] [ebp-Ch]
  int iLastHeaderLinksId; // [esp+2Ch] [ebp-8h]
  int v30; // [esp+30h] [ebp-4h]

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
  while ( 1 )
  {
    v21 = a1--;
    if ( v21 < 0 )
      break;
    for ( i = CLinks::m_iMaxUsedLinksId; ; i -= 2 )
    {
      v3 = CLinks::Link(i - 2);
      if ( !CLink::Unused(v3) )
        break;
    }
    CLinks::m_iMaxUsedLinksId = i;
    if ( i <= 2 )
      return;
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
    v4 = CLinks::Link(CLinks::m_iMaxUsedLinksId - 2);
    if ( !CLink::Used(v4)
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1195, "Link(m_iMaxUsedLinksId - 2).Used()") == 1 )
    {
      __debugbreak();
    }
    v5 = CLinks::Link(CLinks::m_iMaxUsedLinksId);
    if ( CLink::Used(v5)
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1196, "!Link(m_iMaxUsedLinksId).Used()") == 1 )
    {
      __debugbreak();
    }
    for ( j = CLinks::m_iMinFreeLinksId; ; j += 2 )
    {
      v6 = CLinks::Link(j);
      if ( !CLink::Used(v6) )
        break;
    }
    CLinks::m_iMinFreeLinksId = j;
    if ( j >= CLinks::m_iMaxUsedLinksId )
      return;
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
    v7 = CLinks::Link(CLinks::m_iMinFreeLinksId - 2);
    if ( !CLink::Used(v7)
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1219, "Link(m_iMinFreeLinksId - 2).Used()") == 1 )
    {
      __debugbreak();
    }
    v8 = CLinks::Link(CLinks::m_iMinFreeLinksId);
    if ( CLink::Used(v8)
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1220, "!Link(m_iMinFreeLinksId).Used()") == 1 )
    {
      __debugbreak();
    }
    if ( CLinks::m_iMinFreeLinksId > CLinks::m_iMaxUsedLinksId
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1222, "m_iMinFreeLinksId <= m_iMaxUsedLinksId") == 1 )
    {
      __debugbreak();
    }
    for ( iLastHeaderLinksId = CLinks::m_iMaxUsedLinksId - 2; ; iLastHeaderLinksId -= 2 )
    {
      v9 = CLinks::Link(iLastHeaderLinksId);
      if ( CLink::IsHeader(v9) )
        break;
    }
    if ( iLastHeaderLinksId < 2
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1233, "iLastHeaderLinksId >= LINK_FIRST_REAL") == 1 )
    {
      __debugbreak();
    }
    v30 = CLinks::m_iMinFreeLinksId;
    v23 = CLinks::m_iMinFreeLinksId + CLinks::m_iMaxUsedLinksId - iLastHeaderLinksId;
    while ( 1 )
    {
      v10 = CLinks::Link(v30);
      if ( ((v30 < v23) & CLink::Unused(v10)) == 0 )
        break;
      v30 += 2;
    }
    if ( v30 < v23 )
      break;
    v22 = CTilesAndLinks::MoveLinkList(CLinks::m_iMinFreeLinksId, iLastHeaderLinksId);
    CLinks::m_iMinFreeLinksId += v22;
    CLinks::m_iMaxUsedLinksId -= v22;
    v11 = CLinks::Link(CLinks::m_iMaxUsedLinksId);
    if ( CLink::Used(v11)
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1259, "!Link(m_iMaxUsedLinksId).Used()") == 1 )
    {
      __debugbreak();
    }
  }
  while ( 1 )
  {
    v20 = a1--;
    if ( v20 < 0 )
      break;
    for ( k = CLinks::m_iMaxUsedLinksId; ; k -= 2 )
    {
      v12 = CLinks::Link(k - 2);
      if ( !CLink::Unused(v12) )
        break;
    }
    CLinks::m_iMaxUsedLinksId = k;
    if ( k <= 2 )
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
    v13 = CLinks::Link(CLinks::m_iMaxUsedLinksId - 2);
    if ( !CLink::Used(v13)
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1288, "Link(m_iMaxUsedLinksId - 2).Used()") == 1 )
    {
      __debugbreak();
    }
    v14 = CLinks::Link(CLinks::m_iMaxUsedLinksId);
    if ( CLink::Used(v14)
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1289, "!Link(m_iMaxUsedLinksId).Used()") == 1 )
    {
      __debugbreak();
    }
    for ( m = CLinks::m_iMinFreeLinksId; ; m += 2 )
    {
      v15 = CLinks::Link(m);
      if ( !CLink::Used(v15) )
        break;
    }
    CLinks::m_iMinFreeLinksId = m;
    if ( m >= CLinks::m_iMaxUsedLinksId )
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
    v16 = CLinks::Link(CLinks::m_iMinFreeLinksId - 2);
    if ( !CLink::Used(v16)
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1312, "Link(m_iMinFreeLinksId - 2).Used()") == 1 )
    {
      __debugbreak();
    }
    v17 = CLinks::Link(CLinks::m_iMinFreeLinksId);
    if ( CLink::Used(v17)
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1313, "!Link(m_iMinFreeLinksId).Used()") == 1 )
    {
      __debugbreak();
    }
    if ( CLinks::m_iMinFreeLinksId > CLinks::m_iMaxUsedLinksId
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1315, "m_iMinFreeLinksId <= m_iMaxUsedLinksId") == 1 )
    {
      __debugbreak();
    }
    for ( iNextUsedLinksId = CLinks::m_iMinFreeLinksId; ; iNextUsedLinksId += 2 )
    {
      v18 = CLinks::Link(iNextUsedLinksId);
      if ( !CLink::Unused(v18) )
        break;
    }
    v19 = CLinks::Link(iNextUsedLinksId);
    if ( !CLink::IsHeader(v19)
      && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1326, "Link(iNextUsedLinksId).IsHeader()") == 1 )
    {
      __debugbreak();
    }
    CLinks::m_iMinFreeLinksId += CTilesAndLinks::MoveLinkList(CLinks::m_iMinFreeLinksId, iNextUsedLinksId);
  }
}


// address=[0x15e5ac0]
// Decompiled from struct CLinkList *__cdecl CTilesAndLinks::PushLinksUndef(int a1)
class CLinkList & __cdecl CTilesAndLinks::PushLinksUndef(int a1) {
  
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
// Decompiled from CLinkList *__cdecl CTilesAndLinks::PushLinks(const struct CIntLinkList *a1)
class CLinkList & __cdecl CTilesAndLinks::PushLinks(class CIntLinkList const & a1) {
  
  int v1; // eax
  CLinkList *v3; // [esp+0h] [ebp-4h]

  v1 = CIntLinkList::Size(a1);
  v3 = CTilesAndLinks::PushLinksUndef(v1);
  CLinkList::operator=(v3, a1);
  CLinks::CheckLinksInfo();
  return v3;
}


// address=[0x15e5ba0]
// Decompiled from void __cdecl CTilesAndLinks::AddLink(int _iOwnerTileId, int _iLinkTileId)
void __cdecl CTilesAndLinks::AddLink(int _iOwnerTileId, int _iLinkTileId) {
  
  CTile *v2; // eax
  CLink *v3; // eax
  CTile *v4; // eax
  struct CLinkList *v5; // [esp+0h] [ebp-Ch]
  int v6; // [esp+4h] [ebp-8h]
  struct CLinkList *pLinkList; // [esp+8h] [ebp-4h]

  if ( !CTilesEx::IsUsedRealTile(_iOwnerTileId)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1400, "IsUsedRealTile(_iOwnerTileId)") == 1 )
  {
    __debugbreak();
  }
  if ( _iOwnerTileId == _iLinkTileId
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1401, "_iOwnerTileId != _iLinkTileId") == 1 )
  {
    __debugbreak();
  }
  v2 = CTiles::TileEx(_iOwnerTileId);
  pLinkList = CTile::LinkList(v2);
  if ( !(unsigned __int8)CLinks::IsValidUsedLinkList(pLinkList)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1405, "IsValidUsedLinkList(*pLinkList)") == 1 )
  {
    __debugbreak();
  }
  if ( CLinkList::SearchForLinkTileId(pLinkList, _iLinkTileId) )
  {
    CTrace::Print("CTilesAndLinks::AddLink: TileEx %i found in link list 0x%08x!", _iLinkTileId, pLinkList);
    CLinkList::DbgPrint(pLinkList);
  }
  else
  {
    v6 = CLinkList::Size(pLinkList);
    v3 = CLinkList::Link(pLinkList, v6);
    if ( !CLink::Unused(v3) )
    {
      v5 = pLinkList;
      pLinkList = CTilesAndLinks::PushLinksUndef(v6 + 1);
      if ( !CLinks::IsValidRealLinkList(pLinkList)
        && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1417, "IsValidRealLinkList(*pLinkList)") == 1 )
      {
        __debugbreak();
      }
      v4 = CTiles::TileEx(_iOwnerTileId);
      CTile::SetLinkList(v4, pLinkList);
      CLinkList::operator=(pLinkList, v5);
      CLinks::LinkListMarkAsUnused(v5);
    }
    CLinks::LinkListPushLinkTileId(pLinkList, _iLinkTileId);
    CLinks::CheckLinksInfo();
  }
}


// address=[0x15e5d40]
// Decompiled from char __cdecl CTilesAndLinks::DeleteLink(int a1, int a2)
void __cdecl CTilesAndLinks::DeleteLink(int a1, int a2) {
  
  CTile *v2; // eax
  struct CLinkList *v4; // [esp+0h] [ebp-4h]

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
  v4 = CTile::LinkList(v2);
  if ( !CLinks::IsValidUsedLinkList(v4)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1491, "IsValidUsedLinkList(rLinkList)") == 1 )
  {
    __debugbreak();
  }
  return CLinks::LinkListRemoveLinkTileId(v4, a2);
}


// address=[0x15e5e30]
// Decompiled from void __cdecl CTilesAndLinks::ReplaceLink(int a1, int a2, int a3)
void __cdecl CTilesAndLinks::ReplaceLink(int a1, int a2, int a3) {
  
  CTile *v3; // eax
  CLinkList *v4; // [esp+0h] [ebp-4h]

  if ( !CTilesEx::IsUsedRealTile(a1)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1454, "IsUsedRealTile(_iOwnerTileId)") == 1 )
  {
    __debugbreak();
  }
  v3 = CTiles::TileEx(a1);
  v4 = CTile::LinkList(v3);
  if ( !CLinks::LinkListReplaceLink(v4, a2, a3) )
  {
    CTrace::Print("CTilesAndLinks::ReplaceLink(): Old tile %i not found in link list 0x%08x!", a2, v4);
    CLinkList::DbgPrint(v4);
    if ( BBSupportDbgReport(
           1,
           "Pathing\\TilesAndLinks.cpp",
           1467,
           "CTilesAndLinks::ReplaceLink(): OldLinkTileId not found [may be ignored]!") == 1 )
      __debugbreak();
    CTilesAndLinks::AddLink(a1, a3);
  }
}


// address=[0x15e5ef0]
// Decompiled from void __cdecl CTilesAndLinks::AddLinkList(struct CLinkList *a1)
void __cdecl CTilesAndLinks::AddLinkList(class CLinkList const & a1) {
  
  const unsigned __int16 *v1; // eax
  int v2; // [esp+0h] [ebp-Ch]
  int v3; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  if ( !CLinks::IsValidUsedLinkList(a1)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1528, "IsValidUsedLinkList(_rLinkList)") == 1 )
  {
    __debugbreak();
  }
  v3 = CLinkList::Size(a1);
  v2 = CLinkList::OwnerTileId(a1);
  for ( i = 0; i < v3; ++i )
  {
    v1 = CLinkList::operator[](a1, i);
    CTilesAndLinks::AddLink(*v1, v2);
  }
}


// address=[0x15e5f80]
// Decompiled from void __cdecl CTilesAndLinks::DeleteLinkList(struct CLinkList *a1)
void __cdecl CTilesAndLinks::DeleteLinkList(class CLinkList & a1) {
  
  const unsigned __int16 *v1; // eax
  int v2; // [esp+0h] [ebp-Ch]
  int v3; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  if ( !CLinks::IsValidUsedLinkList(a1)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1506, "IsValidUsedLinkList(_rLinkList)") == 1 )
  {
    __debugbreak();
  }
  v3 = CLinkList::Size(a1);
  v2 = CLinkList::OwnerTileId(a1);
  for ( i = 0; i < v3; ++i )
  {
    v1 = CLinkList::operator[](a1, i);
    CTilesAndLinks::DeleteLink(*v1, v2);
  }
  CLinks::LinkListMarkAsUnused(a1);
}


// address=[0x15e6020]
// Decompiled from void __cdecl CTilesAndLinks::DeleteTile(int *a1)
void __cdecl CTilesAndLinks::DeleteTile(int a1) {
  
  CTile *v1; // eax
  struct CLinkList *v2; // eax

  if ( CTilesEx::IsUsedRealTile((int)a1) )
  {
    v1 = CTiles::TileEx((int)a1);
    v2 = CTile::LinkList(v1);
    CTilesAndLinks::DeleteLinkList(v2);
    CTilesEx::DeleteTile((int)a1);
  }
  else if ( !"DeleteTile(): Not a used real tile!"
         && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1551, "\"DeleteTile(): Not a used real tile!\"") == 1 )
  {
    __debugbreak();
  }
}


// address=[0x15e6090]
// Decompiled from void __cdecl CTilesAndLinks::MergeTileLinkLists(int _iDstTileId, int _iSrcTileId)
void __cdecl CTilesAndLinks::MergeTileLinkLists(int _iDstTileId, int _iSrcTileId) {
  
  CTile *v2; // eax
  int i; // eax
  CTile *v4; // eax
  CLinkList *v5; // eax
  struct CLinkList *v6; // [esp+8h] [ebp-Ch]
  int v7; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h]

  if ( _iDstTileId == _iSrcTileId
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1575, "_iDstTileId != _iSrcTileId") == 1 )
  {
    __debugbreak();
  }
  v2 = CTiles::TileEx(_iSrcTileId);
  v6 = CTile::LinkList(v2);
  v8 = 0;
  for ( i = CLinkList::Size(v6); v8 < i; i = CLinkList::Size(v6) )
  {
    v7 = *CLinkList::operator[](v6, v8);
    v4 = CTiles::TileEx(_iDstTileId);
    v5 = CTile::LinkList(v4);
    if ( CLinkList::SearchForLinkTileId(v5, v7) == 0 && v7 != _iDstTileId )
    {
      CTilesAndLinks::AddLink(_iDstTileId, v7);
      CTilesAndLinks::ReplaceLink(v7, _iSrcTileId, _iDstTileId);
    }
    ++v8;
  }
}


#endif // Already implemented
