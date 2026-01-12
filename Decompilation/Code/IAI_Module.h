#ifndef IAI_MODULE_H
#define IAI_MODULE_H

class IAI_Module {
public:
    // address=[0x2f3ced0]
     IAI_Module(void);

    // address=[0x2f3cfc0]
     ~IAI_Module(void);

    // address=[0x2f3d040]
    void  NewSolutionEdge(int,int);

    // address=[0x2f3d0e0]
    class CSolutionTree *  Problem(int,int,int,int,int);

    // address=[0x2f3d230]
    void  Execute(class CSolutionTree *);

    // address=[0x2f3d250]
    bool  checkSolutionForRepeating(int);

    // address=[0x2f3d2b0]
    bool  checkSolutionForExactRepeating(int,class CParam *);

    // address=[0x2f3d320]
    bool  checkSolutionForSpecialRepeating(int,class CParam *,int,int,int,int);

    // address=[0x2f3d3e0]
    void  SetOptimierung(class COptimizeOptions *,int,int);

    // address=[0x2f3d400]
    void  SetHorizont(class COptimizeOptions *,int);

    // address=[0x2f3d420]
    void  SetPrioritaet(class COptimizeOptions *,int);

    // address=[0x2f3d440]
    void  SetMaxSolution(class COptimizeOptions *,int);

private:
    // address=[0x2f3d460]
    class CSolutionTree *  ProblemSolve(int,class CParam *,class COptimizeOptions *);

    // address=[0x2f3db10]
    class CSolutionTree *  GetBestSolution(class CSolutionSet *,class COptimizeOptions *);

    // address=[0x2f3dfd0]
    class CSolutionTree *  TryImportSolution(int,class CParam *);

    // address=[0x2f3e050]
    void  DeleteHistory(void);

    // address=[0x2f3e100]
    void  NewSolutionInHistory(int,class CParam *);

    // address=[0x2f3e190]
    void  NewSolutionInHistory(class CSolutionTree *);

    // address=[0x2f3e2d0]
    class CDynList *  CloneHistorie(class CDynList *);

    // address=[0x2f3e3e0]
    double  ValuationSubSolution(class CSolutionTree *,int,int);

    // address=[0x2f3e550]
    void  Netzplan_ausgeben(void);

    // address=[0x2f3e5a0]
    class CHistorySolution *  gleiche_loesung_suchen(int,class CParam *);

    // address=[0x2f3e600]
    void  PreExecuteSolution(class CSolutionTree *);

    // address=[0x2f3e6c0]
    void  ExecuteSolution(class CSolutionTree *);

    // address=[0x2f3e780]
    void  t(int);

    // address=[0x2f3e7c0]
    void  t(void);

};


#endif // IAI_MODULE_H
