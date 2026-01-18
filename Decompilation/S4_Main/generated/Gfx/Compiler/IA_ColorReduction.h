#ifndef IA_COLORREDUCTION_H
#define IA_COLORREDUCTION_H

#include "defines.h"

class IA_ColorReduction {
public:
    // address=[0x2fd1bb0]
     IA_ColorReduction(void);

    // address=[0x2fd1be0]
     ~IA_ColorReduction(void);

    // address=[0x2fd1c50]
    bool  InitTree(void);

    // address=[0x2fd1cc0]
    bool  BuildTree(unsigned char * * const a2, unsigned int a3);

    // address=[0x2fd1dc0]
    void  DeleteTree(void);

    // address=[0x2fd1df0]
    void  ReduceIt(unsigned int a2);

    // address=[0x2fd1e20]
    void  MapColors(unsigned char * * const a2, unsigned char * a3, unsigned int a4);

    // address=[0x2fd1ef0]
    void  InitPalette(unsigned char * * const a2, unsigned int a3);

protected:
    // address=[0x2fd20e0]
    bool  InsertNode(class IA_ColorReduction_Node * a2, class IA_ColorReduction_Color & a3);

    // address=[0x2fd21d0]
    class IA_ColorReduction_Node *  MakeNode(int a2);

    // address=[0x2fd2290]
    void  DeleteNode(class IA_ColorReduction_Node * a2);

    // address=[0x2fd2350]
    void  MakeReducible(class IA_ColorReduction_Node * a2);

    // address=[0x2fd23b0]
    void  ReduceTree(void);

    // address=[0x2fd2460]
    class IA_ColorReduction_Node *  GetReducible(void);

    // address=[0x2fd2560]
    void  FillPalette(class IA_ColorReduction_Node * a2, unsigned int * a3);

    // address=[0x2fd2610]
    int  QuantizeColor(class IA_ColorReduction_Node * a2, class IA_ColorReduction_Color & a3);

};


#endif // IA_COLORREDUCTION_H
