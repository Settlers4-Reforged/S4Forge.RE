#ifndef CDARKTRIBE_H
#define CDARKTRIBE_H

class CDarkTribe : public IDarkTribe {
public:
    // address=[0x141bad0]
    virtual int  OrderMushroomFarmer(int);

    // address=[0x141bcc0]
    virtual int  OrderSettlerToDarkTemple(int,bool);

    // address=[0x141bde0]
    virtual void  AssociateServantWithMushroomFarm(int);

    // address=[0x141bea0]
    virtual class CBuilding *  GetDarkTempleIfReady(int);

    // address=[0x141cb10]
    virtual void  ChangePositionOrSurroundingToDarkLand(int,int,bool);

    // address=[0x141cca0]
    virtual void  ChangePositionToGreenLand(int,int,int);

    // address=[0x141cce0]
    virtual bool  IsMushroomFarmPositionValid(int,int,int);

    // address=[0x141cec0]
    virtual bool  IsObjectSurrounded(int,bool);

    // address=[0x141d760]
     CDarkTribe(void);

protected:
    // address=[0x141bf00]
    int  GetDarkTempleId(int);

    // address=[0x141bf40]
    bool  GetDarkTempleIfReady(int,class CBuilding * &,class CDarkTempleRole * &);

    // address=[0x141c000]
    int  FindMushroomFarmForServant(int);

    // address=[0x141c250]
    void  OrderServantToMushroomFarm(int,int);

    // address=[0x141c470]
    void  ChangeElementToDarkOrGreen(int,int,bool,int);

    // address=[0x141c680]
    void  ChangeObjectToDarkOrGreen(int,int,int,bool);

    // address=[0x141c840]
    void  FillUnderObject(int,int,bool);

    // address=[0x141c9a0]
    void  SetHolesDarkOrGreen(int,int,bool,int);

};


#endif // CDARKTRIBE_H
