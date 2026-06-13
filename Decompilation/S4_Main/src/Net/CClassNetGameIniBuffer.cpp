#include "CClassNetGameIniBuffer.h"

// Definitions for class CClassNetGameIniBuffer

// address=[0x15bf230]
// Decompiled from int __thiscall CClassNetGameIniBuffer::GetIntValue(CClassNetGameIniBuffer *this, char *SubStr, int a3)
int CClassNetGameIniBuffer::GetIntValue(char const *SubStr, int a3) {
    char *EndPtr; // [esp+0h] [ebp-10h] BYREF
    const char *String = GetStartOfEntry(SubStr);
    if(String)
        return strtol(String, &EndPtr, 10);
    return a3;
}

int CClassNetGameIniBuffer::GetWStringValue(char const *SubStr, wchar_t *pBuffer) {
    const char *pStrFind = GetStartOfEntry(SubStr);
    if(!pStrFind) {
        return -1;
    }
    char const *pLineEnd = strstr(pStrFind, "\n");
    if(!pLineEnd)
        return -1;

    int l = mbstowcs(pBuffer, pStrFind, (pLineEnd - pStrFind));
    pBuffer[l] = 0;

    return l;
}

int CClassNetGameIniBuffer::GetStringValue(char const *SubStr, char *pBuffer) {
    const char *pStrFind = GetStartOfEntry(SubStr);
    if(!pStrFind)
        return -1;

    char const *pLineEnd = strstr(pStrFind, "\n");
    if(!pLineEnd)
        return -1;

    strncpy(pBuffer, pStrFind, (pLineEnd - pStrFind));
    pBuffer[pLineEnd - pStrFind] = 0;
    return pLineEnd - pStrFind;
}

// address=[0x15bf280]
// Decompiled from const char *__thiscall CClassNetGameIniBuffer::GetStartOfEntry(CClassNetGameIniBuffer *this, char *SubStr)
char const *CClassNetGameIniBuffer::GetStartOfEntry(char const *SubStr) {

    // [esp+4h] [ebp-4h]

    if(!SubStr || !*SubStr)
        return 0;
    const char *Str = strstr(this->m_spBuffer, SubStr);
    if(!Str)
        return Str;
    Str = strstr(Str, "=");
    if(Str)
        ++Str;
    return Str;
}

// address=[0x15c3880]
// Decompiled from CClassNetGameIniBuffer *__thiscall CClassNetGameIniBuffer::CClassNetGameIniBuffer(  CClassNetGameIniBuffer *this,  const char *a2,  unsigned int a3)
CClassNetGameIniBuffer::CClassNetGameIniBuffer(char const *a2, unsigned int a3) {
    this->m_spBuffer = a2;
    this->m_uFileSize = a3;
}
