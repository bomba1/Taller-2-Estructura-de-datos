#include "stdafx.h"
#include "Tablero.h"



Tablero::Tablero()
{
}
/*Constructor de la clase
*/
Tablero::Tablero(int alto, int ancho){
	ACOL = new Nodo*[ancho + 1];
	AROW = new Nodo*[alto + 1];
	this->ancho = ancho;
	this->alto = alto;
	for (int i = 1; i <= ancho; i++) {
		ACOL[i] = new Nodo(0, i);
		ACOL[i]->up = (ACOL[i]);
	}
	for (int i = 1; i <= alto; i++) {
		AROW[i] = new Nodo(i, 0);
		AROW[i]->left = (AROW[i]);
	}
}
/*Metodo que agrega un nodo a la matriz poco poblada, dependiendo del valor que se da por parametro
se agrega el nodo jugador o dragon etc.
*/
bool Tablero::agregar(char valor,int fila, int columna){
	if (columna > ancho || columna < 1 || fila > alto || fila < 1) return false;
	if (valor == '@') {
		Nodo* nodo = new Jugador(fila,columna);
		Nodo* aux = AROW[fila];
		while (aux->left->columna > 0 && aux->left->columna > columna) {
			if (aux->left->columna == columna) { //Posicion ocupada
				return false;
			}
			aux = aux->left;
		}
		nodo->left = aux->left;
		aux->left = nodo;
		Nodo* aux2 = ACOL[columna];
		
		while (aux2->up->fila > 0 && aux2->up->fila > fila) {
			aux2 = aux2->up;
		}
		nodo->up = aux2->up;
		aux2->up = nodo;
		return true;
		
	}
	else if (valor == 'B') {
		Nodo* nodo = new Dragon(fila, columna);
		Nodo* aux = AROW[fila];
		while (aux->left->columna > 0 && aux->left->columna > columna) {
			if (aux->left->columna == columna) { //Posicion ocupada
				return false;
			}
			aux = aux->left;
		}
		nodo->left = aux->left;
		aux->left = nodo;
		Nodo* aux2 = ACOL[columna];

		while (aux2->up->fila > 0 && aux2->up->fila > fila) {
			aux2 = aux2->up;
		}
		nodo->up = aux2->up;
		aux2->up = nodo;
		return true;
	}
	else if (valor == '.') {
		Nodo* nodo = new Piso(fila, columna);
		Nodo* aux = AROW[fila];
		while (aux->left->columna > 0 && aux->left->columna > columna) {
			if (aux->left->columna == columna) { //Posicion ocupada
				return false;
			}
			aux = aux->left;
		}
		nodo->left = aux->left;
		aux->left = nodo;
		Nodo* aux2 = ACOL[columna];

		while (aux2->up->fila > 0 && aux2->up->fila > fila) {
			aux2 = aux2->up;
		}
		nodo->up = aux2->up;
		aux2->up = nodo;
		return true;
	}
	else if (valor == 'S') {
		Nodo* nodo = new Espada(fila, columna);
		Nodo* aux = AROW[fila];
		while (aux->left->columna > 0 && aux->left->columna > columna) {
			if (aux->left->columna == columna) { //Posicion ocupada
				return false;
			}
			aux = aux->left;
		}
		nodo->left = aux->left;
		aux->left = nodo;
		Nodo* aux2 = ACOL[columna];

		while (aux2->up->fila > 0 && aux2->up->fila > fila) {
			aux2 = aux2->up;
		}
		nodo->up = aux2->up;
		aux2->up = nodo;
		return true;
	}
	else if (valor == ',') {
		Nodo* nodo = new PisoFragil(fila, columna);
		Nodo* aux = AROW[fila];
		while (aux->left->columna > 0 && aux->left->columna > columna) {
			if (aux->left->columna == columna) { //Posicion ocupada
				return false;
			}
			aux = aux->left;
		}
		nodo->left = aux->left;
		aux->left = nodo;
		Nodo* aux2 = ACOL[columna];

		while (aux2->up->fila > 0 && aux2->up->fila > fila) {
			aux2 = aux2->up;
		}
		nodo->up = aux2->up;
		aux2->up = nodo;
		return true;
	}
	
	

}
/*Metodo que elimina un nodo en las posiciones mandadas por parametro, solo si esta ocupada
*/
void Tablero::eliminar(int fila, int columna){
	if (columna > ancho || columna < 1 || fila > alto || fila < 1) return;
	Nodo* aux = AROW[fila];
	while (aux->left->columna > 0 && aux->left->columna > columna) {
		aux = aux->left;
	}
	if (aux->left->columna < columna) return;
	aux->left = aux->left->left;
	aux = ACOL[columna];
	while (aux->up->fila > 0 && aux->up->fila > fila) {
		aux = aux->up;
	}
	aux->up = aux->up->up;
}
/*Metodo que imprime la matriz y los espacios vacio los imprime con una 'X'
*/
void Tablero::imprimir() {
	cout << '"' << "Mapa" << '"' << ':' << endl;
	for (int i = 1; i <= alto; i++) {
		std::string fila;
		Nodo* aux = AROW[i]->left;
		int espaciosVacios = ancho - aux->columna;// obtiene la distancia recorrida entre auxiliares, para asi determinar cuantos 'X' imprimir
		while (true) {
			for (int j = 0; j<(espaciosVacios); j++) {
				fila = "X" + fila;
			}
			if (aux->columna == 0) break;
			std::stringstream s;
			s << aux->valor ;
			fila = s.str() + fila;
			espaciosVacios = aux->columna - aux->left->columna - 1;
			aux = aux->left;
		}
		std::cout << fila << std::endl ;
	}
}
/*Metodo que mueve al jugador de posicion
*/
void Tablero::moverJugador(Jugador* jugador,int filaActual, int columnaActual, int fila2, int columna2){
	if (columna2 > ancho || columna2 < 1 || fila2 > alto || fila2 < 1) {
		cout << "Esta intentando moverse fuera del tablero, intentelo denuevo" << endl;
		return;
	}
	if (buscarNodo2(fila2, columna2) == 0) {
		cout << "Imposible moverse a esta posicion, intentelo denuevo" << endl;
		return;
	}
	Nodo* aux = buscarNodo(fila2, columna2);
	Nodo* aux2 = jugador;

	eliminar(filaActual, columnaActual);
	agregar(jugador->objeto, filaActual, columnaActual);
	if (jugador->objeto == ',') { //Si es piso fragil, se elimina para que quede una X de vacio
		eliminar(filaActual, columnaActual);
	}
	if (jugador->objeto == 'S' && jugador->espada == true) {
		eliminar(filaActual, columnaActual);
		agregar('.', filaActual, columnaActual);
	}
	jugador->objeto = aux->valor;
	jugador->fila = aux->fila;
	jugador->columna = aux->columna;
	
	eliminar(fila2, columna2);
	agregar('@', fila2, columna2);
	return;
}
/*Metodo que busca un nodo por fila y columna
*/
Nodo* Tablero::buscarNodo(int fila, int columna){
	Nodo* aux = AROW[fila]->left;
	while (aux->columna != 0 && aux->columna != columna) { //Se busca el nodo
		aux = aux->left;
	}
	return aux;
}
/*Metodo que busca un nodo y retorna su valor char
*/
char Tablero::buscarNodo2(int fila, int columna)
{
	Nodo* aux = AROW[fila]->left;
	while (aux->columna != 0 && aux->columna != columna) { //Se busca el nodo
		aux = aux->left;
	}
	if (aux->columna == 0) {
		return 0;
	}
	return aux->valor;
	
}
/*Metodo que elimina todos los valores de la matriz, esto para reiniciar el juego
*/
void Tablero::eliminarValores(){
	for (int i = 1; i <= alto; i++) {
		for (int j = 1; j <= ancho; j++) {
			eliminar(i, j);
		}
	}
}




Tablero::~Tablero()
{
}
