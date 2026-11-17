#include "clsCircularNode.h"

clsCircularNode::clsCircularNode() {
	attJugador = clsJugador();
	attNext = NULL;
}

clsCircularNode::clsCircularNode(clsJugador prmJugador) {
	attJugador = prmJugador;
	attNext = NULL;
}

clsJugador& clsCircularNode::opGetJugador()
{
	return attJugador;
}

void clsCircularNode::opSetJugador(clsJugador prmJugador) {
	attJugador = prmJugador;
}

clsCircularNode* clsCircularNode::opGetNext() {
	return attNext;
}

void clsCircularNode::opSetNext(clsCircularNode *prmNext) {
	attNext = prmNext;
}
