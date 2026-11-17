#ifndef CLSNODESIMPLE_H
#define CLSNODESIMPLE_H

#include "clscarta.h"

class clsNodeSimple
{
private:
	clsCarta attCarta;
	clsNodeSimple *attNext;
	
public:
	
	clsNodeSimple();
	clsNodeSimple(clsCarta prmCarta);
	
	clsCarta opGetCarta();
	void opSetCarta(clsCarta prmCarta);
	
	clsNodeSimple *opGetNext();
	void opSetNext(clsNodeSimple *prmNext);
	
};

#endif
