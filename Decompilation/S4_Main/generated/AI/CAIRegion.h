#ifndef CAIREGION_H
#define CAIREGION_H

#include "defines.h"

class CAIRegion {
public:
    // address=[0x1311ef0]
    bool  Used(void)const;

protected:
    // address=[0x13115f0]
    void  Load(class IS4Chunk & a2);

    // address=[0x1311640]
    void  Save(class IS4Chunk & a2);

    // address=[0x1311c80]
    void  Clear(void);

    // address=[0x1311ca0]
    void  DefineRegion(int a2, int a3, int a4);

};


#endif // CAIREGION_H
