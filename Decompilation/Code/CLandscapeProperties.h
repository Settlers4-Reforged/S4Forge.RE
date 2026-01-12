#ifndef CLANDSCAPEPROPERTIES_H
#define CLANDSCAPEPROPERTIES_H

class CLandscapeProperties {
public:
    // address=[0x141d960]
    bool  IsBlockedLand(int);

    // address=[0x141d9a0]
    static bool __cdecl IsWater(int);

    // address=[0x15f5960]
    unsigned int  TileType(int);

    // address=[0x16a5e60]
     CLandscapeProperties(void);

    // address=[0x16a7200]
    bool  IsSlowType(int);

};


#endif // CLANDSCAPEPROPERTIES_H
