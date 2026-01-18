#ifndef CMISSIONCD2_H
#define CMISSIONCD2_H

#include "defines.h"

class CMissionCD2 : public CExtraCD {
public:
    // address=[0x1481c00]
    virtual bool  IsExtraInstalledEx(void);

    // address=[0x1481c20]
    virtual void  EnsureExtraGUI(int a2, bool (__cdecl*)(int,int,int) a3);

    // address=[0x1481f20]
     CMissionCD2(void);

    // address=[0x1481ff0]
    virtual  ~CMissionCD2(void);

};


#endif // CMISSIONCD2_H
