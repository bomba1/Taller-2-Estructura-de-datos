#include "stdafx.h"
#include "Espada.h"


Espada::Espada()
{
}

Espada::Espada(int fila, int columna) {
	this->fila = fila;
	this->columna = columna;
	this->valor = 'S';
	this->left = nullptr;
	this->up = nullptr;
}

Espada::~Espada()
{
}
