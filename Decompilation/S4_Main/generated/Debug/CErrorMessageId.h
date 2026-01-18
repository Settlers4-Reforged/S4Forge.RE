#ifndef CERRORMESSAGEID_H
#define CERRORMESSAGEID_H

#include "defines.h"

class CErrorMessageId {
public:
    // address=[0x14810b0]
     CErrorMessageId(char const * Str1);

    // address=[0x1481160]
     CErrorMessageId(class CErrorMessageId const & a2);

    // address=[0x1481180]
    int  GetId(void)const;

};


#endif // CERRORMESSAGEID_H
