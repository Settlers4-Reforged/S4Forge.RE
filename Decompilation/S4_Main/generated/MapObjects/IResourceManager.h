#ifndef CONCURRENCY_IRESOURCEMANAGER_H
#define CONCURRENCY_IRESOURCEMANAGER_H

#include "defines.h"

namespace Concurrency {

class IResourceManager {
public:
    // address=[0x3026100]
     IResourceManager(void);

    // Type information members
private:
    struct IResourceManagerVtbl * lpVtbl;

};

} // namespace Concurrency

#endif // CONCURRENCY_IRESOURCEMANAGER_H
