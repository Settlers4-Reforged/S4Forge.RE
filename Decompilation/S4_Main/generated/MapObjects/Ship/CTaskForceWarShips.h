#ifndef CTASKFORCEWARSHIPS_H
#define CTASKFORCEWARSHIPS_H

class CTaskForceWarShips : public CAITaskForceEx {
public:
    // address=[0x132a240]
     CTaskForceWarShips(int,enum T_AI_TASK_FORCE_TYPE,int);

    // address=[0x132a300]
    virtual  ~CTaskForceWarShips(void);

    // address=[0x132ce30]
    virtual bool  IsAddEntityOk(int);

};


#endif // CTASKFORCEWARSHIPS_H
