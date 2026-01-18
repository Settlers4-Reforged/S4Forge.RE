#ifndef CCONFIGFILE_H
#define CCONFIGFILE_H

#include "defines.h"

class CConfigFile {
public:
    // address=[0x2f28860]
     CConfigFile(wchar_t const * FileName);

    // address=[0x2f28980]
     ~CConfigFile(void);

    // address=[0x2f289c0]
    char *  GetConfig(void);

    // address=[0x2f289e0]
    unsigned int  GetSize(void);

    // address=[0x2f28a00]
    wchar_t const *  GetName(void);

};


#endif // CCONFIGFILE_H
