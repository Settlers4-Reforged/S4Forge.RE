#ifndef CAISCRIPTING_H
#define CAISCRIPTING_H

#include "defines.h"

class CAIScripting : public IAIScripting {
public:
    // address=[0x131d980]
    virtual void  Init(void);

    // address=[0x131db20]
    virtual void  Load(class IS4Chunk & a2);

    // address=[0x131db30]
    virtual void  Save(class IS4Chunk & a2);

    // address=[0x131db40]
    virtual unsigned int  Adler32(unsigned int a2);

    // address=[0x131e8c0]
     CAIScripting(void);

protected:
    // address=[0x131dc20]
    void  InitPlayerScriptVarsDefaultValues(void);

};


#endif // CAISCRIPTING_H
