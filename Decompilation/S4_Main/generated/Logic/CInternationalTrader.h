#ifndef CINTERNATIONALTRADER_H
#define CINTERNATIONALTRADER_H

class CInternationalTrader : public IS4ChunkObject {
public:
    // address=[0x1461e60]
     CInternationalTrader(void);

    // address=[0x1461ea0]
     ~CInternationalTrader(void);

    // address=[0x1461ec0]
    virtual void  Load(class IS4Chunk &);

    // address=[0x14620a0]
    virtual void  Save(class IS4Chunk &);

    // address=[0x14622f0]
    static void __cdecl ReInit(void);

    // address=[0x1462420]
    bool  Trade(class CBuilding *);

    // address=[0x1462700]
    void  AddBuilding(class CBuilding *);

    // address=[0x14627a0]
    void  RemoveBuilding(class CBuilding *);

    // address=[0x1462840]
    void  SetGoodStatus(int,class CBuilding *,enum PILE_TYPES,enum TGOOD_STATUS);

    // address=[0x1462930]
    void  SwitchToNextGoodStatus(int,class CBuilding *,enum PILE_TYPES);

    // address=[0x14629f0]
    void  SwitchPlayerTradeStatus(int,int);

    // address=[0x1462a80]
    void  SetPlayerTradeStatus(int,int,bool);

    // address=[0x1462b40]
    bool  GetPlayerTradeStatus(int,int);

    // address=[0x1462bd0]
    bool  TradeWithSomeone(int);

    // address=[0x1462c30]
    bool  CheckGoodMatch(int,int);

    // address=[0x1462e10]
    bool  CheckGoodMatch(int,int,enum PILE_TYPES);

    // address=[0x1463000]
    enum TGOOD_STATUS  GetGoodStatus(int,class CBuilding *,enum PILE_TYPES);

    // address=[0x14630c0]
    class std::vector<struct CPlayerTradeInfo::TGoodInfo,class std::allocator<struct CInternationalTrader::CPlayerTradeInfo::TGoodInfo> >  CInternationalTrader::GetExportGoodList(class CBuilding *);

    // address=[0x1463130]
    bool  CanWalk(int,int);

    // address=[0x3f1f7b4]
    static bool m_bInit;

    // address=[0x3f1f7b8]
    static class std::vector<class CPlayerTradeInfo *,class std::allocator<class CInternationalTrader::CPlayerTradeInfo *> > CInternationalTrader::m_sPlayerList;

private:
    // address=[0x14632c0]
    static void __cdecl InitPlayerList(void);

    // address=[0x14633b0]
    int  CheckTrade(class CInternationalTrader::CPlayerTradeInfo *,class CInternationalTrader::CPlayerTradeInfo *,class CBuilding *);

    // address=[0x1463850]
    void  DisableTrading(class CBuilding *,int,int);

    // address=[0x14638a0]
    bool  IsBuildingAnPort(class CBuilding *);

};


#endif // CINTERNATIONALTRADER_H
