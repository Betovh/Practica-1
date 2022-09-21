#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <conio.h>
#include <string.h>
#include <string>
#include <cstring>  
using namespace std;
class Date {

private:
	int dia;
	int mes;
	int anio;
public:
	string date;
	bool bisiesto;
	void IsBisiesto(int);
	void Run();

	void setDate(int,int,int);
	int getDia();
	int getMes();
	int getAnio();
};

// Constructores, Getters y Setters 
void Date::setDate(int dia,int mes,int anio) {
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
}
int Date::getDia() {
	return dia;
}
int Date::getMes() {
	return mes;
}
int Date::getAnio() {
	return anio;
}

//Método Validación Bisiesto
void Date::IsBisiesto(int anio) {
	this->anio = anio;

	


	if (anio % 4 == 0 && anio % 100 != 0 || anio % 400 == 0) {
		cout << "Su anio es Bisiesto" << endl;
		bisiesto = true;
	}
	else {
		cout << " NO es Bisiesto" << endl;
		bisiesto = false;
	}

}


void Date::Run() {
	
	

		string cadena;
		cout << "\nIngrese la fecha: ";
		cin >> cadena;
		stringstream input_stringstream(cadena);

		string dia_, mes_, anio_;


		getline(input_stringstream, dia_, '-');
		getline(input_stringstream, mes_, '-');
		getline(input_stringstream, anio_, '-');


		cout << "\nDia: " << dia_ << endl;
		cout << "\nMes: " << mes_ << endl;
		cout << "\nAnio: " << anio_ << endl;

		dia = stoi(dia_);
		mes = stoi(mes_);
		anio = stoi(anio_);


		if (dia > 31 || dia == 0) {

			cout << "\nEl dia que ingreso es incorrecto\n";

		}
		else {
			cout << "\nEs correcto\n";

		}

		if (mes > 12 || mes == 0) {

			cout << "\nEl mes que ingreso es incorrecto\n";
		}
		else {
			cout << "\nEs correcto\n";
		}

		
		if (dia > 28 && mes == 02 && bisiesto == true) {

			cout << "\nEl dia de febrero  que ingreso es incorrecto\n";
		}
}


int main() {
	Date fecha;
	fecha.Run();
} 






