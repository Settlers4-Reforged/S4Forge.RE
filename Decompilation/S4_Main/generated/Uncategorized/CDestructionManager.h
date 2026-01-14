#ifndef CDESTRUCTIONMANAGER_H
#define CDESTRUCTIONMANAGER_H

class CDestructionManager {
public:
    // address=[0x1426a10]
    static class CDestructionManager & __cdecl Instance(void);

    // address=[0x1426a30]
    void  RegisterDestructor(class CDestructor *);

    // address=[0x2f03a10]
    void  DestroyObjects(void);

private:
    // address=[0x2f03a90]
    static class std::auto_ptr<class CDestructionManager> & __cdecl GetInstance(void);

    // address=[0x2f03b70]
     ~CDestructionManager(void);

    // address=[0x2f051e0]
     CDestructionManager(void);

};


#endif // CDESTRUCTIONMANAGER_H
