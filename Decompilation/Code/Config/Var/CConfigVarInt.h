#ifndef CCONFIGVARINT_H
#define CCONFIGVARINT_H

class CConfigVarInt : public CDynamicConfigVar {
public:
    // address=[0x2efa050]
    virtual float  GetFloatValue(void)const;

    // address=[0x2efa0d0]
    virtual int  GetIntValue(void)const;

    // address=[0x2efa2d0]
    virtual void  SetValue(int);

    // address=[0x2efa2f0]
    virtual void  SetValue(float);

private:
    // address=[0x2ef8730]
     CConfigVarInt(int);

    // address=[0x2ef8c50]
    virtual  ~CConfigVarInt(void);

};


#endif // CCONFIGVARINT_H
