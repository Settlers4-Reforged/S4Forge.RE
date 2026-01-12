#ifndef CAIAGENTGEOLOGISTS_H
#define CAIAGENTGEOLOGISTS_H

class CAIAgentGeologists : public CAINormalSectorAgent {
public:
    // address=[0x1304250]
    virtual unsigned int  Execute(unsigned int,unsigned int);

    // address=[0x1325aa0]
     CAIAgentGeologists(void);

    // address=[0x1325c70]
    virtual  ~CAIAgentGeologists(void);

};


#endif // CAIAGENTGEOLOGISTS_H
