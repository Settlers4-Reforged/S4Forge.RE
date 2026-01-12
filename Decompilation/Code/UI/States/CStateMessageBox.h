#ifndef CSTATEMESSAGEBOX_H
#define CSTATEMESSAGEBOX_H

class CStateMessageBox : public CGuiGameState {
public:
    // address=[0x14ca410]
    static class CGameState * __cdecl DynamicCreateFunc(void *);

    // address=[0x14ca490]
     CStateMessageBox(void *);

    // address=[0x14ca560]
    virtual  ~CStateMessageBox(void);

    // address=[0x14ca5e0]
    virtual bool  Perform(void);

    // address=[0x14ca680]
    virtual bool  OnEvent(class CEvn_Event &);

};


#endif // CSTATEMESSAGEBOX_H
