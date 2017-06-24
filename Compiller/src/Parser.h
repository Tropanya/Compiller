#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <stack>

#include "Lexer.h"
#include "DSMP.h"

#include "Tree.h"

class CParser
{
private:
	std::vector<CToken> _tokens;
	std::vector<CNode> ruleNodes;
	CDSMP _DSMP;
	bool _accepted;
private:
	CAction moveAction(int state, E_TOKEN_TYPE type);
	int moveGoto(int state, int col);
public:
	CParser(std::vector<CToken> tokens);
	~CParser();

	CTree Parsing();
};

#endif // PARSER_H