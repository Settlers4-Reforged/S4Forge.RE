#ifndef CEVN_LOGIC_H
#define CEVN_LOGIC_H

#include "defines.h"

class CEvn_Logic : public CEvn_Event {
public:
    // address=[0x130e470]
    virtual  ~CEvn_Logic(void);

    // address=[0x1334e60]
     CEvn_Logic(unsigned int a2, unsigned int a3, unsigned int a4, unsigned char a5, unsigned int a6, unsigned short a7);

    // address=[0x1355030]
     CEvn_Logic(void);

    // address=[0x13570f0]
    virtual void  Load(class IS4Chunk & a2);

    // address=[0x13571b0]
    virtual void  Save(class IS4Chunk & a2);

    // address=[0x145fff0]
     CEvn_Logic(class CEvn_Logic const & a2);

    // address=[0x1486be0]
    class CEvn_Logic &  operator=(class CEvn_Logic const & a2);

};


#endif // CEVN_LOGIC_H
