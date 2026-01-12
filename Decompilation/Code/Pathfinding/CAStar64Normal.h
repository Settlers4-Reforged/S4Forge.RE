#ifndef CASTAR64NORMAL_H
#define CASTAR64NORMAL_H

class CAStar64Normal : public CAStar64 {
public:
    // address=[0x15d3ce0]
    static bool __cdecl IsNotBlocked(int);

    // address=[0x15d3d10]
    static int __cdecl MoveCosts(int,int);

    // address=[0x15d5ef0]
     CAStar64Normal(void);

protected:
    // address=[0x15d3cb0]
    virtual bool  InitFindPath(void);

};


#endif // CASTAR64NORMAL_H
