#ifndef IMESSAGETRACER_H
#define IMESSAGETRACER_H

#include "defines.h"

class IMessageTracer {
public:
    // address=[0x1301740]
    void  PushFormatedInts(char const * message, int arg1);

    // address=[0x1301780]
    void  PushFormatedInts(char const * message, int arg1, int arg2);

    // address=[0x13017d0]
    void  PushStaticText(char const * message);

    // address=[0x1311dc0]
    void  PushFormatedInts(char const * message, int arg1, int arg2, int arg3);

    // address=[0x1311e20]
    void  PushFormatedInts(char const * message, int arg1, int arg2, int arg3, int arg4);

    // address=[0x1311e80]
    void  PushFormatedInts(char const * message, int arg, int arg2, int arg3, int arg4, int arg5);

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

    // Type information members
public:
    int m_iCurrentMessage;
    int m_iMaxMessage;
    IMessageTracer::STraceMsg[16384] m_aMessages;

};


#endif // IMESSAGETRACER_H
