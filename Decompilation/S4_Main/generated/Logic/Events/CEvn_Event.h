#ifndef CEVN_EVENT_H
#define CEVN_EVENT_H

#include "defines.h"

class CEvn_Event : public .?AUSEventStruct@@, public IS4ChunkObject {
public:
    // address=[0x130e450]
    virtual  ~CEvn_Event(void);

    // address=[0x1334dc0]
     CEvn_Event(unsigned int a2, unsigned int a3, unsigned int a4, unsigned char a5);

    // address=[0x1352be0]
    virtual void  Load(class IS4Chunk &);

    // address=[0x1352bf0]
    virtual void  Save(class IS4Chunk &);

    // address=[0x145ff30]
     CEvn_Event(class CEvn_Event const & a2);

    // address=[0x1486b30]
    class CEvn_Event &  operator=(class CEvn_Event const & a2);

};


#endif // CEVN_EVENT_H
