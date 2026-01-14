#include "all_headers.h"

// Definitions for class CClientList

// address=[0x15b1d30]
// Decompiled from int __thiscall CClientList::GetPlayerIP(CClientList *this, int a2)
long  CClientList::GetPlayerIP(int) {
  
  CClient *v2; // eax

  v2 = (CClient *)std::vector<CClient>::operator[](a2);
  return CClient::GetIP(v2);
}


// address=[0x15b1d60]
// Decompiled from int __thiscall CClientList::GetPlayerPeerId(CClientList *this, int a2)
unsigned int  CClientList::GetPlayerPeerId(int) {
  
  pairNode *v2; // eax

  v2 = (pairNode *)std::vector<CClient>::operator[](a2);
  return CClient::GetPeerId(v2);
}


// address=[0x15b1d90]
// Decompiled from char __thiscall CClientList::ContainsPeerId(CClientList *this, int a2)
bool  CClientList::ContainsPeerId(unsigned int) {
  
  unsigned int v2; // eax
  const struct CClient *v3; // eax
  _DWORD v5[9]; // [esp+4h] [ebp-3Ch] BYREF
  CClientList *v6; // [esp+28h] [ebp-18h]
  unsigned int i; // [esp+2Ch] [ebp-14h]
  char v8; // [esp+33h] [ebp-Dh]
  int v9; // [esp+3Ch] [ebp-4h]

  v6 = this;
  for ( i = 0; ; ++i )
  {
    v2 = std::vector<CClient>::size((char *)v6 + 4);
    if ( i >= v2 )
      break;
    v3 = (const struct CClient *)std::vector<CClient>::operator[](i);
    CClient::CClient((CClient *)v5, v3);
    v9 = 0;
    if ( CClient::operator==(v5, a2) )
    {
      v8 = 1;
      v9 = -1;
      CClient::~CClient((CClient *)v5);
      return v8;
    }
    v9 = -1;
    CClient::~CClient((CClient *)v5);
  }
  return 0;
}


// address=[0x15b1e50]
// Decompiled from char __thiscall CClientList::Add(CClientList *this, int a2, int a3, unsigned int a4)
bool  CClientList::Add(unsigned int,int,int) {
  
  char v5; // [esp-10h] [ebp-78h] BYREF
  int v6; // [esp-Ch] [ebp-74h]
  int v7; // [esp-8h] [ebp-70h]
  _BYTE *v8; // [esp-4h] [ebp-6Ch]
  _BYTE v9[36]; // [esp+4h] [ebp-64h] BYREF
  _BYTE v10[12]; // [esp+28h] [ebp-40h] BYREF
  _BYTE v11[12]; // [esp+34h] [ebp-34h] BYREF
  int v12; // [esp+40h] [ebp-28h]
  int v13; // [esp+44h] [ebp-24h]
  char *v14; // [esp+48h] [ebp-20h]
  struct std::_Iterator_base12 *v15; // [esp+4Ch] [ebp-1Ch]
  struct std::_Iterator_base12 *v16; // [esp+50h] [ebp-18h]
  int v17; // [esp+54h] [ebp-14h]
  CClientList *v18; // [esp+58h] [ebp-10h]
  int v19; // [esp+64h] [ebp-4h]

  v18 = this;
  if ( CClientList::ContainsPeerId(this, a4) )
    return 0;
  v17 = a2;
  CClient::CClient((CClient *)v9, a2, a3, a4);
  v19 = 0;
  v8 = v9;
  v16 = (struct std::_Iterator_base12 *)std::vector<CClient>::end(v10);
  v15 = v16;
  LOBYTE(v19) = 1;
  v14 = &v5;
  v13 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CClient>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CClient>>>(v16);
  v12 = std::vector<CClient>::insert(v11, v5, v6, v7, v8);
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CClient>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CClient>>>(v11);
  LOBYTE(v19) = 0;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CClient>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CClient>>>(v10);
  v19 = -1;
  CClient::~CClient((CClient *)v9);
  return 0;
}


