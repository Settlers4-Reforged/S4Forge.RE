#ifndef IGROUPMGR_H
#define IGROUPMGR_H

class IGroupMgr : public IS4ChunkObject {
public:
    // address=[0x1550a40]
    static void __cdecl FillGroupSideBar(class CInfoExchange *,bool,int);

    // address=[0x1550a60]
    static void __cdecl FillMagicSideBar(class CInfoExchange *,bool,int);

    // address=[0x15525e0]
     IGroupMgr(void);

};


#endif // IGROUPMGR_H
