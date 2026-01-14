#ifndef CDEBITLEVELMANAGER_H
#define CDEBITLEVELMANAGER_H

class CDebitLevelManager {
public:
    // address=[0x2f58b30]
     CDebitLevelManager(class CSchedule *);

    // address=[0x2f58b60]
     ~CDebitLevelManager(void);

    // address=[0x2f58b70]
    bool  AddDebitLevel(int,enum PILE_TYPES,bool,int,int,int,int,int,int);

    // address=[0x2f58d00]
    int  GetDebitValue(int,enum PILE_TYPES,bool,int);

    // address=[0x2f58df0]
    int  DebitPreCondition(int);

    // address=[0x2f59050]
    int  DebitException(int);

};


#endif // CDEBITLEVELMANAGER_H
