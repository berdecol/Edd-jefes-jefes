#include "clsSimpleList.h"

clsSimpleList::clsSimpleList()
{
	attFirst = NULL;
}
clsSimpleList::~clsSimpleList()
{
	opClear();
}
bool clsSimpleList::opIsEmpty()
{
	return attFirst == NULL;
}
void clsSimpleList::opInsertFirst(clsCarta prmCarta)
{
	clsNodeSimple *newNode = new clsNodeSimple(prmCarta);
	
	newNode->opSetNext(attFirst);
	
	attFirst = newNode;
}
void clsSimpleList::opInsertLast(clsCarta prmCarta)
{
	clsNodeSimple *newNode = new clsNodeSimple(prmCarta);
	
	if (opIsEmpty())
	{
		attFirst = newNode;
	}
	else
	{
		clsNodeSimple *current = attFirst;
		
		while (current->opGetNext() != NULL)
		{
			current = current->opGetNext();
		}
		
		current->opSetNext(newNode);
	}
}
void clsSimpleList::opClear()
{
	clsNodeSimple *current = attFirst;
	
	while (current != NULL)
	{
		clsNodeSimple *next = current->opGetNext();
		
		delete current;
		
		current = next;
	}
	
	attFirst = NULL;
}
clsCarta* clsSimpleList::opToArray(int &prmLength)
{
	prmLength = 0;
	
	clsNodeSimple *current = attFirst;
	
	while (current != NULL)
	{
		prmLength++;
		current = current->opGetNext();
	}
	
	if (prmLength == 0)
	{
		return NULL;
	}
	
	clsCarta *array = new clsCarta[prmLength];
	
	current = attFirst;
	int index = 0;
	
	while (current != NULL)
	{
		array[index] = current->opGetCarta();
		
		index++;
		current = current->opGetNext();
	}
	
	return array;
}
bool clsSimpleList::opSearch(int prmID)
{
	clsNodeSimple *current = attFirst;
	
	while (current != NULL)
	{
		if (current->opGetCarta().opGetId() == prmID)
		{
			return true;
		}
		
		current = current->opGetNext();
	}
	
	return false;
}
bool clsSimpleList::opRemove(int prmID)
{
	clsNodeSimple *previous = NULL;
	clsNodeSimple *current = attFirst;
	
	while (current != NULL)
	{
		if (current->opGetCarta().opGetId() == prmID)
		{
			if (previous == NULL)
			{
				attFirst = current->opGetNext();
			}
			else
			{
				previous->opSetNext(current->opGetNext());
			}
			
			delete current;
			
			return true;
		}
		
		previous = current;
		current = current->opGetNext();
	}
	
	return false;
}
clsSimpleList::clsSimpleList(const clsSimpleList &prmList)
{
	attFirst = NULL;
	
	clsNodeSimple *current = prmList.attFirst;
	
	while (current != NULL)
	{
		opInsertLast(current->opGetCarta());
		
		current = current->opGetNext();
	}
}
clsSimpleList& clsSimpleList::operator=(const clsSimpleList &prmList)
{
	if (this != &prmList)
	{
		opClear();
		
		clsNodeSimple *current = prmList.attFirst;
		
		while (current != NULL)
		{
			opInsertLast(current->opGetCarta());
			
			current = current->opGetNext();
		}
	}
	
	return *this;
}
