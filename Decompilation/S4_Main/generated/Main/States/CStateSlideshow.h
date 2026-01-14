#ifndef CSTATESLIDESHOW_H
#define CSTATESLIDESHOW_H

class CStateSlideshow : public CGameState {
public:
    // address=[0x14ca870]
    static class CGameState * __cdecl DynamicCreateFunc(void *);

    // address=[0x14ca8f0]
     CStateSlideshow(void *);

    // address=[0x14ca9b0]
    virtual  ~CStateSlideshow(void);

    // address=[0x14caa60]
    virtual bool  Perform(void);

    // address=[0x14caba0]
    virtual bool  OnEvent(class CEvn_Event &);

};


#endif // CSTATESLIDESHOW_H
