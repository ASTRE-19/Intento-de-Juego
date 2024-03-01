#pragma once
#include <stdio.h>
#include <Windows.h>
#include <conio.h>//detecta las teclas

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

class NAVE
{

private:
	int x;
	int y;
public:
	NAVE(int _x, int _y): x(_x),y(_y) {
		/*x = _x;
		y = _y*/;
	}; //Constructor otra forma
	void pintar() {
		gotoxy(x, y);printf("  %c",30);
		gotoxy(x, y + 1);printf(" %c%c%c", 40, 207, 41);
		gotoxy(x, y + 2);printf("%c%c %c%c", 35, 190, 190, 35);
		
	}
	void borrar() {
		gotoxy(x, y);printf("     ");
		gotoxy(x, y + 1);printf("     ");
		gotoxy(x, y + 2);printf("     ");
	}
	void mover() {
		if (_kbhit()) {
			char tecla = _getch();
			borrar();

			if (tecla == IZQUIERDA) x--;
			if (tecla == DERECHA) x++;
			if (tecla == ARRIBA) y--;//la coordenada y esta invertida
			if (tecla == ABAJO) y++;
			pintar();
		}
	}
	void gotoxy(int x, int y) {
		HANDLE hCon;
		hCon = GetStdHandle(STD_OUTPUT_HANDLE); //identificador de consola
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;

		SetConsoleCursorPosition(hCon, dwPos);

	}

};


