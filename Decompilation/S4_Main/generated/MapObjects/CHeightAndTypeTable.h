#ifndef CHEIGHTANDTYPETABLE_H
#define CHEIGHTANDTYPETABLE_H

#include "defines.h"

class CHeightAndTypeTable {
public:
    // address=[0x2f71cc0]
    int  GetObjectFog(int a2, int a3, int a4);

    // address=[0x2f7c6a0]
     CHeightAndTypeTable(void);

    // address=[0x2f81cd0]
    void  InitShadeTables(void);

    // address=[0x2f85c90]
    void  CalcFogging(int a2, int a3, int a4, int a5, unsigned int & a6, unsigned int & a7);

    // address=[0x2f86020]
    int  GetAverageShadingValue(int a2, int a3);

    // address=[0x2f860e0]
    int  GetLightFog(int a2, int a3, int a4, int a5);

    // address=[0x2f86130]
    int  GetShadowFog(int a2, int a3, int a4, int a5);

};


#endif // CHEIGHTANDTYPETABLE_H
