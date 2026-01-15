#include "CGuiEventHandler.h"

// Definitions for class CGuiEventHandler

// address=[0x139da10]
// Decompiled from CGuiEventHandler *__thiscall CGuiEventHandler::CGuiEventHandler(CGuiEventHandler *this, bool a2)
 CGuiEventHandler::CGuiEventHandler(bool) {
  
  IEvn_Handle::IEvn_Handle(this);
  *(_DWORD *)this = &CGuiEventHandler::_vftable_;
  *((_DWORD *)this + 7) = -1;
  *((_DWORD *)this + 5) = -1;
  *((_DWORD *)this + 6) = -1;
  *((_DWORD *)this + 3) = -1;
  *((_DWORD *)this + 4) = -1;
  *((_DWORD *)this + 8) = -1;
  *((_DWORD *)this + 9) = -1;
  *((_DWORD *)this + 10) = -1;
  *((_DWORD *)this + 11) = -1;
  *((_DWORD *)this + 12) = -1;
  *((_DWORD *)this + 13) = -1;
  *((_DWORD *)this + 14) = -1;
  *((_DWORD *)this + 15) = -1;
  *((_BYTE *)this + 4) = 0;
  *((_BYTE *)this + 64) = a2;
  *((_DWORD *)this + 2) = 0;
  *((_BYTE *)this + 5) = 0;
  *((_BYTE *)this + 66) = 0;
  *((_BYTE *)this + 65) = 0;
  return this;
}


// address=[0x139daf0]
// Decompiled from CGuiEventHandler *__thiscall CGuiEventHandler::~CGuiEventHandler(CGuiEventHandler *this)
 CGuiEventHandler::~CGuiEventHandler(void) {
  
  CGuiEventHandler *result; // eax

  *(_DWORD *)this = &CGuiEventHandler::_vftable_;
  *((_DWORD *)this + 7) = -1;
  *((_DWORD *)this + 5) = -1;
  *((_DWORD *)this + 6) = -1;
  *((_DWORD *)this + 3) = -1;
  *((_DWORD *)this + 4) = -1;
  *((_DWORD *)this + 8) = -1;
  *((_DWORD *)this + 9) = -1;
  *((_DWORD *)this + 10) = -1;
  *((_DWORD *)this + 11) = -1;
  *((_DWORD *)this + 12) = -1;
  *((_DWORD *)this + 13) = -1;
  *((_DWORD *)this + 14) = -1;
  *((_DWORD *)this + 15) = -1;
  *((_BYTE *)this + 4) = 0;
  *((_BYTE *)this + 64) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_BYTE *)this + 5) = 0;
  result = this;
  *((_BYTE *)this + 66) = 0;
  *((_BYTE *)this + 65) = 0;
  return result;
}


// address=[0x139dbc0]
// Decompiled from int __thiscall CGuiEventHandler::GetEventFunction(CGuiEventHandler *this)
void *  CGuiEventHandler::GetEventFunction(void) {
  
  return 0;
}


