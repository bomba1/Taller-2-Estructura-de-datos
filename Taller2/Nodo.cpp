#include "stdafx.h"
#include "Nodo.h"


Nodo::Nodo()
{
}

Nodo::Nodo(int fila, int columna)
{
	this->fila = fila;
	this->columna = columna;
	this->valor = 0;
	this->left = nullptr;
	this->up = nullptr;
}


Nodo::~Nodo()
{
}
