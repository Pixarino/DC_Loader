#include "stdafx.h"
#include "util_ini.h"
#include <iostream>
#include <Windows.h>
 
void LCase(char string[])
{
   int  i = 0;

   while ( string[i] )
   {
      string[i] = tolower(string[i]);
      i++;
   }

   return;
}

CIniReader::CIniReader(char* szFileName)
{
 memset(m_szFileName, 0x00, 255);
 memcpy(m_szFileName, szFileName, strlen(szFileName));
}
int CIniReader::ReadInteger(char* szSection, char* szKey, int iDefaultValue)
{
 int iResult = GetPrivateProfileIntA(szSection,  szKey, iDefaultValue, m_szFileName);
 return iResult;
}
float CIniReader::ReadFloat(char* szSection, char* szKey, float fltDefaultValue)
{
 char szResult[255];
 char szDefault[255];
 float fltResult;
 sprintf_s(szDefault,254, "%f",fltDefaultValue);
 GetPrivateProfileStringA(szSection,  szKey, szDefault, szResult, 255, m_szFileName);
 fltResult =  atof(szResult);
 return fltResult;
}
bool CIniReader::ReadBoolean(char* szSection, char* szKey, bool bolDefaultValue)
{
 char szResult[255];
 char szDefault[255];
 bool bolResult;
 sprintf_s(szDefault,200, "%s", bolDefaultValue? "true" : "false");
 GetPrivateProfileStringA(szSection, szKey, szDefault, szResult, 255, m_szFileName);
 LCase(szResult);
 bolResult =  (strcmp(szResult, "true") == 0) ? true : false;
 return bolResult;
}
char* CIniReader::ReadString(char* szSection, char* szKey, const char* szDefaultValue)
{
 char* szResult = new char[255];
 memset(szResult, 0x00, 255);
 GetPrivateProfileStringA(szSection,  szKey,
                szDefaultValue, szResult, 255, m_szFileName);
 return szResult;
}
 
CIniWriter::CIniWriter(char* szFileName)
{
 memset(m_szFileName, 0x00, 255);
 memcpy(m_szFileName, szFileName, strlen(szFileName));
}
void CIniWriter::WriteInteger(char* szSection, char* szKey, int iValue)
{
 char szValue[255];
 sprintf_s(szValue,254, "%d", iValue);
 WritePrivateProfileStringA(szSection,  szKey, szValue, m_szFileName);
}
void CIniWriter::WriteFloat(char* szSection, char* szKey, float fltValue)
{
 char szValue[255];
 sprintf_s(szValue,254, "%f", fltValue);
 WritePrivateProfileStringA(szSection,  szKey, szValue, m_szFileName);
}
void CIniWriter::WriteBoolean(char* szSection, char* szKey, bool bolValue)
{
 char szValue[255];
 sprintf_s(szValue,254, "%s", bolValue ? "true" : "false");
 WritePrivateProfileStringA(szSection,  szKey, szValue, m_szFileName);
}
void CIniWriter::WriteString(char* szSection, char* szKey, char* szValue)
{
 WritePrivateProfileStringA(szSection,  szKey, szValue, m_szFileName);
}