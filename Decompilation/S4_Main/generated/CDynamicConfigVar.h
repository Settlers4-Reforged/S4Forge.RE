#ifndef CDYNAMICCONFIGVAR_H
#define CDYNAMICCONFIGVAR_H

class CDynamicConfigVar : public CConfigVar {
public:
    // address=[0x2ef8cb0]
    virtual  ~CDynamicConfigVar(void);

protected:
    // address=[0x2ef8800]
     CDynamicConfigVar(enum T_CFGVAR_TYPE,int);

};


#endif // CDYNAMICCONFIGVAR_H
