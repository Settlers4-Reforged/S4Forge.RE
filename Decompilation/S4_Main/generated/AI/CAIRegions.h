#ifndef CAIREGIONS_H
#define CAIREGIONS_H

class CAIRegions {
public:
    // address=[0x1311690]
    void  DefineRegion(int,int,int,int);

    // address=[0x1311700]
    void  ClearRegion(int);

    // address=[0x1311790]
    void  ClearAllRegions(void);

    // address=[0x13117e0]
    void  ClearAllPlayerRegionFlags(void);

    // address=[0x1311810]
    void  Load(class IS4Chunk &);

    // address=[0x13118b0]
    void  Save(class IS4Chunk &);

    // address=[0x1311d90]
    static bool __cdecl IsValidRegionId(int);

    // address=[0x131ee40]
    void  SetPlayerRegionFlagBits(int,int,int);

protected:
    // address=[0x1311920]
    void  CalculateLastUsedRegionId(void);

};


#endif // CAIREGIONS_H
