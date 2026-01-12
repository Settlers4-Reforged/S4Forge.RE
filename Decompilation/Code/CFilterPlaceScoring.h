#ifndef CFILTERPLACESCORING_H
#define CFILTERPLACESCORING_H

class CFilterPlaceScoring : public IFilterEntry {
public:
    // address=[0x2f39700]
     CFilterPlaceScoring(void);

    // address=[0x2f39720]
     CFilterPlaceScoring(class CSchedule *,struct SBUILDINFODATA *,int,int,int);

    // address=[0x2f39800]
    virtual  ~CFilterPlaceScoring(void);

    // address=[0x2f39820]
    virtual float  GetFilterValue(void);

};


#endif // CFILTERPLACESCORING_H
