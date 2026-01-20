#ifndef CEVN_WINDOW_H
#define CEVN_WINDOW_H

#include "defines.h"
#include "CEvn_Event.h"

class CEvn_Window : public CEvn_Event
{
public:
    // address=[0x1355090]
    CEvn_Window(struct HWND *a2, unsigned int a3, unsigned int a4, long a5);

    // address=[0x1355160]
    virtual ~CEvn_Window(void) = default;

    // Type information members
public:
    struct HWND *m_hWnd;
};

#endif // CEVN_WINDOW_H
