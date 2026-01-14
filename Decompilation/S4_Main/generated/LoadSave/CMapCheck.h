#ifndef CMAPCHECK_H
#define CMAPCHECK_H

class CMapCheck : public IMapCheck {
public:
    // address=[0x1496ac0]
    virtual unsigned int  CalculateMapCRC2(int,int,int,int,int);

    // address=[0x1496af0]
    virtual enum IMapCheck::PATCHMAPS  GetPatchMap(wchar_t const *,unsigned int,unsigned int);

    // address=[0x1496d10]
     CMapCheck(void);

protected:
    // address=[0x1496b80]
    static bool __cdecl StrStrLo(wchar_t const *,wchar_t const *);

};


#endif // CMAPCHECK_H
