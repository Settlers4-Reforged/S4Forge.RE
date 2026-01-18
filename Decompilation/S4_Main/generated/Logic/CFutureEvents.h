#ifndef CFUTUREEVENTS_H
#define CFUTUREEVENTS_H

#include "defines.h"

class CFutureEvents : public IFutureEvents, public CBBObject {
public:
    // address=[0x144fff0]
     CFutureEvents(void);

    // address=[0x1450070]
    virtual void  Release(void);

    // address=[0x14500b0]
    virtual bool  AddFutureEvent32(enum T_FUTURE_EVENT a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6);

    // address=[0x14502b0]
    virtual void  Execute(void);

    // address=[0x1450410]
    virtual void  Load(class IS4Chunk & a2);

    // address=[0x1450590]
    virtual void  Save(class IS4Chunk & a2);

    // address=[0x1450610]
    virtual unsigned int  DbgCheckData(int a2);

    // address=[0x14529e0]
    virtual  ~CFutureEvents(void);

private:
    // address=[0x1450d00]
    void  Init(void);

    // address=[0x1450e10]
    void  AddFutureEventToList(unsigned int a2, unsigned int a3);

    // address=[0x1450f70]
    void  RemoveFutureEventFromList(unsigned int a2);

    // address=[0x14510b0]
    unsigned int  Compactify(void);

    // address=[0x1451430]
    static void __cdecl ExecuteNone(struct CFutureEvents::SFutureEvent &);

    // address=[0x1451440]
    static void __cdecl ExecuteChangeEntityFlags(struct CFutureEvents::SFutureEvent & a1);

    // address=[0x14514a0]
    static void __cdecl ExecuteDamageEntity(struct CFutureEvents::SFutureEvent & a1);

    // address=[0x1451510]
    static void __cdecl ExecuteCastSpell(struct CFutureEvents::SFutureEvent & a1);

    // address=[0x1451540]
    static void __cdecl ExecuteSpellTerrainConversion(struct CFutureEvents::SFutureEvent & a1);

    // address=[0x14516a0]
    static void __cdecl ExecuteCrushBuilding(struct CFutureEvents::SFutureEvent & a1);

    // address=[0x14516e0]
    static void __cdecl ExecuteVehicleFire(struct CFutureEvents::SFutureEvent & a1);

    // address=[0x1451740]
    static void __cdecl ExecuteMovingAnimalUpdate(struct CFutureEvents::SFutureEvent & a1);

    // address=[0x14517a0]
    static void __cdecl ExecuteEnslaveSettler(struct CFutureEvents::SFutureEvent & a1);

    // address=[0x14519c0]
    static void __cdecl ExecuteFreeServant(struct CFutureEvents::SFutureEvent & a1);

    // address=[0x1452a50]
    static unsigned int __cdecl HiWord(unsigned int a1);

    // address=[0x1452a60]
    static unsigned int __cdecl LoWord(unsigned int a1);

    // address=[0x3d89530]
    static void (__cdecl** m_pExecuteFunctions)(struct CFutureEvents::SFutureEvent &);

};


#endif // CFUTUREEVENTS_H
