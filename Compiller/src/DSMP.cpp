#include "DSMP.h"

std::vector<int> CAction::_error =
{
	0
};
std::vector<int> CAction::_shift =
{	 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
	20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
	40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51
};
std::vector<int> CAction::_reduce =
{
	1, 1, 1, 7, 7, 11, 4, 3, 1, 1, 1, 1, 1, 1, 2, 3, 3, 1, 3, 3,
	1, 3, 1
};
std::vector<int> CAction::_accept =
{
	0
};

CAction::CAction():
	_actionType(AT_E), _index(0)
{ }

CAction::CAction(E_ACTION_TYPE type, int i):
	_actionType(type), _index(i)
{ }

CAction::~CAction()
{ }

E_ACTION_TYPE CAction::GetType()
{
	return this->_actionType;
}

void CAction::SetType(E_ACTION_TYPE type)
{
	this->_actionType = type;
}

int CAction::GetElem()
{
	return this->_index;
}

void CAction::SetElem(int v)
{
	this->_index = v;
}

int CAction::Get()
{
	switch (_actionType)
	{
	case AT_E:
		return _error[_index];
	case AT_S:
		return _shift[_index];
	case AT_R:
		return _reduce[_index];
	case AT_A:
		return _accept[_index];
	default:
		return _error[_index];
	}
}

