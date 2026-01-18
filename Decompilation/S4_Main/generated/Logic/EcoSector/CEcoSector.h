#ifndef CECOSECTOR_H
#define CECOSECTOR_H

#include "defines.h"

class CEcoSector : public CPersistence {
public:
    // address=[0x130ee50]
    int  GetUniqueId(void)const;

    // address=[0x130f230]
    int  Owner(void)const;

    // address=[0x13466a0]
    int  ExtraMinCarrierForRecruitment(void)const;

    // address=[0x1346890]
    int  MinCarrier(void)const;

    // address=[0x1400680]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x14299b0]
    int  NrOfSettler(int a2)const;

    // address=[0x1429a00]
    void  ChangeNrOfSettler(int a2, int a3);

    // address=[0x1429ab0]
    int  GetSettlerOffer(int a2)const;

    // address=[0x1429ad0]
    void  SetSettlerOffer(int a2, int a3);

    // address=[0x1429c80]
    void  SetSettlerOfferIncDisplay(int a2, int a3);

    // address=[0x1429ce0]
    void  GetSettlerOutOfOffer(int a2);

    // address=[0x1429ed0]
    void  GetSettlerOutOfOfferDecDisplay(int a2);

    // address=[0x1429f70]
    void  GetCarrierOutOfOfferAndSetNextSettlerType(int a2, int a3);

    // address=[0x142a020]
    void  ResetCarrierNextSettlerTypeAndDecrementOrder(int a2);

    // address=[0x142a0c0]
    int  OrderWorker(int a2, int a3);

    // address=[0x142a580]
    int  CallWorker(int a2, int a3);

    // address=[0x142a6f0]
    int  GetNearestSettler(int a2, int a3, int a4);

    // address=[0x142a7f0]
    bool  HaveFreeCarrier(void)const;

    // address=[0x142a830]
    int  NrOfGoods(int a2)const;

    // address=[0x142a8a0]
    int  GetGoodOffer(int a2)const;

    // address=[0x142a8c0]
    void  SetGoodOffer(int a2, int a3);

    // address=[0x142aa20]
    void  GetPileOutOfOffer(int a2, int a3);

    // address=[0x142ab50]
    void  RequestGood(int a1, enum PILE_TYPES a2);

    // address=[0x142ab90]
    void  CleanUpBuildingNeed(int a2);

    // address=[0x142ad60]
    int  RequestGoodToVehicle(int a2, int a3);

    // address=[0x142aed0]
    bool  TransportGood(int a2, int a3);

    // address=[0x142b020]
    void  RequestSpace(class CPile * a2);

    // address=[0x142b090]
    int  GetFullPile(int a2);

    // address=[0x142b100]
    bool  RegisterFreeStoragePile(int a2, int a3);

    // address=[0x142b150]
    bool  UnregisterFreeStoragePile(int a2, int a3);

    // address=[0x142b1d0]
    bool  RegisterGoodStoragePile(int a2, int a3, int a4);

    // address=[0x142b240]
    bool  UnregisterGoodStoragePile(int a2, int a3, int a4);

    // address=[0x142b2d0]
    bool  RegisterGoodStorage(int a2, int a3);

    // address=[0x142b320]
    bool  UnregisterGoodStorage(int a2, int a3);

    // address=[0x142b3a0]
    int  GetNearestStoragePile(class CPile & a2);

    // address=[0x142b600]
    void  ChangeMinMaxValues(int a2, int a3);

    // address=[0x142b6e0]
    void  SetExtraMinCarrierForRecruitment(int a2);

    // address=[0x142b720]
    bool  CarrierForJobOrderAvailable(bool a2);

    // address=[0x142b7a0]
    int  WorkerDeltaAmount(int a2);

    // address=[0x142b840]
    void  ChangeWorkerDeltaAmount(int a2, int a3);

    // address=[0x142b900]
    int  SpecialistWishes(int a2);

    // address=[0x142b9a0]
    void  ChangeSpecialistWish(int a2, int a3);

    // address=[0x142ba70]
    void  InitTransport(void);

    // address=[0x142c9d0]
    void  ResetGoodNeed(void);

    // address=[0x142ca00]
    void  RecruiteSpecialist(void);

    // address=[0x142ced0]
    void  RecruiteWorker(void);

    // address=[0x142d120]
    void  FillGoodDistribution(class CGoodDistributionInfo * a2);

    // address=[0x142d1f0]
    void  ChangeGoodDistribution(class CGoodDistributionInfo * a2);

    // address=[0x142d250]
    void  FillTransportPrio(class CTransportpriorityInfo * a2);

    // address=[0x142d2c0]
    void  ChangeTransportPrio(enum PILE_TYPES a2, int a3);

    // address=[0x142d2f0]
    void  ChangeBuildingSupplyPrio(enum PILE_TYPES a2, enum BUILDING_TYPES a3, signed char a4);

    // address=[0x142d330]
    int  GetNumberOfGoods(int a2, enum CEcoSector::T_STATISTIC_GOOD_CATEGORY a3);

    // address=[0x142d3e0]
    void  ChangeNumberOfGoodsPile(int a2, int a3);

