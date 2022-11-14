#include "funciones.h"
#include <iostream>

using namespace std;

void ingresoCaracteres(char jugadores[2])
{
	cout << "\t\t\t====Designar Caracter======\n" << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << "Ingrese el caracter del jugador " << i + 1 << ": ";
		cin >> jugadores[i];
	}
}
void verMatrizBase(char matriz[filas][columnas])
{
	cout << endl;
	cout << "\t\t   1 \t 2     3 " << endl;
	for (int i = 0; i < filas; i++)
	{
		cout << "\t\t";
		cout << (i + 1);
		for (int j = 0; j < columnas; j++)
		{
			cout << "  " << matriz[i][j];
			if (j == 2)
				cout << " ";
			else
				cout << " | ";
		}
		cout << endl;
		if (i == 2)
			cout << "" << endl;
		else
			cout << "\t\t-----------------" << endl;
	}
}
void ingresoDatos(char signo[2], char matriz[filas][columnas], int fila, int columna, int id)
{
	/*for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			if (i == fila && j == columna)
				matriz[i][j] = signo;
		}
	}*/
	matriz[fila][columna] = signo[id];
}
bool verificador(char matriz[filas][columnas], char signo[2], int id)
{
	bool gano = false;
	int auxiliar = 0;
	int auxiliarColumnas = 0;
	int auxiliarVerificacion = 0;

	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			if (i == auxiliar) //filas
			{
				if (matriz[i][j] == signo[id])
					auxiliarVerificacion++;
			}
		}
		auxiliar++;
		if (auxiliarVerificacion < 3)
			auxiliarVerificacion = 0;
	}
	for (int j = 0; j < filas; j++)
	{
		for (int i = 0; i < columnas; i++)
		{
			if (j == auxiliarColumnas) //Columnas
			{
				if (matriz[i][j] == signo[id])
					auxiliarVerificacion++;
			}
		}
		auxiliarColumnas++;
		if (auxiliarVerificacion < 3)
			auxiliarVerificacion = 0;
	}
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			if (i == j) //Diagonale Principal
			{
				if (matriz[i][j] == signo[id])
					auxiliarVerificacion++;
			}
		}
	}
	if (auxiliarVerificacion < 3)
		auxiliarVerificacion = 0;
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			if (i + j == 2) //Diagonale Secundaria
			{
				if (matriz[i][j] == signo[id])
					auxiliarVerificacion++;
			}
		}
	}
	if (auxiliarVerificacion < 3)
		auxiliarVerificacion = 0;
	else if (auxiliarVerificacion > 2)
		gano = true;

	return gano;
}