#ifndef STORMSAMPLEFRAMEWORK_H
#define STORMSAMPLEFRAMEWORK_H

#include "defines.h"

class StormSampleFramework : public SampleFrameworkApplication {
public:
    // address=[0x1683070]
     StormSampleFramework(class StormManager & a2, bool a3);

    // address=[0x1685010]
    virtual  ~StormSampleFramework(void);

};


#endif // STORMSAMPLEFRAMEWORK_H
