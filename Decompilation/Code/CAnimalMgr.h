#ifndef CANIMALMGR_H
#define CANIMALMGR_H

class CAnimalMgr {
public:
    // address=[0x14dacb0]
     CAnimalMgr(void);

    // address=[0x14dade0]
     ~CAnimalMgr(void);

    // address=[0x14dae70]
    void  Init(void);

    // address=[0x14db3b0]
    void  ShutDown(void);

    // address=[0x14db4d0]
    void  Clear(void);

    // address=[0x14db510]
    int  AddAnimal(int,int,int);

    // address=[0x14db630]
    int  AddAnimalAsEffect(int,int,int,int);

    // address=[0x14db6d0]
    void  DeleteAnimal(int);

    // address=[0x14db7b0]
    void  SpawnAnimalBehindTree(int,int,int);

    // address=[0x14db940]
    void  SpawnAnimalInTown(int,int,int);

    // address=[0x14dbae0]
    void  SpawnAnimalOnGround(int,int,int,int);

    // address=[0x14dbbc0]
    void  SpawnAnimalOnDarkLand(int,int,int);

    // address=[0x14dbca0]
    void  Update(void);

    // address=[0x14dbe60]
    void  UpdateMovingEffect(unsigned int,unsigned int,unsigned int,unsigned int);

    // address=[0x14dbe90]
    void  AddButterfly(int,int);

    // address=[0x14dbef0]
    bool  IsButterflyLand(int,int);

    // address=[0x14dbf60]
    bool  CheckButterflyUnderground(int,int);

    // address=[0x14dc030]
    bool  CheckButterflyUndergroundFast(int,int);

    // address=[0x14dc0a0]
    bool  IsBirdLand(int,int);

    // address=[0x14dc110]
    bool  CheckBirdUnderground(int,int);

    // address=[0x14dc290]
    bool  IsSeagullLand(int,int);

    // address=[0x14dc300]
    bool  CheckSeagullUnderground(int,int);

    // address=[0x14dc460]
    bool  CheckSeagullUndergroundAddPosition(int,int);

    // address=[0x14dc590]
    void  Store(class S4::CMapFile &);

    // address=[0x14dc840]
    void  Load(class S4::CMapFile &);

    // address=[0x14dc9f0]
    bool  IsHuntable(int);

    // address=[0x14dca20]
    struct SAnimalData *  GetAnimalDataPtr(int);

    // address=[0x14dca50]
    struct SAnimalData *  GetAnimalEffectDataPtr(int);

    // address=[0x14dfeb0]
    static class CAnimal & __cdecl Animal(int);

    // address=[0x15787b0]
    static class CAnimal * __cdecl GetAnimalPtr(int);

private:
    // address=[0x14dca80]
    void  LoadAnimalData(void);

    // address=[0x14dd3d0]
    static void __cdecl InitAnimalJobs(class CAnimal *,int);

    // address=[0x14dd710]
    void  SpawnAnimal(int,int);

    // address=[0x14dd980]
    static int __cdecl Create(int,int,int);

    // address=[0x14ddaa0]
    void  ShowEffect(void);

    // address=[0x14ddba0]
    void  ShowWaterEffect(int,int);

    // address=[0x14ddd50]
    void  ShowFishResources(void);

    // address=[0x14ddf20]
    int  CountBuildingSquares(int,int);

    // address=[0x14ddfc0]
    bool  IsTileFree(int);

    // address=[0x14de020]
    bool  IsLandscapeAround(enum T_RESOURCE_LANDTYPE,int,int);

    // address=[0x14de0b0]
    void  AddButterflies(void);

    // address=[0x14de1d0]
    void  AddBirds(void);

    // address=[0x14de350]
    void  AddSeagulls(void);

    // address=[0x14de4d0]
    void  AddDucks(void);

    // address=[0x14dfed0]
    unsigned int  EffectRandomNumber(void);

    // address=[0x14e2f70]
    void *  Alloc(unsigned int);

    // address=[0x14e2fb0]
    void  Dealloc(void *);

    // address=[0x4032ad0]
    static struct SAnimalData * m_asAnimalData;

    // address=[0x4032da0]
    static struct SAnimalData * m_asAnimalEffectData;

};


#endif // CANIMALMGR_H
