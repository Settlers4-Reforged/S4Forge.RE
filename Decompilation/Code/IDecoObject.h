#ifndef IDECOOBJECT_H
#define IDECOOBJECT_H

class IDecoObject : public IAnimatedEntity {
public:
    // address=[0x151aae0]
    bool  IsStaticInstance(void)const;

    // address=[0x15414c0]
     IDecoObject(int,int,int,int,bool);

    // address=[0x1541700]
     IDecoObject(class IDecoObject const &,int,int,int);

    // address=[0x15418d0]
    virtual  ~IDecoObject(void);

    // address=[0x1541a00]
    virtual int  ConvertToDarkOrGreen(bool);

protected:
    // address=[0x1541a60]
     IDecoObject(std::istream &);

    // address=[0x1541b20]
    virtual void  Store(std::ostream &);

};


#endif // IDECOOBJECT_H
