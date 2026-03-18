#include "CTilesAndLinks.h"

#include "../Collections/CLinkList.h"

#include "CLinks.h"
#include "CTilesEx.h"
#include "CBB/CBBSupport.h"
#include "Collections/CLink.h"
#include "CTiles.h"
#include "CTile.h"
#include "Collections/CIntLinkList.h"
#include "Debug/CTrace.h"

// Definitions for class CTilesAndLinks

// address=[0x15e5000]
// Decompiled from void CTilesAndLinks::InitTiles()
void __cdecl CTilesAndLinks::InitTiles(void) {
  CTilesEx::InitTiles(CLinks::LinkList(0));
}


// address=[0x15e5020]
// Decompiled from int __cdecl CTilesAndLinks::MoveLinkList(int _iDstLinksId, int _iSrcLinksId)
int __cdecl CTilesAndLinks::MoveLinkList(int _iDstLinksId, int _iSrcLinksId) {
  if(_iDstLinksId >= _iSrcLinksId
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1127, "_iDstLinksId < _iSrcLinksId") == 1) {
    __debugbreak();
  }
  if((_iDstLinksId & 1) != 0
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1128, "(_iDstLinksId & 1) == 0") == 1) {
    __debugbreak();
  }
  if((_iSrcLinksId & 1) != 0
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1129, "(_iSrcLinksId & 1) == 0") == 1) {
    __debugbreak();
  }

  if(!CLinks::Link(_iDstLinksId).Unused()
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1130, "Link(_iDstLinksId).Unused()") == 1) {
    __debugbreak();
  }

  if(!CLinks::Link(_iSrcLinksId).IsHeader()
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1131, "Link(_iSrcLinksId).IsHeader()") == 1) {
    __debugbreak();
  }
  CLinkList &rDestLinks = CLinks::LinkList(_iDstLinksId);
  CLinkList &rSrcLinks = CLinks::LinkList(_iSrcLinksId);
  int        v4 = rSrcLinks.Size();
  int        v7 = v4 + (rSrcLinks.Size() & 1) + 2;
  for(int i = 0; i < v7; ++i) {
    rDestLinks.m_uLinkTileIds[i] = rSrcLinks.m_uLinkTileIds[i];
    rSrcLinks.m_uLinkTileIds[i].m_uData = 0xFF00;
    // v8[i] = v9[i];
    // *((_DWORD *) v9 + i) = 0xFF00FF00;
  }

  CTiles::m_cTiles[rDestLinks.OwnerTileId()].SetLinkList(rDestLinks);
  return v7;
}


