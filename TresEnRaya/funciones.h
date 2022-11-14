#pragma once

const int filas = 3;
const int columnas = 3;

void ingresoDatos(char signo[2], char matriz[filas][columnas], int fila, int columna, int id);
void verMatrizBase(char matriz[filas][columnas]);
bool verificador(char matriz[filas][columnas], char signo[2], int id);
void ingresoCaracteres(char jugadores[2]);