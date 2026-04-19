// address=[0x2f2d880]
void __stdcall BBSupportActivateDbgReportHook(void);

// address=[0x2f2d8c0]
int __stdcall BBSupportDbgReport(int, char const *, unsigned int, char const *);

// address=[0x2f2df30]
int __cdecl BBSupportDbgReportF(int, char const *, unsigned int, char const *, ...);

#define BB_REPORT(msg) if(BBSupportDbgReport(2, __FILE__, __LINE__, msg) == 1) { __debugbreak(); }
#define BB_REPORTF(msg, arg...) if(BBSupportDbgReportF(2, __FILE__, __LINE__, msg, arg) == 1) { __debugbreak(); }
#define BB_ASSERT(cond) if(!(cond) && BBSupportDbgReport(2, __FILE__, __LINE__, #cond) == 1) { __debugbreak(); }

// address=[0x2f2dfe0]
void __stdcall BBSupportWarningMessageBoxes(bool);

// address=[0x2f2e210]
void __stdcall BBSupportOpenTraceFile(int, wchar_t const *);

// address=[0x2f2e270]
void __stdcall BBSupportSmartOpenTraceFile(wchar_t const *, wchar_t const *);

// address=[0x2f2e770]
bool __stdcall BBSupportGetTraceFilePath(wchar_t *, unsigned int);

// address=[0x2f2e7d0]
void __stdcall BBSupportTracePrint(unsigned int, char const *);

// address=[0x2f2ea40]
void __stdcall BBSupportTracePrint(unsigned int, wchar_t const *);

// address=[0x2f2ecc0]
void __cdecl BBSupportTracePrintF(unsigned int, char const *, ...);

// address=[0x2f2ed60]
unsigned int __stdcall BBSupportReserveTraceLevel(void);

// address=[0x2f2edb0]
void __stdcall BBSupportEnableTraceLevel(unsigned int);

// address=[0x2f2ee20]
void __stdcall BBSupportDisableTraceLevel(unsigned int);

// address=[0x2f2faa0]
void __stdcall BBSupportSetErrorHandlingMode(int);

// address=[0x2f32390]
void __stdcall BBSupportActivateUnhandledExceptionFilter(void);

// address=[0x2f323b0]
void __stdcall BBSupportActivateSETranslator(void);

// address=[0x2f33610]
void __stdcall BBSupportActivateNewHandler(void);

// address=[0x2f30da0]
int __stdcall BBSupportLoadDbgHelpDll(int);

// address=[0x2f30e00]
void __stdcall BBSupportTraceDumpModules(void);

// address=[0x2f2fb40]
bool __stdcall BBSupportIsDevelopmentMachine(void);

// address=[0x2f2fca0]
unsigned int __stdcall BBSupportDevelopmentMachineId(void);

// address=[0x2f2fe10]
unsigned int __stdcall BBSupportGetModuleTimeDateStamp(void *);

// address=[0x2f2fa90]
char const * __cdecl BBSupportDllVersionString(void);

// address=[0x1603ef0]
void __cdecl ScriptTracePrintF(unsigned int a1, char const *Format, ...);

namespace BBSupportLib {
    // address=[0x2f2f800]
    void __stdcall BBSCopyString(wchar_t *, wchar_t const *, unsigned int);

    // address=[0x2f2f9e0]
    int __stdcall BBSGetDevelopmentFlags(void);

    // address=[0x2f2fa10]
    bool __cdecl BBSIsNumber(char);

    // address=[0x2f2fa40]
    unsigned int __cdecl BBSNumberValue(char);
}
