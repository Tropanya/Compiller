#include "Parser.h"

CParser::CParser(std::vector<CToken> tokens):
	_tokens(tokens), _accepted(false)
{ }

CParser::~CParser()
{ }

CAction CParser::moveAction(int state, E_TOKEN_TYPE type)
{
	return _DSMP.GetActionElem(state, type);
}

int CParser::moveGoto(int state, int col)
{
	return _DSMP.GetGotoElem(state, col);
}

void CParser::Parsing()
{
	std::stack<int> states;
	CAction currentAction;
	int i = 0, size;

	size = _tokens.size();

	states.push(0);

	while (!_accepted)
	{
		currentAction = moveAction(states.top(), _tokens[i].GetType());

		switch (currentAction.GetType())
		{
		case AT_E:
			std::cout << "Syntax error in " << _tokens[i - 1].GetLine() << " line after the token: \"" << _tokens[i - 1].GetProp() <<"\"" << std::endl;
			return;
		case AT_S:
			states.push(currentAction.Get(currentAction));
			i++;
			break;
		case AT_R:
			for (size_t i = 0; i < currentAction.Get(currentAction); i++)
			{
				states.pop();
			}

			states.push(moveGoto(states.top(), currentAction.GetElem()));
			break;
		case AT_A:
			_accepted = true;
			std::cout << "Correct construction!" << std::endl;
			break;
		}
	}
}