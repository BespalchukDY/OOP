// Домашнее задание Беспальчука Дениса
#include <iostream>
#include <locale>
#include <cassert>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <set>

using namespace std;

void task1();
void task2();
void task3();
void task4();
void menu();

/*
Задание 1.
Добавить в контейнерный класс, который был написан в этом уроке, методы:
● для добавления нового элемента в произвольное место
● для добавления нового элемента на последнее место
● для удаления последнего элемента массива (аналог функции pop_back() в векторах)
● для сортировки массива.
*/

class ArrayInt
{
private:
	int m_length;
	int *m_data;
public:
	ArrayInt() : m_length(0), m_data(nullptr)
	{ }
	ArrayInt(int length) :
		m_length(length)
	{
		assert(length >= 0);
		if (length > 0)
			m_data = new int[length];
		else
			m_data = nullptr;
	}
	~ArrayInt()
	{
		delete[] m_data;
	}

	void erase()
	{
		delete[] m_data;
		m_data = nullptr;
		m_length = 0;
	}
	int getLength() { return m_length; }

	int& operator [](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

		void resize(int newLength)
	{
		
		if (newLength == m_length)
			return;
		
		if (newLength <= 0)
		{
			erase();
			return;
		}
		
		int* data = new int[newLength];
	
			if (m_length > 0)
			{
				int elementsToCopy = (newLength > m_length) ? m_length : newLength;
				
				for (int index = 0; index < elementsToCopy; ++index)
					data[index] = m_data[index];
			}

		delete[] m_data;
		m_data = data;
		m_length = newLength;
	}

		void insertBefore(int value, int index)
		{
			assert(index >= 0 && index <= m_length);

			int *data = new int[m_length + 1];

			for (int before = 0; before < index; ++before)
				data[before] = m_data[before];
			
			data[index] = value;
			
			for (int after = index; after < m_length; ++after)
				data[after + 1] = m_data[after];
			
			delete[] m_data;
			m_data = data;
			++m_length;
		}

		void remove(int index)
		{
			assert(index >= 0 && index <= m_length);

			if (m_length == 1)
			{
				erase();
				return;
			}

			int* data = new int[m_length];
			
			for (int before = 0; before < index; ++before)
				data[before] = m_data[before];

			for (int after = index + 1; after < m_length; ++after)
				data[after - 1] = m_data[after];

			delete[] m_data;
			m_data = data;
			--m_length;
		}
		int temp;
		void sort()
		{
			for (int i = 0; i < m_length - 1; i++) {
				for (int j = 0; j < m_length - i - 1; j++) {
					if (m_data[j] > m_data[j + 1]) {
						
						temp = m_data[j];
						m_data[j] = m_data[j + 1];
						m_data[j + 1] = temp;
					}
				}
			}
		}

		void push_back(int value) { insertBefore(value, m_length); }
		void push_begin(int value) { insertBefore(value, 0); }
		void remove_back() { remove(m_length); }
};

void task1()
{

	cout << "Задание 1\n";

	ArrayInt array(10);

	for (int i = 0; i < 10; i++)
		array[i] = i + 1;
	cout << "Исходный массив " << endl;
	for (int j = 0; j < array.getLength(); j++)
		cout << array[j] << " "; cout << endl;

	array.insertBefore(15, 4);
	array.remove(5);
	array.push_back(40);
	array.push_begin(50);
	cout << "Добавили 15 перед 4 элементом массива (с значением 5), удалили элемент со значением 5, в конец добавили 40, в начало добавили 50 " << endl;
	for (int j = 0; j < array.getLength(); j++)
		cout << array[j] << " "; cout << endl;

	array.remove_back();
	cout << "Удалили последний элемент, в данном случае со значением 40 " << endl;
	for (int j = 0; j < array.getLength(); j++)
		cout << array[j] << " "; cout << endl;

	array.sort();
	cout << "Отсортировали полученный массив " << endl;
	for (int j = 0; j < array.getLength(); j++)
		cout << array[j] << " "; cout << endl;

	cout << endl;
}

/*
Задание 2.
Дан вектор чисел (числа вводятся с клавиатуры), требуется выяснить, сколько среди них различных. 
Постараться использовать максимально быстрый алгоритм.
*/

void task2()
{
	cout << "Задание 2\n";

	int arraySize = 0;
	cout << "Введите размер массива: ";
	cin >> arraySize;

	vector<int> array(arraySize);
	set<int> arr;
	set<int>::iterator beg = arr.begin();
	set<int>::iterator end = arr.end();

	for (int i = 0; i < array.size(); i++) {
		cout << "Введите элемент массива: ";
		cin >> array[i];
		arr.insert(array[i]);
	}

	cout << "\nВведенный массив: ";
	if (!array.empty())
	{
		copy(array.begin(), array.end(), ostream_iterator<int>(cout, " "));
	}
	cout << "\nКоличество элементов массива: " << array.size() << endl;
	cout << "\nКоличество различных элементов массива: " << arr.size() << endl;
	cout << endl;
}

/*
Задание 3.
Реализовать класс Hand, который представляет собой коллекцию карт. В классе будет одно
поле: вектор указателей карт (удобно использовать вектор, т.к. это по сути динамический
массив, а тип его элементов должен быть - указатель на объекты класса Card). Также в классе
Hand должно быть 3 метода:
● метод Add, который добавляет в коллекцию карт новую карту, соответственно он
принимает в качестве параметра указатель на новую карту
● метод Clear, который очищает руку от карт
● метод GetValue, который возвращает сумму очков карт руки (здесь предусмотреть
возможность того, что туз может быть равен 11).
*/

class Card
{
public:
	enum rank { // значения карт
		ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
		JACK, QUEEN, KING
	};
	enum suit { // масть
		PEAKS, // пики
		WORMS, // черви
		BAPTIZE, // крести
		BUBI, // буби 
	};
	Card(rank r = ACE, suit s = PEAKS, bool ifu = true);
	int GetValue() const;
	void Flip();
private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
};
Card::Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{}
int Card::GetValue() const
{
	int value = 0;
	if (m_IsFaceUp)
	{
		value = m_Rank;
		if (value > 10)
		{
			value = 10;
		}
	}
	return value;
}
void Card::Flip()
{
	m_IsFaceUp = !(m_IsFaceUp);
}

class Hand
{
public:
	Hand();
	virtual ~Hand();
	void Add(Card* pCard);
	void Clear();
	int GetTotal() const;
protected:
	vector<Card*> m_Cards;
};
Hand::Hand()
{
	m_Cards.reserve(7);
}

Hand::~Hand()
{
	Clear();
}
void Hand::Add(Card* pCard)
{
	m_Cards.push_back(pCard);
}
void Hand::Clear()
{
	vector<Card*>::iterator iter = m_Cards.begin();
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		delete* iter;
		*iter = 0;
	}

