#ifndef CCONDITIONSET_H
#define CCONDITIONSET_H

class CConditionSet {
public:
    // address=[0x2f3ee40]
     CConditionSet(void);

    // address=[0x2f3eec0]
     ~CConditionSet(void);

    // address=[0x2f3ef00]
    int  size(void);

    // address=[0x2f3ef20]
    class CCondition *  elementAt(int);

    // address=[0x2f3ef40]
    void  NewMayProblem(int,class CParam *);

    // address=[0x2f3efe0]
    void  NewMayProblem(int,class CParam *,class COptimizeOptions *);

    // address=[0x2f3f010]
    void  NewProblem(int,class CParam *);

    // address=[0x2f3f0a0]
    void  NewProblem(int,class CParam *,class COptimizeOptions *);

    // address=[0x2f3f1e0]
    void  Ausgabe(void);

};


#endif // CCONDITIONSET_H
