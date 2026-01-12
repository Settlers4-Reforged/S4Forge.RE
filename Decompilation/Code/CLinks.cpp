#include "CLinks.h"

// Definitions for class CLinks

// address=[0x15e3cf0]
// Decompiled from int CLinks::InitLinks()

static void __cdecl CLinks::InitLinks(void) {
  
  int result; // eax
  int i; // [esp+0h] [ebp-4h]

  CLinks::m_cLinks[0] = -1024;
  CLinks::m_cLinks[1] = 0;
  LOBYTE(CLinks::m_cLinks[262142]) = 0;
  HIBYTE(CLinks::m_cLinks[262142]) = -2;
  result = 0;
  CLinks::m_cLinks[0x3FFFF] = 0;
  for ( i = 2; i <= 262141; ++i )
  {
    result = i;
    CLinks::m_cLinks[i] = -256;
  }
  CLinks::m_iLinksPushBackMode = 1;
  CLinks::m_iMinFreeLinksId = 2;
  CLinks::m_iMaxUsedLinksId = 2;
  return result;
}


// address=[0x15e3db0]
// Decompiled from int CLinks::DeactivateLinksPushBackMode()

static void __cdecl CLinks::DeactivateLinksPushBackMode(void) {
  
  if ( !CLinks::m_iLinksPushBackMode
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 674, "m_iLinksPushBackMode") == 1 )
  {
    __debugbreak();
  }
  CLinks::m_iLinksPushBackMode = 0;
  CLinks::m_iMinFreeLinksId = CLinks::m_iMaxUsedLinksId;
  return CLinks::CheckLinksInfo();
}


// address=[0x15e3e00]
// Decompiled from struct CLinkList *__cdecl CLinks::PushLinksBack(const struct CIntLinkList *a1)

static class CLinkList & __cdecl CLinks::PushLinksBack(class CIntLinkList const &) {
  
  int v1; // esi
  char v2; // al
  int v4; // [esp+4h] [ebp-Ch]
  struct CLinkList *v5; // [esp+Ch] [ebp-4h]

  if ( !CLinks::m_iLinksPushBackMode
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 690, "m_iLinksPushBackMode") == 1 )
  {
    __debugbreak();
  }
  v1 = CIntLinkList::Size(a1);
  v2 = CIntLinkList::Size(a1);
  v4 = CLinks::m_iMaxUsedLinksId;
  CLinks::m_iMaxUsedLinksId += v1 + (v2 & 1) + 2;
  v5 = CLinks::LinkList(v4);
  CLinkList::operator=(v5, a1);
  return v5;
}


// address=[0x15e3e90]
// Decompiled from int __cdecl CLinks::PushLinksUndef(int a1)

static int __cdecl CLinks::PushLinksUndef(int) {
  
  CLink *v1; // eax
  int v3; // [esp+0h] [ebp-8h]
  int v4; // [esp+4h] [ebp-4h]

  v3 = a1 + (a1 & 1) + 2;
  v4 = CLinks::SearchForUnusedLinkEntries(v3);
  if ( !v4 )
    return 0;
  if ( (v3 & 1) != 0 && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 719, "(iSizeEx & 1) == 0") == 1 )
    __debugbreak();
  if ( (v4 & 1) != 0 && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 720, "(iUnusedLinksId & 1) == 0") == 1 )
    __debugbreak();
  if ( v3 + v4 > 262142
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 721, "(iUnusedLinksId + iSizeEx) <= (LINK_LAST_REAL + 1)") == 1 )
  {
    __debugbreak();
  }
  if ( v3 + v4 > CLinks::m_iMaxUsedLinksId )
    CLinks::m_iMaxUsedLinksId = v3 + v4;
  if ( CLinks::m_iMaxUsedLinksId < 2
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 728, "m_iMaxUsedLinksId >= LINK_FIRST_REAL") == 1 )
  {
    __debugbreak();
  }
  if ( CLinks::m_iMaxUsedLinksId > 262142
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 729, "m_iMaxUsedLinksId <= (LINK_LAST_REAL + 1)") == 1 )
  {
    __debugbreak();
  }
  if ( (CLinks::m_iMaxUsedLinksId & 1) != 0
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 730, "(m_iMaxUsedLinksId & 1) == 0") == 1 )
  {
    __debugbreak();
  }
  v1 = CLinks::Link(CLinks::m_iMaxUsedLinksId);
  if ( CLink::Used(v1)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 731, "!Link(m_iMaxUsedLinksId).Used()") == 1 )
  {
    __debugbreak();
  }
  if ( CLinks::m_iMinFreeLinksId > CLinks::m_iMaxUsedLinksId
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 733, "m_iMinFreeLinksId <= m_iMaxUsedLinksId") == 1 )
  {
    __debugbreak();
  }
  return v4;
}


