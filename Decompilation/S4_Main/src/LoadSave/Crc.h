// Listing 1
// CRC.H   Created: 1/08/98 
// Author: Colin Mahoney (cmahoney@readysoft.es)
//
// C++ implementation of CRC error checking
//
// Based on Ross Williams' Rocksoft^tm Model CRC Algorithm,
// available as part of the document "A Painless Guide to
// CRC Error Detection Algorithms", also by Ross Williams.
//
#if !defined(__CRC_H)
#define __CRC_H

#include "defines.h"

namespace cdm_crc {
    static const int CRCMaxBits = 32;

    template<int Width, unsigned long Poly, unsigned long Init,
        unsigned long XOrOut, bool Ref, bool Direct = true>
    class CRCGenerator {
    public:
        class CRCTable;
        friend class CRCTable;

        class CRCTable {
            unsigned long Table[256];
            // Calculate the table entry at 'index'
            //
            unsigned long CalcTableEntry(int index) {
                unsigned long inbyte = (unsigned long) index;
                if(Ref) {
                    inbyte = Reflect(inbyte, 8);
                }
                unsigned long topbit = Bitmask(Width - 1);
                unsigned long reg = inbyte << (Width - 8);
                for(int i = 0; i < 8; i++) {
                    if(reg & topbit) {
                        reg = (reg << 1) ^ Poly;
                    } else {
                        reg <<= 1;
                    }
                }
                if(Ref) {
                    reg = Reflect(reg, Width);
                }
                return reg & WidthMask(Width);
            }

        public:
            CRCTable() {
                for(int i = 0; i < 256; i++) {
                    Table[i] = CalcTableEntry(i);
                }
            }

            unsigned long operator[](int i) const { return Table[i]; }
        };

    private:
        static const CRCTable Table;
        // Register holds the current value of the CRC calculation
        unsigned long Register;
        // Return an unsigned long with i'th bit set to one
        static unsigned long Bitmask(int i) { return 1UL << i; }
        // Reflect the bottom b bits of val
        static unsigned long Reflect(unsigned long val, int b) {
            unsigned long t = val;
            for(int i = 0; i < b; i++) {
                if(t & 1L) {
                    val |= Bitmask((b - 1) - i);
                } else {
                    val &= ~Bitmask((b - 1) - i);
                }
                t >>= 1;
            }
            return val;
        }

        // Return an unsigned long with value ( 2^width )-1
        static unsigned long WidthMask(int width) {
            return (((1UL << (width - 1)) - 1UL) << 1) | 1UL;
        }

    public:
        CRCGenerator() : Register(Init) {}

        unsigned long GetCRC() const {
            return (XOrOut ^ Register) & WidthMask(Width);
        }

        unsigned long GetNormalCRC() const {
            unsigned long normCRC;
            if(!Ref) {
                normCRC = GetCRC();
                normCRC <<= (CRCMaxBits - Width);
            } else {
                normCRC = 0;
                unsigned long crc = GetCRC();
                for(int i = 8; i <= CRCMaxBits; i += 8) {
                    normCRC |= (crc & 0xFF) << (CRCMaxBits - i);
                    crc >>= 8;
                }
            }
            return normCRC;
        }

        bool GetDirect() const { return Direct; }
        bool GetReflect() const { return Ref; }
        int  GetWidth() const { return Width; }

        void LoadRegister(unsigned long val) {
            if(Ref) {
                unsigned long v = 0;
                int           i;
                for(i = 0; i < Width - 8; i += 8) {
                    v <<= 8;
                    v |= (val & 0xFF);
                    val >>= 8;
                }
                int extraBits = Width & 0x07;
                v <<= extraBits;
                v |= (val & 0xFF) >> (8 - extraBits);
                val = v;
            }
            Register ^= val;
        }

        void Process(unsigned char ch) {
            if(!Ref) {
                if(Direct) {
                    Register = Table[((Register >> (Width - 8)) ^ ch) & 0xFFL]
                               ^ (Register << 8);
                } else {
                    Register = Table[(Register >> (Width - 8)) & 0xFFL] ^
                               (Register << 8);
                    Register ^= ch;
                }
            } else {
                if(Direct) {
                    Register = Table[(Register ^ ch) & 0xFFL] ^
                               (Register >> 8);
                } else {
                    Register = Table[Register & 0xFFL] ^ (Register >> 8);
                    Register ^= ch << (Width - 8);
                }
            }
        }

        void Process(unsigned char *block, int block_length) {
            for(int i = 0; i < block_length; i++) {
                Process(*block++);
            }
        }

        // Un-comment the following version if no member templates
        ///  void Process( unsigned char* first, unsigned char* last )
        ///   {
        ///   while( first != last )
        ///    {
        ///    Process( *first++ );
        ///    }
        ///   }
        // Comment out the following version if no member templates
        template<class InIter>
        void Process(InIter first, InIter last) {
            while(first != last) {
                Process(*first);
                ++first;
            }
        }

        // Process 'count' bits from 'bits'. if 'Ref' is false reads
        // starting from MSB of 'bits'. If 'Ref' is true starts from
        // LSB
        void ProcessBits(unsigned char bits, int count) {
            if(!Ref) {
                if(Direct) {
                    Register = Table[((Register >> (Width - count)) ^
                                      (bits >> (8 - count))) & (0xFF >> (8 - count))] ^
                               (Register << count);
                } else {
                    Register = Table[(Register >> (Width - count)) &
                                     (0xFF >> (8 - count))] ^ (Register << count);
                    Register ^= bits >> (8 - count);
                }
            } else {
                if(Direct) {
                    Register = Table[((Register ^ bits) & (0xFF >> (8 - count)))
                                     << (8 - count)] ^ (Register >> count);
                } else {
                    Register = Table[(Register & (0xFF >> (8 - count))) <<
                                     (8 - count)] ^ (Register >> count);
                    Register ^= bits << (Width - count);
                }
            }
        }

        void Reset() {
            Register = Init;
        }

        void Write(std::ostream &os) const {
            unsigned long ncrc = GetNormalCRC();
            for(int i = 0; i < Width; i += 8) {
                unsigned char byte = (unsigned char) (ncrc >> (CRCMaxBits - i - 8));
                os << byte;
            }
        }
    };

    template<int Width, unsigned long Poly, unsigned long Init,
        unsigned long XOrOut, bool Ref, bool Direct>
    const CRCGenerator<Width, Poly, Init, XOrOut, Ref, Direct>::CRCTable
    CRCGenerator<Width, Poly, Init, XOrOut, Ref, Direct>::Table;

    template<int Width, unsigned long Poly, unsigned long Init,
        unsigned long XOrOut, bool Ref, bool Direct>
    std::ostream &operator<<(std::ostream &                                        os,
                             CRCGenerator<Width, Poly, Init, XOrOut, Ref, Direct> &crc) {
        crc.Write(os);
        return os;
    }
};
#endif // __CRC_H
