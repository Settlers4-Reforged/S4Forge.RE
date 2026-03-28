//**************************************************************
// Copyright (c) 1998 by Warren Ward. Permission is granted to
// use this source code as long as this copyright notice appears
// in all source files that now include it.
//**************************************************************

#include    "Cryptor.h"

//***********************************************
// CLASS IMPLEMENTATION
// Cryptor
//***********************************************

Cryptor::Cryptor() :
    // Initialize LFSRs to non-zero values.
    m_LFSR_A(0x13579BDF),
    m_LFSR_B(0x2468ACE0),
    m_LFSR_C(0xFDB97531),

    // Initialize feedback masks to magic numbers.
    m_Mask_A(0x80000062),
    m_Mask_B(0x40000020),
    m_Mask_C(0x10000002),

    // Set up LFSR "rotate" masks.
    m_Rot0_A(0x7FFFFFFF),
    m_Rot0_B(0x3FFFFFFF),
    m_Rot0_C(0x0FFFFFFF),
    m_Rot1_A(0x80000000),
    m_Rot1_B(0xC0000000),
    m_Rot1_C(0xF0000000) {}

Cryptor::~Cryptor() {}

void Cryptor::Set_Key(const std::string &Key) {
    int Index = 0;

    // Set default key if none provided.
    m_Key = Key;
    std::string Seed = m_Key;
    if(0 == Seed.length()) {
        Seed = "Default Seed";
    }

    // Make sure seed is at least 12 bytes long .
    for(Index = 0; Seed.length() < 12; Index++) {
        Seed += Seed[Index];
    }

    // LFSR A, B, and C get the first, second, and
    // third four bytes of the seed, respectively.
    for(Index = 0; Index < 4; Index++) {
        m_LFSR_A =
        (
            (m_LFSR_A <<= 8) |
            ((unsigned long int) Seed[Index + 0])
        );
        m_LFSR_B =
        (
            (m_LFSR_B <<= 8) |
            ((unsigned long int) Seed[Index + 4])
        );
        m_LFSR_C =
        (
            (m_LFSR_C <<= 8) |
            ((unsigned long int) Seed[Index + 8])
        );
    }

    // If any LFSR contains 0x00000000, load a
    // non-zero default value instead.
    if(0x00000000 == m_LFSR_A)
        m_LFSR_A = 0x13579BDF;

    if(0x00000000 == m_LFSR_B)
        m_LFSR_B = 0x2468ACE0;

    if(0x00000000 == m_LFSR_C)
        m_LFSR_C = 0xFDB97531;

    return;
}

void Cryptor::Transform_File
(
    const std::string &Key,
    const std::string &Target
) {
    int Current_Char = 'X';

    // Open the file for binary read and write.
    std::ifstream Source
    (
        Target.c_str(),
        std::ios::in | std::ios::out | std::ios::binary
    );
    std::ostream Out(Source.rdbuf());

    // Reset the shift registers.
    Set_Key(Key);

    // Transform each character in the file.
    while(EOF != (Current_Char = Source.peek())) {
        Out.rdbuf()->pubseekoff
                (0, std::ios::cur);
        Transform_Char
                ((unsigned char &) Current_Char);
        Out.put(Current_Char);
        Source.rdbuf()->pubseekoff
                (0, std::ios::cur);
    }   // end while ( EOF . . .

    return;
}

void Cryptor::Transform_String
(
    const std::string &Key,
    std::string &      Target
) {
    int Position = 0;
    int Length = 0;

    // Reset the shift registers.
    Set_Key(Key);

    // Transform each character in the string.
    Length = Target.length();
    for(Position = 0; Position < Length; Position++) {
        Transform_Char
                ((unsigned char &) Target[Position]);
    }

    return;
}


//*********************************************************
// Copyright (c) 1998 by Warren Ward. Permission is granted
// to use this source code as long as this copyright notice
// appears in all source files that now include it.
//*********************************************************

