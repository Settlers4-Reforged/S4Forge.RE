#ifndef CAIDARKTRIBESECTORAI_H
#define CAIDARKTRIBESECTORAI_H

class CAIDarkTribeSectorAI : public CAISectorAI {
public:
    // address=[0x1303820]
    class IAIDarkTribeEcoAI *  EconomyAI(void)const;

    // address=[0x1322250]
    virtual  ~CAIDarkTribeSectorAI(void);

    // address=[0x1322390]
    virtual void  Load(class IS4Chunk &);

    // address=[0x13224d0]
    virtual void  Save(class IS4Chunk &);

    // address=[0x1322610]
    virtual void  PostAIEvent(int,int,int,int);

    // address=[0x1322660]
    virtual void  Execute(void);

    // address=[0x1322690]
    bool  FindMushroomFarm(int &,int &,int,int);

    // address=[0x1323210]
    virtual void  DbgPrint(void);

    // address=[0x1323240]
    virtual bool  IsNormalPlayerSector(void)const;

protected:
    // address=[0x1321d50]
     CAIDarkTribeSectorAI(class CAIPlayerAI &,int);

    // address=[0x13228d0]
    virtual bool  ProcessEvent(class CAIEvent const *);

    // address=[0x1322a00]
    void  AttachAgentEx(class CAIDarkTribeSectorAgent &,unsigned int,unsigned int,unsigned int);

};


#endif // CAIDARKTRIBESECTORAI_H
