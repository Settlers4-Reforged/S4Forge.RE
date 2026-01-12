#ifndef CSTORAGEINFO_H
#define CSTORAGEINFO_H

class CStorageInfo : public CBuildingInfo {
public:
    // address=[0x1454920]
     CStorageInfo(void);

    // address=[0x1454e10]
    virtual unsigned int  Size(void)const;

};


#endif // CSTORAGEINFO_H
