#ifndef CAIAGENTTHIEVES_H
#define CAIAGENTTHIEVES_H

class CAIAgentThieves : public CAINormalSectorAgent {
public:
    // address=[0x1305810]
    virtual unsigned int  Execute(unsigned int,unsigned int);

    // address=[0x1325b30]
     CAIAgentThieves(void);

    // address=[0x1325cd0]
    virtual  ~CAIAgentThieves(void);

};


#endif // CAIAGENTTHIEVES_H
