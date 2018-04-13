#include "stdafx.h"
#include "Principal.h"




/*Este metodo es el que ejecuta el menu principal del programa
*/
void Principal::menuPrincipal() {

	bool menu = true;

	cout << "Bienvenido a Dragon Quest, un juego creado por alumnos de estructura de datos!" << endl;
	string opcion;
	while (menu) {  //While infinito que es usado para el menu principal

		cout << "Menu principal:" << endl;
		cout << "1.-Nuevo Juego\n2.-Configuracion\n3.-Salir" << endl;
		cin >>opcion;
		try
		{
			std::stoi(opcion);
		}
		catch (const std::exception&)
		{
			cout << "Error,no escribio un numero" << endl;
			continue;
		}
		int opcionDef = std::stoi(opcion);

		switch (opcionDef) //Menu
		{
		case 1:
			menuPartida();
			break;
		case 2:
			subMenuConfiguracion();
			break;
		case 3:
			cout << "Adios, Buena suerte!" << endl;
			cout << "Gracias por jugar nuestro juego!" << endl;
			return;
		default:
			cout << "Error, ingrese una opcion valida porfavor" << endl;
			break;
		}

	}
}
/*Metodo que ejectuta el submenu de configuraciones
*/
void Principal::subMenuConfiguracion(){
	bool menu = true;
	cout << "Usted escogio Configuracion..." << endl;
	string opcion;
	while (menu) { //While infinito que sera usado para el submenu

		cout << "Escoja la opcion que desea configurar" << endl;
		cout << "1.-Tamanio de mapa\n2.-Cantidad de entidades\n3.-Cantidad de pasos\n4.-Volver" << endl;
		cin>>opcion;
		try
		{
			std::stoi(opcion);
		}
		catch (const std::exception&)
		{
			cout << "Error,no escribio un numero" << endl;
			continue;
		}
		int opcionDef = std::stoi(opcion);

		switch (opcionDef) //Menu
		{
		case 1:
			cambiarTamaño(); //Nose porque solo funciona con numeros mas bajos que el por defecto :(
			
			break;
		case 2:
			cambiarEntidades();
			
			break;
		case 3:
			cambiarCantidadMaxPasos();
			
			break;
		case 4:
			cout << "Volviendo..." << endl;
			return;
		default:
			cout << "Error, ingrese una opcion valida porfavor" << endl;
			break;
		}

	}
}
/*Metodo que ejecuta el menu que se usa cuando el usuario esta jugando
*/
void Principal::menuPartida(){
	bool menu = true;
	int direccion = 0;
	cout << "A comenzado una nueva partida" << endl;
	generarMapaAleatorio();
	string opcion;
	while (menu) { //While infinito que sera usado para el submenu
		tablero->imprimir();
		if (jugador->objeto == 'B') {
			if (jugador->espada == true) {
				cout << "Felicidades, has matado al dragon!!" << endl;
				cout << "Juego terminado, regresando al menu principal" << endl;
				cout << "Se han dejado los valores por defecto" << endl;
				tablero->eliminarValores();
				tablero->eliminarValores();
				cantidadDragon = auxCantidadDragon;
				cantidadEspada = auxCantidadEspada;
				cantidadPisoFragil = rand() % ((tablero->alto * tablero->ancho) / 2) + 1;
				jugador->objeto = '.';
				jugador->espada = false;
				jugador->fila = 1;
				jugador->columna = 1;
				aux2CantidadDragon = 1;
				aux2CantidadEspada = 1;
				auxCantidadPisoFragil = rand() % ((tablero->alto * tablero->ancho) / 2) + 1;
				cantidadMaxPasos = 3;
				return;
			}
			else {
				cout << "Estabas indefenso contra el dragon sin tu espada, este te a matado :(, suerte a la proxima!" << endl;
				cout << "Juego terminado, regresando al menu principal" << endl;
				cout << "Se han dejado los valores por defecto" << endl;
				tablero->eliminarValores();
				tablero->eliminarValores();
				cantidadDragon = auxCantidadDragon;
				cantidadEspada = auxCantidadEspada;
				cantidadPisoFragil = rand() % ((tablero->alto * tablero->ancho) / 2) + 1;
				jugador->objeto = '.';
				jugador->espada = false;
				jugador->fila = 1;
				jugador->columna = 1;
				aux2CantidadDragon = 1;
				aux2CantidadEspada = 1;
				auxCantidadPisoFragil = rand() % ((tablero->alto * tablero->ancho) / 2) + 1;
				cantidadMaxPasos = 3;
				return;
			}
		}
		cout << "Escoja la opcion que desea" << endl;
		cout << "1.-Moverse\n2.-Revisar espada\n3.-Recoger objeto\n4.-Escoja esta opcion si esque el juego es inganable o imposible(Se reinicia el juego con un nuevo mapa)\n5.-Salir al menu principal" << endl;
		cin>>opcion;
		try
		{
			std::stoi(opcion);
		}
		catch (const std::exception&)
		{
			cout << "Error,no escribio un numero" << endl;
			continue;
		}
		int opcionDef = std::stoi(opcion);

		switch (opcionDef) //Menu
		{
		case 1:
			cout << "Hacia que lado quiere moverse?(2 = abajo;4 = izquierda;8 = arriba,6 = derecha" << endl;
			cin >> direccion;
			moverse(direccion);
			break;
		case 2:
			cout << "Revisando si el jugador tiene la espada" << endl;
			if (jugador->espada == true) {
				cout << "El jugador tiene la espada, vaya hacia el dragon" << endl;
			}
			else {
				cout << "El jugador no tiene la espada, busquela en el mapa" << endl;
			}
			break;
		case 3:
			if (jugador->objeto == 'S') {
				jugador->espada = true;
				cout << "Se a agregado la espada a su inventario" << endl;
			}
			else {
				cout << "No hay ninguna espada que recoger..." << endl;
			}
			break;
		case 4: //Opcion extra
			tablero->eliminarValores();
			tablero->eliminarValores();
			cantidadDragon = aux2CantidadDragon;
			cantidadEspada = aux2CantidadEspada;
			cantidadPisoFragil = auxCantidadPisoFragil;
			jugador->objeto = '.';
			jugador->espada = false;
			jugador->fila = 1;
			jugador->columna = 1;
			generarMapaAleatorio();
			cout << "Reiniciando el juego" << endl;
			break;
		case 5:
			cout << "Volviendo al menu principal..." << endl;
			cout << "Se han dejado los valores por defecto" << endl;
			tablero->eliminarValores();
			tablero->eliminarValores();
			cantidadDragon = auxCantidadDragon;
			cantidadEspada = auxCantidadEspada;
			cantidadPisoFragil = rand() % ((tablero->alto * tablero->ancho) / 2) + 1;
			jugador->objeto = '.';
			jugador->espada = false;
			jugador->fila = 1;
			jugador->columna = 1;
			aux2CantidadDragon = 1;
			aux2CantidadEspada = 1;
			auxCantidadPisoFragil = rand() % ((tablero->alto * tablero->ancho) / 2) + 1;
			cantidadMaxPasos = 3;
			return;
		default:
			cout << "Error, ingrese una opcion valida porfavor" << endl;
			break;
		}

	}
}
/*Metodo que cambia el tamaño del mapa
*/
void Principal::cambiarTamaño(){
	srand(time(NULL));
	int ancho = 0;
	int alto = 0;
	while (true) {
		cout << "Indique el nuevo ancho del mapa:" << endl;
		cin >> ancho;
		if (ancho <= 0) {
			cout << "Escoja un numero mayor a 0 porfavor" << endl;
			continue;
		}
		break;
	}
	while (true) {
		cout << "Indique el nuevo alto del mapa:" << endl;
		cin >> alto;
		if (alto <= 0) {
			cout << "Escoja un numero mayor a 0 porfavor" << endl;
			continue;
		}
		break;
	}
	tablero->alto = ancho;
	tablero->ancho = alto;
	cout << "Se han cambiado exitosamente las dimensiones del mapa" << endl;
	return;
}
/*Metodo que cambia la cantidad que hay en una entidad
*/
void Principal::cambiarEntidades(){
	bool menu = true;

	cout << "Usted escogio cantidad de entidades" << endl;
	string opcion;
	while (menu) {  //While infinito que es usado para validar 

		cout << "Escoja la entidad que desea cambiarle su cantidad" << endl;
		cout << "1.-Piso fragil\n2.-Dragon\n3.-Espada\n4.-Salir" << endl;
		cin >> opcion;
		try
		{
			std::stoi(opcion);
		}
		catch (const std::exception&)
		{
			cout << "Error,no escribio un numero" << endl;
			continue;
		}
		int opcionDef = std::stoi(opcion);

		switch (opcionDef) //Menu
		{
		case 1:
			
			cambiarPisoFragil();
			cout << "Volviendo al menu de configuracion..." << endl;
			return;
		case 2:
			
			cambiarDragon();
			cout << "Volviendo al menu de configuracion..." << endl;
			return;
		case 3:
			
			cambiarEspada();
			cout << "Volviendo al menu de configuracion..." << endl;
			
			return;
		case 4:
			cout << "Volviendo al menu de configuracion..." << endl;
			return;
		default:
			cout << "Error, ingrese una opcion valida porfavor" << endl;
			break;
		}

	}
}
/*Metodo que cambia el valor por defecto de piso fragil
*/
void Principal::cambiarPisoFragil()
{
	int cantidad = 0;
	while (true) {
		cout << "Indique la nueva cantidad de piso fragil, que no sea mayor al 1/3 del area del mapa y menor que 0" << endl;
		cin >> cantidad;
		if (cantidad <= 0 && cantidad > (tablero->alto * tablero->ancho)/3) {
			cout << "Indique una cantidad valida porfavor" << endl;
			continue;
		}
		cantidadPisoFragil = cantidad;
		auxCantidadPisoFragil = cantidad;
		cout << "Cantidad de piso fragil cambiada" << endl;
		break;
	}
	return;
}
/*Metodo que cambia el valor por defecto de dragon
*/
void Principal::cambiarDragon()
{
	int cantidad = 0;
	while (true) {
		cout << "Indique la nueva cantidad de dragones" << endl;
		cin >> cantidad;
		if (cantidad <= 0 ) {
			cout << "Indique una cantidad valida porfavor" << endl;
			continue;
		}
		cantidadDragon = cantidad;
		aux2CantidadDragon = cantidad;
		cout << "Cantidad de dragones cambiados" << endl;
		break;
	}
	return;
}
/*Metodo que cambia el valor por defecto de las espadas
*/
void Principal::cambiarEspada()
{
	int cantidad = 0;
	while (true) {
		cout << "Indique la nueva cantidad de espadas" << endl;
		cin >> cantidad;
		if (cantidad <= 0) {
			cout << "Indique una cantidad valida porfavor" << endl;
			continue;
		}
		cantidadEspada = cantidad;
		aux2CantidadEspada = cantidad;
		cout << "Cantidad de espadas cambiada" << endl;
		break;
	}
	return;
}
/*Metodo que cambia la cantidad maxima de pasos que puede dar el jugador
*/
void Principal::cambiarCantidadMaxPasos(){
	int cantidad = 0;
	while (true) {
		cout << "Indique la nueva cantidad maxima de pasos" << endl;
		cin >> cantidad;
		if (cantidad <= 0) {
			cout << "Indique una cantidad valida porfavor" << endl;
			continue;
		}
		cantidadMaxPasos = cantidad;
		cout << "Cantidad de pasos cambiados" << endl;
		break;
	}
	return;
}
/*Metodo para mover al jugador
*/
void Principal::moverse(int direccion){
	int casillas  = 0;
	while (true) {
		cout << "Cuantas casillas desea moverse?, Maximo " << cantidadMaxPasos << endl;
		cin >> casillas;
		if (casillas <= 0 || casillas > cantidadMaxPasos) {
			cout << "Ingrese un numero entre el rango que se le dijo porfavor(mayor a 0 y menor o igual a " << cantidadMaxPasos << endl;
			continue;
		}
		break;
	}
	if (direccion == 2) { //Abajo
		tablero->moverJugador(jugador, jugador->fila, jugador->columna, jugador->fila + casillas, jugador->columna);
	}
	if (direccion == 4) { //Izquierda
		tablero->moverJugador(jugador, jugador->fila, jugador->columna, jugador->fila , jugador->columna - casillas);
	}
	if (direccion == 6) { //Derecha
		tablero->moverJugador(jugador, jugador->fila, jugador->columna, jugador->fila, jugador->columna + casillas);
	}
	if (direccion == 8) { //Arriba
		tablero->moverJugador(jugador, jugador->fila, jugador->columna, jugador->fila - casillas, jugador->columna );
	}

}
/*Metodo que genera un mapa aleatorio 
*/
void Principal::generarMapaAleatorio(){	
	srand(time(NULL));
	int generador = 0;
	int generadorFila = 0;
	int generadorColumna = 0;
	cantidadPiso = rand() % ((tablero->alto * tablero->ancho)/2) + 1;
	for (int i = 1; i <= tablero->alto; i++) {
		for (int j = 1; j <= tablero->ancho; j++) {
			generador = rand() % 3;
			if (i == 1 && j == 1) { //Agrega al jugador en la posicion por defecto
				tablero->agregar('@',1, 1);
				continue;
			}
			
			if (generador == 0) { // Si generador es 0 se deja vacio el espacio y se imprime con una x
				continue;
			}
			if (generador == 1) { //Agrega piso fragil hasta que la cantidad de este sea 0
				if (cantidadPisoFragil == 0) {
					j -= 1;
					
					continue;
				}
				tablero->agregar(',', i, j);
				cantidadPisoFragil -= 1;
				continue;
				
			}
			if (generador == 2) { //Agrega piso hasta que la cantidad de este sea 0
				if (cantidadPiso == 0) {
					j -= 1;
					
					continue;
				}
				tablero->agregar('.', i, j);
				cantidadPiso -= 1;
				continue;
			}
			

		}
	}
	generadorFila = rand() % (tablero->alto + 1)+1;
	generadorColumna = rand() % (tablero->ancho + 1)+1;
	while (true) { //Mientras el agregar no sea true seguira intentando agregar el dragon
		
		if (cantidadEspada == 0) {
			break;
		}
		if (tablero->agregar('S', generadorFila, generadorColumna) == false) {
			generadorFila = rand() % (tablero->alto + 1)+1;
			generadorColumna = rand() % (tablero->ancho + 1)+1;
			continue;
		}
		else {
			cantidadEspada -= 1;
			generadorFila = rand() % (tablero->alto + 1) + 1;
			generadorColumna = rand() % (tablero->ancho + 1) + 1;
		}
	}
	
	generadorFila = rand() % (tablero->alto + 1)+1;
	generadorColumna = rand() % (tablero->ancho + 1)+1;
	while (true) { //Mientras el agregar no sea true seguira intentando agregar la espada
		
		if (cantidadDragon == 0) {
			break;
		}
		if (tablero->agregar('B', generadorFila, generadorColumna) == false) {
			generadorFila = rand() % (tablero->alto + 1)+1;						  //En posiciones random
			generadorColumna = rand() % (tablero->ancho + 1)+1;
			continue;
		}
		else {
			cantidadDragon -= 1;
			generadorFila = rand() % (tablero->alto + 1) + 1;
			generadorColumna = rand() % (tablero->ancho + 1) + 1;
		}
	}
	
}

Principal::Principal()
{
	srand(time(NULL));
	cantidadPisoFragil = rand() % ((tablero->alto * tablero->ancho)/2) + 1;
	auxCantidadPisoFragil = rand() % ((tablero->alto * tablero->ancho) / 2) + 1;
	menuPrincipal();

}


Principal::~Principal()
{
}
