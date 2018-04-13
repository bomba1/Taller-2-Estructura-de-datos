#include "stdafx.h"
#include "Dragon.h"


Dragon::Dragon()
{
}

Dragon::Dragon(int fila, int columna) {
	this->fila = fila;
	this->columna = columna;
	this->valor = 'B';
	this->left = nullptr;
	this->up = nullptr;
}


Dragon::~Dragon()
{
}
