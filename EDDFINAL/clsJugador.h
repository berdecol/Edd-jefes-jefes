#ifndef CLSJUGADOR_H
#define CLSJUGADOR_H

#include <string>
#include "clsSimpleList.h"

using namespace std;

class clsJugador
{
private:
	int attId;
	string attName;
	int attLifePoints;
	clsSimpleList attCollection;
	
public:
	clsJugador();
	clsJugador(int prmId, string prmName, int prmLifePoints);
	
	int opGetId();
	string opGetName();
	int opGetLifePoints();
	
	void opSetId(int prmId);
	void opSetName(string prmName);
	void opSetLifePoints(int prmLifePoints);
	
	clsSimpleList& opGetCollection();
};

#endif
