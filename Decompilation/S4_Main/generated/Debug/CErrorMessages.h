#ifndef CERRORMESSAGES_H
#define CERRORMESSAGES_H

#include "defines.h"

class CErrorMessages : public IErrorMessages {
public:
    // address=[0x14812a0]
    virtual char const *  GetErrorMessage(class CErrorMessageId const & a2)const;

    // address=[0x1481360]
     CErrorMessages(void);

};


#endif // CERRORMESSAGES_H
