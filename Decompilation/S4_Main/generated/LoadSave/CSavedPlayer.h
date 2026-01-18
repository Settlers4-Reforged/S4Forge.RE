#ifndef CSAVEDPLAYER_H
#define CSAVEDPLAYER_H

#include "defines.h"

class CSavedPlayer {
public:
    // address=[0x13eb720]
    void  Load(class IS4Chunk & a2);

    // address=[0x13eb7f0]
    void  Save(class IS4Chunk & a2);

};


#endif // CSAVEDPLAYER_H
