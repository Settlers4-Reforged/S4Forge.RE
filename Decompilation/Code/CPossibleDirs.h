#ifndef CPOSSIBLEDIRS_H
#define CPOSSIBLEDIRS_H

class CPossibleDirs {
public:
    // address=[0x14e2730]
    void  Init(void);

    // address=[0x14e2750]
    void  PushDir(int);

    // address=[0x14e2e40]
     CPossibleDirs(void);

    // address=[0x14e2ff0]
    bool  Search(int);

};


#endif // CPOSSIBLEDIRS_H
