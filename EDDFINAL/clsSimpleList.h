
#ifndef CLSSIMPLELIST_H
#define CLSSIMPLELIST_H

#include "clsNodeSimple.h"

class clsSimpleList
{
private:
	clsNodeSimple *attFirst;
	
public:
	clsSimpleList();
	clsSimpleList(const clsSimpleList &prmList);
	clsSimpleList& operator=(const clsSimpleList &prmList);
	~clsSimpleList();
	
	bool opIsEmpty();
	
	void opInsertFirst(clsCarta prmCarta);
	void opInsertLast(clsCarta prmCarta);
	
	void opClear();
	
	clsCarta* opToArray(int &prmLength);
	
	bool opSearch(int prmID);
	bool opRemove(int prmID);
};

#endif