// address=[0x139dbd0]
// Decompiled from bool __thiscall CGuiEventHandler::OnEvent(CGuiEventHandler *this, struct CEvn_Event *a2)
bool  CGuiEventHandler::OnEvent(class CEvn_Event &) {
  
  bool result; // al
  int OutputWidth; // eax
  char *v4; // eax
  int v5; // [esp+Ch] [ebp-140h]
  CEvn_Logic *v6; // [esp+14h] [ebp-138h]
  CEvn_Event *v7; // [esp+1Ch] [ebp-130h]
  int v8[2]; // [esp+24h] [ebp-128h] BYREF
  CEvn_Event *v10; // [esp+30h] [ebp-11Ch]
  CEvn_Event *v11; // [esp+38h] [ebp-114h]
  int v12; // [esp+40h] [ebp-10Ch]
  CEvn_Event *v13; // [esp+44h] [ebp-108h]
  CEvn_Event *v14; // [esp+48h] [ebp-104h]
  CEvn_Logic *v15; // [esp+4Ch] [ebp-100h]
  int v16; // [esp+50h] [ebp-FCh]
  BOOL v17; // [esp+54h] [ebp-F8h]
  BOOL v18; // [esp+58h] [ebp-F4h]
  int v19; // [esp+5Ch] [ebp-F0h]
  unsigned int TickCounter; // [esp+60h] [ebp-ECh]
  int v21; // [esp+68h] [ebp-E4h]
  bool v22; // [esp+6Fh] [ebp-DDh]
  CGuiEventHandler *v23; // [esp+70h] [ebp-DCh]
  _BYTE v24[32]; // [esp+74h] [ebp-D8h] BYREF
  _BYTE v25[32]; // [esp+94h] [ebp-B8h] BYREF
  CEvn_Event v26; // [esp+B4h] [ebp-98h] BYREF
  CEvn_Event v27; // [esp+CCh] [ebp-80h] BYREF
  CEvn_Event v28; // [esp+E4h] [ebp-68h] BYREF
  CEvn_Event v29; // [esp+FCh] [ebp-50h] BYREF
  CEvn_Event v30; // [esp+114h] [ebp-38h] BYREF
  _DWORD v31[4]; // [esp+12Ch] [ebp-20h] BYREF
  int v32; // [esp+148h] [ebp-4h]

  v23 = this;
  switch ( a2->event )
  {
    case 0x15:
      if ( g_pGfxEngine )
      {
        if ( *((_BYTE *)v23 + 64) && *((_DWORD *)v23 + 14) == 57 )
          UpdateGuiDlgTutorialCursor();
        if ( *((_DWORD *)v23 + 15) != -1 )
        {
          TickCounter = CStateGame::GetTickCounter(g_pGame);
          if ( TickCounter - *((_DWORD *)v23 + 2) >= 0xE )
          {
            UpdateGuiDlgClock(TickCounter);
            *((_DWORD *)v23 + 2) = TickCounter;
          }
        }
        if ( *((_DWORD *)v23 + 13) == -1 )
          return 0;
        if ( !*((_BYTE *)v23 + 65) )
          return 0;
        if ( --dword_3D891A8 > 0 )
          return 0;
        if ( byte_3ED2029 )
        {
          IGuiEngine::SetImages((void *)g_pGUIEngine, 59, 891, 328, 329);
          byte_3ED2029 = 0;
        }
        else
        {
          IGuiEngine::SetImages((void *)g_pGUIEngine, 59, 891, 330, 331);
          byte_3ED2029 = 1;
        }
        dword_3D891A8 = 5;
        return 0;
      }
      else
      {
        return 0;
      }
    case 0xD:
      return CGuiEventHandler::HandleMsgKeyPress(v23, a2);
    case 0xB:
      return CGuiEventHandler::HandleMsgKeyDown(v23, a2);
    case 0x27:
      *((_DWORD *)v23 + 5) = 0;
      IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 9, GuiDlgBuildBasicProc);
      *((_DWORD *)v23 + 3) = -1;
      if ( *((_BYTE *)v23 + 64) )
        IGuiEngine::SetDlgToIgnore((IGuiEngine *)g_pGUIEngine, 36, 1);
      CGuiEventHandler::ResetMainMenu(v23);
      if ( *((_BYTE *)v23 + 5) )
      {
        v15 = CEvn_Logic::CEvn_Logic((CEvn_Logic *)v24, 0x1E2u, 1u, 0, 0, 0, 0);
        v32 = 0;
        IEventEngine::SendAMessage(g_pEvnEngine, v15);
        v32 = -1;
        CEvn_Logic::~CEvn_Logic(v24);
      }
      if ( *((_DWORD *)v23 + 13) != -1 )
        return 0;
      IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 59, GuiDlgIncomingMessageProc);
      *((_DWORD *)v23 + 13) = 59;
      CGuiEventHandler::RecalcDialogPos(v23, 1);
      return 0;
    default:
      if ( a2->event >= 0x258u && a2->event <= 0x27Bu )
      {
        if ( a2->event == 626 )
        {
          CGuiEventHandler::RecalcDialogPos(v23, 0);
          return 1;
        }
        else if ( a2->event == 609 )
        {
          if ( *((_DWORD *)v23 + 7) != -1 )
            return 1;
          IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 72, GuiDlgWinLossProc);
          *((_DWORD *)v23 + 7) = 72;
          IGuiEngine::GetDialogRenderRect((IGuiEngine *)g_pGUIEngine, 72, (struct SGuiRect *)v31);
          v5 = v31[2] - v31[0] + 1;
          OutputWidth = IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine);
          IGuiEngine::SetDialogRenderPos((IGuiEngine *)g_pGUIEngine, 72, (OutputWidth - 210) / 2 - v5 / 2 + 210, 10);
          UpdateGuiDlgWinLoss(a2->wparam);
          return 1;
        }
        else
        {
          v21 = a2->event - 601;
          switch ( v21 )
          {
            case 0:
              if ( *((_DWORD *)v23 + 4) != -1 )
              {
                if ( *((_DWORD *)v23 + 4) == 52 )
                {
                  IGuiEngine::ResetRadioGroup((IGuiEngine *)g_pGUIEngine, 52, 672);
                  v6 = CEvn_Logic::CEvn_Logic((CEvn_Logic *)v25, 0x1CCu, 0, 0, 0, 0, 0);
                  v32 = 1;
                  IEventEngine::SendAMessage(g_pEvnEngine, v6);
                  v32 = -1;
                  CEvn_Logic::~CEvn_Logic(v25);
                  v7 = CEvn_Event::CEvn_Event(&v26, 0x260u, 0, 0, 0);
                  v32 = 2;
                  IEventEngine::SendAMessage(g_pEvnEngine, v7);
                  v32 = -1;
                  CEvn_Event::~CEvn_Event(&v26);
                }
                if ( *((_DWORD *)v23 + 4) == 56 )
                {
                  IGuiEngine::ResetRadioGroup((IGuiEngine *)g_pGUIEngine, 56, 932);
                  goto CGuiEventHandler__OnEvent___def_179DF97;
                }
              }
              if ( *((_DWORD *)v23 + 3) != -1 )
              {
                switch ( *((_DWORD *)v23 + 3) )
                {
                  case 9:
                    IGuiEngine::ResetRadioGroup((IGuiEngine *)g_pGUIEngine, 9, 375);
                    break;
                  case 0xA:
                    IGuiEngine::ResetRadioGroup((IGuiEngine *)g_pGUIEngine, 10, 492);
                    break;
                  case 0xB:
                    IGuiEngine::ResetRadioGroup((IGuiEngine *)g_pGUIEngine, 11, 435);
                    break;
                  case 0xC:
                    IGuiEngine::ResetRadioGroup((IGuiEngine *)g_pGUIEngine, 12, 545);
                    break;
                  case 0xD:
                    IGuiEngine::ResetRadioGroup((IGuiEngine *)g_pGUIEngine, 13, 505);
                    break;
                  default:
                    return 1;
                }
              }
              return 1;
            case 1:
              *((_BYTE *)v23 + 4) = 0;
              CGuiEventHandler::HandleMsgNewDialog(v23, a2);
              return 1;
            case 2:
              *((_BYTE *)v23 + 4) = 0;
              CGuiEventHandler::ResetMainMenu(v23);
              return 1;
            case 3:
              if ( *((_DWORD *)v23 + 3) != -1 )
                CGuiEventHandler::HandleMsgRefreshDialog(v23, a2);
              return 1;
            case 4:
              if ( *((_DWORD *)v23 + 5) != -1 )
                IGuiEngine::SetSliderPosition((IGuiEngine *)g_pGUIEngine, *((_DWORD *)v23 + 5), 613, a2->lparam);
              return 1;
            case 5:
              if ( *((_DWORD *)v23 + 4) != -1 )
                CGuiEventHandler::HandleMsgRefreshDialog(v23, a2);
              return 1;
            case 6:
              CGuiEventHandler::HandleMsgOpenSidebar(v23, a2);
              return 1;
            case 7:
              if ( *((_DWORD *)v23 + 4) == -1 )
                return 1;
              IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)v23 + 4));
              *((_DWORD *)v23 + 4) = -1;
              return 1;
            case 10:
              if ( *((_DWORD *)v23 + 10) == -1 && g_pEvnEngine )
              {
                v14 = CEvn_Event::CEvn_Event(&v27, 0x269u, 1u, 0, 0);
                v13 = v14;
                v32 = 4;
                IEventEngine::SendAMessage(g_pEvnEngine, v14);
                v32 = -1;
                CEvn_Event::~CEvn_Event(&v27);
              }
              PlayGuiSound(1);
              if ( a2->lparam )
                v16 = 1712;
              else
                v16 = 1711;
              v12 = v16;
              v4 = g_pStringEngine->GetString(g_pStringEngine, a2->wparam);
              IGuiEngine::SetText((void *)g_pGUIEngine, *((_DWORD *)v23 + 10), v16, v4);
              return 1;
            case 11:
              if ( *((_BYTE *)v23 + 64) )
                return 0;
              if ( *((_DWORD *)v23 + 10) != -1 )
              {
                PlayGuiSound(5);
                goto LABEL_115;
              }
              if ( g_pEvnEngine )
              {
                v11 = CEvn_Event::CEvn_Event(&v28, 0x269u, 1u, 0, 0);
                v32 = 5;
                IEventEngine::SendAMessage(g_pEvnEngine, v11);
                v32 = -1;
                CEvn_Event::~CEvn_Event(&v28);
              }
              goto CGuiEventHandler__OnEvent___def_179DF97;
            case 12:
