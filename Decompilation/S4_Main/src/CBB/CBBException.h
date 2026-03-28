#ifndef CBBEXCEPTION_H
#define CBBEXCEPTION_H

#include "defines.h"

class CBBException {
public:
    // address=[0x1313e80]
     CBBException(class CBBException const & a2);

    // address=[0x1313ea0]
     CBBException(void);

    // address=[0x2f30950]
    virtual  ~CBBException(void);

    // address=[0x2f30970]
    virtual bool  GetErrorMessage(char * a2, unsigned int a3);

};


#endif // CBBEXCEPTION_H
