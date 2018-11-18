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
		/* Инкапсуляция. Гетеры и сетеры (чтение и запись) */
		
		double &X() {
			return this->_x;
		}
		
		
		double X() const {
			return this->_x;
		}
		

		// Чтение значения х
		double GetX() const;

		// Запись в значение х
		void SetX(double);

		// Чтение значения y
		double GetY() const;

		// Запись в значение y
		void SetY(double);

		// Чтение значения z
		double GetZ() const;

		// Запись в значение z
		void SetZ(double);

		// Чтение значения id
		int GetID() const;

		// Печать
		void Print() const;

		// Нормирование вектора
		Vector &Normalized();

		// Вычисление модуля вектора
		double Module() const;

		// Произведение скаляра на вектор
		Vector &MulpitlicationOnScalar(double);

		// Копирование значений вектора, который возвращает вектор
		Vector &Create_Copy(const Vector &);

		// конструктор для инициализации векторов нулевыми компонентами
		Vector();

		// конструктор копирования
		Vector(const Vector &obj);

		// неконвертирующийся конструктор для инициализации векторов заданным набором компонентов.
		Vector(double, double, double);

		// Сложение с получением нового вектора С
		friend Vector Addition(const Vector &, const Vector &);

		// Вычитание с получением нового вектора С
		friend Vector Substraction(const Vector &, const Vector &);

		// Векторное произведение с получением нового вектора С
		friend Vector Multiplication(const Vector &, const Vector &);

		// Скалярное произведение 
		friend double ScalarMultiplication(const Vector &, const Vector &);

		// Косинус угла между векторами
		friend double ValueCosBetween(const Vector &, const Vector &);

		// Синус угла между векторами 
		friend double ValueSinBetween(const Vector &, const Vector &);

		// Угол между векторами в пределах
		friend double AngleBetween(const Vector &, const Vector &);

		// Деструктор класса
		~Vector();
	};
};