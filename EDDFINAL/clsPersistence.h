#ifndef CLSPERSISTENCE_H
#define CLSPERSISTENCE_H

#include "clsSimpleList.h"
#include <string>

class clsPersistence
{
public:
	static bool opSaveCards(clsSimpleList &prmList, const std::string &prmFileName);
	
	static bool opLoadCards(clsSimpleList &prmList, const std::string &prmFileName);
};

#endif
