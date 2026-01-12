#ifndef CFIXCURSOR_H
#define CFIXCURSOR_H

class CFixCursor {
public:
    // address=[0x2f62430]
     CFixCursor(void);

    // address=[0x2f624a0]
    void  SetSurfacePtr(unsigned short,class CSurface *,unsigned short);

    // address=[0x2f626a0]
    void  SetFixCursor(int,int,bool);

    // address=[0x2f62800]
    long  Show(class CSurface *);

    // address=[0x2f699a0]
    bool  IsVisible(void);

};


#endif // CFIXCURSOR_H
