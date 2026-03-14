#ifndef CAIENTITYINFOEX_H
#define CAIENTITYINFOEX_H

#include "defines.h"

enum T_AI_ENTITY_INFO_EX_CLASS {
    AI_ENTITY_INFO_EX_CLASS_TOWER = 0,
    AI_ENTITY_INFO_EX_CLASS_MAX,
};

class CAIEntityInfoEx {
public:
    // address=[0x130acc0]
    CAIEntityInfoEx(T_AI_ENTITY_INFO_EX_CLASS a2);

    // address=[0x130acf0]
    virtual ~CAIEntityInfoEx(void);

    // address=[0x130adb0]
    T_AI_ENTITY_INFO_EX_CLASS Class(void) const;

protected:
    // address=[0x130aaf0]
    static class CAIEntityInfoEx * __cdecl CreateExtendedInfo(enum T_AI_ENTITY_INFO_EX_CLASS a1);

    friend class CAIEntityInfo;

    // Type information members
public:
    T_AI_ENTITY_INFO_EX_CLASS m_bClass;
};


#endif // CAIENTITYINFOEX_H
