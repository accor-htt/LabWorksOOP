Шпаргалка по с++

1) explicit - создание явных конструкторов (неконвертирующиеся конструкторы)

class MyClass {
	public:
	MyClass(int j) { i = j; }
}

---
MyClass ob1(1);
MyClass ob2 = 10;

Автоматически конвертируется:
MyClass ob2 = 10 -> MyClass ob2(10);

---

class MyClass {
	public:
	explicit MyClass(int j) { i = j; }
}

Допустимы только : MyClass Ob(5);

2) inline - функции встраиваемые (даем компилятору копировать код функции
непосредственно в код программы по месту вызова, а не создавать функцию в памяти)

inline int sum(int a, int b) {return a+b;}

int main() {
	int a = 2, b = 5, с;
   	c = sum(a, b);     // c = a+b
}

что inline - лишь рекомендация, а не команда компилятору заменять вызов функции ее телом.
Он может подсчитать встраивание нецелесообразным и просто проигнорировать модификатор inline
и трактовать функцию как обычную.

3) & используется для передачи обьекта в функцию не создавая его копии,
то есть работа с сылкой на него и тем самым экономия памяти

4) (&&rvalue) ссылка - обьекты могут быть перемещены
	(&lvalue) (временная) ссылка - всегда копируются

5) . при обращении к элемету через имя обьекта
	-> при обращении через указатель

6) static - статические поля и методы (доступные только в пределах области класса)

7)
const tells the compiler that a variable or method is immutable.
This helps the compiler optimize the code and helps the developer know if a function side effects.
Also, using const & prevents the compiler from copying data unnecessarily.