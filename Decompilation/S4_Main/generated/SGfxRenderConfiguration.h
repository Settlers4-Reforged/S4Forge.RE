#ifndef SGFXRENDERCONFIGURATION_H
#define SGFXRENDERCONFIGURATION_H

class SGfxRenderConfiguration {
public:
    // address=[0x148fbd0]
    void  EnableFiltering(bool);

    // address=[0x148fc20]
    void  EnableHQTextureSet(bool);

    // address=[0x148fc70]
    void  EnableHardwareLandscapeEngine(bool);

    // address=[0x148fcc0]
    void  EnableHardwareObjectEngine(bool);

    // address=[0x148fd10]
    void  ForceBlit(bool);

    // address=[0x148fe40]
    bool  IsFiltering(void)const;

    // address=[0x148fe80]
    bool  IsHQTextureSet(void)const;

    // address=[0x148fec0]
    bool  IsHardwareObjectEngine(void)const;

    // address=[0x148ffc0]
    void  SetPureSoftwareMode(bool);

    // address=[0x2f5f3d0]
    bool  IsEditorMode(void)const;

    // address=[0x2f5f410]
    bool  IsHardwareLandscapeEngine(void)const;

    // address=[0x2f69920]
    bool  IsForceBlit(void)const;

};


#endif // SGFXRENDERCONFIGURATION_H
