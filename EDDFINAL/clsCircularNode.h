#ifndef CLSCIRCULARNODE_H
#define CLSCIRCULARNODE_H

#include "clsJugador.h"

class clsCircularNode {
private:
	clsJugador attJugador;
	clsCircularNode *attNext;

	
public:
	clsCircularNode();
	clsCircularNode(clsJugador prmJugador);
	
	clsJugador& opGetJugador();
	void opSetJugador(clsJugador prmJugador);
	
	clsCircularNode *opGetNext();
	void opSetNext(clsCircularNode *prmNext);

};

#endif
