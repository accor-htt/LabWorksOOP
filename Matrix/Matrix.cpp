#include "stdafx.h"
#include "Matrix.h"

using namespace Math;

int Matrix::count = 0;

Matrix::Matrix() {
	id = ++count;
	_row = _col = 0;
	matrix = nullptr;
	cout << "Constructor #" << id << endl;
}

Matrix::Matrix(int param, const double *data) {
	id = ++count;
	_col = _row = param;
	matrix = new double[_row * _col];
	
	if (data == nullptr) {
		for (int i = 0; i < getSize(); i++) {
			matrix[i] = 0.0;
		}
	} else {
		for (int i = 0; i < getSize(); i++) {
			matrix[i] = data[i];
		}
	}

	cout << "Constructor #" << id << endl;
}

Matrix::Matrix(int row, int col, const double *data) {
	id = ++count;
	_col = col;
	_row = row;
	matrix = new double[_row * _col];

	if (data == nullptr) {
		for (int i = 0; i < getSize(); i++) {
			matrix[i] = 0.0;
		}
	}
	else {
		for (int i = 0; i < getSize(); i++) {
			matrix[i] = data[i];
		}
	}

	cout << "Constructor #" << id << endl;
}

Matrix::Matrix(const Matrix & CopyMatrix) {
	id = ++count;
	_row = CopyMatrix._row;
	_col = CopyMatrix._col;

	matrix = new double[_row * _col];
	for (int i = 0; i < getSize(); i++) {
		matrix[i] = CopyMatrix.matrix[i];
	}
	cout << "Copy constructor #" << id << endl;
}

Matrix::~Matrix() {
	delete[]matrix;
	cout << "Destructor #" << id << endl;
}

ostream & Math::operator<<(ostream &output, const Matrix &m) {
	
	streamsize width = output.width();
	for (int i = 0; i < m._row; i++) {
		for (int j = 0; j < m._col; j++) {
			output.width(width);
			output << m.matrix[i] << " ";
		}
		output << endl;
	}
	output << endl;

	return output;
}

int Matrix::getRow() const {
	return _row;
}
int Matrix::getCol() const {
	return _col;
}

int Matrix::getID() const {
	return id;
}

int Matrix::getSize() const
{
	return (_row * _col);
}

double Matrix::FindMax() const {
	double max = matrix[0];

	for (int i = 0; i < getSize(); i++) {
		if (matrix[i] > max)
			max = matrix[i];
	}

	return max;
}

double Matrix::FindMin() const {
	double min = matrix[0];

	for (int i = 0; i < getSize(); i++) {
		if (matrix[i] < min)
			min = matrix[i];
	}

	return min;
}

bool Matrix::CheckAdd(const Matrix &m2) const {

	if ((_col == m2._col) && (_row == m2._row)) {
		return true;
	} else {
		throw "Add/Sub is impossible, because count of cols and rows Matrix #" + to_string(id) + 
				" and Matrix #" + to_string(m2.id) + " not equals";
	}
}

bool Matrix::CheckMul(const Matrix &m2) const {

	if (_col == m2._row) {
		return true;
	} else {
		throw "Mul is impossible, because cols of Matrix #" + to_string(id) +
			" not equals rows of Matrix #" + to_string(m2.id);
	}

	return false;
}


Matrix & Matrix::operator=(const Matrix &m2) {

	if (getSize() == m2.getSize()) {
		for (int i = 0; i < getSize(); i++) {
			matrix[i] = m2.matrix[i];
		}
	} else {
		delete[] matrix;
		_col = m2._col;
		_row = m2._row;
		matrix = new double[_col * _row];

		for (int i = 0; i < getSize(); i++) {
			matrix[i] = m2.matrix[i];
		}
	}

	return *this;
}

Matrix & Matrix::operator+=(const Matrix &m2) {

	if (CheckAdd(m2)) {
		for (int i = 0; i < getSize(); i++) {
			matrix[i] += m2.matrix[i];
		}
	}

	return *this;
}

Matrix & Matrix::operator-=(const Matrix &m2) {

	if (CheckAdd(m2)) {
		for (int i = 0; i < getSize(); i++) {
			matrix[i] -= m2.matrix[i];
		}
	}

	return *this;
}

Matrix & Matrix::operator*=(const Matrix &m2) {

	if (CheckMul(m2)) {
		Matrix temp(_row, m2._col);
		for (int i = 0; i < temp._row; i++) {
			for (int j = 0; j < m2._col; j++) {
				for (int k = 0; k < m2._row; k++) {
					temp.matrix[i * temp._col + j] += matrix[i * _col + k] * m2.matrix[k * m2._col + j];
				}
			}
		}
		return (*this = temp);
	}
}

Matrix & Matrix::operator*=(const double scalar) {

	for (int i = 0; i < getSize(); i++) {
		matrix[i] *= scalar;
	}

	return *this;
}

Matrix Math::operator+(const Matrix &m1, const Matrix &m2) {
	return Matrix(m1) += m2;
}

Matrix Math::operator-(const Matrix &m1, const Matrix &m2) {
	return Matrix(m1) -= m2;
}

Matrix Math::operator*(const Matrix &m, const double k) {
	return Matrix(m) * k;
}

Matrix Math::operator*(const Matrix &m1, const Matrix &m2) {
	return Matrix(m1) *= m2;
}

Matrix::Index::Index(Matrix *arr, int index) {
	_arr = arr;
	_index = index;
}

Matrix::Index::Index(const Matrix *arr, const int index) {
	_brr = arr;
	_index = index;
}

Matrix::Index Matrix::operator[](int index) {
	if (index < 0 || index >= getSize()) {
		throw ("Index incorrect");
	}
	return Index(this, index);
}

const Matrix::Index Matrix::operator[](const int index) const {
	if (index < 0 || index >= getSize()) {
		throw ("Index incorrect");
	}
	return Index(this, index);
}

double & Matrix::Index::operator[](int j) {
	return _arr->matrix[_index * _arr->_col + j];
}

const double & Matrix::Index::operator[](const int j) const {
	return _arr->matrix[_index * _arr->_col + j];
}





