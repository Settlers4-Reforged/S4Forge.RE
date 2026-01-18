#ifndef CANIMAL_H
#define CANIMAL_H

#include "defines.h"

class CAnimal : public IMovingEntity {
public:
    // address=[0x14d60e0]
     CAnimal(std::istream & a2);

    // address=[0x14d6260]
    virtual void  Store(std::ostream & a1);

    // address=[0x14d6350]
    virtual void  LogicUpdate(void);

    // address=[0x14d6420]
    virtual struct SGfxObjectInfo *  GetGfxInfos(void);

    // address=[0x14d64a0]
    void  AddTask(class CEntityTask & a2);

    // address=[0x14d8660]
    virtual void  Decrease(int a2);

    // address=[0x14d8890]
    virtual void  Take(int a2);

protected:
    // address=[0x14d64c0]
     CAnimal(int a2, int a3, int a4, int a5);

    // address=[0x14d65a0]
    virtual void  Delete(void);

    // address=[0x14d6690]
    virtual void  Update(void);

    // address=[0x14d6890]
    void  NewToDoList(class std::list<class CEntityTask,class std::allocator<class CEntityTask> > * a2);

    // address=[0x14d6980]
    void  NewDestination(int a2, int a3, int a4);

    // address=[0x14d6990]
    virtual void  ConvertEventIntoGoal(class CEntityEvent * a2);

    // address=[0x14d69b0]
    void  TakeWaitJob(bool a2);

    // address=[0x14d6a70]
    void  TakeEatJob(bool a2);

    // address=[0x14d6b60]
    void  TakeWalkJob(bool a2);

    // address=[0x14d6c50]
    void  TakeFleeJob(bool a2);

    // address=[0x14d6d40]
    void  TakeDieJob(void);

    // address=[0x14d6e10]
    void  TakeDeadJob(void);

    // address=[0x14d6e70]
    void  TakeWaitJobAndDoNothing(int a2);

    // address=[0x14d6ea0]
    void  TakeWalkJobAndWalkDir(int a2);

    // address=[0x14d6ed0]
    virtual void  TakeJob(bool a2);

    // address=[0x14d7040]
    void  WalkDir(int a2);

    // address=[0x14d7150]
    void  WalkDirAndRegister(int a2);

    // address=[0x14d8150]
    virtual  ~CAnimal(void);

    // Type information members
private:
    __int16 unk_64;
    BYTE[14] unk_66;
    BYTE unk_74;
    BYTE unk_75;
    BYTE unk_76;
    BYTE unk_77;
    BYTE unk_78;
    BYTE unk_79;
    BYTE unk_7a;
    BYTE unk_7b;
    BYTE unk_7c;
    BYTE unk_7d;
    BYTE unk_7e;
    BYTE unk_7f;
    int unk_80;
    DWORD unk_84;
    int unk_88;

};


#endif // CANIMAL_H
