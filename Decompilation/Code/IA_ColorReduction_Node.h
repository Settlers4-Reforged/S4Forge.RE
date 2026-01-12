#ifndef IA_COLORREDUCTION_NODE_H
#define IA_COLORREDUCTION_NODE_H

class IA_ColorReduction_Node {
public:
    // address=[0x2fd3800]
     IA_ColorReduction_Node(int,bool);

    // address=[0x2fd3840]
     ~IA_ColorReduction_Node(void);

    // address=[0x2fd3850]
    unsigned long  GetColorCount(void);

    // address=[0x2fd3870]
    void  AddColor(class IA_ColorReduction_Color &);

    // address=[0x2fd38f0]
    class IA_ColorReduction_Color  GetColor(void);

    // address=[0x2fd3970]
    void  SetColorIndex(int);

    // address=[0x2fd3990]
    int  GetColorIndex(void);

    // address=[0x2fd39b0]
    void  SetNext(class IA_ColorReduction_Node *);

    // address=[0x2fd39d0]
    class IA_ColorReduction_Node *  GetNext(void);

    // address=[0x2fd39f0]
    void  SetPrev(class IA_ColorReduction_Node *);

    // address=[0x2fd3a10]
    class IA_ColorReduction_Node *  GetPrev(void);

    // address=[0x2fd3a30]
    int  GetNumChild(void);

    // address=[0x2fd3a50]
    void  SetChild(int,class IA_ColorReduction_Node *);

    // address=[0x2fd3a70]
    class IA_ColorReduction_Node *  GetChild(int);

    // address=[0x2fd3a90]
    int  FindChild(class IA_ColorReduction_Color &);

    // address=[0x2fd3b30]
    void  IncNumChild(void);

    // address=[0x2fd3b50]
    void  DecNumChild(void);

    // address=[0x2fd3b70]
    int  GetLevel(void);

    // address=[0x2fd3b80]
    void  SetLeaf(bool);

    // address=[0x2fd3ba0]
    bool  IsLeaf(void);

    // address=[0x2fd3bc0]
    void  SetReducible(bool);

    // address=[0x2fd3be0]
    bool  IsReducible(void);

private:
    // address=[0x2fd3c00]
    int  TestBit(unsigned char,int);

};


#endif // IA_COLORREDUCTION_NODE_H
