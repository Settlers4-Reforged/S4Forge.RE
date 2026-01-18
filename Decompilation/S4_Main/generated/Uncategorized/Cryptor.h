#ifndef CRYPTOR_H
#define CRYPTOR_H

#include "defines.h"

class Cryptor {
public:
    // address=[0x2f029a0]
     Cryptor(void);

    // address=[0x2f02a30]
     ~Cryptor(void);

    // address=[0x2f02a50]
    void  Set_Key(std::string const & a2);

    // address=[0x2f02c10]
    void  Transform_Char(unsigned char & a2);

    // address=[0x2f02d60]
    void  Transform_File(std::string const & a2, std::string const & a3);

    // address=[0x2f02e90]
    void  Transform_String(std::string const & a2, std::string & a3);

    // address=[0x2f02f00]
    void  Weak_Transform_Char(unsigned char & a2);

};


#endif // CRYPTOR_H
