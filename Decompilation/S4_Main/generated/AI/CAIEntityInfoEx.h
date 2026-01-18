#ifndef CAIENTITYINFOEX_H
#define CAIENTITYINFOEX_H

#include "defines.h"

class CAIEntityInfoEx {
public:
    // address=[0x130acc0]
     CAIEntityInfoEx(enum T_AI_ENTITY_INFO_EX_CLASS a2);

    // address=[0x130acf0]
    virtual  ~CAIEntityInfoEx(void);

    // address=[0x130adb0]
    enum T_AI_ENTITY_INFO_EX_CLASS  Class(void)const;

protected:
    // address=[0x130aaf0]
    static class CAIEntityInfoEx * __cdecl CreateExtendedInfo(enum T_AI_ENTITY_INFO_EX_CLASS a1);

};


#endif // CAIENTITYINFOEX_H
