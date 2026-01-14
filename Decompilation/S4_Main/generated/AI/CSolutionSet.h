#ifndef CSOLUTIONSET_H
#define CSOLUTIONSET_H

class CSolutionSet : public CDynListEntry {
public:
    // address=[0x2f3f250]
     CSolutionSet(void);

    // address=[0x2f3f2f0]
    virtual  ~CSolutionSet(void);

    // address=[0x2f3f340]
    int  size(void);

    // address=[0x2f3f360]
    void  NewSolution(int,class CParam *);

};


#endif // CSOLUTIONSET_H
