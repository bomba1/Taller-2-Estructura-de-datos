#include "stdafx.h"
#include "Piso.h"

Piso::Piso() {

}
Piso::Piso(int fila, int columna)
{
	this->fila = fila;
	this->columna = columna;
	this->valor = '.';
	this->left = nullptr;
	this->up = nullptr;
	
}


Piso::~Piso()
{
}