	m_Cards.clear();
}

int Hand::GetTotal() const
{
	if (m_Cards.empty())
	{
		return 0;
	}

	if (m_Cards[0]->GetValue() == 0)
	{
		return 0;
	}

	int total = 0;
	vector<Card*>::const_iterator iter;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		total += (*iter)->GetValue();
	}

	bool containsAce = false;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		if ((*iter)->GetValue() == Card::ACE)
		{
			containsAce = true;
		}
	}

	if (containsAce && total <= 11)
	{
		total += 10;
	}
	return total;
}

void task3()
{
	cout << "Задание 3\n";


	cout << endl;
}

/*
Задание 4.
*Разработать функцию, принимающую два числа в виде списка (вектора) цифр в одной
системе счисления, и возвращающую число — результат сложения.в виде списка (вектора)
цифр в другой системе счисления.
Входные данные:
<ситема_A>: <цифра_A1>, <цифра_A2>, ... <цифра_AN>
<ситема_B>: <цифра_B1>, <цифра_B2>, ... <цифра_BM>
<ситема_C>
● система A, B — системы счисления входных чисел,
● цифра A1..AN и цифра B1..BN — запись входных чисел в виде набора цифр от
старшего разряда к младшему
● система C — система счисления результата сложения
Пример : сложить FF в 16 системе счисления и HELLO в 36 системе счисления, результат
вывести в двоичной системе счисления
16: 15, 15
36: 17, 14, 21, 21, 24
2
По сути задача сводится к тому, чтобы реализовать функцию:
std::vector<int> plus(const std::vector<int> &A, int baseA,
const std::vector<int> &B, int baseB, int baseResult);
реализующую сложение чисел в различных системах счисления, и возвращающую результат
в требуемой системе счисления.
*/

void task4()
{
	cout << "Задание 4\n";

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

void menu()
{
	cout << "Введите номер задания, которое хотите посмотреть и клавишу Enter\n";
	cout << "1 - Задание 1\n";
	cout << "2 - Задание 2\n";
	cout << "3 - Задание 3\n";
	cout << "4 - Задание 4\n";
	cout << "0 - Exit\n";
}