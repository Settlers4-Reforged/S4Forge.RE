#ifndef CS4INVALIDMAPEXCEPTION_H
#define CS4INVALIDMAPEXCEPTION_H

#include "defines.h"

class CS4InvalidMapException : public CBBException {
public:
    // address=[0x1313ec0]
     CS4InvalidMapException(class CS4InvalidMapException const & a2);

    // address=[0x1313ef0]
     CS4InvalidMapException(void);

    // address=[0x1313f80]
    virtual  ~CS4InvalidMapException(void);

};


#endif // CS4INVALIDMAPEXCEPTION_H