    // address=[0x142d4c0]
    void  ChangeNumberOfGoodsCarrier(int a2, int a3);

    // address=[0x142d5a0]
    void  OrderDiggerAndBuilderAtStartUp(void);

    // address=[0x142d6d0]
    void  TakeSoldierOrder(int a2, int a3);

    // address=[0x142d7f0]
    void  TakeWeaponOrder(int a2, int a3);

    // address=[0x142d8f0]
    void  SetWeaponAutoProduction(bool a2);

    // address=[0x142d930]
    void  SetWeaponPercentage(unsigned int a2);

    // address=[0x142d9d0]
    int  WeaponPercentage(int a2);

    // address=[0x142da00]
    void  TakeToolOrder(int a2, int a3);

    // address=[0x142db00]
    static int __cdecl GetSettlerCountEcoSectorId(class CSettler const * a1);

    // address=[0x142dba0]
    int  DbgCheckEcoSector(int a2);

    // address=[0x142eb00]
     CEcoSector(std::istream & a2);

    // address=[0x142fd30]
    virtual void  Store(std::ostream & a2);

    // address=[0x1439a60]
    virtual unsigned long  ClassID(void)const;

    // address=[0x1439a80]
    int  EcoSectorId(void)const;

    // address=[0x1439c50]
    int  NumberOfCarriersWithJobOrder(void)const;

    // address=[0x1447350]
    int  BuildingSitesWithPrio(void)const;

    // address=[0x1447370]
    void  ChangeBuildingSitesWithPrio(int a2);

    // address=[0x14473d0]
    void  ChangePrioBoards(int a2);

    // address=[0x1447400]
    void  ChangePrioBuilder(int a2, int a3);

    // address=[0x14474b0]
    void  ChangePrioDigger(int a2, int a3);

    // address=[0x1447560]
    void  ChangePrioStone(int a2);

    // address=[0x1447590]
    int  GetNrOfSoldierOrder(int a2)const;

    // address=[0x14475b0]
    int  GetNrOfToolOrder(int a2)const;

    // address=[0x14475e0]
    int  GetNrOfWeaponOrder(int a2)const;

    // address=[0x14476f0]
    int  NeededPrioBuilder(void)const;

    // address=[0x1447710]
    int  NeededPrioDigger(void)const;

    // address=[0x1447730]
    int  NrOfBuildingsWithBuilderPrio(void)const;

    // address=[0x1447750]
    int  NrOfBuildingsWithDiggerPrio(void)const;

    // address=[0x1447820]
    int  PrioBoards(void)const;

    // address=[0x1447840]
    int  PrioStone(void)const;

    // address=[0x14478b0]
    int  Size(void)const;

    // address=[0x1473090]
    void  SetProducedArmors(unsigned int a2);

    // address=[0x14730b0]
    void  SetProducedBows(unsigned int a2);

    // address=[0x14730d0]
    void  SetProducedSpecial(unsigned int a2);

    // address=[0x14730f0]
    void  SetProducedSwords(unsigned int a2);

    // address=[0x14e80e0]
    void  DecNrOfSoldierOrder(int a2);

    // address=[0x15185a0]
    void  DecNrOfToolOrder(int a2);

    // address=[0x15185e0]
    void  DecNrOfWeaponOrder(int a2);

    // address=[0x1518620]
    unsigned int  GetArmorsCounter(void);

    // address=[0x1518640]
    unsigned int  GetBowsCounter(void);

    // address=[0x1518660]
    unsigned int  GetSpecialCounter(void);

    // address=[0x1518680]
    unsigned int  GetSwordsCounter(void);

    // address=[0x15186a0]
    void  IncArmorsCounter(void);

    // address=[0x15186d0]
    void  IncBowsCounter(void);

    // address=[0x1518700]
    void  IncSpecialCounter(void);

    // address=[0x1518730]
    void  IncSwordsCounter(void);

    // address=[0x1518760]
    int  WeaponAutoProduction(void)const;

    // address=[0x3d89494]
    static unsigned long m_iClassID;

private:
    // address=[0x142df50]
    void  IncSize(void);

    // address=[0x142df70]
    void  DecSize(void);

    // address=[0x142df90]
     CEcoSector(int a2, int a3);

    // address=[0x142e4a0]
     ~CEcoSector(void);

    // address=[0x142e5b0]
    void  SetWorldIdxForStore(int a2);

    // address=[0x142e650]
    void  ResetBuildingSitesWithPrio(void);

    // address=[0x142e690]
    void  MissingToolWarning(int a2, int a3, int a4, int a5, int a6);

    // address=[0x142e800]
    int  ChangeValue(int a2, int a3, int a4);

    // address=[0x142e880]
    int  GetRegisteredFreeStoragePile(int a2, int a3);

    // address=[0x142e910]
    int  GetRegisteredGoodStoragePile(int a2, int a3, int a4);

    // address=[0x142e9c0]
    int  GetRegisteredGoodStorage(int a2, int a3);

    // address=[0x142ea50]
    void  ClearAllStorageRegistrations(void);

    // address=[0x142ea90]
    void  ReregisterAllStorageRegistrations(void);

};


#endif // CECOSECTOR_H
