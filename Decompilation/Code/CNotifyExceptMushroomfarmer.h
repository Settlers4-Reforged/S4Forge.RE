#ifndef CNOTIFYEXCEPTMUSHROOMFARMER_H
#define CNOTIFYEXCEPTMUSHROOMFARMER_H

class CNotifyExceptMushroomfarmer : public INotifyFilter {
public:
    // address=[0x1508120]
     CNotifyExceptMushroomfarmer(void);

    // address=[0x1508190]
    virtual bool  NotifyEntity(class IEntity const &);

};


#endif // CNOTIFYEXCEPTMUSHROOMFARMER_H
