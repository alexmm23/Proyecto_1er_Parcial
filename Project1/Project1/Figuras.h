//Adrian Alejandro Montes Mendoza - 22110135 - Grupo: 2°O
#pragma once
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
using namespace std;

#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77
#define ESCAPE 27

COORD coord = { 0,0 };
void gotoxy(int, int);

void gotoxy(int x, int y) {
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);


}
void mover_cuadrado() {
	bool bucle = false;
	int coord_x = 0, coord_y = 0;
	char queso = 'x';

	gotoxy(coord_x, coord_y);
	cout << queso;

	while (!bucle)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 72: //arriba
			{
				system("cls");
				coord_y--;
				cout << queso; //borrar e imprimir cuadrado
				gotoxy(coord_x, coord_y);
				break;
			}
			case 80: //abajo
			{
				system("cls");
				coord_y++;
				gotoxy(coord_x, coord_y);
				cout << queso;
				break;
			}
			case 75: //izquierda
			{
				system("cls");
				coord_x--;
				gotoxy(coord_x, coord_y);
				cout << queso;
				break;
			}
			case 77: //derecha
			{
				system("cls");
				coord_x++;
				gotoxy(coord_x, coord_y);
				cout << queso;
				break;
			}
			case 27:
				bucle = true;
			}

		}
	}
}

class Figura {
private:
	int medida_figura = 0;
	bool tipo_relleno = 0;
public:
	
	void setMedidafigura(int);
	int getMedidafigura(void);
	int getTiporelleno(void);
	void setTiporelleno(int);
	virtual void dibujar_figura();//Polimormismo
};
void Figura::setMedidafigura(int medida) {
	if (medida < 0) {
		medida_figura = 0;
	}
	else {
		medida_figura = medida;
	}
}
int Figura::getTiporelleno() {
	return tipo_relleno;
}
int Figura::getMedidafigura() {
	return medida_figura;
}
void Figura::setTiporelleno(int relleno) {
	if (relleno == 0 || relleno == 1) {
		tipo_relleno = relleno;
	}
	else
	{
		tipo_relleno = 1;
	}

}
void Figura::dibujar_figura() {

}

class Cuadrado : public Figura {

public:
	void dibujar_figura();

};
void Cuadrado::dibujar_figura() {
	Figura::dibujar_figura();

	getMedidafigura();
	getTiporelleno();

	if (getTiporelleno() == 1) {

		for (int i = 1; i <= getMedidafigura(); i++) {
			for (int j = 1; j <= getMedidafigura(); j++) {

				cout << "* ";

			}
			cout << "\n";
		}

	}
	else {

		for (int i = 1; i <= getMedidafigura(); i++) {
			for (int j = 1; j <= getMedidafigura(); j++) {
				if (i == 1 || i == getMedidafigura() || j == 1 || j == getMedidafigura()) {
					cout << "* ";
				}
				else {
					cout << "  ";
				}
			}

			cout << "\n";
		}
	}


}

class Triangulo : public Figura {
public:
	void dibujar_figura();
};
void Triangulo::dibujar_figura() {
	Figura::dibujar_figura();

	getMedidafigura();
	getTiporelleno();

	if (getTiporelleno() == 1)
	{
		for (int i = getMedidafigura(); i >= 1; i--)
		{
			for (int j = 0; j < i; j++)
			{
				cout << "*";
			}
			cout << "\n";
		}

	}
	else {
		for (int i = 0; i < getMedidafigura(); i++) {
			cout << "*";

		}

		cout << "" << endl;

		for (int i = 1; i < getMedidafigura() - 1; i++) {
			cout << "*";
			for (int j = 0; j < getMedidafigura() - i - 2; j++) {
				cout << " ";
			}
			cout << "*" << endl;
		}
		cout << "*" << endl;
	}
}

class Rectangulo : public Figura {
private:
	int alto = 0;
public:
	void setAlto(int);
	int getAlto(void);
	void dibujar_figura();
};
void Rectangulo::setAlto(int altura) {
	if (altura < 0)
	{
		alto = 0;
	}
	else {
		alto = altura;
	}

}

int Rectangulo::getAlto() { 
	return alto; 
}
void Rectangulo::dibujar_figura() {
	Figura::dibujar_figura();
	
	getAlto();
	getMedidafigura();
	getTiporelleno();

	if (getTiporelleno() == 1) {

		for (int i = 1; i <= getAlto(); i++) {
			for (int j = 1; j <= getMedidafigura(); j++) {

				cout << "* ";

			}
			cout << "\n";
		}

	}
	else {

		for (int i = 1; i <= getAlto(); i++) {
			for (int j = 1; j <= getMedidafigura(); j++) {
				if ( i == 1 || i == getAlto() || j == 1 || j == getMedidafigura() ) {
					cout << "* ";
				}
				else {
					cout << "  ";
				}
			}

			cout << "\n";
		}
	}


}

class Menu {
private:
	int tipo_figura, tamano_figura,tamano2_figura, es_relleno;
public:
	void imprimir_menu();


};
void Menu::imprimir_menu()
{
	while (true)
	{
		while (true)
		{
			//system("cls");
			cout << "||Adrian Alejandro Montes Mendoza||" << endl;
			cout << "||--Proyecto primer parcial POO--||" << endl;
			cout << endl;
			cout << "--Seleccione la figura a imprimir--" << endl;
			cout << endl;
			cout << "| 1 | - Cuadrado\n| 2 | - Triangulo\n| 3 | - Rectangulo\n| 4 | - Salir" << endl;
			cin >> tipo_figura;

			if (tipo_figura < 1 || tipo_figura > 4)
			{
				system("cls");
				cout << "Escoje una opcion valida" << endl;
				system("pause");
				cout << endl << endl;
			}
			else break;
		}
		if (tipo_figura == 4) break;

		cout << "¿De que tamano lo desea?" << endl;
		cin >> tamano_figura;
		cout << "1-Relleno\n0-Hueco" << endl;
		cin >> es_relleno;


		switch (tipo_figura)
		{
		case 1: //imprimir cuadrado 
		{
			Cuadrado c1;
			
			c1.setMedidafigura(tamano_figura);
			c1.setTiporelleno(es_relleno);
			c1.dibujar_figura();
			system("pause");
			system("cls");

			mover_cuadrado();

			system("pause");
			system("cls");

		}
		break;

		case 2://Imprimir triangulo
		{
			Triangulo t1;
			t1.setMedidafigura(tamano_figura);
			t1.setTiporelleno(es_relleno);
			t1.dibujar_figura();
			system("pause");
			system("cls");

			mover_cuadrado();

			system("pause");
			system("cls");
		}
		break;

		case 3: //Imprimir Rectangulo
		{
			cout << "Ingrese la altura del rectangulo" << endl;
			cin >> tamano2_figura;
			Rectangulo r1;
			r1.setMedidafigura(tamano_figura);
			r1.setAlto(tamano2_figura);
			r1.setTiporelleno(es_relleno);
			r1.dibujar_figura();
			system("pause");
			system("cls");
			
			mover_cuadrado();
			
			system("pause");
			system("cls");


			break;
		}
		}
	}
	system("cls");
}