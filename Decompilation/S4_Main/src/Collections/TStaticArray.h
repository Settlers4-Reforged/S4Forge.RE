#ifndef TSTATICARRAY_H
#define TSTATICARRAY_H

template <typename T, int MAX_SIZE>
class TStaticArray
{
public:
    T &operator[](int index)
    {
        return this->m_aData[index];
    }

    const T &operator[](int index) const
    {
        return this->m_aData[index];
    }

    operator T *()
    {
        return this->m_aData;
    }

    operator const T *() const
    {
        return this->m_aData;
    }

    int Size() const
    {
        return this->m_iSize;
    }

    void Init()
    {
        this->m_iSize = 0;
    }

    int FindEntry(const T *entry) const
    {
        for (int i = 0; i < this->m_iSize; ++i)
        {
            if (this->m_aData[i] == *entry)
            {
                return i;
            }
        }
        return -1;
    }

    void PushBack(const T *entry)
    {
        if (this->m_iSize >= MAX_SIZE && BBSupportDbgReport(2, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\Misc\\Templates.h", 154, "m_iSize < MAX_SIZE") == 1)
        {
            __debugbreak();
        }

        this->m_aData[this->m_iSize++] = *entry;
    }

    void RemoveIndex(int _iIndex)
    {
        if ((_iIndex >= (signed int)this->m_iSize || _iIndex < 0) && BBSupportDbgReport(2, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\Misc\\Templates.h", 209, "(_iIndex >= 0) & (_iIndex < m_iSize)") == 1)
        {
            __debugbreak();
        }

        if (_iIndex < --this->m_iSize)
        {
            // This here breaks pointers to data
            this->m_aData[_iIndex] = this->m_aData[this->m_iSize];
        }
    }

    bool RemoveEntry(const T *entry)
    {
        int index = this->FindEntry(entry);
        if (index < 0)
            return false;

        this->RemoveIndex(index);
        return true;
    }

    void PopBack(const T *unused)
    {
        if (this->m_iSize <= 0 && BBSupportDbgReport(2, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\Misc\\Templates.h", 161, "m_iSize > 0") == 1)
        {
            __debugbreak();
        }
        --this->m_iSize;
    }

private:
    int m_iSize = 0;
    T m_aData[MAX_SIZE];
};

#endif // TSTATICARRAY_H