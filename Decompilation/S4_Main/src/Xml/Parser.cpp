#include "Parser.h"

#include "File/CFileEx.h"
#include "XMLParser/AdvXMLParser.h"
// See XMLParser for actual definition of original


// address=[0x2f26770]
// Decompiled from void *__cdecl AdvXMLParser::Parser::OpenXMLFile(wchar_t *FileName, int *a2)
char * __cdecl AdvXMLParser::Parser::OpenXMLFile(wchar_t const *swpFileName, long &_iSize) {
    CFileEx cFile = CFileEx(swpFileName, 6, false);

    _iSize = cFile.Size();
    char *pBuffer = new char[_iSize + 1];
    cFile.Read(pBuffer, 1, _iSize, CFileLog);
    cFile.Close(CFileLog);
    pBuffer[_iSize] = 0;

    return pBuffer;
}
