// Домашнее задание Беспальчука Дениса
#include <iostream>
#include <locale>
#include <string>
#include <cassert>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

void task1();
void task2();
void task3();
void task4();
void task5();
void menu();

/*
Задание 1.
Создать программу, которая считывает целое число типа int. И поставить «защиту от дурака»:
если пользователь вводит что-то кроме одного целочисленного значения, нужно вывести
сообщение об ошибке и предложить ввести число еще раз. Пример неправильных введенных
строк:
rbtrb
nj34njkn
1n
*/

void task1()
{
	cout << "Задание 1\n";

	int n;
	string str;
	while (1)
	{
		cout << "Введите целое число типа int: ";

		cin >> str;
		bool f = true;
		for (unsigned int i = 0; i < str.length(); i++)
			if (!isdigit(str[i]))
			{
				f = false;
				break;
			}
		if (!f)
			continue;

		stringstream strStream;
		strStream << str;
		strStream >> n;
		break;
	}

	cout << "Вы ввели число: " << n << endl;

	cout << endl;
}

/*
Задание 2.
Создать собственный манипулятор endll для стандартного потока вывода, который выводит
два перевода строки и сбрасывает буфер.
*/

template <class _Elem, class _Traits>
basic_ostream<_Elem, _Traits>& __CLRCALL_OR_CDECL endll(
	basic_ostream<_Elem, _Traits>& _Ostr) { 
	_Ostr.put(_Ostr.widen('\n'));
	_Ostr.put(_Ostr.widen('\n'));
	_Ostr.flush();
	return _Ostr;
}

void task2()
{
	cout << "Задание 2\n";

	cout << "Посмотрим работу манипулятора endll" << endll;
	cout << "Сработало!" << endl;

	cout << endl;
}

/*
Задание 3.
Реализовать класс Player, который наследует от класса GenericPlayer. У этого класса будет 4
метода:
● virtual bool IsHitting() const - реализация чисто виртуальной функции базового
класса. Метод спрашивает у пользователя, нужна ли ему еще одна карта и
возвращает ответ пользователя в виде true или false .
● void Win() const - выводит на экран имя игрока и сообщение, что он выиграл.
● void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
● void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.
*/

/*
Задание 4.
Реализовать класс House, который представляет дилера. Этот класс наследует от класса
GenericPlayer . У него есть 2 метода:
● virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна карта. Если
у дилера не больше 16 очков, то он берет еще одну карту.
● void FlipFirstCard() - метод переворачивает первую карту дилера.
*/

/*
Задание 5.
Написать перегрузку оператора вывода для класса Card. Если карта перевернута рубашкой
вверх (мы ее не видим), вывести ХХ, если мы ее видим, вывести масть и номинал карты.
Также для класса GenericPlayer написать перегрузку оператора вывода, который должен
отображать имя игрока и его карты, а также общую сумму очков его карт.
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

class Player : public GenericPlayer
{
public:
	Player(const string& name = "");

	virtual ~Player();

	virtual bool IsHitting() const {
		cout << m_Name << ", вы хотите взять еще карту? (Y/N): ";
		char response;
		cin >> response;
		return (response == 'y' || response == 'Y' || response == 'д' || response == 'Д');
	}

	void Win() const {
		cout << m_Name << " выиграл!. Поздравляем!\n";
	}

	void Lose() const {
		cout << m_Name << " проиграл!(((\n";
	}

	void Push() const {
		cout << m_Name << " ничья. Повезет в следующий раз!\n";
	}
};

class House : public GenericPlayer
{
public:
	House(const string& name = "Компьютер - дилер");
	virtual ~House();

	virtual bool IsHitting() const {
		return (GetTotal() <= 16);
	}

	void FlipFirstCard() {
		if (!(m_Cards.empty()))
		{
			m_Cards[0]->Flip();
		}
		else
		{
			cout << "Нет карты для переворачивания!\n";
		}
	}
};

void task3()
{
	cout << "Задания 3, 4, 5\n";

	cout << "См. код " << endl;;

	cout << endl;
}

void task4()
{
	cout << "Задания 3, 4, 5\n" << endl;;

	cout << "См. код " << endl;;

	cout << endl;
}

void task5()
{
	cout << "Задания 3, 4, 5\n" << endl;;

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
		case 5:
			task5();
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
	cout << "3 - Задание 3, 4, 5\n";

	cout << "0 - Exit\n";
}