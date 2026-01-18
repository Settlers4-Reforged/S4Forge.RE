#ifndef CBBMEMORYEXCEPTION_H
#define CBBMEMORYEXCEPTION_H

#include "defines.h"

class CBBMemoryException : public CBBException {
public:
    // address=[0x2f30980]
     CBBMemoryException(void);

    // address=[0x2f309a0]
    virtual  ~CBBMemoryException(void);

    // address=[0x2f309c0]
    virtual bool  GetErrorMessage(char * a2, unsigned int a3);

    // address=[0x2f337b0]
     CBBMemoryException(class CBBMemoryException const & a2);

};


#endif // CBBMEMORYEXCEPTION_H