LABEL_115:
              if ( *((_BYTE *)v23 + 64) )
                return 0;
              if ( *((_DWORD *)v23 + 10) != -1 )
                goto LABEL_118;
              if ( *((_DWORD *)v23 + 13) != -1 )
                return 1;
              PlayGuiSound(4);
              IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 59, GuiDlgIncomingMessageProc);
              *((_DWORD *)v23 + 13) = 59;
              CGuiEventHandler::RecalcDialogPos(v23, 1);
              return 1;
            case 13:
              if ( *((_BYTE *)v23 + 64) )
                return 0;
              if ( *((_DWORD *)v23 + 10) == -1 )
                goto CGuiEventHandler__OnEvent___def_179DF97;
LABEL_118:
              PlayGuiSound(1);
              UpdateGuiDlgMessages(a2);
              return 1;
            case 14:
            case 33:
              goto LABEL_134;
            case 15:
            case 32:
              if ( *((_BYTE *)v23 + 64) )
              {
                result = 0;
              }
              else if ( *((_DWORD *)v23 + 10) == -1 )
              {
                if ( g_pEvnEngine )
                {
                  v10 = CEvn_Event::CEvn_Event(&v29, 0x269u, 0, 0, 0);
                  v32 = 6;
                  IEventEngine::SendAMessage(g_pEvnEngine, v10);
                  v32 = -1;
                  CEvn_Event::~CEvn_Event(&v29);
                }
CGuiEventHandler__OnEvent___def_179DF97:
                result = 0;
              }
              else
              {
                if ( a2->event != 633 )
                  PlayGuiSound(5);
LABEL_134:
                if ( (unsigned __int16)a2->lparam )
                  *((_BYTE *)v23 + 65) = 1;
                if ( *((_BYTE *)v23 + 64) )
                {
                  result = 0;
                }
                else
                {
                  if ( a2->event != 616 && a2->event != 633 )
                  {
                    if ( HIWORD(a2->lparam) )
                    {
                      if ( a2->event != 634 )
                        PlayGuiSound(4);
                    }
                  }
                  if ( *((_DWORD *)v23 + 10) == -1 )
                  {
                    result = 1;
                  }
                  else
                  {
                    if ( a2->event != 633 && a2->event != 634 )
                      PlayGuiSound(1);
                    UpdateGuiDlgMessages(a2);
                    result = 1;
                  }
                }
              }
              break;
            case 16:
              if ( *((_DWORD *)v23 + 13) != -1 )
              {
                IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)v23 + 13));
                *((_DWORD *)v23 + 13) = -1;
                *((_BYTE *)v23 + 65) = 0;
              }
              if ( *((_DWORD *)v23 + 10) != -1 )
                return 1;
              CGuiEventHandler::GetTextMessageDialogParameters(v23, v8);
              *((_DWORD *)v23 + 10) = v8[0];
              IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, v8[0], (bool (__cdecl *)(int, int, int))v8[1]);
              if ( !*((_BYTE *)v23 + 64) )
              {
                v18 = a2->wparam != 0;
                v22 = v18;
                v17 = v18;
                CEvn_Event::CEvn_Event(&v30, 0x1773u, v17, 0, 0);
                v32 = 3;
                IEventEngine::SendAMessage(g_pEvnEngine, &v30);
                v32 = -1;
                CEvn_Event::~CEvn_Event(&v30);
              }
              CGuiEventHandler::RecalcDialogPos(v23, 1);
              return 1;
            case 17:
              if ( *((_DWORD *)v23 + 10) == -1 )
                return 1;
              IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)v23 + 10));
              *((_DWORD *)v23 + 10) = -1;
              IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 59, GuiDlgIncomingMessageProc);
              *((_DWORD *)v23 + 13) = 59;
              IGuiEngine::SetImages((void *)g_pGUIEngine, 59, 891, 328, 329);
              CGuiEventHandler::RecalcDialogPos(v23, 1);
              *((_BYTE *)v23 + 65) = 0;
              return 1;
            case 18:
              if ( *((_BYTE *)v23 + 4) && *((_DWORD *)v23 + 3) != -1 )
                CGuiEventHandler::HandleMsgRefreshSettingsDialog(v23, a2);
              return 1;
            case 19:
              *((_BYTE *)v23 + 4) = 1;
              CGuiEventHandler::HandleMsgOpenSettings(v23, a2);
              return 1;
            case 20:
              CGuiEventHandler::HandleMsgCloseAllDialogs(v23);
              return 1;
            case 21:
              if ( !*((_BYTE *)v23 + 64) )
                return 1;
              if ( a2->lparam == 1 )
              {
                if ( *((_DWORD *)v23 + 14) == -1 )
                {
                  IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 57, GuiDlgTutorialCursorProc);
                  *((_DWORD *)v23 + 14) = 57;
                }
                IGuiEngine::MoveDialogTo(
                  (IGuiEngine *)g_pGUIEngine,
                  57,
                  HIWORD(a2->wparam),
                  (unsigned __int16)a2->wparam);
              }
              else if ( *((_DWORD *)v23 + 14) == 57 )
              {
                IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 57);
                *((_DWORD *)v23 + 14) = -1;
              }
              return 1;
            case 22:
              if ( *((_DWORD *)v23 + 5) != -1 )
                UpdateGuiDlgMinimap(a2->wparam);
              return 1;
            case 26:
              if ( *((_DWORD *)v23 + 15) != -1 )
                return 1;
              IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 74, GuiDlgClockProc);
              *((_DWORD *)v23 + 15) = 74;
              CGuiEventHandler::RecalcDialogPos(v23, 1);
              return 1;
            case 27:
              if ( *((_DWORD *)v23 + 15) == -1 )
                return 1;
              IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)v23 + 15));
              *((_DWORD *)v23 + 15) = -1;
              return 1;
            case 30:
              v19 = *((_DWORD *)v23 + 3);
              switch ( v19 )
              {
                case 28:
                  UpdateGuiDlgStatisticWarrior();
                  break;
                case 75:
                  UpdateGuiDlgStatisticLand();
                  break;
                case 76:
                  UpdateGuiDlgStatisticGoods();
                  break;
              }
              goto CGuiEventHandler__OnEvent___def_179DF97;
            case 31:
              IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 4, 748, 1);
              return 1;
            default:
              goto CGuiEventHandler__OnEvent___def_179DF97;
          }
        }
      }
      else
      {
        return 0;
      }
      break;
  }
  return result;
}


