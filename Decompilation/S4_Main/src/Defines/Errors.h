//
// Created by Jonas on 28/03/2026.
//

#ifndef ERRORS_H
#define ERRORS_H

struct SErrorMessagePair {
    const char *m_uName;
    const char *m_uMessage;
};

extern SErrorMessagePair s_aErrorMessages[3];

#endif //ERRORS_H
