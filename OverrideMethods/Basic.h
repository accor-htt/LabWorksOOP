#ifndef OVERRIDEMETHODS_BASIC_H
#define OVERRIDEMETHODS_BASIC_H

#include <iostream>

namespace math {

    class Basic {
    protected:

        double *_myArr;
        static int count;
        int id;

        int _row;
        int _col;

        Basic();

        explicit Basic(int, const double* = nullptr);

        Basic(int, int, const double* = nullptr);

        Basic(const Basic &);

        Basic(Basic&&) noexcept;

        // true - Matrix
        // false - Vector
        virtual int getRank(const Basic &) const;

        // Инициализация
        void Init(int, int, const double *data = nullptr);

    public:

        virtual ~Basic();

        // Функция получения размера
        int getSize() const;

        // Функция получения количества
        static int getCount();

        // Функция проверки возможности сложения (Если возможно - true, нет - false)
        bool CheckAdd(const Basic&) const;

        // Функция проверки возможности умножения (Если возможно - true, нет - false)
        bool CheckMul(const Basic&) const;

        Basic &operator = (const Basic &);
        Basic &operator = (Basic &&) noexcept;
        Basic &operator += (const Basic &);
        Basic &operator -= (const Basic &);
        Basic &operator *= (const Basic &);
        Basic &operator *= (double);

        // Функция нахождения максимального элемента матрицы
        double FindMax() const;

        // Функция нахождения минимального элемента матрицы
        double FindMin() const;

        friend Basic operator + (const Basic &, const Basic&);
        friend Basic operator - (const Basic &, const Basic&);
        friend Basic operator * (const Basic &, double);
        friend Basic operator * (double, const Basic &);
        friend Basic operator * (const Basic &, const Basic&);

        friend std::ostream& operator << (std::ostream &, const Basic &);
    };


    class Vector : public Basic {

    public:

        Vector();

        explicit Vector(int, const double* = nullptr);

        Vector(const Vector &);
        Vector(const Basic &);

        Vector(Vector &&) noexcept;
        Vector(Basic &&) noexcept;

        Vector & Transposition();

        double & operator [] (int);
        const double & operator[](int) const;

        Vector &operator=(const Vector&);
        Vector &operator=(Vector &&) noexcept;

        Vector &operator=(const Basic&);
        Vector &operator=(Basic&&);

        Vector &operator *=(const Vector&);
        Vector &operator *=(const Basic&);
    };

    class Matrix : public Basic {
    private:
        class Index {
        private:
            Matrix * _arr;
            const Matrix *_brr;
            int _index;
        public:
            Index(Matrix *, int);
            Index(const Matrix *, int);
            double & operator [] (int);
            double & operator[](int) const;
        };
    public:

        // Функция для доступа к элементам матрицы по индексу строки и столбца(чтение / запись)
        // Переопределение оператора[];
        Index operator[](int);
        const Index operator[](int) const;

        // Конструктор по умолчанию
        Matrix();

        // Конструктор для инициализации квадратной матрицы заданного размера с заданными компонентами
        explicit Matrix(int, const double* = nullptr);

        // Конструктор для инициализации прямоугольной матрицы заданных размеров с заданными компонентами
        Matrix(int, int, const double* = nullptr);

        // Конструктор копирования
        Matrix(const Matrix &);
        Matrix(const Basic &);

        // Конструктор перемещения
        Matrix(Matrix&&) noexcept;
        Matrix(Basic&&) noexcept;

        // Функция получения значения строк
        int getRow() const;

        // Функция получения значения столбцов
        int getCol() const;

        Matrix &operator=(const Matrix &);
        Matrix &operator=(Matrix &&) noexcept;
        Matrix &operator=(const Basic &);
        Matrix &operator=(Basic &&);
    };
}

#endif //OVERRIDEMETHODS_BASIC_H
