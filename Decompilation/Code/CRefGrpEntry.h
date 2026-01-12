#ifndef CREFGRPENTRY_H
#define CREFGRPENTRY_H

class CRefGrpEntry : public CDynListEntry {
public:
    // address=[0x2f41840]
     CRefGrpEntry(int,class CGrpReserveEntry *);

    // address=[0x2f41880]
    virtual  ~CRefGrpEntry(void);

};


#endif // CREFGRPENTRY_H
