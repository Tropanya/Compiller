#include "Parser.h"

CParser::CParser(std::vector<CToken> tokens):
	_tokens(tokens), _accepted(false),
	ruleNodes
{
	CNode("bodies"), CNode("bodies"), CNode("bodies"),
	CNode("while_expr"),
	CNode("if_expr"), CNode("if_expr"),
	CNode("stmt"),
	CNode("condition"),
	CNode("value"), CNode("value"),
	CNode("logic_op"), CNode("logic_op"),
	CNode("var_value"), CNode("var_value"),
	CNode("var_decl"),
	CNode("assign_expr"), CNode("assign_expr"), CNode("assign_expr"),
	CNode("term"), CNode("term"), CNode("term"),
	CNode("factor"), CNode("factor")
}
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

CTree CParser::Parsing()
{
	std::stack<int> states;
	std::stack<CNode> nodes, tmpNodes;
	CNode tmp, resultNode;
	CAction currentAction;
	int i = 0, bodyCount = 0;

	states.push(0);

	while (!_accepted)
	{
		currentAction = moveAction(states.top(), _tokens[i].GetType());
		int coutReduse = currentAction.Get();

		switch (currentAction.GetType())
		{
		case AT_E:
			std::cout << "Syntax error in " << _tokens[i - 1].GetLine() << " line after the token: \"" << _tokens[i - 1].GetProp() <<"\"" << std::endl;
			return CTree(new CNode("ERROR"));
		case AT_S:
			states.push(coutReduse);
			nodes.push(CNode(_tokens[i].GetProp()));
			i++;
			break;
		case AT_R:
			
			tmp = ruleNodes[currentAction.GetElem()];

			for (int i = 0; i < coutReduse; i++)
			{
				tmpNodes.push(nodes.top());
				nodes.pop();
			}

			for (int i = 0; i < coutReduse; i++)
			{
				tmp._son.push_back(tmpNodes.top());
				tmpNodes.pop();
			}

			for (int i = 0; i < coutReduse; i++)
			{
				states.pop();
			}

			if (!(states.top() == moveGoto(states.top(), currentAction.GetElem())))
				states.push(moveGoto(states.top(), currentAction.GetElem()));
			else bodyCount++;

			nodes.push(tmp);
			break;
		case AT_A:
			_accepted = true;
			std::cout << "Correct construction!" << std::endl;
			break;
		}
	}

	int nodeSize = nodes.size();

	for(int i = 0; i < nodeSize; i++)
	{
		resultNode._son.push_back(nodes.top());
		nodes.pop();
	}

	return CTree(&resultNode);
}