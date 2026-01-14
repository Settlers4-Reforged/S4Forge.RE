#ifndef COWNERMAP_H
#define COWNERMAP_H

class COwnerMap {
public:
    // address=[0x13068b0]
    static int __cdecl OwnerBits1VW(int,int);

    // address=[0x13068d0]
    static int __cdecl OwnerBits9VW(int,int);

    // address=[0x133a050]
    static int __cdecl OwnerBit(int);

    // address=[0x1351d30]
    static int __cdecl OwnerBits1XY(int,int);

    // address=[0x15afa20]
    static int __cdecl OwnerBits9XY(int,int);

protected:
    // address=[0x15de7d0]
    static void __cdecl ClearOwnerBits(void);

    // address=[0x15de7f0]
    static unsigned char & __cdecl OwnerBits1VWRef(int,int);

    // address=[0x15de810]
    static unsigned char & __cdecl OwnerBits9VWRef(int,int);

private:
    // address=[0x418fe60]
    static struct SOwnerBits (* COwnerMap::m_sOwnerBits)[64];

};


#endif // COWNERMAP_H
