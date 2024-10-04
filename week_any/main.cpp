/** Объявление класса Function **/
class Function {
public:
    virtual double operator()(double) const = 0;

    virtual ~Function() {}
};

/** Объявление функций dichotomy_any, make_linear_function, make_quadratic_function, delete_function **/
double dichotomy_any(double left, double right, Function const &f, double tolerance) {
    double result = .5f * left + .5f * right;
    if (f(result) > tolerance) {
        return dichotomy_any(left, result, f, tolerance);
    } else if (f(result) < -tolerance) {
        return dichotomy_any(result, right, f, tolerance);
    } else {
        return result;
    }
}

class LinearFunction : public Function {

public:
    LinearFunction() = default;

    LinearFunction(double a1, double a2) : LinearFunction() {
        k = a1;
        b = a2;
    }

    double operator()(double x) const override {
        return k * x + b;
    }


private:
    double k = 0.f, b = 0.f;
};

LinearFunction *make_linear_function(double k, double b) {
    auto *lf = new LinearFunction{k, b};
    return lf;
}

class QuadraticFunction : public Function {

public:
    QuadraticFunction() = default;

    QuadraticFunction(double a1, double a2, double a3) : QuadraticFunction() {
        a = a1;
        b = a2;
        c = a3;
    }

    double operator()(double x) const override {
        return a * x * x + b * x + c;
    }

private:
    double a = 0.f, b = 0.f, c = 0.f;
};

QuadraticFunction *make_quadratic_function(double a, double b, double c) {
    auto *qf = new QuadraticFunction{a, b, c};
    return qf;
}

void delete_function(Function *f) {
    delete f;
}

bool close(double a, double b, double tolerance) {
    return a - tolerance < b and a + tolerance > b;
}

#include<cassert>

int main() {
    Function *f1 = make_linear_function(1., 1.);
    auto f1_root = dichotomy_any(-10., 10., *f1, 0.001);
    assert(close(f1_root, -1., 0.001));
    delete_function(f1);

    Function *f2 = make_quadratic_function(1., 0., -1.);
    auto f2_root = dichotomy_any(0., 2., *f2, 0.001);
    assert(close(f2_root, 1., 0.001));
    delete_function(f2);

    return 0;
}

/** Ваш код **/