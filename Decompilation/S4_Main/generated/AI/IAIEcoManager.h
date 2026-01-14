#ifndef IAIECOMANAGER_H
#define IAIECOMANAGER_H

class IAIEcoManager {
public:
    // address=[0x133ae70]
    static class IAIEcoManager * __cdecl CreateEcoManager(int,class IAISectorAI *,class IAIEventQueue *);

    // address=[0x1345700]
     IAIEcoManager(void);

    // address=[0x1345e20]
    virtual  ~IAIEcoManager(void);

};


#endif // IAIECOMANAGER_H
