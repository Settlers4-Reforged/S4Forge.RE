#ifndef CCOMMANDQUEUE_H
#define CCOMMANDQUEUE_H

class CCommandQueue {
public:
    // address=[0x153fec0]
    void  CheckCommand(class CEntityEvent *);

    // address=[0x153ff10]
    void  Push(class CEntityEvent *);

    // address=[0x153ff40]
    class CEntityEvent  Pop(void);

};


#endif // CCOMMANDQUEUE_H
