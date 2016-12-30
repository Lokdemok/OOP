#include "stdafx.h"
#include "URLErrors.h"
#include <string>
#include <iostream>

CUrlParsingError::CUrlParsingError(const std::string & msg) : std::invalid_argument(msg)
{
	std::cout << msg << "\n";
}