#ifndef CAIPLAYEREVALUATION_H
#define CAIPLAYEREVALUATION_H

class CAIPlayerEvaluation {
public:
    // address=[0x1310d40]
    void  Clear(void);

    // address=[0x1310e30]
    void  EvaluatePlayer(int);

    // address=[0x1310ea0]
    void  DbgPrint(void);

protected:
    // address=[0x1310f40]
    void  EvaluateGoods(int);

    // address=[0x1311060]
    void  EvaluateWarriors(int);

    // address=[0x1311400]
    void  EvaluateBuildings(int);

};


#endif // CAIPLAYEREVALUATION_H
