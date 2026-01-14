#ifndef CGFXMANAGER_H
#define CGFXMANAGER_H

class CGfxManager {
public:
    // address=[0x1361470]
     CGfxManager(bool,bool,bool);

    // address=[0x1361660]
     ~CGfxManager(void);

    // address=[0x13616d0]
    bool  OpenGFXFiles(void);

    // address=[0x13618d0]
    virtual void  GetGuiGfxInfo(struct SGfxObjectInfo &,unsigned int);

    // address=[0x13619d0]
    virtual void  GetUserLogoGfxInfo(struct SGfxObjectInfo &,unsigned int,unsigned int);

    // address=[0x1361af0]
    void  GetBuildingGfxInfo(struct SGfxObjectInfo &,unsigned int,unsigned int,unsigned int,struct SBuildingFX *);

    // address=[0x1361f10]
    unsigned int  GetBuildingFirstJob(unsigned int,unsigned int);

    // address=[0x1361f80]
    void  GetObjectGfxInfo(struct SGfxObjectInfo &,unsigned int,unsigned int,unsigned int);

    // address=[0x13621a0]
    unsigned int  GetObjectFirstJob(unsigned int);

    // address=[0x1362210]
    void  GetSettlerGfxInfo(struct SGfxObjectInfo &,unsigned int,unsigned int,unsigned int,unsigned int);

    // address=[0x1362410]
    unsigned int  GetSettlerFirstJob(unsigned int,unsigned int);

    // address=[0x13624d0]
    void  GetPatchSettlerGfxInfo(struct SGfxPatchObject &,unsigned int,unsigned int,unsigned int,unsigned int);

    // address=[0x1362620]
    void  GetPileGfxInfo(struct SGfxObjectInfo &,unsigned int,unsigned int,unsigned int);

    // address=[0x1362810]
    void  GetPatchPileGfxInfo(struct SGfxPatchObject &,unsigned int,unsigned int,unsigned int);

    // address=[0x1362a00]
    void  GetVehicleGfxInfo(struct SGfxObjectInfo &,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int);

    // address=[0x1362d50]
    unsigned int  GetVehicleFirstJob(unsigned int,unsigned int);

    // address=[0x1362dc0]
    void  GetAnimalGfxInfo(struct SGfxObjectInfo &,unsigned int,unsigned int,unsigned int);

    // address=[0x1362fc0]
    unsigned int  GetAnimalFirstJob(unsigned int);

    // address=[0x1363030]
    void  GetEffectGfxInfo(struct SGfxObjectInfo &,unsigned int,unsigned int,unsigned int);

    // address=[0x13632c0]
    void  GetAccessoryGfxInfo(struct SGfxObjectInfo &,unsigned int);

    // address=[0x1363410]
    unsigned int  GetSettlerJobFrameCount(unsigned int,unsigned int,unsigned int);

    // address=[0x1363440]
    unsigned int  GetObjectFrameCount(unsigned int);

    // address=[0x1363470]
    unsigned int  GetPileFrameCount(unsigned int);

    // address=[0x13634a0]
    unsigned int  GetVehicleFrameCount(unsigned int,unsigned int);

    // address=[0x13634e0]
    unsigned int  GetAnimalFrameCount(unsigned int);

    // address=[0x1363510]
    unsigned int  GetEffectFrameCount(unsigned int);

    // address=[0x13635a0]
    unsigned int  GetBuildingJobFrameCount(unsigned int,unsigned int);

    // address=[0x13635d0]
    void  GetBoundingBox(struct SGfxBoundingBox &,unsigned int,unsigned int,unsigned int);

    // address=[0x13637e0]
    bool  EnableGfxFile(unsigned int,int,bool,unsigned int);

    // address=[0x1363b20]
    static void * __cdecl Reload(int,bool,bool);

    // address=[0x1363d10]
    unsigned int  GetJobFrameCount(unsigned int,unsigned int,unsigned int);

    // address=[0x13640d0]
    bool  IsDirectionAvailable(unsigned int,unsigned int,unsigned int);

    // address=[0x1364190]
    void  GetRawGfxInfo(struct SGfxObjectInfo &,unsigned int,unsigned int,unsigned int,unsigned int);

    // address=[0x1364360]
    void  GetRawGfxInfo(struct SGfxObjectInfo &,unsigned int,unsigned int);

    // address=[0x1364430]
    bool  GetImageInfo(unsigned int,unsigned int,int &,int &,int &,int &);

    // address=[0x1364940]
    bool  GetImageInfo(unsigned int,unsigned int,int &,int &,int &);

    // address=[0x1364980]
    bool  GetJobIndices(unsigned int,unsigned int,int &,int &);

    // address=[0x1364ba0]
    void  DisableGfxFile(int);

    // address=[0x1364bc0]
    void  EnableMCD2Textures(bool);

    // address=[0x136a1e0]
    unsigned int  GetNrDirection(unsigned int);

    // address=[0x136a200]
    bool  HasSil(unsigned int);

    // address=[0x13d8be0]
    bool  IsGfxFileEnabled(int);

private:
    // address=[0x1364be0]
    bool  RemoveAllGFX(int);

    // address=[0x1364f80]
    void  ErrorMessageBox(class String);

    // address=[0x1364ff0]
    void *  LoadFile(std::wstring,unsigned long *,unsigned int);

    // address=[0x1365310]
    class CFileEx *  MapFullFile(std::wstring,unsigned int);

    // address=[0x1365750]
    bool  LoadGfxFile(unsigned int,bool,unsigned int);

    // address=[0x1365a70]
    bool  LoadGfxColorFile(unsigned int,bool,unsigned int);

    // address=[0x1365ce0]
    bool  LoadGilFile(unsigned int,unsigned int);

    // address=[0x1365f30]
    bool  LoadDilFile(unsigned int,unsigned int);

    // address=[0x1366180]
    bool  LoadJilFile(unsigned int,unsigned int);

    // address=[0x13663d0]
    bool  LoadSilFile(unsigned int,unsigned int);

    // address=[0x1366520]
    bool  LoadPilFile(unsigned int,unsigned int,bool);

    // address=[0x1366790]
    bool  LoadPalFile(unsigned int,unsigned int,bool);

    // address=[0x1366b90]
    bool  MoveAccessoriesToGfxEngine(void);

    // address=[0x1366c80]
    bool  MoveWavesToGfxEngine(void);

    // address=[0x1367b70]
    void  Debug_Check_LayerBlock(unsigned int,struct SGfxObjectInfo &);

    // address=[0x1367e50]
    void  Debug_Check_PatchLayerBlock(unsigned int,struct SGfxPatchObject &);

};


#endif // CGFXMANAGER_H
