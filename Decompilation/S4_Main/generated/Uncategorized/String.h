#ifndef STRING_H
#define STRING_H

class String {
public:
    // address=[0x13512a0]
     String(std::string const &);

    // address=[0x13512d0]
     String(char const *,unsigned int);

    // address=[0x1351470]
     ~String(void);

    // address=[0x13516d0]
    class String &  operator=(class String const &);

    // address=[0x1351700]
    class String &  operator=(char const *);

    // address=[0x1352200]
    char const *  c_str(void)const;

    // address=[0x1369f20]
     String(class String const &,unsigned int,unsigned int);

    // address=[0x1369f50]
     String(void);

    // address=[0x136a1b0]
    class String &  operator+=(char const *);

};


#endif // STRING_H
