#ifndef CAITASKFORCEMANAKOPTERS_H
#define CAITASKFORCEMANAKOPTERS_H

class CAITaskForceManakopters : public CAITaskForceEx {
public:
    // address=[0x132a180]
     CAITaskForceManakopters(int,int);

    // address=[0x132a2a0]
    virtual  ~CAITaskForceManakopters(void);

    // address=[0x132d290]
    virtual void  Execute(void);

    // address=[0x132d480]
    virtual bool  NewCommand(int,int,int);

};


#endif // CAITASKFORCEMANAKOPTERS_H
