#include <iostream>

#include "src/Lexer.h"
#include "src/Parser.h"

#include "src/DSMP.h"

int main()
{
	CLexer lexer("dfa.txt");
	std::vector<CToken> tokens;

	tokens = lexer.FindTokens();

	std::cout << "--------Tokens---------" << std::endl;

	for (unsigned int i = 0; i < tokens.size() - 1; i++)
		std::cout << tokens[i] << std::endl;

	std::cout << "--------Postfix--------" << std::endl;

	CParser parser(tokens);

	parser.Parsing();

	std::cout << std::endl << "----------End----------" << std::endl;
		
	return 0;
}