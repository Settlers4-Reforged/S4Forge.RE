#ifndef CSTDSCRIPTFILE_H
#define CSTDSCRIPTFILE_H

#include "defines.h"

class CStdScriptFile : public IScriptFile {
public:
    // address=[0x160dbd0]
     CStdScriptFile(wchar_t const * FileName);

    // address=[0x160dd00]
    virtual  ~CStdScriptFile(void);

    // address=[0x160dd50]
    virtual char const *  GetScript(void);

    // address=[0x160dd70]
    virtual unsigned int  GetSize(void);

};


#endif // CSTDSCRIPTFILE_H
