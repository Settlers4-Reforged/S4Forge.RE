#ifndef IAIECOSECTORAI_H
#define IAIECOSECTORAI_H

class IAIEcoSectorAI : public IAIUnknown {
public:
    // address=[0x2f346f0]
    static int __cdecl InterfaceVersion(void);

    // address=[0x2f34700]
    static class IAIEcoSectorAI * __cdecl CreateEcoSectorAI(class IAIEcoManager *);

    // address=[0x2f3b2e0]
     IAIEcoSectorAI(void);

};


#endif // IAIECOSECTORAI_H
