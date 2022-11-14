#include <iostream>
#include "funciones.h"

using namespace std;

int main()
{
	system("color f0");
	char matrizBase[filas][columnas] = { '-', '-', '-', '-', '-', '-', '-', '-', '-' };
	int jugador = 1, i = 0;
	char caracter;
	char jugadores[2];
	int posicionFila, posicionColumna;
	bool sinoGano;
	int contadorDeEmpate = 0;
	try
	{
		ingresoCaracteres(jugadores);
		system("cls");
		do
		{
			verMatrizBase(matrizBase);
			cout << "\t\t===Jugador " << jugador << "====" << endl;
			jugadores[i];
			cout << "Posicion de fila: ";
			cin >> posicionFila;
			cout << "Posicion de columna: ";
			cin >> posicionColumna;
			ingresoDatos(jugadores, matrizBase, posicionFila - 1, posicionColumna - 1, i);
			sinoGano = verificador(matrizBase, jugadores, i);
			contadorDeEmpate++;
			if (sinoGano)
			{
				system("cls");
				cout << "Jugador " << jugador << "  Gano!!!" << endl;
				verMatrizBase(matrizBase);
			}
			else
			{
				if (contadorDeEmpate == 9)
				{
					system("cls");
					cout << "Empataron!!!" << endl;
					verMatrizBase(matrizBase);
					sinoGano = true;
				}
				else
				{
					jugador++;
					i++;
					if (jugador > 2)
						jugador = 1;
					if (i > 1)
						i = 0;
					system("cls");
				}
			}
		} while (!sinoGano);
	}
	catch(exception excp)
	{
		cout << "Algun error ocurrio!" << endl;
	}
	return 0;
}