#include "stdafx.h"
#include "HTTPURL.h"

using namespace std;


void PrintUrlInformation(const CHttpUrl &cHttpUrl)
{
	cout << "URL: " << cHttpUrl.GetURL() << "\n";
	cout << "Domain: " << cHttpUrl.GetDomain() << "\n";
	cout << "Port: " << cHttpUrl.GetPort() << "\n";
	cout << "Protocol: " << cHttpUrl.GetProtocol() << "\n";
	cout << "Document: " << cHttpUrl.GetDocument() << "\n";
}

int main()
{
	cout << "Write URL or press q for exit" << endl;
	string str;
	for (; ;)
	{
		cin >> str;
		if (str == "q")
		{
			break;
		}
		else
		{
			CHttpUrl cHttpUrl(str);
			PrintUrlInformation(cHttpUrl);
		}
	}
	return 0;
}
