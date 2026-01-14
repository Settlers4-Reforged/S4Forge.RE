#ifndef CAISHAMAN_H
#define CAISHAMAN_H

class CAIShaman : public IAIShaman {
public:
    // address=[0x13264f0]
    virtual bool  FindGlobalTargetForShaman(int,int,int &,int &,bool);

    // address=[0x13267b0]
    virtual bool  FindNearTargetForShaman(int,int,int &,int &);

    // address=[0x1326840]
    virtual int  FindTeleportationTarget(int &,int &,int);

    // address=[0x1326950]
    virtual int  FindFieldToRot(int &,int &,int);

    // address=[0x1326d60]
     CAIShaman(void);

protected:
    // address=[0x1326a60]
    int  EvaluateTargetPosition(int,int);

    // address=[0x1326af0]
    void  FindBetterTargetBuilding(int,int,int &,int &,int &,bool);

};


#endif // CAISHAMAN_H
