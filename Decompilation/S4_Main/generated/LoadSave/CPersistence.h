#ifndef CPERSISTENCE_H
#define CPERSISTENCE_H

class CPersistence {
public:
    // address=[0x130e9f0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x13ed840]
    virtual void  Store(std::ostream &);

    // address=[0x13ed870]
    static void __cdecl RegisterClassWhithId(unsigned long &,class CPersistence * (__cdecl*)(std::istream &),unsigned long);

    // address=[0x13ed8b0]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x13ed9d0]
    static class CPersistence * __cdecl New_HACK_VERSION(std::istream &);

    // address=[0x14d7f80]
     CPersistence(class CPersistence const &);

    // address=[0x14e4760]
    class CPersistence &  operator=(class CPersistence const &);

    // address=[0x154edd0]
     CPersistence(class CPersistence &&);

protected:
    // address=[0x130e3c0]
     CPersistence(void);

    // address=[0x13eda90]
    static unsigned char __cdecl LOAD_UINT8(std::istream &);

    // address=[0x13edae0]
    static unsigned short __cdecl LOAD_UINT16(std::istream &);

    // address=[0x13edb30]
    static unsigned int __cdecl LOAD_UINT32(std::istream &);

    // address=[0x13edb80]
    static signed char __cdecl LOAD_INT8(std::istream &);

    // address=[0x13edbd0]
    static short __cdecl LOAD_INT16(std::istream &);

    // address=[0x13edc20]
    static int __cdecl LOAD_INT32(std::istream &);

    // address=[0x13edc70]
    static unsigned long __cdecl LOAD_ID(std::istream &);

    // address=[0x13edcc0]
    static double __cdecl LOAD_FLOAT64(std::istream &);

    // address=[0x13edd10]
    static float __cdecl LOAD_FLOAT32(std::istream &);

    // address=[0x13edd60]
    static char __cdecl LOAD_char(std::istream &);

    // address=[0x13eddb0]
    static std::string __cdecl LOAD_string(std::istream &);

    // address=[0x13ede70]
    static bool __cdecl LOAD_bool(std::istream &);

private:
    // address=[0x3d89400]
    static unsigned long m_iNextClassID;

    // address=[0x3efe474]
    static unsigned long m_iClassID;

};


#endif // CPERSISTENCE_H
