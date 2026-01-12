#ifndef DNAMESTATUSNODE_H
#define DNAMESTATUSNODE_H

class DNameStatusNode : public DNameNode {
public:
    // address=[0x3088000]
    virtual char  getLastChar(void)const;

    // address=[0x308a5e0]
    virtual char *  getString(char *,char *)const;

    // address=[0x308cf70]
    virtual int  length(void)const;

    // address=[0x308d0a0]
    static class DNameStatusNode * __cdecl make(enum DNameStatus);

private:
    // address=[0x3081170]
     DNameStatusNode(enum DNameStatus);

};


#endif // DNAMESTATUSNODE_H
