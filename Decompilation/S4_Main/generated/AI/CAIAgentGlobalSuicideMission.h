#ifndef CAIAGENTGLOBALSUICIDEMISSION_H
#define CAIAGENTGLOBALSUICIDEMISSION_H

class CAIAgentGlobalSuicideMission : public CAIAgentPlayerBase {
public:
    // address=[0x1306b70]
    virtual unsigned int  Execute(unsigned int,unsigned int);

    // address=[0x1306e40]
    virtual void  Load(class IS4Chunk &);

    // address=[0x1306ea0]
    virtual void  Save(class IS4Chunk &);

    // address=[0x1319160]
     CAIAgentGlobalSuicideMission(char const *);

    // address=[0x1319260]
    virtual  ~CAIAgentGlobalSuicideMission(void);

protected:
    // address=[0x1306f00]
    static int __cdecl FindNearestBuildingInSector(int,int,int,int);

};


#endif // CAIAGENTGLOBALSUICIDEMISSION_H
