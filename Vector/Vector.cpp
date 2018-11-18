#define _USE_MATH_DEFINES

#include "Vector.h"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;
using namespace Math;

int Vector::count = 0;

Vector::Vector() {
	_x = _y = _z = 0;
	id = ++count;
	cout << "Конструктор Вектора #" << id << endl;
}

Vector::Vector(double x, double y, double z) {
	_x = x;
	_y = y;
	_z = z;
	id = ++count;
	cout << "Конструктор Вектора #" << id << endl;
}

Vector::Vector(const Vector &obj) {
	_x = obj._x;
	_y = obj._y;
	_z = obj._z;
	id = ++count;
	cout << "Конструктор Вектора #" << id << endl;
}

Vector::~Vector() {
	cout << "Деструктор класса #" << id << endl;
}

// Чтение значения х
double Vector::GetX() const {
	return _x;
}

// Запись в значение х
void Vector::SetX(double x) {
	_x = x;
}

// Чтение значения y
double Vector::GetY() const {
	return _y;
}

// Запись в значение y
void Vector::SetY(double y) {
	_y = y;
}

// Чтение значения z
double Vector::GetZ() const {
	return _z;
}

// Запись в значение z
void Vector::SetZ(double z) {
	_z = z;
}

int Vector::GetID() const {
	return id;
}

// Печать
void Vector::Print() const {
	cout << "X = " << _x << endl << "Y = " << _y << endl << "Z = " << _z << endl << endl;
}

// Вычисление модуля вектора
double Vector::Module() const {
	return sqrt((_x * _x) + (_y * _y) + (_z * _z));
}
 
// Нормирование вектора
Vector& Vector::Normalized() {
	double len = Module();
	if (len == 0) 
		throw "Деление на ноль при нормализации\nОшибка в векторе #" + to_string(id);
	_x /= len;
	_y /= len;
	_z /= len;
	return *this;
}

// Произведение скаляра на вектор
Vector& Vector::MulpitlicationOnScalar(double scal) {
	_x *= scal;
	_y *= scal;
	_z *= scal;
	return *this;
}

Vector& Vector::Create_Copy(const Vector &Of) {
	_x = Of._x;
	_y = Of._y;
	_z = Of._z;
	return *this; // разыменовывание this (вместо возврата адреса памяти - возвращается обьект располооженный по этому адресу памяти
}

// Сложение с получением нового вектора С
Vector Math::Addition(const Vector &A, const Vector &B) {
	Vector v(A._x + B._x,
			 A._y + B._y,
			 A._z + B._z);
	return v;
}

// Вычитание с получением нового вектора С
Vector Math::Substraction(const Vector &A, const Vector &B) {
	return Vector(A._x - B._x,
				  A._y - B._y,
				  A._z - B._z);
}

// Векторное произведение с получением нового вектора С
Vector Math::Multiplication(const Vector &A, const Vector &B) {
	return Vector((A._y * B._z) - (A._z * B._y),
				  (A._z * B._x) - (A._x * B._z),
				  (A._x * B._y) - (A._y * B._x));
}

// Скалярное произведение 
double Math::ScalarMultiplication(const Vector &A, const Vector &B) {
	return A.GetX() * B.GetX() + A.GetY() * B.GetY() + A.GetZ() * B.GetZ();
}

// Косинус угла между векторами 
double Math::ValueCosBetween(const Vector &A, const Vector &B) {
	double MulpScalar = ScalarMultiplication(A, B);
	if ((A.Module() * B.Module()) == 0)
		throw "Деление на ноль при вычисления косинуса " + to_string(A.id) + ", " + to_string(B.id);
	return (MulpScalar) / (A.Module() * B.Module());
}

// Синус угла между векторами 
double Math::ValueSinBetween(const Vector &A, const Vector &B) {
	double Mulp = Multiplication(A, B).Module();
	if ((A.Module() * B.Module()) == 0)
		throw "Деление на ноль при вычисления синуса " + to_string(A.id) + "," + to_string(B.id);
	return Mulp / A.Module() * B.Module();
}

// Угол между векторами в пределах
double Math::AngleBetween(const Vector &A, const Vector &B) {
	double cosa = ValueCosBetween(A, B);
	double sina = ValueSinBetween(A, B);
	return atan2(sina, cosa) * 180 / M_PI;
}

