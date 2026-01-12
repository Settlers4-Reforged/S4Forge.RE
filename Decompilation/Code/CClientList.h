#ifndef CCLIENTLIST_H
#define CCLIENTLIST_H

class CClientList {
public:
    // address=[0x15b1d30]
    long  GetPlayerIP(int);

    // address=[0x15b1d60]
    unsigned int  GetPlayerPeerId(int);

    // address=[0x15b1d90]
    bool  ContainsPeerId(unsigned int);

    // address=[0x15b1e50]
    bool  Add(unsigned int,int,int);

    // address=[0x15b1f30]
    unsigned int  GetPlayerPing(unsigned int);

    // address=[0x15b1f90]
     CClientList(void);

    // address=[0x15b1fc0]
    virtual  ~CClientList(void);

    // address=[0x15b1fe0]
    int  CreateNewPlayerID(void);

    // address=[0x15b2000]
    bool  RemoveClientAt(int);

    // address=[0x15b20c0]
    bool  RemoveClientPeerId(unsigned int);

    // address=[0x15b21d0]
    bool  AllClientsReady(void);

    // address=[0x15b2220]
    void  SetClientReadyFromPeerId(unsigned int,bool);

    // address=[0x15b2320]
    int  GetClientIndexPerPeerId(unsigned int);

    // address=[0x15b3b90]
    int  GetSize(void);

    // address=[0x15c4d90]
    void  SetClientLastAck(unsigned int,unsigned int);

};


#endif // CCLIENTLIST_H
