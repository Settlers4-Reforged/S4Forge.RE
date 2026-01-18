#ifndef CTILE_H
#define CTILE_H

#include "defines.h"

class CTile {
public:
    // address=[0x12fd600]
    int  SectorId(void)const;

    // address=[0x13064a0]
    int  CenterX(void)const;

    // address=[0x13064c0]
    int  CenterY(void)const;

    // address=[0x1306770]
    int  NextSquareTile(void)const;

    // address=[0x13068f0]
    int  OwnerId(void)const;

    // address=[0x130eaf0]
    int  EcoSectorId(void)const;

    // address=[0x133a160]
    enum T_TILING_TYPE  TilingType(void)const;

    // address=[0x1346870]
    class CLinkList &  LinkList(void)const;

    // address=[0x13469c0]
    int  Type(void)const;

    // address=[0x1351a90]
    int  CenterXY(void)const;

    // address=[0x15d6e90]
    static int __cdecl TileTypeOwnerCheckMask(int a1, int a2);

    // address=[0x15d6ed0]
    static int __cdecl TileTypeOwnerCheckMaskFromPlayerBits(int a1);

    // address=[0x15e7360]
    void  SetLinkList(class CLinkList & a2);

    // address=[0x15e7380]
    void  SetSize(int a2);

    // address=[0x15e7410]
    void  SetType(int a2);

    // address=[0x15e74b0]
    static int __cdecl TileType(int a1);

    // address=[0x15e7510]
    bool  Unused(void)const;

    // address=[0x15e7590]
    bool  Used(void)const;

    // address=[0x15f4220]
    void  ChangeSize(int a2);

    // address=[0x15f4a70]
    int  NextFree(void)const;

    // address=[0x15f5340]
    int  PrevFree(void)const;

    // address=[0x15f56f0]
    void  SetCenterXY(int a2);

    // address=[0x15f5710]
    void  SetEcoSectorId(int a2);

    // address=[0x15f5840]
    void  SetSectorId(int a2);

    // address=[0x15f5900]
    int  Size(void)const;

    // address=[0x15f59d0]
    static int __cdecl TileTypeToOwnerId(int a1);

protected:
    // address=[0x15e6f80]
    void  Init(int a2, int a3, class CLinkList & a4);

    // address=[0x15e6fc0]
    void  InitPseudoTile(int a2, class CLinkList & a3);

    // Type information members
private:
    DWORD type;
    DWORD ecoSectorId;
    DWORD center;
    WORD field_C;
    WORD nextSquareTile;
    DWORD LinkList;

};


#endif // CTILE_H
