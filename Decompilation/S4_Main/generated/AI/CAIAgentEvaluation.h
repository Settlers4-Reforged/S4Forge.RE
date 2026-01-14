#ifndef CAIAGENTEVALUATION_H
#define CAIAGENTEVALUATION_H

class CAIAgentEvaluation : public CAIAgent {
public:
    // address=[0x1303a40]
     CAIAgentEvaluation(class CAIPlayerEvaluations &);

    // address=[0x1303a80]
    virtual unsigned int  Execute(unsigned int,unsigned int);

    // address=[0x1303be0]
    virtual  ~CAIAgentEvaluation(void);

    // address=[0x1314030]
    void  Init(void);

};


#endif // CAIAGENTEVALUATION_H
