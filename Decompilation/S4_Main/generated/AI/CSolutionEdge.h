#ifndef CSOLUTIONEDGE_H
#define CSOLUTIONEDGE_H

#include "defines.h"

class CSolutionEdge : public CDynListEntry {
public:
    // address=[0x2f3e7e0]
     CSolutionEdge(int a2, int a3);

    // address=[0x2f3e820]
    virtual  ~CSolutionEdge(void);

    // address=[0x2f3e840]
    void  show(void);

};


#endif // CSOLUTIONEDGE_H
