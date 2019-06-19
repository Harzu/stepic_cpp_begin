struct Expression
{
    virtual double evaluate() const = 0;
    virtual ~Expression() {}
};

bool check_equals(Expression const *left, Expression const *right)
{
    int * left_vptr =  *(int **)left;
    int * right_vptr = *(int **)right;
    
    if (left_vptr == right_vptr) return true;
    return false;
}