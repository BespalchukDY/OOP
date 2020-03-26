// Домашнее задание Беспальчука Дениса
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <conio.h>
#include <locale>

using namespace std;

void task1();
void task2();
void task3();
void task4();
void menu();

/*
Задание 1.
Создать абстрактный класс Figure (фигура). Его наследниками являются классы Parallelogram
(параллелограмм) и Circle (круг). Класс Parallelogram — базовый для классов Rectangle
(прямоугольник), Square (квадрат), Rhombus (ромб). Для всех классов создать конструкторы.
Для класса Figure добавить чисто виртуальную функцию area() (площадь). Во всех остальных
классах переопределить эту функцию, исходя из геометрических формул нахождения
площади.
*/

class Figure
{
public:
	virtual int area() = 0;
};

class Parallelogram : public Figure
{
protected:
	int a;
	int b; 
public:
	Parallelogram(int A) : a(A) { }
	Parallelogram(int A, int B) : a(A), b(B) { }
	int area() override
	{
		cout << "Площадь параллелограмма равна: " << a * b << endl;
		return 0;
	}
};

class Circle : public Figure
{
private:
	int r; 
public:
	Circle(int A) : r(A) { }
	int area()
	{
		cout << "Площадь круга равна: " << 3.14 * r * r << endl;
		return 0;
	}
};

class Rectangle : public Parallelogram
{
public:
	Rectangle(int A, int B) : Parallelogram (A, B) { }
	int area() override
	{
		cout << "Площадь прямоугольника равна: " << a * b << endl;
		return 0;
	}
};

class Square : public Parallelogram
{
public:
	Square(int A) : Parallelogram(A) { }
	int area() override
	{
		cout << "Площадь квадрата равна: " << a * a << endl;
		return 0;
	}
};

class Rhombus : public Parallelogram
{
public:
	Rhombus(int A, int B) : Parallelogram(A, B) { }
	int area() override
	{
		cout << "Площадь ромба равна: " << (a * b) / 2 << endl;
		return 0;
	}
};

/*
Задание 2.
Создать класс Car (автомобиль) с полями company (компания) и model (модель).
Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус). От этих классов
наследует класс Minivan (минивэн). Создать конструкторы для каждого из классов, чтобы они
выводили данные о классах. Создать объекты для каждого из классов и посмотреть, в какой
последовательности выполняются конструкторы. Обратить внимание на проблему «алмаз
смерти».
Примечание: если использовать виртуальный базовый класс, то объект самого "верхнего"
базового класса создает самый "дочерний" класс.
*/

class Car
{

public:
	
	Car(string company, string model) {
		cout << company << endl;
		cout << model << endl;
	}
	
};

class PassengerCar: virtual public Car
{
public:
	PassengerCar(string company, string model, string type) : Car(company, model)
	{
		cout << type << endl;
	}
};

class Bus : virtual public Car
{
public:
	Bus(string company, string model, string type2) : Car(company, model)
	{
		cout << type2 << endl;
	}
};

class Minivan : public PassengerCar, public Bus
{
public:
	Minivan(string company, string model, string type, string type2) : PassengerCar(company, model, type), Bus(company, model, type2), Car(company, model)
	{
		cout << "" << endl;
	}
};

/*
Задание 3.
Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или
9/2). Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:
● математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
● унарный оператор (-)
● логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности,
попробуйте перегрузить один через другой.
Продемонстрировать использование перегруженных операторов.
*/

unsigned nod(unsigned m, unsigned n)
{
	return n ? nod(n, m % n) : m;
}

class Fraction
{
private:
	double numerator;
	double denomimator;
public:
	Fraction(void) 
	{
		numerator = 1;
		denomimator = 1;
	}

	Fraction(double num, double denom) 
	{ 
		if (num != 0)
			numerator = num;
		else
			numerator = 1;
		if (denom != 0)
			denomimator = denom;
		else
			denomimator = 1;
	}

	friend ostream& operator<< (ostream& os, const Fraction& num)
	{
		os << num.numerator << "/" << num.denomimator;
		return os;
	}

	Fraction operator+ (Fraction& num)
	{
		Fraction result;
		if (denomimator == num.denomimator)
		{
			result.denomimator = denomimator;
			result.numerator = numerator + num.numerator;
		}
		else
		{
			result.denomimator = denomimator * num.denomimator;
			result.numerator = (numerator * num.denomimator) + (num.numerator * denomimator);
		}
		return result;
	}

	Fraction operator- (Fraction& num)
	{
		Fraction result;
		if (denomimator == num.denomimator)
		{
			result.denomimator = denomimator;
			result.numerator = numerator - num.numerator;
		}
		else
		{
			result.denomimator = denomimator * num.denomimator;
			result.numerator = (numerator * num.denomimator) - (num.numerator * denomimator);
		}
		return result;
	}

