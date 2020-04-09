// Домашнее задание Беспальчука Дениса

#include <memory>
#include <locale>
#include "card.h"
#include "deck.h"
#include "game.h"
#include "generic_player.h"
#include "hand.h"
#include "house.h"
#include "player.h"

using namespace std;

void task1();
void task2();
void task3();
void menu();

/*
Задание 1.
Создайте класс Date с полями день, месяц, год и методами доступа к этим полям.
Перегрузите оператор вывода для данного класса. Создайте два "умных" указателя today и
date. Первому присвойте значение сегодняшней даты. Для него вызовите по отдельности
методы доступа к полям класса Date, а также выведите на экран данные всего объекта с
помощью перегруженного оператора вывода. Затем переместите ресурс, которым владеет
указатель today в указатель date. Проверьте, являются ли нулевыми указатели today и date и
выведите соответствующую информацию об этом в консоль.
*/

class Date
{
private:
	int m_day, m_month, m_year;
public:
	Date(int day = 0, int month = 0, int year = 0) : m_day(day), m_month(month), m_year(year)
	{ }
	friend ostream& operator<< (ostream& out, const Date& date);
	void setDay(int day) {
		m_day = day;
	}
	void setMonth(int month) {
		m_month = month;
	}
	void setYear(int year) {
		m_year = year;
	}

	int getDay() const { return m_day; }
	int getMonth() const { return m_month; }
	int getYear() const { return m_year; }
};

ostream& operator<< (ostream& out, const Date& date)
{
	out << "Дата: " << date.m_day << "." << date.m_month << "." << date.m_year << "\n";
	return out;
}

void task1()
{
	cout << "Задание 1\n";

	unique_ptr<Date> today = make_unique<Date>(9, 4, 2020);
	cout << "Указатель today: " << today->getDay() << "_" << today->getMonth() << "_" << today->getYear();
	if (today) {
		cout << " не пустой" << endl;
	}
	else {
		cout << " пустой" << endl;
	}
	cout << *today;

	unique_ptr<Date> date(move(today));
	cout << "Указатель date: " << date->getDay() << "_" << date->getMonth() << "_" << date->getYear();
	if (date) {
		cout << " не пустой" << endl;
	}
	else {
		cout << " пустой" << endl;
	}
	cout << *date;

	cout << "Указатель today: ";
	if (today) {
		cout << "не пустой!" << endl;
	}
	else {
		cout << "пустой!" << endl;
	}

	cout << endl;
}

/*
Задание 2.
По условию предыдущей задачи создайте два умных указателя date1 и date2 .
● Создайте функцию, которая принимает в качестве параметра два умных указателя
типа Date и сравнивает их между собой (сравнение происходит по датам). Функция
должна вернуть более позднюю дату.
● Создайте функцию, которая обменивает ресурсами (датами) два умных указателя,
переданных в функцию в качестве параметров.
Примечание: обратите внимание, что первая функция не должна уничтожать объекты,
переданные ей в качестве параметров.
*/

void maxDate(unique_ptr<Date>& date1, unique_ptr<Date>& date2) {
	if (date1.get()->getYear() > date2.get()->getYear()) {
		cout << *date1 << " больше чем " << *date2;
	}
	else if (date1.get()->getYear() < date2.get()->getYear())
	{
		cout << *date2 << " больше чем " << *date1;
	}
	else {
		if (date1.get()->getMonth() > date2.get()->getMonth()) {
			cout << *date1 << " больше чем " << *date2;
		}
		else if (date1.get()->getMonth() < date2.get()->getMonth())
		{
			cout << *date2 << " больше чем " << *date1;
		}
		else {
			if (date1.get()->getDay() > date2.get()->getDay()) {
				cout << *date1 << " больше чем " << *date2;
			}
			else if (date1.get()->getDay() < date2.get()->getDay())
			{
				cout << *date2 << " больше чем " << *date1;
			}
			else {
				cout << *date2 << " равно " << *date1;
			}
		}
	}
}

void swapDate(unique_ptr<Date>& date1, unique_ptr<Date>& date2) {
	unique_ptr<Date> tmp = make_unique<Date>();
	tmp = move(date1);
	date1 = move(date2);
	date2 = move(tmp);
}

void task2()
{
	cout << "Задание 2\n";

	unique_ptr<Date> date1 = make_unique<Date>(9, 4, 2020);
	unique_ptr<Date> date2 = make_unique<Date>(1, 1, 2019);
	maxDate(date1, date2);
	cout << "Были даты: " << endl << *date1 << *date2;
	swapDate(date1, date2);
	cout << "Стали даты: " << endl << *date1 << *date2;

	cout << endl;
}

/*
Задание 3.
Создать класс Deck, который наследует от класса Hand и представляет собой колоду карт.
Класс Deck имеет 4 метода:
● vold Populate() - Создает стандартную колоду из 52 карт, вызывается из конструктора.
● void Shuffle() - Метод, который тасует карты, можно использовать функцию из
алгоритмов STL random_shuffle
● vold Deal (Hand& aHand) - метод, который раздает в руку одну карту
● void AddltionalCards (GenericPlayer& aGenerlcPlayer) - раздает игроку
дополнительные карты до тех пор, пока он может и хочет их получать
Обратите внимание на применение полиморфизма. В каких методах применяется этот
принцип ООП?
*/

/*
Задание 4.
Реализовать класс Game, который представляет собой основной процесс игры. У этого
класса будет 3 поля:
● колода карт
● рука дилера
● вектор игроков.
Конструктор класса принимает в качестве параметра вектор имен игроков и создает объекты
самих игроков. В конструкторе создается колода карт и затем перемешивается.
Также класс имеет один метод play(). В этом методе раздаются каждому игроку по две
стартовые карты, а первая карта дилера прячется. Далее выводится на экран информация о
картах каждого игра, в т.ч. и для дилера. Затем раздаются игрокам дополнительные карты.
Потом показывается первая карта дилера и дилер набирает карты, если ему надо. После
этого выводится сообщение, кто победил, а кто проиграл. В конце руки всех игроков
очищаются.
*/

/*
Задание 5.
Написать функцию main() к игре Блекджек. В этой функции вводятся имена игроков.
Создается объект класса Game и запускается игровой процесс. Предусмотреть возможность
повторной игры.
*/


void task3()
{
	cout << "Задания 3\n" << endl;;

	cout << "\t\tИгра Блэкджек!\n" << endl;

	int numPlayers = 0;

	while (numPlayers < 1 || numPlayers > 7) {
		cout << "Введите количество игроков от 1 до 7: ";
		cin >> numPlayers;
	}

	vector<string> names;
	string name;

	for (int i = 0; i < numPlayers; ++i) {
		cout << "Введите имя игрока: ";
		cin >> name;
		names.push_back(name);
	}

	cout << endl;

	Game aGame(names);
	char again = 'y'; 

	while (again != 'n' && again != 'N') {
		aGame.Play();
		cout << "\nХотите сыграть еще раз? (Y/N): ";
		cin >> again;
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