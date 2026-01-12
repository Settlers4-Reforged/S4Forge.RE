#ifndef CAIDARKTRIBEPLAYERAI_H
#define CAIDARKTRIBEPLAYERAI_H

class CAIDarkTribePlayerAI : public CAIPlayerAI {
protected:
    // address=[0x1319d30]
     CAIDarkTribePlayerAI(int);

    // address=[0x1319d70]
    virtual void  Execute(void);

    // address=[0x131a000]
    virtual void  Load(class IS4Chunk &);

    // address=[0x131a120]
    virtual void  Save(class IS4Chunk &);

    // address=[0x131a210]
    virtual void  Init(void);

};


#endif // CAIDARKTRIBEPLAYERAI_H
