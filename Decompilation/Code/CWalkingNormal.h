#ifndef CWALKINGNORMAL_H
#define CWALKINGNORMAL_H

class CWalkingNormal : public CWalkingBase {
public:
    // address=[0x15f9070]
     CWalkingNormal(int);

    // address=[0x15faf90]
    virtual  ~CWalkingNormal(void);

    // address=[0x15fb260]
    virtual enum T_WALKING_TYPE const  GetWalkingType(void);

};


#endif // CWALKINGNORMAL_H
