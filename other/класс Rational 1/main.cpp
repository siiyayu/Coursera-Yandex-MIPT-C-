#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <stdexcept>

using namespace std;

class Rational {
public:
    Rational() {
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {
        if (denominator == 0) {
            throw invalid_argument("Invalid argument");
        }
        int a, b, nod;
        a = abs(numerator);
        b = abs(denominator);
        while (a > 0 && b > 0) {
            if (a > b) {
                a = a % b;
            } else {
                b = b % a;
            }
        }
        nod = a + b;
        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) {
            p = -abs(numerator)/nod;
            q = abs(denominator)/nod;
        } else {
            p = abs(numerator)/nod;
            q = abs(denominator)/nod;
        }
    }
    int Numerator() const {
        return p;
    }

    int Denominator() const {
        return q;
    }

private:
    int p;
    int q;
};

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

Rational operator +(const Rational& lhs, const Rational& rhs) {
    int k = lcm(lhs.Denominator(), rhs.Denominator());
    int k1 = k/lhs.Denominator();
    int k2 = k/rhs.Denominator();
    return Rational(k1*lhs.Numerator() + k2*rhs.Numerator(), k);
}

Rational operator -(const Rational& lhs, const Rational& rhs) {
    int k = lcm(lhs.Denominator(), rhs.Denominator());
    int k1 = k/lhs.Denominator();
    int k2 = k/rhs.Denominator();
    return Rational(k1*lhs.Numerator() - k2*rhs.Numerator(), k);
}

bool operator ==(const Rational& lhs, const Rational& rhs) {
    if (lhs.Denominator() == rhs.Denominator() && lhs.Numerator() == rhs.Numerator()) {
        return true;
    } else {
        return false;
    }
}

Rational operator *(const Rational& lhs, const Rational& rhs) {
    int a, b;
    a = lhs.Numerator() * rhs.Numerator();
    b = lhs.Denominator() * rhs.Denominator();
    return Rational(a, b); //  в конструкторе класса ничего не вычислять - тестер выдает ошибку
}

Rational operator /(const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw domain_error("Division by zero");
    }
    int a, b;
    a = lhs.Numerator() * rhs.Denominator();
    b = rhs.Numerator() * lhs.Denominator();
    return Rational(a, b);
}

ostream& operator<<(ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& rational) {
    int a, b;
    if (stream >> a && stream.ignore(1) && stream >> b) {
        rational = Rational(a, b);
    }
    return stream;
}

bool operator<(const Rational& lhs, const Rational& rhs) {
    return (lhs - rhs).Numerator() < 0;
}


int main() {

    Rational r1, r2;
    char s;
    try {
        cin >> r1 >> s >> r2;
    } catch (invalid_argument& e) {
        cout << e.what() << endl;
        return 0;
    }
    if (s == '-') {
        auto x = r1 - r2;
        cout << x;
    }
    if (s == '+') {
        auto x = r1 + r2;
        cout << x;
    }
    if (s == '*') {
        auto x = r1 * r2;
        cout << x;
    }
    if (s == '/') {
        try {
            auto x = r1 / r2;
            cout << x;
        } catch (domain_error& e) {
            cout << e.what() << endl;
        }
    }
    return 0;
}