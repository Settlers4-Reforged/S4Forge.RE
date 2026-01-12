#ifndef CTILINGWORLD_H
#define CTILINGWORLD_H

class CTilingWorld {
public:
    // address=[0x15f5b60]
    static int __cdecl WorldGroundType(int);

    // address=[0x15f5bd0]
    static bool __cdecl WorldInInnerWorld16(int,int);

    // address=[0x15f5c40]
    static bool __cdecl WorldInInnerWorld1(int,int);

    // address=[0x15f5cb0]
    static bool __cdecl WorldInInnerWorld2(int,int);

    // address=[0x15f5d20]
    static bool __cdecl WorldInWorld(int,int);

    // address=[0x15f5d80]
    static bool __cdecl WorldInWorldPackedXY(int);

    // address=[0x15f5df0]
    static int __cdecl WorldIndex(int);

    // address=[0x15f5e20]
    static int __cdecl WorldIndex(int,int);

    // address=[0x15f5e40]
    static bool __cdecl WorldIsBlockedLand(int);

    // address=[0x15f5e80]
    static bool __cdecl WorldIsBuildingOrDecoObjectBitSet(int);

    // address=[0x15f5ec0]
    static int __cdecl WorldIsGroundTypeWater(int);

    // address=[0x15f5ee0]
    static bool __cdecl WorldIsWater(int);

    // address=[0x15f5f10]
    static int __cdecl WorldNeighborRelIndex(int);

    // address=[0x15f5f30]
    static int __cdecl WorldNumberOfElements(void);

    // address=[0x15f6030]
    static int __cdecl WorldSortedNeighborRelIndex(int);

    // address=[0x15f6050]
    static int __cdecl WorldSurroundingRelIndex(int);

    // address=[0x15f6070]
    static int __cdecl WorldWidthHeight(void);

    // address=[0x42cf8e0]
    static int m_iWorldInterfaceInitialized;

    // address=[0x42cf8e4]
    static unsigned int m_uWorldWidthHeight;

    // address=[0x42cf8e8]
    static unsigned int m_uWorldSize;

    // address=[0x42cf8ec]
    static struct T_GFX_MAP_ELEMENT * m_pWorldGfxMapElements;

    // address=[0x42cf8f0]
    static unsigned char * m_pWorldFlagBitsLayer;

    // address=[0x42cf8f4]
    static unsigned char * m_pWorldFogLayer;

    // address=[0x42cf8f8]
    static int * m_iWorldNeighborRelIndices;

    // address=[0x42cf928]
    static int * m_iWorldSortedNeighborRelIndices;

    // address=[0x42cf940]
    static int * m_iWorldSurroundingRelIndices;

protected:
    // address=[0x15e75d0]
    static void __cdecl WorldInterfaceInit(int,struct T_GFX_MAP_ELEMENT *,unsigned char *,unsigned char *);

    // address=[0x15e7960]
    static void __cdecl WorldInterfaceDone(void);

    // address=[0x15f5b00]
    static void __cdecl WorldClearBlockedLandFlag(int);

    // address=[0x15f5b30]
    static void __cdecl WorldClearGfxBorderstoneBit(int);

    // address=[0x15f5fd0]
    static void __cdecl WorldSetBlockedLandFlag(int);

    // address=[0x15f6000]
    static void __cdecl WorldSetGfxBorderstoneBit(int);

};


#endif // CTILINGWORLD_H
