#if FALSE
#include "CClientList.h"

// Definitions for class CClientList

// address=[0x15b1d30]
// Decompiled from int __thiscall CClientList::GetPlayerIP(CClientList *this, unsigned int a1)
long  CClientList::GetPlayerIP(int a1) {
  
  CClient *v2; // eax

  v2 = std::vector<CClient>::operator[](&this->m_vClients, a1);
  return CClient::GetIP(v2);
}


// address=[0x15b1d60]
// Decompiled from int __thiscall CClientList::GetPlayerPeerId(CClientList *this, unsigned int a1)
unsigned int  CClientList::GetPlayerPeerId(int a2) {
  
  CClient *v2; // eax

  v2 = std::vector<CClient>::operator[](&this->m_vClients, a1);
  return CClient::GetPeerId(v2);
}


// address=[0x15b1d90]
// Decompiled from char __thiscall CClientList::ContainsPeerId(CClientList *this, uint _uPeerId)
bool  CClientList::ContainsPeerId(unsigned int _uPeerId) {
  
  unsigned int iSize; // eax
  CClient *v3; // eax
  CClient v5; // [esp+4h] [ebp-3Ch] BYREF
  unsigned int i; // [esp+2Ch] [ebp-14h]
  char v8; // [esp+33h] [ebp-Dh]
  int exceptionBlock; // [esp+3Ch] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    iSize = std::vector<CClient>::size(&this->m_vClients);
    if ( i >= iSize )
      break;
    v3 = std::vector<CClient>::operator[](&this->m_vClients, i);
    CClient::CClient(&v5, v3);
    exceptionBlock = 0;
    if ( CClient::operator==(&v5, _uPeerId) )
    {
      v8 = 1;
      exceptionBlock = -1;
      CClient::~CClient(&v5);
      return v8;
    }
    exceptionBlock = -1;
    CClient::~CClient(&v5);
  }
  return 0;
}


// address=[0x15b1e50]
// Decompiled from char __thiscall CClientList::Add(CClientList *this, int _uIp, int _uPlayerId, int _uPeerId)
bool  CClientList::Add(unsigned int _uIp, int _uPlayerId, int _uPeerId) {
  
  _DWORD v5[3]; // [esp-10h] [ebp-78h] BYREF
  CClient *v6; // [esp-4h] [ebp-6Ch]
  CClient v7; // [esp+4h] [ebp-64h] BYREF
  _BYTE v8[12]; // [esp+28h] [ebp-40h] BYREF
  _BYTE v9[12]; // [esp+34h] [ebp-34h] BYREF
  int v10; // [esp+40h] [ebp-28h]
  _DWORD *v11; // [esp+44h] [ebp-24h]
  _DWORD *v12; // [esp+48h] [ebp-20h]
  struct std::_Iterator_base12 *v13; // [esp+4Ch] [ebp-1Ch]
  struct std::_Iterator_base12 *v14; // [esp+50h] [ebp-18h]
  int v17; // [esp+64h] [ebp-4h]

  if ( CClientList::ContainsPeerId(this, _uPeerId) )
    return 0;
  CClient::CClient(&v7, _uIp, _uPlayerId, _uPeerId);
  v17 = 0;
  v6 = &v7;
  v14 = (struct std::_Iterator_base12 *)std::vector<CClient>::end(&this->m_vClients, (int)v8);
  v13 = v14;
  LOBYTE(v17) = 1;
  v12 = v5;
  v11 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CClient>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CClient>>>(
          v5,
          v14);
  v10 = std::vector<CClient>::insert((int)v9, v5[0], v5[1], v5[2], (int)v6);
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CClient>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CClient>>>(v9);
  LOBYTE(v17) = 0;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CClient>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CClient>>>(v8);
  v17 = -1;
  CClient::~CClient(&v7);
  return 0;
}


// address=[0x15b1f30]
// Decompiled from int __thiscall CClientList::GetPlayerPing(CClientList *this, unsigned int _id)
unsigned int  CClientList::GetPlayerPing(unsigned int _id) {
  
  CClient *v3; // [esp+0h] [ebp-8h]

  if ( _id > CClientList::GetSize(this) - 1
    && BBSupportDbgReport(2, "Net\\ClientList.cpp", 235, "_id <= GetSize() - 1") == 1 )
  {
    __debugbreak();
  }
  v3 = std::vector<CClient>::operator[](&this->m_vClients, _id);
  return CClient::GetLastPingTime(v3);
}


// address=[0x15b1f90]
// Decompiled from void __thiscall CClientList::CClientList(CClientList *this)
 CClientList::CClientList(void) {
  
  this->vftable = (CClientList_vtbl *)&CClientList::_vftable_;
  std::vector<CClient>::vector<CClient>(this);
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
  
  return std::vector<CClient>::size(&this->m_vClients);
}


