#ifndef CENTITYTODOLISTMGR_H
#define CENTITYTODOLISTMGR_H

#include "Defines/Job.h"
#include "Defines/Races.h"
#include "defines.h"

class CEntityToDoListMgr {
  public:
    // address=[0x154c610]
    CEntityToDoListMgr(void);

    // address=[0x154e090]
    ~CEntityToDoListMgr(void);

    // address=[0x154e220]
    class std::list<class CEntityTask, class std::allocator<class CEntityTask>> *SettlerJobList(int _iRace, int _iJob);

    // address=[0x154e2a0]
    static void __cdecl GetJobSoundInfo(int _iJobId, struct SJobSoundInfo &rJobSoundInfo);

  private:
    // address=[0x40fe5b8]
    static struct SJobSoundInfo m_vJobSoundInfo[367];

    // Type information members
  public:
    std::list<CEntityTask> *m_vSettlerJobsList[RACE_MAX][JOB_MAX];
};

// NOTE: Move maybe to sound files...
struct SJobSoundInfo {
    int m_iId;
    unsigned __int8 m_iRandom;
    char m_iFrame;
};

#endif // CENTITYTODOLISTMGR_H
