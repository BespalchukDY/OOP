// Домашнее задание Беспальчука Дениса
#include <iostream>
#include <locale>
#include <string>

using namespace std;

void task1();
void task2();
int task3();
void menu();

/*
Задание 1.
Написать функцию div, которая должна вычислять результат деления двух целых чисел и
запускать исключение DivisionByZero, если делитель равен 0. В функции main ввести два
целых числа и вывести их неполное частное, если делитель не равен нулю, и сообщение об
ошибке, если равен.
*/

int division(int d1, int d2)
{
	if (d2 == 0)
	{
		throw exception("DivisionByZero!");
	}
	return d1 / d2;
}

void task1()
{
	cout << "Задание 1\n";

	int d1;
	int d2;
	cout << "Введите значение числителя: ";
	cin >> d1;
	cout << "Введите значение знаменателя: ";
	cin >> d2;
	try
	{
		cout << division(d1, d2) << endl;
	}
	catch (exception& err)
	{
		cout << "Ошибка: " << err.what() << " Деление на ноль запрещено!" << endl;
	}
	cout << endl;
}

/*
Задание 2.
Написать класс Ex, хранящий вещественное число x и имеющий конструктор по
вещественному числу, инициализирующий x значением параметра. Написать класс Bar,
хранящий вещественное число y (конструктор по умолчанию инициализирует его нулем) и
имеющий метод set с единственным вещественным параметром a. Если y + a > 100,
возбуждается исключение типа Ex с данными ay, иначе в y заносится значение a. В функции
main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры целое n.
Использовать его в качестве параметра метода set до тех пор, пока не будет введено 0. В
обработчике исключения выводить сообщение об ошибке, содержащее данные объекта
исключения.
*/

class Ex
{
public:
	double x;
	Ex(const double &x_) : x(x_) {}
	~Ex() {}
};

class Bar
{
private:
	double y;
public:
	Bar() { y = 0; }
	~Bar() {}

	void setX(const double& a)
	{
		if (y + a <= 100)
		{
			y = a;
		}
		else
		{
			throw Ex(y*a);
		}
	}
};

void task2()
{
	cout << "Задание 2\n";

	Bar b;
	int n{};

	cout << "Введите число: ";
	while(cin >> n && n != 0) 
	{
		try
		{
			b.setX(n);
		}
		catch (Ex& err)
		{
			cerr << "Exception: ay " << err.x << endl;
		}
	}

	cout << endl;
}

/*
Задание 3.
Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у которого есть
метод, означающий задание переместиться на соседнюю позицию. Эти методы должны
запускать исключение OffTheField, если робот должен уйти с сетки, и IllegalCommand, если
подана неверная команда (направление не находится в нужном диапазоне). Объект
исключения должен содержать всю необходимую информацию — текущую позицию и
направление движения. Написать функцию main, пользующуюся этим классом и
перехватывающую все исключения от его методов, а также выводящую подробную
информацию о всех возникающих ошибках.
*/

class OffTheField {
public:
	int x, y;
	OffTheField(int a, int b) {
		x = a;
		y = b;
	}
};
class IllegalCommand {
public:
	int x, y;
	IllegalCommand(int a, int b) {
		x = a;
		y = b;
	}
};

class robot {
	int x = 0, y = 0;
public:
	void go(int x0, int y0) {
		if ((x + x0 > 9) || (y + y0 > 9) || (x + x0 < 0) || (y + y0 < 0)) throw OffTheField(x + x0, y + y0);
		if ((abs(x0) > 1) || (abs(y0) > 1)) throw IllegalCommand(x0, y0);
		x += x0;
		y += y0;
	}
	void pos() {
		cout << "(" << x << ";" << y << ")" << endl;
	};
};

int task3()
{
	cout << "Задания 3\n";

	robot r;
	r.pos();
	int x = 1, y = 1;
	try {
		while (x != 0 || y != 0) {
			cout << "Задавайте направление движения размерностью в единицу, например: 1 1" << endl;
			cout << "А теперь задайте направление движения: " << endl;
			cin >> x >> y;
			r.go(x, y);
			r.pos();
		}
	}
	catch (OffTheField a) {
		cout << "Вы пытаетесь выйти за рамки поля на позицию (" << a.x << ";" << a.y << ")" << endl;
		return EXIT_FAILURE;
	}
	catch (IllegalCommand a) {
		cout << "Команда (" << a.x << ";" << a.y << ") не допустима" << endl;
		return EXIT_FAILURE;
	}

	cout << endl;
}

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
		case 0:
			cout << "Всего хорошего!\n";
			break;
		default:
			cout << "Введен некорректный номер задания!\n";
		}
	} while (sel != 0);

	return 0;
}

void menu()
{
	cout << "Введите номер задания, которое хотите посмотреть и клавишу Enter\n";
	cout << "1 - Задание 1\n";
	cout << "2 - Задание 2\n";
	cout << "3 - Задание 3\n";

	cout << "0 - Exit\n";
}