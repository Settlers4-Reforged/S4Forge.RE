#ifndef CGFXMANAGER_H
#define CGFXMANAGER_H

#include "defines.h"

class CGfxManager {
public:
    // address=[0x1361470]
     CGfxManager(bool a2, bool a3, bool a4);

    // address=[0x1361660]
     ~CGfxManager(void);

    // address=[0x13616d0]
    bool  OpenGFXFiles(void);

    // address=[0x13618d0]
    virtual void  GetGuiGfxInfo(struct SGfxObjectInfo & a2, unsigned int a3);

    // address=[0x13619d0]
    virtual void  GetUserLogoGfxInfo(struct SGfxObjectInfo & userLogoGfxInfo, unsigned int logoNr, unsigned int _iDir);

    // address=[0x1361af0]
    void  GetBuildingGfxInfo(struct SGfxObjectInfo & a2, unsigned int _iRace, unsigned int a4, unsigned int _iFlags, struct SBuildingFX * _argBuildingFX);

    // address=[0x1361f10]
    unsigned int  GetBuildingFirstJob(unsigned int _iRace, unsigned int a3);

    // address=[0x1361f80]
    void  GetObjectGfxInfo(struct SGfxObjectInfo & a2, unsigned int a3, unsigned int a4, unsigned int _iAmount);

    // address=[0x13621a0]
    unsigned int  GetObjectFirstJob(unsigned int a2);

    // address=[0x1362210]
    void  GetSettlerGfxInfo(struct SGfxObjectInfo & a2, unsigned int _iRace, unsigned int _iJob, unsigned int _iFrame, unsigned int _iDir);

    // address=[0x1362410]
    unsigned int  GetSettlerFirstJob(unsigned int _iRace, unsigned int a3);

    // address=[0x13624d0]
    void  GetPatchSettlerGfxInfo(struct SGfxPatchObject & a2, unsigned int _iRace, unsigned int _iJob, unsigned int _iFrame, unsigned int _iDir);

    // address=[0x1362620]
    void  GetPileGfxInfo(struct SGfxObjectInfo & a2, unsigned int iPile, unsigned int _iAmount, unsigned int a5);

    // address=[0x1362810]
    void  GetPatchPileGfxInfo(struct SGfxPatchObject & a2, unsigned int iPile, unsigned int _iAmount, unsigned int a5);

    // address=[0x1362a00]
    void  GetVehicleGfxInfo(struct SGfxObjectInfo & a2, unsigned int iRace, unsigned int a4, unsigned int _iDir, unsigned int _iFrame, unsigned int _iJobPatch, unsigned int _iFramePatch);

    // address=[0x1362d50]
    unsigned int  GetVehicleFirstJob(unsigned int _iRace, unsigned int a3);

    // address=[0x1362dc0]
    void  GetAnimalGfxInfo(struct SGfxObjectInfo & a2, unsigned int a3, unsigned int a4, unsigned int a5);

    // address=[0x1362fc0]
    unsigned int  GetAnimalFirstJob(unsigned int a2);

    // address=[0x1363030]
    void  GetEffectGfxInfo(struct SGfxObjectInfo & a2, unsigned int _iJob, unsigned int _iDir, unsigned int _iFrame);

    // address=[0x13632c0]
    void  GetAccessoryGfxInfo(struct SGfxObjectInfo & a2, unsigned int _iAccessory);

    // address=[0x1363410]
    unsigned int  GetSettlerJobFrameCount(unsigned int a2, unsigned int a3, unsigned int a4);

    // address=[0x1363440]
    unsigned int  GetObjectFrameCount(unsigned int a2);

    // address=[0x1363470]
    unsigned int  GetPileFrameCount(unsigned int a1);

    // address=[0x13634a0]
    unsigned int  GetVehicleFrameCount(unsigned int a2, unsigned int a3);

    // address=[0x13634e0]
    unsigned int  GetAnimalFrameCount(unsigned int a2);

    // address=[0x1363510]
    unsigned int  GetEffectFrameCount(unsigned int a2);

    // address=[0x13635a0]
    unsigned int  GetBuildingJobFrameCount(unsigned int a2, unsigned int a3);

    // address=[0x13635d0]
    void  GetBoundingBox(struct SGfxBoundingBox & a2, unsigned int a3, unsigned int a4, unsigned int a5);