// address=[0x15e51c0]
// Decompiled from void __cdecl CTilesAndLinks::LinksGarbageCollection(int a1)
void __cdecl CTilesAndLinks::LinksGarbageCollection(int a1) {
  int iNextUsedLinksId; // [esp+18h] [ebp-1Ch]
  int m; // [esp+1Ch] [ebp-18h]
  int k; // [esp+20h] [ebp-14h]
  int j; // [esp+24h] [ebp-10h]
  int i; // [esp+28h] [ebp-Ch]
  int iLastHeaderLinksId; // [esp+2Ch] [ebp-8h]
  // [esp+30h] [ebp-4h]

  if(CLinks::m_iMaxUsedLinksId < 2
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1157, "m_iMaxUsedLinksId >= LINK_FIRST_REAL") == 1) {
    __debugbreak();
  }
  if(CLinks::m_iMaxUsedLinksId > 262142
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1158, "m_iMaxUsedLinksId <= (LINK_LAST_REAL + 1)") == 1) {
    __debugbreak();
  }
  if((CLinks::m_iMaxUsedLinksId & 1) != 0
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1159, "(m_iMaxUsedLinksId & 1) == 0") == 1) {
    __debugbreak();
  }
  if(CLinks::Link(CLinks::m_iMaxUsedLinksId).Used()
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1160, "!Link(m_iMaxUsedLinksId).Used()") == 1) {
    __debugbreak();
  }
  if(CLinks::m_iMinFreeLinksId < 2
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1162, "m_iMinFreeLinksId >= LINK_FIRST_REAL") == 1) {
    __debugbreak();
  }
  if(CLinks::m_iMinFreeLinksId > 262142
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1163, "m_iMinFreeLinksId <= (LINK_LAST_REAL + 1)") == 1) {
    __debugbreak();
  }
  if((CLinks::m_iMinFreeLinksId & 1) != 0
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1164, "(m_iMinFreeLinksId & 1) == 0") == 1) {
    __debugbreak();
  }
  if(!CLinks::Link(CLinks::m_iMinFreeLinksId - 2).Used()
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1165, "Link(m_iMinFreeLinksId - 2).Used()") == 1) {
    __debugbreak();
  }
  if(CLinks::m_iMinFreeLinksId > CLinks::m_iMaxUsedLinksId
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1167, "m_iMinFreeLinksId <= m_iMaxUsedLinksId") == 1) {
    __debugbreak();
  }
  while(1) {
    int v21 = a1--;
    if(v21 < 0)
      break;
    for(i = CLinks::m_iMaxUsedLinksId; ; i -= 2) {
      if(!CLinks::Link(i - 2).Unused())
        break;
    }
    CLinks::m_iMaxUsedLinksId = i;
    if(i <= 2)
      return;
    if(CLinks::m_iMaxUsedLinksId < 2
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1192, "m_iMaxUsedLinksId >= LINK_FIRST_REAL") == 1) {
      __debugbreak();
    }
    if(CLinks::m_iMaxUsedLinksId > 262142
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1193, "m_iMaxUsedLinksId <= (LINK_LAST_REAL + 1)") == 1) {
      __debugbreak();
    }
    if((CLinks::m_iMaxUsedLinksId & 1) != 0
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1194, "(m_iMaxUsedLinksId & 1) == 0") == 1) {
      __debugbreak();
    }
    if(!CLinks::Link(CLinks::m_iMaxUsedLinksId - 2).Used()
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1195, "Link(m_iMaxUsedLinksId - 2).Used()") == 1) {
      __debugbreak();
    }
    if(CLinks::Link(CLinks::m_iMaxUsedLinksId).Used()
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1196, "!Link(m_iMaxUsedLinksId).Used()") == 1) {
      __debugbreak();
    }
    for(j = CLinks::m_iMinFreeLinksId; ; j += 2) {
      if(!CLinks::Link(j).Used())
        break;
    }
    CLinks::m_iMinFreeLinksId = j;
    if(j >= CLinks::m_iMaxUsedLinksId)
      return;
    if(CLinks::m_iMinFreeLinksId < 2
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1216, "m_iMinFreeLinksId >= LINK_FIRST_REAL") == 1) {
      __debugbreak();
    }
    if(CLinks::m_iMinFreeLinksId > 262142
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1217, "m_iMinFreeLinksId <= (LINK_LAST_REAL + 1)") == 1) {
      __debugbreak();
    }
    if((CLinks::m_iMinFreeLinksId & 1) != 0
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1218, "(m_iMinFreeLinksId & 1) == 0") == 1) {
      __debugbreak();
    }
    if(!CLinks::Link(CLinks::m_iMinFreeLinksId - 2).Used()
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1219, "Link(m_iMinFreeLinksId - 2).Used()") == 1) {
      __debugbreak();
    }
    if(CLinks::Link(CLinks::m_iMinFreeLinksId).Used()
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1220, "!Link(m_iMinFreeLinksId).Used()") == 1) {
      __debugbreak();
    }
    if(CLinks::m_iMinFreeLinksId > CLinks::m_iMaxUsedLinksId
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1222, "m_iMinFreeLinksId <= m_iMaxUsedLinksId") == 1) {
      __debugbreak();
    }
    for(iLastHeaderLinksId = CLinks::m_iMaxUsedLinksId - 2; ; iLastHeaderLinksId -= 2) {
      if(CLinks::Link(iLastHeaderLinksId).IsHeader())
        break;
    }
    if(iLastHeaderLinksId < 2
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1233, "iLastHeaderLinksId >= LINK_FIRST_REAL") == 1) {
      __debugbreak();
    }
    int v30 = CLinks::m_iMinFreeLinksId;
    int v23 = CLinks::m_iMinFreeLinksId + CLinks::m_iMaxUsedLinksId - iLastHeaderLinksId;
    while(1) {
      if(((v30 < v23) & CLinks::Link(v30).Unused()) == 0)
        break;
      v30 += 2;
    }
    if(v30 < v23)
      break;
    int v22 = CTilesAndLinks::MoveLinkList(CLinks::m_iMinFreeLinksId, iLastHeaderLinksId);
    CLinks::m_iMinFreeLinksId += v22;
    CLinks::m_iMaxUsedLinksId -= v22;
    if(CLinks::Link(CLinks::m_iMaxUsedLinksId).Used()
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1259, "!Link(m_iMaxUsedLinksId).Used()") == 1) {
      __debugbreak();
    }
  }
  while(1) {
    int v20 = a1--;
    if(v20 < 0)
      break;
    for(k = CLinks::m_iMaxUsedLinksId; ; k -= 2) {
      if(!CLinks::Link(k - 2).Unused())
        break;
    }
    CLinks::m_iMaxUsedLinksId = k;
    if(k <= 2)
      break;
    if(CLinks::m_iMaxUsedLinksId < 2
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1285, "m_iMaxUsedLinksId >= LINK_FIRST_REAL") == 1) {
      __debugbreak();
    }
    if(CLinks::m_iMaxUsedLinksId > 262142
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1286, "m_iMaxUsedLinksId <= (LINK_LAST_REAL + 1)") == 1) {
      __debugbreak();
    }
    if((CLinks::m_iMaxUsedLinksId & 1) != 0
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1287, "(m_iMaxUsedLinksId & 1) == 0") == 1) {
      __debugbreak();
    }
    if(!CLinks::Link(CLinks::m_iMaxUsedLinksId - 2).Used()
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1288, "Link(m_iMaxUsedLinksId - 2).Used()") == 1) {
      __debugbreak();
    }
    if(CLinks::Link(CLinks::m_iMaxUsedLinksId).Used()
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1289, "!Link(m_iMaxUsedLinksId).Used()") == 1) {
      __debugbreak();
    }
    for(m = CLinks::m_iMinFreeLinksId; ; m += 2) {
      if(!CLinks::Link(m).Used())
        break;
    }
    CLinks::m_iMinFreeLinksId = m;
    if(m >= CLinks::m_iMaxUsedLinksId)
      break;
    if(CLinks::m_iMinFreeLinksId < 2
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1309, "m_iMinFreeLinksId >= LINK_FIRST_REAL") == 1) {
      __debugbreak();
    }
    if(CLinks::m_iMinFreeLinksId > 262142
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1310, "m_iMinFreeLinksId <= (LINK_LAST_REAL + 1)") == 1) {
      __debugbreak();
    }
    if((CLinks::m_iMinFreeLinksId & 1) != 0
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1311, "(m_iMinFreeLinksId & 1) == 0") == 1) {
      __debugbreak();
    }
    if(!CLinks::Link(CLinks::m_iMinFreeLinksId - 2).Used()
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1312, "Link(m_iMinFreeLinksId - 2).Used()") == 1) {
      __debugbreak();
    }
    if(CLinks::Link(CLinks::m_iMinFreeLinksId).Used()
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1313, "!Link(m_iMinFreeLinksId).Used()") == 1) {
      __debugbreak();
    }
    if(CLinks::m_iMinFreeLinksId > CLinks::m_iMaxUsedLinksId
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1315, "m_iMinFreeLinksId <= m_iMaxUsedLinksId") == 1) {
      __debugbreak();
    }
    for(iNextUsedLinksId = CLinks::m_iMinFreeLinksId; ; iNextUsedLinksId += 2) {
      if(!CLinks::Link(iNextUsedLinksId).Unused())
        break;
    }
    if(!CLinks::Link(iNextUsedLinksId).IsHeader()
       && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1326, "Link(iNextUsedLinksId).IsHeader()") == 1) {
      __debugbreak();
    }
    CLinks::m_iMinFreeLinksId += CTilesAndLinks::MoveLinkList(CLinks::m_iMinFreeLinksId, iNextUsedLinksId);
  }
}