// address=[0x15b2000]
// Decompiled from char __thiscall CClientList::RemoveClientAt(CClientList *this, unsigned int a2)
bool  CClientList::RemoveClientAt(int a2) {
  
  _DWORD v3[4]; // [esp-Ch] [ebp-48h] BYREF
  _BYTE v4[12]; // [esp+4h] [ebp-38h] BYREF
  _BYTE v5[12]; // [esp+10h] [ebp-2Ch] BYREF
  int v6; // [esp+1Ch] [ebp-20h]
  int v7; // [esp+20h] [ebp-1Ch]
  _DWORD *v8; // [esp+24h] [ebp-18h]
  char v10; // [esp+2Fh] [ebp-Dh]
  int v11; // [esp+38h] [ebp-4h]

  if ( a2 > std::vector<CClient>::size(&this->m_vClients) - 1 )
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
bool  CClientList::RemoveClientPeerId(unsigned int a2) {
  
  CClient *v2; // eax
  _DWORD v4[4]; // [esp-Ch] [ebp-5Ch] BYREF
  _BYTE v5[12]; // [esp+4h] [ebp-4Ch] BYREF
  _BYTE v6[12]; // [esp+10h] [ebp-40h] BYREF
  _BYTE v7[12]; // [esp+1Ch] [ebp-34h] BYREF
  int v8; // [esp+28h] [ebp-28h]
  int v9; // [esp+2Ch] [ebp-24h]
  _DWORD *v10; // [esp+30h] [ebp-20h]
  std::_Iterator_base12 *v11; // [esp+34h] [ebp-1Ch]
  std::_Iterator_base12 *v12; // [esp+38h] [ebp-18h]
  char v14; // [esp+42h] [ebp-Eh]
  char v15; // [esp+43h] [ebp-Dh]
  int v16; // [esp+4Ch] [ebp-4h]

  std::vector<CClient>::begin(v7);
  v16 = 0;
  while ( 1 )
  {
    v12 = (std::_Iterator_base12 *)std::vector<CClient>::end(&this->m_vClients, (int)v6);
    v11 = v12;
    LOBYTE(v16) = 1;
    v15 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CClient>>>::operator!=(v12);
    LOBYTE(v16) = 0;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CClient>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CClient>>>(v6);
    if ( !v15 )
      break;
    v2 = (CClient *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CClient>>>::operator*(v7);
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
  
  unsigned int a1; // [esp+4h] [ebp-4h]

  for ( a1 = 0; a1 < std::vector<CClient>::size(&this->m_vClients); ++a1 )
  {
    if ( !std::vector<CClient>::operator[](&this->m_vClients, a1)->m_bReady )
      return 0;
  }
  return 1;
}


// address=[0x15b2220]
// Decompiled from void __thiscall CClientList::SetClientReadyFromPeerId(CClientList *this, int _uPeerId, bool _bReady)
void  CClientList::SetClientReadyFromPeerId(unsigned int _uPeerId, bool _bReady) {
  
  unsigned int v3; // eax
  CClient *v4; // eax
  CClient v5; // [esp+4h] [ebp-38h] BYREF
  unsigned int i; // [esp+2Ch] [ebp-10h]
  int v8; // [esp+38h] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    v3 = std::vector<CClient>::size(&this->m_vClients);
    if ( i >= v3 )
      break;
    v4 = std::vector<CClient>::operator[](&this->m_vClients, i);
    CClient::CClient(&v5, v4);
    v8 = 0;
    if ( CClient::operator==(&v5, _uPeerId) )
    {
      std::vector<CClient>::operator[](&this->m_vClients, i)->m_bReady = _bReady;
      v8 = -1;
      CClient::~CClient(&v5);
      return;
    }
    v8 = -1;
    CClient::~CClient(&v5);
  }
  if ( BBSupportDbgReportF(2, "Net\\ClientList.cpp", 149, "Client not found !!!") == 1 )
    __debugbreak();
}


// address=[0x15b2320]
// Decompiled from unsigned int __thiscall CClientList::GetClientIndexPerPeerId(CClientList *this, uint _uPeerId)
int  CClientList::GetClientIndexPerPeerId(unsigned int _uPeerId) {
  
  unsigned int v2; // eax
  CClient *v3; // eax
  CClient v5; // [esp+4h] [ebp-3Ch] BYREF
  unsigned int v6; // [esp+28h] [ebp-18h]
  unsigned int a1; // [esp+30h] [ebp-10h]
  int v9; // [esp+3Ch] [ebp-4h]

  for ( a1 = 0; ; ++a1 )
  {
    v2 = std::vector<CClient>::size(&this->m_vClients);
    if ( a1 >= v2 )
      break;
    v3 = std::vector<CClient>::operator[](&this->m_vClients, a1);
    CClient::CClient(&v5, v3);
    v9 = 0;
    if ( CClient::operator==(&v5, _uPeerId) )
    {
      v6 = a1;
      v9 = -1;
      CClient::~CClient(&v5);
      return v6;
    }
    v9 = -1;
    CClient::~CClient(&v5);
  }
  return -1;
}


// address=[0x15b3b90]
// Decompiled from int __thiscall CClientList::GetSize(CClientList *this)
int  CClientList::GetSize(void) {
  
  return std::vector<CClient>::size(&this->m_vClients);
}


// address=[0x15c4d90]
// Decompiled from void __thiscall CClientList::SetClientLastAck(CClientList *this, unsigned int a1, unsigned int a3)
void  CClientList::SetClientLastAck(unsigned int a2, unsigned int a3) {
  
  CClient *v3; // eax

  v3 = std::vector<CClient>::operator[](&this->m_vClients, a1);
  CClient::SetLastAckTime(v3, a3);
}


#endif // Already implemented
