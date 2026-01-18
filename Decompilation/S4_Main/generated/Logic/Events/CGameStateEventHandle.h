#ifndef CGAMESTATEEVENTHANDLE_H
#define CGAMESTATEEVENTHANDLE_H

#include "defines.h"

class CGameStateEventHandle : public IEvn_Handle {
public:
    // address=[0x1489f60]
     CGameStateEventHandle(void);

    // address=[0x1489f80]
    virtual  ~CGameStateEventHandle(void);

    // address=[0x1489fa0]
    virtual bool  OnEvent(class CEvn_Event & a2);

};


#endif // CGAMESTATEEVENTHANDLE_H
