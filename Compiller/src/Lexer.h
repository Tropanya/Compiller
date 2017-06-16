#ifndef LEXER_H
#define LEXER_H

#include <vector>

#include "Token.h"
#include "DSM.h"
#include "utils/FileUtils.h"

class CLexer
{
private:
	std::vector<CToken> _tokens;
	std::string _fileBuff;
	CDSM _DSM;
	bool _found;
private:
	int move(int state, char current);
public:
	CLexer(const char* filePath);
	~CLexer();

	std::vector<CToken> FindTokens();
};

#endif // LEXER_H