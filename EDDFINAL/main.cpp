
#include <iostream>
#include <string>
#include <sstream>

#include "clsCarta.h"
#include "clsJugador.h"
#include "clsSimpleList.h"
#include "clsDoubleList.h"
#include "clsCircularList.h"
#include "clsPersistence.h"

using namespace std;

// ==========================================
// MOSTRAR CARTAS
// ==========================================

void opShowCards(clsSimpleList &prmList)
{
	int length = 0;
	clsCarta *array = prmList.opToArray(length);
	
	if (length == 0)
	{
		cout << "\nNo hay cartas para mostrar.\n";
		return;
	}
	
	for (int i = 0; i < length; i++)
	{
		cout << "\nID: " << array[i].opGetId();
		cout << "\nNombre: " << array[i].opGetName();
		cout << "\nTipo: " << array[i].opGetType();
		cout << "\nAtaque: " << array[i].opGetAttack();
		cout << "\nDefensa: " << array[i].opGetDefense();
		cout << "\nCoste: " << array[i].opGetCost();
		cout << "\n-----------------------------\n";
	}
	
	delete[] array;
}

// ==========================================
// AGREGAR CARTA A UNA COLECCION
// ==========================================

void opAddCollection(clsSimpleList &prmCatalog,
					 clsSimpleList &prmCollection)
{
	int id;
	int length = 0;
	
	cout << "\nIngrese el ID de la carta: ";
	cin >> id;
	
	clsCarta *array = prmCatalog.opToArray(length);
	
	for (int i = 0; i < length; i++)
	{
		if (array[i].opGetId() == id)
		{
			prmCollection.opInsertLast(array[i]);
			
			cout << "\nCarta agregada a la coleccion.\n";
			
			delete[] array;
			return;
		}
	}
	
	delete[] array;
	
	cout << "\nNo existe una carta con ese ID.\n";
}

// ==========================================
// BUSCAR CARTA EN UNA COLECCION
// ==========================================

void opSearchCollection(clsSimpleList &prmCollection)
{
	int id;
	
	cout << "\nIngrese el ID de la carta: ";
	cin >> id;
	
	if (prmCollection.opSearch(id))
		cout << "\nLa carta se encuentra en la coleccion.\n";
	else
		cout << "\nLa carta no se encuentra en la coleccion.\n";
}

// ==========================================
// ELIMINAR CARTA DE UNA COLECCION
// ==========================================

void opRemoveCollection(clsSimpleList &prmCollection)
{
	int id;
	
	cout << "\nIngrese el ID de la carta: ";
	cin >> id;
	
	if (prmCollection.opRemove(id))
		cout << "\nCarta eliminada correctamente.\n";
	else
		cout << "\nNo se encontro esa carta.\n";
}

// ==========================================
// NOMBRE DEL ARCHIVO DE CADA JUGADOR
// ==========================================

string opCollectionFileName(int prmID)
{
	stringstream fileName;
	
	fileName << "coleccion_" << prmID << ".txt";
	
	return fileName.str();
}

// ==========================================
// GUARDAR COLECCION
// ==========================================

void opSaveCollection(clsJugador &prmPlayer)
{
	string fileName = opCollectionFileName(prmPlayer.opGetId());
	
	if (clsPersistence::opSaveCards(
									prmPlayer.opGetCollection(), fileName))
	{
		cout << "\nColeccion guardada correctamente.\n";
	}
	else
									{
										cout << "\nError al guardar la coleccion.\n";
									}
}

// ==========================================
// CARGAR COLECCION
// ==========================================

void opLoadCollection(clsJugador &prmPlayer)
{
	string fileName = opCollectionFileName(prmPlayer.opGetId());
	
	if (clsPersistence::opLoadCards(
									prmPlayer.opGetCollection(), fileName))
	{
		cout << "\nColeccion cargada correctamente.\n";
	}
	else
									{
										cout << "\nError al cargar la coleccion.\n";
									}
}

// ==========================================
// MENU DE COLECCION
// ==========================================

