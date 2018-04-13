#pragma once
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
#include <iostream>
#include "Tablero.h"
#include <stdlib.h>
#include <time.h>
class Principal
{
public:
	void menuPrincipal();
	void subMenuConfiguracion();
	void menuPartida();
	
	void cambiarTamaño();
	void cambiarEntidades();
	void cambiarPisoFragil();
	void cambiarDragon();
	void cambiarEspada();
	void cambiarCantidadMaxPasos();
	void moverse(int direccion);

	void generarMapaAleatorio();

	Principal();
	~Principal();
private:
	
	Tablero* tablero = new Tablero(10,20);
	int auxCantidadDragon = 1;
	int auxCantidadEspada = 1;
	int aux2CantidadDragon = 1;
	int aux2CantidadEspada = 1;
	int auxCantidadPisoFragil = rand() % ((tablero->alto * tablero->ancho) / 2) + 1;
	int cantidadDragon = 1;
	int cantidadEspada = 1;
	int cantidadPisoFragil = rand() % ((tablero->alto * tablero->ancho)/2)+1 ;
	int cantidadPiso = rand() % ((tablero->alto * tablero->ancho)/2)+1 ;
	int cantidadJugador = 1;
	int cantidadMaxPasos = 3;
	Jugador* jugador = new Jugador(1, 1);
};

