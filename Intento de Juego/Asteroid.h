#pragma once
#include <stdio.h>
#include <Windows.h>
#include <conio.h>//detecta las teclas
#include <stdlib.h>
#include "NAVE.h"


class Asteroid
{
private:
	int x;
	int y;

public:
	Asteroid(int _x, int _y) {
		x = _x;
		y = _y;
	}

	void gotoxy(int x, int y) {
		HANDLE hCon;
		hCon = GetStdHandle(STD_OUTPUT_HANDLE); //identificador de consola
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;

		SetConsoleCursorPosition(hCon, dwPos);

	}

	void pintar() {
		gotoxy(x, y); printf("%c", 184);

	}

	void caer() {
		gotoxy(x, y);printf(" ");
		y++;
		if (y > 26) {
			x = rand() % 87 + 3;
			y = 2;
		}

		pintar();
	}

	void choque(NAVE &N) {
		if (x >= N.getX() && x<N.getX()+6 && y>=N.getY() &&y<=N.getY()+2) {

			N.cor();//retar corazones
			N.borrar();
			N.pintar();//redibujar la nave

			N.pintarCorazones();//redibujar los corazones

			x = rand() % 87 + 3;
			y = 2;  //reubicar el asteroide
		}
	}
};
