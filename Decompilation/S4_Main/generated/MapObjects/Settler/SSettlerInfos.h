#ifndef CSETTLERMGR_SSETTLERINFOS_H
#define CSETTLERMGR_SSETTLERINFOS_H

#include "defines.h"

namespace CSettlerMgr {

class SSettlerInfos {
public:
    // address=[0x1587b80]
     SSettlerInfos(void);

    // address=[0x1587cb0]
     ~SSettlerInfos(void);

    // address=[0x1588360]
    struct CSettlerMgr::SSettlerInfos &  operator=(struct CSettlerMgr::SSettlerInfos const & a2);

};

} // namespace CSettlerMgr

#endif // CSETTLERMGR_SSETTLERINFOS_H
