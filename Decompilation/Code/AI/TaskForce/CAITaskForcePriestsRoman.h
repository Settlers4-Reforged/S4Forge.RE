#ifndef CAITASKFORCEPRIESTSROMAN_H
#define CAITASKFORCEPRIESTSROMAN_H

class CAITaskForcePriestsRoman : public CAITaskForcePriests {
public:
    // address=[0x132b8b0]
    virtual int  ChooseMilitarySpell(struct SCountFightersResult const &,int);

    // address=[0x132b980]
    virtual int  ChooseMilitarySpellDestination(int,int,int,int);

    // address=[0x132e520]
     CAITaskForcePriestsRoman(int,enum T_AI_TASK_FORCE_TYPE,int);

    // address=[0x132e650]
    virtual  ~CAITaskForcePriestsRoman(void);

};


#endif // CAITASKFORCEPRIESTSROMAN_H
