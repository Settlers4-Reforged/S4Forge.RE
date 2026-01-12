#ifndef REPLICATOR_H
#define REPLICATOR_H

class Replicator {
public:
    // address=[0x30811e0]
     Replicator(void);

    // address=[0x30819c0]
    class DName  operator[](int)const;

    // address=[0x3082320]
    class Replicator &  operator+=(class DName const &);

    // address=[0x308cd80]
    int  isFull(void)const;

};


#endif // REPLICATOR_H