void Cryptor::Weak_Transform_Char(unsigned char &Target) {
    int               Counter = 0;
    unsigned char     Crypto = '\0';
    unsigned long int Out_A = 0x00000000;

    // Cycle the LFSR eight times to get eight pseudo-
    // random bits. Assemble these into a single random
    // character (Crypto).
    for(Counter = 0; Counter < 8; Counter++) {
        if(m_LFSR_A & 0x00000001) {
            // The least-significant bit of LFSR A is
            // "1". XOR LFSR A with its feedback mask.
            m_LFSR_A =
            (
                (m_LFSR_A ^ (m_Mask_A >> 1)) |
                m_Rot1_A
            );
            Out_A = 0x00000001;
        }   // end if ( m_LFSR_A . . .
        else {
            // The LSB of LFSR A is "0".
            // Rotate the LFSR contents once.
            m_LFSR_A =
            (
                (m_LFSR_A >> 1) &
                m_Rot0_A
            );
            Out_A = 0x00000000;
        }   // end else

        // Rotate the output bit into Crypto.
        //
        Crypto = ((Crypto << 1) | (Out_A));
    }   // end for ( Counter . . .

    // XOR the resulting character with the
    // input character to encrypt/decrypt it.
    Target = (Target ^ Crypto);

    return;
}

//**************************************************************
// Copyright (c) 1998 by Warren Ward. Permission is granted to
// use this source code as long as this copyright notice appears
// in all source files that now include it.
//**************************************************************

void Cryptor::Transform_Char(unsigned char &Target) {
    int               Counter = 0;
    unsigned char     Crypto = '\0';
    unsigned long int Out_B = (m_LFSR_B & 0x00000001);
    unsigned long int Out_C = (m_LFSR_C & 0x00000001);

    // Cycle the LFSRs eight times to get eight pseudo-
    // random bits. Assemble these into a single random
    // character (Crypto).
    for(Counter = 0; Counter < 8; Counter++) {
        if(m_LFSR_A & 0x00000001) {
            // The least-significant bit of LFSR A is
            // "1". XOR LFSR A with its feedback mask.
            m_LFSR_A =
            (
                (m_LFSR_A ^ (m_Mask_A >> 1)) |
                m_Rot1_A
            );

            // Clock shift register B once.
            if(m_LFSR_B & 0x00000001) {
                // The LSB of LFSR B is "1".
                // XOR LFSR B with its feedback mask.
                m_LFSR_B =
                (
                    (m_LFSR_B ^ (m_Mask_B >> 1)) |
                    m_Rot1_B
                );
                Out_B = 0x00000001;
            } else {
                // The LSB of LFSR B is "0". Rotate
                // the LFSR contents once.
                m_LFSR_B =
                (
                    (m_LFSR_B >> 1) &
                    m_Rot0_B
                );
                Out_B = 0x00000000;
            }
        }   // end if
        else {
            // The LSB of LFSR A is "0".
            // Rotate the LFSR contents once.
            m_LFSR_A = ((m_LFSR_A >> 1) & m_Rot0_A);

            // Clock shift register C once.
            if(m_LFSR_C & 0x00000001) {
                // The LSB of LFSR C is "1".
                // XOR LFSR C with its feedback mask.
                m_LFSR_C =
                (
                    (m_LFSR_C ^ (m_Mask_C >> 1)) |
                    m_Rot1_C
                );
                Out_C = 0x00000001;
            }   // end if
            else {
                // The LSB of LFSR C is "0". Rotate
                // the LFSR contents once.
                m_LFSR_C =
                        ((m_LFSR_C >> 1) & m_Rot0_C);
                Out_C = 0x00000000;
            }   // end else
        }   // end else

        // XOR the output from LFSRs B and C and rotate it
        // into the right bit of Crypto.
        Crypto = ((Crypto << 1) | (Out_B ^ Out_C));
    }   // end for ( Counter . . .

    // XOR the resulting character with the
    // input character to encrypt/decrypt it.
    Target = (Target ^ Crypto);

    return;
}
