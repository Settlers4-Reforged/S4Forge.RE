#include "TStaticConfigIntArray.h"


template<int S>
TStaticConfigIntArrayBase<S>::TStaticConfigIntArrayBase(char const *a2, char const *a3) : CStaticConfigVar(a2, a3, T_CFGVAR_TYPE_INT_ARRAY, S) {}

template<int S>
int *TStaticConfigIntArrayBase<S>::GetIntArray() {
    return this->m_aData;
}

template<int S>
int const *TStaticConfigIntArrayBase<S>::GetIntArray() const {
    return this->m_aData;
}

