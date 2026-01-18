#ifndef CEFFECT_H
#define CEFFECT_H

#include "defines.h"

class CEffect {
public:
    // address=[0x144a5e0]
    void  InitEffect(int a2, enum SIV_SOUNDS a3, int a4, int a5, unsigned int a6, int a7, bool a8);

    // address=[0x144a700]
    void  InitAngel(enum T_EFFECT_ANGEL a2, enum SIV_SOUNDS a3, int a4, int a5, int a6, unsigned int a7);

    // address=[0x144a880]
    void  InitMissile(enum T_EFFECT_MISSILE a2, int a3, int a4, unsigned int a5, int a6, int a7);

    // address=[0x144ac00]
    void  InitSporeCloud(int a2, int a3, unsigned int a4);

    // address=[0x144aed0]
    void  InitStagnantAnimal(enum SIV_ANIMALS a2, enum SIV_SOUNDS a3, int a4, int a5, int a6, unsigned int a7);

    // address=[0x144afe0]
    void  InitMovingEffect(int a2, int a3, int a4);

    // address=[0x144b0f0]
    unsigned int  SetNewDestinationForMovingEffect(int a2, int a3, int a4);

    // address=[0x144b3e0]
    void  UpdateAttachedEffect(class CEffect const & a2);

    // address=[0x144b450]
    void  InitAttachedEffect(int a2, unsigned int a3, class CEffect const & a4, int a5);

    // address=[0x144b530]
    void  VisualizeEffect(struct SGfxObjectInfo & a2, int a3);

    // address=[0x144b5f0]
    void  VisualizeAngel(struct SGfxObjectInfo & a2, int a3);

    // address=[0x144b6e0]
    void  VisualizeArrow(struct SGfxObjectInfo & a2, int a3);

    // address=[0x144b800]
    void  VisualizeCannonball(struct SGfxObjectInfo & a2, int a3);

    // address=[0x144b950]
    void  VisualizeSporeCloud(struct SGfxObjectInfo & a2, int a3);

    // address=[0x144ba40]
    void  VisualizeStagnantAnimal(struct SGfxObjectInfo & a2, int a3);

    // address=[0x144bb10]
    void  VisualizeMovingEffect(struct SGfxObjectInfo & a2, int a3);

    // address=[0x144bc80]
    void  VisualizeTopEffect(struct SGfxObjectInfo & a2, int a3);

    // address=[0x144bd50]
    void  VisualizeTopFireball(struct SGfxObjectInfo & a2, int a3);

    // address=[0x144beb0]
    void  VisualizeAttachedEffect(struct SGfxObjectInfo & a2, int a3);

    // address=[0x144f270]
    void  VisualizeNOP(struct SGfxObjectInfo & a2, int a3);

    // address=[0x144f500]
    static void __cdecl GetEffectGfxInfo(struct SGfxObjectInfo & a1, int a2, unsigned int a3, unsigned int a4);

    // address=[0x144f530]
    static unsigned int __cdecl GetEffectNumberOfFrames(int a1);

    // address=[0x144f5c0]
    static void __cdecl GetWorldScreenCoordinates(int a1, int a2, int & a3, int & a4);

    // address=[0x144f620]
    static void __cdecl GetWorldScreenCoordinates(int a1, int a2, float & a3, float & a4);

    // address=[0x144f690]
    int  IsOutOfDate(int a2)const;

    // address=[0x144f700]
    void  SetVisualizeFunc(enum T_VISUALIZE_FUNC a2);

    // address=[0x144f770]
    int  SquareRow(void)const;

    // address=[0x144f790]
    int  TimeIndex(unsigned int a2)const;

    // address=[0x144f7b0]
    void  Visualize(struct SGfxObjectInfo & a2, int a3);

    // address=[0x144f7e0]
    enum T_VISUALIZE_FUNC  VisualizeFunc(void)const;

};


#endif // CEFFECT_H
