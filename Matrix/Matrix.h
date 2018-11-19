#pragma once

namespace Math {
	class Matrix {
	private: 

		double *matrix;
		
		// ������
		int _row;

		// �������
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

		// ������� ��� ������� � ��������� ������� �� ������� ������ � �������(������ / ������)
		// ��������������� ���������[];
		Index operator[](int);
		const Index operator[](const int) const;

		// ����������� �� ���������
		Matrix();

		// ����������� ��� ������������� ���������� ������� ��������� ������� � ��������� ������������
		Matrix(int = 0, const double* = nullptr);

		// ����������� ��� ������������� ������������� ������� �������� �������� � ��������� ������������
		Matrix(int, int, const double* = nullptr);

		// ����������� �����������
		Matrix(const Matrix&);

		// ����������� �����������
		Matrix(Matrix&&);

		// ����������
		~Matrix();

		// ������� ��������� �������� �����
		int getRow() const;

		// ������� ��������� �������� ��������
		int getCol() const;

		// ������� ��������� id �������
		int getID() const;

		// ������� ��������� ������� ��� �����
		int getSize() const;

		// ������� �������� ����������� �������� (���� �������� - true, ��� - false)
		bool CheckAdd(const Matrix &) const;

		// ������� �������� ����������� ��������� (���� �������� - true, ��� - false)
		bool CheckMul(const Matrix &) const;

		// ������� ���������� ������������� �������� �������
		double FindMax() const;

		// ������� ���������� ������������ �������� �������
		double FindMin() const;

		// �������������� �������� ��� ��������� A � B ��� ��������� ����� ������
		// ������� ��������������� ���������� =, +=, -=, *=.
		Matrix &operator =  (const Matrix &);
		Matrix &operator += (const Matrix &);
		Matrix &operator -= (const Matrix &);
		Matrix &operator *= (const Matrix &);
		Matrix &operator *= (const double);

		// ���������� �������� ��� ��������� A � B � ���������� ����� ������� C
		friend Matrix operator + (const Matrix &, const Matrix&);
		friend Matrix operator - (const Matrix &, const Matrix&);
		friend Matrix operator * (const Matrix &, const double);
		friend Matrix operator * (const Matrix &, const Matrix&);

		// ������� ������ �� ����� ������� � ���������� �����
		// ��������������� ��������� ������ �� ����� (<<).
		friend ostream & operator << (ostream &output, const Matrix&);
	};
}



