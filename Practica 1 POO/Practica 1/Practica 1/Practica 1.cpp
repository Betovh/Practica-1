#include <iostream>
#include <stdio.h>
#include <sstream>

using namespace std;
class Date {

private:
	int dia;
	int mes;
	int anio;


	void AddDays(int DaysToAdd)
	{
		dia += DaysToAdd;
		if (dia > 30) {

			dia = 1;
			AddMonths(1);
		}

		if (dia > 31)
		{
			dia = 1;
			AddMonths(1);
		}
		if (mes == 2) {

			if (dia > 29)
			{
				dia = 1;
				AddMonths(1);
			}
		}

	}

	void AddMonths(int MonthsToAdd)
	{
		mes += MonthsToAdd;

		if (mes > 12)
		{
			mes = 1;
			AddYears(1);
		}
	}

	void AddYears(int YearsToAdd)
	{
		anio += YearsToAdd;
	}

public:
	
	string date;
	Date& operator ++ ();
	
	Date() {
	
	}

	bool bisiesto;
	void IsBisiesto(int);
	void ValDiaFeb(int);
	void ValDia(int);
	void ValMes(int);
	void ValMesFeb(int);

	void ValYear(int);
	void Run();

	void setDate(int, int, int);


	void getFecha();
	int getDia();
	int getMes();
	int getAnio();


	

};

Date & Date ::operator ++() {
	AddDays(1);
	return *this;
}

int num;



// Constructores, Getters y Setters 
void Date::setDate(int dia, int mes, int anio) {
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
void Date::getFecha() {
	cout << "\nproxima fecha: ";
	cout << dia << "-" << mes << "-" << anio << endl;
}



//Método Validación Bisiesto
void Date::IsBisiesto(int year) {
	this->anio = year;

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		cout << "\nSu Year ES Bisiesto" << endl;
		bisiesto = true;
	}
	else {
		cout << "\nSu Year NO es Bisiesto" << endl;
		bisiesto = false;
	}
}



//Validaciones Año, Mes, Dia

void Date::ValYear(int year) {
	this->anio = year;
	if (anio >= 1000 && anio <= 3000 || anio >= 1 && anio <= 99) {

		ValMes(anio);
	}

}
void Date::ValMes(int year) {
	this->anio = year;

	if (mes >= 1 && mes <= 12) {
		ValMesFeb(anio);

	}
	else {

		cout << "\nEl Mes NO es valido";
	}

}
void Date::ValMesFeb(int year) {
	this->anio = year;
	if (mes == 2) {
		ValDiaFeb(anio);
	}
	else {
		ValDia(anio);
	}
}


void Date::ValDiaFeb(int year) {
	this->anio = year;

	if (dia >= 1 && dia <= 29) {

		IsBisiesto(anio);
		
	}
	
	else {
		cout << "\nEl Dia NO es valido";

	}
}


void Date::ValDia(int year) {
	this->anio = year;


	if (dia >= 1 && dia <= 31) {

		IsBisiesto(anio);

	}
	else {
		cout << "\nEl Dia NO es valido";

	}
}




void Date::Run() {

	string cadena;
	
	cout << "\nIngrese la fecha de esta manera (Dia-Mes-Year):  ";
	cin >> cadena;
	stringstream input_stringstream(cadena);

	string dia_, mes_, anio_;


	getline(input_stringstream, dia_, '-');
	getline(input_stringstream, mes_, '-');
	getline(input_stringstream, anio_, '-');


	cout << "\nDia: " << dia_ << endl;
	cout << "\nMes: " << mes_ << endl;
	cout << "\nYear: " << anio_ << endl;

	dia = stoi(dia_);
	mes = stoi(mes_);
	anio = stoi(anio_);

	cout << "\nIngrese el numero de fechas que quiere visualizar: ";
	cin >> num;
	ValYear(anio);

}

int main() {
	
	Date fecha=Date();

	fecha.Run();
	for (int i = 0; i <num ;i++) {
		++fecha;
		fecha.getFecha();
	}
}