// address=[0x15e5ac0]
// Decompiled from struct CLinkList *__cdecl CTilesAndLinks::PushLinksUndef(int a1)
class CLinkList & __cdecl CTilesAndLinks::PushLinksUndef(int a1) {
  // [esp+0h] [ebp-4h]

  int v2 = CLinks::PushLinksUndef(a1);
  if(v2)
    return CLinks::LinkList(v2);
  CTilesAndLinks::LinksGarbageCollection(16);
  if(CLinks::PushLinksUndef(a1))
    CTilesAndLinks::LinksGarbageCollection(0x7FFFFFFF);
  v2 = CLinks::PushLinksUndef(a1);
  if(v2)
    return CLinks::LinkList(v2);
  if(BBSupportDbgReport(1, "Pathing\\TilesAndLinks.cpp", 1368, "Tiling: Out of links!") == 1)
    __debugbreak();
  return CLinks::LinkList(0);
}


// address=[0x15e5b70]
// Decompiled from CLinkList *__cdecl CTilesAndLinks::PushLinks(const struct CIntLinkList *a1)
class CLinkList & __cdecl CTilesAndLinks::PushLinks(class CIntLinkList const &a1) {
  // eax
  ; // [esp+0h] [ebp-4h]

  int        v1 = a1.Size();
  CLinkList &v3 = CTilesAndLinks::PushLinksUndef(v1);
  v3 = a1;
  CLinks::CheckLinksInfo();
  return v3;
}