// address=[0x139eaa0]
// Decompiled from bool __thiscall CGuiEventHandler::RecalcDialogPos(CGuiEventHandler *this, bool a2)
void  CGuiEventHandler::RecalcDialogPos(bool) {
  
  bool result; // al
  int OutputWidth; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // [esp-4h] [ebp-FCh]
  int v8; // [esp+4h] [ebp-F4h]
  int v9; // [esp+8h] [ebp-F0h]
  int v10; // [esp+Ch] [ebp-ECh]
  CEvn_Logic *v11; // [esp+10h] [ebp-E8h]
  CEvn_Logic *v12; // [esp+18h] [ebp-E0h]
  CEvn_Event *v13; // [esp+20h] [ebp-D8h]
  CEvn_Event *v14; // [esp+28h] [ebp-D0h]
  CEvn_Event *v15; // [esp+30h] [ebp-C8h]
  int OutputHeight; // [esp+44h] [ebp-B4h]
  char v17; // [esp+4Ah] [ebp-AEh]
  char v18; // [esp+4Bh] [ebp-ADh]
  _BYTE v20[32]; // [esp+50h] [ebp-A8h] BYREF
  _BYTE v21[32]; // [esp+70h] [ebp-88h] BYREF
  CEvn_Event v22; // [esp+90h] [ebp-68h] BYREF
  CEvn_Event v23; // [esp+A8h] [ebp-50h] BYREF
  CEvn_Event v24; // [esp+C0h] [ebp-38h] BYREF
  int v25; // [esp+D8h] [ebp-20h] BYREF
  int v26; // [esp+DCh] [ebp-1Ch]
  int v27; // [esp+E0h] [ebp-18h]
  int v28; // [esp+E4h] [ebp-14h]
  int v29; // [esp+F4h] [ebp-4h]

  if ( !a2 && *((_DWORD *)this + 10) != -1 && g_pEvnEngine )
  {
    v15 = CEvn_Event::CEvn_Event(&v24, 0x26Au, 0, 0, 0);
    v29 = 0;
    IEventEngine::SendAMessage(g_pEvnEngine, v15);
    v29 = -1;
    CEvn_Event::~CEvn_Event(&v24);
    v14 = CEvn_Event::CEvn_Event(&v23, 0x269u, 0, 0, 0);
    v29 = 1;
    IEventEngine::SendAMessage(g_pEvnEngine, v14);
    v29 = -1;
    CEvn_Event::~CEvn_Event(&v23);
    v13 = CEvn_Event::CEvn_Event(&v22, 0x1773u, 0, 0, 0);
    v29 = 2;
    IEventEngine::SendAMessage(g_pEvnEngine, v13);
    v29 = -1;
    CEvn_Event::~CEvn_Event(&v22);
  }
  OutputHeight = IGfxEngine::GetOutputHeight((IGfxEngine *)g_pGfxEngine);
  v18 = sub_139F260(1, OutputHeight);
  if ( v18 != (*((_DWORD *)this + 8) != -1) )
  {
    if ( v18 )
    {
      IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 1, GuiDlgMainBarExt1Proc);
      *((_DWORD *)this + 8) = 1;
      v12 = CEvn_Logic::CEvn_Logic((CEvn_Logic *)v21, 0x1E2u, 1u, 0, 0, 0, 0);
      v29 = 3;
      IEventEngine::SendAMessage(g_pEvnEngine, v12);
      v29 = -1;
      CEvn_Logic::~CEvn_Logic(v21);
      *((_BYTE *)this + 5) = 1;
    }
    else
    {
      v11 = CEvn_Logic::CEvn_Logic((CEvn_Logic *)v20, 0x1E2u, 0, 0, 0, 0, 0);
      v29 = 4;
      IEventEngine::SendAMessage(g_pEvnEngine, v11);
      v29 = -1;
      CEvn_Logic::~CEvn_Logic(v20);
      *((_BYTE *)this + 5) = 0;
      IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)this + 8));
      *((_DWORD *)this + 8) = -1;
    }
  }
  v17 = sub_139F260(2, OutputHeight);
  result = v17;
  if ( v17 != (*((_DWORD *)this + 9) != -1) )
  {
    if ( v17 )
    {
      IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 2, GuiDlgMainBarExt2Proc);
      *((_DWORD *)this + 9) = 2;
      result = IGfxEngine::EnableCameraWindow((IGfxEngine *)g_pGfxEngine, 1, 16, 818, 174, 190);
    }
    else
    {
      IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)this + 9));
      *((_DWORD *)this + 9) = -1;
      result = IGfxEngine::EnableCameraWindow((IGfxEngine *)g_pGfxEngine, 0, 0, 0, 0, 0);
    }
  }
  if ( *((_DWORD *)this + 7) != -1 )
  {
    IGuiEngine::GetDialogRenderRect((IGuiEngine *)g_pGUIEngine, 72, (struct SGuiRect *)&v25);
    v10 = v27 - v25 + 1;
    OutputWidth = IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine);
    result = IGuiEngine::SetDialogRenderPos((IGuiEngine *)g_pGUIEngine, 72, (OutputWidth - 210) / 2 - v10 / 2 + 210, 10);
  }
  if ( *((_DWORD *)this + 15) != -1 )
  {
    IGuiEngine::GetDialogRenderRect((IGuiEngine *)g_pGUIEngine, 74, (struct SGuiRect *)&v25);
    v9 = v27 - v25 + 1;
    v4 = IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine);
    result = IGuiEngine::SetDialogRenderPos((IGuiEngine *)g_pGUIEngine, 74, v4 - v9, 0);
  }
  if ( *((_DWORD *)this + 10) == -1 )
  {
    if ( *((_DWORD *)this + 13) != -1 )
    {
      IGuiEngine::GetDialogRenderRect((IGuiEngine *)g_pGUIEngine, 59, (struct SGuiRect *)&v25);
      result = IGuiEngine::SetDialogRenderPos((IGuiEngine *)g_pGUIEngine, 59, 209, OutputHeight - (v28 - v26 + 1));
    }
  }
  else
  {
    IGuiEngine::GetDialogRenderRect((IGuiEngine *)g_pGUIEngine, *((_DWORD *)this + 10), (struct SGuiRect *)&v25);
    result = IGuiEngine::SetDialogRenderPos(
               (IGuiEngine *)g_pGUIEngine,
               *((_DWORD *)this + 10),
               209,
               OutputHeight - (v28 - v26 + 1));
  }
  if ( !*(_DWORD *)(g_pGame + 360) )
    return result;
  IGuiEngine::GetDialogRenderRect((IGuiEngine *)g_pGUIEngine, 73, (struct SGuiRect *)&v25);
  v8 = v27 - v25 + 1;
  v5 = IGfxEngine::GetOutputHeight((IGfxEngine *)g_pGfxEngine);
  v7 = v5 - (v28 - v26 + 1);
  v6 = IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine);
  return IGuiEngine::SetDialogRenderPos((IGuiEngine *)g_pGUIEngine, 73, v6 - v8, v7);
}


