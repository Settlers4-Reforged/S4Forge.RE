#ifndef CTILEIDREF_H
#define CTILEIDREF_H

class CTileIdRef {
public:
    // address=[0x15d5f80]
     CTileIdRef(enum T_TILING_TYPE,int);

    // address=[0x15d6e70]
    int  TileId(int)const;

    // address=[0x15f4080]
    class CTileIdRef &  operator++(void);

    // address=[0x15f40b0]
    class CTileIdRef &  operator+=(int);

protected:
    // address=[0x15f5860]
    void  SetTileId(int)const;

    // address=[0x15f5880]
    void  SetTileId(int,int)const;

};


#endif // CTILEIDREF_H
