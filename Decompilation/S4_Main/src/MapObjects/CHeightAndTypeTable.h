#ifndef CHEIGHTANDTYPETABLE_H
#define CHEIGHTANDTYPETABLE_H

#include "defines.h"

extern class CHeightAndTypeTable g_cHeightAndTypeTable;

class CHeightAndTypeTable {
  public:
    // address=[0x2f71cc0]
    int GetObjectFog(int a2, int a3, int a4);

    // address=[0x2f7c6a0]
    CHeightAndTypeTable(void);

    // address=[0x2f81cd0]
    void InitShadeTables(void);

    // address=[0x2f85c90]
    void CalcFogging(int a2, int a3, int a4, int a5, unsigned int &_rShadow, unsigned int &_rLight);

    // address=[0x2f86020]
    int GetAverageShadingValue(int _iShadeA, int _iShadeB);

    // address=[0x2f860e0]
    int GetLightFog(int a2, int a3, int a4, int a5);

    // address=[0x2f86130]
    int GetShadowFog(int a2, int a3, int a4, int a5);

  private:
    struct FOG_ENTRY {
        unsigned int m_uShadowFog;
        unsigned int m_uLightFog;
    };

    struct FROM_TO_TABLE_ELEMENT {
        unsigned __int8 x;
        unsigned __int8 y;
        unsigned __int8 Page;
        unsigned __int8 Flags;
    };

    // Type information members
  public:
    unsigned int uShadeColor[16];
    unsigned int uLightColor[16];
    FROM_TO_TABLE_ELEMENT FromToTable[39][39];
    FOG_ENTRY uFogTable[16][16][8][8];
};

#endif // CHEIGHTANDTYPETABLE_H
