#ifndef CAICONFIGINT_H
#define CAICONFIGINT_H

class CAIConfigInt : public CStaticConfigVarInt {
public:
    // address=[0x12fc7b0]
     CAIConfigInt(char const *,int);

    // address=[0x12fc9e0]
    virtual  ~CAIConfigInt(void);

};


#endif // CAICONFIGINT_H