// address=[0x15e70b0]
// Decompiled from BOOL __cdecl CLinks::IsValidRealLinkList(const struct CLinkList *a1)

static bool __cdecl CLinks::IsValidRealLinkList(class CLinkList const &) {
  
  return a1 <= (const struct CLinkList *)&CLinks::m_cLinks[262141]
      && a1 >= (const struct CLinkList *)&CLinks::m_cLinks[2];
}


// address=[0x15e7170]
// Decompiled from int __cdecl CLinks::IsValidUsedLinkList(const struct CLinkList *a1)

static bool __cdecl CLinks::IsValidUsedLinkList(class CLinkList const &) {
  
  bool v2; // [esp+0h] [ebp-4h]

  v2 = *((unsigned __int8 *)a1 + 1) == 253;
  return v2 & CLinks::IsValidRealLinkList(a1);
}


// address=[0x15e7250]
// Decompiled from __int16 *__cdecl CLinks::Link(int a1)

static class CLink const & __cdecl CLinks::Link(int) {
  
  return &CLinks::m_cLinks[a1];
}


// address=[0x15e7270]
// Decompiled from __int16 *__cdecl CLinks::LinkList(int a1)

static class CLinkList & __cdecl CLinks::LinkList(int) {
  
  return &CLinks::m_cLinks[a1];
}


// address=[0x15e4050]
// Decompiled from int __cdecl CLinks::LinkListMarkAsUnused(struct CLinkList *a1)

static void __cdecl CLinks::LinkListMarkAsUnused(class CLinkList &) {
  
  int v1; // esi
  int v3; // [esp+4h] [ebp-18h]
  int v4; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  CLinks::CheckLinksInfo();
  v1 = CLinkList::Size((unsigned __int8 *)a1);
  v3 = ((CLinkList::Size((unsigned __int8 *)a1) & 1) + v1) >> 1;
  *(_DWORD *)a1 = -16711936;
  for ( i = 0; i < v3; ++i )
    *((_DWORD *)a1 + i + 1) = -16711936;
  v4 = CLinks::LinksId(a1);
  if ( (v4 > 262141 || v4 < 2)
    && BBSupportDbgReport(
         2,
         "Pathing\\TilesAndLinks.cpp",
         886,
         "(iLinksId >= LINK_FIRST_REAL) & (iLinksId <= LINK_LAST_REAL)") == 1 )
  {
    __debugbreak();
  }
  if ( v4 < CLinks::m_iMinFreeLinksId )
    CLinks::m_iMinFreeLinksId = v4;
  return CLinks::CheckLinksInfo();
}


// address=[0x15e4140]
// Decompiled from int __cdecl CLinks::LinkListPushLinkTileId(struct CLinkList *a1, int a2)

