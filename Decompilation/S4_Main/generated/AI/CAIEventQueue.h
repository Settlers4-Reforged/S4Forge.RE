#ifndef CAIEVENTQUEUE_H
#define CAIEVENTQUEUE_H

class CAIEventQueue : public IAIEventQueue {
public:
    // address=[0x130a0d0]
     ~CAIEventQueue(void);

    // address=[0x130a240]
    void  Clear(void);

    // address=[0x130f720]
     CAIEventQueue(void);

    // address=[0x130f7a0]
    virtual bool  PeekAIEvent(class CAIEvent &,bool);

    // address=[0x130f830]
    class CAIEvent const *  PeekAIEvent(bool);

    // address=[0x130f8a0]
    virtual void  Load(class IS4Chunk &);

    // address=[0x130f9a0]
    virtual void  Save(class IS4Chunk &);

    // address=[0x1319880]
    void  PostAIEvent(int,int,int,int);

};


#endif // CAIEVENTQUEUE_H