	Fraction operator* (Fraction& num)
	{
		Fraction result;
		result.numerator = numerator * num.numerator;
		result.denomimator = denomimator * num.denomimator;
		return result;
	}

	Fraction operator* (int num)
	{
		Fraction result;
		result.numerator = numerator * num;
		result.denomimator = denomimator;
		return result;
	}

	Fraction operator/ (Fraction& num)
	{
		Fraction result;
		Fraction result1;
		Fraction result2;
		result1 = Fraction(num.denomimator, num.numerator);
		result2 = Fraction(numerator, denomimator);
		result = result1 * result2;
		return result;
	}
	
	~Fraction(void) {}
};

/*
Задание 4.
Создать класс Card, описывающий карту в игре БлэкДжек.У этого класса должно быть три
поля : масть, значение карты и положение карты(вверх лицом или рубашкой).Сделать поля
масть и значение карты типом перечисления(enum).Положение карты - тип bool.Также в
этом классе должно быть два метода :
● метод Flip(), который переворачивает карту, т.е.если она была рубашкой вверх, то он
ее поворачивает лицом вверх, и наоборот.
● метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.
*/

class Card
{
private:
	enum suit // масть
	{
		PEAKS, // пики
		WORMS, // черви
		BAPTIZE, // крести
		BUBI, // буби
	
	}; 
	enum value // значения карт
	{
		TWO = 2, // два
		THREE = 3, // три
		FOUR = 4, // четыре
		FIVE = 5, // пять
		SIX = 6, // шесть
		SEVEN = 7, // семь
		EIGHT = 8, // восемь
		NINE = 9, // девять
		TEN = 10, // десять
		JACK = 10, // валет
		QUEEN = 10, // дама
		KING = 10, // король
		ACE = 1 // туз
	}; 
	bool position = true; // положение Открыта (лицом к игроку) или Закрыта (рубашкой к игроку)
public:
	Card(){}
	bool Flip()
	{
		if (position == false)
		{
			position = true;
			cout << "Карта открыта " << endl;
		}
		else
		{
			cout << "Карта закрыта " << endl;
		}
	}
	int getValue(int enumValue) const
	{
	
		return enumValue;
	}
};



int main() {

	setlocale(LC_ALL, "Russian");
	
	int sel = 0;
	do
	{
		menu();
		cout << "Введите номер задания: ";
		cin >> sel;
		switch (sel)
		{
		case 1:
			task1();
			break;
		case 2:
			task2();
			break;
		case 3:
			task3();
			break;
		case 4:
			task4();
			break;
		case 0:
			cout << "Всего хорошего!\n";
			break;
		default:
			cout << "Введен некорректный номер задания!\n";
		}
	} while (sel != 0);

	return 0;
}

void task1()
{

	cout << "Задание 1\n";

	Parallelogram parallelogram(2, 6);
	parallelogram.area();

	Circle circle(6);
	circle.area();

	Rectangle rectangle(3, 6);
	Square square(5);
	Rhombus rhombus(5, 6);

	Parallelogram* r1 = &rectangle;
	Parallelogram* s1 = &square;
	Parallelogram* r2 = &rhombus;

	r1->area();
	s1->area();
	r2->area();

	cout << endl;
}
void task2()
{
	cout << "Задание 2\n";

	Minivan car("Компания", "Модель", "Легковой автомобиль", "Автобус");


}

void task3()
{
	cout << "Задание 3\n";

	Fraction num(3, 7);
	Fraction denom(9, 2);
	Fraction c = num + denom;

	cout << "Результат сложения дроби " << num << ", с дробью " << denom << " равняется " << c << endl;
	cout << "Результат сложения дроби " << num << ", с дробью " << denom << " равняется " << num + denom << endl;

	cout << "Результат вычитания дроби " << num << ", с дробью " << denom << " равняется " << num - denom << endl;
	cout << "Результат умножения дроби " << num << ", с дробью " << denom << " равняется " << num * denom << endl;
	cout << "Результат деления дроби " << num << ", с дробью " << denom << " равняется " << num / denom << endl;
	cout << "Результат деления дроби " << denom << ", с дробью " << num << " равняется " << denom / num << endl;

	cout << endl;
}

void task4()
{
	cout << "Задание 4\n";

	cout << "См. код";

	cout << endl;
}

void menu()
{
	cout << "Введите номер задания, которое хотите посмотреть и клавишу Enter\n";
	cout << "1 - Задание 1\n";
	cout << "2 - Задание 2\n";
	cout << "3 - Задание 3\n";
	cout << "4 - Задание 4\n";
	cout << "0 - Exit\n";
}