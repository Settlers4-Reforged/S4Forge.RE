#ifndef CAIDARKTRIBESECTORAGENT_H
#define CAIDARKTRIBESECTORAGENT_H

class CAIDarkTribeSectorAgent : public CAIAgent {
public:
    // address=[0x12fc7f0]
     CAIDarkTribeSectorAgent(char const *);

    // address=[0x12fca00]
    virtual  ~CAIDarkTribeSectorAgent(void);

    // address=[0x12fd5c0]
    class CAIDarkTribeSectorAI *  SectorAI(void)const;

    // address=[0x1301910]
    void  AttachSectorAI(class CAIDarkTribeSectorAI *);

};


#endif // CAIDARKTRIBESECTORAGENT_H
