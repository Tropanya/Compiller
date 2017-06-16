#include "Lexer.h"

CLexer::CLexer(const char* filePath)
{
	_fileBuff = CFileUtils::read_file(filePath);
	_found = false;
}

CLexer::~CLexer()
{ }

int CLexer::move(int state, char current)
{
	int col = _DSM.GetDSMCol(current - '(');
	return _DSM.GetDSMElem(state, col);
}

std::vector<CToken> CLexer::FindTokens()
{
	std::string buffProp = "";
	int i = 0, state = 0, state2 = 0, lineCount = 1;
	char current, next;

	int sizeBuff = _fileBuff.size();

	current = _fileBuff[i];
	next = current;
	if (!((i + 1) > sizeBuff))
		next = _fileBuff[i + 1];

	while (current == '\n' || current == ' ' || current == '\t')
	{
		if (current == '\n')
			lineCount++;
		i++;

		current = _fileBuff[i];
		if (!((i + 1) > sizeBuff))
			next = _fileBuff[i + 1];
	}

	while (current != '\0')
	{
		state = move(state, current);
		if (next == '\0' || next == '\n' || next == ' ' || next == '\t')
			state2 = 0;
		else
			state2 = move(state, next);

		switch (state)
		{
		case 1:
			buffProp = current;
			_tokens.push_back(CToken(TT_L_FB, buffProp, lineCount));
			_found = true;
			state = 0;
			break;
		case 2:
			buffProp = current;
			_tokens.push_back(CToken(TT_R_FB, buffProp, lineCount));
			_found = true;
			state = 0;
			break;
		case 3:
			buffProp = current;
			_tokens.push_back(CToken(TT_OP_MULT, buffProp, lineCount));
			_found = true;
			state = 0;
			break;
		case 4:
			buffProp = current;
			_tokens.push_back(CToken(TT_OP_PLUS, buffProp, lineCount));
			_found = true;
			state = 0;
			break;
		case 6:
			buffProp = current;
			_tokens.push_back(CToken(TT_OP_MINUS, buffProp, lineCount));
			_found = true;
			state = 0;
			break;
		case 8:
			buffProp = current;
			_tokens.push_back(CToken(TT_OP_DIV, buffProp, lineCount));
			_found = true;
			state = 0;
			break;
		case 9:
			buffProp = current;
			_tokens.push_back(CToken(TT_NUMBER, buffProp, lineCount));
			_found = true;
			state = 0;
			break;
		case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17:
		case 18:
			if (state2 == 0)
			{
				buffProp += current;
				_tokens.push_back(CToken(TT_NUMBER, buffProp, lineCount));
				_found = true;
				state = 0;
				break;
			}
			else
			{
				buffProp += current;
				break;
			}
		case 20:
			buffProp = current;
			_tokens.push_back(CToken(TT_SEMICOLON, buffProp, lineCount));
			_found = true;
			state = 0;
			break;
		case 21:
			buffProp = current;
			_tokens.push_back(CToken(TT_LE, buffProp, lineCount));
			_found = true;
			state = 0;
			break;
		case 22:
			buffProp = current;
			_tokens.push_back(CToken(TT_EQ, buffProp, lineCount));
			_found = true;
			state = 0;
			break;
		case 23:
			buffProp = current;
			_tokens.push_back(CToken(TT_ME, buffProp, lineCount));
			_found = true;
			state = 0;
			break;
		case 26: case 27: case 28: case 29: case 30: case 31: case 32: case 33:
		case 34: case 35: case 36: case 37: case 38: case 39: case 40: case 41:
		case 42: case 43: case 44: case 45: case 46: case 47: case 48: case 49:
		case 50: case 51: case 56: case 58: case 59: case 60: case 61: case 62:
		case 63: case 64: case 65: case 66: case 67: case 68: case 69: case 70:
		case 71: case 72: case 73: case 74: case 75: case 76: case 77: case 78:
		case 79: case 80: case 81: case 82: case 83:
			if (state2 == 0)
			{
				buffProp += current;
				_tokens.push_back(CToken(TT_IDENTIF, buffProp, lineCount));
				_found = true;
				state = 0;
				break;
			}
			else
			{
				buffProp += current;
				break;
			}
		case 84:
			buffProp = current;
			_tokens.push_back(CToken(TT_LB, buffProp, lineCount));
			_found = true;
			state = 0;
			break;
		case 86:
			buffProp = current;
			_tokens.push_back(CToken(TT_RB, buffProp, lineCount));
			_found = true;
			state = 0;
			break;
		case 87: case 88: case 89: case 90: case 91: case 92: case 93: case 94:
		case 95: case 96:
			if (state2 == 0)
			{
				buffProp += current;
				_tokens.push_back(CToken(TT_NUMBER, buffProp, lineCount));
				_found = true;
				state = 0;
				break;
			}
			else
			{
				buffProp += current;
				break;
			}
		case  97: case  98: case  99: case 100: case 101: case 102: case 103: case 104:
		case 105: case 106: case 107: case 108: case 109: case 110: case 111: case 112:
		case 113: case 114: case 115: case 116: case 117: case 118: case 119: case 120:
		case 121: case 122: case 123: case 124: case 125: case 126: case 127: case 128:
		case 129: case 130: case 131: case 132: case 133: case 134: case 135: case 136:
		case 137: case 138: case 139: case 140: case 141: case 142: case 143: case 144:
		case 145: case 146: case 147: case 148: case 149: case 150: case 151: case 152:
		case 153: case 154: case 155: case 156: case 157: case 158: case 159: case 160:
		case 162: case 163: case 164: case 166: case 168:
			if (state2 == 0)
			{
				buffProp += current;
				_tokens.push_back(CToken(TT_IDENTIF, buffProp, lineCount));
				_found = true;
				state = 0;
				break;
			}
			else
			{
				buffProp += current;
				break;
			}
		case  5: case  7: case 19: case 24: case 25: case 52: case 53: case 54:
		case 55: case 57: case 85:
			buffProp = current;
			_tokens.push_back(CToken(TT_UNKNOWN, buffProp, lineCount));
			_found = true;
			state = 0;
			break;
		case 161:
			if (state2 == 0)
			{
				buffProp += current;
				_found = true;
				_tokens.push_back(CToken(TT_KW_IF, buffProp, lineCount));
				state = 0;
				break;
			}
			else
			{
				buffProp += current;
				break;
			}
		case 165:
			if (state2 == 0)
			{
				buffProp += current;
				_tokens.push_back(CToken(TT_VAR_TYPE_INT, buffProp, lineCount));
				_found = true;
				state = 0;
				break;
			}
			else
			{
				buffProp += current;
				break;
			}
		case 167:
			if (state2 == 0)
			{
				buffProp += current;
				_tokens.push_back(CToken(TT_KW_ELSE, buffProp, lineCount));
				_found = true;
				state = 0;
				break;
			}
			else
			{
				buffProp += current;
				break;
			}
		case 169:
			if (state2 == 0)
			{
				buffProp += current;
				_tokens.push_back(CToken(TT_KW_WHILE, buffProp, lineCount));
				_found = true;
				state = 0;
				break;
			}
			else
			{
				buffProp += current;
				break;
			}
		}

		i++;

		current = _fileBuff[i];
		if (!((i + 1) > sizeBuff))
			next = _fileBuff[i + 1];

		while (current == '\n' || current == ' ' || current == '\t')
		{
			if (current == '\n')
				lineCount++;
			i++;

			current = _fileBuff[i];
			if (!((i + 1) > sizeBuff))
				next = _fileBuff[i + 1];
		}

		if (_found)
		{
			buffProp = "";
			_found = false;
		}
	}
	return _tokens;
}