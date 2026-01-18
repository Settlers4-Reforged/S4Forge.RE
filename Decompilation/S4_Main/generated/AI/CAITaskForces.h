#ifndef CAITASKFORCES_H
#define CAITASKFORCES_H

#include "defines.h"

class CAITaskForces {
public:
    // address=[0x13039d0]
    static enum T_AI_TASK_FORCE_CLASS __cdecl TaskForceClass(enum T_AI_TASK_FORCE_TYPE a1);

    // address=[0x1328e40]
    static void __cdecl Init(void);

    // address=[0x1328e70]
    static void __cdecl Done(void);

    // address=[0x1328ed0]
    static void __cdecl Execute(void);

    // address=[0x1328fd0]
    static void __cdecl RemoveEntityFromTaskForce(int a1);

    // address=[0x1329020]
    static class CAITaskForce * __cdecl CreateTaskForce(int a1, enum T_AI_TASK_FORCE_TYPE a2);

    // address=[0x13293f0]
    void  DbgPrint(void);

protected:
    // address=[0x1329460]
    static int __cdecl TotalNumberOfTaskForces(void);

    // address=[0x1329470]
    static int __cdecl NumberOfTaskForces(int a1, int a2);

    // address=[0x1329490]
    static void __cdecl AddTaskForce(class CAITaskForce * a1);

    // address=[0x1329590]
    static void __cdecl RemoveTaskForce(class CAITaskForce * a1);

};


#endif // CAITASKFORCES_H
