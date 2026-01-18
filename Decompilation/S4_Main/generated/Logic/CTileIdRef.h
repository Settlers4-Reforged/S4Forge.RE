#ifndef CTILEIDREF_H
#define CTILEIDREF_H

#include "defines.h"

class CTileIdRef {
public:
    // address=[0x15d5f80]
     CTileIdRef(enum T_TILING_TYPE a2, int a3);

    // address=[0x15d6e70]
    int  TileId(int a2)const;

    // address=[0x15f4080]
    class CTileIdRef &  operator++(void);

    // address=[0x15f40b0]
    class CTileIdRef &  operator+=(int a2);

protected:
    // address=[0x15f5860]
    void  SetTileId(int a2)const;

    // address=[0x15f5880]
    void  SetTileId(int a2, int a3)const;

};


#endif // CTILEIDREF_H
