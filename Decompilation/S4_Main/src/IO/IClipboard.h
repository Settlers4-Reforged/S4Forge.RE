#ifndef ICLIPBOARD_H
#define ICLIPBOARD_H

#include "defines.h"

class IClipboard {
public:
    // address=[0x147f820]
     IClipboard(void);

    virtual void  CopyTextToClipboard(char const * Str) = 0;

    virtual void  CopyTextToClipboard(std::string const & a2) = 0;

    virtual void  GetTextFromClipboard(std::string & a1, int a2) = 0;
};


#endif // ICLIPBOARD_H
