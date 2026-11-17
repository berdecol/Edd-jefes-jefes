#ifndef CLSDOUBLENODE_H
#define CLSDOUBLENODE_H

#include "clscarta.h"

class clsDoubleNode
{
private:
	clsCarta attCarta;
	clsDoubleNode *attNext;
	clsDoubleNode *attPrevious;
	
public:
	clsDoubleNode();
	clsDoubleNode(clsCarta prmCarta);
	
	clsCarta opGetCarta();
	void opSetCarta(clsCarta prmCarta);
	
	clsDoubleNode *opGetNext();
	void opSetNext(clsDoubleNode *prmNext);
	
	clsDoubleNode *opGetPrevious();
	void opSetPrevious(clsDoubleNode *prmPrevious);
};

#endif
