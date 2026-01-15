#ifndef CSTRINGENGINEEX_H
#define CSTRINGENGINEEX_H

class CStringEngineEx : public CStringEngine {
public:
    // address=[0x14ce780]
     CStringEngineEx(int);

    // address=[0x14ce900]
    virtual  ~CStringEngineEx(void);

    // address=[0x14ce9a0]
    virtual char const *  GetString(int);

private:
    // address=[0x14cea80]
    bool  ExtractStrings(char *,int,int);

    // address=[0x14ced10]
    bool  ImportFile(wchar_t const *,int);

    // address=[0x14cef30]
    void  CreateTextForEmptyStrings(void);

    // Type information members
private:
    wchar_t ** strings;

};


#endif // CSTRINGENGINEEX_H
