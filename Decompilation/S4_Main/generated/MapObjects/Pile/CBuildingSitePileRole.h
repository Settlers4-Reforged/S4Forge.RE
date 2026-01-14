#ifndef CBUILDINGSITEPILEROLE_H
#define CBUILDINGSITEPILEROLE_H

class CBuildingSitePileRole : public IPileRole {
public:
    // address=[0x13ffdc0]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x155b3b0]
    virtual void  Init(class CPile *);

    // address=[0x155b3e0]
    virtual void  Increase(class CPile *,int);

    // address=[0x155b4f0]
    virtual void  SubjectStopped(class CPile *);

    // address=[0x155b550]
    virtual void  SubjectStarted(class CPile *);

    // address=[0x155b5b0]
     CBuildingSitePileRole(std::istream &);

    // address=[0x155b660]
    virtual void  Store(std::ostream &);

    // address=[0x155b750]
    virtual  ~CBuildingSitePileRole(void);

    // address=[0x155b7b0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x1560380]
    static class CBuildingSitePileRole * __cdecl Load(std::istream &);

    // address=[0x3d8bbb8]
    static unsigned long m_iClassID;

private:
    // address=[0x1560140]
     CBuildingSitePileRole(void);

};


#endif // CBUILDINGSITEPILEROLE_H
