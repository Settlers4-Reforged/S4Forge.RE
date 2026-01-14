#ifndef CLANDSCAPECOLORPROPERTIES_H
#define CLANDSCAPECOLORPROPERTIES_H

class CLandscapeColorProperties {
public:
    // address=[0x2f8dcb0]
     CLandscapeColorProperties(void);

    // address=[0x2f8eab0]
    struct SColorEntry const &  CLandscapeColorProperties::ColorEntry(int)const;

    // address=[0x2fc5290]
    unsigned short  HiColValue(int)const;

};


#endif // CLANDSCAPECOLORPROPERTIES_H
