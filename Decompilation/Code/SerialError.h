#ifndef CPERSISTENCE_SERIALERROR_H
#define CPERSISTENCE_SERIALERROR_H

namespace CPersistence {

class SerialError {
public:
    // address=[0x13f2590]
     SerialError(class CPersistence::SerialError const &);

    // address=[0x13f25c0]
     SerialError(void);

    // address=[0x13f5600]
    virtual char const *  What(void)const;

};

} // namespace CPersistence

#endif // CPERSISTENCE_SERIALERROR_H
