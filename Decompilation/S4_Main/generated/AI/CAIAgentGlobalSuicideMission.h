#ifndef CAIAGENTGLOBALSUICIDEMISSION_H
#define CAIAGENTGLOBALSUICIDEMISSION_H

#include "defines.h"

class CAIAgentGlobalSuicideMission : public CAIAgentPlayerBase {
public:
    // address=[0x1306b70]
    virtual unsigned int  Execute(unsigned int,unsigned int);

    // address=[0x1306e40]
    virtual void  Load(class IS4Chunk & a2);

    // address=[0x1306ea0]
    virtual void  Save(class IS4Chunk & a2);

    // address=[0x1319160]
     CAIAgentGlobalSuicideMission(char const *);

    // address=[0x1319260]
    virtual  ~CAIAgentGlobalSuicideMission(void);

protected:
    // address=[0x1306f00]
    static int __cdecl FindNearestBuildingInSector(int a1, int a2, int a3, int a4);

};


#endif // CAIAGENTGLOBALSUICIDEMISSION_H
