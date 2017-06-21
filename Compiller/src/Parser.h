#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <stack>

#include "Lexer.h"
#include "DSMP.h"

class CParser
{
private:
	std::vector<CToken> _tokens;
	CDSMP _DSMP;
	bool _accepted;
private:
	CAction moveAction(int state, E_TOKEN_TYPE type);
	int moveGoto(int state, int col);
public:
	CParser(std::vector<CToken> tokens);
	~CParser();

	void Parsing();
};

#endif // PARSER_H