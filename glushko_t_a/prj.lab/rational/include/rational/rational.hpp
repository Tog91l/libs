#pragma once
#include <iostream>
#include<string>
#ifndef RATIONAL_RATIONAL_HPP_20230215
#define RATIONAL_RATIONAL_HPP_20230215
class Rational {
public:

    Rational();
    Rational(const int32_t num) noexcept;
    Rational(const int32_t num, const int32_t denom);
    Rational(const Rational&) = default;
    ~Rational() = default;

    Rational& operator+=(const Rational& rhs);
    Rational& operator-=(const Rational& rhs);
    Rational& operator*=(const Rational& rhs);
    Rational& operator/=(const Rational& rhs);
    Rational& operator =(const Rational& rhs);
    Rational& operator++();
    Rational operator++(int);
    Rational& operator--();
    Rational operator --(int);


    bool PosN()const;
    bool NegN()const;
    bool ZeroN()const;


    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

private:
    int32_t num = 0;
    int32_t denom = 1;
    void gsd();
    

    
    static const char slash = '/';
    

};

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);
std::istream& operator>>(std::istream& istrm, Rational& rhs);

Rational operator+(Rational& rhs);
Rational operator-(Rational& rhs);

Rational operator+(Rational lhs, const Rational& rhs);
Rational operator-(Rational lhs, const Rational& rhs);
Rational operator/(Rational lhs, const Rational& rhs);
Rational operator*(Rational lhs, const Rational& rhs);

bool operator ==(Rational lhs, const Rational& rhs);
bool operator>(Rational lhs, const Rational& rhs);
bool operator<(Rational lhs, const Rational& rhs);
bool operator!=(const Rational& lhs, const Rational& rhs);
bool operator<=(const Rational& lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const Rational& rhs);
#endif

