#ifndef _BSTR_T_DATA_T_H
#define _BSTR_T_DATA_T_H

namespace _bstr_t {

class Data_t {
public:
    // address=[0x2fbec70]
     Data_t(wchar_t const *);

    // address=[0x2fbedd0]
    static void * __cdecl operator new(unsigned int);

    // address=[0x2fbee70]
    char const *  GetString(void)const;

    // address=[0x2fbeeb0]
    unsigned long  Release(void);

private:
    // address=[0x2fbed90]
     ~Data_t(void);

    // address=[0x2fbef10]
    void  _Free(void);

};

} // namespace _bstr_t

#endif // _BSTR_T_DATA_T_H
