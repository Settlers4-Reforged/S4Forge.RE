#ifndef CTRACE_H
#define CTRACE_H

class CTrace {
public:
    // address=[0x14d3520]
     CTrace(char const *);

    // address=[0x14d3540]
     CTrace(class CTrace const &);

    // address=[0x14d3560]
    virtual  ~CTrace(void);

    // address=[0x14d3580]
    class CTrace &  operator=(class CTrace const &);

    // address=[0x14d35a0]
    static void __cdecl Print(char const *,...);

    // address=[0x14d3610]
    static void __cdecl TextEinfuegen(char const *,...);

private:
    // address=[0x14d3680]
    void  TraceInitObject(char const *);

    // address=[0x14d36e0]
    void  TracePrintHeader(void);

};


#endif // CTRACE_H
