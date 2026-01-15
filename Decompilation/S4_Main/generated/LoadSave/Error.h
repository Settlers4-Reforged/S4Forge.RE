#ifndef CPERSISTENCE_ERROR_H
#define CPERSISTENCE_ERROR_H

namespace CPersistence {

class Error {
public:
    // address=[0x13f2550]
     Error(class CPersistence::Error const &);

    // address=[0x13f2570]
     Error(void);

    // Type information members
private:
    struct ErrorVtbl * lpVtbl;

};

} // namespace CPersistence

#endif // CPERSISTENCE_ERROR_H
