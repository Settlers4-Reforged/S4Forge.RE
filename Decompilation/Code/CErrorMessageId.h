#ifndef CERRORMESSAGEID_H
#define CERRORMESSAGEID_H

class CErrorMessageId {
public:
    // address=[0x14810b0]
     CErrorMessageId(char const *);

    // address=[0x1481160]
     CErrorMessageId(class CErrorMessageId const &);

    // address=[0x1481180]
    int  GetId(void)const;

};


#endif // CERRORMESSAGEID_H
