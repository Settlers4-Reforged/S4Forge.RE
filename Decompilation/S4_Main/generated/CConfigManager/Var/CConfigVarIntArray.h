#ifndef CCONFIGVARINTARRAY_H
#define CCONFIGVARINTARRAY_H

class CConfigVarIntArray : public CDynamicConfigVar {
public:
    // address=[0x2efa070]
    virtual int *  GetIntArray(void);

    // address=[0x2efa090]
    virtual int const *  GetIntArray(void)const;

private:
    // address=[0x2eeef30]
     CConfigVarIntArray(int const *,int);

    // address=[0x2eef050]
    virtual  ~CConfigVarIntArray(void);

};


#endif // CCONFIGVARINTARRAY_H
