#pragma once
#include <stdio.h>
#include <Windows.h>
#include <conio.h>//detecta las teclas
#include <stdlib.h>

class Bala
{
private:
	int x;
	int y;
public:
	Bala(int _x, int _y) {
		x = _x;
		y = _y;
	}

	int getX() { return x; }
	int getY() { return y; }

	void gotoxy(int x, int y) {
		HANDLE hCon;
		hCon = GetStdHandle(STD_OUTPUT_HANDLE); //identificador de consola
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;

		SetConsoleCursorPosition(hCon, dwPos);
	}

	void mover() {
		gotoxy(x, y); printf(" ");
		if (y > 2) y--;
		gotoxy(x, y); printf("*");
	}

	bool fuera() {
		if (y == 2) return true;
		return false;
	}
};

