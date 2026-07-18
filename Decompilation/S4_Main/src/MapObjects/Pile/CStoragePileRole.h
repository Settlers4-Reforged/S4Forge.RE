#ifndef CSTORAGEPILEROLE_H
#define CSTORAGEPILEROLE_H

#include "IPileRole.h"
#include "defines.h"

class CStoragePileRole : public IPileRole {
  public:
    // address=[0x1402200]
    static class CPersistence *__cdecl New(std::istream &_rStream);

    // address=[0x1560260]
    virtual ~CStoragePileRole(void);

    // address=[0x1560320]
    virtual unsigned long ClassID(void) const;

    // address=[0x1560440]
    static class CStoragePileRole *__cdecl Load(std::istream &_rStream);

    // address=[0x1561900]
    virtual void Init(class CPile *_pPile);

    // address=[0x1561940]
    CStoragePileRole(std::istream &_rStream);

    // address=[0x15619f0]
    virtual void Store(std::ostream &_rStream);

    // address=[0x3d8be9c]
    static unsigned long m_iClassID;

  private:
    friend class CPileMgr;

    // address=[0x15601d0]
    CStoragePileRole(void);
};

#endif // CSTORAGEPILEROLE_H