CDSMP::CDSMP():
	_actionTable
{
	act(AT_E, 0), act(AT_S, 5), act(AT_S, 6), act(AT_E, 0),  act(AT_S, 10), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 9),  act(AT_E, 0),
	act(AT_E, 0), act(AT_S, 5), act(AT_S, 6), act(AT_E, 0),  act(AT_S, 10), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 9),  act(AT_A, 0),
	act(AT_E, 0), act(AT_R, 0), act(AT_R, 0), act(AT_E, 0),  act(AT_R, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 0),  act(AT_R, 0),
	act(AT_E, 0), act(AT_R, 1), act(AT_R, 1), act(AT_E, 0),  act(AT_R, 1),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 1),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 1),  act(AT_R, 1),
	act(AT_E, 0), act(AT_R, 2), act(AT_R, 2), act(AT_E, 0),  act(AT_R, 2),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 2),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 2),  act(AT_R, 2),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 12), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 13), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 33), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 12), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 13), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 11), act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 14), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 41), act(AT_S, 40), act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 41), act(AT_S, 40), act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 17), act(AT_S, 18), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 41), act(AT_S, 40), act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 7),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 10), act(AT_R, 10), act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 11), act(AT_R, 11), act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 21), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 22), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 23), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 24), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),
	act(AT_E, 0), act(AT_S, 5), act(AT_S, 6), act(AT_E, 0),  act(AT_S, 10), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 9),  act(AT_E, 0),
	act(AT_E, 0), act(AT_S, 5), act(AT_S, 6), act(AT_E, 0),  act(AT_S, 10), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 9),  act(AT_E, 0),
	act(AT_E, 0), act(AT_S, 5), act(AT_S, 6), act(AT_E, 0),  act(AT_S, 10), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 27), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 9),  act(AT_E, 0),
	act(AT_E, 0), act(AT_S, 5), act(AT_S, 6), act(AT_E, 0),  act(AT_S, 10), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 28), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 9),  act(AT_E, 0),
	act(AT_E, 0), act(AT_R, 3), act(AT_R, 3), act(AT_E, 0),  act(AT_R, 3),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 3),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 3),  act(AT_R, 3),
	act(AT_E, 0), act(AT_R, 4), act(AT_R, 4), act(AT_S, 29), act(AT_R, 4),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 4),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 4),  act(AT_R, 4),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 30), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),
	act(AT_E, 0), act(AT_S, 5), act(AT_S, 6), act(AT_E, 0),  act(AT_S, 10), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 9),  act(AT_E, 0),
	act(AT_E, 0), act(AT_S, 5), act(AT_S, 6), act(AT_E, 0),  act(AT_S, 10), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 32), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 9),  act(AT_E, 0),
	act(AT_E, 0), act(AT_R, 5), act(AT_R, 5), act(AT_E, 0),  act(AT_R, 5),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 5),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 5),  act(AT_R, 5),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 38), act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 41), act(AT_S, 40), act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 42), act(AT_S, 43), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 35), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),
	act(AT_E, 0), act(AT_R, 6), act(AT_R, 6), act(AT_E, 0),  act(AT_R, 6),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 6),  act(AT_R, 6),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 6),  act(AT_R, 6),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 17), act(AT_R, 17), act(AT_S, 44), act(AT_S, 45), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 17), act(AT_R, 17), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 20), act(AT_R, 20), act(AT_R, 20), act(AT_R, 20), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 20), act(AT_R, 20), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 38), act(AT_E, 0),  act(AT_S, 41), act(AT_S, 40), act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 22), act(AT_R, 22), act(AT_R, 22), act(AT_R, 22), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 22), act(AT_R, 22), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 8),  act(AT_R, 8),  act(AT_R, 8),  act(AT_R, 8),  act(AT_E, 0),  act(AT_R, 8),  act(AT_R, 8),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 8),  act(AT_R, 8),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 9),  act(AT_R, 9),  act(AT_R, 9),  act(AT_R, 9),  act(AT_E, 0),  act(AT_R, 9),  act(AT_R, 9),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 9),  act(AT_R, 9),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 38), act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 41), act(AT_S, 40), act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 38), act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 41), act(AT_S, 40), act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 38), act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 41), act(AT_S, 40), act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 38), act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 41), act(AT_S, 40), act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 15), act(AT_R, 15), act(AT_S, 44), act(AT_S, 45), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 15), act(AT_R, 15), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 16), act(AT_R, 16), act(AT_S, 44), act(AT_S, 45), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 16), act(AT_R, 16), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 18), act(AT_R, 18), act(AT_R, 18), act(AT_R, 18), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 18), act(AT_R, 18), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 19), act(AT_R, 19), act(AT_R, 19), act(AT_R, 19), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 19), act(AT_R, 19), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 42), act(AT_S, 43), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_S, 51), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),
	act(AT_E, 0), act(AT_E, 0), act(AT_E, 0), act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 21), act(AT_R, 21), act(AT_R, 21), act(AT_R, 21), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0),  act(AT_R, 21), act(AT_R, 21), act(AT_E, 0),  act(AT_E, 0),  act(AT_E, 0)
},
	_gotoTable
{
	 1,  1,  1,  2,  3,  3,  4,  0,  0,  0,  0,  0,  7,  7,  8,  0,  0,  0,  0,  0,  0,  0,  0,
	 1,  1,  1,  2,  3,  3,  4,  0,  0,  0,  0,  0,  7,  7,  8,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0, 19, 14, 14,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0, 20, 14, 14,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 15, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0, 16, 16,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	25, 25, 25,  2,  3,  3,  4,  0,  0,  0,  0,  0,  7,  7,  8,  0,  0,  0,  0,  0,  0,  0,  0,
	26, 26, 26,  2,  3,  3,  4,  0,  0,  0,  0,  0,  7,  7,  8,  0,  0,  0,  0,  0,  0,  0,  0,
	25, 25, 25,  2,  3,  3,  4,  0,  0,  0,  0,  0,  7,  7,  8,  0,  0,  0,  0,  0,  0,  0,  0,
	26, 26, 26,  2,  3,  3,  4,  0,  0,  0,  0,  0,  7,  7,  8,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	31, 31, 31,  2,  3,  3,  4,  0,  0,  0,  0,  0,  7,  7,  8,  0,  0,  0,  0,  0,  0,  0,  0,
	31, 31, 31,  2,  3,  3,  4,  0,  0,  0,  0,  0,  7,  7,  8,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0, 39, 39,  0,  0,  0,  0,  0, 34, 34, 34, 36, 36, 36, 37, 37,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0, 39, 39,  0,  0,  0,  0,  0, 50, 50, 50, 36, 36, 36, 37, 37,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0, 39, 39,  0,  0,  0,  0,  0,  0,  0,  0, 46, 46, 46, 37, 37,
	 0,  0,  0,  0,  0,  0,  0,  0, 39, 39,  0,  0,  0,  0,  0,  0,  0,  0, 47, 47, 47, 37, 37,
	 0,  0,  0,  0,  0,  0,  0,  0, 39, 39,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48,
	 0,  0,  0,  0,  0,  0,  0,  0, 39, 39,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 49, 49,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
}
{ }

CDSMP::~CDSMP()
{ }

CAction CDSMP::GetActionElem(int i, int j)
{
	return _actionTable[i][j];
}

int CDSMP::GetGotoElem(int i, int j)
{
	return _gotoTable[i][j];
}