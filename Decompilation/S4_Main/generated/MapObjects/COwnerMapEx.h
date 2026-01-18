#ifndef COWNERMAPEX_H
#define COWNERMAPEX_H

#include "defines.h"

class COwnerMapEx {
protected:
    // address=[0x15de0a0]
    static void __cdecl CalculateOwnerBits(void);

    // address=[0x15de190]
    static void __cdecl NotifyCreateTile(int a1, int a2);

    // address=[0x15de380]
    static void __cdecl NotifyDeleteTile(int a1, int a2);

};


#endif // COWNERMAPEX_H
