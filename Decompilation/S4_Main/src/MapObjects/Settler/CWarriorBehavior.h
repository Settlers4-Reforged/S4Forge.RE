#ifndef CWARRIORBEHAVIOR_H
#define CWARRIORBEHAVIOR_H

#include "defines.h"

class CWarriorBehavior {
  public:
    struct SWarriorScanResult {
        int m_iEntityId;
        int m_iOtherDistance;
        int m_iDistance;
        int dwordC;
    };
    struct SWarriorBehaviorData {
        struct CWarriorProperties *m_pProperties;
        unsigned __int8 m_uState;
        char m_iU01;
        unsigned __int16 m_uLastTargetId;
        int m_iDestinationXYOrId;
        int m_iFlags;
        int m_iNextFullUpdate;
    };

    // address=[0x1592e10]
    int WarriorDestinationXY(void) const;

    // address=[0x15ac3a0]
    CWarriorBehavior(void);

    // address=[0x15ac3e0]
    virtual void WarriorInit(class IMovingEntity &_rEntity, int a3, int a4);

    // address=[0x15ac600]
    void WarriorLogicUpdate(class IMovingEntity &_rEntity, unsigned int a3, int a4);

    // address=[0x15acbd0]
    void WarriorVehicleLogicUpdate(class IMovingEntity &_rEntity, unsigned int a3, int a4);

    // address=[0x15ad0e0]
    bool WarriorCheckTargetAndDistance(class IMovingEntity &_rEntity, int _iEntityId);

    // address=[0x15ad1f0]
    bool WarriorValidLastTargetMedic(class IMovingEntity &_rEntity, int _iTargetId);

    // address=[0x15ad2a0]
    bool WarriorValidLastTargetAxeWarrior(class IMovingEntity &a2, int a3);

    // address=[0x15ad2b0]
    bool WarriorValidLastTargetSaboteur(class IMovingEntity &a2, int a3);

    // address=[0x15ad2c0]
    int WarriorAttackCheck1(class IMovingEntity &_rEntity);

    // address=[0x15ad4a0]
    int WarriorAttackCheck15(class IMovingEntity &_rEntity);

    // address=[0x15ad6a0]
    int WarriorAttackCheckBowman(class IMovingEntity &_rEntity);

    // address=[0x15ad840]
    int WarriorAttackCheckMedic(class IMovingEntity &_rEntity);

    // address=[0x15ad980]
    int WarriorAttackCheckAxeWarrior(class IMovingEntity &a2);

    // address=[0x15ad9c0]
    int WarriorAttackCheckSaboteur(class IMovingEntity &_rEntity);

    // address=[0x15ada00]
    int WarriorAttackScan15(class IMovingEntity &_rEntity, int *_pPackedXY);

    // address=[0x15adb50]
    int WarriorAttackScanBowman(class IMovingEntity &_rEntity, int *_pPackedXY);

    // address=[0x15adcd0]
    int WarriorAttackScanMedic(class IMovingEntity &_rEntity, int *_pPackedXY);

    // address=[0x15ade90]
    int WarriorAttackScanAxeWarrior(class IMovingEntity &a2, int *a3);

    // address=[0x15adee0]
    int WarriorAttackScanSaboteur(class IMovingEntity &a2, int *a3);

    // address=[0x15adf10]
    int WarriorEvadeScan15a(class IMovingEntity &_rEntity, int *_pPackedXY);

    // address=[0x15ae0f0]
    void WarriorVehicleAttackScan31(class IMovingEntity &_pEntity, SWarriorScanResult &_rResult);

    // address=[0x15ae660]
    void WarriorVehicleIdleWalkOneStep(class IMovingEntity &a2);

    // address=[0x15ae680]
    void WarriorVehicleMoveWalkOneStep(class IMovingEntity &a2);

    // address=[0x15ae6f0]
    void WarriorVehicleEscortWalkOneStep(class IMovingEntity &_rEntity);

    // address=[0x15ae7b0]
    bool IsValidTarget(class IMovingEntity const &a2, class IEntity const &a3);

    // address=[0x15ae7f0]
    bool IsTargetInAtackRange(class IMovingEntity const &_rEntity, class IEntity const &_rTarget);

    // address=[0x15ae8c0]
    bool WarriorCheckInflu1(class IMovingEntity &_rEntity);

    // address=[0x15ae930]
    bool WarriorCheckOwner9(class IMovingEntity &_rEntity);

    // address=[0x15ae9a0]
    bool WarriorCheckMedic(class IMovingEntity &a2);

    // address=[0x15ae9b0]
    bool WarriorCheckSaboteur(class IMovingEntity &a2);

    // address=[0x15afe80]
    void WarriorVehicleAttackTarget(class IMovingEntity &a2, int a3);

    virtual int WarriorTaskWalkOneStep(class IMovingEntity &a2) = 0;
    virtual void WarriorTaskAttack(class IMovingEntity &a2, int a3, enum T_WARRIOR_ATTACK a4) = 0;
    virtual void WarriorTaskFinished(class IMovingEntity &a2) = 0;
    virtual int WarriorTaskIdleWalk(class IMovingEntity &a2) = 0;

  protected:
    // address=[0x153fdd0]
    SWarriorBehaviorData &CWarriorBehavior::GetWarriorBehaviorData(void);

  private:
    // address=[0x15ae9c0]
    int WarriorPseudoInitWalk(class IMovingEntity &_rEntity, int _iTargetXY);

    // address=[0x15aea80]
    int FindAttackWayPoint(class IMovingEntity &_rEntity, class IEntity &_rWaypointEntity);

    // address=[0x15afa60]
    int WarriorAttackCheck(class IMovingEntity &a2);

    // address=[0x15afa90]
    void WarriorAttackTarget(class IMovingEntity &_rEntity, int a3);

    // address=[0x15afad0]
    static bool __cdecl WarriorCheckTarget(class IEntity const &_rEntity, int _iPlayer, int a3);

    // address=[0x15afb20]
    static bool __cdecl WarriorCheckTarget(int a1, int a2, int a3);

    // address=[0x15afb70]
    int WarriorDestinationId(void) const;

    // address=[0x15afb90]
    void WarriorGetEnemyBitsAndScanMask(class IEntity const &_rEntity, int &_rBits, int &_rScanMask);

    // address=[0x15afc10]
    void WarriorInitWalk(class IMovingEntity &a2, int a3);

    // address=[0x15afc70]
    bool WarriorIsFullUpdate(unsigned int a2) const;

    // address=[0x15afcb0]
    class CWarriorProperties const &WarriorProperties(void) const;

    // address=[0x15afcd0]
    void WarriorSetNextFullUpdate(unsigned int a2, unsigned int a3);

    // address=[0x15afcf0]
    static bool __cdecl WarriorTargetAllowableAndVulnerable(class IEntity const &_rTarget, int a2);

    // address=[0x15afec0]
    int WarriorWalkDestinationXY(class IMovingEntity &_rEntity);

    // Type information members
  public:
    SWarriorBehaviorData m_sWarriorBehaviorData;
};

#endif // CWARRIORBEHAVIOR_H