// address=[0x15e5ba0]
// Decompiled from void __cdecl CTilesAndLinks::AddLink(int _iOwnerTileId, int _iLinkTileId)
void __cdecl CTilesAndLinks::AddLink(int _iOwnerTileId, int _iLinkTileId) {
  // eax
  // eax
  // eax
  // [esp+0h] [ebp-Ch]
  // [esp+4h] [ebp-8h]
  // [esp+8h] [ebp-4h]

  if(!CTilesEx::IsUsedRealTile(_iOwnerTileId)
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1400, "IsUsedRealTile(_iOwnerTileId)") == 1) {
    __debugbreak();
  }
  if(_iOwnerTileId == _iLinkTileId
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1401, "_iOwnerTileId != _iLinkTileId") == 1) {
    __debugbreak();
  }
  struct CLinkList *pLinkList = &CTiles::TileEx(_iOwnerTileId).LinkList();
  if(!(unsigned __int8) CLinks::IsValidUsedLinkList(*pLinkList)
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1405, "IsValidUsedLinkList(*pLinkList)") == 1) {
    __debugbreak();
  }
  if(pLinkList->SearchForLinkTileId(_iLinkTileId)) {
    CTrace::Print("CTilesAndLinks::AddLink: TileEx %i found in link list 0x%08x!", _iLinkTileId, pLinkList);
    pLinkList->DbgPrint();
  } else {
    int v6 = pLinkList->Size();
    if(!pLinkList->Link(v6).Unused()) {
      struct CLinkList *v5 = pLinkList;
      pLinkList = &CTilesAndLinks::PushLinksUndef(v6 + 1);
      if(!CLinks::IsValidRealLinkList(*pLinkList)
         && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1417, "IsValidRealLinkList(*pLinkList)") == 1) {
        __debugbreak();
      }

      CTiles::TileEx(_iOwnerTileId).SetLinkList(*pLinkList);
      pLinkList = v5;
      CLinks::LinkListMarkAsUnused(*v5);
    }
    CLinks::LinkListPushLinkTileId(*pLinkList, _iLinkTileId);
    CLinks::CheckLinksInfo();
  }
}


// address=[0x15e5d40]
// Decompiled from char __cdecl CTilesAndLinks::DeleteLink(int a1, int a2)
void __cdecl CTilesAndLinks::DeleteLink(int a1, int a2) {
  // eax
  // [esp+0h] [ebp-4h]

  if(!CTilesEx::IsUsedRealTile(a1)
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1484, "IsUsedRealTile(_iOwnerTileId)") == 1) {
    __debugbreak();
  }
  if(!CTiles::IsValidRealTile(a2)
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1485, "IsValidRealTile(_iLinkTileId)") == 1) {
    __debugbreak();
  }
  if(a1 == a2 && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1487, "_iOwnerTileId != _iLinkTileId") == 1)
    __debugbreak();

  CLinkList &rLinkList = CTiles::TileEx(a1).LinkList();
  if(!CLinks::IsValidUsedLinkList(rLinkList)
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1491, "IsValidUsedLinkList(rLinkList)") == 1) {
    __debugbreak();
  }
  CLinks::LinkListRemoveLinkTileId(rLinkList, a2);
}


