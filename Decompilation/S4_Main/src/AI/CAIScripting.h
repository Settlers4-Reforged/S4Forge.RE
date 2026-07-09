#ifndef CAISCRIPTING_H
#define CAISCRIPTING_H

#include "IAIScripting.h"
#include "defines.h"

class CAIScripting : public IAIScripting {
  public:
    // address=[0x131e8c0]
    CAIScripting(void);

  protected:
    // address=[0x131dc20]
    void InitPlayerScriptVarsDefaultValues(void);
};

#endif // CAISCRIPTING_H
