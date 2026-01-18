#ifndef CTILESANDLINKS_H
#define CTILESANDLINKS_H

#include "defines.h"

class CTilesAndLinks {
protected:
    // address=[0x15e5000]
    static void __cdecl InitTiles(void);

    // address=[0x15e5020]
    static int __cdecl MoveLinkList(int a1, int a2);

    // address=[0x15e51c0]
    static void __cdecl LinksGarbageCollection(int a1);

    // address=[0x15e5ac0]
    static class CLinkList & __cdecl PushLinksUndef(int a1);

    // address=[0x15e5b70]
    static class CLinkList & __cdecl PushLinks(class CIntLinkList const & a1);

    // address=[0x15e5ba0]
    static void __cdecl AddLink(int a1, int a2);

    // address=[0x15e5d40]
    static void __cdecl DeleteLink(int a1, int a2);

    // address=[0x15e5e30]
    static void __cdecl ReplaceLink(int a1, int a2, int a3);

    // address=[0x15e5ef0]
    static void __cdecl AddLinkList(class CLinkList const & a1);

    // address=[0x15e5f80]
    static void __cdecl DeleteLinkList(class CLinkList & a1);

    // address=[0x15e6020]
    static void __cdecl DeleteTile(int a1);

    // address=[0x15e6090]
    static void __cdecl MergeTileLinkLists(int a1, int a2);

};


#endif // CTILESANDLINKS_H
