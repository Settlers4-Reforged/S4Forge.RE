#ifndef SPOINT_H
#define SPOINT_H

class SPoint {
public:
    // address=[0x15ddb00]
    struct SPoint &  operator=(struct SPoint8 const &);

    // address=[0x15ddb40]
    bool  operator==(struct SPoint const &)const;

    // address=[0x15ddbb0]
    int  operator*(struct SPoint const &)const;

    // address=[0x15ddce0]
    int  X(void)const;

    // address=[0x15ddd00]
    int  Y(void)const;

    // address=[0x15ddd20]
    struct SPoint &  Zero(void);

};


#endif // SPOINT_H
