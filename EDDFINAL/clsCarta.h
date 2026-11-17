#ifndef clsCARTA_H
#define clsCARTA_H

#include <string>
using namespace std;

class clsCarta {
private:
	int attId;
	string attName;
	string attType;
	int attAttack;
	int attDefense;
	int attCost;
	
public:
	clsCarta();
	clsCarta(int prmId, string prmName, string prmType,int prmAttack, int prmDefense, int prmCost);
	
	int opGetId();
	string opGetName();
	string opGetType();
	int opGetAttack();
	int opGetDefense();
	int opGetCost();
};

#endif