void opMenuCollection(clsJugador &prmPlayer,
					  clsSimpleList &prmCatalog)
{
	int option;
	
	do
	{
		cout << "\n================================";
		cout << "\n       COLECCION PERSONAL";
		cout << "\n================================";
		cout << "\nJugador: " << prmPlayer.opGetName();
		cout << "\nID: " << prmPlayer.opGetId();
		
		cout << "\n\n1. Mostrar coleccion";
		cout << "\n2. Agregar carta";
		cout << "\n3. Buscar carta";
		cout << "\n4. Eliminar carta";
		cout << "\n5. Guardar coleccion";
		cout << "\n6. Cargar coleccion";
		cout << "\n0. Volver";
		
		cout << "\nSeleccione una opcion: ";
		cin >> option;
		
		switch (option)
		{
		case 1:
			opShowCards(prmPlayer.opGetCollection());
			break;
			
		case 2:
			opAddCollection(
							prmCatalog,
							prmPlayer.opGetCollection());
			break;
			
		case 3:
			opSearchCollection(prmPlayer.opGetCollection());
			break;
			
		case 4:
			opRemoveCollection(prmPlayer.opGetCollection());
			break;
			
		case 5:
			opSaveCollection(prmPlayer);
			break;
			
		case 6:
			opLoadCollection(prmPlayer);
			break;
			
		case 0:
			cout << "\nVolviendo al menu de jugadores.\n";
			break;
			
		default:
			cout << "\nOpcion no valida.\n";
			break;
		}
		
	} while (option != 0);
}

// ==========================================
// REGISTRAR CARTA EN EL HISTORIAL
// ==========================================

void opRegisterHistory(clsSimpleList &prmCatalog,
					   clsDoubleList &prmHistory)
{
	int id;
	int length = 0;
	
	cout << "\nIngrese el ID de la carta: ";
	cin >> id;
	
	clsCarta *array = prmCatalog.opToArray(length);
	
	for (int i = 0; i < length; i++)
	{
		if (array[i].opGetId() == id)
		{
			prmHistory.opInsertLast(array[i]);
			
			cout << "\nCarta registrada en el historial.\n";
			
			delete[] array;
			return;
		}
	}
	
	delete[] array;
	
	cout << "\nNo existe una carta con ese ID.\n";
}

// ==========================================
// VISUALIZAR HISTORIAL
// ==========================================

void opShowHistory(clsDoubleList &prmHistory)
{
	if (!prmHistory.opStart())
	{
		cout << "\nEl historial esta vacio.\n";
		return;
	}
	
	int option;
	int movement = 1;
	
	clsCarta currentCard;
	
	do
	{
		prmHistory.opGetCurrent(currentCard);
		
		cout << "\n==================================";
		cout << "\n       HISTORIAL DE CARTAS";
		cout << "\n==================================";
		
		cout << "\nMovimiento numero: " << movement;
		
		cout << "\n\nID: " << currentCard.opGetId();
		cout << "\nNombre: " << currentCard.opGetName();
		cout << "\nTipo: " << currentCard.opGetType();
		cout << "\nAtaque: " << currentCard.opGetAttack();
		cout << "\nDefensa: " << currentCard.opGetDefense();
		cout << "\nCoste: " << currentCard.opGetCost();
		
		cout << "\n\n1. Siguiente movimiento";
		cout << "\n2. Movimiento anterior";
		cout << "\n0. Volver";
		
		cout << "\nSeleccione una opcion: ";
		cin >> option;
		
		switch (option)
		{
		case 1:
			if (prmHistory.opNext())
				movement++;
			else
				cout << "\nYa estas en el ultimo movimiento.\n";
			break;
			
		case 2:
			if (prmHistory.opPrevious())
				movement--;
			else
				cout << "\nYa estas en el primer movimiento.\n";
			break;
			
		case 0:
			cout << "\nSaliendo del historial.\n";
			break;
			
		default:
			cout << "\nOpcion no valida.\n";
			break;
		}
		
	} while (option != 0);
}

// ==========================================
// BUSCAR EN EL HISTORIAL
// ==========================================

void opSearchHistory(clsDoubleList &prmHistory)
{
	int id;
	
	cout << "\nIngrese el ID de la carta: ";
	cin >> id;
	
	if (prmHistory.opSearch(id))
		cout << "\nLa carta se encuentra en el historial.\n";
	else
		cout << "\nLa carta no se encuentra en el historial.\n";
}

