#ifndef CASTAR64SHIP_H
#define CASTAR64SHIP_H

class CAStar64Ship : public CAStar64 {
public:
    // address=[0x15d3fd0]
    static bool __cdecl IsNotBlocked(int);

    // address=[0x15d4000]
    static int __cdecl MoveCosts(int,int);

    // address=[0x15d5f20]
     CAStar64Ship(void);

private:
    // address=[0x15d3fa0]
    virtual bool  InitFindPath(void);

};


#endif // CASTAR64SHIP_H
