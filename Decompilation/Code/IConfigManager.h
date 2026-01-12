#ifndef ICONFIGMANAGER_H
#define ICONFIGMANAGER_H

class IConfigManager {
public:
    // address=[0x2eef090]
    static class IConfigManager * __cdecl CreateConfigManger(void);

    // address=[0x2ef8840]
     IConfigManager(void);

    // address=[0x2ef8cd0]
    virtual  ~IConfigManager(void);

};


#endif // ICONFIGMANAGER_H
