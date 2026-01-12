#ifndef CBBOBJECT_H
#define CBBOBJECT_H

class CBBObject {
public:
    // address=[0x2f337e0]
     CBBObject(char const *,bool);

    // address=[0x2f33860]
     CBBObject(class CBBObject const &);

    // address=[0x2f33900]
    virtual  ~CBBObject(void);

};


#endif // CBBOBJECT_H
