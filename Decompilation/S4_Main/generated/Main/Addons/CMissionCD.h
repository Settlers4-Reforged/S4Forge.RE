#ifndef CMISSIONCD_H
#define CMISSIONCD_H

class CMissionCD : public CExtraCD {
public:
    // address=[0x1481b40]
    virtual bool  IsExtraInstalledEx(void);

    // address=[0x1481b60]
    virtual void  EnsureExtraGUI(int,bool (__cdecl*)(int,int,int));

    // address=[0x1481f80]
     CMissionCD(void);

    // address=[0x1482030]
    virtual  ~CMissionCD(void);

};


#endif // CMISSIONCD_H
