#ifndef DSMP_H
#define DSMP_H

#include <vector>

enum E_ACTION_TYPE
{
	AT_E = 0,
	AT_S = 1,
	AT_R = 2,
	AT_A = 3
};

class CAction
{
private:
	E_ACTION_TYPE _actionType;
	int _index;
	static std::vector<int> _error, _shift, _reduce, _accept;
public:
	CAction();
	CAction(E_ACTION_TYPE type, int i);
	~CAction();

	E_ACTION_TYPE GetType();
	void SetType(E_ACTION_TYPE type);

	int GetElem();
	void SetElem (int v);

	int Get();
} typedef act;

class CDSMP
{
private:
	CAction _actionTable[52][20];
	int _gotoTable[52][23];
public:
	CDSMP();
	~CDSMP();

	CAction GetActionElem(int i, int j);
	int GetGotoElem(int i, int j);
};

#endif // DSMP_H