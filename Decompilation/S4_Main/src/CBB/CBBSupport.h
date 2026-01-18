// address=[0x2f2d880]
void __stdcall BBSupportActivateDbgReportHook(void);

// address=[0x2f2d8c0]
int __stdcall BBSupportDbgReport(int,char const *,unsigned int,char const *);

// address=[0x2f2df30]
int __cdecl BBSupportDbgReportF(int,char const *,unsigned int,char const *,...);

// address=[0x2f2dfe0]
void __stdcall BBSupportWarningMessageBoxes(bool);

// address=[0x2f2e210]
void __stdcall BBSupportOpenTraceFile(int,wchar_t const *);

// address=[0x2f2e270]
void __stdcall BBSupportSmartOpenTraceFile(wchar_t const *,wchar_t const *);

// address=[0x2f2e770]
bool __stdcall BBSupportGetTraceFilePath(wchar_t *,unsigned int);

// address=[0x2f2e7d0]
void __stdcall BBSupportTracePrint(unsigned int,char const *);

// address=[0x2f2ea40]
void __stdcall BBSupportTracePrint(unsigned int,wchar_t const *);

// address=[0x2f2ecc0]
void __cdecl BBSupportTracePrintF(unsigned int,char const *,...);

// address=[0x2f2ed60]
unsigned int __stdcall BBSupportReserveTraceLevel(void);

// address=[0x2f2edb0]
void __stdcall BBSupportEnableTraceLevel(unsigned int);

// address=[0x2f2ee20]
void __stdcall BBSupportDisableTraceLevel(unsigned int);

namespace BBSupportLib {
    // address=[0x2f2f800]
    void __stdcall BBSCopyString(wchar_t *,wchar_t const *,unsigned int);

    // address=[0x2f2f9e0]
    int __stdcall BBSGetDevelopmentFlags(void);

    // address=[0x2f2fa10]
    bool __cdecl BBSIsNumber(char);

    // address=[0x2f2fa40]
    unsigned int __cdecl BBSNumberValue(char);
}
