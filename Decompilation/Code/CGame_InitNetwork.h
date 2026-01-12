#ifndef CGAME_INITNETWORK_H
#define CGAME_INITNETWORK_H

class CGame_InitNetwork : public CGameState {
public:
    // address=[0x15c7f60]
    static class CGameState * __cdecl DynamicCreateFunc(void *);

    // address=[0x15c7fe0]
     CGame_InitNetwork(void *);

    // address=[0x15c8280]
    virtual  ~CGame_InitNetwork(void);

    // address=[0x15c82a0]
    virtual bool  Perform(void);

    // address=[0x15c82f0]
    virtual bool  OnEvent(class CEvn_Event &);

};


#endif // CGAME_INITNETWORK_H
