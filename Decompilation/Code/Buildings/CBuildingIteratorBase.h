#ifndef CBUILDINGITERATORBASE_H
#define CBUILDINGITERATORBASE_H

class CBuildingIteratorBase {
public:
    // address=[0x1317300]
    int  BuildingId(void)const;

    // address=[0x1317320]
    int  BuildingType(void)const;

protected:
    // address=[0x1317340]
    bool  BuildingValid(int);

    // address=[0x13173a0]
    void  Init(int);

};


#endif // CBUILDINGITERATORBASE_H