// address=[0x15e5e30]
// Decompiled from void __cdecl CTilesAndLinks::ReplaceLink(int a1, int a2, int a3)
void __cdecl CTilesAndLinks::ReplaceLink(int a1, int a2, int a3) {
  // eax
  // [esp+0h] [ebp-4h]

  if(!CTilesEx::IsUsedRealTile(a1)
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1454, "IsUsedRealTile(_iOwnerTileId)") == 1) {
    __debugbreak();
  }

  CLinkList &v4 = CTiles::TileEx(a1).LinkList();
  if(!CLinks::LinkListReplaceLink(v4, a2, a3)) {
    CTrace::Print("CTilesAndLinks::ReplaceLink(): Old tile %i not found in link list 0x%08x!", a2, v4);
    v4.DbgPrint();
    if(BBSupportDbgReport(
         1,
         "Pathing\\TilesAndLinks.cpp",
         1467,
         "CTilesAndLinks::ReplaceLink(): OldLinkTileId not found [may be ignored]!") == 1)
      __debugbreak();
    CTilesAndLinks::AddLink(a1, a3);
  }
}


// address=[0x15e5ef0]
// Decompiled from int __cdecl CTilesAndLinks::AddLinkList(struct CLinkList *a1)
void __cdecl CTilesAndLinks::AddLinkList(class CLinkList const &a1) {
  // eax
  // eax
  // [esp+0h] [ebp-Ch]
  // [esp+4h] [ebp-8h]
  // [esp+8h] [ebp-4h]

  if(!CLinks::IsValidUsedLinkList(a1)
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1528, "IsValidUsedLinkList(_rLinkList)") == 1) {
    __debugbreak();
  }
  int v4 = a1.Size();
  for(int i = 0; i < v4; ++i) {
    unsigned short const &v2 = a1[i];
    CTilesAndLinks::AddLink(v2, a1.OwnerTileId());
  }
}


// address=[0x15e5f80]
// Decompiled from int __cdecl CTilesAndLinks::DeleteLinkList(struct CLinkList *a1)
void __cdecl CTilesAndLinks::DeleteLinkList(class CLinkList &a1) {
  // eax
  // [esp+0h] [ebp-Ch]
  // [esp+4h] [ebp-8h]
  // [esp+8h] [ebp-4h]

  if(!CLinks::IsValidUsedLinkList(a1)
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1506, "IsValidUsedLinkList(_rLinkList)") == 1) {
    __debugbreak();
  }

  for(int i = 0; i < a1.Size(); ++i) {
    unsigned short const &v2 = a1[i];
    CTilesAndLinks::DeleteLink(v2, a1.OwnerTileId());
  }
  CLinks::LinkListMarkAsUnused(a1);
}


// address=[0x15e6020]
// Decompiled from void __cdecl CTilesAndLinks::DeleteTile(int *a1)
void __cdecl CTilesAndLinks::DeleteTile(int a1) {
  // eax
  // eax

  if(CTilesEx::IsUsedRealTile(a1)) {
    CTilesAndLinks::DeleteLinkList(CTiles::TileEx(a1).LinkList());
    CTilesEx::DeleteTile((int) a1);
  } else if(!"DeleteTile(): Not a used real tile!"
            && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1551, "\"DeleteTile(): Not a used real tile!\"") == 1) {
    __debugbreak();
  }
}


// address=[0x15e6090]
// Decompiled from int __cdecl CTilesAndLinks::MergeTileLinkLists(int _iDstTileId, int _iSrcTileId)
void __cdecl CTilesAndLinks::MergeTileLinkLists(int _iDstTileId, int _iSrcTileId) {
  if(_iDstTileId == _iSrcTileId
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1575, "_iDstTileId != _iSrcTileId") == 1) {
    __debugbreak();
  }
  struct CLinkList &v6 = CTiles::TileEx(_iSrcTileId).LinkList();
  int               v8 = 0;
  for(int i = v6.Size(); v8 < i; i = v6.Size()) {
    unsigned short const &v7 = v6[v8];
    if(CTiles::TileEx(_iDstTileId).LinkList().SearchForLinkTileId(v7) == 0 && v7 != _iDstTileId) {
      CTilesAndLinks::AddLink(_iDstTileId, v7);
      CTilesAndLinks::ReplaceLink(v7, _iSrcTileId, _iDstTileId);
    }
    ++v8;
  }
}


