#ifndef CFERRYSHIP_H
#define CFERRYSHIP_H

class CFerryShip : public CShip {
public:
    // address=[0x14009a0]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x1596310]
    virtual void  Delete(void);

    // address=[0x1596500]
    virtual int const  GetMeetingPointXY(enum OBJ_TYPE,int);

    // address=[0x15965f0]
    enum TFerryRequestResult  CFerryShip::Request(int);

    // address=[0x15969f0]
    virtual void  FillDialog(bool);

    // address=[0x1596e10]
    virtual void  VehicleLogicUpdate(void);

    // address=[0x15971a0]
    virtual void  Unload(void);

    // address=[0x1597330]
    bool  EmergencyReload(int);

    // address=[0x1597530]
    virtual void  EntityOrderCanceled(int);

    // address=[0x1597760]
    virtual void  EntityEnter(int);

    // address=[0x1597840]
    bool  CanLoad(int,int);

    // address=[0x15978d0]
    bool  AddEntityToFerry(int);

    // address=[0x1597aa0]
    virtual void  CountCargo(class ICargoCounter &);

    // address=[0x1597b50]
    static void * __cdecl operator new(unsigned int);

    // address=[0x1597b70]
    static void __cdecl operator delete(void *);

    // address=[0x1597bb0]
    virtual struct SGfxObjectInfo *  GetGfxInfos(void);

    // address=[0x1597bf0]
     CFerryShip(std::istream &);

    // address=[0x1597e50]
    virtual void  Store(std::ostream &);

    // address=[0x159ba90]
    virtual unsigned long  ClassID(void)const;

    // address=[0x159bae0]
    static int __cdecl GetCargoSize(int,int);

    // address=[0x3d8bfb0]
    static unsigned long m_iClassID;

protected:
    // address=[0x1598010]
     CFerryShip(int,int,int,int,int,int,bool);

    // address=[0x15980c0]
    virtual  ~CFerryShip(void);

private:
    // address=[0x15980f0]
    bool  OnShipArrived(void);

    // address=[0x1598140]
    bool  OnLoad(void);

    // address=[0x1598330]
    int  CalcDistanceToLand(int &,int &);

    // address=[0x1598440]
    bool  FindLoadPosition(int,int &,int &);

    // address=[0x15986b0]
    bool  FindUnLoadPosition(int,int &,int &);

    // address=[0x15988e0]
    bool  UnloadAt(int,int,int);

    // address=[0x1598a10]
    void  ClearCargo(void);

    // address=[0x1598b80]
    void  DeleteCargo(class CFerryShip::CCargo &);

    // address=[0x1598cf0]
    bool  HasRegisterdCargo(int);

    // address=[0x1598d50]
    virtual void  NotifyDetach(int);

    // address=[0x159bb10]
    enum TFerryJob  CFerryShip::GetFerryJob(void);

    // address=[0x159bb70]
    void  SetFerryJob(enum CFerryShip::TFerryJob);

};


#endif // CFERRYSHIP_H
