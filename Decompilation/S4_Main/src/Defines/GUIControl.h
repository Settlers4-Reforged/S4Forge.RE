#ifndef UI_H
#define UI_H

enum T_GUI_CNTRL : unsigned __int8 {
    GUI_CNTRL_SLIDER = 0x7,
    GUI_CNTRL_SLIDER2 = 0x8,
    GUI_CNTRL_SLIDERAREA = 0x10,
    GUI_CNTRL_BUTTON = 0xD,
    GUI_CNTRL_TEXT = 0x15,
    GUI_CNTRL_RADIO = 0x3,
    GUI_CNTRL_TOOLTIP = 0xE,
    GUI_CNTRL_TOOLTIP_EXTRA = 0xF,
};

#endif // UI_H
