#ifndef CCONDITION_H
#define CCONDITION_H

class CCondition : public CDynListEntry {
public:
    // address=[0x2f3ed60]
     CCondition(void);

    // address=[0x2f3ed80]
    virtual  ~CCondition(void);

    // address=[0x2f3ee00]
     CCondition(int,class CParam *,class COptimizeOptions *);

};


#endif // CCONDITION_H
