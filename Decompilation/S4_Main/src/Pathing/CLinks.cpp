#include "CLinks.h"

#include "CBB/CBBSupport.h"
#include "Collections/CIntLinkList.h"
#include "Collections/CLink.h"
#include "../Collections/CLinkList.h"

// Definitions for class CLinks

// address=[0x15e3cf0]
// Decompiled from void CLinks::InitLinks()
void __cdecl CLinks::InitLinks(void) {
  // [esp+0h] [ebp-4h]

  CLinks::m_cLinks[0].m_uData = 0xFC00;
  CLinks::m_cLinks[1].m_uData = 0;
  CLinks::m_cLinks[0x3FFFE].m_uData = 0xFE00;
  CLinks::m_cLinks[0x3FFFF].m_uData = 0;
  for(int i = 2; i <= 0x3FFFD; ++i)
    CLinks::m_cLinks[i].m_uData = 0xFF00;
  CLinks::m_iLinksPushBackMode = 1;
  CLinks::m_iMinFreeLinksId = 2;
  CLinks::m_iMaxUsedLinksId = 2;
}


// address=[0x15e3db0]
// Decompiled from void CLinks::DeactivateLinksPushBackMode()
void __cdecl CLinks::DeactivateLinksPushBackMode(void) {
  if(!CLinks::m_iLinksPushBackMode
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 674, "m_iLinksPushBackMode") == 1) {
    __debugbreak();
  }
  CLinks::m_iLinksPushBackMode = 0;
  CLinks::m_iMinFreeLinksId = CLinks::m_iMaxUsedLinksId;
  CLinks::CheckLinksInfo();
}


// address=[0x15e3e00]
// Decompiled from struct CLinkList *__cdecl CLinks::PushLinksBack(const struct CIntLinkList *a1)
class CLinkList & __cdecl CLinks::PushLinksBack(class CIntLinkList const &a1) {
  int  v1; // esi
  char v2; // al
  // [esp+4h] [ebp-Ch]

  if(!CLinks::m_iLinksPushBackMode
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 690, "m_iLinksPushBackMode") == 1) {
    __debugbreak();
  }
  int v4 = CLinks::m_iMaxUsedLinksId;
  CLinks::m_iMaxUsedLinksId += a1.Size() + (a1.Size() & 1) + 2;
  CLinks::LinkList(v4) = a1;
  return CLinks::LinkList(v4);
}


// address=[0x15e3e90]
// Decompiled from int __cdecl CLinks::PushLinksUndef(int a1)
int __cdecl CLinks::PushLinksUndef(int a1) {
  int iSizeEx = a1 + (a1 & 1) + 2;
  int iUnusedLinksId = CLinks::SearchForUnusedLinkEntries(iSizeEx);
  if(!iUnusedLinksId)
    return 0;
  if((iSizeEx & 1) != 0 && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 719, "(iSizeEx & 1) == 0") == 1)
    __debugbreak();
  if((iUnusedLinksId & 1) != 0
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 720, "(iUnusedLinksId & 1) == 0") == 1) {
    __debugbreak();
  }
  if(iSizeEx + iUnusedLinksId > 262142
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 721, "(iUnusedLinksId + iSizeEx) <= (LINK_LAST_REAL + 1)") == 1) {
    __debugbreak();
  }
  if(iSizeEx + iUnusedLinksId > CLinks::m_iMaxUsedLinksId)
    CLinks::m_iMaxUsedLinksId = iSizeEx + iUnusedLinksId;
  if(CLinks::m_iMaxUsedLinksId < 2
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 728, "m_iMaxUsedLinksId >= LINK_FIRST_REAL") == 1) {
    __debugbreak();
  }
  if(CLinks::m_iMaxUsedLinksId > 262142
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 729, "m_iMaxUsedLinksId <= (LINK_LAST_REAL + 1)") == 1) {
    __debugbreak();
  }
  if((CLinks::m_iMaxUsedLinksId & 1) != 0
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 730, "(m_iMaxUsedLinksId & 1) == 0") == 1) {
    __debugbreak();
  }
  if(CLinks::Link(CLinks::m_iMaxUsedLinksId).Used()
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 731, "!Link(m_iMaxUsedLinksId).Used()") == 1) {
    __debugbreak();
  }
  if(CLinks::m_iMinFreeLinksId > CLinks::m_iMaxUsedLinksId
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 733, "m_iMinFreeLinksId <= m_iMaxUsedLinksId") == 1) {
    __debugbreak();
  }
  return iUnusedLinksId;
}


