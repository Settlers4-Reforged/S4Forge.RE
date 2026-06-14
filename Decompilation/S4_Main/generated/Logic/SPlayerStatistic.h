#ifndef CSTATISTIC_SPLAYERSTATISTIC_H
#define CSTATISTIC_SPLAYERSTATISTIC_H

#include "defines.h"

namespace CStatistic {

class SPlayerStatistic {
public:
    // address=[0x1478cc0]
    void  UpdateFightingStrength(int _iPlayerId, int _iBoards, int _iStone, int _iGold, bool _bEyeCatcher);

    // address=[0x1478da0]
    void  CalculateFightingStrength(int _iOwnerId);

};

} // namespace CStatistic

#endif // CSTATISTIC_SPLAYERSTATISTIC_H
