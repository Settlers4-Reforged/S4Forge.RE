#ifndef CMAPCHECK_H
#define CMAPCHECK_H

#include "defines.h"

class CMapCheck : public IMapCheck {
public:
    // address=[0x1496ac0]
    virtual unsigned int  CalculateMapCRC2(int a2, int a3, int a4, int a5, int a6);

    // address=[0x1496af0]
    virtual enum IMapCheck::PATCHMAPS  GetPatchMap(wchar_t const * Source, unsigned int a2, unsigned int a3);

    // address=[0x1496d10]
     CMapCheck(void);

protected:
    // address=[0x1496b80]
    static bool __cdecl StrStrLo(wchar_t const * Source, wchar_t const * SubStr);

};


#endif // CMAPCHECK_H
