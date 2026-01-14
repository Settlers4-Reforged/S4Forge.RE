#ifndef CWARRIORBEHAVIOR_H
#define CWARRIORBEHAVIOR_H

class CWarriorBehavior {
public:
    // address=[0x1592e10]
    int  WarriorDestinationXY(void)const;

    // address=[0x15ac3a0]
     CWarriorBehavior(void);

    // address=[0x15ac3e0]
    virtual void  WarriorInit(class IMovingEntity &,int,int);

    // address=[0x15ac600]
    void  WarriorLogicUpdate(class IMovingEntity &,unsigned int,int);

    // address=[0x15acbd0]
    void  WarriorVehicleLogicUpdate(class IMovingEntity &,unsigned int,int);

    // address=[0x15ad0e0]
    bool  WarriorCheckTargetAndDistance(class IMovingEntity &,int);

    // address=[0x15ad1f0]
    bool  WarriorValidLastTargetMedic(class IMovingEntity &,int);

    // address=[0x15ad2a0]
    bool  WarriorValidLastTargetAxeWarrior(class IMovingEntity &,int);

    // address=[0x15ad2b0]
    bool  WarriorValidLastTargetSaboteur(class IMovingEntity &,int);

    // address=[0x15ad2c0]
    int  WarriorAttackCheck1(class IMovingEntity &);

    // address=[0x15ad4a0]
    int  WarriorAttackCheck15(class IMovingEntity &);

    // address=[0x15ad6a0]
    int  WarriorAttackCheckBowman(class IMovingEntity &);

    // address=[0x15ad840]
    int  WarriorAttackCheckMedic(class IMovingEntity &);

    // address=[0x15ad980]
    int  WarriorAttackCheckAxeWarrior(class IMovingEntity &);

    // address=[0x15ad9c0]
    int  WarriorAttackCheckSaboteur(class IMovingEntity &);

    // address=[0x15ada00]
    int  WarriorAttackScan15(class IMovingEntity &,int *);

    // address=[0x15adb50]
    int  WarriorAttackScanBowman(class IMovingEntity &,int *);

    // address=[0x15adcd0]
    int  WarriorAttackScanMedic(class IMovingEntity &,int *);

    // address=[0x15ade90]
    int  WarriorAttackScanAxeWarrior(class IMovingEntity &,int *);

    // address=[0x15adee0]
    int  WarriorAttackScanSaboteur(class IMovingEntity &,int *);

    // address=[0x15adf10]
    int  WarriorEvadeScan15a(class IMovingEntity &,int *);

    // address=[0x15ae0f0]
    void  WarriorVehicleAttackScan31(class IMovingEntity &,struct CWarriorBehavior::SWarriorScanResult &);

    // address=[0x15ae660]
    void  WarriorVehicleIdleWalkOneStep(class IMovingEntity &);

    // address=[0x15ae680]
    void  WarriorVehicleMoveWalkOneStep(class IMovingEntity &);

    // address=[0x15ae6f0]
    void  WarriorVehicleEscortWalkOneStep(class IMovingEntity &);

    // address=[0x15ae7b0]
    bool  IsValidTarget(class IMovingEntity const &,class IEntity const &);

    // address=[0x15ae7f0]
    bool  IsTargetInAtackRange(class IMovingEntity const &,class IEntity const &);

    // address=[0x15ae8c0]
    bool  WarriorCheckInflu1(class IMovingEntity &);

    // address=[0x15ae930]
    bool  WarriorCheckOwner9(class IMovingEntity &);

    // address=[0x15ae9a0]
    bool  WarriorCheckMedic(class IMovingEntity &);

    // address=[0x15ae9b0]
    bool  WarriorCheckSaboteur(class IMovingEntity &);

    // address=[0x15afe80]
    void  WarriorVehicleAttackTarget(class IMovingEntity &,int);

protected:
    // address=[0x153fdd0]
    struct SWarriorBehaviorData &  CWarriorBehavior::GetWarriorBehaviorData(void);

private:
    // address=[0x15ae9c0]
    int  WarriorPseudoInitWalk(class IMovingEntity &,int);

    // address=[0x15aea80]
    int  FindAttackWayPoint(class IMovingEntity &,class IEntity &);

    // address=[0x15afa60]
    int  WarriorAttackCheck(class IMovingEntity &);

    // address=[0x15afa90]
    void  WarriorAttackTarget(class IMovingEntity &,int);

    // address=[0x15afad0]
    static bool __cdecl WarriorCheckTarget(class IEntity const &,int,int);

    // address=[0x15afb20]
    static bool __cdecl WarriorCheckTarget(int,int,int);

    // address=[0x15afb70]
    int  WarriorDestinationId(void)const;

    // address=[0x15afb90]
    void  WarriorGetEnemyBitsAndScanMask(class IEntity const &,int &,int &);

    // address=[0x15afc10]
    void  WarriorInitWalk(class IMovingEntity &,int);

    // address=[0x15afc70]
    bool  WarriorIsFullUpdate(unsigned int)const;

    // address=[0x15afcb0]
    class CWarriorProperties const &  WarriorProperties(void)const;

    // address=[0x15afcd0]
    void  WarriorSetNextFullUpdate(unsigned int,unsigned int);

    // address=[0x15afcf0]
    static bool __cdecl WarriorTargetAllowableAndVulnerable(class IEntity const &,int);

    // address=[0x15afec0]
    int  WarriorWalkDestinationXY(class IMovingEntity &);

};


#endif // CWARRIORBEHAVIOR_H
