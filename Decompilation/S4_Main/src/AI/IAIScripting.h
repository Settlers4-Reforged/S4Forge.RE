#ifndef IAISCRIPTING_H
#define IAISCRIPTING_H

#include "defines.h"

class IAIScripting {
  public:
    // address=[0x131e8f0]
    IAIScripting(void);

    virtual void Init(void) = 0;
    virtual void Load(class IS4Chunk &a2) = 0;
    virtual void Save(class IS4Chunk &a2) = 0;
    virtual unsigned int Adler32(unsigned int a2) = 0;
};

#endif // IAISCRIPTING_H
