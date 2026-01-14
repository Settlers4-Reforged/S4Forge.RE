#ifndef CAIREGION_H
#define CAIREGION_H

class CAIRegion {
public:
    // address=[0x1311ef0]
    bool  Used(void)const;

protected:
    // address=[0x13115f0]
    void  Load(class IS4Chunk &);

    // address=[0x1311640]
    void  Save(class IS4Chunk &);

    // address=[0x1311c80]
    void  Clear(void);

    // address=[0x1311ca0]
    void  DefineRegion(int,int,int);

};


#endif // CAIREGION_H
