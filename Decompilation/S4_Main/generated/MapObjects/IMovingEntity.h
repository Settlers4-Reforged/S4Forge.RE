#ifndef IMOVINGENTITY_H
#define IMOVINGENTITY_H

class IMovingEntity : public IAnimatedEntity {
public:
    // address=[0x130eb80]
    class CEntityTask const &  GetActualTask(void)const;

    // address=[0x130f500]
    class CWalking *  Walking(void);

    // address=[0x1351ad0]
    int  Direction(void)const;

    // address=[0x1351af0]
    int  Distance(void)const;

    // address=[0x1460610]
    int  GetJobPart(void)const;

    // address=[0x1470a80]
    bool  IsFree(int);

    // address=[0x14d86e0]
    virtual bool  IsUnEmployed(void)const;

    // address=[0x14e2fd0]
    void  IncToDoListIter(void);

    // address=[0x150b590]
    void  SetDisplacementCosts(int);

    // address=[0x1513b10]
    void  SetDirection(int);

    // address=[0x15590a0]
     IMovingEntity(int);

    // address=[0x1559130]
    virtual  ~IMovingEntity(void);

    // address=[0x1559170]
    void  WalkToXY(int,int);

    // address=[0x15591b0]
    virtual void  NewToDoList(class std::list<class CEntityTask,class std::allocator<class CEntityTask> > *,int);

    // address=[0x1559260]
    void  ResetToDoList(void);

    // address=[0x1559340]
    void  SetToDoList(class std::list<class CEntityTask,class std::allocator<class CEntityTask> > *);

    // address=[0x1559400]
    bool  IsNotOccupied(int);

    // address=[0x1559430]
    bool  IsNotBlocked(int);

    // address=[0x1563870]
    bool  IsEndIter(void);

    // address=[0x1563980]
    void  SetDistance(int);

    // address=[0x1568790]
    class std::_List_iterator<class std::_List_val<struct std::_List_simple_types<class CEntityTask> > > const  GetActualIter(void)const;

    // address=[0x15d6230]
    int  DisplacementCosts(void)const;

protected:
    // address=[0x14d8840]
    void  SetPositionAndDir(int,int);

    // address=[0x1559460]
     IMovingEntity(std::istream &);

    // address=[0x15595e0]
    virtual void  Store(std::ostream &);

    // address=[0x15596c0]
    void  InitDistance(void);

    // address=[0x15596e0]
    void  DecDistance(unsigned int);

};


#endif // IMOVINGENTITY_H
