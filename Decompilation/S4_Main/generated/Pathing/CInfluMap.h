#ifndef CINFLUMAP_H
#define CINFLUMAP_H

class CInfluMap {
public:
    // address=[0x1306520]
    static int __cdecl EnemyValueVW(int,int,int);

    // address=[0x1306580]
    static int __cdecl EnemyValueXY(int,int,int);

    // address=[0x130e900]
    static int __cdecl AllyValueVW(int,int,int);

    // address=[0x13231c0]
    static int __cdecl AllyValueXY(int,int,int);

protected:
    // address=[0x15ddd70]
    static void __cdecl Init(void);

    // address=[0x15ddda0]
    static void __cdecl Done(void);

    // address=[0x15dddb0]
    static void __cdecl ModifyInfluenceMapVW(int,int,int,int);

    // address=[0x41799ec]
    static int m_iInitialized;

    // address=[0x41799f0]
    static unsigned short (* m_uValues)[64][9];

private:
    // address=[0x15ddff0]
    static void __cdecl ModifyValueVW(int,int,int,int);

};


#endif // CINFLUMAP_H
