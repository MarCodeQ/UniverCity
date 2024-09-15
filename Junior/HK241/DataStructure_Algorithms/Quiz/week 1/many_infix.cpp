#include <iostream>
#include <sstream>

using namespace std;

string many_infix_cal(const string &input)
{
  stringstream ss(input);
  string line;
  int sum;
  string final_result = "";
  while (getline(ss,line)){
    int op1, op2;
    string op;
    stringstream st(line);
    st >> op1 >> op >> op2;
    if (op2 != 0){
      sum = (op == "+") ? op1 + op2 : (op == "-") ? op1 - op2 : (op == "*") ? op1 * op2 : (op == "/") ? op1 / op2 : 0;
    }
    else sum = (op == "+") ? op1 + op2 : (op == "-") ? op1 - op2 : (op == "*") ? op1 * op2 : 0;
    final_result += to_string(sum) + " ";
  }
  return final_result;
}

int main()
{
  string input;
  cout << "Enter infix expression: ";
  getline(cin, input);
  cout << "Result: " << many_infix_cal(input) << endl;
  return 0;
}