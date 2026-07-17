#ifndef CENTITYTODOLISTMGR_H
#define CENTITYTODOLISTMGR_H

#include "defines.h"

class CEntityToDoListMgr {
public:
    // address=[0x154c610]
     CEntityToDoListMgr(void);

    // address=[0x154e090]
     ~CEntityToDoListMgr(void);

    // address=[0x154e220]
    class std::list<class CEntityTask,class std::allocator<class CEntityTask> > *  SettlerJobList(int _iRace, int _iJob);

    // address=[0x154e2a0]
    static void __cdecl GetJobSoundInfo(int a1, struct SJobSoundInfo & a2);

private:
    // address=[0x40fe5b8]
    static struct SJobSoundInfo * m_vJobSoundInfo;

    // Type information members
public:
    std::list *[4][267] m_vSettlerJobsList;

};


#endif // CENTITYTODOLISTMGR_H
