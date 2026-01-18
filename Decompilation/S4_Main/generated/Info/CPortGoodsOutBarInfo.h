#ifndef CPORTGOODSOUTBARINFO_H
#define CPORTGOODSOUTBARINFO_H

#include "defines.h"

class CPortGoodsOutBarInfo : public CInfoExchange {
public:
    // address=[0x1454740]
     CPortGoodsOutBarInfo(void);

    // address=[0x1454cd0]
    virtual unsigned int  Size(void)const;

};


#endif // CPORTGOODSOUTBARINFO_H
