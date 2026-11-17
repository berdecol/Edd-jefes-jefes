#include "clsCircularList.h"

clsCircularList::clsCircularList() {
	attFirst = NULL;
	attLast = NULL;
	attCurrent = NULL;
}

clsCircularList::~clsCircularList() {
	opClear();
}

bool clsCircularList::opIsEmpty() {
	return attFirst == NULL;
}
void clsCircularList::opInsertFirst(clsJugador prmJugador) {
	clsCircularNode *newNode = new clsCircularNode(prmJugador);
	
	if (opIsEmpty()) {
		attFirst = newNode;
		attLast = newNode;
		attCurrent = newNode;
		newNode->opSetNext(newNode);
	} else {
		newNode->opSetNext(attFirst);
		attFirst = newNode;
		attLast->opSetNext(attFirst);
	}
}

void clsCircularList::opInsertLast(clsJugador prmJugador) {
	clsCircularNode *newNode = new clsCircularNode(prmJugador);
	
	if (opIsEmpty()) {
		attFirst = newNode;
		attLast = newNode;
		attCurrent = newNode;
		newNode->opSetNext(newNode);
	} else {
		newNode->opSetNext(attFirst);
		attLast->opSetNext(newNode);
		attLast = newNode;
	}
}

bool clsCircularList::opSearch(int prmID) {
	if (opIsEmpty()) {
		return false;
	}
	
	clsCircularNode *current = attFirst;
	
	do {
		if (current->opGetJugador().opGetId() == prmID) {
			return true;
		}
		
		current = current->opGetNext();
		
	} while (current != attFirst);
	
	return false;
}

bool clsCircularList::opRemove(int prmID) {
	if (opIsEmpty()) {
		return false;
	}
	
	clsCircularNode *previous = attLast;
	clsCircularNode *current = attFirst;
	
	do {
		if (current->opGetJugador().opGetId() == prmID) {
			
			if (attFirst == attLast) {
				delete current;
				
				attFirst = NULL;
				attLast = NULL;
				attCurrent = NULL;
				
				return true;
			}
			
			clsCircularNode *next = current->opGetNext();
			
			if (attCurrent == current) {
				attCurrent = next;
			}
			
			if (current == attFirst) {
				attFirst = next;
				attLast->opSetNext(attFirst);
			}
			
			else if (current == attLast) {
				attLast = previous;
				attLast->opSetNext(attFirst);
			}
			
			else {
				previous->opSetNext(next);
			}
			
			delete current;
			
			return true;
		}
		
		previous = current;
		current = current->opGetNext();
		
	} while (current != attFirst);
	
	return false;
}

clsJugador* clsCircularList::opGetCurrent()
{
	if (attCurrent == NULL)
	{
		return NULL;
	}
	
	return &(attCurrent->opGetJugador());
}

clsJugador* clsCircularList::opToArray(int &prmLength) {
	prmLength = 0;
	
	if (opIsEmpty()) {
		return NULL;
	}
	
	clsCircularNode *current = attFirst;
	
	do {
		prmLength++;
		current = current->opGetNext();
		
	} while (current != attFirst);
	
	clsJugador *array = new clsJugador[prmLength];
	
	current = attFirst;
	int index = 0;
	
	do {
		array[index] = current->opGetJugador();
		
		index++;
		current = current->opGetNext();
		
	} while (current != attFirst);
	
	return array;
}

void clsCircularList::opClear() {
	if (opIsEmpty()) {
		return;
	}
	
	clsCircularNode *current = attFirst->opGetNext();
	
	while (current != attFirst) {
		clsCircularNode *next = current->opGetNext();
		
		delete current;
		
		current = next;
	}
	
	delete attFirst;
	
	attFirst = NULL;
	attLast = NULL;
	attCurrent = NULL;
}
bool clsCircularList::opAdvance()
{
	if (attCurrent == NULL)
		return false;
	
	attCurrent = attCurrent->opGetNext();
	
	return true;
}
