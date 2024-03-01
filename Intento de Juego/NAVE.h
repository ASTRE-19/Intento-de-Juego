#pragma once
#include <stdio.h>
#include <Windows.h>
#include <conio.h>//detecta las teclas
#include <iostream>

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

class NAVE
{

private:
	int x;
	int y;
	int corazones;
	int vidas;
public:
	NAVE(int _x, int _y, int _corazones, int _vidas)
		: x(_x), y(_y),
		corazones(_corazones),
		vidas(_vidas) {
		/*x = _x;
		y = _y*/;
	}; //Constructor otra forma
	void pintar() {
		gotoxy(x, y);printf("  %c",35);
		gotoxy(x, y + 1);printf(" %c%c%c", 40, 207, 41);
		gotoxy(x, y + 2);printf("%c%c %c%c", 174, 190, 190, 175);
		morir();
	}
	void borrar() {
		gotoxy(x, y);printf("       ");
		gotoxy(x, y + 1);printf("        ");
		gotoxy(x, y + 2);printf("        ");
	}
	void mover() {
		if (_kbhit()) {
			char tecla = _getch();
			borrar();
			//Definiendo los limites para la nave
			if (tecla == IZQUIERDA && x>3) x--;
			if (tecla == DERECHA && x+6<90) x++;
			if (tecla == ARRIBA && y>2) y--;//la coordenada y esta invertida
			if (tecla == ABAJO && y+3<27) y++;
			if (tecla == 'e') corazones--;
			pintarCorazones();
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

	void pintar_limites() {
		for (int i = 2; i < 90; i++) {
			gotoxy(i, 1); printf("%c", 205);
			gotoxy(i, 27); printf("%c", 205);
		}

		for (int i = 2; i < 27; i++) {
			gotoxy(2, i); printf("%c", 186);
			gotoxy(89, i); printf("%c", 186);
		}

		gotoxy(2, 1); printf("%c", 201);
		gotoxy(2, 27); printf("%c", 200);
		gotoxy(89, 1); printf("%c", 187);
		gotoxy(89, 27); printf("%c", 188);

	}

	void pintarCorazones() {
		gotoxy(92, 6); printf("Vidas %d", vidas);
		gotoxy(92, 2); printf("Salud");
		gotoxy(93, 3); printf("      ");
		for (int i = 0; i < corazones; i++) {

			gotoxy(93 + i, 3); printf("%c",219);
		}

	}

	void morir() {
		if (corazones == 0) {
			borrar();
			gotoxy(x, y);printf("   **  ");
			gotoxy(x, y+1);printf("  ****  ");
			gotoxy(x, y+2);printf("   **  ");
			Sleep(200);

			borrar();
			gotoxy(x, y);printf(" * ** *");
			gotoxy(x, y + 1);printf("  **** ");
			gotoxy(x, y + 2);printf(" * ** *");
			Sleep(200);
			borrar();
			vidas--;
			corazones = 3;
			pintarCorazones();
			pintar();
		}
	}
};


