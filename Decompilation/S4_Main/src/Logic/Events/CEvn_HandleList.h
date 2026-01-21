#ifndef CEVN_HANDLELIST_H
#define CEVN_HANDLELIST_H

#include "defines.h"

class CEvn_HandleList : public std::list<class IEvn_Handle *> {
public:
    // address=[0x1356900]
     CEvn_HandleList(void) = default;

    // address=[0x1356930]
    virtual  ~CEvn_HandleList(void) = default;
};


#endif // CEVN_HANDLELIST_H
