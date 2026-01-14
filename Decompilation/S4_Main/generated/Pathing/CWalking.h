#ifndef CWALKING_H
#define CWALKING_H

class CWalking {
public:
    // address=[0x14d8690]
    bool  IsFree(int);

    // address=[0x15f6110]
    static class CWalking * __cdecl Create(enum T_WALKING_TYPE,int);

    // address=[0x15f62c0]
    static class CWalking * __cdecl Create(std::istream &);

    // address=[0x15faec0]
     CWalking(void);

    // address=[0x15faf50]
    virtual  ~CWalking(void);

};


#endif // CWALKING_H
