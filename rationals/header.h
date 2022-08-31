#ifndef RATIONAL_NUMBER_H
#define RATIONAL_NUMBER_H

class RationalNumber {
    public:
        RationalNumber( int = 0, int = 1 ); // default constructor
   /* Write prototype for operator + */
        RationalNumber operator+(const RationalNumber &source);
   /* Write prototype for operator - */
        RationalNumber operator-(const RationalNumber &source);
   /* Write prototype for operator * */
        RationalNumber operator*(const RationalNumber &source);
   /* Write prototype for operator / */
        RationalNumber operator/(const RationalNumber &source);

   // relational operators
   /* Write prototype for operator > */
        bool operator>(const RationalNumber &source) const;
   /* Write prototype for operator < */
        bool operator<(const RationalNumber &source) const;
   /* Write prototype for operator >= */
        bool operator>=(const RationalNumber &source) const;
   /* Write prototype for operator <= */
        bool operator<=(const RationalNumber &source) const;

   // equality operators
   /* Write prototype for operator == */
        bool operator==(const RationalNumber &source) const;
   /* Write prototype for operator != */
        bool operator!=(const RationalNumber &source) const;

        void printRational() const; // display rational number
    private:
        int numerator; // private variable numerator
        int denominator; // private variable denominator
        void reduction(); // function for fraction reduction
}; // end class RationalNumber

#endif