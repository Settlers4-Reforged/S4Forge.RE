#ifndef S4_CSAVEFILE_H
#define S4_CSAVEFILE_H

namespace S4 {

class CSaveFile {
public:
    // address=[0x13e50e0]
     ~CSaveFile(void);

    // address=[0x13e6580]
    unsigned int  GetFilePos(void);

    // address=[0x13eb4f0]
     CSaveFile(bool);

    // address=[0x13eb520]
    bool  Open(std::wstring const &,int);

    // address=[0x13eb590]
    bool  Close(void);

    // address=[0x13eb5b0]
    int  Read(void *,int);

    // address=[0x13eb600]
    int  Write(void const *,int);

    // address=[0x13eb630]
    void  SetFilePos(int,int);

    // address=[0x13eb660]
    unsigned int  GetFileSize(void);

    // address=[0x13eb680]
    bool  Eof(void);

};

} // namespace S4

#endif // S4_CSAVEFILE_H
