#ifndef CSETTLERMGR_H
#define CSETTLERMGR_H

#include "defines.h"

class CSettlerMgr {
public:
    // address=[0x130e490]
    class CSettler &  operator[](int a1);

    // address=[0x130ecc0]
    int  GetNumberOfSettlers(int a2, int a3)const;

    // address=[0x130edf0]
    class CSettler *  GetSettlerPtr(int a1);

    // address=[0x1311cd0]
    int  GetNumberOfOfferedSettlers(int a2, int a3)const;

    // address=[0x1439bb0]
    static struct SSettlerInfos const & __cdecl CSettlerMgr::GetSettlerInfo(int race, int type);

    // address=[0x1439ed0]
    static int __cdecl SettlerWarriorType(int a1);

    // address=[0x1580220]
     CSettlerMgr(void);

    // address=[0x1580410]
     ~CSettlerMgr(void);

    // address=[0x1580430]
    void  Clear(void);

    // address=[0x15804a0]
    class ISettlerRole *  CreateSettlerRole(int race, int type);

    // address=[0x1580c20]
    static class ISettlerRole * __cdecl LoadSettlerRole(std::istream & a1, int a2);

    // address=[0x1580eb0]
    void  LoadSettlerData(class S4::CMapFile & a2, int a3);

    // address=[0x1580fe0]
    void  LoadInfo(bool isMP);

    // address=[0x1582460]
    int  AddSettler(int posX, int posY, int player, int settlerType, int a6);

    // address=[0x1582720]
    bool  IsAddSettlerOk(int a2, int a3, int a4);

    // address=[0x15827b0]
    void  AddSettlers(int a2, int a3, int a4, int a5, int a6, int a7);

    // address=[0x1582970]
    int  AddGuardSettler(int a2, int a3, int a4);

    // address=[0x1582b30]
    void  DeleteSettler(int a2);

    // address=[0x1582bc0]
    bool  SearchSpaceForSettler(int a2, int a3, int a4);

    // address=[0x1582d50]
    bool  SearchFreePositionInSector(int & a2, int & a3, int a4, int a5);

    // address=[0x1582e60]
    bool  SearchFreePositionInEcoSector(int & a2, int & a3, int a4);

    // address=[0x1582f20]
    int  GetFirstSettlerId(int a2, int a3)const;

    // address=[0x1582fa0]
    int  OrderWarrior(int a2, int a3, int a4);

    // address=[0x1583190]
    int  OrderAIWarrior(int a2, int a3);

    // address=[0x1583370]
    int  OrderSpecialist(int a2, int a3);

    // address=[0x15835e0]
    void  OrderWarriorToTower(int a2, int a3);

    // address=[0x1583730]
    static void __cdecl FillSettlerAmount(class CInfoExchange * a1, bool a2, bool a3);

    // address=[0x1583c60]
    static void __cdecl FillFreeCarrier(class CInfoExchange * a1, bool a2, bool a3);

    // address=[0x1583f30]
    static void __cdecl FillSpecialistProduction(class CInfoExchange * a1, bool a2, bool a3);

    // address=[0x1584240]
    static void __cdecl FillSoldierMenu(class CInfoExchange * a1, bool a2, bool a3);

    // address=[0x15845d0]
    static void __cdecl FillSpecialistMenu(class CInfoExchange * a1, bool a2, bool a3);

    // address=[0x1584870]
    void  Store(class S4::CMapFile &);

    // address=[0x1584c80]
    void  Load(class S4::CMapFile &);

    // address=[0x1584f70]
    void  IncNumberOfSettler(int a2, int a3);

    // address=[0x1585020]
    void  DecNumberOfSettler(int a2, int a3);

    // address=[0x15889c0]
    class CSettler &  Settler(int a2);

    // address=[0x1592200]
    static int __cdecl GetSquadLeaderBonus256(int a1);

    // address=[0x15a7b80]
    static int __cdecl SettlerWarriorLevel(int a1);

protected:
    // address=[0x1585120]
    void  AttachSettler(class CSettler & settler);

    // address=[0x15853f0]
    void  DetachSettler(class CSettler & a2);

private:
    // address=[0x157ff60]
    void *  Alloc(unsigned int a2);

    // address=[0x1580020]
    void  Dealloc(void * a2);

    // address=[0x1585740]
    void  CheckOutSettler(int a2);

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

};


#endif // CSETTLERMGR_H
