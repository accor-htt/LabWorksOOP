#include "Basic.h"
#include <iostream>

using namespace std;

int math::Basic::count = 0;

math::Basic::Basic() : _row(0), _col(0), _myArr(nullptr), id(++count) {
}

math::Basic::Basic(int row, int col, const double *data) : id(++count) {
    if ((row < 0) || (col < 0)) {
        throw "Rows or cols of object #" + to_string(id) + " < 0";
    }

    Init(row, col, data);
}

math::Basic::Basic(int param, const double *data) : Basic(param, param, data) {
}

math::Basic::Basic(const Basic & CopyBasic) : Basic(CopyBasic._row,CopyBasic._col, CopyBasic._myArr) {
}

math::Basic::Basic(Basic && MoveBasic) noexcept : Basic() {
    operator=(move(MoveBasic));
}

math::Basic::~Basic() {
    if (_myArr != nullptr) {
        delete[]_myArr;
        _myArr = nullptr;
        _row = _col = 0;
    }
}

void math::Basic::Init(int row, int col, const double *data) {
    _col = col;
    _row = row;

    if (_row != 0 && _col != 0) {
        _myArr = new double[_row * _col];
    }
    else {
        _col = _row = 0;
        _myArr = nullptr;
    }

    if (data == nullptr) {
        for (int i = 0; i < getSize(); i++) {
            _myArr[i] = 0.0;
        }
    } else {
        for (int i = 0; i < getSize(); i++) {
            _myArr[i] = data[i];
        }
    }
}

math::Vector::Vector(int length, const double *data) : Basic(length, 1, data) {
}

math::Vector::Vector() : Basic() {
}

math::Vector::Vector(const math::Vector &v) : Basic(v) {
}

math::Vector::Vector(math::Vector &&v) noexcept : Basic(move(v)) {
}

math::Vector::Vector(const math::Basic &b){
    if (getRank(b) > 1) {
        throw "Error, copy constructor for not vector #" + to_string(id);
    }

    Basic::operator = (b);
}

math::Vector::Vector(math::Basic &&b) noexcept {
    if (getRank(b) > 1) {
        throw "Error, copy constructor for not vector #" + to_string(id);
    }

    Basic::operator = (move(b));
}


double &math::Vector::operator[](int index) {
    if (index < 0 || index >= getSize()) {
        throw "Wrong index #" + to_string(id);
    }

    return _myArr[index];
}

const double &math::Vector::operator[](int index) const {
    if (index < 0 || index >= getSize()) {
        throw "Wrong index #" + to_string(id);
    }

    return _myArr[index];
}


math::Vector &math::Vector::operator=(const math::Basic &b) {
    if (getRank(b) > 1) {
        throw "Error, this is not vector " + to_string(id);
    }

    Basic::operator=(b);
    return *this;
}

math::Vector &math::Vector::operator=(math::Basic &&b) {
    if(getRank(b) > 1) {
        throw "Error, this is not vector " + to_string(id);
    }

    Basic::operator=(move(b));
    return *this;
}

math::Vector &math::Vector::operator=(const math::Vector &v) {
    Basic::operator=(v);
    return *this;
}

math::Vector &math::Vector::operator=(math::Vector &&v) noexcept {
    Basic::operator=(move(v));
    return *this;
}


math::Vector &math::Vector::operator*=(const math::Vector &v) {
    if (_col == 1 && v._row == 1)
        throw "Error, transform vector into matrix" + to_string(id);
    else
        Basic::operator *= (v);

    return *this;
}

math::Vector &math::Vector::operator*=(const math::Basic &b) {
    if (getRank(b) > 1)
        throw "Error, transform vector into matrix" + to_string(id);
    else
        Vector::operator *= (Vector(b));
        //Basic::operator *= (b);

    return *this;
}

math::Vector &math::Vector::Transposition() {
    swap(_row, _col);
    return *this;
}

math::Matrix::Index::Index(Matrix *arr, int index) {
    _arr = arr;
    _index = index;
}

math::Matrix::Index::Index(const Matrix *arr, const int index) {
    _brr = arr;
    _index = index;
}

math::Matrix::Index math::Matrix::operator[](int index) {
    if (index < 0 || index >= _row) {
        throw "Index incorrect in object #" + to_string(id);
    }
    return Index(this, index);
}

const math::Matrix::Index math::Matrix::operator[](int index) const {
    if (index < 0 || index >= _row) {
        throw "Index incorrect in object #" + to_string(id);
    }
    return Index(this, index);
}

math::Matrix::Matrix() : Basic() {
}

math::Matrix::Matrix(int param, const double *data) : Basic(param, param, data){
}

math::Matrix::Matrix(int row, int col, const double *data) : Basic(row, col, data){
}

math::Matrix::Matrix(const math::Matrix &m) : Basic(m) {
}

math::Matrix::Matrix(math::Matrix &&m) noexcept: Basic(move(m)) {
}

math::Matrix::Matrix(const math::Basic &b) {
    if (getRank(b) > 2) {
        throw "Error, this is not matrix" + to_string(id);
    }

    Basic::operator = (b);
}

math::Matrix::Matrix(math::Basic &&b) noexcept {
    if (getRank(b) > 2) {
        throw "Error, this is not matrix" + to_string(id);
    }

    Basic::operator = (move(b));
}


int math::Matrix::getRow() const {
    return _row;
}

int math::Matrix::getCol() const {
    return _col;
}

math::Matrix &math::Matrix::operator=(const math::Matrix &m) {
    Basic::operator=(move(m));
    return *this;
}

