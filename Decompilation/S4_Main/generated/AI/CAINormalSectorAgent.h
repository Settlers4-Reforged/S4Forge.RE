#ifndef CAINORMALSECTORAGENT_H
#define CAINORMALSECTORAGENT_H

#include "defines.h"

class CAINormalSectorAgent : public CAIAgent {
public:
    // address=[0x1300fe0]
     CAINormalSectorAgent(char const *);

    // address=[0x1301040]
    virtual  ~CAINormalSectorAgent(void);

    // address=[0x1301810]
    class CAINormalSectorAI *  SectorAI(void)const;

    // address=[0x1303c90]
    void  AttachSectorAI(class CAINormalSectorAI * a2);

};


#endif // CAINORMALSECTORAGENT_H
