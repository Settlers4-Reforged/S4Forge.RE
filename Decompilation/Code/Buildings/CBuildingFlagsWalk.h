#ifndef CBUILDINGFLAGSWALK_H
#define CBUILDINGFLAGSWALK_H

class CBuildingFlagsWalk {
public:
    // address=[0x14eaf90]
     CBuildingFlagsWalk(int,int,int,int,class std::vector<unsigned int,class std::allocator<unsigned int> > const &);

    // address=[0x14eb380]
    int  CurrentX(void)const;

    // address=[0x14eb3a0]
    int  CurrentY(void)const;

    // address=[0x14eb430]
    void  Init(void);

    // address=[0x14eb5b0]
    bool  NextPosition(void);

};


#endif // CBUILDINGFLAGSWALK_H