math::Matrix &math::Matrix::operator=(const math::Basic &b) {
    Basic::operator=(b);
    return *this;
}

math::Matrix &math::Matrix::operator=(math::Matrix &&m) noexcept {
    Basic::operator = (move(m));
    return *this;
}

math::Matrix &math::Matrix::operator=(math::Basic &&b) {
    if (getRank(b) > 2) {
        throw "Error, this is not matrix" + to_string(id);
    }

    Basic::operator = (move(b));
    return *this;
}

double & math::Matrix::Index::operator[](int j) {
    if (j < 0 || j >= _arr->_col) {
        throw "Index incorrect in matrix #" + to_string(_arr->id);
    }

    return _arr->_myArr[_index * _arr->_col + j];
}

double & math::Matrix::Index::operator[](int j) const {
    if (j < 0 || j >= _arr->_col) {
        throw "Index incorrect in matrix #" + to_string(_arr->id);
    }

    return _arr->_myArr[_index * _arr->_col + j];
}

double math::Basic::FindMax() const {
    if (_col == 0 || _row == 0) {
        throw "Object #" + to_string(id) + " is empty";
    }

    double max = _myArr[0];

    for (int i = 0; i < getSize(); i++) {
        if (_myArr[i] > max) {
            max = _myArr[i];
        }
    }

    return max;
}

double math::Basic::FindMin() const {
    if (_col == 0 || _row == 0) {
        throw "Object #" + to_string(id) + " is empty";
    }

    double min = _myArr[0];

    for (int i = 0; i < getSize(); i++) {
        if (_myArr[i] < min) {
            min = _myArr[i];
        }
    }

    return min;
}

int math::Basic::getSize() const {
    return _row * _col;
}

math::Basic &math::Basic::operator*=(double scalar) {
    for (int i = 0; i < getSize(); i++) {
        _myArr[i] *= scalar;
    }

    return *this;
}

bool math::Basic::CheckAdd(const math::Basic &basic) const {
    return _col == basic._col && _row == basic._row;
}

bool math::Basic::CheckMul(const math::Basic &basic) const {
    return _col == basic._row;
}

math::Basic &math::Basic::operator*=(const math::Basic &basic) {
    if (CheckMul(basic)) {
        Matrix temp(_row, basic._col);
        for (int i = 0; i < temp._row; i++) {
            for (int j = 0; j < basic._col; j++) {
                for (int k = 0; k < basic._row; k++) {
                    temp._myArr[i * temp._col + j] += _myArr[i * _col + k] * basic._myArr[k * basic._col + j];
                }
            }
        }

        // std::move return from lvalue rvalue -> operator = (Matrix &&);
        return *this = std::move(temp);

    } else
        throw "Mul is impossible, because cols of #" + to_string(id) +
              " not equals rows of #" + to_string(basic.id);
}

math::Basic &math::Basic::operator=(const math::Basic &basic) {
    if (getSize() != basic.getSize()) {
        if (_myArr != nullptr)
            delete[] _myArr;
        if (basic._col != 0 && basic._row != 0)
            _myArr = new double[basic._col * basic._row];
        else
            _myArr= nullptr;
    }
    _col = basic._col;
    _row = basic._row;
    for (int i = 0; i < getSize(); i++) {
        _myArr[i] = basic._myArr[i];
    }
    return *this;
}

math::Basic &math::Basic::operator=(math::Basic &&basic) noexcept {
    swap(_col, basic._col);
    swap(_row, basic._row);
    swap(_myArr, basic._myArr);
    return *this;
}

math::Basic &math::Basic::operator+=(const math::Basic &basic) {
    if (CheckAdd(basic)) {
        for (int i = 0; i < getSize(); i++) {
            _myArr[i] += basic._myArr[i];
        }
        return *this;
    } else
        throw "Add/Sub is impossible, because count of cols and rows#" + to_string(id) +
              " and#" + to_string(basic.id) + " not equals";
}

math::Basic &math::Basic::operator-=(const math::Basic &basic) {
    if (CheckAdd(basic)) {
        for (int i = 0; i < getSize(); i++) {
            _myArr[i] -= basic._myArr[i];
        }
        return *this;
    } else
        throw "Add/Sub is impossible, because count of cols and rows #" + to_string(id) +
              " and #" + to_string(basic.id) + " not equals";
}

std::ostream &math::operator<<(std::ostream &output, const math::Basic &basic) {
    streamsize width = output.width();

    for (int i = 0; i < basic._row; i++) {
        for (int j = 0; j < basic._col; j++) {
            output.width(width);
            output << basic._myArr[i * basic._col + j];
            if (!width)
                output << "\t";
        }
        output << endl;
    }
    output << endl;

    return output;
}

math::Basic math::operator+(const math::Basic &b1, const math::Basic &b2) {
    return Basic(b1) += b2;
}

math::Basic math::operator-(const math::Basic &b1, const math::Basic &b2) {
    return Basic(b1) -= b2;
}

math::Basic math::operator*(const math::Basic &b1, const math::Basic &b2) {
    return Basic(b1) *= b2;
}

math::Basic math::operator*(const Basic &b, double k) {
    return Basic(b) *= k;
}

math::Basic math::operator*(double k, const Basic &b) {
    return operator*(b, k);
}

// 2 - matrix
// 1 - vector
int math::Basic::getRank(const math::Basic &b) const {
    return b._col > 1 && b._row > 1 ? 2 : (b._col > 0 && b._row > 0 ? 1 : 0);
}

int math::Basic::getCount() {
    return count;
}
