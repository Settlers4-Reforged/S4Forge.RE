#ifndef CQUICKSCAN_H
#define CQUICKSCAN_H

class CQuickScan {
public:
    // address=[0x1305850]
     CQuickScan(int,int,unsigned int,unsigned int);

    // address=[0x1305900]
     CQuickScan(int,unsigned int,unsigned int);

    // address=[0x13059c0]
    bool  NextPosition(int &,int &);

    // address=[0x1306470]
    int  CenterSectorId(void)const;

};


#endif // CQUICKSCAN_H
