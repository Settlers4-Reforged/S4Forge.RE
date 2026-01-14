#ifndef CGRID_H
#define CGRID_H

class CGrid {
public:
    // address=[0x2fc5520]
     CGrid(int);

    // address=[0x2fc5580]
     ~CGrid(void);

    // address=[0x2fc55b0]
    int  getElement(int,int);

    // address=[0x2fc55f0]
    void  setElement(int,int,int);

    // address=[0x2fc5630]
    int  getElement(int);

    // address=[0x2fc5660]
    void  setElement(int,int);

    // address=[0x2fc5670]
    int  getSize(void);

};


#endif // CGRID_H
