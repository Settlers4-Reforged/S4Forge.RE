#ifndef CSOLUTIONTREE_H
#define CSOLUTIONTREE_H

#include "defines.h"

class CSolutionTree : public CDynListEntry {
public:
    // address=[0x2f3eac0]
     CSolutionTree(void);

    // address=[0x2f3eae0]
    virtual  ~CSolutionTree(void);

    // address=[0x2f3eb60]
     CSolutionTree(int a2, class CParam * a3);

    // address=[0x2f3ec50]
    void  NewSubSolution(int a2, class CParam * a3);

    // address=[0x2f3ece0]
    void  NewSubSolution(class CSolutionTree * a2);

};


#endif // CSOLUTIONTREE_H
