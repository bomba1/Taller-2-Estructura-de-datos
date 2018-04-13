#include "stdafx.h"
#include "PisoFragil.h"


PisoFragil::PisoFragil(){
}

PisoFragil::PisoFragil(int fila, int columna) {
	this->fila = fila;
	this->columna = columna;
	this->valor = ',';
	this->left = nullptr;
	this->up = nullptr;
}

PisoFragil::~PisoFragil()
{
}
