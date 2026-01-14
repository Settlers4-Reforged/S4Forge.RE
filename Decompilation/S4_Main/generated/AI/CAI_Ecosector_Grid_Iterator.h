#ifndef CAI_ECOSECTOR_GRID_ITERATOR_H
#define CAI_ECOSECTOR_GRID_ITERATOR_H

class CAI_Ecosector_Grid_Iterator {
public:
    // address=[0x1339930]
     CAI_Ecosector_Grid_Iterator(void);

    // address=[0x1339960]
     ~CAI_Ecosector_Grid_Iterator(void);

    // address=[0x1339970]
    void  Init(int);

    // address=[0x13399f0]
    bool  IsEnd(void);

    // address=[0x1339a10]
    int  GetNext(void);

private:
    // address=[0x1339c80]
    void  FindStartPoint(void);

    // address=[0x1339d60]
    bool  IsMyTile(int);

    // address=[0x1339fe0]
    bool  IsChecked(int,int);

    // address=[0x133a0f0]
    void  SetChecked(int,int);

};


#endif // CAI_ECOSECTOR_GRID_ITERATOR_H
