#include "stdafx.h"
#include <Windows.h>
#include <WinInet.h>
#include <cstdio>
#pragma comment (lib, "Wininet.lib")
#pragma comment (lib, "urlmon.lib")
#define POST 1
#define GET 0

void Request(int Method, LPCSTR Host, LPCSTR url, LPCSTR header, LPSTR data,CHAR* responseBuffer);
/*
uso:
//POST Request
char user[64] = "test123";
char pass[64] = "f4g5h6j7k8";
char data[1024];
char* posturi = "user=%s&pass=%s";
wsprintfA( data, posturi,  user, pass);
Request(POST, "localhost", "/testing/index.php", "Content-Type: application/x-www-form-urlencoded", data);
 
//---------------------------
 
//GET Request
char URL[1024];
char* geturi = "/testing/index.php?user=%s&pass=%s";
wsprintfA( URL, geturi, user, pass );
Request(GET, "localhost", URL, NULL, NULL);
*/