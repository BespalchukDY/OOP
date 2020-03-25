// Домашнее задание Беспальчука Дениса
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <cassert>a

using namespace std;

/*
Задание 1.
Создать класс Person (человек) с полями: имя, возраст, пол и вес. Определить методы переназначения имени, изменения возраста и веса. 
Создать производный класс Student (студент), имеющий поле года обучения. Определить методы переназначения и увеличения этого значения. 
Создать счетчик количества созданных студентов. В функции main() создать несколько студентов. 
По запросу вывести определенного человека.
*/
class Person {
private:
	string m_name;
	int m_age;
	string m_gender;
	double m_weight;
public:
	Person()
	{
		m_name = "Имя";
		m_gender = "Мужской/Женский";
		m_age = 18;
		m_weight = 60;
	}
	
	Person(string name, string gender, int age, double weight)
	{
		m_name = name;
		m_gender = gender;
		m_age = age;
		m_weight = weight;
	}
	
	void setName(string name) {
		m_name = name;
	}

	string getName() const{
		return m_name;
	}

	void setGender(string gender) {
		m_gender = gender;
	}

	string getGender() const{
		return m_gender;
	}
	
	void setAge(int age) {
		m_age = age;
	}

	int getAge() const{
		return m_age;
	}

	void setWeight(double weight) {
		m_weight = weight;
	}	

	double getWeight() const{
		return m_weight;
	}

};


class Student : public Person
{
private:
	int m_year;
	static int count;
public:
	Student()
	{
		m_year = 1;
		count++;
	}

	Student(string name, string gender, int age, double weight, int year) : Person(name, gender, age, weight), m_year(year)
	{
		count++;
	}
	void setYear(int year) 
	{
		m_year = year;
	}
	int getYear() const {
		return m_year;
	}

	void printStudent() const
	{
		cout << "\nИмя студента: " << getName() << "\nПол: " << getGender() << "\nВозраст: " << getAge() << "\nВес: " << getWeight() << "\nГод обучения: " << getYear() << '\n' << endl;
		cout << "Количество студентов: ";
		cout << count << endl << endl;
	}

};

int Student::count = 0;

/*
Задание 2.
Создать базовый класс, который способен генерировать целые случайные числа. Используя приватное наследование, создать два класса:
- первый класс должен генерировать случайные дробные числа в диапазоне от 0 до 1.
- второй класс должен генерировать слачайные символы от A до Z и от a до z.
Для каждого класса создать соответствующие public методы, которые используют метод базового класса, генерирующий случайные числа.

*/

class Random {
public:
	unsigned seed = 0;
	Random() {  }
	void initGenerator(Random& generator)
	{
		generator.seed = (unsigned(time(nullptr)));
	}
	
	unsigned random(Random& generator, double low, double high)
	{
		assert(low < high);
		return ((((generator.seed / (high + 1 - low)) + low)* 10000) / 10000.0);
	}
};

class NRandom : private Random {

public:
	NRandom(Random& generator, double low, double high) {}
	

};



/*
Задание 3.
Изучить правила игры в Blackjack. Подумать, как написать данную игру на С++, используя
объектно-ориентированное программирование. Сколько будет классов в программе? Какие
классы будут базовыми, а какие производными? Продумать реализацию игры с помощью
классов и записать результаты.
*/



int main() {

	setlocale(LC_ALL, "Russian");

	cout << "Задание 1\n";

	Student lavr;
	lavr.setName("Лаврентий");
	lavr.setGender("Мужской");
	lavr.setAge(21);
	lavr.setWeight(73);
	lavr.setYear(1);

	Student elena;
	elena.setName("Елена");
	elena.setGender("Женский");
	elena.setAge(19);
	elena.setWeight(51.5);
	elena.setYear(2);

	Student anton;
	anton.setName("Антон");
	anton.setGender("Мужской");
	anton.setAge(29);
	anton.setWeight(120);
	anton.setYear(5);

	lavr.printStudent();

	cout << "Задание 2\n";

	Random generator;
	generator.initGenerator(generator);
	cout << generator.random(generator, 0, 1) << endl;


	cout << "Задание 3\n";


	return 0;
}