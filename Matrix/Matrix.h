#pragma once

namespace Math {
	class Matrix {
	private: 

		double *matrix;
		
		// Строки
		int _row;

		// Столбцы
		int _col;

		static int count;
		int id;
		
		class Index {
		private: 
			Matrix * _arr;
			const Matrix * _brr;
			int _index;
		public:
			Index(Matrix *, int);
			Index(const Matrix *, const int);
			double & operator [] (int);
			const double & operator[](const int) const;
		};

	public:

		// Функция для доступа к элементам матрицы по индексу строки и столбца(чтение / запись)
		// Переопределение оператора[];
		Index operator[](int);
		const Index operator[](const int) const;

		// Конструктор по умолчанию
		Matrix();

		// Конструктор для инициализации квадратной матрицы заданного размера с заданными компонентами
		Matrix(int = 0, const double* = nullptr);

		// Конструктор для инициализации прямоугольной матрицы заданных размеров с заданными компонентами
		Matrix(int, int, const double* = nullptr);

		// Конструктор копирования
		Matrix(const Matrix&);

		// Конструктор перемещения
		Matrix(Matrix&&);

		// Деструктор
		~Matrix();

		// Функция получения значения строк
		int getRow() const;

		// Функция получения значения столбцов
		int getCol() const;

		// Функция получения id матрицы
		int getID() const;

		// Функция получения размера для цикла
		int getSize() const;

		// Функция проверки возможности сложения (Если возможно - true, нет - false)
		bool CheckAdd(const Matrix &) const;

		// Функция проверки возможности умножения (Если возможно - true, нет - false)
		bool CheckMul(const Matrix &) const;

		// Функция нахождения максимального элемента матрицы
		double FindMax() const;

		// Функция нахождения минимального элемента матрицы
		double FindMin() const;

		// Математические действия над матрицами A и B без получения новых матриц
		// Функции переопределения операторов =, +=, -=, *=.
		Matrix &operator =  (const Matrix &);
		Matrix &operator += (const Matrix &);
		Matrix &operator -= (const Matrix &);
		Matrix &operator *= (const Matrix &);
		Matrix &operator *= (const double);

		// Двуместные операции над матрицами A и B с получением новой матрицы C
		friend Matrix operator + (const Matrix &, const Matrix&);
		friend Matrix operator - (const Matrix &, const Matrix&);
		friend Matrix operator * (const Matrix &, const double);
		friend Matrix operator * (const Matrix &, const Matrix&);

		// Функция вывода на экран матрицы в построчной форме
		// Переопределение оператора вывода на поток (<<).
		friend ostream & operator << (ostream &output, const Matrix&);
	};
}



