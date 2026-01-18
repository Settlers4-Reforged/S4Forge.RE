#ifndef CCLIPBOARD_H
#define CCLIPBOARD_H

#include "defines.h"

class CClipboard : public IClipboard {
public:
    // address=[0x147f5e0]
    virtual void  CopyTextToClipboard(char const * Str);

    // address=[0x147f690]
    virtual void  CopyTextToClipboard(std::string const & a2);

    // address=[0x147f6c0]
    virtual void  GetTextFromClipboard(std::string & a1, int a2);

    // address=[0x147f7f0]
     CClipboard(void);

};


#endif // CCLIPBOARD_H
