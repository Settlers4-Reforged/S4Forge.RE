#ifndef CAIREGIONS_H
#define CAIREGIONS_H

#include "CAIRegion.h"
#include "defines.h"

// address=[0x3e95500]
extern class CAIRegions g_cAIRegions;

class CAIRegions {
  public:
    // address=[0x1311690]
    void DefineRegion(int _iRegionId, int a3, int a4, int a5);

    // address=[0x1311700]
    void ClearRegion(int _iRegionId);

    // address=[0x1311790]
    void ClearAllRegions(void);

    // address=[0x13117e0]
    void ClearAllPlayerRegionFlags(void);

    // address=[0x1311810]
    void Load(class IS4Chunk &a2);

    // address=[0x13118b0]
    void Save(class IS4Chunk &a2);

    // address=[0x1311d90]
    static bool __cdecl IsValidRegionId(int a1);

    // address=[0x131ee40]
    void SetPlayerRegionFlagBits(int _iPlayerId, int _iRegionId, int a4);

  protected:
    // address=[0x1311920]
    void CalculateLastUsedRegionId(void);

    // Type information members
  public:
    int m_iLastUsedRegionId;
    CAIRegion m_cRegions[16];
    int m_vPlayerRegionFlags[9][16];
};

#endif // CAIREGIONS_H
