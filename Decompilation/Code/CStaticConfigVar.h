#ifndef CSTATICCONFIGVAR_H
#define CSTATICCONFIGVAR_H

class CStaticConfigVar : public CConfigVar {
public:
    // address=[0x12fca40]
    virtual  ~CStaticConfigVar(void);

protected:
    // address=[0x2eeeea0]
     CStaticConfigVar(char const *,char const *,enum T_CFGVAR_TYPE,int);

};


#endif // CSTATICCONFIGVAR_H
