#ifndef CAITASKFORCEPRIESTSMAYA_H
#define CAITASKFORCEPRIESTSMAYA_H

class CAITaskForcePriestsMaya : public CAITaskForcePriests {
public:
    // address=[0x132bbf0]
    virtual int  ChooseMilitarySpell(struct SCountFightersResult const &,int);

    // address=[0x132bd00]
    virtual int  ChooseMilitarySpellDestination(int,int,int,int);

    // address=[0x132e4e0]
     CAITaskForcePriestsMaya(int,enum T_AI_TASK_FORCE_TYPE,int);

    // address=[0x132e630]
    virtual  ~CAITaskForcePriestsMaya(void);

};


#endif // CAITASKFORCEPRIESTSMAYA_H