static void __cdecl CLinks::LinkListPushLinkTileId(class CLinkList &,int) {
  
  CLink *v2; // eax
  CLink *v3; // eax
  int result; // eax
  int v5; // [esp+0h] [ebp-14h]
  int v6; // [esp+Ch] [ebp-8h]
  int v7; // [esp+10h] [ebp-4h]

  if ( CLinkList::SearchForLinkTileId(a1, a2)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 910, "!_rLinkList.SearchForLinkTileId(_iLinkTileId)") == 1 )
  {
    __debugbreak();
  }
  if ( CLinks::m_iMaxUsedLinksId < 2
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 912, "m_iMaxUsedLinksId >= LINK_FIRST_REAL") == 1 )
  {
    __debugbreak();
  }
  if ( CLinks::m_iMaxUsedLinksId > 262142
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 913, "m_iMaxUsedLinksId <= (LINK_LAST_REAL + 1)") == 1 )
  {
    __debugbreak();
  }
  if ( (CLinks::m_iMaxUsedLinksId & 1) != 0
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 914, "(m_iMaxUsedLinksId & 1) == 0") == 1 )
  {
    __debugbreak();
  }
  v2 = CLinks::Link(CLinks::m_iMaxUsedLinksId);
  if ( CLink::Used(v2)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 915, "!Link(m_iMaxUsedLinksId).Used()") == 1 )
  {
    __debugbreak();
  }
  v7 = CLinkList::Size((unsigned __int8 *)a1);
  if ( v7 + 1 >= 62 && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 921, "(iOldSize + 1) < LINK_LIST_MAX") == 1 )
    __debugbreak();
  if ( *((unsigned __int16 *)a1 + v7 + 2) != 65280
    && BBSupportDbgReport(
         2,
         "Pathing\\TilesAndLinks.cpp",
         922,
         "_rLinkList.m_uLinkTileIds[iOldSize] == LINK_ENTRY_UNUSED_16") == 1 )
  {
    __debugbreak();
  }
  *(_BYTE *)a1 = v7 + 1;
  *((_WORD *)a1 + v7 + 2) = a2;
  v6 = CLinks::LinksId(a1);
  v5 = v7 + (((_BYTE)v7 + 1) & 1) + 3;
  if ( (v6 > 262141 || v6 < 2)
    && BBSupportDbgReport(
         2,
         "Pathing\\TilesAndLinks.cpp",
         932,
         "(iLinksId >= LINK_FIRST_REAL) & (iLinksId <= LINK_LAST_REAL)") == 1 )
  {
    __debugbreak();
  }
  if ( v5 + v6 >= CLinks::m_iMaxUsedLinksId )
    CLinks::m_iMaxUsedLinksId = v5 + v6;
  if ( CLinks::m_iMaxUsedLinksId < 2
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 939, "m_iMaxUsedLinksId >= LINK_FIRST_REAL") == 1 )
  {
    __debugbreak();
  }
  if ( CLinks::m_iMaxUsedLinksId > 262142
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 940, "m_iMaxUsedLinksId <= (LINK_LAST_REAL + 1)") == 1 )
  {
    __debugbreak();
  }
  if ( (CLinks::m_iMaxUsedLinksId & 1) != 0
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 941, "(m_iMaxUsedLinksId & 1) == 0") == 1 )
  {
    __debugbreak();
  }
  v3 = CLinks::Link(CLinks::m_iMaxUsedLinksId);
  LOBYTE(result) = CLink::Used(v3);
  if ( !(_BYTE)result )
    return result;
  result = BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 942, "!Link(m_iMaxUsedLinksId).Used()");
  if ( result == 1 )
    __debugbreak();
  return result;
}


// address=[0x15e4410]
// Decompiled from char __cdecl CLinks::LinkListRemoveLinkTileId(struct CLinkList *a1, int a2)

static bool __cdecl CLinks::LinkListRemoveLinkTileId(class CLinkList &,int) {
  
  int v3; // [esp+4h] [ebp-10h]
  int v4; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  int v6; // [esp+10h] [ebp-4h]

  v6 = *(unsigned __int8 *)a1;
  for ( i = 0; ; ++i )
  {
    if ( i >= v6 )
    {
      CLinks::CheckLinksInfo();
      return 0;
    }
    if ( *((unsigned __int16 *)a1 + i + 2) == a2 )
      break;
  }
  *((_WORD *)a1 + i + 2) = *((_WORD *)a1 + v6 + 1);
  *((_WORD *)a1 + v6 + 1) = -256;
  --*(_BYTE *)a1;
  if ( (v6 & 1) != 0 )
  {
    v4 = CLinks::LinksId(a1);
    v3 = v6 + (((_BYTE)v6 - 1) & 1) + 1;
    if ( v3 + v4 < CLinks::m_iMinFreeLinksId )
      CLinks::m_iMinFreeLinksId = v3 + v4;
  }
  CLinks::CheckLinksInfo();
  return 1;
}


