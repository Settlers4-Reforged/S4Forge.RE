#ifndef CCONFIGVARSTRING_H
#define CCONFIGVARSTRING_H

class CConfigVarString : public CDynamicConfigVar {
public:
    // address=[0x2efa0f0]
    virtual std::string  GetStringValue(void)const;

    // address=[0x2efa310]
    virtual void  SetValue(std::string const &);

    // address=[0x2efa340]
    virtual void  SetValue(char const *);

private:
    // address=[0x2ef8770]
     CConfigVarString(std::string const &);

    // address=[0x2ef8c80]
    virtual  ~CConfigVarString(void);

};


#endif // CCONFIGVARSTRING_H