// address=[0x139c480]
// Decompiled from char __thiscall CGuiEventHandler::HandleMsgKeyPress(CGuiEventHandler *this, struct CEvn_Event *a2)
bool  CGuiEventHandler::HandleMsgKeyPress(class CEvn_Event &) {
  
  char result; // al
  CEvn_Logic *v3; // [esp+4h] [ebp-80h]
  CEvn_Event *v4; // [esp+Ch] [ebp-78h]
  CEvn_Event *v5; // [esp+14h] [ebp-70h]
  _BYTE v6[32]; // [esp+24h] [ebp-60h] BYREF
  CEvn_Event v7; // [esp+44h] [ebp-40h] BYREF
  CEvn_Event v8; // [esp+5Ch] [ebp-28h] BYREF
  int v9; // [esp+80h] [ebp-4h]

  if ( a2->wparam != 13 || (a2->lparam & 4) != 0 || (a2->lparam & 8) != 0 || *((_BYTE *)this + 64) || !g_pEvnEngine )
  {
    if ( *((_BYTE *)this + 64) )
    {
      return 0;
    }
    else
    {
      switch ( a2->wparam )
      {
        case 'A':
        case 'a':
          IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 0, 607, 1);
          IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 4, 747, 1);
          result = 1;
          break;
        case 'C':
        case 'c':
          IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 0, 608, 1);
          IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 5, 1068, 1);
          result = 1;
          break;
        case 'D':
        case 'd':
          IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 0, 607, 1);
          IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 4, 745, 1);
          result = 1;
          break;
        case 'E':
        case 'e':
          IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 0, 606, 1);
          IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 3, 538, 1);
          result = 1;
          break;
        case 'F':
        case 'f':
          IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 0, 607, 1);
          v3 = CEvn_Logic::CEvn_Logic((CEvn_Logic *)v6, 0x1E5u, 0, 0, 0, 0, 0);
          v9 = 2;
          IEventEngine::SendAMessage(g_pEvnEngine, v3);
          v9 = -1;
          CEvn_Logic::~CEvn_Logic(v6);
          result = 1;
          break;
        case 'M':
        case 'm':
          if ( std::string::size(&unk_402C9B4) || CGameData::GetMode(g_pGameData) == 3 )
          {
            IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 0, 611, 1);
            IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 8, 929, 1);
          }
          result = 1;
          break;
        case 'Q':
        case 'q':
          if ( (a2->lparam & 0x10) != 0 )
          {
            IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 0, 611, 1);
            IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 8, 930, 1);
          }
          else
          {
            IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 0, 606, 1);
            IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 3, 536, 1);
          }
          result = 1;
          break;
        case 'R':
        case 'r':
          IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 0, 606, 1);
          IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 3, 539, 1);
          result = 1;
          break;
        case 'S':
        case 's':
          IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 0, 607, 1);
          IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 4, 746, 1);
          result = 1;
          break;
        case 'T':
        case 't':
          IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 0, 606, 1);
          IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 3, 540, 1);
          result = 1;
          break;
        case 'W':
        case 'w':
          IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 0, 606, 1);
          IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 3, 537, 1);
          result = 1;
          break;
        case 'X':
        case 'x':
          IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 0, 608, 1);
          IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 5, 1067, 1);
          result = 1;
          break;
        case 'Y':
        case 'Z':
        case 'y':
        case 'z':
          IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 0, 608, 1);
          IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 5, 1069, 1);
          result = 1;
          break;
        default:
          result = 0;
          break;
      }
    }
  }
  else
  {
    if ( CGameData::IsNetworkGame(g_pGameData) )
    {
      v5 = CEvn_Event::CEvn_Event(&v8, 0x269u, 1u, 0, 0);
      v9 = 0;
      IEventEngine::SendAMessage(g_pEvnEngine, v5);
      v9 = -1;
      CEvn_Event::~CEvn_Event(&v8);
      OpenChatentry();
    }
    else
    {
      v4 = CEvn_Event::CEvn_Event(&v7, 0x269u, 1u, 0, 0);
      v9 = 1;
      IEventEngine::SendAMessage(g_pEvnEngine, v4);
      v9 = -1;
      CEvn_Event::~CEvn_Event(&v7);
      OpenChatentry();
    }
    return 1;
  }
  return result;
}


// address=[0x139c960]
// Decompiled from char __thiscall CGuiEventHandler::HandleMsgKeyDown(CGuiEventHandler *this, struct CEvn_Event *a2)
bool  CGuiEventHandler::HandleMsgKeyDown(class CEvn_Event &) {
  
  CEvn_Event *v3; // [esp+4h] [ebp-58h]
  CEvn_Event *v4; // [esp+Ch] [ebp-50h]
  int wparam; // [esp+18h] [ebp-44h]
  CEvn_Event v6; // [esp+1Ch] [ebp-40h] BYREF
  CEvn_Event v7; // [esp+34h] [ebp-28h] BYREF
  int v8; // [esp+58h] [ebp-4h]

  wparam = a2->wparam;
  switch ( wparam )
  {
    case 27:
      IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 0, 611, 1);
      IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 8, 930, 1);
      return 1;
    case 117:
      if ( *((_BYTE *)this + 64) )
        return 1;
      IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 0, 611, 1);
      IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 8, 931, 1);
      return 1;
    case 118:
      if ( *((_BYTE *)this + 66) )
        return 1;
      if ( *((_DWORD *)this + 15) == -1 )
      {
        v3 = CEvn_Event::CEvn_Event(&v6, 0x273u, 0, 0, 0);
        v8 = 1;
        IEventEngine::SendAMessage(g_pEvnEngine, v3);
        v8 = -1;
        CEvn_Event::~CEvn_Event(&v6);
        GuiDlgClockSetCountdown(0);
      }
      else
      {
        v4 = CEvn_Event::CEvn_Event(&v7, 0x274u, 0, 0, 0);
        v8 = 0;
        IEventEngine::SendAMessage(g_pEvnEngine, v4);
        v8 = -1;
        CEvn_Event::~CEvn_Event(&v7);
      }
      return 1;
    default:
      return 0;
  }
}


