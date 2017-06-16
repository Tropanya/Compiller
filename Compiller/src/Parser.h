#ifndef PARSER_H
#define PARSER_H

#include <iostream>

#include "Lexer.h"

class CParser
{
private:
	std::vector<CToken> _tokens;
	CToken _current;
	unsigned int i;
public:
	CParser(std::vector<CToken> tokens);
	~CParser();

	void Expr();
	void Term();
	void Match(E_TOKEN_TYPE type);
};

#endif // !PARSER_H