// address=[0x15e44f0]
// Decompiled from char __cdecl CLinks::LinkListReplaceLink(struct CLinkList *a1, int a2, __int16 a3)

static bool __cdecl CLinks::LinkListReplaceLink(class CLinkList &,int,int) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < *(unsigned __int8 *)a1; ++i )
  {
    if ( *((unsigned __int16 *)a1 + i + 2) == a2 )
    {
      *((_WORD *)a1 + i + 2) = a3;
      return 1;
    }
  }
  return 0;
}


// address=[0x15e4550]
// Decompiled from int __cdecl CLinks::SearchForUnusedLinkEntries(int a1)

static int __cdecl CLinks::SearchForUnusedLinkEntries(int) {
  
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
  int v12; // [esp+0h] [ebp-14h]
  int j; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  int v15; // [esp+10h] [ebp-4h]

  if ( a1 < 2 && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 752, "_iSizeEx >= 2") == 1 )
    __debugbreak();
  if ( (a1 & 1) != 0 && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 753, "(_iSizeEx & 1) == 0") == 1 )
    __debugbreak();
  if ( CLinks::m_iLinksPushBackMode
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 755, "!m_iLinksPushBackMode") == 1 )
  {
    __debugbreak();
  }
  if ( CLinks::m_iMaxUsedLinksId < 2
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 757, "m_iMaxUsedLinksId >= LINK_FIRST_REAL") == 1 )
  {
    __debugbreak();
  }
  if ( CLinks::m_iMaxUsedLinksId > 262142
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 758, "m_iMaxUsedLinksId <= (LINK_LAST_REAL + 1)") == 1 )
  {
    __debugbreak();
  }
  if ( (CLinks::m_iMaxUsedLinksId & 1) != 0
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 759, "(m_iMaxUsedLinksId & 1) == 0") == 1 )
  {
    __debugbreak();
  }
  v1 = CLinks::Link(CLinks::m_iMaxUsedLinksId);
  if ( CLink::Used(v1)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 760, "!Link(m_iMaxUsedLinksId).Used()") == 1 )
  {
    __debugbreak();
  }
  if ( CLinks::m_iMinFreeLinksId < 2
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 762, "m_iMinFreeLinksId >= LINK_FIRST_REAL") == 1 )
  {
    __debugbreak();
  }
  if ( CLinks::m_iMinFreeLinksId > 262142
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 763, "m_iMinFreeLinksId <= (LINK_LAST_REAL + 1)") == 1 )
  {
    __debugbreak();
  }
  if ( (CLinks::m_iMinFreeLinksId & 1) != 0
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 764, "(m_iMinFreeLinksId & 1) == 0") == 1 )
  {
    __debugbreak();
  }
  v2 = CLinks::Link(CLinks::m_iMinFreeLinksId - 2);
  if ( !CLink::Used(v2)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 765, "Link(m_iMinFreeLinksId - 2).Used()") == 1 )
  {
    __debugbreak();
  }
  if ( CLinks::m_iMinFreeLinksId > CLinks::m_iMaxUsedLinksId
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 767, "m_iMinFreeLinksId <= m_iMaxUsedLinksId") == 1 )
  {
    __debugbreak();
  }
  for ( i = CLinks::m_iMinFreeLinksId; ; i += 2 )
  {
    v3 = CLinks::Link(i);
    if ( !CLink::Used(v3) )
      break;
  }
  CLinks::m_iMinFreeLinksId = i;
  if ( i < 2 && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 782, "m_iMinFreeLinksId >= LINK_FIRST_REAL") == 1 )
    __debugbreak();
  if ( CLinks::m_iMinFreeLinksId > 262142
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 783, "m_iMinFreeLinksId <= (LINK_LAST_REAL + 1)") == 1 )
  {
    __debugbreak();
  }
  if ( (CLinks::m_iMinFreeLinksId & 1) != 0
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 784, "(m_iMinFreeLinksId & 1) == 0") == 1 )
  {
    __debugbreak();
  }
  v4 = CLinks::Link(CLinks::m_iMinFreeLinksId - 2);
  if ( !CLink::Used(v4)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 785, "Link(m_iMinFreeLinksId - 2).Used()") == 1 )
  {
    __debugbreak();
  }
  v5 = CLinks::Link(CLinks::m_iMinFreeLinksId);
  if ( CLink::Used(v5)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 786, "!Link(m_iMinFreeLinksId).Used()") == 1 )
  {
    __debugbreak();
  }
  for ( j = CLinks::m_iMaxUsedLinksId; ; j -= 2 )
  {
    v6 = CLinks::Link(j - 2);
    if ( !CLink::Unused(v6) )
      break;
  }
  CLinks::m_iMaxUsedLinksId = j;
  if ( j < 2 && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 802, "m_iMaxUsedLinksId >= LINK_FIRST_REAL") == 1 )
    __debugbreak();
  if ( CLinks::m_iMaxUsedLinksId > 262142
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 803, "m_iMaxUsedLinksId <= (LINK_LAST_REAL + 1)") == 1 )
  {
    __debugbreak();
  }
  if ( (CLinks::m_iMaxUsedLinksId & 1) != 0
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 804, "(m_iMaxUsedLinksId & 1) == 0") == 1 )
  {
    __debugbreak();
  }
  v7 = CLinks::Link(CLinks::m_iMaxUsedLinksId - 2);
  if ( !CLink::Used(v7)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 805, "Link(m_iMaxUsedLinksId - 2).Used()") == 1 )
  {
    __debugbreak();
  }
  v8 = CLinks::Link(CLinks::m_iMaxUsedLinksId);
  if ( CLink::Used(v8)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 806, "!Link(m_iMaxUsedLinksId).Used()") == 1 )
  {
    __debugbreak();
  }
  if ( CLinks::m_iMinFreeLinksId > CLinks::m_iMaxUsedLinksId
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 808, "m_iMinFreeLinksId <= m_iMaxUsedLinksId") == 1 )
  {
    __debugbreak();
  }
  if ( CLinks::m_iMinFreeLinksId < CLinks::m_iMaxUsedLinksId )
  {
    v15 = CLinks::m_iMinFreeLinksId;
    v12 = a1 + CLinks::m_iMinFreeLinksId;
    while ( 1 )
    {
      v10 = CLinks::Link(v15);
      if ( ((v15 < v12) & CLink::Unused(v10)) == 0 )
        break;
      v15 += 2;
    }
    if ( v15 < v12 )
    {
      v11 = CLinks::Link(v15);
      if ( !CLink::IsHeader(v11)
        && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 841, "Link(iNextUsedLinksId).IsHeader()") == 1 )
      {
        __debugbreak();
      }
      if ( 262142 - CLinks::m_iMaxUsedLinksId < a1 )
        return 0;
      else
        return CLinks::m_iMaxUsedLinksId;
    }
    else
    {
      return CLinks::m_iMinFreeLinksId;
    }
  }
  else if ( 262142 - CLinks::m_iMaxUsedLinksId < a1 )
  {
    return 0;
  }
  else
  {
    return CLinks::m_iMaxUsedLinksId;
  }
}


