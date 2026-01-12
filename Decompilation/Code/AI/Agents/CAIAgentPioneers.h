#ifndef CAIAGENTPIONEERS_H
#define CAIAGENTPIONEERS_H

class CAIAgentPioneers : public CAINormalSectorAgent {
public:
    // address=[0x1304df0]
     CAIAgentPioneers(void);

    // address=[0x1304e40]
    virtual unsigned int  Execute(unsigned int,unsigned int);

    // address=[0x13062c0]
    virtual  ~CAIAgentPioneers(void);

protected:
    // address=[0x13051a0]
    bool  FindWorkPosition(int &,int &);

    // address=[0x1305440]
    bool  CheckSquare(int,int);

};


#endif // CAIAGENTPIONEERS_H