// address=[0x139cae0]
// Decompiled from char __thiscall CGuiEventHandler::HandleMsgNewDialog(CGuiEventHandler *this, struct CEvn_Event *a2)
void  CGuiEventHandler::HandleMsgNewDialog(class CEvn_Event &) {
  
  char result; // al
  int lparam; // [esp+Ch] [ebp-8h]

  result = (char)a2;
  lparam = a2->lparam;
  if ( !lparam )
    return result;
  if ( *((_DWORD *)this + 3) != -1 )
  {
    IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)this + 3));
    *((_DWORD *)this + 3) = -1;
  }
  result = lparam;
  switch ( *(_DWORD *)(lparam + 4) )
  {
    case 0:
      CGuiEventHandler::ResetMainMenuForContext(this);
      result = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 15, GuiDlgBuildingContextProc);
      *((_DWORD *)this + 3) = 15;
      break;
    case 1:
      CGuiEventHandler::ResetMainMenuForContext(this);
      IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 14, GuiDlgBuildContextProc);
      result = (char)this;
      *((_DWORD *)this + 3) = 14;
      break;
    case 2:
      CGuiEventHandler::ResetMainMenuForContext(this);
      result = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 18, GuiDlgResourceCollectorContextProc);
      *((_DWORD *)this + 3) = 18;
      break;
    case 3:
      CGuiEventHandler::ResetMainMenuForContext(this);
      result = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 19, GuiDlgResourceUpgradeContextProc);
      *((_DWORD *)this + 3) = 19;
      break;
    case 4:
      CGuiEventHandler::ResetMainMenuForContext(this);
      result = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 16, GuiDlgMilitaryBuildingContextProc);
      *((_DWORD *)this + 3) = 16;
      break;
    case 5:
      CGuiEventHandler::ResetMainMenuForContext(this);
      IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 17, GuiDlgPortContextProc);
      result = (char)this;
      *((_DWORD *)this + 3) = 17;
      break;
    case 6:
      CGuiEventHandler::ResetMainMenuForContext(this);
      result = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 23, GuiDlgStorageContextProc);
      *((_DWORD *)this + 3) = 23;
      break;
    case 7:
      CGuiEventHandler::ResetMainMenuForContext(this);
      result = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 22, GuiDlgBarracksContextProc);
      *((_DWORD *)this + 3) = 22;
      break;
    case 8:
      CGuiEventHandler::ResetMainMenuForContext(this);
      IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 20, GuiDlgSmallTempleContextProc);
      result = (char)this;
      *((_DWORD *)this + 3) = 20;
      break;
    case 9:
      CGuiEventHandler::ResetMainMenuForContext(this);
      result = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 24, GuiDlgShipVehicleContextProc);
      *((_DWORD *)this + 3) = 24;
      break;
    case 0xA:
      result = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 43, GuiDlgYesNoProc);
      *((_DWORD *)this + 3) = 43;
      break;
    case 0x12:
      CGuiEventHandler::ResetMainMenuForContext(this);
      IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 45, GuiDlgSoldierContextProc);
      result = (char)this;
      *((_DWORD *)this + 3) = 45;
      break;
    case 0x13:
      CGuiEventHandler::ResetMainMenuForContext(this);
      result = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 44, GuiDlgSpecialistsContextProc);
      *((_DWORD *)this + 3) = 44;
      break;
    case 0x14:
      CGuiEventHandler::ResetMainMenuForContext(this);
      IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 40, GuiDlgVehiclesContextProc);
      result = (char)this;
      *((_DWORD *)this + 3) = 40;
      break;
    case 0x15:
    case 0x16:
    case 0x18:
      CGuiEventHandler::ResetMainMenuForContext(this);
      result = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 41, GuiDlgVehicleLoadContextProc);
      *((_DWORD *)this + 3) = 41;
      break;
    case 0x17:
      CGuiEventHandler::ResetMainMenuForContext(this);
      result = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 42, GuiDlgFerryLoadContextProc);
      *((_DWORD *)this + 3) = 42;
      break;
    case 0x1C:
      result = *(_BYTE *)(lparam + 8);
      switch ( result )
      {
        case 0:
          result = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 9, GuiDlgBuildBasicProc);
          *((_DWORD *)this + 3) = 9;
          break;
        case 1:
          result = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 11, GuiDlgBuildFoodProc);
          *((_DWORD *)this + 3) = 11;
          break;
        case 2:
          IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 10, GuiDlgBuildMetalProc);
          result = (char)this;
          *((_DWORD *)this + 3) = 10;
          break;
        case 3:
          result = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 12, GuiDlgBuildTownProc);
          *((_DWORD *)this + 3) = 12;
          break;
        case 4:
          result = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 13, GuiDlgBuildMilitaryProc);
          *((_DWORD *)this + 3) = 13;
          break;
        default:
          return result;
      }
      break;
    case 0x1D:
      result = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 31, GuiDlgSettlerStatisticMenuProc);
      *((_DWORD *)this + 3) = 31;
      break;
    case 0x1E:
      IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 30, GuiDlgSettlerProductionMenuProc);
      result = (char)this;
      *((_DWORD *)this + 3) = 30;
      break;
    case 0x1F:
      result = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 32, GuiDlgFreeCarrierMenuProc);
      *((_DWORD *)this + 3) = 32;
      break;
    case 0x20:
      result = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 27, GuiDlgAvailableGoodsProc);
      *((_DWORD *)this + 3) = 27;
      break;
    case 0x21:
      result = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 25, GuiDlgTransportpriorityProc);
      *((_DWORD *)this + 3) = 25;
      break;
    case 0x22:
      IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 26, GuiDlgGoodDistributionProc);
      result = (char)this;
      *((_DWORD *)this + 3) = 26;
      break;
    case 0x24:
      result = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 77, GuiDlgEconomyProc);
      *((_DWORD *)this + 3) = 77;
      break;
    default:
      return result;
  }
  return result;
}


// address=[0x139d020]
// Decompiled from char __thiscall CGuiEventHandler::HandleMsgOpenSettings(CGuiEventHandler *this, struct CEvn_Event *a2)
void  CGuiEventHandler::HandleMsgOpenSettings(class CEvn_Event &) {
  
  char result; // al
  _DWORD *lparam; // [esp+4h] [ebp-8h]

  result = (char)a2;
  lparam = (_DWORD *)a2->lparam;
  if ( !lparam )
    return result;
  if ( *((_DWORD *)this + 3) != -1 )
  {
    IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)this + 3));
    *((_DWORD *)this + 3) = -1;
  }
  result = (char)lparam;
  switch ( *lparam )
  {
    case 0:
      IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 36, GuiDlgSettingsGraphicProc);
      result = (char)this;
      *((_DWORD *)this + 3) = 36;
      break;
    case 1:
      result = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 37, GuiDlgSettingsSoundProc);
      *((_DWORD *)this + 3) = 37;
      break;
    case 2:
      result = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 38, GuiDlgSettingsGameProc);
      *((_DWORD *)this + 3) = 38;
      break;
    case 3:
      IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 39, GuiDlgSettingsMessagesProc);
      result = (char)this;
      *((_DWORD *)this + 3) = 39;
      break;
    case 4:
      result = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 58, GuiDlgChatProc);
      *((_DWORD *)this + 3) = 58;
      break;
    case 5:
      result = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 33, GuiDlgLoadSaveProc);
      *((_DWORD *)this + 3) = 33;
      break;
    default:
      return result;
  }
  return result;
}


