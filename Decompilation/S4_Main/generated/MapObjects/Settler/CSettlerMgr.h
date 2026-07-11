#ifndef CSETTLERMGR_H
#define CSETTLERMGR_H

#include "defines.h"

class CSettlerMgr {
public:
    // address=[0x130e490]
    class CSettler &  operator[](int a1);

    // address=[0x130ecc0]
    int  GetNumberOfSettlers(int _iPlayerId, int _iSettlerType)const;

    // address=[0x130edf0]
    class CSettler *  GetSettlerPtr(int a1);

    // address=[0x1311cd0]
    int  GetNumberOfOfferedSettlers(int _iPlayerId, int _iSettlerType)const;

    // address=[0x1439bb0]
    static struct SSettlerInfos const & __cdecl CSettlerMgr::GetSettlerInfo(int _iRace, int _iType);

    // address=[0x1439ed0]
    static int __cdecl SettlerWarriorType(int a1);

    // address=[0x1580220]
     CSettlerMgr(void);

    // address=[0x1580410]
     ~CSettlerMgr(void);

    // address=[0x1580430]
    void  Clear(void);

    // address=[0x15804a0]
    class ISettlerRole *  CreateSettlerRole(int _iRace, int _iType);

    // address=[0x1580c20]
    static class ISettlerRole * __cdecl LoadSettlerRole(std::istream & a1, int a2);

    // address=[0x1580eb0]
    void  LoadSettlerData(class S4::CMapFile & _pMapFile, int _iChunk);

    // address=[0x1580fe0]
    void  LoadInfo(bool isMP);

    // address=[0x1582460]
    int  AddSettler(int _iX, int _iY, int _iOwnerId, int _iSettlerType, int a6);

    // address=[0x1582720]
    bool  IsAddSettlerOk(int _iX, int _iY, int _iOwnerId);

    // address=[0x15827b0]
    void  AddSettlers(int _iX, int _iY, int _iOwnerId, int _iSettlerType, int _iAmount, int a7);

    // address=[0x1582970]
    int  AddGuardSettler(int iX, int iY, int iOwnerId);

    // address=[0x1582b30]
    void  DeleteSettler(int _iSettlerId);

    // address=[0x1582bc0]
    bool  SearchSpaceForSettler(int _iSettlerId, int _iX, int _iY);

    // address=[0x1582d50]
    bool  SearchFreePositionInSector(int & _rX, int & _rY, int _iSectorId, int a5);

    // address=[0x1582e60]
    bool  SearchFreePositionInEcoSector(int & _rX, int & _rY, int _iEcoSectorId);

    // address=[0x1582f20]
    int  GetFirstSettlerId(int _iOwnerId, int _iSettlerType)const;

    // address=[0x1582fa0]
    int  OrderWarrior(int _iBuildingId, int _iSettlerType, int _iMaxDistance);

    // address=[0x1583190]
    int  OrderAIWarrior(int _iBuildingId, int _iWarriorType);

    // address=[0x1583370]
    int  OrderSpecialist(int a2, int _iSettlerType);

    // address=[0x15835e0]
    void  OrderWarriorToTower(int _iBuildingId, int _iSettlerId);

    // address=[0x1583730]
    static void __cdecl FillSettlerAmount(class CInfoExchange * _pInfoExchange, bool a2, bool _bInEcoSector);

    // address=[0x1583c60]
    static void __cdecl FillFreeCarrier(class CInfoExchange * _pInfoExchange, bool a2, bool a3);

    // address=[0x1583f30]
    static void __cdecl FillSpecialistProduction(class CInfoExchange * pInfoExchange, bool a2, bool a3);

    // address=[0x1584240]
    static void __cdecl FillSoldierMenu(class CInfoExchange * _pInfoExchange, bool a2, bool a3);

    // address=[0x15845d0]
    static void __cdecl FillSpecialistMenu(class CInfoExchange * _pInfoExchange, bool a2, bool a3);

    // address=[0x1584870]
    void  Store(class S4::CMapFile & a2);

    // address=[0x1584c80]
    void  Load(class S4::CMapFile & a2);

    // address=[0x1584f70]
    void  IncNumberOfSettler(int _iPlayerId, int _iSettlerType);

    // address=[0x1585020]
    void  DecNumberOfSettler(int _iPlayerId, int _iSettlerType);

    // address=[0x15889c0]
    class CSettler &  Settler(int iSettlerId);

    // address=[0x1592200]
    static int __cdecl GetSquadLeaderBonus256(int a1);

    // address=[0x15a7b80]
    static int __cdecl SettlerWarriorLevel(int a1);

protected:
    // address=[0x1585120]
    void  AttachSettler(class CSettler & _rSettler);

    // address=[0x15853f0]
    void  DetachSettler(class CSettler & _rSettler);

private:
    // address=[0x157ff60]
    void *  Alloc(unsigned int a2);

    // address=[0x1580020]
    void  Dealloc(void * a2);

    // address=[0x1585740]
    void  CheckOutSettler(int _iSettlerId);

    // address=[0x15858b0]
    static int __cdecl GetUserESInMiddleOfTheScreen(void);

    // address=[0x4152138]
    static unsigned char * m_uSettlerWarriorTypes;

    // address=[0x4152180]
    static unsigned char * m_uSettlerWarriorLevels;

    // address=[0x41521c8]
    static int * m_iSquadLeaderBoni256;

    // address=[0x4153e40]
    static struct SSettlerInfos (* CSettlerMgr::m_vSettlerInfos)[70];

    // Type information members
public:
    MemoryAllocator m_cAllocator;
    unsigned __int16 m_uTotalSettlers;
    bool m_bLoaded;
    DWORD[9][67] m_vFirstSettlerId;
    int[9][67] m_vPlayerSettlerNumber;
    int[9][67] m_vPlayerSettlerOfferedNumber;

};


#endif // CSETTLERMGR_H
