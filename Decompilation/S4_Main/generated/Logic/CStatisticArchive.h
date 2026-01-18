#ifndef CSTATISTICARCHIVE_H
#define CSTATISTICARCHIVE_H

#include "defines.h"

class CStatisticArchive : public IS4ChunkObject {
public:
    // address=[0x147a420]
     CStatisticArchive(void);

    // address=[0x147a580]
     ~CStatisticArchive(void);

    // address=[0x147a5a0]
    void  TriggerStatistic(void);

private:
    // address=[0x147a7d0]
    void  GetAreaSizeData(int a2);

    // address=[0x147a870]
    void  GetPopulationData(int a2);

    // address=[0x147a900]
    void  GetRessourcesData(int a2);

    // address=[0x147a9a0]
    void  GetSoldierData(int a2);

    // address=[0x147aa40]
    void  GetBeatenEnemiesData(int a2);

    // address=[0x147aae0]
    void  GetLostWarriorsData(int a2);

    // address=[0x147ab80]
    void  GetDestroyedBuildingsData(int a2);

    // address=[0x147ac20]
    void  GetGoodData(int a2);

    // address=[0x147c210]
    virtual void  Load(class IS4Chunk & a2);

    // address=[0x147c3d0]
    virtual void  Save(class IS4Chunk & a2);

};


#endif // CSTATISTICARCHIVE_H
