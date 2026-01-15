#ifndef IUNKNOWN_H
#define IUNKNOWN_H

class IUnknown {
public:
    // address=[0x2616650]
     IUnknown(void);

    // Type information members
private:
    struct IUnknownVtbl * lpVtbl;

};


#endif // IUNKNOWN_H
