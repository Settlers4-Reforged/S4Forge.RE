#ifndef CLINKS_H
#define CLINKS_H

#include "defines.h"

class CLinks {
public:
    // address=[0x15e3cf0]
    static void __cdecl InitLinks(void);

    // address=[0x15e3db0]
    static void __cdecl DeactivateLinksPushBackMode(void);

    // address=[0x15e3e00]
    static class CLinkList & __cdecl PushLinksBack(class CIntLinkList const & a1);

    // address=[0x15e3e90]
    static int __cdecl PushLinksUndef(int a1);

    // address=[0x15e70b0]
    static bool __cdecl IsValidRealLinkList(class CLinkList const & a1);

    // address=[0x15e7170]
    static bool __cdecl IsValidUsedLinkList(class CLinkList const & a1);

    // address=[0x15e7250]
    static class CLink const & __cdecl Link(int a1);

    // address=[0x15e7270]
    static class CLinkList & __cdecl LinkList(int a1);

protected:
    // address=[0x15e4050]
    static void __cdecl LinkListMarkAsUnused(class CLinkList & a1);

    // address=[0x15e4140]
    static void __cdecl LinkListPushLinkTileId(class CLinkList & a1, int a2);

    // address=[0x15e4410]
    static bool __cdecl LinkListRemoveLinkTileId(class CLinkList & a1, int a2);

    // address=[0x15e44f0]
    static bool __cdecl LinkListReplaceLink(class CLinkList & a1, int a2, int a3);

    // address=[0x15e4550]
    static int __cdecl SearchForUnusedLinkEntries(int a1);

    // address=[0x15e4b00]
    static void __cdecl CalculateLinksInfo(void);

    // address=[0x15e4dd0]
    static void __cdecl CheckLinksInfo(void);

    // address=[0x15e7290]
    static int __cdecl LinksId(class CLinkList const & a1);

    // address=[0x424f8d0]
    static int m_iLinksPushBackMode;

    // address=[0x424f8d4]
    static int m_iMinFreeLinksId;

    // address=[0x424f8d8]
    static int m_iMaxUsedLinksId;

    // address=[0x424f8e0]
    static class CLink * m_cLinks;

};


#endif // CLINKS_H
