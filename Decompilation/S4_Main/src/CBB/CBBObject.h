#ifndef CBBOBJECT_H
#define CBBOBJECT_H

#include "defines.h"

class CBBObject {
public:
    // address=[0x2f337e0]
     CBBObject(char const * a2, bool a3);

    // address=[0x2f33860]
     CBBObject(class CBBObject const & a2);

    // address=[0x2f33900]
    virtual  ~CBBObject(void);

    // Type information members
public:
    void * vtable;
    int m_uSerialNumber;
    char * m_spType;
    CBBObject *m_pFirst;
    int16_t m_uU10;

};


#endif // CBBOBJECT_H
