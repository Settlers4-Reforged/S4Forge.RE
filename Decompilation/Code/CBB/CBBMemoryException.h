#ifndef CBBMEMORYEXCEPTION_H
#define CBBMEMORYEXCEPTION_H

class CBBMemoryException : public CBBException {
public:
    // address=[0x2f30980]
     CBBMemoryException(void);

    // address=[0x2f309a0]
    virtual  ~CBBMemoryException(void);

    // address=[0x2f309c0]
    virtual bool  GetErrorMessage(char *,unsigned int);

    // address=[0x2f337b0]
     CBBMemoryException(class CBBMemoryException const &);

};


#endif // CBBMEMORYEXCEPTION_H
