#ifndef DSML_H
#define DSML_H

class CDSML
{
private:
	int _DSML[170][86], _col[86];
public:
	CDSML();
	~CDSML();

	int GetDSMLElem(int i, int j);
	int GetDSMLCol(int i);
};

#endif // DSML_H