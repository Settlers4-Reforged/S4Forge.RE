#ifndef FILEPATHS_PATHSPLITRESULT_H
#define FILEPATHS_PATHSPLITRESULT_H

#include "defines.h"

namespace FilePaths
{
    class PathSplitResult
    {
    public:
        // address=[0x134e750]
        ~PathSplitResult(void);

        // address=[0x2eff700]
        PathSplitResult(struct FilePaths::PathSplitResult &&a2);

        // address=[0x2eff760]
        PathSplitResult(void);

        std::wstring m_swpDrive;
        std::vector<std::wstring> m_vSplits;
        std::wstring m_swpDirectoryName;
        bool m_bSplit;
    };

} // namespace FilePaths

#endif // FILEPATHS_PATHSPLITRESULT_H
