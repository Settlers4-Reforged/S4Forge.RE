#ifndef CENDSTATISTIC_H
#define CENDSTATISTIC_H

class CEndStatistic : public CStatistic {
public:
    // address=[0x144f850]
     CEndStatistic(void);

    // address=[0x144f8e0]
    void  Clear(void);

    // address=[0x144f990]
    void  Init(void);

    // address=[0x144f9b0]
    void  Update(class CStatistic);

    // address=[0x144fb00]
    wchar_t const *  GetMapName(void);

    // address=[0x144fb20]
    std::wstring  GetPlayerName(int);

    // address=[0x144fb90]
    int  GetNumberOfPlayers(void);

    // address=[0x144fbb0]
    int  GetPlayerRace(int);

    // address=[0x144fc00]
    int  GetPlayerColor(int);

    // address=[0x144fc50]
    int  GetPlayerAlliance(int);

    // address=[0x144fca0]
    bool  IsGameWone(void);

    // address=[0x144fcc0]
    int  GetWonAlliance(void);

    // address=[0x144fce0]
    unsigned int  GetTickCounter(void);

    // address=[0x144fe20]
     ~CEndStatistic(void);

};


#endif // CENDSTATISTIC_H
