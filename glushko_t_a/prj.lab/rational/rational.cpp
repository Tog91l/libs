#include <rational/rational.hpp>
#include <iostream>
#include <string>
std::istream& Rational::readFrom(std::istream& istrm) {

    char slash(0);
    int32_t num(0);
    int32_t denom(1);
    istrm >> num >> slash >> denom;
    return istrm;
}
std::ostream& Rational::writeTo(std::ostream& ostrm) const {
    ostrm << num << slash << denom;
    return ostrm;
}


Rational::Rational() {
    num = 0;
    denom = 1;
}

Rational::Rational(int32_t num_int)noexcept {
    num = num_int;
    denom = 1;
}


Rational::Rational(int32_t num_int, int32_t denom_int) {
    if (denom_int == 0) {
        throw std::invalid_argument("you cann't divine by zero");
    }
        if (denom_int < 0) {
            denom_int *= -1;
            num_int *= -1;
        }
        num = num_int;
        denom = denom_int;
        

    }


bool Rational::PosN()const {
    return num > 0;
}

bool Rational::NegN()const {
    return num < 0;
}

bool Rational::ZeroN()const {
    return num == 0;
}
void Rational::gsd() {
    int32_t a, b;
    a = abs(num); b = denom;
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    num /= a;
    denom /= a;
}
Rational& Rational::operator=(const Rational& rhs) {
    num = rhs.num;
    denom = rhs.denom;
    return *this;
}

Rational& Rational::operator+=(const Rational& rhs) {
    num *= rhs.denom;
    denom *= rhs.denom;
    num += denom / rhs.denom * rhs.num;
    gsd();
    return *this;
}

Rational& Rational::operator++() {
   *this += 1;
   return *this;
}

Rational Rational::operator++(int) {
    Rational plus(*this);
    ++(*this);
    return plus;

}
Rational& Rational::operator--() {
   *this -= 1;
   return *this;
}


Rational Rational::operator--(int) {
    Rational minus(*this);
    --(*this);
    return minus;
}

Rational& Rational::operator-=(const Rational& rhs) {
    int32_t a = rhs.denom;
    num *= rhs.denom;
    denom *= rhs.denom;
    num -= denom / rhs.denom * rhs.num;
    gsd();
    return *this;
}

Rational& Rational::operator/=(const Rational& temp) {
    if (temp.num == 0) {
        throw std::invalid_argument("invalid argument");
    }
    num *= temp.denom;
    denom *= temp.num;
    gsd();
    return *this;

}

Rational& Rational::operator*=(const Rational& rhs) {
    num *= rhs.num;
    denom *= rhs.denom;
    gsd();
    return *this;
}





std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {
    return rhs.writeTo(ostrm);
}

std::istream& operator>>(std::istream& istrm, Rational& rhs) {
    return rhs.readFrom(istrm);
}

Rational operator+(Rational& rhs) {
    return rhs;
}

Rational operator-(Rational& rhs) {
    Rational minus;
    minus -= rhs;
    return minus;
}

Rational operator-(Rational lhs, const Rational& rhs) {
    lhs -= rhs;
    return lhs;
}

Rational operator*(Rational lhs, const Rational& rhs) {
    lhs *= rhs;
    return lhs;
}


Rational operator/(Rational lhs, const Rational& rhs) {
    lhs /= rhs;
    return lhs;
}

bool operator==(Rational lhs, const Rational& rhs) {
    lhs -= rhs;
    return lhs.ZeroN();

}

bool operator <(Rational lhs, const Rational& rhs) {
    Rational difference = lhs - rhs;
    return difference.NegN();
}

bool operator >(Rational lhs, const Rational& rhs) {
    Rational difference = lhs - rhs;
    return difference.PosN();
}

bool operator !=(const Rational& lhs, const Rational& rhs) {
    return operator==(lhs, rhs);
}

bool operator <=(const Rational& lhs, const Rational& rhs) {
    return operator >(lhs, rhs);
}
bool operator >=(const Rational& lhs, const Rational& rhs) {
    return operator <(lhs, rhs);
}
