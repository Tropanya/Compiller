#ifndef LEXER_H
#define LEXER_H

#include <vector>

#include "Token.h"
#include "DSML.h"
#include "utils/FileUtils.h"

class CLexer
{
private:
	std::vector<CToken> _tokens;
	std::string _fileBuff;
	CDSML _DSML;
	bool _found;
private:
	int move(int state, char current);
public:
	CLexer(const char* filePath);
	~CLexer();

	std::vector<CToken> FindTokens();
};

#endif // LEXER_H