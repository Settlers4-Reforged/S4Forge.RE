#ifndef CMANAKOPTER_CSETTLERSTATUS_H
#define CMANAKOPTER_CSETTLERSTATUS_H

namespace CManakopter {

class CSettlerStatus {
public:
    // address=[0x1554910]
     CSettlerStatus(class CManakopter::CSettlerStatus const &);

    // address=[0x1554950]
     CSettlerStatus(int,enum SETTLER_TYPES,int);

    // address=[0x1554990]
     CSettlerStatus(void);

    // address=[0x1554b60]
     ~CSettlerStatus(void);

};

} // namespace CManakopter

#endif // CMANAKOPTER_CSETTLERSTATUS_H
