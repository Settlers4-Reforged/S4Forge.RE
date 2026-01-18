#ifndef CDEFINETRANSLATOR_H
#define CDEFINETRANSLATOR_H

#include "defines.h"

class CDefineTranslator {
public:
    // address=[0x141dbe0]
    int  GetValueOfDefine(std::string const & a2)const;

    // address=[0x14f3f70]
    static class CDefineTranslator & __cdecl Instance(void);

private:
    // address=[0x141dcf0]
    static class std::auto_ptr<class CDefineTranslator> & __cdecl GetInstance(void);

    // address=[0x141ddd0]
     CDefineTranslator(void);

    // address=[0x1422bf0]
     ~CDefineTranslator(void);

    // address=[0x1422c40]
    bool  Status(void);

    // address=[0x14269c0]
    static void __cdecl DestroyInstance(void);

};


#endif // CDEFINETRANSLATOR_H
