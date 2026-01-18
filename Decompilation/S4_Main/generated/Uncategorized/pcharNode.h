#ifndef PCHARNODE_H
#define PCHARNODE_H

#include "defines.h"

class pcharNode : public DNameNode {
public:
    // address=[0x30813d0]
     pcharNode(char const * a2, int a3);

    // address=[0x3088120]
    virtual char  getLastChar(void)const;

    // address=[0x308a750]
    virtual char *  getString(char * a2, char * a3)const;

    // address=[0x308d080]
    virtual int  length(void)const;

};


#endif // PCHARNODE_H
