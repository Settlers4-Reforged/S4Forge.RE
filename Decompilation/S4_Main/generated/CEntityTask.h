#ifndef CENTITYTASK_H
#define CENTITYTASK_H

class CEntityTask : public CPersistence {
public:
    // address=[0x14007c0]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x14d7e80]
     CEntityTask(class CEntityTask const &);

    // address=[0x14d8620]
    virtual unsigned long  ClassID(void)const;

    // address=[0x14dfb60]
     CEntityTask(int,int,int,int,int,int,int,bool,bool,int,unsigned int,unsigned int,unsigned int);

    // address=[0x154c2d0]
     CEntityTask(std::istream &);

    // address=[0x154c440]
    virtual void  Store(std::ostream &);

    // address=[0x154ecd0]
     CEntityTask(class CEntityTask &&);

    // address=[0x1568830]
    static class CEntityTask * __cdecl Load(std::istream &);

    // address=[0x3d8bb24]
    static unsigned long m_iClassID;

};


#endif // CENTITYTASK_H