// address=[0x139d150]
// Decompiled from char __thiscall CGuiEventHandler::HandleMsgOpenSidebar(CGuiEventHandler *this, struct CEvn_Event *a2)
void  CGuiEventHandler::HandleMsgOpenSidebar(class CEvn_Event &) {
  
  int v2; // eax
  int lparam; // [esp+0h] [ebp-Ch]

  LOBYTE(v2) = (_BYTE)a2;
  lparam = a2->lparam;
  if ( !lparam )
    return v2;
  if ( *((_DWORD *)this + 4) != -1 )
  {
    IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)this + 4));
    *((_DWORD *)this + 4) = -1;
  }
  v2 = *(_DWORD *)(lparam + 4) - 11;
  switch ( *(_DWORD *)(lparam + 4) )
  {
    case 0xB:
      IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 46, GuiDlgWeaponsmithBarProc);
      LOBYTE(v2) = (_BYTE)this;
      *((_DWORD *)this + 4) = 46;
      break;
    case 0xC:
      LOBYTE(v2) = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 47, GuiDlgAddToolBarProc);
      *((_DWORD *)this + 4) = 47;
      break;
    case 0xD:
      LOBYTE(v2) = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 54, GuiDlgGoodstradeBarProc);
      *((_DWORD *)this + 4) = 54;
      break;
    case 0xE:
      LOBYTE(v2) = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 53, GuiDlgGoodsoutBarProc);
      *((_DWORD *)this + 4) = 53;
      break;
    case 0xF:
      IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 50, GuiDlgAddStorageBarProc);
      LOBYTE(v2) = (_BYTE)this;
      *((_DWORD *)this + 4) = 50;
      break;
    case 0x10:
      LOBYTE(v2) = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 48, GuiDlgAddSoldierBarProc);
      *((_DWORD *)this + 4) = 48;
      break;
    case 0x11:
      LOBYTE(v2) = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 51, GuiDlgAddVehicleBarProc);
      *((_DWORD *)this + 4) = 51;
      break;
    case 0x19:
      IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 55, GuiDlgGroupProc);
      LOBYTE(v2) = (_BYTE)this;
      *((_DWORD *)this + 4) = 55;
      break;
    case 0x1A:
      LOBYTE(v2) = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 56, GuiDlgMagicSpellBarProc);
      *((_DWORD *)this + 4) = 56;
      break;
    case 0x1B:
      LOBYTE(v2) = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 52, GuiDlgBuildEyecatcherProc);
      *((_DWORD *)this + 4) = 52;
      break;
    default:
      return v2;
  }
  return v2;
}


// address=[0x139d340]
// Decompiled from CGuiEventHandler *__thiscall CGuiEventHandler::HandleMsgCloseAllDialogs(CGuiEventHandler *this)
void  CGuiEventHandler::HandleMsgCloseAllDialogs(void) {
  
  CGuiEventHandler *result; // eax
  CEvn_Logic *v2; // [esp+4h] [ebp-3Ch]
  _BYTE v4[32]; // [esp+10h] [ebp-30h] BYREF
  int v5; // [esp+3Ch] [ebp-4h]

  if ( *((_DWORD *)this + 13) != -1 )
  {
    IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)this + 13));
    *((_DWORD *)this + 13) = -1;
  }
  if ( *((_DWORD *)this + 4) != -1 )
  {
    IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)this + 4));
    *((_DWORD *)this + 4) = -1;
  }
  if ( *((_DWORD *)this + 3) != -1 )
  {
    IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)this + 3));
    *((_DWORD *)this + 3) = 0;
  }
  if ( *((_DWORD *)this + 7) != -1 )
  {
    IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)this + 7));
    *((_DWORD *)this + 7) = -1;
  }
  if ( *((_DWORD *)this + 6) != -1 )
  {
    IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)this + 6));
    *((_DWORD *)this + 6) = -1;
  }
  if ( *((_DWORD *)this + 5) != -1 )
  {
    IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)this + 5));
    *((_DWORD *)this + 5) = -1;
  }
  if ( *((_DWORD *)this + 8) != -1 )
  {
    v2 = CEvn_Logic::CEvn_Logic((CEvn_Logic *)v4, 0x1E2u, 0, 0, 0, 0, 0);
    v5 = 0;
    IEventEngine::SendAMessage(g_pEvnEngine, v2);
    v5 = -1;
    CEvn_Logic::~CEvn_Logic(v4);
    *((_BYTE *)this + 5) = 0;
    IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)this + 8));
    *((_DWORD *)this + 8) = -1;
  }
  if ( *((_DWORD *)this + 9) != -1 )
  {
    IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)this + 9));
    *((_DWORD *)this + 9) = -1;
  }
  if ( *((_DWORD *)this + 10) != -1 )
  {
    IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)this + 10));
    *((_DWORD *)this + 10) = -1;
  }
  if ( *((_DWORD *)this + 11) != -1 )
  {
    IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)this + 11));
    *((_DWORD *)this + 11) = -1;
  }
  if ( *((_DWORD *)this + 12) != -1 )
  {
    IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)this + 12));
    *((_DWORD *)this + 12) = -1;
  }
  if ( *((_DWORD *)this + 14) != -1 )
  {
    IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)this + 14));
    *((_DWORD *)this + 14) = -1;
  }
  result = this;
  if ( *((_DWORD *)this + 15) == -1 )
    return result;
  IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)this + 15));
  result = this;
  *((_DWORD *)this + 15) = -1;
  return result;
}


// address=[0x139d5c0]
// Decompiled from void __thiscall CGuiEventHandler::HandleMsgRefreshDialog(CGuiEventHandler *this, struct CEvn_Event *a2)
void  CGuiEventHandler::HandleMsgRefreshDialog(class CEvn_Event &) {
  
  int lparam; // [esp+10h] [ebp-4h]

  lparam = a2->lparam;
  if ( lparam )
  {
    switch ( *(_DWORD *)(lparam + 4) )
    {
      case 0:
        UpdateGuiDlgBuildingContext();
        break;
      case 1:
        UpdateGuiDlgBuildContext();
        break;
      case 2:
        UpdateGuiDlgResourceCollectorContext();
        break;
      case 3:
        UpdateGuiDlgResourceUpgradeContext();
        break;
      case 4:
        UpdateGuiDlgMilitaryBuildingContext();
        break;
      case 5:
        UpdateGuiDlgPortContext();
        break;
      case 6:
        UpdateGuiDlgStorageContext();
        break;
      case 7:
        UpdateGuiDlgBarracksContext();
        break;
      case 8:
        UpdateGuiDlgSmallTempleContext();
        break;
      case 9:
        UpdateGuiDlgShipVehicleContext();
        break;
      case 0xB:
        UpdateGuiDlgWeaponsmithBar();
        break;
      case 0xC:
        UpdateGuiDlgAddToolBar();
        break;
      case 0xD:
        UpdateGuiDlgGoodstradeBar();
        break;
      case 0xE:
        UpdateGuiDlgGoodsoutBar();
        break;
      case 0xF:
        UpdateGuiDlgAddStorageBar();
        break;
      case 0x10:
        UpdateGuiDlgAddSoldierBar();
        break;
      case 0x11:
        UpdateGuiDlgAddVehicleBar();
        break;
      case 0x12:
        UpdateGuiDlgSoldierContext();
        break;
      case 0x13:
        UpdateGuiDlgSpecialistsContext();
        break;
      case 0x14:
        UpdateGuiDlgVehiclesContext();
        break;
      case 0x15:
      case 0x16:
      case 0x18:
        UpdateGuiDlgVehicleLoadContext();
        break;
      case 0x17:
        UpdateGuiDlgFerryLoadContext();
        break;
      case 0x19:
        UpdateGuiDlgGroup();
        break;
      case 0x1A:
        UpdateGuiDlgMagicSpellBar();
        break;
      case 0x1B:
        UpdateGuiDlgBuildEyecatcher();
        break;
      case 0x1C:
        switch ( *(_BYTE *)(lparam + 8) )
        {
          case 0:
            UpdateGuiDlgBuildBasic();
            break;
          case 1:
            UpdateGuiDlgBuildFood();
            break;
          case 2:
            UpdateGuiDlgBuildMetal();
            break;
          case 3:
            UpdateGuiDlgBuildTown();
            break;
          case 4:
            UpdateGuiDlgBuildMilitary();
            break;
          default:
            return;
        }
        break;
      case 0x1D:
        UpdateGuiDlgSettlerStatisticMenu();
        break;
      case 0x1E:
        UpdateGuiDlgSettlerProductionMenu();
        break;
      case 0x1F:
        UpdateGuiDlgFreeCarrierMenu();
        break;
      case 0x20:
        UpdateGuiDlgAvailableGoods();
        break;
      case 0x21:
        UpdateGuiDlgTransportpriority();
        break;
      case 0x22:
        UpdateGuiDlgGoodDistribution();
        break;
      case 0x24:
        UpdateGuiDlgEconomy();
        break;
      case 0x25:
        if ( *((_DWORD *)this + 8) != -1 )
          UpdateGuiDlgMainBarExt1();
        break;
      default:
        return;
    }
  }
}


