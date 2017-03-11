#include "stdafx.h"

#include <cctype>
#include "HTTPURL.h"
#include "URLErrors.h"
#include <algorithm>

using namespace std;

namespace
{
	const string HTTP_DDMAIN = "http://";
	const string https = "https://";
	
}

CHttpUrl::CHttpUrl(string const &domain, string const &document, Protocol protocol,
	unsigned short port)
{
	InitializePartsOfUrl(domain, document, protocol, port);
}

bool CHttpUrl::IsDomainCorrect(const string &domain) const
{
	return (domain.find_first_of(" \t") == string::npos);
}

void CHttpUrl::InitializePartsOfUrl(string const &domain, string const &document, Protocol protocol,
	unsigned short port)
{
	m_domain = domain;
	if (document != "")
	{
		if (document[0] != '/')
		{
			m_document = "/" + document;
		}
		else
		{
			m_document = document;
		}
	}
	else
	{
		m_document = "/";
	}

	m_port = port;


	if (protocol == HTTP)
		m_protocol = "http";
	else
		m_protocol = "https";
	if (port == 80 || port == 443)
	{
		m_url = m_protocol + "://" + m_domain + m_document;
	}
	else
	{
		m_url = m_protocol + "://" + m_domain + ":" + to_string(m_port) + m_document;
	}
}

bool CHttpUrl::IsProtocolInUrl(const string &protocol, const string &url) const
{
	return url.find(protocol) != string::npos;
}

bool CHttpUrl::IsNumber(const string &s)
{
	return !s.empty() && find_if(s.begin(),
		s.end(), [](char c)
	{ return !isdigit(c); }) == s.end();
}

bool CHttpUrl::IsPortCorrect(const long &port) const
{
	return (port >= 0 && port < 65535);
}

CHttpUrl::CHttpUrl(string const &url)
{
	const string http("http://");
	const string https("https://");
	size_t protocolPosition;

	string domain;
	string document;
	Protocol protocol;
	unsigned short port;

	if (IsProtocolInUrl(http, url))
	{
		protocolPosition = url.substr(0, http.size()).find_last_of(http);
		protocol = HTTP;
	}
	else if (IsProtocolInUrl(https, url))
	{
		protocolPosition = url.substr(0, https.size()).find_last_of(https);
		protocol = HTTPS;
	}
	else
	{
		throw CUrlParsingError(
			"You should pass a url with protocol at the beginning. For example: <https://www.google.com>");
	}

	string str = url.substr(protocolPosition);
	auto portPosition = str.find_first_of(":");

	if (portPosition == string::npos)
	{
		auto positionOfDocument = str.substr(1).find_first_of("/");
		if (positionOfDocument != string::npos)
		{
			document = str.substr(positionOfDocument + 1);
		}
		if (IsDomainCorrect(str.substr(1, positionOfDocument)))
		{
			domain = str.substr(1, positionOfDocument);
		}
		else
		{
			throw CUrlParsingError("Domain can't contain a whitespaces");
		}
		if (protocol == HTTPS)
		{
			port = 443;
			InitializePartsOfUrl(domain, document, protocol, port);
		}
		else if (protocol == HTTP)
		{
			port = 80;
			InitializePartsOfUrl(domain, document, protocol, port);
		}
	}
	else
	{
		auto positionOfDocument = str.substr(1).find_first_of("/");
		string expectedPort = str.substr(portPosition + 1, positionOfDocument - portPosition);

		if (!IsNumber(expectedPort) || !IsPortCorrect(stol(expectedPort)))
		{
			throw CUrlParsingError("Unknown port");
		}
		port = static_cast<unsigned short>(atoi(expectedPort.c_str()));
		if (positionOfDocument != string::npos)
		{
			document = str.substr(positionOfDocument + 1);
		}

		if (IsDomainCorrect(str.substr(1, portPosition - 1)))
		{
			domain = str.substr(1, portPosition - 1);
		}
		else
		{
			throw CUrlParsingError("Domain can't contain a whitespaces");
		}

		InitializePartsOfUrl(domain, document, protocol, port);
	}
}

string CHttpUrl::GetDocument() const
{
	return m_document;
}

string CHttpUrl::GetURL() const
{
	return m_url;
}

string CHttpUrl::GetDomain() const
{
	return m_domain;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

Protocol CHttpUrl::GetProtocol() const
{
	if (m_protocol == "http")
	{
		return HTTP;
	}
	else
	{
		return HTTPS;
	}
}