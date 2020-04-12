// �������� ������� ����������� ������
#include <iostream>
#include <locale>
#include <string>

using namespace std;

void task1();
void task2();
int task3();
void menu();

/*
������� 1.
�������� ������� div, ������� ������ ��������� ��������� ������� ���� ����� ����� �
��������� ���������� DivisionByZero, ���� �������� ����� 0. � ������� main ������ ���
����� ����� � ������� �� �������� �������, ���� �������� �� ����� ����, � ��������� ��
������, ���� �����.
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
	cout << "������� 1\n";

	int d1;
	int d2;
	cout << "������� �������� ���������: ";
	cin >> d1;
	cout << "������� �������� �����������: ";
	cin >> d2;
	try
	{
		cout << division(d1, d2) << endl;
	}
	catch (exception& err)
	{
		cout << "������: " << err.what() << " ������� �� ���� ���������!" << endl;
	}
	cout << endl;
}

/*
������� 2.
�������� ����� Ex, �������� ������������ ����� x � ������� ����������� ��
������������� �����, ���������������� x ��������� ���������. �������� ����� Bar,
�������� ������������ ����� y (����������� �� ��������� �������������� ��� �����) �
������� ����� set � ������������ ������������ ���������� a. ���� y + a > 100,
������������ ���������� ���� Ex � ������� ay, ����� � y ��������� �������� a. � �������
main ������� ���������� ������ Bar � � ����� � ����� try ������� � ���������� ����� n.
������������ ��� � �������� ��������� ������ set �� ��� ���, ���� �� ����� ������� 0. �
����������� ���������� �������� ��������� �� ������, ���������� ������ �������
����������.
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
	cout << "������� 2\n";

	Bar b;
	int n{};

	cout << "������� �����: ";
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
������� 3.
�������� ����� ������, ������������ ����������� ������ �� ����� 10x10, � �������� ����
�����, ���������� ������� ������������� �� �������� �������. ��� ������ ������
��������� ���������� OffTheField, ���� ����� ������ ���� � �����, � IllegalCommand, ����
������ �������� ������� (����������� �� ��������� � ������ ���������). ������
���������� ������ ��������� ��� ����������� ���������� � ������� ������� �
����������� ��������. �������� ������� main, ������������ ���� ������� �
��������������� ��� ���������� �� ��� �������, � ����� ��������� ���������
���������� � ���� ����������� �������.
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
	cout << "������� 3\n";

	robot r;
	r.pos();
	int x = 1, y = 1;
	try {
		while (x != 0 || y != 0) {
			cout << "��������� ����������� �������� ������������ � �������, ��������: 1 1" << endl;
			cout << "� ������ ������� ����������� ��������: " << endl;
			cin >> x >> y;
			r.go(x, y);
			r.pos();
		}
	}
	catch (OffTheField a) {
		cout << "�� ��������� ����� �� ����� ���� �� ������� (" << a.x << ";" << a.y << ")" << endl;
		return EXIT_FAILURE;
	}
	catch (IllegalCommand a) {
		cout << "������� (" << a.x << ";" << a.y << ") �� ���������" << endl;
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
		cout << "������� ����� �������: ";
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
			cout << "����� ��������!\n";
			break;
		default:
			cout << "������ ������������ ����� �������!\n";
		}
	} while (sel != 0);

	return 0;
}

void menu()
{
	cout << "������� ����� �������, ������� ������ ���������� � ������� Enter\n";
	cout << "1 - ������� 1\n";
	cout << "2 - ������� 2\n";
	cout << "3 - ������� 3\n";

	cout << "0 - Exit\n";
}