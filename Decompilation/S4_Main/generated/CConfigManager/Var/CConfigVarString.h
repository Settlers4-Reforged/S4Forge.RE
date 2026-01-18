#ifndef CCONFIGVARSTRING_H
#define CCONFIGVARSTRING_H

#include "defines.h"

class CConfigVarString : public CDynamicConfigVar {
public:
    // address=[0x2efa0f0]
    virtual std::string  GetStringValue(void a2)const;

    // address=[0x2efa310]
    virtual void  SetValue(std::string const & a1);

    // address=[0x2efa340]
    virtual void  SetValue(char const * Str);

private:
    // address=[0x2ef8770]
     CConfigVarString(std::string const & a2);

    // address=[0x2ef8c80]
    virtual  ~CConfigVarString(void);

};


#endif // CCONFIGVARSTRING_H
