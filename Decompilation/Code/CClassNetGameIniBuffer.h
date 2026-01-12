#ifndef CCLASSNETGAMEINIBUFFER_H
#define CCLASSNETGAMEINIBUFFER_H

class CClassNetGameIniBuffer {
public:
    // address=[0x15bf230]
    int  GetIntValue(char const *,int);

    // address=[0x15bf280]
    char const *  GetStartOfEntry(char const *);

    // address=[0x15c3880]
     CClassNetGameIniBuffer(char const *,unsigned int);

};


#endif // CCLASSNETGAMEINIBUFFER_H
