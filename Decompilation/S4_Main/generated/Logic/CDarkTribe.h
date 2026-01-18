#ifndef CDARKTRIBE_H
#define CDARKTRIBE_H

#include "defines.h"

class CDarkTribe : public IDarkTribe {
public:
    // address=[0x141bad0]
    virtual int  OrderMushroomFarmer(int a2);

    // address=[0x141bcc0]
    virtual int  OrderSettlerToDarkTemple(int a2, bool a3);

    // address=[0x141bde0]
    virtual void  AssociateServantWithMushroomFarm(int a2);

    // address=[0x141bea0]
    virtual class CBuilding *  GetDarkTempleIfReady(int a2);

    // address=[0x141cb10]
    virtual void  ChangePositionOrSurroundingToDarkLand(int a2, int a3, bool a4);

    // address=[0x141cca0]
    virtual void  ChangePositionToGreenLand(int a2, int a3, int a4);

    // address=[0x141cce0]
    virtual bool  IsMushroomFarmPositionValid(int a2, int a3, int a4);

    // address=[0x141cec0]
    virtual bool  IsObjectSurrounded(int a2, bool a3);

    // address=[0x141d760]
     CDarkTribe(void);

protected:
    // address=[0x141bf00]
    int  GetDarkTempleId(int a2);

    // address=[0x141bf40]
    bool  GetDarkTempleIfReady(int a2, class CBuilding * & a3, class CDarkTempleRole * & a4);

    // address=[0x141c000]
    int  FindMushroomFarmForServant(int a2);

    // address=[0x141c250]
    void  OrderServantToMushroomFarm(int a2, int a3);

    // address=[0x141c470]
    void  ChangeElementToDarkOrGreen(int a2, int a3, bool a4, int a5);

    // address=[0x141c680]
    void  ChangeObjectToDarkOrGreen(int a2, int a3, int a4, bool a5);

    // address=[0x141c840]
    void  FillUnderObject(int a2, int a3, bool a4);

    // address=[0x141c9a0]
    void  SetHolesDarkOrGreen(int a2, int a3, bool a4, int a5);

};


#endif // CDARKTRIBE_H
