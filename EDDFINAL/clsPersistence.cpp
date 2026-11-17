
#include "clsPersistence.h"
#include "clsCarta.h"

#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Convierte un texto en entero y comprueba que sea valido.
static bool opParseInt(string prmText, int &prmValue)
{
	stringstream stream(prmText);
	
	if (!(stream >> prmValue))
		return false;
	
	stream >> ws;
	
	return stream.eof();
}

// Guarda las cartas de una lista en un archivo.
bool clsPersistence::opSaveCards(clsSimpleList &prmList,
								 const string &prmFileName)
{
	ofstream file(prmFileName.c_str());
	
	if (!file.is_open())
		return false;
	
	int length = 0;
	clsCarta *array = prmList.opToArray(length);
	
	for (int i = 0; i < length; i++)
	{
		file << array[i].opGetId() << ";"
			<< array[i].opGetName() << ";"
			<< array[i].opGetType() << ";"
			<< array[i].opGetAttack() << ";"
			<< array[i].opGetDefense() << ";"
			<< array[i].opGetCost() << endl;
	}
	
	delete[] array;
	
	file.close();
	
	return !file.fail();
}

// Carga las cartas de un archivo en una lista.

bool clsPersistence::opLoadCards(clsSimpleList &prmList,
								 const string &prmFileName)
{
	ifstream file(prmFileName.c_str());
	
	if (!file.is_open())
		return false;
	
	clsSimpleList tempList;
	string line;
	int count = 0;
	
	while (getline(file, line))
	{
		if (line.empty())
			continue;
		
		stringstream stream(line);
		
		string idText;
		string name;
		string type;
		string attackText;
		string defenseText;
		string costText;
		string extra;
		
		if (!getline(stream, idText, ';') ||
			!getline(stream, name, ';') ||
			!getline(stream, type, ';') ||
			!getline(stream, attackText, ';') ||
			!getline(stream, defenseText, ';') ||
			!getline(stream, costText, ';'))
		{
			return false;
		}
			
			if (getline(stream, extra, ';'))
				return false;
			
			int id;
			int attack;
			int defense;
			int cost;
			
			if (!opParseInt(idText, id) ||
				!opParseInt(attackText, attack) ||
				!opParseInt(defenseText, defense) ||
				!opParseInt(costText, cost))
			{
				return false;
			}
				
				clsCarta card(id, name, type, attack, defense, cost);
				
				tempList.opInsertLast(card);
				count++;
	}
	
	if (file.bad() || count == 0)
		return false;
	
	file.close();
	
	int length = 0;
	clsCarta *array = tempList.opToArray(length);
	
	prmList.opClear();
	
	for (int i = 0; i < length; i++)
	{
		prmList.opInsertLast(array[i]);
	}
	
	delete[] array;
	
	return true;
}

