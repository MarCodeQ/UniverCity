class Exp
{
public:
  virtual int eval() = 0;
};

class BinExp : public Exp
{
private:
  Exp *left;
  char op;
  Exp *right;

public:
  BinExp(Exp *left, char op, Exp *right) : left(left), op(op), right(right) {};

  int eval() override
  {
    int leftVal = left->eval();
    int rightVal = right->eval();

    switch (op)
    {
    case '+':
      return leftVal + rightVal;
    case '-':
      return leftVal - rightVal;
    case '*':
      return leftVal * rightVal;
    case '/':
      return leftVal / rightVal;
    }

    return 0;
  }
};

class UnExp : public Exp
{
private:
  char op;
  Exp *exp;

public:
  UnExp(char op, Exp *exp) : op(op), exp(exp) {};
  int eval() override
  {
    int value = exp->eval();
    if (op == '+')
      return value;
    else
      return -value;
  }
};

class IntLit : public Exp
{
private:
  int val;

public:
  IntLit(int v) : val(v) {}

  int eval() override
  {
    return val;
  }
};