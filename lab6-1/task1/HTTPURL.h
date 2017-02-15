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
	// выполняет парсинг строкового представления URL-а, в случае ошибки парсинга
	// выбрасыват исключение CUrlParsingError, содержащее текстовое описание ошибки
	CHttpUrl(string const &url);

	/* инициализирует URL на основе переданных параметров.
	При недопустимости входных параметров выбрасывает исключение
	std::invalid_argument
	Если имя документа не начинается с символа /, то добавляет / к имени документа
	*/
	CHttpUrl(
		string const &domain,
		string const &document,
		Protocol protocol = HTTP,
		unsigned short port = 80);

	// возвращает строковое представление URL-а. Порт, являющийся стандартным для
	// выбранного протокола (80 для http и 443 для https) в URL не должен включаться
	string GetURL()const;

	// возвращаетдоменноеимя
	string GetDomain()const;

	/*
	Возвращает имя документа. Примеры:
	/
	/index.html
	/images/photo.jpg
	*/
	string GetDocument()const;

	// возвращаеттиппротокола
	Protocol GetProtocol()const;

	// возвращаетномерпорта
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
