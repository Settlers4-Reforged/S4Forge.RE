#ifndef CSOLUTIONTREE_H
#define CSOLUTIONTREE_H

class CSolutionTree : public CDynListEntry {
public:
    // address=[0x2f3eac0]
     CSolutionTree(void);

    // address=[0x2f3eae0]
    virtual  ~CSolutionTree(void);

    // address=[0x2f3eb60]
     CSolutionTree(int,class CParam *);

    // address=[0x2f3ec50]
    void  NewSubSolution(int,class CParam *);

    // address=[0x2f3ece0]
    void  NewSubSolution(class CSolutionTree *);

};


#endif // CSOLUTIONTREE_H
