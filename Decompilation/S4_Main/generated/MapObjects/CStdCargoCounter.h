#ifndef CSTDCARGOCOUNTER_H
#define CSTDCARGOCOUNTER_H

class CStdCargoCounter : public ICargoCounter {
public:
    // address=[0x15a3ad0]
    void  Clear(void);

    // address=[0x15a3af0]
    virtual void  CountEntity(int,int);

    // address=[0x160d8f0]
     CStdCargoCounter(void);

};


#endif // CSTDCARGOCOUNTER_H