// address=[0x15e70b0]
// Decompiled from BOOL __cdecl CLinks::IsValidRealLinkList(const struct CLinkList *a1)
bool __cdecl CLinks::IsValidRealLinkList(class CLinkList const &a1) {
  return &a1 <= (const struct CLinkList *) &CLinks::m_cLinks[262141]
         && &a1 >= (const struct CLinkList *) &CLinks::m_cLinks[2];
}


// address=[0x15e7170]
// Decompiled from bool __cdecl CLinks::IsValidUsedLinkList(const struct CLinkList *a1)
bool __cdecl CLinks::IsValidUsedLinkList(class CLinkList const &a1) {
  // [esp+0h] [ebp-4h]

  bool v2 = a1.m_uMarker == 253;
  return v2 & CLinks::IsValidRealLinkList(a1);
}


// address=[0x15e7250]
// Decompiled from CLink *__cdecl CLinks::Link(int a1)
class CLink const & __cdecl CLinks::Link(int a1) {
  return CLinks::m_cLinks[a1];
}


// address=[0x15e7270]
// Decompiled from struct CLinkList *__cdecl CLinks::LinkList(int a1)
class CLinkList & __cdecl CLinks::LinkList(int a1) {
  return reinterpret_cast<struct CLinkList &>(CLinks::m_cLinks[a1]);
}


// address=[0x15e4050]
// Decompiled from int __cdecl CLinks::LinkListMarkAsUnused(struct CLinkList *a1)
void __cdecl CLinks::LinkListMarkAsUnused(class CLinkList &a1) {
  // esi
  // [esp+4h] [ebp-18h]
  // [esp+14h] [ebp-8h]
  // [esp+18h] [ebp-4h]

  CLinks::CheckLinksInfo();

  a1.m_uSize = 0;
  a1.m_uMarker = 0xFF;
  a1.m_uOwnerTileId = 0;
  a1.m_uLinkTileIds[0].m_uData = 0xFF00;

  for(int i = 0; i < ((a1.Size() & 1) + a1.Size()); ++i)
    a1.m_uLinkTileIds[i].m_uData = 0xFF00;
  int iLinksId = CLinks::LinksId(a1);
  if((iLinksId > 262141 || iLinksId < 2)
     && BBSupportDbgReport(
       2,
       "Pathing\\TilesAndLinks.cpp",
       886,
       "(iLinksId >= LINK_FIRST_REAL) & (iLinksId <= LINK_LAST_REAL)") == 1) {
    __debugbreak();
  }
  if(iLinksId < CLinks::m_iMinFreeLinksId)
    CLinks::m_iMinFreeLinksId = iLinksId;
  return CLinks::CheckLinksInfo();
}


// address=[0x15e4140]
// Decompiled from void __cdecl CLinks::LinkListPushLinkTileId(struct CLinkList *_rLinkList, int _iLinkTileId)
void __cdecl CLinks::LinkListPushLinkTileId(class CLinkList &_rLinkList, int _iLinkTileId) {
  if(_rLinkList.SearchForLinkTileId(_iLinkTileId)
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 910, "!_rLinkList.SearchForLinkTileId(_iLinkTileId)") == 1) {
    __debugbreak();
  }
  if(CLinks::m_iMaxUsedLinksId < LINK_FIRST_REAL
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 912, "m_iMaxUsedLinksId >= LINK_FIRST_REAL") == 1) {
    __debugbreak();
  }
  if(CLinks::m_iMaxUsedLinksId > 262142
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 913, "m_iMaxUsedLinksId <= (LINK_LAST_REAL + 1)") == 1) {
    __debugbreak();
  }
  if((CLinks::m_iMaxUsedLinksId & 1) != 0
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 914, "(m_iMaxUsedLinksId & 1) == 0") == 1) {
    __debugbreak();
  }
  if(CLinks::Link(CLinks::m_iMaxUsedLinksId).Used()
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 915, "!Link(m_iMaxUsedLinksId).Used()") == 1) {
    __debugbreak();
  }
  int iOldSize = _rLinkList.Size();
  if(iOldSize + 1 >= 62
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 921, "(iOldSize + 1) < LINK_LIST_MAX") == 1) {
    __debugbreak();
  }
  if(_rLinkList.m_uLinkTileIds[iOldSize].m_uData != 65280
     && BBSupportDbgReport(
       2,
       "Pathing\\TilesAndLinks.cpp",
       922,
       "_rLinkList.m_uLinkTileIds[iOldSize] == LINK_ENTRY_UNUSED_16") == 1) {
    __debugbreak();
  }
  _rLinkList.m_uSize = iOldSize + 1;
  _rLinkList.m_uLinkTileIds[iOldSize].m_uData = _iLinkTileId;
  int iLinksId = CLinks::LinksId(_rLinkList);
  int v4 = iOldSize + (((_BYTE) iOldSize + 1) & 1) + 3;
  if((iLinksId > 262141 || iLinksId < 2)
     && BBSupportDbgReport(
       2,
       "Pathing\\TilesAndLinks.cpp",
       932,
       "(iLinksId >= LINK_FIRST_REAL) & (iLinksId <= LINK_LAST_REAL)") == 1) {
    __debugbreak();
  }
  if(v4 + iLinksId >= CLinks::m_iMaxUsedLinksId)
    CLinks::m_iMaxUsedLinksId = v4 + iLinksId;
  if(CLinks::m_iMaxUsedLinksId < 2
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 939, "m_iMaxUsedLinksId >= LINK_FIRST_REAL") == 1) {
    __debugbreak();
  }
  if(CLinks::m_iMaxUsedLinksId > 262142
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 940, "m_iMaxUsedLinksId <= (LINK_LAST_REAL + 1)") == 1) {
    __debugbreak();
  }
  if((CLinks::m_iMaxUsedLinksId & 1) != 0
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 941, "(m_iMaxUsedLinksId & 1) == 0") == 1) {
    __debugbreak();
  }

  if(CLinks::Link(CLinks::m_iMaxUsedLinksId).Used()
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 942, "!Link(m_iMaxUsedLinksId).Used()") == 1) {
    __debugbreak();
  }
}


