#ifndef CSTATELOADTYPE_H
#define CSTATELOADTYPE_H

class CStateLoadType : public CGuiGameState {
public:
    // address=[0x14b6480]
    static class CGameState * __cdecl DynamicCreateFunc(void *);

    // address=[0x14b6500]
     CStateLoadType(void *);

    // address=[0x14b6570]
    virtual  ~CStateLoadType(void);

    // address=[0x14b65f0]
    virtual bool  Perform(void);

    // address=[0x14b6690]
    virtual bool  OnEvent(class CEvn_Event &);

};


#endif // CSTATELOADTYPE_H
