/*
14. Design and implement a Money class for calculations involving dollars and cents
where arithmetic must be accurate to the last cent using 4/5 rounding rule (.5 of a 
cent rounds up; anything less than .5 rounds down). Represent a monetary amount as a 
number of cents in a long int, but input and output as dollars and cents, e.g., $123.45. 
Don’t worry about amounts that don’t fit into a long int.
*/

#include "std_lib_facilities.h"

class Money
{
public:
    Money();
    Money(long int c) : cents(c) {};
    //Money(long int c, string currency) : cents(c), currency(currency) {};
    long int formatCents() const { return cents % 100; }
    long int formatDollars() const { return cents / 100; }
    Money(long int d, long int c) : cents(d * 100 + c)
    {
        if (c > 100) error("Cents must be between 0 and 99");
    };
    long int cents;
    string currency;
};

ostream& operator << (ostream& os, const Money& m)
{
    os << "$" << m.formatDollars() << ".";
    if (m.formatCents() < 10)
        os << "0";
    os << m.formatCents();
    return os;
}

Money operator + (Money const& a, Money const& b)
{
    int sum = 0;
    sum = a.cents + b.cents;
    return sum;
}

Money operator - (Money const& a, Money const& b)
{
    int diff = 0;
    diff = a.cents - b.cents;
    return abs(diff);
}

long int myRound(double num)
{
    double fractionalPart = num - static_cast<long int>(num);
    if (fractionalPart < 0.5)
        return static_cast<long int>(num);
    else
        return static_cast<long int>(num) + 1;
}

Money operator * (Money const& a, Money const& b)
{
    double product;
    product = (a.cents * b.cents) / 100.0;
    return Money(myRound(product));
}

Money operator / (Money const& a, Money const& b)
{
    double div;
    div = (a.cents * 100.0 / b.cents);
    return Money(myRound(div));
}

int main()
{
    try
    {
        Money m1(573); // Cent input
        cout << "m1(573): " << m1;
        Money m2(8, 57); // Dollar input
        cout << "\nm2(8, 57): " << m2;
        cout << "\nm1 + m2: " << m1 + m2;
        cout << "\nm1 - m2: " << m1 - m2;
        cout << "\nm1 * m2: " << m1 * m2;
        Money m3(3, 91); // Dollar input
        cout << "\nm3(3, 91)";
        cout << "\nm1 * m2 * m3: " << m1 * m2 * m3;
        cout << "\nm1/m3: " << m1 / m3;
        cout << "\nm2/m3: " << m2 / m3;
        //Money m4(3, "DK"); // Dollar input
    }

    catch (exception& e)
    {
        cout << "\nException: " << e.what() << endl;
    }
}