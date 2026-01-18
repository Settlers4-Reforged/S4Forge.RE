#ifndef CWARMAP_H
#define CWARMAP_H

#include "defines.h"

class CWarMap {
public:
    // address=[0x131c8e0]
    static int __cdecl FirstEntityIdVW(enum T_WAR_MAP_TYPE a1, int a2, int a3);

    // address=[0x1351c00]
    static unsigned int __cdecl NumberOfEntitiesXY(enum T_WAR_MAP_TYPE a1, int a2, int a3);

    // address=[0x14e0030]
    static unsigned int __cdecl NumberOfEntitiesVW(enum T_WAR_MAP_TYPE a1, int a2, int a3);

    // address=[0x152bce0]
    static int __cdecl FirstEntityIdXY(enum T_WAR_MAP_TYPE a1, int a2, int a3);

    // address=[0x15e2d40]
    static int __cdecl SettlerInfluValue(int a1);

    // address=[0x15fb5f0]
    static void __cdecl Init(void);

    // address=[0x15fb7d0]
    static void __cdecl Done(void);

    // address=[0x15fb840]
    static void __cdecl AddEntity(class IEntity & target);

    // address=[0x15fb880]
    static void __cdecl RemoveEntity(class IEntity & a1);

    // address=[0x15fb8b0]
    static void __cdecl NotifyMove(class IEntity & a1, int a2);

    // address=[0x15fc6b0]
    static enum T_WAR_MAP_TYPE __cdecl ObjectTypeToWarMapType(int a1);

protected:
    // address=[0x15fbb80]
    static void __cdecl AddEntityEx(class IEntity & target, int packedXY);

    // address=[0x15fbeb0]
    static void __cdecl RemoveEntityEx(class IEntity & a1, int a2);

private:
    // address=[0x15fc7c0]
    static struct SWarMapTypeSquareData & __cdecl CWarMap::WarMapTypeSquareDataVW(enum T_WAR_MAP_TYPE a1, int a2, int a3);

    // address=[0x45b2050]
    static int * m_iSettlerInfluValues;

    // address=[0x45b2168]
    static int m_iInitialized;

    // address=[0x45b2170]
    static struct SWarMapSquare (* CWarMap::m_sSquares)[64];

};


#endif // CWARMAP_H
