#include <iostream>

using namespace std;

void task1()
{
	cout << "Task 1\n";
	int a, b, c;
	cout << "Enter 3 numbers: ";
	cin >> a >> b >> c;
	a = (a + b + c) / 3;
	cout << "Average: " << a << endl;
	cout << "End of task 1\n\n";
	return;
}

void task2()
{
	cout << "Task 2\n";
	int A, B;
	cout << "Enter 2 numbers: ";
	cin >> A >> B;
	cout << "Sum: " << (A + B) << endl;
	cout << "Sub: " << (A - B) << endl;
	cout << "Div: " << (A / B) << endl;
	cout << "Mod: " << (A % B) << endl;
	cout << "Mul: " << (A * B) << endl;
	cout << "End of task 2\n\n";
}

void task3()
{
	cout << "Task 3\n";
	cout << "Xin Chao, Toi ten la Vu Minh Quan, Toi hoc khoa Computer Science\n";
	cout << "Toi thich ra duong an ngon mac dep\n";
	cout << "End of task 3\n\n";
}

void task4()
{
	cout << "Task 4\n";
	int x, y;
	cout << "Enter x and y: ";
	cin >> x >> y;
	cout << x << " percentage of " << y << " is " << (x * y / 100) << endl;
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