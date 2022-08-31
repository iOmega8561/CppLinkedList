#include <cstdlib>
#include <iostream>
#include <cassert>
using namespace std;

#include "header.h"

RationalNumber::RationalNumber(int num, int den) {
    assert(den != 0);
    numerator = num;
    denominator = den;
}

RationalNumber RationalNumber::operator+(const RationalNumber &source) {
    int res_den, res_num;

    if (denominator != source.denominator) {
        res_den = denominator*source.denominator;
        res_num = (source.denominator*numerator)+(denominator*source.numerator);
    } else {
        res_den = denominator;
        res_num = numerator+source.numerator;
    }

    RationalNumber result(res_num, res_den);
    result.reduction();
    return result;
}

RationalNumber RationalNumber::operator-(const RationalNumber &source) {
    int res_den, res_num;

    if (denominator != source.denominator) {
        res_den = denominator*source.denominator;
        res_num = (source.denominator*numerator)-(denominator*source.numerator);
    } else {
        res_den = denominator;
        res_num = numerator-source.numerator;
    }

    RationalNumber result(res_num, res_den);
    result.reduction();
    return result;
}


RationalNumber RationalNumber::operator*(const RationalNumber &source) {
    int res_den = denominator*source.denominator, res_num = numerator*source.numerator;

    RationalNumber result(res_num, res_den);
    result.reduction();
    return result;
}

RationalNumber RationalNumber::operator/(const RationalNumber &source) {
    int res_den = denominator*source.numerator, res_num = numerator*source.denominator;

    RationalNumber result(res_num, res_den);
    result.reduction();
    return result;
}

bool RationalNumber::operator>(const RationalNumber &source) const {
    if (denominator != source.denominator)
        return (numerator*source.denominator) > (source.numerator*denominator);
    else
        return numerator > source.numerator;
}

bool RationalNumber::operator<(const RationalNumber &source) const {
    if (denominator != source.denominator)
        return (numerator*source.denominator) < (source.numerator*denominator);
    else
        return numerator < source.numerator;
}

bool RationalNumber::operator>=(const RationalNumber &source) const {
    if (denominator != source.denominator)
        return (numerator*source.denominator) >= (source.numerator*denominator);
    else
        return numerator >= source.numerator;
}

bool RationalNumber::operator<=(const RationalNumber &source) const {
    if (denominator != source.denominator)
        return (numerator*source.denominator) <= (source.numerator*denominator);
    else
        return numerator <= source.numerator;
}

bool RationalNumber::operator==(const RationalNumber &source) const {
    if (denominator != source.denominator)
        return (numerator*source.denominator) == (source.numerator*denominator);
    else
        return numerator == source.numerator;
}

bool RationalNumber::operator!=(const RationalNumber &source) const {
    if (denominator != source.denominator)
        return (numerator*source.denominator) != (source.numerator*denominator);
    else
        return numerator != source.numerator;
}

void RationalNumber::printRational() const
{
   if ( numerator == 0 ) // print fraction as zero
      cout << numerator;
   else if ( denominator == 1 ) // print fraction as integer
      cout << numerator;
   else
      cout << numerator << '/' << denominator;
}

void RationalNumber::reduction()
{
   int largest, gcd = 1;  // greatest common divisor;

   largest = ( numerator > denominator ) ? numerator: denominator;

   for ( int loop = 2; loop <= largest; loop++ )
       if ( numerator % loop == 0 && denominator % loop == 0 )
          gcd = loop;

   numerator /= gcd;
   denominator /= gcd;
}
