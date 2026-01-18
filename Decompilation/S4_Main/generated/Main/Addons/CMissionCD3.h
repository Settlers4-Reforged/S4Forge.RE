#ifndef CMISSIONCD3_H
#define CMISSIONCD3_H

#include "defines.h"

class CMissionCD3 : public CExtraCD {
public:
    // address=[0x1481c60]
    virtual bool  IsExtraInstalledEx(void);

    // address=[0x1481c80]
    virtual void  EnsureExtraGUI(int a2, bool (__cdecl*)(int,int,int) a3);

    // address=[0x1481f50]
     CMissionCD3(void);

    // address=[0x1482010]
    virtual  ~CMissionCD3(void);

};


#endif // CMISSIONCD3_H
