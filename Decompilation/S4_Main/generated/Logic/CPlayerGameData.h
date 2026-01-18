#ifndef CPLAYERGAMEDATA_H
#define CPLAYERGAMEDATA_H

#include "defines.h"

class CPlayerGameData {
public:
    // address=[0x1470ac0]
    class CPlayerMagicData &  MagicData(void);

    // address=[0x1473250]
    void  Clear(void);

    // address=[0x1473300]
    void  AddEcoSectorId(int a2);

    // address=[0x1473470]
    void  DeleteEcoSectorId(int a2);

    // address=[0x14734a0]
    void  ResetIterator(void)const;

    // address=[0x1473520]
    int  GetNextEcoSectorId(void)const;

    // address=[0x1473660]
    virtual void  Load(class IS4Chunk & a2);

    // address=[0x14736b0]
    virtual void  Save(class IS4Chunk & a2);

    // address=[0x1473700]
    void  PostLoadInit(int a2);

    // address=[0x1498020]
     CPlayerGameData(void);

    // address=[0x14982b0]
     ~CPlayerGameData(void);

    // address=[0x14eb7b0]
    void  SetPlayerLostFlag(void);

    // address=[0x1508240]
    class CPlayerStatisticData &  StaticData(void);

    // address=[0x160dad0]
    bool  PlayerLost(void)const;

protected:
    // address=[0x1473760]
    void  LoadDataBlock(class IS4Chunk & a2, void * a3, unsigned int a4);

    // address=[0x1473800]
    void  SaveDataBlock(class IS4Chunk & a2, void * a3, unsigned int a4);

    // address=[0x1474ca0]
    void  SetFlags(unsigned int a2);

    // address=[0x14eb410]
    unsigned int  Flags(void)const;

};


#endif // CPLAYERGAMEDATA_H
