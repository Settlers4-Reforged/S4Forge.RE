#ifndef CAITASKFORCEPRIESTSVIKING_H
#define CAITASKFORCEPRIESTSVIKING_H

class CAITaskForcePriestsViking : public CAITaskForcePriests {
public:
    // address=[0x132ba20]
    virtual int  ChooseMilitarySpell(struct SCountFightersResult const &,int);

    // address=[0x132bb20]
    virtual int  ChooseMilitarySpellDestination(int,int,int,int);

    // address=[0x132e5a0]
     CAITaskForcePriestsViking(int,enum T_AI_TASK_FORCE_TYPE,int);

    // address=[0x132e690]
    virtual  ~CAITaskForcePriestsViking(void);

};


#endif // CAITASKFORCEPRIESTSVIKING_H
