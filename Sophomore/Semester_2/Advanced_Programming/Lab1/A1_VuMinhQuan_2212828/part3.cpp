#include <iostream>
using namespace std;
void task1()
{
  int age;
  cout << "Enter your age: ";
  cin >> age;

  int ticketCost;
  if (age < 5)
  {
    ticketCost = 0;
  }
  else if (age >= 5 && age <= 10)
  {
    ticketCost = 10;
  }
  else if (age >= 11 && age <= 16)
  {
    ticketCost = 20;
  }
  else
  {
    ticketCost = 25;
  }

  cout << "Ticket price: $" << ticketCost << endl;
  cout << "End of task 1\n\n";
}

void task2()
{
  double amount;
  cout << "Enter the amount in VND: ";
  cin >> amount;

  int choice;
  cout << "Choose currency conversion: (1) AUD or (2) USD: ";
  cin >> choice;

  double convertedAmount;
  if (choice == 1)
  {
    convertedAmount = amount / 20000;
    cout << "Converted amount in AUD: " << convertedAmount << endl;
  }
  else if (choice == 2)
  {
    convertedAmount = amount / 23000;
    cout << "Converted amount in USD: " << convertedAmount << endl;
  }
  else
  {
    cout << "Invalid choice!" << endl;
  }
  cout << "End of task 2\n\n";
}

void task3()
{
  double num1, num2;
  char op;

  cout << "Enter first number: ";
  cin >> num1;

  cout << "Enter second number: ";
  cin >> num2;

  cout << "Enter operator (+, -, *, /): ";
  cin >> op;

  double result;
  switch (op)
  {
  case '+':
    result = num1 + num2;
    break;
  case '-':
    result = num1 - num2;
    break;
  case '*':
    result = num1 * num2;
    break;
  case '/':
    if (num2 != 0)
    {
      result = num1 / num2;
    }
    else
    {
      cout << "Error: Division by zero!" << endl;
      return;
    }
    break;
  default:
    cout << "Invalid operator!" << endl;
    return;
  }

  cout << "Result: " << result << endl;
  cout << "End of task 3\n\n";
}

int main()
{
  task1();
  task2();
  task3();

  return 0;
}
