#ifndef CSECTORS_H
#define CSECTORS_H

class CSectors {
public:
    // address=[0x15e79a0]
    void  Init(void);

    // address=[0x15e7a20]
    int  NewSector(unsigned char);

    // address=[0x15e7ad0]
    void  DeleteSector(int);

    // address=[0x15e7b40]
    int  CountSectors(unsigned char)const;

    // address=[0x15f3ed0]
     CSectors(void);

    // address=[0x15f4620]
    void  IncSectorSize(int);

    // address=[0x15f5660]
    int  SectorSize(int)const;

};


#endif // CSECTORS_H
