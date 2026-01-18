#ifndef IDECOOBJECT_H
#define IDECOOBJECT_H

#include "defines.h"

class IDecoObject : public IAnimatedEntity {
public:
    // address=[0x151aae0]
    bool  IsStaticInstance(void)const;

    // address=[0x15414c0]
     IDecoObject(int a2, int a3, int a4, int a5, bool a6);

    // address=[0x1541700]
     IDecoObject(class IDecoObject const & a2, int a3, int a4, int a5);

    // address=[0x15418d0]
    virtual  ~IDecoObject(void);

    // address=[0x1541a00]
    virtual int  ConvertToDarkOrGreen(bool a2);

protected:
    // address=[0x1541a60]
     IDecoObject(std::istream & a2);

    // address=[0x1541b20]
    virtual void  Store(std::ostream & a2);

};


#endif // IDECOOBJECT_H
