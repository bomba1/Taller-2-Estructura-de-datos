#pragma once
#include "Nodo.h"
#include "Dragon.h"
#include "Espada.h"
#include "Jugador.h"
#include"Piso.h"
#include "PisoFragil.h"
#include <string>
using namespace std;
#include <iostream>
#include <sstream>

class Tablero

{
public:
	int ancho;
	int alto;
	Nodo** ACOL;
	Nodo** AROW;

	bool agregar(char valor,int fila, int columna);
	void eliminar(int fila, int columna);
	void imprimir();
	void moverJugador(Jugador* jugador,int filaActual,int columnaActual,int fila2,int columna2);
	Nodo* buscarNodo(int fila, int columna);
	char buscarNodo2(int fila, int columna);
	void eliminarValores();
	

	Tablero();
	Tablero(int alto, int ancho);
	~Tablero();
private:
	
};

