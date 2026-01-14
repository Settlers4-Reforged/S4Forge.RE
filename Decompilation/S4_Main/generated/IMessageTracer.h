#ifndef IMESSAGETRACER_H
#define IMESSAGETRACER_H

class IMessageTracer {
public:
    // address=[0x1301740]
    void  PushFormatedInts(char const *,int);

    // address=[0x1301780]
    void  PushFormatedInts(char const *,int,int);

    // address=[0x13017d0]
    void  PushStaticText(char const *);

    // address=[0x1311dc0]
    void  PushFormatedInts(char const *,int,int,int);

    // address=[0x1311e20]
    void  PushFormatedInts(char const *,int,int,int,int);

    // address=[0x1311e80]
    void  PushFormatedInts(char const *,int,int,int,int,int);

    // address=[0x1496d60]
    void  Init(void);

    // address=[0x1496da0]
    void  Done(void);

    // address=[0x1496dd0]
    void  PrintMessages(unsigned int,unsigned int);

    // address=[0x14970f0]
     IMessageTracer(void);

    // address=[0x1558d30]
    bool  RemoveCurrentMsgIfEqual(char const *,int);

protected:
    // address=[0x1301410]
    struct STraceMsg *  IMessageTracer::GetNextTraceMsg(void);

};


#endif // IMESSAGETRACER_H
