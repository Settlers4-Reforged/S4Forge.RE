#ifndef CFILE_H
#define CFILE_H

class CFile : public IFSNode {
public:
    // address=[0x135ca40]
     CFile(void);

    // address=[0x135d3a0]
    virtual  ~CFile(void);

    // address=[0x135df00]
    virtual void  Accept(class IFSVisitor &);

    // address=[0x135dff0]
    virtual std::string const &  GetName(void);

    // address=[0x2f01020]
     CFile(std::wstring const &,unsigned int);

    // address=[0x2f010d0]
     CFile(wchar_t const *,unsigned int);

    // address=[0x2f011c0]
    void  Open(std::wstring const &,unsigned int,char *,int);

    // address=[0x2f011f0]
    void  Open(wchar_t const *,unsigned int,char *,int);

    // address=[0x2f012d0]
    unsigned int  Read(void *,int,int,char *,int);

    // address=[0x2f01300]
    unsigned int  Write(void const *,int,int,char *,int);

    // address=[0x2f01330]
    int  Seek(int,int,char *,int);

    // address=[0x2f01380]
    virtual int  Size(void)const;

    // address=[0x2f013e0]
    int  Tell(char *,int)const;

    // address=[0x2f01400]
    int  Eof(void);

    // address=[0x2f01420]
    int  Error(void);

    // address=[0x2f01440]
    int  Close(char *,int);

    // address=[0x2f016b0]
    class CFile &  operator=(class CFile &);

    // address=[0x2f016f0]
    struct _iobuf *  GetFile(void);

protected:
    // address=[0x2f014c0]
    void  OpenMaskToCWStr(unsigned int,std::wstring &);

};


#endif // CFILE_H
