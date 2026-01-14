#ifndef CSTATICCONFIGVARINT_H
#define CSTATICCONFIGVARINT_H

class CStaticConfigVarInt : public CStaticConfigVar {
public:
    // address=[0x12fc830]
     CStaticConfigVarInt(char const *,char const *,int);

    // address=[0x12fca60]
    virtual  ~CStaticConfigVarInt(void);

    // address=[0x12fcc30]
     operator int(void)const;

    // address=[0x12fd180]
    virtual float  GetFloatValue(void)const;

    // address=[0x12fd1d0]
    virtual int  GetIntValue(void)const;

    // address=[0x12fd6d0]
    virtual void  SetValue(int);

    // address=[0x12fd6f0]
    virtual void  SetValue(float);

    // address=[0x1355250]
    class CStaticConfigVarInt &  operator=(int);

};


#endif // CSTATICCONFIGVARINT_H
