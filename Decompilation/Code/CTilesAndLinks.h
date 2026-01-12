#ifndef CTILESANDLINKS_H
#define CTILESANDLINKS_H

class CTilesAndLinks {
protected:
    // address=[0x15e5000]
    static void __cdecl InitTiles(void);

    // address=[0x15e5020]
    static int __cdecl MoveLinkList(int,int);

    // address=[0x15e51c0]
    static void __cdecl LinksGarbageCollection(int);

    // address=[0x15e5ac0]
    static class CLinkList & __cdecl PushLinksUndef(int);

    // address=[0x15e5b70]
    static class CLinkList & __cdecl PushLinks(class CIntLinkList const &);

    // address=[0x15e5ba0]
    static void __cdecl AddLink(int,int);

    // address=[0x15e5d40]
    static void __cdecl DeleteLink(int,int);

    // address=[0x15e5e30]
    static void __cdecl ReplaceLink(int,int,int);

    // address=[0x15e5ef0]
    static void __cdecl AddLinkList(class CLinkList const &);

    // address=[0x15e5f80]
    static void __cdecl DeleteLinkList(class CLinkList &);

    // address=[0x15e6020]
    static void __cdecl DeleteTile(int);

    // address=[0x15e6090]
    static void __cdecl MergeTileLinkLists(int,int);

};


#endif // CTILESANDLINKS_H