// address=[0x15e4410]
// Decompiled from bool __cdecl CLinks::LinkListRemoveLinkTileId(struct CLinkList *a1, int a2)
bool __cdecl CLinks::LinkListRemoveLinkTileId(class CLinkList &a1, int a2) {
  // [esp+4h] [ebp-10h]
  // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  // [esp+10h] [ebp-4h]

  int m_uSize = a1.m_uSize;
  for(i = 0; ; ++i) {
    if(i >= m_uSize) {
      CLinks::CheckLinksInfo();
      return 0;
    }
    if(a1.m_uLinkTileIds[i].m_uData == a2)
      break;
  }
  a1.m_uLinkTileIds[i].m_uData = *(&a1.m_uOwnerTileId + m_uSize);
  *(&a1.m_uOwnerTileId + m_uSize) = -256;
  --a1.m_uSize;
  if((m_uSize & 1) != 0) {
    int v4 = CLinks::LinksId(a1);
    int v3 = m_uSize + (((_BYTE) m_uSize - 1) & 1) + 1;
    if(v3 + v4 < CLinks::m_iMinFreeLinksId)
      CLinks::m_iMinFreeLinksId = v3 + v4;
  }
  CLinks::CheckLinksInfo();
  return 1;
}


// address=[0x15e44f0]
// Decompiled from bool __cdecl CLinks::LinkListReplaceLink(struct CLinkList *a1, int a2, WORD a3)
bool __cdecl CLinks::LinkListReplaceLink(class CLinkList &a1, int a2, int a3) {
  // [esp+4h] [ebp-4h]

  for(int i = 0; i < a1.m_uSize; ++i) {
    if(a1.m_uLinkTileIds[i].m_uData == a2) {
      a1.m_uLinkTileIds[i].m_uData = a3;
      return 1;
    }
  }
  return 0;
}