// ==========================================
// ELIMINAR DEL HISTORIAL
// ==========================================

void opRemoveHistory(clsDoubleList &prmHistory)
{
	int id;
	
	cout << "\nIngrese el ID de la carta: ";
	cin >> id;
	
	if (prmHistory.opRemove(id))
		cout << "\nCarta eliminada correctamente.\n";
	else
		cout << "\nNo se encontro la carta.\n";
}

// ==========================================
// MENU DEL HISTORIAL
// ==========================================

void opMenuHistory(clsSimpleList &prmCatalog,
				   clsDoubleList &prmHistory)
{
	int option;
	
	do
	{
		cout << "\n======= HISTORIAL DE CARTAS =======";
		cout << "\n1. Registrar carta";
		cout << "\n2. Visualizar historial";
		cout << "\n3. Buscar carta";
		cout << "\n4. Eliminar carta";
		cout << "\n0. Volver";
		cout << "\nSeleccione una opcion: ";
		
		cin >> option;
		
		switch (option)
		{
		case 1:
			opRegisterHistory(prmCatalog, prmHistory);
			break;
			
		case 2:
			opShowHistory(prmHistory);
			break;
			
		case 3:
			opSearchHistory(prmHistory);
			break;
			
		case 4:
			opRemoveHistory(prmHistory);
			break;
			
		case 0:
			cout << "\nVolviendo al menu principal.\n";
			break;
			
		default:
			cout << "\nOpcion no valida.\n";
			break;
		}
		
	} while (option != 0);
}

// ==========================================
// REGISTRAR JUGADOR
// ==========================================

void opRegisterPlayer(clsCircularList &prmPlayers)
{
	int length = 0;
	
	clsJugador *array = prmPlayers.opToArray(length);
	
	if (length >= 2)
	{
		delete[] array;
		cout << "\nYa hay dos jugadores registrados.\n";
		return;
	}
	
	delete[] array;
	
	int id;
	string name;
	int lifePoints;
	
	cout << "\nIngrese el ID del jugador: ";
	cin >> id;
	
	if (prmPlayers.opSearch(id))
	{
		cout << "\nYa existe un jugador con ese ID.\n";
		return;
	}
	
	cout << "Ingrese el nombre del jugador: ";
	cin >> ws;
	getline(cin, name);
	
	cout << "Ingrese los puntos de vida: ";
	cin >> lifePoints;
	
	if (lifePoints <= 0)
	{
		cout << "\nLos puntos de vida deben ser mayores que cero.\n";
		return;
	}
	
	clsJugador newPlayer(id, name, lifePoints);
	
	prmPlayers.opInsertLast(newPlayer);
	
	cout << "\nJugador registrado correctamente.";
	cout << "\nSu coleccion comienza vacia.\n";
}

// ==========================================
// MOSTRAR JUGADOR ACTUAL
// ==========================================

void opShowCurrentPlayer(clsCircularList &prmPlayers)
{
	clsJugador *current = prmPlayers.opGetCurrent();
	
	if (current == NULL)
	{
		cout << "\nNo hay jugadores registrados.\n";
		return;
	}
	
	cout << "\n======= TURNO ACTUAL =======";
	cout << "\nID: " << current->opGetId();
	cout << "\nNombre: " << current->opGetName();
	cout << "\nPuntos de vida: " << current->opGetLifePoints();
	cout << "\n";
}

// ==========================================
// AVANZAR TURNO
// ==========================================

void opAdvanceTurn(clsCircularList &prmPlayers)
{
	if (prmPlayers.opIsEmpty())
	{
		cout << "\nNo hay jugadores registrados.\n";
		return;
	}
	
	prmPlayers.opAdvance();
	
	cout << "\nEl turno ha avanzado.\n";
	
	opShowCurrentPlayer(prmPlayers);
}

// ==========================================
// MOSTRAR JUGADORES
// ==========================================

