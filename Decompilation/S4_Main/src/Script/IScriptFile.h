#ifndef ISCRIPTFILE_H
#define ISCRIPTFILE_H

#include "defines.h"

class IScriptFile {
public:
    // address=[0x160ddf0]
     IScriptFile(void);

    // address=[0x160de10]
    virtual  ~IScriptFile(void);

    // address=[0x160dd50]
    virtual char const *  GetScript(void);

    // address=[0x160dd70]
    virtual unsigned int  GetSize(void);
};


#endif // ISCRIPTFILE_H
