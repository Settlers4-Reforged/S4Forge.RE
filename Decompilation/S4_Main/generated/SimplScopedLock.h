#ifndef SIMPLSCOPEDLOCK_H
#define SIMPLSCOPEDLOCK_H

class SimplScopedLock {
public:
    // address=[0x2dbc270]
     SimplScopedLock(struct _RTL_CRITICAL_SECTION &);

    // address=[0x2dc1ab0]
     ~SimplScopedLock(void);

};


#endif // SIMPLSCOPEDLOCK_H
