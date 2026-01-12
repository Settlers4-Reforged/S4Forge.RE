#ifndef CENTITYTODOLISTMGR_H
#define CENTITYTODOLISTMGR_H

class CEntityToDoListMgr {
public:
    // address=[0x154c610]
     CEntityToDoListMgr(void);

    // address=[0x154e090]
     ~CEntityToDoListMgr(void);

    // address=[0x154e220]
    class std::list<class CEntityTask,class std::allocator<class CEntityTask> > *  SettlerJobList(int,int);

    // address=[0x154e2a0]
    static void __cdecl GetJobSoundInfo(int,struct SJobSoundInfo &);

private:
    // address=[0x40fe5b8]
    static struct SJobSoundInfo * m_vJobSoundInfo;

};


#endif // CENTITYTODOLISTMGR_H