// address=[0x15e4b00]
// Decompiled from int CLinks::CalculateLinksInfo()

static void __cdecl CLinks::CalculateLinksInfo(void) {
  
  CLink *v0; // eax
  CLink *v1; // eax
  CLink *v2; // eax
  CLink *v3; // eax
  CLink *v4; // eax
  CLink *v5; // eax
  int result; // eax
  int v7; // [esp+0h] [ebp-10h]
  int v8; // [esp+4h] [ebp-Ch]
  int j; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  for ( i = 2; ; i += 2 )
  {
    v0 = CLinks::Link(i);
    if ( !CLink::Used(v0) )
      break;
  }
  v8 = i - 2;
  v7 = i - 2;
  for ( j = i; j <= 262141; j += 2 )
  {
    v1 = CLinks::Link(j);
    if ( CLink::Used(v1) )
    {
      v8 += 2;
      v7 = j;
    }
  }
  CLinks::m_iMinFreeLinksId = i;
  CLinks::m_iMaxUsedLinksId = v7 + 2;
  if ( i < 2 && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1065, "m_iMinFreeLinksId >= LINK_FIRST_REAL") == 1 )
    __debugbreak();
  if ( CLinks::m_iMinFreeLinksId > 262142
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1066, "m_iMinFreeLinksId <= (LINK_LAST_REAL + 1)") == 1 )
  {
    __debugbreak();
  }
  if ( (CLinks::m_iMinFreeLinksId & 1) != 0
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1067, "(m_iMinFreeLinksId & 1) == 0") == 1 )
  {
    __debugbreak();
  }
  v2 = CLinks::Link(CLinks::m_iMinFreeLinksId - 2);
  if ( !CLink::Used(v2)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1068, "Link(m_iMinFreeLinksId - 2).Used()") == 1 )
  {
    __debugbreak();
  }
  v3 = CLinks::Link(CLinks::m_iMinFreeLinksId);
  if ( CLink::Used(v3)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1069, "!Link(m_iMinFreeLinksId).Used()") == 1 )
  {
    __debugbreak();
  }
  if ( CLinks::m_iMaxUsedLinksId < 2
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1071, "m_iMaxUsedLinksId >= LINK_FIRST_REAL") == 1 )
  {
    __debugbreak();
  }
  if ( CLinks::m_iMaxUsedLinksId > 262142
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1072, "m_iMaxUsedLinksId <= (LINK_LAST_REAL + 1)") == 1 )
  {
    __debugbreak();
  }
  if ( (CLinks::m_iMaxUsedLinksId & 1) != 0
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1073, "(m_iMaxUsedLinksId & 1) == 0") == 1 )
  {
    __debugbreak();
  }
  v4 = CLinks::Link(CLinks::m_iMaxUsedLinksId - 2);
  if ( !CLink::Used(v4)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1074, "Link(m_iMaxUsedLinksId - 2).Used()") == 1 )
  {
    __debugbreak();
  }
  v5 = CLinks::Link(CLinks::m_iMaxUsedLinksId);
  if ( CLink::Used(v5)
    && BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1075, "!Link(m_iMaxUsedLinksId).Used()") == 1 )
  {
    __debugbreak();
  }
  result = CLinks::m_iMinFreeLinksId;
  if ( CLinks::m_iMinFreeLinksId <= CLinks::m_iMaxUsedLinksId )
    return result;
  result = BBSupportDbgReport(2, "Pathing\\TilesAndLinks.cpp", 1077, "m_iMinFreeLinksId <= m_iMaxUsedLinksId");
  if ( result == 1 )
    __debugbreak();
  return result;
}


// address=[0x15e4dd0]
// Decompiled from void CLinks::CheckLinksInfo()

static void __cdecl CLinks::CheckLinksInfo(void) {
  
  ;
}


// address=[0x15e7290]
// Decompiled from int __cdecl CLinks::LinksId(const struct CLinkList *a1)

static int __cdecl CLinks::LinksId(class CLinkList const &) {
  
  return (a1 - (const struct CLinkList *)CLinks::m_cLinks) >> 1;
}


// address=[0x424f8d0]
// [Decompilation failed for static int CLinks::m_iLinksPushBackMode]

// address=[0x424f8d4]
// [Decompilation failed for static int CLinks::m_iMinFreeLinksId]

// address=[0x424f8d8]
// [Decompilation failed for static int CLinks::m_iMaxUsedLinksId]

// address=[0x424f8e0]
// [Decompilation failed for static class CLink * CLinks::m_cLinks]

