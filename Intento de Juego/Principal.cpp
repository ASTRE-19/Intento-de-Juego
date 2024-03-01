#include <stdio.h>
#include <Windows.h>
#include <conio.h>//detecta las teclas
#include "NAVE.h"
#include "Asteroid.h"


void ocultarCursor() {
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;//Controlar la aparimcia de cursor
	cci.dwSize = 2;//Variable entera que toma valores de 1 a 100(depequenioa grande
	cci.bVisible = FALSE;//Si es verdad se muestra en pantall

	
	SetConsoleCursorInfo(hCon,&cci );//pasar la direccion de la estructura
}



int main() {
	ocultarCursor();
	
	NAVE N(7,7,3,3);  //Crear el objeto
	N.pintar_limites();
	N.pintar();
	N.pintarCorazones();

	Asteroid ast(10, 4);

	bool game_over = false;
	while(!game_over) {
		
		ast.caer();
		N.mover();
		

		Sleep(30);
	}
	return 0;
}

