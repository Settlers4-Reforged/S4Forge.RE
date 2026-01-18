#ifndef CNET_EVENT_H
#define CNET_EVENT_H

#include "defines.h"

class CNet_Event : public CEvn_Logic {
public:
    // address=[0x15c38b0]
     CNet_Event(class CNet_Event const & a2);

    // address=[0x15c38e0]
     CNet_Event(unsigned int,unsigned int,unsigned int,unsigned char,unsigned int,unsigned short,unsigned int);

    // address=[0x15c3dc0]
    virtual  ~CNet_Event(void);

    // address=[0x15cad30]
    bool  operator<(class CNet_Event const & a2);

};


#endif // CNET_EVENT_H
