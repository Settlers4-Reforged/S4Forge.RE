#ifndef CBBFILEEXCEPTION_H
#define CBBFILEEXCEPTION_H

class CBBFileException : public CBBException {
public:
    // address=[0x14c2e30]
    int  Cause(void)const;

    // address=[0x14c2e50]
    wchar_t const *  FileName(void)const;

    // address=[0x14dfb00]
     CBBFileException(class CBBFileException const &);

    // address=[0x2f309f0]
     CBBFileException(int,wchar_t const *);

    // address=[0x2f30a70]
    virtual  ~CBBFileException(void);

    // address=[0x2f30a90]
    virtual bool  GetErrorMessage(char *,unsigned int);

};


#endif // CBBFILEEXCEPTION_H