// address=[0x15b1f30]
// Decompiled from int __thiscall CClientList::GetPlayerPing(CDaoIndexFieldInfo *this, unsigned int a2)
unsigned int  CClientList::GetPlayerPing(unsigned int) {
  
  int v2; // eax
  CClient *v4; // [esp+0h] [ebp-8h]

  CClientList::GetSize(this);
  if ( a2 > v2 - 1 && BBSupportDbgReport(2, "Net\\ClientList.cpp", 235, "_id <= GetSize() - 1") == 1 )
    __debugbreak();
  v4 = (CClient *)std::vector<CClient>::operator[](a2);
  return CClient::GetLastPingTime(v4);
}


// address=[0x15b1f90]
// Decompiled from CClientList *__thiscall CClientList::CClientList(CClientList *this)
 CClientList::CClientList(void) {
  
  CClientList *v2; // [esp+0h] [ebp-4h]

  *(_DWORD *)this = &CClientList::_vftable_;
  std::vector<CClient>::vector<CClient>(this);
  return v2;
}


// address=[0x15b1fc0]
// Decompiled from void __thiscall CClientList::~CClientList(boost::exception *this)
 CClientList::~CClientList(void) {
  
  *(_DWORD *)this = &CClientList::_vftable_;
  std::vector<CClient>::~vector<CClient>(this);
}


// address=[0x15b1fe0]
// Decompiled from int __thiscall CClientList::CreateNewPlayerID(CClientList *this)
int  CClientList::CreateNewPlayerID(void) {
  
  return std::vector<CClient>::size((char *)this + 4);
}


// address=[0x15b2000]
// Decompiled from char __thiscall CClientList::RemoveClientAt(char *this, unsigned int a2)
bool  CClientList::RemoveClientAt(int) {
  
  _DWORD v3[4]; // [esp-Ch] [ebp-48h] BYREF
  _BYTE v4[12]; // [esp+4h] [ebp-38h] BYREF
  _BYTE v5[12]; // [esp+10h] [ebp-2Ch] BYREF
  int v6; // [esp+1Ch] [ebp-20h]
  int v7; // [esp+20h] [ebp-1Ch]
  _DWORD *v8; // [esp+24h] [ebp-18h]
  char *v9; // [esp+28h] [ebp-14h]
  char v10; // [esp+2Fh] [ebp-Dh]
  int v11; // [esp+38h] [ebp-4h]

  v9 = this;
  if ( a2 > std::vector<CClient>::size(this + 4) - 1 )
    return 0;
  std::vector<CClient>::begin(v5);
  v11 = 0;
  std::advance<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CClient>>>,int>(v5, a2);
  v8 = v3;
  v7 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CClient>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CClient>>>((struct std::_Iterator_base12 *)v5);
  v6 = std::vector<CClient>::erase(v4, v3[0], v3[1], v3[2]);
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CClient>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CClient>>>(v4);
  v10 = 1;
  v11 = -1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CClient>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CClient>>>(v5);
  return v10;
}


// address=[0x15b20c0]
// Decompiled from char __thiscall CClientList::RemoveClientPeerId(CClientList *this, int a2)
bool  CClientList::RemoveClientPeerId(unsigned int) {
  
  _DWORD *v2; // eax
  _DWORD v4[4]; // [esp-Ch] [ebp-5Ch] BYREF
  _BYTE v5[12]; // [esp+4h] [ebp-4Ch] BYREF
  _BYTE v6[12]; // [esp+10h] [ebp-40h] BYREF
  _BYTE v7[12]; // [esp+1Ch] [ebp-34h] BYREF
  int v8; // [esp+28h] [ebp-28h]
  int v9; // [esp+2Ch] [ebp-24h]
  _DWORD *v10; // [esp+30h] [ebp-20h]
  std::_Iterator_base12 *v11; // [esp+34h] [ebp-1Ch]
  std::_Iterator_base12 *v12; // [esp+38h] [ebp-18h]
  CClientList *v13; // [esp+3Ch] [ebp-14h]
  char v14; // [esp+42h] [ebp-Eh]
  char v15; // [esp+43h] [ebp-Dh]
  int v16; // [esp+4Ch] [ebp-4h]

  v13 = this;
  std::vector<CClient>::begin(v7);
  v16 = 0;
  while ( 1 )
  {
    v12 = (std::_Iterator_base12 *)std::vector<CClient>::end(v6);
    v11 = v12;
    LOBYTE(v16) = 1;
    v15 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CClient>>>::operator!=(v12);
    LOBYTE(v16) = 0;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CClient>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CClient>>>(v6);
    if ( !v15 )
      break;
    v2 = (_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CClient>>>::operator*(v7);
    if ( CClient::operator==(v2, a2) )
    {
      v10 = v4;
      v9 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CClient>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CClient>>>((struct std::_Iterator_base12 *)v7);
      v8 = std::vector<CClient>::erase(v5, v4[0], v4[1], v4[2]);
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CClient>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CClient>>>(v5);
      v14 = 1;
      v16 = -1;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CClient>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CClient>>>(v7);
      return v14;
    }
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CClient>>>::operator++(v7);
  }
  v16 = -1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CClient>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CClient>>>(v7);
  return 0;
}


// address=[0x15b21d0]
// Decompiled from char __thiscall CClientList::AllClientsReady(CClientList *this)
bool  CClientList::AllClientsReady(void) {
  
  unsigned int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < std::vector<CClient>::size((char *)this + 4); ++i )
  {
    if ( !*(_BYTE *)(std::vector<CClient>::operator[](i) + 4) )
      return 0;
  }
  return 1;
}


