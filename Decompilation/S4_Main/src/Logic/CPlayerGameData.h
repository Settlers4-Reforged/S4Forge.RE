#ifndef CPLAYERGAMEDATA_H
#define CPLAYERGAMEDATA_H

#include "defines.h"
#include "Main/Player/CPlayerStatisticData.h"
#include "Main/Player/CPlayerMagicData.h"

class CPlayerGameData {
public:
    // address=[0x1470ac0]
    CPlayerMagicData &MagicData(void);

    // address=[0x1473250]
    void Clear(void);

    // address=[0x1473300]
    void AddEcoSectorId(int _iESId);

    // address=[0x1473470]
    void DeleteEcoSectorId(int _iESId);

    // address=[0x14734a0]
    void ResetIterator(void) const;

    // address=[0x1473520]
    int GetNextEcoSectorId(void) const;

    // address=[0x1473660]
    virtual void Load(class IS4Chunk &a2);

    // address=[0x14736b0]
    virtual void Save(class IS4Chunk &a2);

    // address=[0x1473700]
    void PostLoadInit(int a2);

    // address=[0x1498020]
    CPlayerGameData(void);

    // address=[0x14982b0]
    ~CPlayerGameData(void);

    // address=[0x14eb7b0]
    void SetPlayerLostFlag(void);

    // address=[0x1508240]
    CPlayerStatisticData &StaticData(void);

    // address=[0x160dad0]
    bool PlayerLost(void) const;

protected:
    // address=[0x1473760]
    void LoadDataBlock(class IS4Chunk &a2, void *_pData, unsigned int _uSize);

    // address=[0x1473800]
    void SaveDataBlock(class IS4Chunk &a2, void *_pData, unsigned int _uSize);

    // address=[0x1474ca0]
    void SetFlags(unsigned int a2);

    // address=[0x14eb410]
    unsigned int Flags(void) const;

    // Type information members
public:
    DWORD m_iFlags;

    CPlayerMagicData                    m_cMagicData;
    CPlayerStatisticData                m_cStatisticData;
    std::list<unsigned short>           m_lEcoSectorId;
    std::list<unsigned short>::iterator m_iEcoSectorIterator;
};


#endif // CPLAYERGAMEDATA_H
