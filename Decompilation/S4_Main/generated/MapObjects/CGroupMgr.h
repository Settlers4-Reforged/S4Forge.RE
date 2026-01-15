#ifndef CGROUPMGR_H
#define CGROUPMGR_H

class CGroupMgr : public IGroupMgr {
public:
    // address=[0x1550a80]
    virtual void  Clear(void);

    // address=[0x1550af0]
    virtual int  GetGroupSize(int,int)const;

    // address=[0x1550b80]
    virtual unsigned short const *  GetGroupEntityIds(int,int)const;

    // address=[0x1550c10]
    virtual bool  AttachEntity(int,int,int);

    // address=[0x1550ec0]
    virtual bool  DetachEntity(int,int,int);

    // address=[0x1551170]
    virtual void  DetachEntityFromAllGroups(int);

    // address=[0x1551270]
    virtual void  DetachAllEntitiesFromGroup(int,int);

    // address=[0x15513f0]
    virtual bool  HasSquadLeader(int,int);

    // address=[0x1551490]
    virtual void  SendGroupCommand(int,unsigned short const *,int,int,int);

    // address=[0x1551850]
    virtual void  Load(class IS4Chunk &);

    // address=[0x15519a0]
    virtual void  Save(class IS4Chunk &);

    // address=[0x1551ae0]
    void  FillGroupSideBarEx(class CInfoExchange *,bool,int);

    // address=[0x1551d50]
    void  FillMagicSideBarEx(class CInfoExchange *,bool,int);

    // address=[0x1552590]
     CGroupMgr(void);

    // Type information members
private:
    BYTE[100] groupFlags;
    struct CGroupMgr::TStaticArray100short[99] entries;

};


#endif // CGROUPMGR_H
