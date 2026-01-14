#ifndef CASTAR64_H
#define CASTAR64_H

class CAStar64 {
public:
    // address=[0x15d3820]
    bool  FindPath(int,int,class CDirCache &);

    // address=[0x15d5ea0]
     CAStar64(void);

protected:
    // address=[0x15d6de0]
    static int __cdecl SettlerDisplacementCosts(int,int);

    // address=[0x15d7130]
    static int __cdecl WorldMoveCosts(int);

    // address=[0x15d7150]
    static int __cdecl WorldMoveCostsNoRoad(int);

};


#endif // CASTAR64_H
