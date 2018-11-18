#pragma once
namespace Math {
	class Vector {
	private:
		double _x;
		double _y;
		double _z;
		int id;
		static int count; 

	public:
		/* ������������. ������ � ������ (������ � ������) */
		
		double &X() {
			return this->_x;
		}
		
		
		double X() const {
			return this->_x;
		}
		

		// ������ �������� �
		double GetX() const;

		// ������ � �������� �
		void SetX(double);

		// ������ �������� y
		double GetY() const;

		// ������ � �������� y
		void SetY(double);

		// ������ �������� z
		double GetZ() const;

		// ������ � �������� z
		void SetZ(double);

		// ������ �������� id
		int GetID() const;

		// ������
		void Print() const;

		// ������������ �������
		Vector &Normalized();

		// ���������� ������ �������
		double Module() const;

		// ������������ ������� �� ������
		Vector &MulpitlicationOnScalar(double);

		// ����������� �������� �������, ������� ���������� ������
		Vector &Create_Copy(const Vector &);

		// ����������� ��� ������������� �������� �������� ������������
		Vector();

		// ����������� �����������
		Vector(const Vector &obj);

		// ������������������ ����������� ��� ������������� �������� �������� ������� �����������.
		Vector(double, double, double);

		// �������� � ���������� ������ ������� �
		friend Vector Addition(const Vector &, const Vector &);

		// ��������� � ���������� ������ ������� �
		friend Vector Substraction(const Vector &, const Vector &);

		// ��������� ������������ � ���������� ������ ������� �
		friend Vector Multiplication(const Vector &, const Vector &);

		// ��������� ������������ 
		friend double ScalarMultiplication(const Vector &, const Vector &);

		// ������� ���� ����� ���������
		friend double ValueCosBetween(const Vector &, const Vector &);

		// ����� ���� ����� ��������� 
		friend double ValueSinBetween(const Vector &, const Vector &);

		// ���� ����� ��������� � ��������
		friend double AngleBetween(const Vector &, const Vector &);

		// ���������� ������
		~Vector();
	};
};