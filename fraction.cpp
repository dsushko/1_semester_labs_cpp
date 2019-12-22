#include "fraction.h"

ProperFraction::ProperFraction() {

};
ProperFraction::ProperFraction(int numerator, int denominator){
    this->numerator=numerator;
    this->denominator=denominator;
    inf = false;
    if(denominator == 0) inf = true;
    negative = false;
    if(numerator < 0) negative = !negative;
    if(denominator < 0) negative = !negative;
};
ProperFraction::ProperFraction(const ProperFraction &fraction) : numerator(fraction.numerator), denominator(fraction.denominator){
    numerator = fraction.numerator;
    denominator = fraction.denominator;
    inf = fraction.inf;
    negative = fraction.negative;
};

int ProperFraction::get_numerator() {
    return numerator;
};
int ProperFraction::get_denominator(){
    return denominator;
};
void ProperFraction::reduction(){
    if(!inf)
        for(int i = 1000; i >= 3; i--){
            while (numerator% i == 0 && denominator % i == 0){
                numerator/=i;
                denominator/=i;
            }
        }
};
void ProperFraction::add(int additive){
    if(!inf){
        numerator+=additive*denominator;
        reduction();
    }
}
void ProperFraction::multiply(int multiplicative){
    if(!inf){
        numerator*=multiplicative;
        reduction();
    }
}
void ProperFraction::divide(int divider){
    if(!inf && divider != 0){
        denominator*= divider;
        reduction();
    }
};
void ProperFraction::add(const ProperFraction &fraction){
    if(!inf && !fraction.inf) {
        numerator = numerator*fraction.denominator + fraction.numerator*denominator;
        denominator = denominator*fraction.denominator;
        reduction();
    };
};
void ProperFraction::multiply(const ProperFraction &fraction){
    if(!inf && !fraction.inf) {
        numerator *= fraction.numerator;
        denominator *= fraction.denominator;
        reduction();
    };
};
void ProperFraction::divide(const ProperFraction &fraction){
    if(!inf && !fraction.inf && fraction.numerator != 0) {
        numerator *= fraction.denominator;
        denominator *=fraction.numerator;
        reduction();
    };
};

std::ostream& operator<<(std::ostream &out, const ProperFraction &fraction){
    if(!fraction.inf && fraction.numerator != 0 && fraction.numerator/fraction.denominator != 0) {
        out << (fraction.negative ? "-" : "")
            << fraction.numerator / fraction.denominator;
        ((fraction.numerator % fraction.denominator) != 0) ? out << "("
                                                                 << fraction.numerator % fraction.denominator
                                                                 << "/"
                                                                 << fraction.denominator
                                                                 << ")" : out << "";
    }
    if(!fraction.inf && fraction.numerator != 0 && fraction.numerator/fraction.denominator == 0) {
        out << (fraction.negative ? " - " : "")
            << fraction.numerator
            << "/"
            << fraction.denominator;
    }
    if(!fraction.inf && fraction.numerator == 0){
        out << "0";
    }
    if(fraction.inf) out << "(inf)";
    return out;
};
ProperFraction operator+(const ProperFraction &fraction, int additive){
    if(!fraction.inf) {
        ProperFraction assist(fraction.numerator + fraction.denominator*additive, fraction.denominator);
        assist.reduction();
        return assist;
    } else {
        return fraction;
    }
};
ProperFraction operator+(const ProperFraction &fraction1, const ProperFraction &fraction2) {
    if (!fraction1.inf) {
        ProperFraction assist(fraction1.numerator*fraction2.denominator + fraction2.numerator*fraction1.denominator, fraction1.denominator*fraction2.denominator);
        assist.reduction();
        return assist;
    } else {
        return fraction1;
    }
};
ProperFraction operator*(const ProperFraction &fraction, int multiplicative){
    if(!fraction.inf) {
        ProperFraction assist(fraction.numerator * multiplicative, fraction.denominator);
        assist.reduction();
        return assist;
    } else {
        return fraction;
    }
};
ProperFraction operator*(const ProperFraction &fraction1, const ProperFraction &fraction2){
    if(!fraction1.inf && !fraction2.inf) {
        ProperFraction assist(fraction1.numerator*fraction2.numerator, fraction1.denominator*fraction2.denominator);
        assist.reduction();
        return assist;
    } else {
        return fraction1;
    }
};
ProperFraction operator/(const ProperFraction &fraction, int divider){
    if(!fraction.inf && divider != 0) {
        ProperFraction assist(fraction.numerator, fraction.denominator*divider);
        assist.reduction();
        return assist;
    } else {
        return fraction;
    }
};
ProperFraction operator/(const ProperFraction &fraction1, const ProperFraction &fraction2){
    if(!fraction1.inf && !fraction2.inf) {
        ProperFraction assist(fraction1.numerator * fraction2.denominator, fraction1.denominator*fraction2.numerator);
        assist.reduction();
        return assist;
    } else {
        return fraction1;
    }
};