    // address=[0x13637e0]
    bool  EnableGfxFile(unsigned int _iGfxFile, int _iType, bool _bMapFile, unsigned int _iFileVersion);

    // address=[0x1363b20]
    static void * __cdecl Reload(int a1, bool a2, bool a3);

    // address=[0x1363d10]
    unsigned int  GetJobFrameCount(unsigned int _iGfxFile, unsigned int _iJob, unsigned int _iDir);

    // address=[0x13640d0]
    bool  IsDirectionAvailable(unsigned int _iGfxFile, unsigned int a3, unsigned int a4);

    // address=[0x1364190]
    void  GetRawGfxInfo(struct SGfxObjectInfo & a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6);

    // address=[0x1364360]
    void  GetRawGfxInfo(struct SGfxObjectInfo & a2, unsigned int a3, unsigned int a4);

    // address=[0x1364430]
    bool  GetImageInfo(unsigned int _iGfxFile, unsigned int a3, int & a4, int & a5, int & a6, int & a7);

    // address=[0x1364940]
    bool  GetImageInfo(unsigned int a2, unsigned int a3, int & a4, int & a5, int & a6);

    // address=[0x1364980]
    bool  GetJobIndices(unsigned int _iGfxFile, unsigned int a3, int & a4, int & a5);

    // address=[0x1364ba0]
    void  DisableGfxFile(int a2);

    // address=[0x1364bc0]
    void  EnableMCD2Textures(bool a2);

    // address=[0x136a1e0]
    unsigned int  GetNrDirection(unsigned int a2);

    // address=[0x136a200]
    bool  HasSil(unsigned int a2);

    // address=[0x13d8be0]
    bool  IsGfxFileEnabled(int a2);

private:
    // address=[0x1364be0]
    bool  RemoveAllGFX(int a2);

    // address=[0x1364f80]
    void  ErrorMessageBox(class String a1);

    // address=[0x1364ff0]
    void *  LoadFile(std::wstring a2, unsigned long * a3, unsigned int a4);

    // address=[0x1365310]
    class CFileEx *  MapFullFile(std::wstring a2, unsigned int _iFileVersion);

    // address=[0x1365750]
    bool  LoadGfxFile(unsigned int a2, bool _bMapFile, unsigned int _iFileVersion);

    // address=[0x1365a70]
    bool  LoadGfxColorFile(unsigned int a2, bool a3, unsigned int a4);

    // address=[0x1365ce0]
    bool  LoadGilFile(unsigned int a2, unsigned int a3);

    // address=[0x1365f30]
    bool  LoadDilFile(unsigned int a2, unsigned int a3);

    // address=[0x1366180]
    bool  LoadJilFile(unsigned int a2, unsigned int a3);

    // address=[0x13663d0]
    bool  LoadSilFile(unsigned int a2, unsigned int a3);

    // address=[0x1366520]
    bool  LoadPilFile(unsigned int a2, unsigned int a3, bool a4);

    // address=[0x1366790]
    bool  LoadPalFile(unsigned int a2, unsigned int a3, bool a4);

    // address=[0x1366b90]
    bool  MoveAccessoriesToGfxEngine(void);

    // address=[0x1366c80]
    bool  MoveWavesToGfxEngine(void);

    // address=[0x1367b70]
    void  Debug_Check_LayerBlock(unsigned int _iGfxFile, struct SGfxObjectInfo & a3);

    // address=[0x1367e50]
    void  Debug_Check_PatchLayerBlock(unsigned int a2, struct SGfxPatchObject & a3);

    // Type information members
public:
    CGfxManager::SGFXINFO[42] m_sFilePal;
    char **[42] m_pFilePalIndex;
    CGfxManager::SGfxFrame[42] m_pFileGfxFrames;
    CGfxManager::SGfxFrame[42] m_pFileGfxDirections;
    CGfxManager::SGfxFrame[42] m_pFileGfxJobs;
    CGfxManager::SGfxFrame[42] m_pFileGfxJobCodes;
    CGfxManager::SGFXINFO[42] m_sFileGfx;
    _BYTE[336] field_B2C;
    std::wstring m_swGfxFolderName;
    BYTE m_bUse6Palette;
    BYTE m_bUseHighPalette;
    _BYTE[2] gapC9A;
    int m_iActiveGfxFile;
    std::string m_sLastError;
    bool field_cbc;
    bool field_cbd;
    bool m_bUseHighTerrain;

};


#endif // CGFXMANAGER_H
