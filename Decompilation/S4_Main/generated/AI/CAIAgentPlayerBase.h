#ifndef CAIAGENTPLAYERBASE_H
#define CAIAGENTPLAYERBASE_H

class CAIAgentPlayerBase : public CAIAgent {
public:
    // address=[0x1306b10]
    void  AttachPlayerAI(class CAIPlayerAI *);

    // address=[0x1307170]
    class CAIPlayerAI *  PlayerAI(void)const;

    // address=[0x1319190]
     CAIAgentPlayerBase(char const *);

    // address=[0x1319280]
    virtual  ~CAIAgentPlayerBase(void);

};


#endif // CAIAGENTPLAYERBASE_H
