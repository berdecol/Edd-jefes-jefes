#ifndef CLSCIRCULARLIST_H
#define CLSCIRCULARLIST_H

#include "clsCircularNode.h"
#include "clsJugador.h"
class clsCircularList {
private:
	clsCircularNode *attFirst;
	clsCircularNode *attLast;
	clsCircularNode *attCurrent;
	
public:
	clsCircularList();
	~clsCircularList();
	
	bool opIsEmpty();
	
	void opInsertFirst(clsJugador prmJugador);
	void opInsertLast(clsJugador prmJugador);
	
	bool opSearch(int prmID);
	bool opRemove(int prmID);
	
	clsJugador* opGetCurrent();
	
	bool opAdvance();
	
	clsJugador* opToArray(int &prmLength);
	
	void opClear();

};

#endif
