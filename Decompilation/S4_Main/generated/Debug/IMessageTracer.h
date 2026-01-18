#ifndef IMESSAGETRACER_H
#define IMESSAGETRACER_H

#include "defines.h"

class IMessageTracer {
public:
    // address=[0x1301740]
    void  PushFormatedInts(char const * a2, int a3);

    // address=[0x1301780]
    void  PushFormatedInts(char const * a2, int a3, int a4);

    // address=[0x13017d0]
    void  PushStaticText(char const * a2);

    // address=[0x1311dc0]
    void  PushFormatedInts(char const * a2, int a3, int a4, int a5);

    // address=[0x1311e20]
    void  PushFormatedInts(char const * a2, int a3, int a4, int a5, int a6);

    // address=[0x1311e80]
    void  PushFormatedInts(char const * a2, int a3, int a4, int a5, int a6, int a7);

    // address=[0x1496d60]
    void  Init(void);

    // address=[0x1496da0]
    void  Done(void);

    // address=[0x1496dd0]
    void  PrintMessages(unsigned int a2, unsigned int a3);

    // address=[0x14970f0]
     IMessageTracer(void);

    // address=[0x1558d30]
    bool  RemoveCurrentMsgIfEqual(char const * a2, int a3);

protected:
    // address=[0x1301410]
    struct STraceMsg *  IMessageTracer::GetNextTraceMsg(void);

};


#endif // IMESSAGETRACER_H
