#ifndef CPLAYLIST_H
#define CPLAYLIST_H

class CPlaylist {
public:
    // address=[0x2fd8e60]
     CPlaylist(void);

    // address=[0x2fd8ec0]
    virtual  ~CPlaylist(void);

    // address=[0x2fd8f20]
    void  Init(int);

    // address=[0x2fd8f60]
    void  AddTitle(std::string const *,int);

    // address=[0x2fd8fd0]
    void  TitleEnded(void);

    // address=[0x2fd9050]
    int  GetStreamPos(void);

    // address=[0x2fd9070]
    void  SetStreamPos(int);

    // address=[0x2fd9090]
    void  StoreStreamPos(void);

    // address=[0x2fd90b0]
    void  ResumeOnLastPos(void);

    // address=[0x2fd90d0]
    int  GetPlayingTitleNum(void);

    // address=[0x2fd90f0]
    char const *  GetTitle(int);

    // address=[0x2fd9130]
    char const *  GetActiveTitle(void);

    // address=[0x2fd9170]
    void  SetTrackID(unsigned int);

    // address=[0x2fd9190]
    unsigned int  GetTrackID(void);

    // address=[0x2fd91b0]
    void  SetTitle(int);

    // address=[0x2fd91e0]
    void  SetHandle(struct _STREAM *);

    // address=[0x2fd9200]
    int  GetFadeInTime(int);

    // address=[0x2fd9240]
    void  SkipTitle(void);

private:
    // address=[0x2fd8d30]
    void  FreeMemory(void);

};


#endif // CPLAYLIST_H
