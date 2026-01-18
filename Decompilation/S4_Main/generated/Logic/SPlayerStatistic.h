#ifndef CSTATISTIC_SPLAYERSTATISTIC_H
#define CSTATISTIC_SPLAYERSTATISTIC_H

#include "defines.h"

namespace CStatistic {

class SPlayerStatistic {
public:
    // address=[0x1478cc0]
    void  UpdateFightingStrength(int a2, int a3, int a4, int a5, bool a6);

    // address=[0x1478da0]
    void  CalculateFightingStrength(int a2);

};

} // namespace CStatistic

#endif // CSTATISTIC_SPLAYERSTATISTIC_H
