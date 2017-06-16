#ifndef DSM_H
#define DSM_H

class CDSM
{
private:
	int _DSM[170][86], _col[86];
public:
	CDSM();
	~CDSM();

	int GetDSMElem(int i, int j);
	int GetDSMCol(int i);
};

#endif // DSM_H