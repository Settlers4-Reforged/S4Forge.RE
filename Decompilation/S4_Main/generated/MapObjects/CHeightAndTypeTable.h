#ifndef CHEIGHTANDTYPETABLE_H
#define CHEIGHTANDTYPETABLE_H

class CHeightAndTypeTable {
public:
    // address=[0x2f71cc0]
    int  GetObjectFog(int,int,int);

    // address=[0x2f7c6a0]
     CHeightAndTypeTable(void);

    // address=[0x2f81cd0]
    void  InitShadeTables(void);

    // address=[0x2f85c90]
    void  CalcFogging(int,int,int,int,unsigned int &,unsigned int &);

    // address=[0x2f86020]
    int  GetAverageShadingValue(int,int);

    // address=[0x2f860e0]
    int  GetLightFog(int,int,int,int);

    // address=[0x2f86130]
    int  GetShadowFog(int,int,int,int);

};


#endif // CHEIGHTANDTYPETABLE_H
