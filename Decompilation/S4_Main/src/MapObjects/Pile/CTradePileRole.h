#ifndef CTRADEPILEROLE_H
#define CTRADEPILEROLE_H

#include "IPileRole.h"
#include "defines.h"

class CTradePileRole : public IPileRole {
  public:
    enum TRADEPILE_ROLE {
        TRADEPILE_FREE = 0,
        TRADEPILE_UNKNOWN = 1,
        TRADEPILE_UNKNOWN_2 = 2,
        TRADEPILE_UNKNOWN_3 = 3,
        TRADEPILE_EXPORT_RESERVES = 4
    };

    // address=[0x14023e0]
    static class CPersistence *__cdecl New(std::istream &_rStream);

    // address=[0x1560480]
    static class CTradePileRole *__cdecl Load(std::istream &_rStream);

    // address=[0x1561a70]
    virtual void Increase(class CPile *_pPile, int _iAmount);

    // address=[0x1561b70]
    virtual void Decrease(class CPile *_pPile, int a3);

    // address=[0x1561c90]
    virtual void Empty(class CPile *_pPile);

    // address=[0x1561d60]
    virtual void Init(class CPile *_pPile);

    // address=[0x1561de0]
    virtual void LogicUpdate(class CPile *_pPile);

    // address=[0x1561f40]
    virtual void Occupied(class CPile *_pPile, int _iES);

    // address=[0x1561fc0]
    virtual bool SetFree(class CPile *_pPile, int a3);

    // address=[0x1562050]
    virtual void NotifyChangeEcoSector(class CPile *_pPile, int a3, int a4);

    // address=[0x15620c0]
    virtual void SubjectDie(class CPile *_pPile, int _iBuildingId);

    // address=[0x15621c0]
    virtual void SubjectStopped(class CPile *_pPile);

    // address=[0x1562230]
    virtual void SubjectStarted(class CPile *_pPile);

    // address=[0x1562290]
    virtual bool ChangeGoodTypeUnforseen(class CPile *_pPile, int _iGood);

    // address=[0x1562340]
    void SetTradeRoleType(TRADEPILE_ROLE _tRole);

    // address=[0x1562440]
    int GetTradeRoleType(void);

    // address=[0x1562460]
    void SetExpectedAmount(int a2);

    // address=[0x1562480]
    int GetExpectedAmount(void);

    // address=[0x15624a0]
    virtual void IncAmoutLeaving(class CPile *_pPile);

    // address=[0x1562500]
    virtual void DecAmountLeaving(class CPile *_pPile);

    // address=[0x1562560]
    virtual void IncAmountComing(class CPile *_pPile);

    // address=[0x1562590]
    virtual void DecAmountComing(class CPile *_pPile);

    // address=[0x15625e0]
    int ReservesGood(int _iAmount, enum PILE_TYPES a3, class CPile *pPile);

    // address=[0x15626d0]
    int GetReserveAmount(void);

    // address=[0x1562710]
    CTradePileRole(std::istream &_rStream);

    // address=[0x1562810]
    virtual void Store(std::ostream &_rStream);

    // address=[0x1562d70]
    virtual unsigned long ClassID(void) const;

    // address=[0x3d8bea0]
    static unsigned long m_iClassID;

  private:
    friend class CPileMgr;

    // address=[0x1562890]
    CTradePileRole(void);

    // address=[0x1562920]
    virtual ~CTradePileRole(void);

    // Type information members
  public:
    int m_iRoleType;
    int m_iExpectedAmount;
    int m_iReserveAmount;
};

#endif // CTRADEPILEROLE_H
