#ifndef CAITASKFORCEPRIESTSTROJAN_H
#define CAITASKFORCEPRIESTSTROJAN_H

class CAITaskForcePriestsTrojan : public CAITaskForcePriests {
public:
    // address=[0x132be00]
    virtual int  ChooseMilitarySpell(struct SCountFightersResult const &,int);

    // address=[0x132bf10]
    virtual int  ChooseMilitarySpellDestination(int,int,int,int);

    // address=[0x132e560]
     CAITaskForcePriestsTrojan(int,enum T_AI_TASK_FORCE_TYPE,int);

    // address=[0x132e670]
    virtual  ~CAITaskForcePriestsTrojan(void);

};


#endif // CAITASKFORCEPRIESTSTROJAN_H
