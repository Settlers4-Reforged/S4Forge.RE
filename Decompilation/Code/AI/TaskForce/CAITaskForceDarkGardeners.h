#ifndef CAITASKFORCEDARKGARDENERS_H
#define CAITASKFORCEDARKGARDENERS_H

class CAITaskForceDarkGardeners : public CAITaskForceEx {
public:
    // address=[0x132a100]
     CAITaskForceDarkGardeners(int,int);

    // address=[0x132a280]
    virtual  ~CAITaskForceDarkGardeners(void);

    // address=[0x132ce70]
    virtual void  Execute(void);

    // address=[0x132cee0]
    virtual bool  NewCommand(int,int,int);

};


#endif // CAITASKFORCEDARKGARDENERS_H
