#include "clsDoubleList.h"

clsDoubleList::clsDoubleList()
{
	attFirst = NULL;
	attLast = NULL;
	attCurrent = NULL;
}

clsDoubleList::~clsDoubleList()
{
	opClear();
}

bool clsDoubleList::opIsEmpty()
{
	return attFirst == NULL;
}

void clsDoubleList::opInsertFirst(clsCarta prmCarta)
{
	clsDoubleNode *newNode = new clsDoubleNode(prmCarta);
	
	if (opIsEmpty())
	{
		attFirst = newNode;
		attLast = newNode;
	}
	else
	{
		newNode->opSetNext(attFirst);
		attFirst->opSetPrevious(newNode);
		attFirst = newNode;
	}
}

void clsDoubleList::opInsertLast(clsCarta prmCarta)
{
	clsDoubleNode *newNode = new clsDoubleNode(prmCarta);
	
	if (opIsEmpty())
	{
		attFirst = newNode;
		attLast = newNode;
	}
	else
	{
		newNode->opSetPrevious(attLast);
		attLast->opSetNext(newNode);
		attLast = newNode;
	}
}

void clsDoubleList::opClear()
{
	clsDoubleNode *current = attFirst;
	
	while (current != NULL)
	{
		clsDoubleNode *next = current->opGetNext();
		
		delete current;
		
		current = next;
	}
	
	attFirst = NULL;
	attLast = NULL;
	attCurrent = NULL;
}

bool clsDoubleList::opSearch(int prmID)
{
	clsDoubleNode *current = attFirst;
	
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


bool clsDoubleList::opRemove(int prmID)
{
	clsDoubleNode *current = attFirst;
	
	// Buscar el nodo que contiene el ID
	while (current != NULL &&
		   current->opGetCarta().opGetId() != prmID)
	{
		current = current->opGetNext();
	}
	
	// No se encontro la carta
	if (current == NULL)
		return false;
	
	// Actualizar el enlace del nodo anterior
	if (current->opGetPrevious() != NULL)
	{
		current->opGetPrevious()->opSetNext(
											current->opGetNext());
	}
	else
	{
		attFirst = current->opGetNext();
	}
	
	// Actualizar el enlace del nodo siguiente
	if (current->opGetNext() != NULL)
	{
		current->opGetNext()->opSetPrevious(
											current->opGetPrevious());
	}
	else
	{
		attLast = current->opGetPrevious();
	}
	
	// Si eliminamos el nodo actual, reiniciar el recorrido
	if (attCurrent == current)
		attCurrent = attFirst;
	
	delete current;
	
	return true;
}


clsCarta* clsDoubleList::opToArray(int &prmLength)
{
	prmLength = 0;
	
	clsDoubleNode *current = attFirst;
	
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
clsCarta* clsDoubleList::opToArrayReverse(int &prmLength)
{
	prmLength = 0;
	
	clsDoubleNode *current = attLast;
	
	while (current != NULL)
	{
		prmLength++;
		current = current->opGetPrevious();
	}
	
	if (prmLength == 0)
	{
		return NULL;
	}
	
	clsCarta *array = new clsCarta[prmLength];
	
	current = attLast;
	int index = 0;
	
	while (current != NULL)
	{
		array[index] = current->opGetCarta();
		
		index++;
		current = current->opGetPrevious();
	}
	
	return array;
}
bool clsDoubleList::opStart()
{
	if (opIsEmpty())
		return false;
	
	attCurrent = attFirst;
	return true;
}
bool clsDoubleList::opNext()
{
	if (attCurrent == NULL)
		return false;
	
	if (attCurrent->opGetNext() == NULL)
		return false;
	
	attCurrent = attCurrent->opGetNext();
	
	return true;
}
bool clsDoubleList::opPrevious()
{
	if (attCurrent == NULL)
		return false;
	
	if (attCurrent->opGetPrevious() == NULL)
		return false;
	
	attCurrent = attCurrent->opGetPrevious();
	
	return true;
}
bool clsDoubleList::opGetCurrent(clsCarta &prmCarta)
{
	if (attCurrent == NULL)
		return false;
	
	prmCarta = attCurrent->opGetCarta();
	
	return true;
}
