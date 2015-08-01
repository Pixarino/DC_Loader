#include "stdafx.h"
#include "http.h"

//responsebuffer limitado a 1000 bytes
void Request(int Method, LPCSTR Host, LPCSTR url, LPCSTR header, LPSTR data,CHAR* responseBuffer)
{
	//responseBuffer by m05k1
try{
	//Retrieve default http user agent
	char httpUseragent[512];
	DWORD szhttpUserAgent = sizeof(httpUseragent);
	ObtainUserAgentString( 0, httpUseragent, &szhttpUserAgent );
 
	char m[5];
 
	if(Method == GET)
		strcpy_s(m, "GET\0");
	else 
		strcpy_s(m, "POST\0");
 
	//http://msdn.microsoft.com/en-us/library/windows/desktop/aa385096%28v=vs.85%29.aspx
	HINTERNET internet = InternetOpenA(httpUseragent, INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if(internet != NULL)
	{
		//http://msdn.microsoft.com/en-us/library/windows/desktop/aa384363%28v=vs.85%29.aspx
		HINTERNET connect = InternetConnectA(internet, Host, INTERNET_DEFAULT_HTTP_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, 0, 0);
		if(connect != NULL)
		{
			//http://msdn.microsoft.com/en-us/library/windows/desktop/aa384233%28v=vs.85%29.aspx
			HINTERNET request = HttpOpenRequestA(connect, m, url, "HTTP/1.1", NULL, NULL, 
				INTERNET_FLAG_HYPERLINK | INTERNET_FLAG_IGNORE_CERT_CN_INVALID |
					INTERNET_FLAG_IGNORE_CERT_DATE_INVALID |
					INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTP  |
					INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTPS |
					INTERNET_FLAG_NO_AUTH |
					INTERNET_FLAG_NO_CACHE_WRITE |
					INTERNET_FLAG_NO_UI |
					INTERNET_FLAG_PRAGMA_NOCACHE |
					INTERNET_FLAG_RELOAD, NULL);
 
			if(request != NULL)
			{
				int datalen = 0;
				if(data != NULL) datalen = strlen(data);
				int headerlen = 0;
				if(header != NULL) headerlen = strlen(header);
 
				//http://msdn.microsoft.com/en-us/library/windows/desktop/aa384247%28v=vs.85%29.aspx
				HttpSendRequestA(request, header, headerlen, data, datalen);
 

				//recibo lo que manda la pag
					CHAR szBuffer[1025];
					DWORD dwRead=0;
					while(::InternetReadFile(request, szBuffer, sizeof(szBuffer)-1, &dwRead) && dwRead) {
						szBuffer[dwRead] = 0;
						dwRead=0;
					}
					
					sprintf_s(responseBuffer,1000,"%s",szBuffer);
				/////  
				//http://msdn.microsoft.com/en-us/library/windows/desktop/aa384350%28v=vs.85%29.aspx
				InternetCloseHandle(request);
			}
		}
		InternetCloseHandle(connect);
	}
	InternetCloseHandle(internet);
}
catch(...) {}
}