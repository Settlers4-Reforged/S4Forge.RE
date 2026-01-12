#ifndef PCHARNODE_H
#define PCHARNODE_H

class pcharNode : public DNameNode {
public:
    // address=[0x30813d0]
     pcharNode(char const *,int);

    // address=[0x3088120]
    virtual char  getLastChar(void)const;

    // address=[0x308a750]
    virtual char *  getString(char *,char *)const;

    // address=[0x308d080]
    virtual int  length(void)const;

};


#endif // PCHARNODE_H
