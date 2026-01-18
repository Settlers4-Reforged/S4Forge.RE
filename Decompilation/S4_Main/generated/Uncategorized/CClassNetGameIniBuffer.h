#ifndef CCLASSNETGAMEINIBUFFER_H
#define CCLASSNETGAMEINIBUFFER_H

#include "defines.h"

class CClassNetGameIniBuffer {
public:
    // address=[0x15bf230]
    int  GetIntValue(char const * SubStr, int a3);

    // address=[0x15bf280]
    char const *  GetStartOfEntry(char const * SubStr);

    // address=[0x15c3880]
     CClassNetGameIniBuffer(char const * a2, unsigned int a3);

};


#endif // CCLASSNETGAMEINIBUFFER_H
