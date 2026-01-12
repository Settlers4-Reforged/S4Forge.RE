#ifndef DNAME_H
#define DNAME_H

class DName {
public:
    // address=[0x3080430]
     DName(char const * &,char);

    // address=[0x30807a0]
     DName(class DName const &);

    // address=[0x30807d0]
     DName(char);

    // address=[0x30808e0]
     DName(class DName *);

    // address=[0x3080a60]
     DName(char const *);

    // address=[0x3080b90]
     DName(enum DNameStatus);

    // address=[0x3080cf0]
     DName(void);

    // address=[0x3080de0]
     DName(__int64);

    // address=[0x3080fc0]
     DName(unsigned __int64);

    // address=[0x30814b0]
    class DName &  operator=(class DName const &);

    // address=[0x30814e0]
    class DName &  operator=(char);

    // address=[0x30815f0]
    class DName &  operator=(class DName *);

    // address=[0x3081770]
    class DName &  operator=(char const *);

    // address=[0x3081880]
    class DName &  operator=(enum DNameStatus);

    // address=[0x3081e50]
    class DName  operator+(class DName const &)const;

    // address=[0x3081ea0]
    class DName  operator+(char)const;

    // address=[0x3081ef0]
    class DName  operator+(class DName *)const;

    // address=[0x3081f40]
    class DName  operator+(char const *)const;

    // address=[0x3081f90]
    class DName  operator+(enum DNameStatus)const;

    // address=[0x3081fe0]
    class DName &  operator+=(class DName const &);

    // address=[0x3082060]
    class DName &  operator+=(char);

    // address=[0x3082100]
    class DName &  operator+=(class DName *);

    // address=[0x30821e0]
    class DName &  operator+=(char const *);

    // address=[0x30822a0]
    class DName &  operator+=(enum DNameStatus);

    // address=[0x30823d0]
    class DName &  operator|=(class DName const &);

    // address=[0x30849a0]
    char *  dbGetString(void)const;

    // address=[0x3087fb0]
    char  getLastChar(void)const;

    // address=[0x308a4d0]
    char *  getString(char *,char *)const;

    // address=[0x308a530]
    char *  getString(char *,int)const;

    // address=[0x308cd00]
    int  isArray(void)const;

    // address=[0x308cd20]
    int  isComArray(void)const;

    // address=[0x308cd40]
    int  isEmpty(void)const;

    // address=[0x308cdc0]
    int  isNoTE(void)const;

    // address=[0x308cde0]
    int  isPinPtr(void)const;

    // address=[0x308ce00]
    int  isPtrRef(void)const;

    // address=[0x308ce20]
    int  isUDC(void)const;

    // address=[0x308ce70]
    int  isUDTThunk(void)const;

    // address=[0x308cec0]
    int  isVCallThunk(void)const;

    // address=[0x308cee0]
    int  isValid(void)const;

    // address=[0x308cf20]
    int  length(void)const;

    // address=[0x308d130]
    void  setIsArray(void);

    // address=[0x308d160]
    void  setIsComArray(void);

    // address=[0x308d190]
    void  setIsNoTE(void);

    // address=[0x308d1c0]
    void  setIsPinPtr(void);

    // address=[0x308d1f0]
    void  setIsUDC(void);

    // address=[0x308d230]
    void  setIsVCallThunk(void);

    // address=[0x308d260]
    class DName &  setPtrRef(void);

    // address=[0x308d290]
    enum DNameStatus  status(void)const;

private:
    // address=[0x3082540]
    void  append(class DNameNode *);

    // address=[0x3084b90]
    void  doPchar(char const *,int);

};


#endif // DNAME_H
