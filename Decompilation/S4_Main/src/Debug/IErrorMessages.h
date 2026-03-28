#ifndef IERRORMESSAGES_H
#define IERRORMESSAGES_H

#include "defines.h"

class IErrorMessages {
public:
    // address=[0x1481390]
    IErrorMessages(void);

    virtual char const *GetErrorMessage(class CErrorMessageId const &a2) const = 0;
};


#endif // IERRORMESSAGES_H
