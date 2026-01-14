#ifndef CRESERVEENTRY_H
#define CRESERVEENTRY_H

class CReserveEntry : public CDynListEntry {
public:
    // address=[0x2f416b0]
     CReserveEntry(void);

    // address=[0x2f416d0]
     CReserveEntry(enum BUILDING_TYPES,int,int);

    // address=[0x2f41710]
    virtual  ~CReserveEntry(void);

};


#endif // CRESERVEENTRY_H
