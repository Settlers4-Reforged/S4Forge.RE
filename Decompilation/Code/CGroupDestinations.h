#ifndef CGROUPDESTINATIONS_H
#define CGROUPDESTINATIONS_H

class CGroupDestinations {
public:
    // address=[0x15507a0]
     CGroupDestinations(int,int,int,int,int);

    // address=[0x1552710]
    int  GetNextDestination(void);

protected:
    // address=[0x15509f0]
    static int __fastcall NormalSectorId(int,int);

    // address=[0x1550a10]
    static int __fastcall CatapultSectorId(int,int);

};


#endif // CGROUPDESTINATIONS_H
