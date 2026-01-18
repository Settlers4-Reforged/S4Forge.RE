#ifndef CATTACKMSGLIST_H
#define CATTACKMSGLIST_H

#include "defines.h"

class CAttackMsgList {
public:
    // address=[0x140a800]
    void  SendAttackMessage(int a2, int a3);

    // address=[0x140a9c0]
     CAttackMsgList(void);

    // address=[0x140aa00]
     ~CAttackMsgList(void);

};


#endif // CATTACKMSGLIST_H
