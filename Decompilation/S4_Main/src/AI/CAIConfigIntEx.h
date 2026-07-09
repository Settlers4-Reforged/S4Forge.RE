#ifndef CAICONFIGINTEX_H
#define CAICONFIGINTEX_H

#include "CConfigManager/Var/TStaticConfigIntArray.h"
#include "defines.h"

constexpr int USE_PREV_CONFIG_VALUE = -2147483648;

class CAIConfigIntEx : public TStaticConfigIntArray<3> {
  public:
    // address=[0x131e810]
    CAIConfigIntEx(char const *_spVarName, int _iDefault0, int _iDefault1, int _iDefault2);

    // address=[0x131ea80]
    virtual ~CAIConfigIntEx(void);

    // address=[0x131ecd0]
    char const *Name(void) const;

  private:
    const char *m_spName;
};

#endif // CAICONFIGINTEX_H
