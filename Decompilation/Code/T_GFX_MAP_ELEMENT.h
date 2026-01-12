#ifndef T_GFX_MAP_ELEMENT_H
#define T_GFX_MAP_ELEMENT_H

class T_GFX_MAP_ELEMENT {
public:
    // address=[0x151aa30]
    int  GetGradient(void);

    // address=[0x15db1b0]
    int  GetNewFogging(void);

    // address=[0x15db1d0]
    int  GetOldFogging(void);

    // address=[0x2f90e30]
    void  SetNewFogging(int);

};


#endif // T_GFX_MAP_ELEMENT_H
