#include <iostream>

struct Expression
{
    virtual double evaluate() const = 0;
    virtual ~Expression() {}
};

struct Number : Expression
{
    Number(double value) : value(value) {}
    double evaluate() const { return this->value; }

private:
    double value;
};

struct BinaryOperation : Expression
{
    BinaryOperation(Expression const * left, char op, Expression const * right)
        : left(left), op(op), right(right)
    { }
    
    ~BinaryOperation() {
        delete left;
        delete right;
    }
    
    double evaluate() const {
        double left = this->left->evaluate();
        double right = this->right->evaluate();
        
        switch (this->op) {
            case '+':
                return left + right;
            case '-':
                return left - right;
            case '*':
                return left * right;
            case '/':
                return left / right;
        }
    }

private:
    Expression const * left;
    Expression const * right;
    char op;
};

int main() {
  Expression * sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
  Expression * expr = new BinaryOperation(new Number(3), '+', sube);

  std::cout << expr->evaluate() << std::endl;
  return 42;
}