#ifndef CAIAGENTDARKTRIBERECRUITMENT_H
#define CAIAGENTDARKTRIBERECRUITMENT_H

#include "defines.h"

class CAIAgentDarkTribeRecruitment : public CAIDarkTribeSectorAgent {
public:
    // address=[0x1301f00]
    virtual unsigned int  Execute(unsigned int a2, unsigned int a3);

    // address=[0x1322e40]
     CAIAgentDarkTribeRecruitment(void);

    // address=[0x1322f60]
    virtual  ~CAIAgentDarkTribeRecruitment(void);

};


#endif // CAIAGENTDARKTRIBERECRUITMENT_H
