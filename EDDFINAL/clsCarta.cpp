#include "clsCarta.h"
#include <string>
using namespace std;
clsCarta::clsCarta(){
	attId = 0;
	attName = "";
	attType = "";
	attAttack = 0;
	attDefense = 0;
	attCost = 0;
}
clsCarta::clsCarta(int prmId, string prmName, string prmType,int prmAttack, int prmDefense, int prmCost) {
	attId = prmId;
	attName = prmName;
	attType = prmType;
	attAttack = prmAttack;
	attDefense = prmDefense;
	attCost = prmCost;
}

int clsCarta::opGetId() {
	return attId;
}

string clsCarta::opGetName() {
	return attName;
}

string clsCarta::opGetType() {
	return attType;
}

int clsCarta::opGetAttack() {
	return attAttack;
}

int clsCarta::opGetDefense() {
	return attDefense;
}

int clsCarta::opGetCost() {
	return attCost;
}
