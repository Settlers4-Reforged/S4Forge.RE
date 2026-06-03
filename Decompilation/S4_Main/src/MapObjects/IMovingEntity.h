#ifndef IMOVINGENTITY_H
#define IMOVINGENTITY_H

#include "IAnimatedEntity.h"
#include "defines.h"

#include <memory>

class IMovingEntity : public IAnimatedEntity {
  public:
    // address=[0x130eb80]
    class CEntityTask const &GetActualTask(void) const;

    // address=[0x130f500]
    class CWalking *Walking(void);

    // address=[0x1351ad0]
    int Direction(void) const;

    // address=[0x1351af0]
    int Distance(void) const;

    // address=[0x1460610]
    int GetJobPart(void) const;

    // address=[0x1470a80]
    bool IsFree(int a2);

    // address=[0x14d86e0]
    virtual bool IsUnEmployed(void) const;

    // address=[0x14e2fd0]
    void IncToDoListIter(void);

    // address=[0x150b590]
    void SetDisplacementCosts(int a2);

    // address=[0x1513b10]
    void SetDirection(int a2);

    // address=[0x15590a0]
    IMovingEntity(int id);

    // address=[0x1559130]
    virtual ~IMovingEntity(void);

    // address=[0x1559170]
    void WalkToXY(int a2, int a3);

    // address=[0x15591b0]
    virtual void NewToDoList(std::list<CEntityTask> *_toDo, int _iSize);

    // address=[0x1559260]
    void ResetToDoList(void);

    // address=[0x1559340]
    void SetToDoList(std::list<CEntityTask> *_pToDo);

    // address=[0x1559400]
    bool IsNotOccupied(int a2);

    // address=[0x1559430]
    bool IsNotBlocked(int a2);

    // address=[0x1563870]
    bool IsEndIter(void);

    // address=[0x1563980]
    void SetDistance(int a2);

    // address=[0x1568790]
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>> const GetActualIter(void) const;

    // address=[0x15d6230]
    int DisplacementCosts(void) const;

  protected:
    // address=[0x14d8840]
    void SetPositionAndDir(int a2, int a3);

    // address=[0x1559460]
    IMovingEntity(std::istream &_rStream);

    // address=[0x15595e0]
    virtual void Store(std::ostream &_rStream);

    // address=[0x15596c0]
    void InitDistance(void);

    // address=[0x15596e0]
    void DecDistance(unsigned int a2);

    // Type information members
  public:
    char m_iDirection;
    unsigned __int8 m_iDistance;
    unsigned __int8 m_iDisplacementCosts;
    __int16 m_iToDoSize;
    int unk_4c;
    std::unique_ptr<CWalking> m_pWalking;
    std::list<CEntityTask> *m_pToDoList;
    std::list<CEntityTask>::iterator m_cCurrentToDoItemIter;
};

#endif // IMOVINGENTITY_H
