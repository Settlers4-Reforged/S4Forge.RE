#ifndef TMAP_H
#define TMAP_H

#include "defines.h"

namespace S4 {
    class CMapFile;
}

template<typename T>
class TMap {
public:
    void Done(void);

    void Init(int _iWidth);

    // address=[0x16A7240]
    void LoadMap(S4::CMapFile &, int, int);

    // address=[0x016A7580]
    void SaveMap(S4::CMapFile &, int, int);

    T *m_pData;
};

template<typename T>
class TSparseMap {
public:
    TSparseMap(unsigned int, unsigned int, T);

    // 16A7410
    bool LoadMap(S4::CMapFile &, int);

    // 16A7670
    bool SaveMap(class S4::CMapFile &, int);

    // 1460800
    void Set(unsigned int, unsigned int, T const &);

    // 01460510
    T Get(unsigned int, unsigned int);

    // 01460380
    void Clear(void);

    void SetNewLine(int);

    // 016A6EC0
    T GetByX(int);

    struct TNode {
        int    m_iHeight;
        TNode *m_pNextNode;
        T      m_iValue;
    };

private:
    // 016A6CF0
    void Destruct(void);

    // 16A6B60
    void Construct(void);

    // 1460700
    bool IsValidCoordinate(unsigned int, unsigned int) const;

    struct SSaveData {
    public:
        bool IsBufferEnd(void) const;

        void SetAsBufferEnd(void);

    protected:
        T   m_iData;
        int m_iX = 0;
        int m_iY = 0;
    };

    static_assert(sizeof(SSaveData) == 12);


    std::vector<TNode *> m_vNodes;
    int                  m_iNewLine;
    int                  m_iHeight;
    int                  m_iWidth;
    int                  m_uSetNodes;
    T                    m_iDefault;
    // BYTE                 unk_21;
    // BYTE                 unk_22;
    // BYTE                 unk_23;
};


#endif //TMAP_H
