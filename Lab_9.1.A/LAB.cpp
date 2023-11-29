#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // ������������ ����������� ��������
using namespace std;
//enum Kurs {};
enum Spec { KN = 0, IT, PF  };
string SpecStr[] = { "����'����� �����", "����������� �������㳿","���������" };
struct Student
{
	string prizv;
	int kurs;
	Spec spec;
	double physics_mark;
	double math_mark;
	double inf_mark;
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
void Student_Who_have_5(Student* p, const int N);
double LineSearch(Student* p, const int N);

int main()
{ 
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 
	int N;
	cout << "������ ������� �������� N: "; cin >> N;
	Student* p = new Student[N];
	
		double proc;
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - ���� ������  ��������," << endl;
		cout << " �� �������� � ������ ������ 5 " << endl << endl;
		cout << " [4] - ���� ������ � ������� �������� �� ������� �� ������" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			cout << "�������� �� �������� � ������ 5:" << endl;
			Student_Who_have_5(p, N);
			break;
		case 4:
			proc = LineSearch(p, N);
			cout << "������� �������� �� ������� �� ������:" << endl;
			cout << proc << "%" << endl;
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (menuItem != 0);
	return 0;
}
void Create(Student* p, const int N)
{
	int specialnist;
	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;

		cin.get();
		cin.sync();

		cout << " �������: "; getline(cin, p[i].prizv);
		cout << "����: "; cin >> p[i].kurs;
		cout << " ������������ (0 - ��, 1 - ��, 2 - ��):  ";
		cin >> specialnist;
		p[i].spec = static_cast<Spec>(specialnist);

		cout << "������ � Գ����: ";
		cin >> p[i].physics_mark;
		cout << "������ � ����������: ";
		cin >> p[i].math_mark;
		cout << "������ � �����������: ";
		cin >> p[i].inf_mark;
		
	}
}
void Print(Student* p, const int N)
{
	cout << "============================================================================="
		<< endl;
	cout << "| � | �������  | ���� | ������������  | Գ���� | ���������� | ����������� | "
		<< endl;
	cout << "-----------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(10) << left << p[i].prizv
			<< "| " << setw(5) << right << p[i].kurs
			<< "| ";
			switch (p[i].spec)
			{
			case KN: cout << setw(15) << "��";
				break;
			case IT: cout << setw(15) << "��";
				break;
			case PF: cout << setw(15) << "��";
				break;
			}
			cout<< "| " << setw(7) << right << p[i].physics_mark << "| "
			<< setw(10) << p[i].math_mark << "| "
			<< setw(12) << p[i].inf_mark << "| " << endl;
	
	}
	cout << "============================================================================="
		<< endl;
	cout << endl;
}
double LineSearch(Student* p, const int N)
{
	cout << "������� �������� �� ������� �� ������:" << endl;
	int  n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].physics_mark == 5 && p[i].math_mark == 5 && p[i].inf_mark == 5)
		{
			n++;
		
				cout << setw(3) << right << n
					<< " " << p[i].prizv << endl;
			
		}
	}
	return n * 100.0 / N;
}
void Student_Who_have_5(Student* p, const int N)
{
	for (int i = 0; i < N; i++)
	{
		if (p[i].physics_mark == 5)
		{
			cout << p[i].prizv << endl;
		}
	}
}