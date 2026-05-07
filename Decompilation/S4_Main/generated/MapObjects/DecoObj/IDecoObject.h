#ifndef IDECOOBJECT_H
#define IDECOOBJECT_H

#include "defines.h"

class IDecoObject : public IAnimatedEntity {
public:
    // address=[0x151aae0]
    bool  IsStaticInstance(void)const;

    // address=[0x15414c0]
     IDecoObject(int _iX, int _iY, int _iDecoObjectType, int _iId, bool a6);

    // address=[0x1541700]
     IDecoObject(class IDecoObject const & _rStaticDecoObject, int _iId, int _iX, int _iY);

    // address=[0x15418d0]
    virtual  ~IDecoObject(void);

    // address=[0x1541a00]
    virtual int  ConvertToDarkOrGreen(bool a2);

protected:
    // address=[0x1541a60]
     IDecoObject(std::istream & a2);

    // address=[0x1541b20]
    virtual void  Store(std::ostream & a2);

    // Type information members
public:
    bool m_bStaticInstance;

};


#endif // IDECOOBJECT_H
