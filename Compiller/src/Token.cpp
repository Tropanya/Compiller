#include "Token.h"

CToken::CToken()
{
	this->_tokenType = TT_UNKNOWN;
	this->_tokenProp = "";
	this->_line = 0;
}

CToken::CToken(E_TOKEN_TYPE type, std::string prop, int line)
{
	this->_tokenType = type;
	this->_tokenProp = prop;
	this->_line = line;
}

CToken::~CToken()
{ }

E_TOKEN_TYPE CToken::GetType()
{
	return this->_tokenType;
}

void CToken::SetType(E_TOKEN_TYPE type)
{
	this->_tokenType = type;
}

std::string CToken::GetProp()
{
	return this->_tokenProp;
}

void CToken::SetProp(std::string prop)
{
	this->_tokenProp = prop;
}

int CToken::GetLine()
{
	return this->_line;
}

CToken CToken::GetToken(E_TOKEN_TYPE type, std::string prop, int line)
{
	return CToken(type, prop, line);
}

void CToken::SetToken(E_TOKEN_TYPE type, std::string prop, int line)
{
	this->_tokenType = type;
	this->_tokenProp = prop;
	this->_line = line;
}

std::ostream& operator<<(std::ostream& stream, const CToken& token)
{
	return stream << "Token: (" << token._tokenType << ", " << token._tokenProp << ", " << token._line << ")";
}