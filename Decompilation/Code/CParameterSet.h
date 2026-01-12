#ifndef CPARAMETERSET_H
#define CPARAMETERSET_H

class CParameterSet : public CDynListEntry {
public:
    // address=[0x2f3f500]
     CParameterSet(void);

    // address=[0x2f3f5a0]
    virtual  ~CParameterSet(void);

    // address=[0x2f3f5f0]
    int  size(void);

    // address=[0x2f3f610]
    class CParam *  elementAt(int);

    // address=[0x2f3f630]
    void  NewParameterSet(class CParam *);

    // address=[0x2f3f650]
    void  Ausgabe(void);

};


#endif // CPARAMETERSET_H
