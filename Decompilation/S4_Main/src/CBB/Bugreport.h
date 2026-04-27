#ifndef BUGREPORT_H
#define BUGREPORT_H

#include "defines.h"

extern char g_szBugReportText[8200];

namespace Bugreport {
    // address=[0x134dbe0]
    std::wstring __cdecl GetBugReportsDirectoryPath(void);

    // address=[0x134dc80]
    std::wstring __cdecl GetBugReportScreenshotPath(void);

    // address=[0x134dd20]
    std::wstring __cdecl GetBugReportMessageFilePath(void);

    // address=[0x134df60]
    std::wstring __cdecl BuildTraceFilePath(std::wstring const &a2);

    // address=[0x134ddc0]
    std::wstring __cdecl BuildAutoReporterCmdLineArgsForDebugReports(void);

    // address=[0x134de90]
    std::wstring __cdecl BuildAutoReporterCmdLineArgsForUserReports(void);

    // address=[0x134e050]
    void __cdecl LaunchAutoreport(bool, std::wstring const &);
}

#endif // BUGREPORT_H