// address=[0x15b2220]
// Decompiled from CClient *__thiscall CClientList::SetClientReadyFromPeerId(CClientList *this, int a2, bool a3)
void  CClientList::SetClientReadyFromPeerId(unsigned int,bool) {
  
  unsigned int v3; // eax
  const struct CClient *v4; // eax
  CClient *result; // eax
  _DWORD v6[9]; // [esp+4h] [ebp-38h] BYREF
  CClientList *v7; // [esp+28h] [ebp-14h]
  unsigned int i; // [esp+2Ch] [ebp-10h]
  int v9; // [esp+38h] [ebp-4h]

  v7 = this;
  for ( i = 0; ; ++i )
  {
    v3 = std::vector<CClient>::size((char *)v7 + 4);
    if ( i >= v3 )
      break;
    v4 = (const struct CClient *)std::vector<CClient>::operator[](i);
    CClient::CClient((CClient *)v6, v4);
    v9 = 0;
    if ( CClient::operator==(v6, a2) )
    {
      *(_BYTE *)(std::vector<CClient>::operator[](i) + 4) = a3;
      v9 = -1;
      return CClient::~CClient((CClient *)v6);
    }
    v9 = -1;
    CClient::~CClient((CClient *)v6);
  }
  result = (CClient *)BBSupportDbgReportF(2, "Net\\ClientList.cpp", 149, "Client not found !!!");
  if ( result == (CClient *)1 )
    __debugbreak();
  return result;
}


// address=[0x15b2320]
// Decompiled from int __thiscall CClientList::GetClientIndexPerPeerId(CClientList *this, int a2)
int  CClientList::GetClientIndexPerPeerId(unsigned int) {
  
  unsigned int v2; // eax
  const struct CClient *v3; // eax
  _DWORD v5[9]; // [esp+4h] [ebp-3Ch] BYREF
  unsigned int v6; // [esp+28h] [ebp-18h]
  CClientList *v7; // [esp+2Ch] [ebp-14h]
  unsigned int i; // [esp+30h] [ebp-10h]
  int v9; // [esp+3Ch] [ebp-4h]

  v7 = this;
  for ( i = 0; ; ++i )
  {
    v2 = std::vector<CClient>::size((char *)v7 + 4);
    if ( i >= v2 )
      break;
    v3 = (const struct CClient *)std::vector<CClient>::operator[](i);
    CClient::CClient((CClient *)v5, v3);
    v9 = 0;
    if ( CClient::operator==(v5, a2) )
    {
      v6 = i;
      v9 = -1;
      CClient::~CClient((CClient *)v5);
      return v6;
    }
    v9 = -1;
    CClient::~CClient((CClient *)v5);
  }
  return -1;
}


// address=[0x15b3b90]
// Decompiled from void __thiscall CClientList::GetSize(CDaoIndexFieldInfo *this)
int  CClientList::GetSize(void) {
  
  std::vector<CClient>::size((char *)this + 4);
}


// address=[0x15c4d90]
// Decompiled from CClient *__thiscall CClientList::SetClientLastAck(CClientList *this, unsigned int a2, unsigned int a3)
void  CClientList::SetClientLastAck(unsigned int,unsigned int) {
  
  CClient *v3; // eax

  v3 = (CClient *)std::vector<CClient>::operator[](a2);
  return CClient::SetLastAckTime(v3, a3);
}


