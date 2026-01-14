#ifndef CAITASKFORCEEX_H
#define CAITASKFORCEEX_H

class CAITaskForceEx : public CAITaskForce {
public:
    // address=[0x132a540]
    void  ClearWaypoints(void);

    // address=[0x132a590]
    void  PopWaypoint(void);

    // address=[0x132a600]
    bool  CheckWaypoint(void);

    // address=[0x132a6c0]
    bool  CheckDestination(void);

    // address=[0x132a840]
    bool  FindWaypoints(void);

    // address=[0x132a990]
    virtual bool  SetDestinationXY(int);

    // address=[0x132a9b0]
    virtual void  Execute(void);

    // address=[0x132ace0]
    void  InitWalk(bool);

    // address=[0x132aef0]
    void  InitGroupWalk(void);

    // address=[0x132af30]
    bool  FindSneakUpPosition(void);

    // address=[0x132b0f0]
    virtual void  Load(class IS4Chunk &);

    // address=[0x132b190]
    virtual void  Save(class IS4Chunk &);

    // address=[0x132e950]
    int  DestinationX(void)const;

    // address=[0x132e970]
    int  DestinationXY(void)const;

    // address=[0x132e990]
    int  DestinationY(void)const;

    // address=[0x132ed00]
    bool  WaypointAvailable(void)const;

    // address=[0x132ed40]
    int  WaypointX(void)const;

    // address=[0x132ed70]
    int  WaypointXY(void)const;

    // address=[0x132ed90]
    int  WaypointY(void)const;

protected:
    // address=[0x13192a0]
    virtual  ~CAITaskForceEx(void);

    // address=[0x132a140]
     CAITaskForceEx(int,enum T_AI_TASK_FORCE_CLASS,enum T_AI_TASK_FORCE_TYPE,int);

    // address=[0x132b230]
    bool  EscortInitWalk(void);

    // address=[0x132eac0]
    void  SetCommandAndClearStuff(int,int,int);

};


#endif // CAITASKFORCEEX_H
