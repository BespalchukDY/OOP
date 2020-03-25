// �������� ������� ����������� ������
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <conio.h>

using namespace std;

/*
������� 1.
������� ����� Person (�������) � ������: ���, �������, ��� � ���. ���������� ������ �������������� �����, ��������� �������� � ����. 
������� ����������� ����� Student (�������), ������� ���� ���� ��������. ���������� ������ �������������� � ���������� ����� ��������. 
������� ������� ���������� ��������� ���������. � ������� main() ������� ��������� ���������. 
�� ������� ������� ������������� ��������.
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
		m_name = "���";
		m_gender = "�������/�������";
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
	int getYear() {
		return m_year;
	}

	void printStudent()
	{
		cout << "\n��� ��������: " << getName() << "\n���: " << getGender() << "\n�������: " << getAge() << "\n���: " << getWeight() << "\n��� ��������: " << getYear() << '\n' << endl;
		cout << "���������� ���������: ";
		cout << count << endl << endl;
	}

};

int Student::count = 0;

/*
������� 2.
������� ������� �����, ������� �������� ������������ ����� ��������� �����. ��������� ��������� ������������, ������� ��� ������:
- ������ ����� ������ ������������ ��������� ������� ����� � ��������� �� 0 �� 1.
- ������ ����� ������ ������������ ��������� ������� �� A �� Z � �� a �� z.
��� ������� ������ ������� ��������������� public ������, ������� ���������� ����� �������� ������, ������������ ��������� �����.

*/

class Random {
private:
	int low;
	int high;
	int number;
public:
	Random() {}

	Random(int L, int H) : low(L), high(H) { setRandom(); }
	
	void setRandom()
	{
		srand(time(NULL));
		number = (rand() % ((high - low + 1) - low));
	}

	int getNum() {
		return number;
	}

	void printNum() {
		cout << "��������� �����: " << number << endl;
	}
};



/*
������� 3.
������� ������� ���� � Blackjack. ��������, ��� �������� ������ ���� �� �++, ���������
��������-��������������� ����������������. ������� ����� ������� � ���������? �����
������ ����� ��������, � ����� ������������? ��������� ���������� ���� � �������
������� � �������� ����������.
*/



int main() {

	setlocale(LC_ALL, "Russian");

	cout << "������� 1\n";

	Student lavr;
	lavr.setName("���������");
	lavr.setGender("�������");
	lavr.setAge(21);
	lavr.setWeight(73);
	lavr.setYear(1);

	Student elena;
	elena.setName("�����");
	elena.setGender("�������");
	elena.setAge(19);
	elena.setWeight(51.5);
	elena.setYear(2);

	Student anton;
	anton.setName("�����");
	anton.setGender("�������");
	anton.setAge(29);
	anton.setWeight(120);
	anton.setYear(5);

	lavr.printStudent();


	cout << "������� 2\n";

	Random one(0, 10);
	one.printNum();

	cout << "������� 3\n";


	return 0;
}