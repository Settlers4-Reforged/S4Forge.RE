#ifndef GAMESESSIONDESCRIPTOR_H
#define GAMESESSIONDESCRIPTOR_H

#include "defines.h"

class GameSessionDescriptor : public SimpleSessionDescriptor_Matchmaking@storm {
public:
    // address=[0x1308e60]
    void  SetPeerCount(unsigned long a2);

    // address=[0x1308f70]
    void  SetSaveId(long a2);

    // address=[0x15c4ac0]
    unsigned long  GetPeerCount(void)const;

    // address=[0x15c4c80]
    unsigned long  GetTickCount(void)const;

    // address=[0x160e800]
    virtual void  GetMaxSlots(unsigned long & a2)const;

    // address=[0x160e820]
    virtual void  SetMaxSlots(unsigned long a2);

    // address=[0x160e8a0]
    virtual void  GetFreeSlots(unsigned long & a2)const;

    // address=[0x160e8c0]
    virtual void  SetFreeSlots(unsigned long a2);

    // address=[0x16110a0]
    static char const * __cdecl GetClassTypeName(void);

    // address=[0x16110f0]
    static unsigned long __cdecl GetClassTypeStaticCrc(void);

    // address=[0x161ff10]
    long  GetSaveId(void)const;

    // address=[0x1682600]
     GameSessionDescriptor(void);

    // address=[0x1684a60]
    virtual  ~GameSessionDescriptor(void);

    // address=[0x168cfb0]
    void  SetTickCount(unsigned long a2);

};


#endif // GAMESESSIONDESCRIPTOR_H
