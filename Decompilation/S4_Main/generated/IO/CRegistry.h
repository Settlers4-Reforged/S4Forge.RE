#ifndef CREGISTRY_H
#define CREGISTRY_H

class CRegistry : public IRegistry {
public:
    // address=[0x149aa80]
    virtual bool  ExistsHLMKey(char const *);

    // address=[0x149ab00]
     CRegistry(void);

};


#endif // CREGISTRY_H
