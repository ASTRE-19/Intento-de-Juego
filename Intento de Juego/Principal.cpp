#include <stdio.h>
#include <Windows.h>
#include <conio.h>//detecta las teclas
#include "NAVE.h"
#include "Asteroid.h"
#include <list>
#include "Bala.h"
using namespace std;


void ocultarCursor() {
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;//Controlar la apariencia de cursor
	cci.dwSize = 2;//Variable entera que toma valores de 1 a 100(de pequenioa grande
	cci.bVisible = FALSE;//Si es verdad se muestra en pantalla

	
	SetConsoleCursorInfo(hCon,&cci );//pasar la direccion de la estructura
}

void gotoxy(int x, int y) {
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE); //identificador de consola
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;

	SetConsoleCursorPosition(hCon, dwPos);
}



int main() {
	ocultarCursor();
	
	NAVE N(7,7,3,3);  //Crear el objeto
	N.pintar_limites();
	N.pintar();
	N.pintarCorazones();

	Asteroid ast(10, 2);
	Asteroid ast1(4, 8);
	Asteroid ast2(15, 10);

	list<Bala*> B; //para crear objetos automatico
	list<Bala*>::iterator it;//Iterador para listas
	bool game_over = false;
	while(!game_over) {
		
		if (_kbhit()) {
			char tecla = _getch();
			if (tecla == 'a'){
				B.push_back(new Bala(N.getX() + 2, N.getY() - 1));
			}
		}

		for (it = B.begin();it != B.end(); it++) {
			(*it)->mover();//para tener acceso a los datos del puntero
			if ((*it)->fuera()) {
				gotoxy((*it)->getX(), (*it)->getY());
				printf(" ");
				/*delete(*it);
				it = B.erase(it);*/
		    }
			
		}
		ast.caer();  ast.choque(N);
		ast1.caer(); ast1.choque(N);
		ast2.caer(); ast2.choque(N);

		N.mover();
		

		Sleep(30);
	}
	return 0;
}

