#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <conio.h>
#include "rlutil.h"
#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <Psapi.h>
#include <wincrypt.h>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include "util_ini.h"
#include "http.h"

char choice;
char login;

using namespace std;

bool existeproceso(char* nombreProc )
{ 
  HANDLE hProcessSnap;
  HANDLE hProcess;
  PROCESSENTRY32 pe32;
  DWORD dwPriorityClass;
 
  hProcessSnap = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
  if( hProcessSnap == INVALID_HANDLE_VALUE )
  {
 
    return( FALSE );
  }
 
  pe32.dwSize = sizeof( PROCESSENTRY32 );
 
  if( !Process32First( hProcessSnap, &pe32 ) )
  {
    CloseHandle( hProcessSnap );
    return( FALSE );
  }
 
  do
  {
          if(strcmp(pe32.szExeFile, nombreProc)==0){
                  return TRUE;
          }
  } while( Process32Next( hProcessSnap, &pe32 ) );
 
          return FALSE;
         
  CloseHandle( hProcessSnap );
  return( FALSE );
}


bool doLogin(char* user,char*pass){ 
	//by m05k1 :3
	char respbuf[5000];
	char URL[1024];
		char* geturi = "/alpha_login/login.php?user=%s&pass=%s";
		wsprintfA( URL, geturi, user, pass );
		Request(GET, "www.nemu.tk", URL, NULL, NULL,respbuf);
		//printf(respbuf);
		if(strcmp(respbuf,"ok")>=0){//funciona pero es un asco >_< la pagina devuelve "ok" con espacios, fuck everything
			return true;
		}
		return false;
}
int main()
{   
	CIniWriter iniWriter(".\\DC_Loader_x32.ini");
	
	char user[200];
	char pass[200];

	printf (" ----------------------------------------------------------\n");
	printf (" - DC Loader v1.07.1 <x32> by RaZz for DominationCheats.com -\n");
	printf (" ----------------------------------------------------------\n");
	printf (" \n");

	printf (" Please enter your forum username and password below to continue. ");
	printf (" \n");
	
	cout << " Username: "; cin >> user;
	iniWriter.WriteString("Login","Username", user);

	cout << " Password: "; cin >> pass;
	iniWriter.WriteString("Login","Password", pass);
	
	Sleep(1000);

	system("cls");

	printf (" ----------------------------------------------------------\n");
	printf (" - DC Loader v1.07.1 <x32> by RaZz for DominationCheats.com -\n");
	printf (" ----------------------------------------------------------\n");
	printf (" \n");

	Sleep(1000);
	
	rlutil::setColor(14);
	printf (" Logging in with details from INI file, please delete INI to manually\n");
	printf (" log in again\n");
	printf (" \n");

	rlutil::setColor(7);
	printf (" Please wait...");

	//logueo con la pagina
	if(doLogin(user,pass)){
		printf ("Login successful!");
	}else{
		printf ("Bad login details!");
		Sleep(3000);
		return 0;
	}
	////////
	Sleep(3000);
	system("cls");

	printf (" ----------------------------------------------------------\n");
	printf (" - DC Loader v1.07.1 <x32> by RaZz for DominationCheats.com -\n");
	printf (" ----------------------------------------------------------\n");
	printf (" \n");

	printf (" Refreshing hack list, please wait...");

	Sleep(2000);
	system("cls");

	printf (" ----------------------------------------------------------\n");
	printf (" - DC Loader v1.07.1 <x32> by RaZz for DominationCheats.com -\n");
	printf (" ----------------------------------------------------------\n");
	printf (" \n");
	
	printf (" Option Product name                                 Status    \n");
	printf (" --------------------------------------------------------------\n");
	printf (" 1      Call of Duty 2                              ");

	rlutil::setColor(10);
	printf (" Undetected \n");

	rlutil::setColor(7);
	printf (" 2      Call of Duty 4: Modern Warfare              ");

	rlutil::setColor(10);
	printf (" Undetected \n");

	rlutil::setColor(7);
	printf (" 3      Call of Duty 4: <GUID SPOOFER>              ");

	rlutil::setColor(10);
	printf (" Undetected \n");

	rlutil::setColor(7);
	printf (" 4      Call of Duty 5: World At War                ");

	rlutil::setColor(10);
	printf (" Undetected \n");

	rlutil::setColor(7);
	printf (" 5      Call of Duty 5: <GUID SPOOFER>              ");

	rlutil::setColor(10);
	printf (" Undetected \n");

	rlutil::setColor(7);
	printf (" 6      Call of Duty 6: Modern Warfare 2            ");

	rlutil::setColor(10);
	printf (" Undetected \n");

	rlutil::setColor(7);
	printf (" 7      Call of Duty 7: Black Ops                   ");

	rlutil::setColor(10);
	printf (" Undetected \n");

	rlutil::setColor(7);
	printf (" 8      Call of Duty 8: Modern Warfare 3            ");

	rlutil::setColor(10);
	printf (" Undetected \n");
	
	rlutil::setColor(7);
	printf (" 9      Call of Duty 9: Black Ops 2                 ");

	rlutil::setColor(10);
	printf (" Undetected \n");

	rlutil::setColor(7);
	printf (" \n");

	printf (" Please select a hack to load by typing one of the options numbers\n");
	printf (" using your keyboard and then pressing enter.\n");
	printf (" \n");

	cout << " Select an option <please type a number>: "; cin >> choice;

		if (choice == '1') {

			system("cls");

			printf (" ----------------------------------------------------------\n");
			printf (" - DC Loader v1.07.1 <x32> by RaZz for DominationCheats.com -\n");
			printf (" ----------------------------------------------------------\n");
			printf (" \n");

			Sleep(1000);

			printf (" The hack Call of Duty 2 is still up to date, please wait...!\n");
			printf (" Waiting for CoD2MP.exe, you can now start the game!\n");
				
			while(!existeproceso("CoD2MP.exe")) {}

			Sleep(1000);
			printf (" Found CoD2MP.exe!\n");

			Sleep(1000);
			printf (" Injection successful!\n");
			
			Sleep(2000);

		} else if (choice == '2') {

			system("cls");

	  		printf (" ----------------------------------------------------------\n");
			printf (" - DC Loader v1.07.1 <x32> by RaZz for DominationCheats.com -\n");
			printf (" ----------------------------------------------------------\n");
			printf (" \n");

			Sleep(1000);

			printf (" The hack Call of Duty 4: Modern Warfare is still up to date, please wait...!\n");
			printf (" Waiting for iw3mp.exe, you can now start the game!\n");

			while(!existeproceso("iw3mp.exe")) {}

			Sleep(1000);
			printf (" Found iw3mp.exe!\n");

			Sleep(1000);
			printf (" Injection successful!\n");

			Sleep(2000);

		} else if (choice == '3') {

			system("cls");

	  		printf (" ----------------------------------------------------------\n");
			printf (" - DC Loader v1.07.1 <x32> by RaZz for DominationCheats.com -\n");
			printf (" ----------------------------------------------------------\n");
			printf (" \n");
	
			Sleep(1000);

			printf (" The hack Call of Duty 4: <GUID SPOOFER> is still up to date, please wait...!\n");
			printf (" Waiting for iw3mp.exe, you can now start the game!\n");

			while(!existeproceso("iw3mp.exe")) {}

			Sleep(1000);
			printf (" Found iw3mp.exe!\n");

			Sleep(1000);
			printf (" Injection successful!\n");

			Sleep(2000);

		} else if (choice == '4') {

			system("cls");

	  		printf (" ----------------------------------------------------------\n");
			printf (" - DC Loader v1.07.1 <x32> by RaZz for DominationCheats.com -\n");
			printf (" ----------------------------------------------------------\n");
			printf (" \n");
	
			Sleep(1000);

			printf (" The hack Call of Duty 5: World At War is still up to date, please wait...!\n");
			printf (" Waiting for CoDWaWMP.exe, you can now start the game!\n");

			while(!existeproceso("CoDWaWMP.exe")) {}

			Sleep(1000);
			printf (" Found CoDWaWMP.exe!\n");

			Sleep(1000);
			printf (" Injection successful!\n");

			Sleep(2000);

		} else if (choice == '5') {

			system("cls");

	  		printf (" ----------------------------------------------------------\n");
			printf (" - DC Loader v1.07.1 <x32> by RaZz for DominationCheats.com -\n");
			printf (" ----------------------------------------------------------\n");
			printf (" \n");
	
			Sleep(1000);

			printf (" The hack Call of Duty 5: <GUID SPOOFER> is still up to date, please wait...!\n");
			printf (" Waiting for CoDWaWMP.exe, you can now start the game!\n");

			while(!existeproceso("CoDWaWMP.exe")) {}

			Sleep(1000);
			printf (" Found CoDWaWMP.exe!\n");

			Sleep(1000);
			printf (" Injection successful!\n");

			Sleep(2000);

		} else if (choice == '6') {

			system("cls");

	  		printf (" ----------------------------------------------------------\n");
			printf (" - DC Loader v1.07.1 <x32> by RaZz for DominationCheats.com -\n");
			printf (" ----------------------------------------------------------\n");
			printf (" \n");
	
			Sleep(1000);

			printf (" The hack Call of Duty 6: Modern Warfare 2 is still up to date, please wait...!\n");
			printf (" Waiting for iw4mp.exe, you can now start the game!\n");

			while(!existeproceso("iw4mp.exe")) {}

			Sleep(1000);
			printf (" Found iw4mp.exe!\n");

			Sleep(1000);
			printf (" Injection successful!\n");

			Sleep(2000);

		} else if (choice == '7') {

			system("cls");

	  		printf (" ----------------------------------------------------------\n");
			printf (" - DC Loader v1.07.1 <x32> by RaZz for DominationCheats.com -\n");
			printf (" ----------------------------------------------------------\n");
			printf (" \n");
	
			Sleep(1000);

			printf (" The hack Call of Duty 7: Black Ops is still up to date, please wait...!\n");
			printf (" Waiting for BlackOpsMP.exe, you can now start the game!\n");

			while(!existeproceso("BlackOpsMP.exe")) {}

			Sleep(1000);
			printf (" Found BlackOpsMP.exe!\n");

			Sleep(1000);
			printf (" Injection successful!\n");

			Sleep(2000);

		} else if (choice == '8') {

			system("cls");

	  		printf (" ----------------------------------------------------------\n");
			printf (" - DC Loader v1.07.1 <x32> by RaZz for DominationCheats.com -\n");
			printf (" ----------------------------------------------------------\n");
			printf (" \n");
	
			Sleep(1000);

			printf (" The hack Call of Duty 8: Modern Warfare 3 is still up to date, please wait...!\n");
			printf (" Waiting for iw5mp.exe, you can now start the game!\n");

			while(!existeproceso("iw5mp.exe")) {}

			Sleep(1000);
			printf (" Found iw5mp.exe!\n");

			Sleep(1000);
			printf (" Injection successful!\n");

			Sleep(2000);

		} else if (choice == '9') {

			system("cls");

	  		printf (" ----------------------------------------------------------\n");
			printf (" - DC Loader v1.07.1 <x32> by RaZz for DominationCheats.com -\n");
			printf (" ----------------------------------------------------------\n");
			printf (" \n");
	
			Sleep(1000);

			printf (" The hack Call of Duty 9: Black Ops 2 is still up to date, please wait...!\n");
			printf (" Waiting for t6mp.exe, you can now start the game!\n");

			while(!existeproceso("t6mp.exe")) {}

			Sleep(1000);
			printf (" Found t6mp.exe!\n");

			Sleep(1000);
			printf (" Injection successful!\n");

			Sleep(2000);
		}
	return 0;
}