#ifndef CMIRRORBASICGRID_H
#define CMIRRORBASICGRID_H

class CMirrorBasicGrid : public CBasicGrid {
public:
    // address=[0x2fc5fb0]
     CMirrorBasicGrid(int,int);

    // address=[0x2fc5fe0]
    virtual void  initGrid(void);

protected:
    // address=[0x2fc6600]
    void  getMirrorBasisPoint(int &,int &,bool);

};


#endif // CMIRRORBASICGRID_H
