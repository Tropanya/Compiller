#include "Parser.h"

CParser::CParser(std::vector<CToken> tokens)
{
	i = 0;
	_tokens = tokens;
}

CParser::~CParser()
{
}

void CParser::Expr()
{
	_current = _tokens[i];

	Term();

	while (true)
	{
		if (_current.GetType() == TT_OP_PLUS)
		{
			Match(TT_OP_PLUS);
			Term();
			std::cout << "+";
		}
		else if (_current.GetType() == TT_OP_MINUS)
		{
			Match(TT_OP_MINUS);
			Term();
			std::cout << "-";
		}
		else
			return;
	}
}

void CParser::Term()
{
	if (_current.GetType() == TT_NUMBER)
	{
		std::cout << _current.GetProp();
		Match(TT_NUMBER);
	}
}

void CParser::Match(E_TOKEN_TYPE type)
{
	if (_current.GetType() == type)
	{
		i++;
		if(!(i >= _tokens.size()))
			_current = _tokens[i];
	}
}