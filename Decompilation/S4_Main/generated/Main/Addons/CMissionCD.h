#ifndef CMISSIONCD_H
#define CMISSIONCD_H

#include "defines.h"

class CMissionCD : public CExtraCD {
public:
    // address=[0x1481b40]
    virtual bool  IsExtraInstalledEx(void);

    // address=[0x1481b60]
    virtual void  EnsureExtraGUI(int a2, bool (__cdecl*)(int,int,int) a3);

    // address=[0x1481f80]
     CMissionCD(void);

    // address=[0x1482030]
    virtual  ~CMissionCD(void);

};


#endif // CMISSIONCD_H
