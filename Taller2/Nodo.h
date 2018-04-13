#pragma once
class Nodo
{
public:
	char valor;
	Nodo* left;
	Nodo* up;
	int columna;
	int fila;

	Nodo();
	Nodo(int fila,int columna);
	~Nodo();
private:


};

