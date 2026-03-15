#ifndef S4_MAIN_CAIEVENT_H
#define S4_MAIN_CAIEVENT_H

class CAIEvent {
public:
    CAIEvent(int _iType, int _iX, int _iY, int _iDark)
        : m_iType(_iType),
          m_iX(_iX),
          m_iY(_iY),
          m_iDark(_iDark) {}

private:
    int m_iType;
    int m_iX;
    int m_iY;
    int m_iDark;
};

#endif //S4_MAIN_CAIEVENT_H
