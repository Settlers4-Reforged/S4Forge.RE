#ifndef CFILEEX_H
#define CFILEEX_H

class CFileEx : public CFile, public IFileEx {
public:
    // address=[0x135cb10]
     CFileEx(void);

    // address=[0x135d430]
    virtual  ~CFileEx(void);

    // address=[0x1496960]
    bool  InLibrary(void)const;

    // address=[0x2f01710]
     CFileEx(std::wstring const &,unsigned int,bool);

    // address=[0x2f017f0]
     CFileEx(wchar_t const *,unsigned int,bool);

    // address=[0x2f01900]
    virtual void  Open(std::wstring const &,unsigned int,bool,char *,int);

    // address=[0x2f01950]
    virtual void  Open(wchar_t const *,unsigned int,bool,char *,int);

    // address=[0x2f01ad0]
    virtual int  MapFile(wchar_t const *,char *,int);

    // address=[0x2f01d30]
    virtual void *  GetMapFilePtr(void);

    // address=[0x2f01d50]
    virtual unsigned int  Read(void *,int,int,char *,int);

    // address=[0x2f01ef0]
    virtual unsigned int  Write(void const *,int,int,char *,int);

    // address=[0x2f01f40]
    virtual int  Seek(int,int,char *,int);

    // address=[0x2f02120]
    virtual int  Size(void)const;

    // address=[0x2f02160]
    virtual int  Close(char *,int);

    // address=[0x2f02220]
    virtual void  Release(void);

};


#endif // CFILEEX_H
