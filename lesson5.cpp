// Домашнее задание Беспальчука Дениса
#include <iostream>
#include <locale>
#include <string>
#include <cassert>
#include <vector>
#include <iterator>

using namespace std;

void task1();
void task2();
void task3();
void task4();
void menu();

/*
Задание 1.
Реализовать шаблон класса Pair1 , который позволяет пользователю передавать данные
одного типа парами.
Следующий код:
int main()
{
	Pair1< int > p1(6, 9);
	cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n' ;
	const Pair1< double > p2(3.4, 7.8);
	cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n' ;
	return 0;
}
… должен производить результат:
Pair: 6 9
Pair: 3.4 7.8
*/

template <class T>
class Pair1
{
private:
	T m_first;
	T m_second;
public:
	Pair1(T first, T second)
	{
		m_first = first;
		m_second = second;
	}
	~Pair1()
	{	}

	T first () const
	{
		return m_first;
	}
	T second() const
	{
		return m_second;
	}
};

void task1()
{
	cout << "Задание 1\n";

	Pair1<int> p1(6, 9);
	cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2(3.4, 7.8);
	cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	cout << endl;
}

/*
Задание 2.
Реализовать класс Pair, который позволяет использовать разные типы данных в
передаваемых парах.
Следующий код:
int main()
{
	Pair< int , double > p1(6, 7.8);
	cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n' ;
	const Pair< double , int > p2(3.4, 5);
	cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n' ;
	return 0;
}
… должен производить следующий результат:
Pair: 6 7.8
Pair: 3.4 5
Подсказка: чтобы определить шаблон с использованием двух разных типов, просто
разделите параметры типа шаблона запятой.
*/

template <class T1, class T2>
class Pair
{
private:
	T1 m_first;
	T2 m_second;
public:
	Pair(T1 first, T2 second)
	{
		m_first = first;
		m_second = second;
	}
	~Pair()
	{	}

	T1 first() const
	{
		return m_first;
	}
	T2 second() const
	{
		return m_second;
	}
};

void task2()
{
	cout << "Задание 2\n";

	Pair< int, double > p1(6, 7.8);
	cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
	const Pair< double, int > p2(3.4, 5);
	cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	cout << endl;
}

/*
Задание 3.
Написать шаблон класса StringValuePair , в котором первое значение всегда типа string, а
второе — любого типа. Этот шаблон класса должен наследовать частично
специализированный класс Pair, в котором первый параметр — string , а второй — любого
типа данных.
Следующий код:
int main()
{
	StringValuePair< int > svp( "Amazing" , 7);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n' ;
	return 0;
}
… должен производить следующий результат:
Pair: Amazing 7
Подсказка: при вызове конструктора класса Pair из конструктора класса StringValuePair не
забудьте указать, что параметры относятся к классу Pair .
*/

template <class T3, class T4>
class Pair3
{
private:
	T3 m_str;
	T4 m_value3;
public:
	Pair3(const T3& str, const T4& val3) : m_str(str), m_value3(val3) { }
	
	T3& first3() 
	{
		return m_str;
	}
	const T3& first3() const
	{
		return m_str;
	}

	T4& second3()
	{
		return m_value3;
	}
	const T4& second3() const
	{
		return m_value3;
	}
};

template <class T5>
class StringValuePair : public Pair3<string, T5>
{
public:
	StringValuePair(const string& s3, const T5& v3) : Pair3<string, T5>(s3, v3) {	}
};

void task3()
{
	cout << "Задание 3\n";

	StringValuePair< int > svp("Amazing", 7);
	cout << "Pair: " << svp.first3() << ' ' << svp.second3() << '\n';

	cout << endl;
}

/*
Задание 4.
Согласно иерархии классов, которая представлена в методичке к уроку 3, от класса Hand
наследует класс GenericPlayer, который обобщенно представляет игрока, ведь у нас будет
два типа игроков - человек и компьютер. Создать класс GenericPlayer, в который добавить
поле name - имя игрока. Также добавить 3 метода:
● IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку
еще одна карта.
● IsBoosted() - возвращает bool значение, есть ли у игрока перебор
● Bust() - выводит на экран имя игрока и объявляет, что у него перебор.
*/

class Card
{
public:
	enum rank { // значения карт
		ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
	};
	enum suit { // масть
		PEAKS, // пики
		WORMS, // черви
		BAPTIZE, // крести
		DIAMONDS, // буби 
	};
	Card(rank r = ACE, suit s = PEAKS, bool ifu = true);
	
	int GetValue() const
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
	void Flip()
	{
		m_IsFaceUp = !(m_IsFaceUp);
	}
	friend ostream& operator<<(ostream& os, const Card& aCard);
private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
};
Card::Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{}

ostream& operator<<(ostream& os, const Card& aCard)
{
	const string RANKS[] = { "0" , "A" , "2" , "3" , "4" , "5" , "6" , "7" , "8" , "9" , "10" , "J" , "Q" , "K" };
	const string SUITS[] = { "p" , "w" , "b" , "d" };
	if (aCard.m_IsFaceUp)
	{
		os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
	}
	else
	{
		os << "XX";
	}
	return os;
}

class Hand
{
public:
	Hand();
	virtual ~Hand();
	void Add(Card* pCard)
	{
		m_Cards.push_back(pCard);
	}
	void Clear()
	{
		vector<Card*>::iterator iter = m_Cards.begin();
		for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
		{
			delete* iter;
			*iter = 0;
		}

		m_Cards.clear();
	}
	int GetTotal() const
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

class GenericPlayer : public Hand
{
	friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);
public:
	GenericPlayer(const string& name = "");
	virtual ~GenericPlayer();

	virtual bool IsHitting() const = 0;

	bool IsBusted() const
	{
		return (GetTotal() > 21);
	}

	void Bust() const
	{
		cout << m_Name << " перебор!\n";
	}
protected:
	string m_Name;
};

GenericPlayer::GenericPlayer(const string& name) : m_Name(name) { }
GenericPlayer::~GenericPlayer() { }

ostream& operator <<(ostream& os, const GenericPlayer& aGenericPlayer)
{
	os << aGenericPlayer.m_Name << ":\t";
	vector<Card*>::const_iterator pCard;
	if (!aGenericPlayer.m_Cards.empty())
	{
		for (pCard = aGenericPlayer.m_Cards.begin();
			pCard != aGenericPlayer.m_Cards.end();
			++pCard)
		{
			os << *(*pCard) << "\t";
		}
		if (aGenericPlayer.GetTotal() != 0)
		{
			cout << "(" << aGenericPlayer.GetTotal() << ")";
		}
	}
	else
	{
		os << "<пусто>";
	}
	return os;
}

void task4()
{
	cout << "Задание 4\n" << endl;;

	cout << "См. код " << endl;;

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