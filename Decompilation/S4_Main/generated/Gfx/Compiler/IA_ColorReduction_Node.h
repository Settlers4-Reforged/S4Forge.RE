#ifndef IA_COLORREDUCTION_NODE_H
#define IA_COLORREDUCTION_NODE_H

#include "defines.h"

class IA_ColorReduction_Node {
public:
    // address=[0x2fd3800]
     IA_ColorReduction_Node(int a2, bool a3);

    // address=[0x2fd3840]
     ~IA_ColorReduction_Node(void);

    // address=[0x2fd3850]
    unsigned long  GetColorCount(void);

    // address=[0x2fd3870]
    void  AddColor(class IA_ColorReduction_Color & a2);

    // address=[0x2fd38f0]
    class IA_ColorReduction_Color  GetColor(void a2);

    // address=[0x2fd3970]
    void  SetColorIndex(int a2);

    // address=[0x2fd3990]
    int  GetColorIndex(void);

    // address=[0x2fd39b0]
    void  SetNext(class IA_ColorReduction_Node * a2);

    // address=[0x2fd39d0]
    class IA_ColorReduction_Node *  GetNext(void);

    // address=[0x2fd39f0]
    void  SetPrev(class IA_ColorReduction_Node * a2);

    // address=[0x2fd3a10]
    class IA_ColorReduction_Node *  GetPrev(void);

    // address=[0x2fd3a30]
    int  GetNumChild(void);

    // address=[0x2fd3a50]
    void  SetChild(int a2, class IA_ColorReduction_Node * a3);

    // address=[0x2fd3a70]
    class IA_ColorReduction_Node *  GetChild(int a2);

    // address=[0x2fd3a90]
    int  FindChild(class IA_ColorReduction_Color & a2);

    // address=[0x2fd3b30]
    void  IncNumChild(void);

    // address=[0x2fd3b50]
    void  DecNumChild(void);

    // address=[0x2fd3b70]
    int  GetLevel(void);

    // address=[0x2fd3b80]
    void  SetLeaf(bool a2);

    // address=[0x2fd3ba0]
    bool  IsLeaf(void);

    // address=[0x2fd3bc0]
    void  SetReducible(bool a2);

    // address=[0x2fd3be0]
    bool  IsReducible(void);

private:
    // address=[0x2fd3c00]
    int  TestBit(unsigned char a2, int a3);

};


#endif // IA_COLORREDUCTION_NODE_H
