#include <complex>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

struct DiscriminantStrategy
{
    virtual double calculate_discriminant(double a, double b, double c) = 0;
};

struct OrdinaryDiscriminantStrategy : DiscriminantStrategy
{
    double calculate_discriminant(double a, double b, double c) {
        return (b*b - 4*a*c);
    }
};

struct RealDiscriminantStrategy : DiscriminantStrategy
{
    double calculate_discriminant(double a, double b, double c) {
        double res = b*b - 4*a*c;
        return (res >= 0 ? res : NAN);
    }   
};

class QuadraticEquationSolver
{
    DiscriminantStrategy& strategy;
public:
    QuadraticEquationSolver(DiscriminantStrategy &strategy) : strategy(strategy) {}

    tuple<complex<double>, complex<double>> solve(double a, double b, double c)
    {
        double discriminant = strategy.calculate_discriminant(a, b, c);
        complex<double> disc(discriminant, 0.);
        complex<double> r1 ((-b+sqrt(disc))/(2*a));
        complex<double> r2 ((-b-sqrt(disc))/(2*a));
        return make_tuple(r1, r2);
    }
};
