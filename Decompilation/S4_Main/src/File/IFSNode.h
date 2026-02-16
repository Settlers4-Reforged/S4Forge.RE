#ifndef IFSNODE_H
#define IFSNODE_H

#include "defines.h"

class IFSNode {
public:
    // address=[0x135df30]
    virtual class IFSNode *  Adopt(class IFSNode * a2);

    // address=[0x135df50]
    virtual class IFSNode *  GetChild(int a2);

    // address=[0x135e0c0]
    virtual void  Orphan(class IFSNode * a2);

protected:
    // address=[0x135cc00]
     IFSNode(void);

    // address=[0x135d4e0]
    virtual  ~IFSNode(void);

};


#endif // IFSNODE_H
