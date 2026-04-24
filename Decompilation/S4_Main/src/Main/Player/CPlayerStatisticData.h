#ifndef CPLAYERSTATISTICDATA_H
#define CPLAYERSTATISTICDATA_H

#include "defines.h"

class CPlayerStatisticData {
public:
    // address=[0x1508170]
    void IncreaseMushroomFarmsDestroyed(void);

    // address=[0x160daa0]
    int MushroomFarmsDestroyed(void) const;

    // address=[0x160db50]
    int ServantsFreed(void) const;

protected:
    friend class CPlayerGameData;

    // address=[0x1474c70]
    void Clear(void);

    // Type information members
public:
    int m_iMushroomFarmsDestroyed;
    int m_iServantsFreed;
};


#endif // CPLAYERSTATISTICDATA_H