// address=[0x139d830]
// Decompiled from void __thiscall CGuiEventHandler::HandleMsgRefreshSettingsDialog(CGuiEventHandler *this, struct CEvn_Event *a2)
void  CGuiEventHandler::HandleMsgRefreshSettingsDialog(class CEvn_Event &) {
  
  _DWORD *lparam; // [esp+8h] [ebp-4h]

  lparam = (_DWORD *)a2->lparam;
  if ( lparam )
  {
    switch ( *lparam )
    {
      case 0:
        UpdateGuiDlgSettingsGraphic();
        break;
      case 1:
        UpdateGuiDlgSettingsSound();
        break;
      case 2:
        UpdateGuiDlgSettingsGame();
        break;
      case 3:
        UpdateGuiDlgSettingsMessages();
        break;
      case 4:
        UpdateGuiDlgChat();
        goto LABEL_8;
      case 5:
LABEL_8:
        UpdateGuiDlgLoadSave();
        break;
      default:
        return;
    }
  }
}


// address=[0x139d8b0]
// Decompiled from char __thiscall CGuiEventHandler::ResetMainMenu(CGuiEventHandler *this)
void  CGuiEventHandler::ResetMainMenu(void) {
  
  char result; // al

  result = (char)this;
  if ( *((_DWORD *)this + 5) != -1 )
    return IGuiEngine::SelectControl((IGuiEngine *)g_pGUIEngine, 0, 606, 1);
  return result;
}


// address=[0x139d8e0]
// Decompiled from CGuiEventHandler *__thiscall CGuiEventHandler::ResetMainMenuForContext(CGuiEventHandler *this)
void  CGuiEventHandler::ResetMainMenuForContext(void) {
  
  CGuiEventHandler *result; // eax
  CEvn_Event *v2; // [esp+4h] [ebp-5Ch]
  CEvn_Logic *v3; // [esp+Ch] [ebp-54h]
  _BYTE v5[32]; // [esp+18h] [ebp-48h] BYREF
  CEvn_Event v6; // [esp+38h] [ebp-28h] BYREF
  int v7; // [esp+5Ch] [ebp-4h]

  v3 = CEvn_Logic::CEvn_Logic((CEvn_Logic *)v5, 0x1CCu, 0, 0, 0, 0, 0);
  v7 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, v3);
  v7 = -1;
  CEvn_Logic::~CEvn_Logic(v5);
  v2 = CEvn_Event::CEvn_Event(&v6, 0x260u, 0, 0, 0);
  v7 = 1;
  IEventEngine::SendAMessage(g_pEvnEngine, v2);
  v7 = -1;
  CEvn_Event::~CEvn_Event(&v6);
  if ( *((_DWORD *)this + 5) != -1 )
    IGuiEngine::ResetRadioGroup((IGuiEngine *)g_pGUIEngine, 0, 606);
  if ( *((_DWORD *)this + 3) != -1 )
  {
    IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)this + 3));
    *((_DWORD *)this + 3) = -1;
  }
  result = this;
  if ( *((_DWORD *)this + 6) == -1 )
    return result;
  IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)this + 6));
  result = this;
  *((_DWORD *)this + 6) = -1;
  return result;
}


// address=[0x139f020]
// Decompiled from _DWORD *__thiscall CGuiEventHandler::GetTextMessageDialogParameters(_BYTE *this, _DWORD *a2)
struct CGuiEventHandler::GuiDialogParameters  CGuiEventHandler::GetTextMessageDialogParameters(void)const {
  
  if ( IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine) < 1280 )
  {
    if ( IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine) < 1024 )
    {
      if ( *(_DWORD *)(g_pGame + 360) )
      {
        if ( this[64] )
        {
          *a2 = 66;
          a2[1] = GuiDlgTutorialProc;
        }
        else
        {
          *a2 = 60;
          a2[1] = GuiDlgMessagesProc;
        }
        return a2;
      }
      else
      {
        if ( this[64] )
        {
          *a2 = 67;
          a2[1] = GuiDlgTutorialProc;
        }
        else
        {
          *a2 = 61;
          a2[1] = GuiDlgMessagesProc;
        }
        return a2;
      }
    }
    else if ( *(_DWORD *)(g_pGame + 360) )
    {
      if ( this[64] )
      {
        *a2 = 68;
        a2[1] = GuiDlgTutorialProc;
      }
      else
      {
        *a2 = 62;
        a2[1] = GuiDlgMessagesProc;
      }
      return a2;
    }
    else
    {
      if ( this[64] )
      {
        *a2 = 69;
        a2[1] = GuiDlgTutorialProc;
      }
      else
      {
        *a2 = 63;
        a2[1] = GuiDlgMessagesProc;
      }
      return a2;
    }
  }
  else if ( *(_DWORD *)(g_pGame + 360) )
  {
    if ( this[64] )
    {
      *a2 = 70;
      a2[1] = GuiDlgTutorialProc;
    }
    else
    {
      *a2 = 64;
      a2[1] = GuiDlgMessagesProc;
    }
    return a2;
  }
  else
  {
    if ( this[64] )
    {
      *a2 = 71;
      a2[1] = GuiDlgTutorialProc;
    }
    else
    {
      *a2 = 65;
      a2[1] = GuiDlgMessagesProc;
    }
    return a2;
  }
}


