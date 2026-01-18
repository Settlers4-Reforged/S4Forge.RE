#ifndef CDYNLIST_H
#define CDYNLIST_H

#include "defines.h"

class CDynList {
public:
    // address=[0x2f3bb50]
    class CDynListEntry *  FirstEntry(void)const;

    // address=[0x2f3c7e0]
     CDynList(void);

    // address=[0x2f3c810]
     ~CDynList(void);

    // address=[0x2f3c850]
    int  addElement(class CDynListEntry * a2);

    // address=[0x2f3c8d0]
    int  insertElementAt(class CDynListEntry * a2, int a3);

    // address=[0x2f3c980]
    class CDynListEntry *  elementAt(int a2);

    // address=[0x2f3c9f0]
    int  resize(void);

    // address=[0x2f3ca60]
    int  delElement(int a2);

    // address=[0x2f3cb60]
    int  delElement(class CDynListEntry * a2);

    // address=[0x2f3cb80]
    void  ClearDynList(void);

    // address=[0x2f3cc30]
    int  sort(int a2);

    // address=[0x2f404e0]
    int  isEmpty(void);

    // address=[0x2f40520]
    int  size(void);

};


#endif // CDYNLIST_H
