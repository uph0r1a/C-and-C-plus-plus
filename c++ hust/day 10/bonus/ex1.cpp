#include <iostream>

using namespace std;

typedef struct
{
    int numerator, denominator;
} Fraction;

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

void Simplify(Fraction &frac)
{
    int gcd = GCD(frac.numerator, frac.denominator);

    frac.denominator /= gcd;
    frac.numerator /= gcd;
}

Fraction Addition(Fraction frac1, Fraction frac2)
{
    Fraction fracSum;

    fracSum.numerator = (frac1.numerator * frac2.denominator) + (frac2.numerator * frac1.denominator);
    fracSum.denominator = frac1.denominator * frac2.denominator;

    Simplify(fracSum);

    return fracSum;
}

Fraction Subtraction(Fraction frac1, Fraction frac2)
{
    Fraction fracDifference;

    fracDifference.numerator = (frac1.numerator * frac2.denominator) - (frac2.numerator * frac1.denominator);
    fracDifference.denominator = frac1.denominator * frac2.denominator;

    Simplify(fracDifference);

    return fracDifference;
}

Fraction Multiplication(Fraction frac1, Fraction frac2)
{
    Fraction fracProduct;

    fracProduct.numerator = frac1.numerator * frac2.numerator;
    fracProduct.denominator = frac1.denominator * frac2.denominator;

    Simplify(fracProduct);

    return fracProduct;
}

Fraction Division(Fraction frac1, Fraction frac2)
{
    Fraction fracQuotient;

    fracQuotient.numerator = frac1.numerator * frac2.denominator;
    fracQuotient.denominator = frac1.denominator * frac2.numerator;

    Simplify(fracQuotient);

    return fracQuotient;
}

int main(int argc, char const *argv[])
{
    Fraction frac1, frac2;

    frac1.numerator = 2;
    frac1.denominator = 4;

    frac2.numerator = 0;
    frac2.denominator = 9;

    cout << "Fraction 1: " << frac1.numerator << "/" << frac1.denominator << endl
         << "Fraction 2: " << frac2.numerator << "/" << frac2.denominator << endl;

    Simplify(frac1);
    Simplify(frac2);

    cout << "Simplify of fraction 1: " << frac1.numerator << "/" << frac1.denominator << endl
         << "Simplify of fraction 2: " << frac2.numerator << "/" << frac2.denominator << endl
         << "Sum of " << frac1.numerator << "/" << frac1.denominator << " and " << frac2.numerator << "/" << frac2.denominator << " is: " << Addition(frac1, frac2).numerator << "/" << Addition(frac1, frac2).denominator << endl
         << "Difference of " << frac1.numerator << "/" << frac1.denominator << " and " << frac2.numerator << "/" << frac2.denominator << " is: " << Subtraction(frac1, frac2).numerator << "/" << Subtraction(frac1, frac2).denominator << endl
         << "Product of " << frac1.numerator << "/" << frac1.denominator << " and " << frac2.numerator << "/" << frac2.denominator << " is: " << Multiplication(frac1, frac2).numerator << "/" << Multiplication(frac1, frac2).denominator << endl;
    (frac2.numerator == 0) ? (cout << "No quotient" << endl) : (cout << "Quotient of " << frac1.numerator << "/" << frac1.denominator << " and " << frac2.numerator << "/" << frac2.denominator << " is: " << Division(frac1, frac2).numerator << "/" << Division(frac1, frac2).denominator << endl);
}