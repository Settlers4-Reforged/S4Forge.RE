#ifndef CTUTORIAL_H
#define CTUTORIAL_H

class CTutorial : public IEvn_Handle {
public:
    // address=[0x147d690]
    void  Init(void);

    // address=[0x147d720]
    void  Kill(void);

    // address=[0x147d780]
    void  RefreshGUIControlStatus(void);

    // address=[0x147d7a0]
    void  EnableGUIControl(int);

    // address=[0x147d7c0]
    void  DisableGUIControl(int);

    // address=[0x147d7e0]
    void  EnableAllGUIControls(void);

    // address=[0x147d800]
    void  DisableAllGUIControls(void);

    // address=[0x147d910]
    void  SetWorldTutorialCursor(int,int);

    // address=[0x147d970]
    void  DeleteWorldTutorialCursor(void);

    // address=[0x147e520]
     CTutorial(void);

    // address=[0x160d980]
    int  CurrentZoomFactor(void)const;

protected:
    // address=[0x147d9b0]
    virtual bool  OnEvent(class CEvn_Event &);

    // address=[0x147de30]
    bool  IsWarriorSelected(void);

    // address=[0x147df00]
    int  GetSelectedBuilding(void);

};


#endif // CTUTORIAL_H
