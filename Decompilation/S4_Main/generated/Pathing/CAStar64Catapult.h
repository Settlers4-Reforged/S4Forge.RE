#ifndef CASTAR64CATAPULT_H
#define CASTAR64CATAPULT_H

class CAStar64Catapult : public CAStar64 {
public:
    // address=[0x15d3ea0]
    static bool __cdecl IsNotBlocked(int);

    // address=[0x15d3ee0]
    static int __cdecl MoveCosts(int,int);

    // address=[0x15d5ec0]
     CAStar64Catapult(void);

private:
    // address=[0x15d3e70]
    virtual bool  InitFindPath(void);

};


#endif // CASTAR64CATAPULT_H
