#ifndef CEFFECTS_H
#define CEFFECTS_H

class CEffects : public IEffects, public CBBObject {
public:
    // address=[0x144bfb0]
     CEffects(void);

    // address=[0x144c200]
    virtual  ~CEffects(void);

    // address=[0x144c280]
    virtual void  SetEffectsViewport(int,int,int,int,int);

    // address=[0x144c3a0]
    virtual struct SGfxObjectInfo *  FirstEffect(int);

    // address=[0x144c6e0]
    virtual struct SGfxObjectInfo *  NextEffect(void);

    // address=[0x144c880]
    virtual void  Load(class IS4Chunk &);

    // address=[0x144ca00]
    virtual void  Save(class IS4Chunk &);

    // address=[0x144cae0]
    virtual unsigned int  AddEffect(int,enum SIV_SOUNDS,int,int,unsigned int,int,bool);

    // address=[0x144cbb0]
    virtual unsigned int  AddAngel(enum T_EFFECT_ANGEL,enum SIV_SOUNDS,int,int,int,unsigned int);

    // address=[0x144cd20]
    virtual unsigned int  AddMissile(enum T_EFFECT_MISSILE,int,int,unsigned int,int,int);

    // address=[0x144ce50]
    virtual unsigned int  AddSporeCloud(int,int,unsigned int);

    // address=[0x144cf90]
    virtual unsigned int  AddStagnantAnimal(enum SIV_ANIMALS,enum SIV_SOUNDS,int,int,int,unsigned int);

    // address=[0x144d0f0]
    virtual void  DeleteEffect(unsigned int);

    // address=[0x144d180]
    virtual unsigned int  CreateMovingEffect(int,int,int);

    // address=[0x144d230]
    virtual void  ChangeMovingEffectType(unsigned int,int);

    // address=[0x144d330]
    virtual int  NumberOfMovingEffects(int);

    // address=[0x144d3a0]
    virtual void  GetMovingEffectInfo(unsigned int,int &,int &,int &,int &);

    // address=[0x144d4f0]
    virtual void  SetMovingEffectSpeed(unsigned int,int);

    // address=[0x144d560]
    virtual unsigned int  SetMovingEffectDestination(unsigned int,int,int,int);

    // address=[0x144d620]
    virtual int  GetMovingEffectDirection(unsigned int);

    // address=[0x144d680]
    virtual void  SetMovingEffectDirection(unsigned int,int);

    // address=[0x144d6f0]
    virtual int  GetMovingEffectSoundId(unsigned int);

    // address=[0x144d740]
    virtual void  SetMovingEffectSoundId(unsigned int,int);

    // address=[0x144d790]
    virtual unsigned int  CreateAttachedEffect(int,unsigned int,int);

    // address=[0x144d860]
    virtual void  SetAttachedEffectOffset(unsigned int,float,float);

    // address=[0x144d8c0]
    virtual void  UpdateAttachedEffect(unsigned int);

    // address=[0x144d950]
    virtual bool  WasAttachedEffectVisible(unsigned int);

    // address=[0x144d9b0]
    virtual void  Execute(void);

    // address=[0x144dbf0]
    virtual void  Release(void);

    // address=[0x144dc30]
    virtual unsigned int  DbgCheckData(int);

protected:
    // address=[0x144dc40]
    void  AddEffectToFreeList(unsigned int);

    // address=[0x144dda0]
    void  AddEffectToSquareList(unsigned int);

    // address=[0x144df80]
    void  RemoveEffectFromList(unsigned int);

    // address=[0x144e170]
    void  CleanUp(void);

    // address=[0x144f340]
    bool  CheckParentEffect(unsigned int);

    // address=[0x144f3b0]
    static void __cdecl ClipXOrY(int &);

    // address=[0x144f3f0]
    void  DecreaseMovingEffectCounter(int);

    // address=[0x144f4a0]
    unsigned short &  EffectSquareListHeadVW(int,int);

    // address=[0x144f4d0]
    unsigned int  FirstFreeEffectId(void);

    // address=[0x144f650]
    void  IncreaseMovingEffectCounter(int);

    // address=[0x144f6d0]
    void  MoveEffectFromSquareListToFreeList(unsigned int);

private:
    // address=[0x3f11f68]
    static struct SGfxObjectInfo m_sGfxInfo;

};


#endif // CEFFECTS_H
