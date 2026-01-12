#ifndef CENTITYEVENT_H
#define CENTITYEVENT_H

class CEntityEvent : public CPersistence {
public:
    // address=[0x130e350]
     CEntityEvent(unsigned char,int,int,int,int);

    // address=[0x130e430]
     ~CEntityEvent(void);

    // address=[0x130e9d0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x1400720]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x14e44e0]
     CEntityEvent(class CEntityEvent const &);

    // address=[0x14e46f0]
    class CEntityEvent &  operator=(class CEntityEvent const &);

    // address=[0x14e4b20]
    static class CEntityEvent * __cdecl Load(std::istream &);

    // address=[0x154c110]
     CEntityEvent(std::istream &);

    // address=[0x154c1e0]
    virtual void  Store(std::ostream &);

    // address=[0x3d8bb20]
    static unsigned long m_iClassID;

};


#endif // CENTITYEVENT_H
