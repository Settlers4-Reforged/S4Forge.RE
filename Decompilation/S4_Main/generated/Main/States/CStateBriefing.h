#ifndef CSTATEBRIEFING_H
#define CSTATEBRIEFING_H

class CStateBriefing : public CGuiGameState {
public:
    // address=[0x14a1d50]
    static class CGameState * __cdecl DynamicCreateFunc(void *);

    // address=[0x14a1eb0]
     CStateBriefing(void *);

    // address=[0x14a2240]
    virtual  ~CStateBriefing(void);

    // address=[0x14a22c0]
    virtual bool  Perform(void);

    // address=[0x14a2390]
    virtual bool  OnEvent(class CEvn_Event &);

    // address=[0x14a2c20]
    static void __cdecl InitBriefingTexts(int,int);

private:
    // address=[0x14a1dd0]
    void  PaintMap(bool);

};


#endif // CSTATEBRIEFING_H
