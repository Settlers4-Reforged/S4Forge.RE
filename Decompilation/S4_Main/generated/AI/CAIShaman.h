#ifndef CAISHAMAN_H
#define CAISHAMAN_H

#include "defines.h"

class CAIShaman : public IAIShaman {
public:
    // address=[0x13264f0]
    virtual bool  FindGlobalTargetForShaman(int player, int a3, int & x, int & y, bool a6);

    // address=[0x13267b0]
    virtual bool  FindNearTargetForShaman(int a2, int a3, int & a4, int & a5);

    // address=[0x1326840]
    virtual int  FindTeleportationTarget(int & a2, int & a3, int a4);

    // address=[0x1326950]
    virtual int  FindFieldToRot(int & a2, int & a3, int a4);

    // address=[0x1326d60]
     CAIShaman(void);

protected:
    // address=[0x1326a60]
    int  EvaluateTargetPosition(int a2, int a3);

    // address=[0x1326af0]
    void  FindBetterTargetBuilding(int a2, int a3, int & a4, int & a5, int & a6, bool a7);

};


#endif // CAISHAMAN_H
