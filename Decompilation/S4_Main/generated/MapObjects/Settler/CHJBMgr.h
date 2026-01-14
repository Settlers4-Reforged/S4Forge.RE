#ifndef CHJBMGR_H
#define CHJBMGR_H

class CHJBMgr : public IHJBMgr {
public:
    // address=[0x1574510]
    virtual bool  LocalLoadHJBGfxFileIfNecessary(void);

    // address=[0x15745a0]
    virtual bool  StaticCheckHJBCommand(char const *);

    // address=[0x1574630]
    virtual bool  StaticCheckHJBPlayerName(std::wstring const &);

    // address=[0x1574690]
    virtual void  ProcessHJBRequest(int);

    // address=[0x1574720]
    virtual void  ProcessHJBAcknowledgement(int,int);

    // address=[0x15748b0]
     CHJBMgr(void);

protected:
    // address=[0x1574820]
    virtual void  InitHJBManager(void);

    // address=[0x1574850]
    virtual bool  LocalIsHJBAllowedEx(void);

    // address=[0x15748f0]
    void  ActivateHJB(int);

    // address=[0x1574960]
    bool  CheckHJBDatFile(void);

    // address=[0x1574d90]
    void  ClearRequest(void);

};


#endif // CHJBMGR_H
