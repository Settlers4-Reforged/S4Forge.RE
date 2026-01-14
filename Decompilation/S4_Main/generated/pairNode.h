#ifndef PAIRNODE_H
#define PAIRNODE_H

class pairNode : public DNameNode {
public:
    // address=[0x3081380]
     pairNode(class DNameNode *,class DNameNode *);

    // address=[0x30880a0]
    virtual char  getLastChar(void)const;

    // address=[0x308a6b0]
    virtual char *  getString(char *,char *)const;

    // address=[0x308cff0]
    virtual int  length(void)const;

};


#endif // PAIRNODE_H
