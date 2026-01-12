#ifndef CECOSECTOR_H
#define CECOSECTOR_H

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
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x14299b0]
    int  NrOfSettler(int)const;

    // address=[0x1429a00]
    void  ChangeNrOfSettler(int,int);

    // address=[0x1429ab0]
    int  GetSettlerOffer(int)const;

    // address=[0x1429ad0]
    void  SetSettlerOffer(int,int);

    // address=[0x1429c80]
    void  SetSettlerOfferIncDisplay(int,int);

    // address=[0x1429ce0]
    void  GetSettlerOutOfOffer(int);

    // address=[0x1429ed0]
    void  GetSettlerOutOfOfferDecDisplay(int);

    // address=[0x1429f70]
    void  GetCarrierOutOfOfferAndSetNextSettlerType(int,int);

    // address=[0x142a020]
    void  ResetCarrierNextSettlerTypeAndDecrementOrder(int);

    // address=[0x142a0c0]
    int  OrderWorker(int,int);

    // address=[0x142a580]
    int  CallWorker(int,int);

    // address=[0x142a6f0]
    int  GetNearestSettler(int,int,int);

    // address=[0x142a7f0]
    bool  HaveFreeCarrier(void)const;

    // address=[0x142a830]
    int  NrOfGoods(int)const;

    // address=[0x142a8a0]
    int  GetGoodOffer(int)const;

    // address=[0x142a8c0]
    void  SetGoodOffer(int,int);

    // address=[0x142aa20]
    void  GetPileOutOfOffer(int,int);

    // address=[0x142ab50]
    void  RequestGood(int,enum PILE_TYPES);

    // address=[0x142ab90]
    void  CleanUpBuildingNeed(int);

    // address=[0x142ad60]
    int  RequestGoodToVehicle(int,int);

    // address=[0x142aed0]
    bool  TransportGood(int,int);

    // address=[0x142b020]
    void  RequestSpace(class CPile *);

    // address=[0x142b090]
    int  GetFullPile(int);

    // address=[0x142b100]
    bool  RegisterFreeStoragePile(int,int);

    // address=[0x142b150]
    bool  UnregisterFreeStoragePile(int,int);

    // address=[0x142b1d0]
    bool  RegisterGoodStoragePile(int,int,int);

    // address=[0x142b240]
    bool  UnregisterGoodStoragePile(int,int,int);

    // address=[0x142b2d0]
    bool  RegisterGoodStorage(int,int);

    // address=[0x142b320]
    bool  UnregisterGoodStorage(int,int);

    // address=[0x142b3a0]
    int  GetNearestStoragePile(class CPile &);

    // address=[0x142b600]
    void  ChangeMinMaxValues(int,int);

    // address=[0x142b6e0]
    void  SetExtraMinCarrierForRecruitment(int);

    // address=[0x142b720]
    bool  CarrierForJobOrderAvailable(bool);

    // address=[0x142b7a0]
    int  WorkerDeltaAmount(int);

    // address=[0x142b840]
    void  ChangeWorkerDeltaAmount(int,int);

    // address=[0x142b900]
    int  SpecialistWishes(int);

    // address=[0x142b9a0]
    void  ChangeSpecialistWish(int,int);

    // address=[0x142ba70]
    void  InitTransport(void);

    // address=[0x142c9d0]
    void  ResetGoodNeed(void);

    // address=[0x142ca00]
    void  RecruiteSpecialist(void);

    // address=[0x142ced0]
    void  RecruiteWorker(void);

    // address=[0x142d120]
    void  FillGoodDistribution(class CGoodDistributionInfo *);

    // address=[0x142d1f0]
    void  ChangeGoodDistribution(class CGoodDistributionInfo *);

    // address=[0x142d250]
    void  FillTransportPrio(class CTransportpriorityInfo *);

    // address=[0x142d2c0]
    void  ChangeTransportPrio(enum PILE_TYPES,int);

    // address=[0x142d2f0]
    void  ChangeBuildingSupplyPrio(enum PILE_TYPES,enum BUILDING_TYPES,signed char);

    // address=[0x142d330]
    int  GetNumberOfGoods(int,enum CEcoSector::T_STATISTIC_GOOD_CATEGORY);

    // address=[0x142d3e0]
    void  ChangeNumberOfGoodsPile(int,int);

    // address=[0x142d4c0]
    void  ChangeNumberOfGoodsCarrier(int,int);

    // address=[0x142d5a0]
    void  OrderDiggerAndBuilderAtStartUp(void);

    // address=[0x142d6d0]
    void  TakeSoldierOrder(int,int);

    // address=[0x142d7f0]
    void  TakeWeaponOrder(int,int);

    // address=[0x142d8f0]
    void  SetWeaponAutoProduction(bool);

    // address=[0x142d930]
    void  SetWeaponPercentage(unsigned int);

    // address=[0x142d9d0]
    int  WeaponPercentage(int);

    // address=[0x142da00]
    void  TakeToolOrder(int,int);

    // address=[0x142db00]
    static int __cdecl GetSettlerCountEcoSectorId(class CSettler const *);

    // address=[0x142dba0]
    int  DbgCheckEcoSector(int);

    // address=[0x142eb00]
     CEcoSector(std::istream &);

    // address=[0x142fd30]
    virtual void  Store(std::ostream &);

    // address=[0x1439a60]
    virtual unsigned long  ClassID(void)const;

    // address=[0x1439a80]
    int  EcoSectorId(void)const;

    // address=[0x1439c50]
    int  NumberOfCarriersWithJobOrder(void)const;

    // address=[0x1447350]
    int  BuildingSitesWithPrio(void)const;

    // address=[0x1447370]
    void  ChangeBuildingSitesWithPrio(int);

    // address=[0x14473d0]
    void  ChangePrioBoards(int);

    // address=[0x1447400]
    void  ChangePrioBuilder(int,int);

    // address=[0x14474b0]
    void  ChangePrioDigger(int,int);

    // address=[0x1447560]
    void  ChangePrioStone(int);

    // address=[0x1447590]
    int  GetNrOfSoldierOrder(int)const;

    // address=[0x14475b0]
    int  GetNrOfToolOrder(int)const;

    // address=[0x14475e0]
    int  GetNrOfWeaponOrder(int)const;

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
    void  SetProducedArmors(unsigned int);

    // address=[0x14730b0]
    void  SetProducedBows(unsigned int);

    // address=[0x14730d0]
    void  SetProducedSpecial(unsigned int);

    // address=[0x14730f0]
    void  SetProducedSwords(unsigned int);

    // address=[0x14e80e0]
    void  DecNrOfSoldierOrder(int);

    // address=[0x15185a0]
    void  DecNrOfToolOrder(int);

    // address=[0x15185e0]
    void  DecNrOfWeaponOrder(int);

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
     CEcoSector(int,int);

    // address=[0x142e4a0]
     ~CEcoSector(void);

    // address=[0x142e5b0]
    void  SetWorldIdxForStore(int);

    // address=[0x142e650]
    void  ResetBuildingSitesWithPrio(void);

    // address=[0x142e690]
    void  MissingToolWarning(int,int,int,int,int);

    // address=[0x142e800]
    int  ChangeValue(int,int,int);

    // address=[0x142e880]
    int  GetRegisteredFreeStoragePile(int,int);

    // address=[0x142e910]
    int  GetRegisteredGoodStoragePile(int,int,int);

    // address=[0x142e9c0]
    int  GetRegisteredGoodStorage(int,int);

    // address=[0x142ea50]
    void  ClearAllStorageRegistrations(void);

    // address=[0x142ea90]
    void  ReregisterAllStorageRegistrations(void);

};


#endif // CECOSECTOR_H
