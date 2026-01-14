#ifndef CEVN_WINDOW_H
#define CEVN_WINDOW_H

class CEvn_Window : public CEvn_Event {
public:
    // address=[0x1355090]
     CEvn_Window(struct HWND__ *,unsigned int,unsigned int,long);

    // address=[0x1355160]
    virtual  ~CEvn_Window(void);

};


#endif // CEVN_WINDOW_H
