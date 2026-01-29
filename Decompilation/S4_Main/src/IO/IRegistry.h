#ifndef IREGISTRY_H
#define IREGISTRY_H

#include "defines.h"

class IRegistry
{
public:
    // address=[0x149ab30]
    IRegistry(void);

    virtual bool ExistsHLMKey(char const *lpSubKey) = 0;
};

#endif // IREGISTRY_H
