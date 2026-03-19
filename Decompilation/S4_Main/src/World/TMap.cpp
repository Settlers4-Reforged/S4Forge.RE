#include "TMap.h"

#include "CBB/CBBSupport.h"
#include "LoadSave/CMapFile.h"


template<typename T>
void TMap<T>::Done() {
    delete m_pData;
}

template<typename T>
void TMap<T>::Init(int _iWidth) {
    Done();
    m_pData = new T[_iWidth * _iWidth];
    memset(m_pData, 0, _iWidth * _iWidth * sizeof(T));
}


template<typename T>
void TMap<T>::LoadMap(class S4::CMapFile &_rMapFile, int _iChunkId, int _iWidth) {
    int         v4 = 0;
    void const *pChunk = _rMapFile.LoadChunk(_iChunkId, 0, v4, 0);
    BB_ASSERT(pChunk != nullptr);

    memcpy(m_pData, pChunk, _iWidth * _iWidth * sizeof(T));
    _rMapFile.CloseChunk(_iChunkId, 0);
}
