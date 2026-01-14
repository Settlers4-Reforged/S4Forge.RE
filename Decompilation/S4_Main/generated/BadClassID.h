#ifndef CPERSISTENCE_BADCLASSID_H
#define CPERSISTENCE_BADCLASSID_H

namespace CPersistence {

class BadClassID {
public:
    // address=[0x13f24f0]
     BadClassID(class CPersistence::BadClassID const &);

    // address=[0x13f2520]
     BadClassID(void);

    // address=[0x13f55e0]
    virtual char const *  What(void)const;

};

} // namespace CPersistence

#endif // CPERSISTENCE_BADCLASSID_H
