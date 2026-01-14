#ifndef COPENLISTENTRY16_H
#define COPENLISTENTRY16_H

class COpenListEntry16 {
public:
    // address=[0x15d6090]
    bool  operator<(class COpenListEntry16 const &)const;

    // address=[0x15d65a0]
    int  G(void)const;

    // address=[0x15d6640]
    int  Index(void)const;

    // address=[0x15d6740]
    void  MaxItem(void);

    // address=[0x15d6d20]
    void  Set(int,int,int);

};


#endif // COPENLISTENTRY16_H
