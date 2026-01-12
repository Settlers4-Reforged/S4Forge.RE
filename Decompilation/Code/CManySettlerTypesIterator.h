#ifndef CMANYSETTLERTYPESITERATOR_H
#define CMANYSETTLERTYPESITERATOR_H

class CManySettlerTypesIterator {
public:
    // address=[0x13151c0]
    void  Init(int,int,int);

    // address=[0x1315200]
    int  FirstSettler(void);

    // address=[0x1315280]
    int  NextSettler(void);

    // address=[0x1315320]
    int  NextSettlerIfCurrentIsNotValid(void);

    // address=[0x1317210]
     CManySettlerTypesIterator(void);

};


#endif // CMANYSETTLERTYPESITERATOR_H
