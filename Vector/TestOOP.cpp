#include <iostream>
#include <locale.h>
#include <math.h>
#include <string>
#include "Vector.h"

using namespace std;
using namespace Math;

int main() {
	setlocale(LC_ALL, "russian");

	Vector A(1, 2, 3);

	Vector B(1, 2, 3);
	//Addition(A, B).Print();
	Vector C = Addition(A, B);
	C.Print();

	
	A.X() = 555;
	cout << A.X() << endl;
	
	/*
	double result = 0;
	try {
		result = ValueCosBetween(A, B);
	}
	catch (const string &err) {
		cout << "Error: " << err << endl;
		return 0;
	}
	*/

	/*A.Print();

	try {
		A.Normalized();
	}
	catch(const string &err)
	{
		cout << "Error: " << err << endl;
		return 0;
	}

	A.Print();

	double valueScalar = 0;
	cout << "Введите значения скаляра : ";
	cin >> valueScalar;
	A.MulpitlicationOnScalar(valueScalar);
	cout << "Получение значений вектора А после умножения на скаляр: " << endl;
	A.Print();

	cout << "Ввод значений вектора B {x, y, z} (Примечание: через пробел или enter) : ";
	cin >> x >> y >> z;
	Vector B(x, y, z);

	double mod = B.Module();
	cout << "Модуль вектора B = " << mod << endl;

	Vector C = Addition(A, B);
	cout << "Получение значений вектора С после суммы: " << endl;
	C.Print();

	double valCos = ValueSinBetween(A, B);
	cout << "значение cинуса между векторами  = " << valCos << endl;
	*/
    return 0;
}

