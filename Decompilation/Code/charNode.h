#ifndef CHARNODE_H
#define CHARNODE_H

class charNode : public DNameNode {
public:
    // address=[0x30812c0]
     charNode(char);

    // address=[0x3088040]
    virtual char  getLastChar(void)const;

    // address=[0x308a620]
    virtual char *  getString(char *,char *)const;

    // address=[0x308cf90]
    virtual int  length(void)const;

};


#endif // CHARNODE_H
