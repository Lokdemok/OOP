#pragma once
#include "stdafx.h"

using namespace std;

enum Protocol
{
	HTTP,
	HTTPS
};

class CHttpUrl
{
public:
	// ��������� ������� ���������� ������������� URL-�, � ������ ������ ��������
	// ���������� ���������� CUrlParsingError, ���������� ��������� �������� ������
	CHttpUrl(string const &url);

	/* �������������� URL �� ������ ���������� ����������.
	��� �������������� ������� ���������� ����������� ����������
	std::invalid_argument
	���� ��� ��������� �� ���������� � ������� /, �� ��������� / � ����� ���������
	*/
	CHttpUrl(
		string const &domain,
		string const &document,
		Protocol protocol = HTTP,
		unsigned short port = 80);

	// ���������� ��������� ������������� URL-�. ����, ���������� ����������� ���
	// ���������� ��������� (80 ��� http � 443 ��� https) � URL �� ������ ����������
	string GetURL()const;

	// ���������������������
	string GetDomain()const;

	/*
	���������� ��� ���������. �������:
	/
	/index.html
	/images/photo.jpg
	*/
	string GetDocument()const;

	// ����������������������
	Protocol GetProtocol()const;

	// ��������������������
	unsigned short GetPort()const;

private:
	void InitializePartsOfUrl(
		string const &domain,
		string const &document,
		Protocol protocol = HTTP,
		unsigned short port = 80);
	bool IsNumber(const string &s);
	bool IsProtocolInUrl(const string &protocol, const string &url) const;
	bool IsDomainCorrect(const string & domain) const;
	bool IsPortCorrect(const long & port) const;
	string m_url;
	string m_domain;
	string m_document;
	string m_protocol;
	unsigned short m_port;
};
