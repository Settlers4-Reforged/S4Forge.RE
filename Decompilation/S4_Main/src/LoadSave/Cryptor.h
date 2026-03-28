//*******************************************
// Copyright (c) 1998 by Warren Ward.
// Permission is granted to use this source
// code as long as this copyright notice
// appears in all source files that now
// include it.
//*******************************************

#ifndef     _CRYPTOR_H
#define     _CRYPTOR_H

#include    <fstream>   // Std. CPP stream files
#include    <string>    // Std. CPP strings

class Cryptor {
    //
    // Properties.
    //
protected:
    std::string         m_Key;
    unsigned long       m_LFSR_A;
    unsigned long       m_LFSR_B;
    unsigned long       m_LFSR_C;
    const unsigned long m_Mask_A;
    const unsigned long m_Mask_B;
    const unsigned long m_Mask_C;
    const unsigned long m_Rot0_A;
    const unsigned long m_Rot0_B;
    const unsigned long m_Rot0_C;
    const unsigned long m_Rot1_A;
    const unsigned long m_Rot1_B;
    const unsigned long m_Rot1_C;

    // Standard methods.
public:
    Cryptor();

    ~Cryptor();

    // Class interface.
public:
    void Set_Key
    (const std::string &Key);

    void Transform_Char
    (unsigned char &Target);

    void Transform_File
    (
        const std::string &Key,
        const std::string &Target
    );

    void Transform_String
    (
        const std::string &Key,
        std::string &      Target
    );

    void Weak_Transform_Char
    (unsigned char &Target);
};

#endif  //      _CRYPTOR_H
