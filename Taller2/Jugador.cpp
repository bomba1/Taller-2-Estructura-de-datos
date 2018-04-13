#include "stdafx.h"
#include "Jugador.h"




Jugador::Jugador(int fila,int columna){
	this->fila = fila;
	this->columna = columna;
	this->valor = '@';
	this->left = nullptr;
	this->up = nullptr;
	this->espada = false;
	this->objeto = '.';

}


Jugador::~Jugador()
{
}
