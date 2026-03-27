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

template<typename T>
void TMap<T>::SaveMap(S4::CMapFile &a2, int a3, int a4) {
    if(!this->m_pData)
        return;

    a2.SaveChunk(a3, 0, a4 * a4, this->m_pData, 0);
}

template<typename T>
TSparseMap<T>::TSparseMap(unsigned int _iWidth, unsigned int _iHeight, T a4) : m_vNodes() {
    this->m_iHeight = _iWidth;
    this->m_iWidth = _iHeight;
    this->m_uSetNodes = 0;
    this->m_iDefault = a4;
    this->Construct();
}

template<typename T>
bool TSparseMap<T>::LoadMap(S4::CMapFile &rMapFile, int a3) {
    this->Destruct();
    this->Construct();

    int iChunkData;

    SSaveData const *pBuffer = rMapFile.LoadChunk(a3, 0, iChunkData, 0);
    BB_ASSERT(pBuffer != nullptr)

    while(!pBuffer->IsBufferEnd()) {
        this->Set(pBuffer->m_iX, pBuffer->m_iY, pBuffer);
        ++pBuffer;
    }
    rMapFile.CloseChunk(a3, 0);
    return 1;
}

template<typename T>
bool TSparseMap<T>::SaveMap(S4::CMapFile &_rMapFile, int a3) {
    std::vector<SSaveData> vSaveData{};
    vSaveData.reserve(this->m_uSetNodes + 1);

    int iY = 0;
    for(auto &i: this->m_vNodes) {
        for(TNode *j = i->m_pNextNode; j->m_pNextNode; j = j->m_pNextNode) {
            SSaveData saveData{};
            saveData.m_iX = j->m_iHeight;
            saveData.m_iY = iY;
            saveData.m_iData = j->m_iValue;
            vSaveData.push_back(saveData);
        }
        iY++;
    }

    vSaveData.emplace_back().SetAsBufferEnd();
    _rMapFile.SaveChunk(a3, 0, sizeof(SSaveData) * vSaveData.size(), vSaveData.data(), false);
    return true;
}

template<typename T>
void TSparseMap<T>::Set(unsigned int _uX, unsigned int _uY, T const &_uValue) {
    BB_ASSERT(IsValidCoordinate(_uX, _uY))
    if(!this->IsValidCoordinate(_uX, _uY)) return;

    TSparseMap::TNode *pTargetNode = this->m_vNodes[_uY];
    for(TSparseMap::TNode *i = this->m_vNodes[_uY]->m_pNextNode; i->m_iHeight < _uX; i = i->m_pNextNode)
        pTargetNode = i;

    TNode *v4 = new TNode();
    if(!v4) return; // OOM - should not happen on good days
    v4->m_iValue = _uValue;
    v4->m_iHeight = _uX;
    v4->m_pNextNode = pTargetNode->m_pNextNode;
    pTargetNode->m_pNextNode = v4;
    ++this->m_uSetNodes;
}

template<typename T>
T TSparseMap<T>::Get(unsigned int _uX, unsigned int _uY) {
    TSparseMap::TNode *i; // [esp+4h] [ebp-4h]

    BB_ASSERT(IsValidCoordinate(_uX, _uY))

    if(!IsValidCoordinate(_uX, _uY))
        return this->m_iDefault;

    for(i = this->m_vNodes[_uY]->m_pNextNode; i->m_iHeight < _uX; i = i->m_pNextNode);
    if(i->m_iHeight == _uX)
        return i->m_iValue;
    else
        return this->m_iDefault;
}

template<typename T>
void TSparseMap<T>::Clear() {
    for(unsigned int i = 0; i < this->m_iWidth; ++i) {
        if(this->m_vNodes[i]) {
            TNode *pTempNode = this->m_vNodes[i]->m_pNextNode;
            BB_ASSERT(pTempNode!=NULL)

            while(pTempNode->m_pNextNode) {
                pTempNode->m_pNextNode = pTempNode->m_pNextNode;
                TNode *v2 = pTempNode;
                delete pTempNode;
                pTempNode = v2->m_pNextNode;
            }
        }
    }
    this->m_uSetNodes = 0;
}

template<typename T>
void TSparseMap<T>::SetNewLine(int a2) {
    this->m_iNewLine = a2;
}

template<typename T>
T TSparseMap<T>::GetByX(int _uX) {
    return this->Get(_uX, this->m_iNewLine);
}

template<typename T>
void TSparseMap<T>::Destruct() {
    for(unsigned int a1 = 0; a1 < this->m_iWidth; ++a1) {
        if(*this->m_vNodes[a1]) {
            TNode *m_pNextNode = this->m_vNodes[a1]->m_pNextNode;
            TNode *v1 = this->m_vNodes[a1];
            delete v1;

            do {
                TNode *v2 = m_pNextNode;
                m_pNextNode = m_pNextNode->m_pNextNode;
                delete v2;
            } while(m_pNextNode);
        }
    }
    this->m_uSetNodes = 0;
}

template<typename T>
void TSparseMap<T>::Construct() {
    m_vNodes.resize(this->m_iWidth);
    for(unsigned int a1 = 0; a1 < this->m_iWidth; ++a1) {
        TNode *v3 = new TNode();
        v3->m_iHeight = this->m_iHeight;
        this->m_vNodes[a1] = v3;
        TNode *v1 = new TNode();
        v1->m_iValue = 0;
        v1->m_iHeight = this->m_iHeight;
        v1->m_pNextNode = 0;
        this->m_vNodes[a1]->m_pNextNode = v1;
    }
}

template<typename T>
bool TSparseMap<T>::IsValidCoordinate(unsigned int a2, unsigned int a3) const {
    return a2 < this->m_iHeight && a3 < this->m_iWidth;
}

template<typename T>
bool TSparseMap<T>::SSaveData::IsBufferEnd() const {
    return !this->m_iData && this->m_iX == -1 && this->m_iY == -1;
}

template<typename T>
void TSparseMap<T>::SSaveData::SetAsBufferEnd() {
    this->m_iData = 0;
    this->m_iX = -1;
    this->m_iY = -1;
}