// address=[0x15e4550]
// Decompiled from int __cdecl CLinks::SearchForUnusedLinkEntries(int _iSizeEx)
int __cdecl CLinks::SearchForUnusedLinkEntries(int _iSizeEx) {
  CLink *v1; // eax
  CLink *v2; // eax
  CLink *v3; // eax
  CLink *v4; // eax
  CLink *v5; // eax
  CLink *v6; // eax
  CLink *v7; // eax
  CLink *v8; // eax
  CLink *v10; // eax
  CLink *v11; // eax
  // [esp+0h] [ebp-14h]
  int j; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  // [esp+10h] [ebp-4h]

  if(_iSizeEx < 2 && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 752, "_iSizeEx >= 2") == 1)
    __debugbreak();
  if((_iSizeEx & 1) != 0 && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 753, "(_iSizeEx & 1) == 0") == 1)
    __debugbreak();
  if(CLinks::m_iLinksPushBackMode
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 755, "!m_iLinksPushBackMode") == 1) {
    __debugbreak();
  }
  if(CLinks::m_iMaxUsedLinksId < 2
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 757, "m_iMaxUsedLinksId >= LINK_FIRST_REAL") == 1) {
    __debugbreak();
  }
  if(CLinks::m_iMaxUsedLinksId > 262142
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 758, "m_iMaxUsedLinksId <= (LINK_LAST_REAL + 1)") == 1) {
    __debugbreak();
  }
  if((CLinks::m_iMaxUsedLinksId & 1) != 0
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 759, "(m_iMaxUsedLinksId & 1) == 0") == 1) {
    __debugbreak();
  }
  if(CLinks::Link(CLinks::m_iMaxUsedLinksId).Used()
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 760, "!Link(m_iMaxUsedLinksId).Used()") == 1) {
    __debugbreak();
  }
  if(CLinks::m_iMinFreeLinksId < 2
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 762, "m_iMinFreeLinksId >= LINK_FIRST_REAL") == 1) {
    __debugbreak();
  }
  if(CLinks::m_iMinFreeLinksId > 262142
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 763, "m_iMinFreeLinksId <= (LINK_LAST_REAL + 1)") == 1) {
    __debugbreak();
  }
  if((CLinks::m_iMinFreeLinksId & 1) != 0
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 764, "(m_iMinFreeLinksId & 1) == 0") == 1) {
    __debugbreak();
  }

  if(!CLinks::Link(CLinks::m_iMinFreeLinksId - 2).Used()
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 765, "Link(m_iMinFreeLinksId - 2).Used()") == 1) {
    __debugbreak();
  }
  if(CLinks::m_iMinFreeLinksId > CLinks::m_iMaxUsedLinksId
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 767, "m_iMinFreeLinksId <= m_iMaxUsedLinksId") == 1) {
    __debugbreak();
  }
  for(i = CLinks::m_iMinFreeLinksId; ; i += 2) {
    if(!CLinks::Link(i).Used())
      break;
  }
  CLinks::m_iMinFreeLinksId = i;
  if(i < 2 && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 782, "m_iMinFreeLinksId >= LINK_FIRST_REAL") == 1)
    __debugbreak();
  if(CLinks::m_iMinFreeLinksId > 262142
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 783, "m_iMinFreeLinksId <= (LINK_LAST_REAL + 1)") == 1) {
    __debugbreak();
  }
  if((CLinks::m_iMinFreeLinksId & 1) != 0
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 784, "(m_iMinFreeLinksId & 1) == 0") == 1) {
    __debugbreak();
  }

  if(!CLinks::Link(CLinks::m_iMinFreeLinksId - 2).Used()
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 785, "Link(m_iMinFreeLinksId - 2).Used()") == 1) {
    __debugbreak();
  }
  if(CLinks::Link(CLinks::m_iMinFreeLinksId).Used()
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 786, "!Link(m_iMinFreeLinksId).Used()") == 1) {
    __debugbreak();
  }
  for(j = CLinks::m_iMaxUsedLinksId; ; j -= 2) {
    if(!CLinks::Link(j - 2).Unused())
      break;
  }
  CLinks::m_iMaxUsedLinksId = j;
  if(j < 2 && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 802, "m_iMaxUsedLinksId >= LINK_FIRST_REAL") == 1)
    __debugbreak();
  if(CLinks::m_iMaxUsedLinksId > 262142
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 803, "m_iMaxUsedLinksId <= (LINK_LAST_REAL + 1)") == 1) {
    __debugbreak();
  }
  if((CLinks::m_iMaxUsedLinksId & 1) != 0
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 804, "(m_iMaxUsedLinksId & 1) == 0") == 1) {
    __debugbreak();
  }
  if(!CLinks::Link(CLinks::m_iMaxUsedLinksId - 2).Used()
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 805, "Link(m_iMaxUsedLinksId - 2).Used()") == 1) {
    __debugbreak();
  }
  if(CLinks::Link(CLinks::m_iMaxUsedLinksId).Used()
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 806, "!Link(m_iMaxUsedLinksId).Used()") == 1) {
    __debugbreak();
  }
  if(CLinks::m_iMinFreeLinksId > CLinks::m_iMaxUsedLinksId
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 808, "m_iMinFreeLinksId <= m_iMaxUsedLinksId") == 1) {
    __debugbreak();
  }
  if(CLinks::m_iMinFreeLinksId < CLinks::m_iMaxUsedLinksId) {
    int v15 = CLinks::m_iMinFreeLinksId;
    int v12 = _iSizeEx + CLinks::m_iMinFreeLinksId;
    while(1) {
      if(((v15 < v12) & CLinks::Link(v15).Unused()) == 0)
        break;
      v15 += 2;
    }
    if(v15 < v12) {
      if(!CLinks::Link(v15).IsHeader()
         && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 841, "Link(iNextUsedLinksId).IsHeader()") == 1) {
        __debugbreak();
      }
      if(262142 - CLinks::m_iMaxUsedLinksId < _iSizeEx)
        return 0;
      else
        return CLinks::m_iMaxUsedLinksId;
    } else {
      return CLinks::m_iMinFreeLinksId;
    }
  } else if(262142 - CLinks::m_iMaxUsedLinksId < _iSizeEx) {
    return 0;
  } else {
    return CLinks::m_iMaxUsedLinksId;
  }
}