void opShowPlayers(clsCircularList &prmPlayers)
{
	int length = 0;
	
	clsJugador *array = prmPlayers.opToArray(length);
	
	if (length == 0)
	{
		cout << "\nNo hay jugadores registrados.\n";
		return;
	}
	
	cout << "\n======= JUGADORES REGISTRADOS =======\n";
	
	for (int i = 0; i < length; i++)
	{
		cout << "\nID: " << array[i].opGetId();
		cout << "\nNombre: " << array[i].opGetName();
		cout << "\nPuntos de vida: " << array[i].opGetLifePoints();
		cout << "\n-----------------------------\n";
	}
	
	delete[] array;
}

// ==========================================
// BUSCAR JUGADOR
// ==========================================

void opSearchPlayer(clsCircularList &prmPlayers)
{
	int id;
	
	cout << "\nIngrese el ID del jugador: ";
	cin >> id;
	
	if (prmPlayers.opSearch(id))
		cout << "\nEl jugador se encuentra registrado.\n";
	else
		cout << "\nNo existe un jugador con ese ID.\n";
}

// ==========================================
// ELIMINAR JUGADOR
// ==========================================

void opRemovePlayer(clsCircularList &prmPlayers)
{
	int id;
	
	cout << "\nIngrese el ID del jugador que desea eliminar: ";
	cin >> id;
	
	if (prmPlayers.opRemove(id))
		cout << "\nJugador eliminado correctamente.\n";
	else
		cout << "\nNo se encontro el jugador.\n";
}

// ==========================================
// MENU DE JUGADORES
// ==========================================

void opMenuPlayers(clsCircularList &prmPlayers,
				   clsSimpleList &prmCatalog)
{
	int option;
	
	do
	{
		cout << "\n======= GESTION DE JUGADORES =======";
		cout << "\n1. Registrar jugador";
		cout << "\n2. Mostrar jugador actual";
		cout << "\n3. Avanzar turno";
		cout << "\n4. Mostrar jugadores registrados";
		cout << "\n5. Buscar jugador";
		cout << "\n6. Eliminar jugador";
		cout << "\n7. Gestionar coleccion del jugador actual";
		cout << "\n0. Volver";
		cout << "\nSeleccione una opcion: ";
		
		cin >> option;
		
		switch (option)
		{
		case 1:
			opRegisterPlayer(prmPlayers);
			break;
			
		case 2:
			opShowCurrentPlayer(prmPlayers);
			break;
			
		case 3:
			opAdvanceTurn(prmPlayers);
			break;
			
		case 4:
			opShowPlayers(prmPlayers);
			break;
			
		case 5:
			opSearchPlayer(prmPlayers);
			break;
			
		case 6:
			opRemovePlayer(prmPlayers);
			break;
			
		case 7:
		{
			clsJugador *current = prmPlayers.opGetCurrent();
			
			if (current == NULL)
			{
				cout << "\nNo hay jugadores registrados.\n";
			}
			else
			{
				opMenuCollection(*current, prmCatalog);
			}
			
			break;
		}
		
		case 0:
			cout << "\nVolviendo al menu principal.\n";
			break;
			
		default:
			cout << "\nOpcion no valida.\n";
			break;
		}
		
	} while (option != 0);
}

// ==========================================
// MAIN
// ==========================================

int main()
{
	clsSimpleList catalogList;
	clsDoubleList historyList;
	clsCircularList playersList;
	
	int option;
	
	if (clsPersistence::opLoadCards(catalogList, "cartas.txt"))
		cout << "\nCatalogo cargado correctamente.\n";
	else
		cout << "\nNo se pudo cargar el catalogo.\n";
	
	do
	{
		cout << "\n==================================";
		cout << "\n    MYSTICAL CARDS BATTLEGROUND";
		cout << "\n==================================";
		
		cout << "\n1. Mostrar catalogo";
		cout << "\n2. Gestionar historial";
		cout << "\n3. Gestionar jugadores";
		cout << "\n0. Salir";
		
		cout << "\nSeleccione una opcion: ";
		cin >> option;
		
		switch (option)
		{
		case 1:
			opShowCards(catalogList);
			break;
			
		case 2:
			opMenuHistory(catalogList, historyList);
			break;
			
		case 3:
			opMenuPlayers(playersList, catalogList);
			break;
			
		case 0:
			cout << "\nGracias por jugar.\n";
			break;
			
		default:
			cout << "\nOpcion no valida.\n";
			break;
		}
		
	} while (option != 0);
	
	return 0;
}
