#ifndef IAI_MODULE_H
#define IAI_MODULE_H

#include "defines.h"

class IAI_Module {
public:
    // address=[0x2f3ced0]
     IAI_Module(void);

    // address=[0x2f3cfc0]
     ~IAI_Module(void);

    // address=[0x2f3d040]
    void  NewSolutionEdge(int a2, int a3);

    // address=[0x2f3d0e0]
    class CSolutionTree *  Problem(int a2, int a3, int a4, int a5, int a6);

    // address=[0x2f3d230]
    void  Execute(class CSolutionTree * a2);

    // address=[0x2f3d250]
    bool  checkSolutionForRepeating(int a2);

    // address=[0x2f3d2b0]
    bool  checkSolutionForExactRepeating(int a2, class CParam * a3);

    // address=[0x2f3d320]
    bool  checkSolutionForSpecialRepeating(int a2, class CParam * a3, int a4, int a5, int a6, int a7);

    // address=[0x2f3d3e0]
    void  SetOptimierung(class COptimizeOptions * a1, int a2, int a3);

    // address=[0x2f3d400]
    void  SetHorizont(class COptimizeOptions * a2, int a3);

    // address=[0x2f3d420]
    void  SetPrioritaet(class COptimizeOptions * a1, int a2);

    // address=[0x2f3d440]
    void  SetMaxSolution(class COptimizeOptions * a2, int a3);

private:
    // address=[0x2f3d460]
    class CSolutionTree *  ProblemSolve(int a2, class CParam * a3, class COptimizeOptions * a4);

    // address=[0x2f3db10]
    class CSolutionTree *  GetBestSolution(class CSolutionSet * a2, class COptimizeOptions * a3);

    // address=[0x2f3dfd0]
    class CSolutionTree *  TryImportSolution(int a2, class CParam * a3);

    // address=[0x2f3e050]
    void  DeleteHistory(void);

    // address=[0x2f3e100]
    void  NewSolutionInHistory(int a2, class CParam * a3);

    // address=[0x2f3e190]
    void  NewSolutionInHistory(class CSolutionTree * a2);

    // address=[0x2f3e2d0]
    class CDynList *  CloneHistorie(class CDynList *);

    // address=[0x2f3e3e0]
    double  ValuationSubSolution(class CSolutionTree * a2, int a3, int a4);

    // address=[0x2f3e550]
    void  Netzplan_ausgeben(void);

    // address=[0x2f3e5a0]
    class CHistorySolution *  gleiche_loesung_suchen(int a2, class CParam * a3);

    // address=[0x2f3e600]
    void  PreExecuteSolution(class CSolutionTree * a2);

    // address=[0x2f3e6c0]
    void  ExecuteSolution(class CSolutionTree * a2);

    // address=[0x2f3e780]
    void  t(int a2);

    // address=[0x2f3e7c0]
    void  t(void);

};


#endif // IAI_MODULE_H
