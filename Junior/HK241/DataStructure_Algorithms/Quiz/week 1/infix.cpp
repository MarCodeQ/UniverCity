#include <iostream>
#include <sstream>

using namespace std;

int infix_cal(const string &input)
{
  stringstream st(input);
  int op1, op2;
  string op = "";
  st >> op1 >> op >> op2;
  if (op2 != 0)
  {
    return op == "+" ? op1 + op2 : op == "-" ? op1 - op2
                               : op == "*"   ? op1 * op2
                               : op == "/"   ? op1 / op2
                                             : 0;
  }
  else if (op != "/")
  {
    return op == "+" ? op1 + op2 : op == "-" ? op1 - op2
                               : op == "*"   ? op1 * op2
                                             : 0;
  }
  else
  {
    cout << "Error: Division by zero" << endl;
    return 0;
  }
  return 0;
}

int main()
{
  string input;
  cout << "Enter infix expression: ";
  getline(cin, input);
  cout << "Result: " << infix_cal(input) << endl;
  return 0;
}