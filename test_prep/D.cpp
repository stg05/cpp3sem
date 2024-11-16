struct Expression
{
    virtual double evaluate() const = 0;
    virtual ~Expression() = default; //!!!!!!
};

struct Number : Expression
{
    Number(double value) : value(value)
    {
    }

    double evaluate() const override
    {
        return value;
    }

private:
    double value;
};

struct BinaryOperation : Expression
{
    BinaryOperation(Expression const *left, char op, Expression const *right) : left(left), right(right), op(op)
    {
    }

    double evaluate() const override
    {
        switch (op)
        {
        case ('+'):
        {
            return left->evaluate() + right->evaluate();
        }
        case ('-'):
        {
            return left->evaluate() - right->evaluate();
        }
        case ('*'):
        {
            return left->evaluate() * right->evaluate();
        }
        case ('/'):
        {

            return left->evaluate() / right->evaluate();
        }
        default:
        {
            break;
            return 0.f;
        }
        }
        return 0.f;
    }

    ~BinaryOperation()
    {
        delete left;
        delete right;
    }

private:
    Expression const *left;
    Expression const *right;
    char op;
};