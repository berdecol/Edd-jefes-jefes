#include "clsJugador.h"

clsJugador::clsJugador()
{
	attId = 0;
	attName = "";
	attLifePoints = 0;
}

clsJugador::clsJugador(int prmId, string prmName, int prmLifePoints)
{
	attId = prmId;
	attName = prmName;
	attLifePoints = prmLifePoints;
}

int clsJugador::opGetId()
{
	return attId;
}

string clsJugador::opGetName()
{
	return attName;
}

int clsJugador::opGetLifePoints()
{
	return attLifePoints;
}

void clsJugador::opSetId(int prmId)
{
	attId = prmId;
}

void clsJugador::opSetName(string prmName)
{
	attName = prmName;
}

void clsJugador::opSetLifePoints(int prmLifePoints)
{
	attLifePoints = prmLifePoints;
}

clsSimpleList& clsJugador::opGetCollection()
{
	return attCollection;
}

