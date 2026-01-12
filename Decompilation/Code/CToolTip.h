#ifndef CTOOLTIP_H
#define CTOOLTIP_H

class CToolTip {
public:
    // address=[0x2f9fd80]
    int  GetCurrentLengthOfTooltip(void);

    // address=[0x2f9fda0]
    char *  GetTooltipStringPtr(void);

    // address=[0x2f9fdc0]
    bool  IsLocked(void);

    // address=[0x2f9fde0]
    bool  IsOpen(void);

    // address=[0x2f9fe00]
    void  Lock(void);

    // address=[0x2f9fe50]
    void  SetSourceDialogSurfaceID(int);

    // address=[0x2f9fe70]
    void  Unlock(void);

    // address=[0x2fa0fa0]
    int  GetSourceDialogSurfaceID(void);

    // address=[0x2fa2f70]
    void  SetEnableStatus(bool);

    // address=[0x2fa3070]
     CToolTip(void);

    // address=[0x2fa30d0]
    void  SetTooltipText(char const *);

    // address=[0x2fa3130]
    bool  OpenTooltip(int,int);

    // address=[0x2fa3560]
    bool  CloseTooltip(void);

    // address=[0x2fa3fb0]
     ~CToolTip(void);

    // address=[0x2fa4020]
    int  GetMaxLengthOfTooltip(void);

};


#endif // CTOOLTIP_H
