#ifndef PDNAMENODE_H
#define PDNAMENODE_H

#include "defines.h"

class pDNameNode : public DNameNode {
public:
    // address=[0x3081300]
     pDNameNode(class DName * a2);

    // address=[0x3088060]
    virtual char  getLastChar(void)const;

    // address=[0x308a660]
    virtual char *  getString(char * a2, char * a3)const;

    // address=[0x308cfb0]
    virtual int  length(void)const;

};


#endif // PDNAMENODE_H
