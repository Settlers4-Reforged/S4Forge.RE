#ifndef GUI_ENGINE_H
#define GUI_ENGINE_H

constexpr struct GUI_MENU_DIALOG_HEADER *GetContainerPtr(int _iContainerId) {
    return g_pFileHeader + g_pFileHeader->m_iContainerMap[_iContainerId];
}

// address=[0x2f99880]
bool __cdecl GuiEngine2_EventProc(struct SEventStruct &);

// address=[0x2f9b750]
bool __cdecl IsTextControl(int);

// address=[0x2f9b7a0]
bool __cdecl CanHilightControl(int);

// address=[0x2f9b7f0]
bool __cdecl HasImage(int);

// address=[0x2f9b840]
int __cdecl GetSurfaceID(struct SGuiControl *);

// address=[0x2f9b870]
struct SGuiControl *__cdecl GetControlPtr(int, int);

// address=[0x2f9b8f0]
int __cdecl CalcSliderPosition(int, int, int, bool);

// address=[0x2f9b950]
int __cdecl CalcPercentageValue(int, int, int, bool);

// address=[0x2f9b9c0]
int __cdecl AddKeyStates(int);

// address=[0x2f9ba00]
bool __cdecl IsNonTransparentGuiArea(int, int);

// address=[0x2f9bc00]
bool __cdecl DeleteCharacter(unsigned char *, int);

// address=[0x2f9bd50]
bool __cdecl InsertCharacter(unsigned char *, int, int, int);

// address=[0x2f9bee0]
void __cdecl DoScrolling(struct SGuiControl *, int);

// address=[0x2f9c0c0]
bool __cdecl DrawControl(void *, unsigned int, int, int, struct SGuiControl *);

// address=[0x2f9cb10]
bool __cdecl DrawControlText(struct HDC__ *, struct SGuiControl *);

// address=[0x2f9d020]
bool __cdecl SetControlState(struct SGuiControl *, int, bool);

// address=[0x2f9d1b0]
void __cdecl ChangeMultisliders(struct SGuiControl *, int);

// address=[0x2f9d3c0]
void __cdecl EnsureMultisliders(struct SGuiControl *);

// address=[0x2f9d580]
bool __cdecl CanLockMultislider(struct SGuiControl *);

// address=[0x2f9d670]
void __cdecl StoreMultisliderSettings(struct SGuiControl *);

// address=[0x2f9d720]
void __cdecl RestoreMultisliderSettings(struct SGuiControl *);

// address=[0x2f9d850]
bool __cdecl SelectRadioGroup(struct SGuiControl *);

// address=[0x2f9d9b0]
bool __cdecl FindControlUnderCursor(int, int, struct SGuiControl *&, int &, int &);

// address=[0x2f9dc20]
bool __cdecl FindDialogUnderCursor(int, int, struct GUI_MENU_DIALOG_HEADER *&);

// address=[0x2f9dce0]
void __cdecl UpdateGui(int);

// address=[0x2f9e2c0]
void __cdecl CalcCharWidths(struct SGuiControl *);

// address=[0x2f9e430]
bool __cdecl SelectEditControl(struct SGuiControl *, int);

// address=[0x2f9e5e0]
bool __cdecl IsValidInput(int, int);

// address=[0x2f9fe90]
unsigned int __cdecl GetGuiInterfaceVersion(void);

// address=[0x2fa2f90]
bool __cdecl CalcTextSize(int, char *, struct tagSIZE &, int, int);

// address=[0x2fa4040]
void __cdecl InitTables(void);

// address=[0x2fa4150]
void __cdecl FastBlit(void *, int, int, int, int, int, void *, int, int, int);

// address=[0x2fa4300]
void __cdecl FastBlit8Bit(void *, int, int, int, int, int, void *, int, int, int, void *);

// address=[0x2fa4580]
void __cdecl UnpackGfx(void *, void *, void *, int, int, int);

// address=[0x2fa4990]
void __cdecl UnpackGfxTransparent(void *, void *, void *, int, int, int);

// address=[0x2fa4b30]
void __cdecl UnpackGfxTransparentHiLight555(void *, void *, void *, int, int, int);

// address=[0x2fa4d10]
void __cdecl UnpackGfxTransparentHiLight565(void *, void *, void *, int, int, int);

// address=[0x2fa4ef0]
void __cdecl UnpackGfxTransparentGrayed555(void *, void *, void *, int, int, int);

// address=[0x2fa50c0]
void __cdecl UnpackGfxTransparentGrayed565(void *, void *, void *, int, int, int);

// address=[0x2fa5290]
void __cdecl FastRectangle(unsigned short *, int, int, int, int, int, unsigned short);

// address=[0x2fa5350]
void __cdecl FastHLine(unsigned short *, int, int, int, int, unsigned short);

// address=[0x2fa53e0]
void __cdecl FastVLine(unsigned short *, int, int, int, int, unsigned short);

// address=[0x2fa5470]
void __cdecl FastRaster(void *, int, int, int, int, int, int);

// address=[0x2fa55c0]
void __cdecl FastRasterSolid(void *, int, int, int, int, int, int, int);

#endif // GUI_ENGINE_H
