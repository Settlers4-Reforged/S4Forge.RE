#ifndef CUNIQUE_H
#define CUNIQUE_H

#include "defines.h"

class CUnique : public CPersistence {
public:
    // address=[0x14035b0]
    static class CUnique * __cdecl GetObjectPtr(std::istream & a1);

    // address=[0x14035e0]
    static class CUnique & __cdecl GetObjectA(std::istream & a1);

    // address=[0x1403610]
    static class CUnique & __cdecl GetObjectA(unsigned long a1);

    // address=[0x1403680]
    static class CUnique * __cdecl GetObjectPtr(unsigned long a1);

    // address=[0x1403760]
    static class CUnique * __cdecl GetNextObjectPtr(unsigned long a1);

    // address=[0x14038b0]
    static class CUnique * __cdecl GetFirstObjectPtr(void);

    // address=[0x1403990]
    static void __cdecl Init(std::istream & a1);

    // address=[0x14039c0]
    static void __cdecl Exit(std::ostream & a1);

    // address=[0x14039e0]
     CUnique(std::istream & a2);

    // address=[0x1403a30]
    virtual void  Store(std::ostream & a2);

    // address=[0x1407c30]
    unsigned long  ObjectID(void)const;

private:
    // address=[0x1403a70]
    static void __cdecl _add(unsigned long a1, class CUnique * a2);

    // address=[0x1403a90]
    static void __cdecl _remove(unsigned long a1);

    // address=[0x3d89404]
    static unsigned long _NextObjID;

};


#endif // CUNIQUE_H