// address=[0x15e4b00]
// Decompiled from void CLinks::CalculateLinksInfo()
void __cdecl CLinks::CalculateLinksInfo(void) {
  CLink *v0; // eax
  CLink *v1; // eax
  CLink *v2; // eax
  CLink *v3; // eax
  CLink *v4; // eax
  CLink *v5; // eax
  // [esp+0h] [ebp-10h]
  // [esp+4h] [ebp-Ch]
  // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  for(i = 2; ; i += 2) {
    if(!CLinks::Link(i).Used())
      break;
  }
  int v7 = i - 2;
  int v6 = i - 2;
  for(int j = i; j <= 262141; j += 2) {
    if(CLinks::Link(j).Used()) {
      v7 += 2;
      v6 = j;
    }
  }
  CLinks::m_iMinFreeLinksId = i;
  CLinks::m_iMaxUsedLinksId = v6 + 2;
  if(i < 2 && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1065, "m_iMinFreeLinksId >= LINK_FIRST_REAL") == 1)
    __debugbreak();
  if(CLinks::m_iMinFreeLinksId > 262142
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1066, "m_iMinFreeLinksId <= (LINK_LAST_REAL + 1)") == 1) {
    __debugbreak();
  }
  if((CLinks::m_iMinFreeLinksId & 1) != 0
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1067, "(m_iMinFreeLinksId & 1) == 0") == 1) {
    __debugbreak();
  }
  if(!CLinks::Link(CLinks::m_iMinFreeLinksId - 2).Used()
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1068, "Link(m_iMinFreeLinksId - 2).Used()") == 1) {
    __debugbreak();
  }
  if(CLinks::Link(CLinks::m_iMinFreeLinksId).Used()
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1069, "!Link(m_iMinFreeLinksId).Used()") == 1) {
    __debugbreak();
  }
  if(CLinks::m_iMaxUsedLinksId < 2
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1071, "m_iMaxUsedLinksId >= LINK_FIRST_REAL") == 1) {
    __debugbreak();
  }
  if(CLinks::m_iMaxUsedLinksId > 262142
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1072, "m_iMaxUsedLinksId <= (LINK_LAST_REAL + 1)") == 1) {
    __debugbreak();
  }
  if((CLinks::m_iMaxUsedLinksId & 1) != 0
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1073, "(m_iMaxUsedLinksId & 1) == 0") == 1) {
    __debugbreak();
  }
  if(!CLinks::Link(CLinks::m_iMaxUsedLinksId - 2).Used()
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1074, "Link(m_iMaxUsedLinksId - 2).Used()") == 1) {
    __debugbreak();
  }
  if(CLinks::Link(CLinks::m_iMaxUsedLinksId).Used()
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1075, "!Link(m_iMaxUsedLinksId).Used()") == 1) {
    __debugbreak();
  }
  if(CLinks::m_iMinFreeLinksId > CLinks::m_iMaxUsedLinksId
     && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1077, "m_iMinFreeLinksId <= m_iMaxUsedLinksId") == 1) {
    __debugbreak();
  }
}


// address=[0x15e4dd0]
// Decompiled from void CLinks::CheckLinksInfo()
void __cdecl CLinks::CheckLinksInfo(void) {
  ;
}


// address=[0x15e7290]
// Decompiled from int __cdecl CLinks::LinksId(const struct CLinkList *a1)
int __cdecl CLinks::LinksId(class CLinkList const &a1) {
  return ((char *) &a1 - (char *) CLinks::m_cLinks) >> 1;
}


// address=[0x424f8d0]
// [Decompilation failed for static int CLinks::m_iLinksPushBackMode]

// address=[0x424f8d4]
// [Decompilation failed for static int CLinks::m_iMinFreeLinksId]

// address=[0x424f8d8]
// [Decompilation failed for static int CLinks::m_iMaxUsedLinksId]

// address=[0x424f8e0]
// [Decompilation failed for static class CLink * CLinks::m_cLinks]

