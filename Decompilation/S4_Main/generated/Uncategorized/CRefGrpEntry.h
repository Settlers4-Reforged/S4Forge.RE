#ifndef CREFGRPENTRY_H
#define CREFGRPENTRY_H

#include "defines.h"

class CRefGrpEntry : public CDynListEntry {
public:
    // address=[0x2f41840]
     CRefGrpEntry(int a2, class CGrpReserveEntry * a3);

    // address=[0x2f41880]
    virtual  ~CRefGrpEntry(void);

};


#endif // CREFGRPENTRY_H
