#ifndef CINTERNATIONALTRADER_CPLAYERTRADEINFO_H
#define CINTERNATIONALTRADER_CPLAYERTRADEINFO_H

#include "defines.h"

namespace CInternationalTrader {

class CPlayerTradeInfo {
public:
    // address=[0x1461000]
    bool  TradeWithSomeone(void);

    // address=[0x1461050]
    void  AddBuilding(class CBuilding * a2);

    // address=[0x1461150]
    void  RemoveBuilding(class CBuilding * a2);

    // address=[0x14613a0]
    void  SetGoodStatus(class CBuilding * a2, enum PILE_TYPES a3, enum TGOOD_STATUS a4);

    // address=[0x1461410]
    enum TGOOD_STATUS  GetGoodStatus(class CBuilding * a2, enum PILE_TYPES a3);

    // address=[0x14614a0]
    class CInternationalTrader::CTradeBuildingInfo *  GetBuildingInfo(class CBuilding * a2);

    // address=[0x14616a0]
    class std::vector<struct TGoodInfo,class std::allocator<struct CInternationalTrader::CPlayerTradeInfo::TGoodInfo> >  CInternationalTrader::CPlayerTradeInfo::GetExportListForBuilding(class CBuilding * a2);

    // address=[0x14617d0]
    class std::vector<struct TGoodInfo,class std::allocator<struct CInternationalTrader::CPlayerTradeInfo::TGoodInfo> >  CInternationalTrader::CPlayerTradeInfo::GetExportList(enum BUILDING_TYPES a2);

    // address=[0x1461a00]
    class std::vector<struct TGoodInfo,class std::allocator<struct CInternationalTrader::CPlayerTradeInfo::TGoodInfo> >  CInternationalTrader::CPlayerTradeInfo::GetImportList(enum BUILDING_TYPES a2);

    // address=[0x1461c30]
    bool  ImportGood(enum PILE_TYPES a2, enum BUILDING_TYPES a3);

    // address=[0x1461d40]
    bool  ImportGoodAtBuilding(int & a2, enum PILE_TYPES a3, enum BUILDING_TYPES a4);

    // address=[0x1465d20]
     CPlayerTradeInfo(void);

    // address=[0x1466c10]
    int  GetPlayerID(void);

    // address=[0x1466c30]
    bool  GetPlayerTradeStatus(int a2);

    // address=[0x1466c50]
    void  SetPlayerID(int a2);

    // address=[0x1466ce0]
    void  SetPlayerTradeStatus(int a2, bool a3);

    // address=[0x1466d00]
    void  SwitchPlayerTradeStatus(int a2);

    // address=[0x1466d50]
    bool  TradeWithPlayer(int a2);

};

} // namespace CInternationalTrader

#endif // CINTERNATIONALTRADER_CPLAYERTRADEINFO_H
