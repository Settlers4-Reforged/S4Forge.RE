#ifndef CADDON_H
#define CADDON_H

class CAddOn : public CExtraCD {
public:
    // address=[0x1481ba0]
    virtual bool  IsExtraInstalledEx(void);

    // address=[0x1481bc0]
    virtual void  EnsureExtraGUI(int,bool (__cdecl*)(int,int,int));

    // address=[0x1481ef0]
     CAddOn(void);

    // address=[0x1481fd0]
    virtual  ~CAddOn(void);

};


#endif // CADDON_H
