#ifndef CECOSECTORMGR_H
#define CECOSECTORMGR_H

#include "defines.h"

class CEcoSectorMgr {
public:
    // address=[0x130a3d0]
    class CEcoSector *  GetEcoSectorPtr(int a2);

    // address=[0x130ec00]
    class CEcoSector *  GetEcoSectorPtrEx(int a2);

    // address=[0x130ec30]
    class CEcoSector *  GetEcoSectorPtrEx(int a2, int a3);

    // address=[0x130f120]
    int  LastUsedEcoSectorId(void)const;

    // address=[0x1326e00]
    class CEcoSector *  EntryPtr(int a2);

    // address=[0x1346370]
    class CEcoSector &  operator[](int a2);

    // address=[0x1441b90]
     CEcoSectorMgr(void);

    // address=[0x1441c30]
     ~CEcoSectorMgr(void);

    // address=[0x1441c90]
    void  OrderDiggerAndBuilderAtStartUp(void);

    // address=[0x1441ce0]
    void  Clear(void);

    // address=[0x1441dc0]
    void  Update(void);

    // address=[0x1441e10]
    int  GetNrStrikingCarriers(int a2);

    // address=[0x1441e40]
    int  GetNrOfStrikingCarriersInEcoSector(int a2);

    // address=[0x1441f20]
    int  GetNrOfInitialFreeBeds(int a2);

    // address=[0x1441f80]
    int  GetNrOfCurrentTotalBeds(int a2);

    // address=[0x1442080]
    void  RemoveCarrierFromStrikeSettlers(int a2, int a3);

    // address=[0x1442150]
    void  CalculateInitialFreeBeds(void);

    // address=[0x14421b0]
    void  UpdateStrikeSettlers(void);

    // address=[0x14425c0]
    int  NotifyCreateEcoSector(int a2);

    // address=[0x1442610]
    void  NotifyChangeEcoSector(int a2, int a3, int a4);

    // address=[0x1442c00]
    void  NotifyDeleteEcoSector(int a2);

    // address=[0x1442c20]
    void  SeparateEconomy(int a2, int a3);

    // address=[0x1442f60]
    void  NotifyEcoSectorMerge(int a2, int a3);

    // address=[0x1442f80]
    void  ConnectEconomy(int a2, int a3);

    // address=[0x1443370]
    void  OfferSettler(int a2, int a3, int a4);

    // address=[0x14433d0]
    void  OfferGood(int a2, int a3, int a4);

    // address=[0x1443430]
    void  InitTransport(void);

    // address=[0x1443490]
    void  RecruiteSpecialist(void);

    // address=[0x14434e0]
    void  RecruiteWorker(void);

    // address=[0x1443530]
    static void __cdecl FillGoodAmount(class CInfoExchange * a1, bool a2, bool a3);

    // address=[0x1443770]
    static void __cdecl FillTransportPrio(class CInfoExchange * a1, bool a2, bool a3);

    // address=[0x14438a0]
    static void __cdecl ChangeTransportPrio(enum PILE_TYPES a1, int a2, bool a3, bool a4);

    // address=[0x1443980]
    static void __cdecl ChangeTransportPrio(enum PILE_TYPES a1, int a2, int a3);

    // address=[0x1443a90]
    static void __cdecl FillGoodDistribution(class CInfoExchange * a1, bool a2, bool a3);

    // address=[0x1443c10]
    static void __cdecl ChangeGoodDistributionPrio(enum PILE_TYPES a1, enum BUILDING_TYPES a2, int a3, signed char a4);

    // address=[0x1443cd0]
    static int __cdecl GetLocalPlayerEcoSectorIdAtCenter(void);

    // address=[0x1443d80]
    static class CEcoSector * __cdecl GetLocalPlayerEcoSectorPtrAtCenter(void);

    // address=[0x1443de0]
    void  Store(class S4::CMapFile &);

    // address=[0x1444230]
    void  Load(class S4::CMapFile & a2);

    // address=[0x14445d0]
    int  GetNearestPileIDOfferGood(int a2, int a3, int a4, int a5);

    // address=[0x1444720]
    void  DBG_CheckEcoSectors(void);

    // address=[0x1444770]
    int  GetFirstESForPlayer(int a2);

    // address=[0x14447d0]
    int  GetNextESForPlayer(int a2, int a3);

private:
    // address=[0x1444830]
    int  GetFreeSlot(void);

    // address=[0x14448e0]
    void  RegisterEcoSector(int a2, class CEcoSector * a3, bool a4);

    // address=[0x1444a50]
    void  DestroyEcoSector(int a2);

    // address=[0x1444c50]
    void  CalculateStoreWorldIndices(void);

    // address=[0x1444f60]
    int  NewEcoSector(int a2);

    // address=[0x14450d0]
    void  DeleteEcoSector(int a2);

};


#endif // CECOSECTORMGR_H
