#include <iostream>
#include <math.h>
#include <string.h>
#include <string>

using namespace std;

void task1()
{
	cout << "Task 1\n";
	double a, b;
	cout << "Enter the amount of money (USD): ";
	cin >> a;
	b = a * 24.19;
	cout << a << " USD = " << b << " VND " << endl;
	cout << "End of task 1\n\n";
}

void task2()
{
	cout << "Task 2\n";
	double a, b;
	cout << "Enter radius and height of the cylinder: ";
	cin >> a >> b;
	cout << "Volume : " << (a * a * 3.14 * b) << endl;
	cout << "End of task 2\n\n";
}

void task3()
{
	cout << "Task 3\n";
	double a;
	cout << "Enter a number: ";
	cin >> a;
	cout << "abs: " << abs(a) << endl;
	cout << "sin: " << sin(a) << endl;
	cout << "cos: " << cos(a) << endl;
	cout << "tan: " << tan(a) << endl;
	if (a > 0)
	{
		cout << "log10: " << log10(a) << endl;
		cout << "sprt: " << sqrt(a) << endl;
	}
	cout << "End of task 3\n\n";
}

void task4()
{
	cout << "Task 3\n";
	string name, birth, hometown, major;
	cout << "Name: ";
	cin >> name;
	cout << "Day of birth: ";
	cin >> birth;
	cout << "Hometown(1 world only): ";
	cin >> hometown;
	cout << "Major(1 word only): ";
	cin >> major;
	cout << "\n The user personal information can be written down as follow: \n";
	cout << "Name: " << name << endl;
	cout << "Day of birth: " << birth << endl;
	cout << "Hometown: " << hometown << endl;
	cout << "Major: " << major << endl;
	cout << "End of task 4\n\n";
}

int main()
{
	task1();
	task2();
	task3();
	task4();
	return 0;
}