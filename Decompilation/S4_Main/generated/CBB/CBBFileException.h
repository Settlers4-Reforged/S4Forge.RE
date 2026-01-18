#ifndef CBBFILEEXCEPTION_H
#define CBBFILEEXCEPTION_H

#include "defines.h"

class CBBFileException : public CBBException {
public:
    // address=[0x14c2e30]
    int  Cause(void)const;

    // address=[0x14c2e50]
    wchar_t const *  FileName(void)const;

    // address=[0x14dfb00]
     CBBFileException(class CBBFileException const & a2);

    // address=[0x2f309f0]
     CBBFileException(int a2, wchar_t const * a3);

    // address=[0x2f30a70]
    virtual  ~CBBFileException(void);

    // address=[0x2f30a90]
    virtual bool  GetErrorMessage(char * a2, unsigned int a3);

};


#endif // CBBFILEEXCEPTION_H
