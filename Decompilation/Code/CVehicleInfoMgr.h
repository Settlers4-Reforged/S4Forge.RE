#ifndef CVEHICLEINFOMGR_H
#define CVEHICLEINFOMGR_H

class CVehicleInfoMgr : public IVehicleInfoMgr {
public:
    // address=[0x15aae80]
    virtual void  InitializeVehicleProperties(bool,bool);

    // address=[0x15ac350]
     CVehicleInfoMgr(void);

protected:
    // address=[0x15aafc0]
    void  ReadXMLFile(void);

};


#endif // CVEHICLEINFOMGR_H
