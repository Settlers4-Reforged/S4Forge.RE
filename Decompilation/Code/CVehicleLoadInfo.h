#ifndef CVEHICLELOADINFO_H
#define CVEHICLELOADINFO_H

class CVehicleLoadInfo : public CInfoExchange {
public:
    // address=[0x14549f0]
     CVehicleLoadInfo(void);

    // address=[0x1454e90]
    virtual unsigned int  Size(void)const;

};


#endif // CVEHICLELOADINFO_H
