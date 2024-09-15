#include <iostream>
#include <sstream>

using namespace std;
struct action
{

  string op; // operator

  int (*func)(int, int); // function pointer to corresponding function
};

int myadd(int x, int y) { return x + y; }

int mymin(int x, int y) { return x - y; }

int mymul(int x, int y) { return x * y; }

int mydiv(int x, int y) { return x / y; }
int infix_cal(const string &input)
{
  stringstream st(input);
  int op1, op2;
  int final_result = 0;
  string op = "";
  st >> op1 >> op >> op2;
  action actions[4] = {{"+", myadd}, {"-", mymin}, {"*", mymul}, {"/", mydiv}};
  for (int i = 0; i < 4; ++i)
  {
    if (op == actions[i].op)
    {
      final_result = actions[i].func(op1, op2);
    }
  }
  return final_result;
}

int main()
{
  string input;
  cout << "Enter infix expression: ";
  getline(cin, input);
  cout << "Result: " << infix_cal(input) << endl;
  return 0;
}