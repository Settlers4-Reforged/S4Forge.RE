#ifndef CECOSECTORAI_H
#define CECOSECTORAI_H

class CEcoSectorAI : public IAIEcoSectorAI {
public:
    // address=[0x2f34860]
     CEcoSectorAI(void);

    // address=[0x2f34890]
     CEcoSectorAI(class IAIEcoManager *,class IAISectorAI *,int,int);

    // address=[0x2f34a20]
     ~CEcoSectorAI(void);

    // address=[0x2f34af0]
    virtual void  Release(void);

    // address=[0x2f34b30]
    void  ReadConfigFile(void);

    // address=[0x2f34bb0]
    virtual void  Execute(void);

    // address=[0x2f34bd0]
    virtual enum T_AI_BUILD_RESULT  PutUpBuilding(int,int,int,int);

    // address=[0x2f34c90]
    virtual int  Flags(void);

    // address=[0x2f34cb0]
    virtual void  SetFlags(int);

};


#endif // CECOSECTORAI_H
