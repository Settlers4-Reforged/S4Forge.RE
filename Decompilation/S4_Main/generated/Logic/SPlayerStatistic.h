#ifndef CSTATISTIC_SPLAYERSTATISTIC_H
#define CSTATISTIC_SPLAYERSTATISTIC_H

namespace CStatistic {

class SPlayerStatistic {
public:
    // address=[0x1478cc0]
    void  UpdateFightingStrength(int,int,int,int,bool);

    // address=[0x1478da0]
    void  CalculateFightingStrength(int);

};

} // namespace CStatistic

#endif // CSTATISTIC_SPLAYERSTATISTIC_H
