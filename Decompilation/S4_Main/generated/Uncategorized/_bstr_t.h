#ifndef _BSTR_T_H
#define _BSTR_T_H

#include "defines.h"

class _bstr_t {
public:
    // address=[0x2fbecd0]
     _bstr_t(wchar_t const * psz);

    // address=[0x2fbedb0]
     ~_bstr_t(void);

    // address=[0x2fbedf0]
     operator char const *(void)const;

private:
    // address=[0x2fbef80]
    void  _Free(void);

};


#endif // _BSTR_T_H
