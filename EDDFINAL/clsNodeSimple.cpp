#include "clsNodeSimple.h"

clsNodeSimple::clsNodeSimple()
{
	attCarta = clsCarta();
	attNext = NULL;
}

clsNodeSimple::clsNodeSimple(clsCarta prmCarta)
{
	attCarta = prmCarta;
	attNext = NULL;
}

clsCarta clsNodeSimple::opGetCarta()
{
	return attCarta;
}

void clsNodeSimple::opSetCarta(clsCarta prmCarta)
{
	attCarta = prmCarta;
}

clsNodeSimple* clsNodeSimple::opGetNext()
{
	return attNext;
}

void clsNodeSimple::opSetNext(clsNodeSimple *prmNext)
{
	attNext = prmNext;
}
