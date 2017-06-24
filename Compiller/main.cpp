#include <iostream>

#include "src/Lexer.h"
#include "src/Parser.h"

int main()
{
	CLexer lexer("dfa.txt");
	std::vector<CToken> tokens;

	tokens = lexer.FindTokens();

	std::cout << "--------Tokens---------" << std::endl;

	for (unsigned int i = 0; i < tokens.size() - 1; i++)
		std::cout << tokens[i] << std::endl;

	std::cout << "--------Postfix--------" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	CParser parser(tokens);

	CTree tree = parser.Parsing();

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << std::endl << "----------End----------" << std::endl;
		
	return 0;
}