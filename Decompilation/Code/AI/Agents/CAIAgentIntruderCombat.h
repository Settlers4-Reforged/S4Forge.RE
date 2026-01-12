#ifndef CAIAGENTINTRUDERCOMBAT_H
#define CAIAGENTINTRUDERCOMBAT_H

class CAIAgentIntruderCombat : public CAINormalSectorAgent {
public:
    // address=[0x1304730]
     CAIAgentIntruderCombat(void);

    // address=[0x1304760]
    virtual unsigned int  Execute(unsigned int,unsigned int);

    // address=[0x13062a0]
    virtual  ~CAIAgentIntruderCombat(void);

protected:
    // address=[0x1304940]
    void  MoveHunterHome(int);

    // address=[0x13049f0]
    int  HuntNextIntruderType(void);

    // address=[0x1304a40]
    int  HuntIntruders(int);

};


#endif // CAIAGENTINTRUDERCOMBAT_H
