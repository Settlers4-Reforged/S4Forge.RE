#ifndef CSCRIPTEVENTREQUESTS_H
#define CSCRIPTEVENTREQUESTS_H

class CScriptEventRequests {
public:
    // address=[0x1439f30]
    int  Size(void)const;

    // address=[0x15febd0]
    int  FindFunction(int);

    // address=[0x15fec50]
    void  AddFunction(int);

    // address=[0x15fed50]
    void  RemoveFunction(int);

    // address=[0x15fede0]
    void  Load(class IS4Chunk &);

    // address=[0x15fee40]
    void  Save(class IS4Chunk &);

    // address=[0x1601cf0]
     CScriptEventRequests(void);

    // address=[0x1601d30]
    int  operator[](int)const;

    // address=[0x16022d0]
    void  Clear(void);

};


#endif // CSCRIPTEVENTREQUESTS_H
