#ifndef TMAP_H
#define TMAP_H

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

    T *m_pData;
};


#endif //TMAP_H
