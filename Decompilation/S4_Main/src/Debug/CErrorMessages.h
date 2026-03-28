#ifndef CERRORMESSAGES_H
#define CERRORMESSAGES_H

#include "defines.h"
#include "CErrorMessageId.h"
#include "IErrorMessages.h"

extern class CErrorMessages *g_pErrorMessages;

class CErrorMessages : public IErrorMessages {
public:
    // address=[0x14812a0]
    virtual char const *GetErrorMessage(CErrorMessageId const &a2) const;

    // address=[0x1481360]
    CErrorMessages(void);
};


#endif // CERRORMESSAGES_H
