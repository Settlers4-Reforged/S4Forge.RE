#ifndef CDEFINETRANSLATOR_H
#define CDEFINETRANSLATOR_H

#include <memory>

#include "defines.h"

extern class CDefineTranslator *g_pDefineTranslator;

class CDefineTranslator {
public:
    // address=[0x141dbe0]
    int GetValueOfDefine(std::string const &rDefine) const;

    // address=[0x14f3f70]
    // See note below. Use g_pDefineTranslator
    //static class CDefineTranslator & __cdecl Instance(void);

    static CDefineTranslator s_cDefineTranslator;

private:
    // address=[0x141dcf0]
    // NOTE: this managed pointer just doesn't make that much sense for global singletons
    //static std::shared_ptr<CDefineTranslator> __cdecl GetInstance(void); //NOTE: modified from auto_ptr!

    // address=[0x141ddd0]
    CDefineTranslator(void);

    // address=[0x1422bf0]
    ~CDefineTranslator(void);

    // address=[0x1422c40]
    bool Status(void);

    // address=[0x14269c0]
    // NOTE: see note above
    //static void __cdecl DestroyInstance(void);

    std::map<std::string, int> m_mDefines;
};


#endif // CDEFINETRANSLATOR_H
