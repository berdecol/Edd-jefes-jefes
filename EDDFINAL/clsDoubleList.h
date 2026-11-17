#ifndef CLSDOUBLELIST_H
#define CLSDOUBLELIST_H

#include "clsDoubleNode.h"

class clsDoubleList
{
private:
	clsDoubleNode *attFirst;
	clsDoubleNode *attLast;
	clsDoubleNode *attCurrent;
public:
	clsDoubleList();
	~clsDoubleList();
	
	bool opIsEmpty();
	
	void opInsertFirst(clsCarta prmCarta);
	void opInsertLast(clsCarta prmCarta);
	
	bool opSearch(int prmID);
	bool opRemove(int prmID);
	
	clsCarta* opToArray(int &prmLength);
	
	void opClear();
	
	clsCarta* opToArrayReverse(int &prmLength);
	
	bool opStart();
	bool opNext();
	bool opPrevious();
	bool opGetCurrent(clsCarta &prmCarta);
};

#endif
