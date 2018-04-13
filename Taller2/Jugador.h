#pragma once
#include "Nodo.h"
class Jugador : public Nodo{
public:
	bool espada;
	char objeto;
	Jugador(int fila,int columna);
	~Jugador();
};

