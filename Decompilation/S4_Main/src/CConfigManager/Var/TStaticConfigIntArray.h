#ifndef TSTATICCONFIGINTARRAYBASE_H
#define TSTATICCONFIGINTARRAYBASE_H

#include "CStaticConfigVar.h"

template<int S>
class TStaticConfigIntArrayBase : CStaticConfigVar {
protected:
    TStaticConfigIntArrayBase(char const *a2, char const *a3);

public:
    // address=[0x12fd1a0]
    virtual int *GetIntArray(void);

    // address=[0x12fd1b0]
    virtual int const *GetIntArray(void) const;

protected:
    int m_aData[S];
};

template<int S>
class TStaticConfigIntArray : TStaticConfigIntArrayBase<S> {
public:
    template<typename... Args,
        typename = std::enable_if_t<sizeof...(Args) == S> >
    constexpr TStaticConfigIntArray(char const *a2, char const *a3, Args... args)
        : TStaticConfigIntArrayBase<S>(a2, a3) {
        // Cant directly assign to m_aData, no constructor known there and this is the best way without explicit declaration
        int tmp[S] = {static_cast<int>(args)...};

        for(std::size_t i = 0; i < S; ++i) {
            this->m_aData[i] = tmp[i];
        }
    }
};


#endif //TSTATICCONFIGINTARRAYBASE_H
