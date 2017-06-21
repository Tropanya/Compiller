#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum E_TOKEN_TYPE
{
	TT_UNKNOWN		= 0,
	TT_KW_WHILE		= 1,
	TT_KW_IF		= 2,
	TT_KW_ELSE		= 3,
	TT_VAR_TYPE_INT	= 4,
	TT_OP_PLUS		= 5,
	TT_OP_MINUS		= 6,
	TT_OP_MULT		= 7,
	TT_OP_DIV		= 8,
	TT_EQ			= 9,
	TT_LE			= 10,
	TT_ME			= 11,
	TT_LB			= 12,
	TT_RB			= 13,
	TT_L_FB			= 14,
	TT_R_FB			= 15,
	TT_SEMICOLON	= 16,
	TT_NUMBER		= 17,
	TT_IDENTIF		= 18,
	TT_END			= 19
};

class CToken
{
private:
	E_TOKEN_TYPE _tokenType;
	std::string _tokenProp;
	int _line;
public:
	CToken();
	CToken(E_TOKEN_TYPE type, std::string prop, int line);
	~CToken();

	E_TOKEN_TYPE GetType();
	void SetType(E_TOKEN_TYPE type);

	std::string GetProp();
	void SetProp(std::string prop);

	int GetLine();

	CToken GetToken(E_TOKEN_TYPE type, std::string prop, int line);
	void SetToken(E_TOKEN_TYPE type, std::string prop, int line);

	friend std::ostream& operator<<(std::ostream& stream, const CToken& token);
};

#endif // TOKEN_H