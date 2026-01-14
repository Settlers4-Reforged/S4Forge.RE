#ifndef CAIGOALCACHE_H
#define CAIGOALCACHE_H

class CAIGoalCache : public IS4ChunkObject {
public:
    // address=[0x1301470]
    class CAIGoal const &  Goal(int);

    // address=[0x13015a0]
    int  NumberOfCachedGoals(void)const;

    // address=[0x13140c0]
    void  Init(void);

    // address=[0x1314100]
    void  Insert(int,int);

    // address=[0x1314350]
    void  Delete(int);

    // address=[0x1314380]
    void  DbgPrint(char const * const);

    // address=[0x13144a0]
    void  DeleteInvalidGoals(void);

    // address=[0x1314530]
    void  DeleteInvalidGoalsIfNecessary(void);

    // address=[0x1314560]
    virtual void  Load(class IS4Chunk &);

    // address=[0x13145d0]
    virtual void  Save(class IS4Chunk &);

    // address=[0x1325b90]
     CAIGoalCache(void);

protected:
    // address=[0x1314640]
    int  Search(int)const;

    // address=[0x1314690]
    void  DeleteIdx(int);

};


#endif // CAIGOALCACHE_H
