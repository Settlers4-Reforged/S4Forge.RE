#ifndef SIMPLLOCKWRAPPER_H
#define SIMPLLOCKWRAPPER_H

class SimplLockWrapper {
public:
    // address=[0x2dbc220]
     SimplLockWrapper(char const *);

    // address=[0x2dc1a70]
     ~SimplLockWrapper(void);

    // address=[0x2dd13a0]
    struct _RTL_CRITICAL_SECTION &  GetLock(void);

};


#endif // SIMPLLOCKWRAPPER_H
