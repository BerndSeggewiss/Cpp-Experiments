#include "std_lib_facilities.h"

class Money
{
public:
    enum Currency
    {
        USD, DKK, CHF
    };
    Money(int d, int c, Currency cur) : cents(d * 100 + c), currency(cur)
    {
        if (c > 99 || c < 0) error("Cents must be between 0 an 99");
    }
    Money(long int c, Currency cur) : cents(c), currency(cur) 
    {
        if (c < 0) error("Cents cannot be negative");
    };
    long int formatDollars() const { return cents / 100; }
    long int formatCents() const { return cents % 100; }
    string formatCurrency() const
    {
        switch (currency)
        {
            case USD: return "USD";
            case DKK: return "DKK";
            case CHF: return "CHF";
            default: return "";
        }
    }
    Currency currency;
    long int cents;
};

ostream& operator << (ostream& os, const Money& m)
{
    os << "USD" << m.formatDollars() << "." << setfill('0')
        << setw(2) << m.formatCents();
    return os;
}

double exchangeRate(Money::Currency e1, Money::Currency e2)
{
    switch (e1)
    {
        case Money::USD:
            if (e2 == Money::DKK)
                return (1/6.95);
            if (e2 == Money::CHF)
                return 1/0.9;
            break;
        case Money::DKK:
            if (e2 == Money::USD)
                return 1/6.95;
            break;
        case Money::CHF:
            if (e2 == Money::USD)
                return 1/0.9;
            break;
    }
}


Money operator + (Money const& a, Money const& b)
{
    double sum = 0;
    double exchRate = exchangeRate(a.currency, b.currency);
    if (a.currency == b.currency)
    {
        sum = a.cents + b.cents;
    }
    switch (a.currency)
    {
        case Money::USD:
            if (b.formatCurrency() != "USD")
                sum = a.cents + b.cents * exchRate;
            break;
        case Money::DKK:
            if (b.formatCurrency() != "DKK")
                sum = a.cents * exchRate + b.cents;
            break;
        case Money::CHF:
            if (b.formatCurrency() != "CHF")
                sum = a.cents * exchRate + b.cents;
            break;
    }
    return Money(static_cast<long int>(round(sum)), a.currency);
}

Money operator - (Money const& a, Money const& b)
{
    double sum = 0;
    double exchRate = exchangeRate(a.currency, b.currency);
    if (a.currency == b.currency)
    {
        sum = a.cents - b.cents;
    }
    switch (a.currency)
    {
    case Money::USD:
        if (b.formatCurrency() != "USD")
            sum = a.cents - b.cents * exchRate;
        break;
    case Money::DKK:
        if (b.formatCurrency() != "DKK")
            sum = a.cents * exchRate - b.cents;
        break;
    case Money::CHF:
        if (b.formatCurrency() != "CHF")
            sum = a.cents * exchRate - b.cents;
        break;
    }
    return Money(static_cast<long int>(round(sum)), a.currency);
}

Money operator * (Money const& a, Money const& b)
{
    double product = 0;
    double exchRate = exchangeRate(a.currency, b.currency);
    if (a.currency == b.currency)
    {
        product = (a.cents * b.cents)/1000.0;
    }
    switch (a.currency)
    {
    case Money::USD:
        if (b.formatCurrency() != "USD")
            product = (a.cents * (b.cents*exchRate));
        break;
    case Money::DKK:
        if (b.formatCurrency() != "DKK")
            product = (a.cents * (b.cents*exchRate));
        break;
    case Money::CHF:
        if (b.formatCurrency() != "CHF")
            product = (a.cents * (b.cents*exchRate));
        break;
    }
    return Money(static_cast<long int>(round(product)), a.currency);
}

Money operator / (Money const& a, Money const& b)
{
    double division = 0;
    double exchRate = exchangeRate(a.currency, b.currency);
    if (a.currency == b.currency)
    {
        division = (a.cents / b.cents);
    }
    switch (a.currency)
    {
    case Money::USD:
        if (b.formatCurrency() != "USD")
            division = (a.cents / (b.cents * exchRate));
        break;
    case Money::DKK:
        if (b.formatCurrency() != "DKK")
            division = (a.cents / (b.cents * exchRate));
        break;
    case Money::CHF:
        if (b.formatCurrency() != "CHF")
            division = (a.cents / (b.cents * exchRate));
        break;
    }
    return Money(static_cast<long int>(round(division)), a.currency);
}


int main()
{
    try
    {
        Money m1(8, 91, Money::USD); // Dollar and Cent input
        cout << "\nm1(8,91 USD): " << m1; 
        Money m2(4981, Money::USD);  // Dollar ent input
        cout << "\nm2(4,321 USD): " << m2;
        Money m3(5871, Money::DKK);  // Dansk kroner input
        cout << "\nm3(5,871 DKK): " << m3;
        Money m4(1943, Money::CHF);  // Swiss franc input
        cout << "\nm4(1943 CHF): " << m4;

        cout << "\nm1 + m3: " << m1 + m3; // USD + DKK
        cout << "\nm1 + m4: " << m1 + m4; // USD + CHF
        cout << "\nm3 + m1: " << m3 + m1; // DKK + USD
        cout << "\nm4 + m1: " << m4 + m1; // CHF + USD

        cout << "\nm1 - m3: " << m1 - m3; // USD - DKK
        cout << "\nm2 - m1: " << m2 - m1; // USD - USD

        cout << "\nm1 * m2: " << m1 * m2; // USD * USD
        cout << "\nm1 * m3: " << m1 * m3; // USD * DKK
        cout << "\nm1 * m4: " << m1 * m4; // USD * CHF
        cout << "\nm4 * m1: " << m4 * m1; // CHF * USD

        cout << "\nm4 / m1: " << m4 / m1; // CHF / USD
    }
    catch (exception& e)
    {
        cout << "\nException: " << e.what() << endl;
    }
}



