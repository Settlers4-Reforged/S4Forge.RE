#ifndef CBBEXCEPTION_H
#define CBBEXCEPTION_H

class CBBException {
public:
    // address=[0x1313e80]
     CBBException(class CBBException const &);

    // address=[0x1313ea0]
     CBBException(void);

    // address=[0x2f30950]
    virtual  ~CBBException(void);

    // address=[0x2f30970]
    virtual bool  GetErrorMessage(char *,unsigned int);

};


#endif // CBBEXCEPTION_H
