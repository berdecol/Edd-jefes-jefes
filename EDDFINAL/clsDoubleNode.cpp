#include "clsDoubleNode.h"

clsDoubleNode::clsDoubleNode()
{
	attCarta = clsCarta();
	attNext = NULL;
	attPrevious = NULL;
}

clsDoubleNode::clsDoubleNode(clsCarta prmCarta)
{
	attCarta = prmCarta;
	attNext = NULL;
	attPrevious = NULL;
}

clsCarta clsDoubleNode::opGetCarta()
{
	return attCarta;
}

void clsDoubleNode::opSetCarta(clsCarta prmCarta)
{
	attCarta = prmCarta;
}

clsDoubleNode* clsDoubleNode::opGetNext()
{
	return attNext;
}

void clsDoubleNode::opSetNext(clsDoubleNode *prmNext)
{
	attNext = prmNext;
}

clsDoubleNode* clsDoubleNode::opGetPrevious()
{
	return attPrevious;
}

void clsDoubleNode::opSetPrevious(clsDoubleNode *prmPrevious)
{
	attPrevious = prmPrevious;
}
