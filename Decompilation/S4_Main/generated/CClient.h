#ifndef CCLIENT_H
#define CCLIENT_H

class CClient {
public:
    // address=[0x15b1b00]
     CClient(void);

    // address=[0x15b1b60]
     CClient(class CClient const &);

    // address=[0x15b1bd0]
     CClient(long,int,int);

    // address=[0x15b1c40]
    virtual  ~CClient(void);

    // address=[0x15b1c60]
    bool  operator==(unsigned int);

    // address=[0x15b3530]
    class CClient &  operator=(class CClient const &);

    // address=[0x15b3b30]
    long  GetIP(void);

    // address=[0x15b3b50]
    unsigned int  GetLastPingTime(void);

    // address=[0x15b3b70]
    unsigned int  GetPeerId(void);

    // address=[0x15c4df0]
    void  SetLastAckTime(unsigned int);

};


#endif // CCLIENT_H
