#ifndef CS4ERROREXCEPTION_H
#define CS4ERROREXCEPTION_H

class CS4ErrorException : public CBBException {
public:
    // address=[0x1481190]
     CS4ErrorException(class CErrorMessageId const &);

    // address=[0x1481200]
    virtual bool  GetErrorMessage(char *,unsigned int);

    // address=[0x14813b0]
    virtual  ~CS4ErrorException(void);

};


#endif // CS4ERROREXCEPTION_H
