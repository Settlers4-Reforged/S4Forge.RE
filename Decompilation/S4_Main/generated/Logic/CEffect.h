#ifndef CEFFECT_H
#define CEFFECT_H

class CEffect {
public:
    // address=[0x144a5e0]
    void  InitEffect(int,enum SIV_SOUNDS,int,int,unsigned int,int,bool);

    // address=[0x144a700]
    void  InitAngel(enum T_EFFECT_ANGEL,enum SIV_SOUNDS,int,int,int,unsigned int);

    // address=[0x144a880]
    void  InitMissile(enum T_EFFECT_MISSILE,int,int,unsigned int,int,int);

    // address=[0x144ac00]
    void  InitSporeCloud(int,int,unsigned int);

    // address=[0x144aed0]
    void  InitStagnantAnimal(enum SIV_ANIMALS,enum SIV_SOUNDS,int,int,int,unsigned int);

    // address=[0x144afe0]
    void  InitMovingEffect(int,int,int);

    // address=[0x144b0f0]
    unsigned int  SetNewDestinationForMovingEffect(int,int,int);

    // address=[0x144b3e0]
    void  UpdateAttachedEffect(class CEffect const &);

    // address=[0x144b450]
    void  InitAttachedEffect(int,unsigned int,class CEffect const &,int);

    // address=[0x144b530]
    void  VisualizeEffect(struct SGfxObjectInfo &,int);

    // address=[0x144b5f0]
    void  VisualizeAngel(struct SGfxObjectInfo &,int);

    // address=[0x144b6e0]
    void  VisualizeArrow(struct SGfxObjectInfo &,int);

    // address=[0x144b800]
    void  VisualizeCannonball(struct SGfxObjectInfo &,int);

    // address=[0x144b950]
    void  VisualizeSporeCloud(struct SGfxObjectInfo &,int);

    // address=[0x144ba40]
    void  VisualizeStagnantAnimal(struct SGfxObjectInfo &,int);

    // address=[0x144bb10]
    void  VisualizeMovingEffect(struct SGfxObjectInfo &,int);

    // address=[0x144bc80]
    void  VisualizeTopEffect(struct SGfxObjectInfo &,int);

    // address=[0x144bd50]
    void  VisualizeTopFireball(struct SGfxObjectInfo &,int);

    // address=[0x144beb0]
    void  VisualizeAttachedEffect(struct SGfxObjectInfo &,int);

    // address=[0x144f270]
    void  VisualizeNOP(struct SGfxObjectInfo &,int);

    // address=[0x144f500]
    static void __cdecl GetEffectGfxInfo(struct SGfxObjectInfo &,int,unsigned int,unsigned int);

    // address=[0x144f530]
    static unsigned int __cdecl GetEffectNumberOfFrames(int);

    // address=[0x144f5c0]
    static void __cdecl GetWorldScreenCoordinates(int,int,int &,int &);

    // address=[0x144f620]
    static void __cdecl GetWorldScreenCoordinates(int,int,float &,float &);

    // address=[0x144f690]
    int  IsOutOfDate(int)const;

    // address=[0x144f700]
    void  SetVisualizeFunc(enum T_VISUALIZE_FUNC);

    // address=[0x144f770]
    int  SquareRow(void)const;

    // address=[0x144f790]
    int  TimeIndex(unsigned int)const;

    // address=[0x144f7b0]
    void  Visualize(struct SGfxObjectInfo &,int);

    // address=[0x144f7e0]
    enum T_VISUALIZE_FUNC  VisualizeFunc(void)const;

};


#endif // CEFFECT_H
