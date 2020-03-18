#include <iostream>
#include <cmath>
#include <cstdint>
#include <stack>
#include <cassert>

using namespace std;

/*
Задание 1.
Создать класс Power, который содержит два вещественных числа. Этот класс должен иметь
две переменные-члена для хранения этих вещественных чисел. Еще создать два метода:
один с именем set, который позволит присваивать значения переменным, второй — calculate,
который будет выводить результат возведения первого числа в степень второго числа. Задать
значения этих двух чисел по умолчанию.
*/
class Power{
public:
	int first;
	int second;
	void setvalue() {
		first = 2;
		second = 5;
	}

	void calculate() {
		cout << "Первое число = " << first << endl;
		cout << "Второе число = " << second << endl;
		cout << "Первое число возведенное в степень второго числа = " << pow(first, second) << endl;
	}
};


/*
Задание 2.
Написать класс с именем RGBA, который содержит 4 переменные-члена типа std::uint8_t:
m_red, m_green, m_blue и m_alpha ( #include cstdint для доступа к этому типу). Задать 0 в
качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha. Создать
конструктор со списком инициализации членов, который позволит пользователю передавать
значения для m_red , m_blue , m_green и m_alpha . Написать функцию print() , которая будет
выводить значения переменных-членов.
*/
class RGBA {

public:
	int m_red = 0, m_green = 0, m_blue = 0, m_alpha = 255;

	RGBA() {
		std::uint8_t m_red = 0, m_green = 0, m_blue = 0, m_alpha = 255;
		cout << "\nПри std::uint8_t \nПеременная m_red = " << m_red << "\nПеременная m_green = " << m_green << "\nПеременная m_blue = " << m_blue << "\nПеременная m_alpha = " << m_alpha << endl;
	}

	void print()
	{
		cout << "\nЗначение m_red = " << m_red << "\nЗначение m_green = " << m_green << "\nЗначение m_blue = " << m_blue << "\nЗначение m_alpha = " << m_alpha << endl;
	}

	void setRGBA() {
		cout << "Введите значение для m_red = ";
		cin >> m_red;
		cout << "";

		cout << "Введите значение для m_green = ";
		cin >> m_green;
		cout << "";

		cout << "Введите значение для m_blue = ";
		cin >> m_blue;
		cout << "";

		cout << "Введите значение для m_alpha = ";
		cin >> m_alpha;
		cout << "";
	}

	int getRGBA() {
		return m_red, m_green, m_blue, m_alpha;
	}
};

/*
Задание 3.
Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
● private-массив целых чисел длиной 10;
● private целочисленное значение для отслеживания длины стека;
● public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
● public-метод с именем push(), который будет добавлять значение в стек. push()
должен возвращать значение false, если массив уже заполнен, и true в противном случае;
● public-метод с именем pop() для вытягивания и возврата значения из стека. Если в
стеке нет значений, то должно выводиться предупреждение;
● public-метод с именем print() , который будет выводить все значения стека.
*/

class Stack
{
private:
	int m_array[10];
	int m_next;

public:

	void reset()
	{
		m_next = 0;
		for (int i = 0; i < 10; ++i)
			m_array[i] = 0;
	}

	bool push(int value)
	{
	
		if (m_next == 10)
			return false;

		m_array[m_next++] = value; 
		return true;
	}

	int pop()
	{
		assert(m_next > 0);
		return m_array[--m_next];
	}

	void print()
	{
		cout << "( ";
		for (int i = 0; i < m_next; ++i)
			cout << m_array[i] << ' ';
		cout << ")\n";
	}
};
int main() {

	setlocale(LC_ALL, "Russian");
	cout << "Задание 1\n";
	Power calculate;
	calculate.setvalue();
	calculate.calculate();
	cout << "\n";

	cout << "Задание 2\n";
	RGBA one;
	one.setRGBA();
	one.getRGBA();
	one.print();
	cout << "\n";

	cout << "Задание 3\n";
	Stack stack;
	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();

	return 0;
}