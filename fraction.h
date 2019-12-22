#include <iostream>

class ProperFraction{
private:
    int numerator;
    int denominator;
    bool negative = false;
    bool inf = false;

    void reduction();

    ProperFraction();
public:
    ProperFraction(int numerator, int denominator);
    ProperFraction(const ProperFraction &fraction);

    int get_numerator();
    int get_denominator();

    void add(int additive);
    void multiply(int multiplicative);
    void divide(int divider);

    void add(const ProperFraction &fraction);
    void multiply(const ProperFraction &fraction);
    void divide(const ProperFraction &fraction);

    friend std::ostream& operator<<(std::ostream &out, const ProperFraction &fraction);
    friend ProperFraction operator+(const ProperFraction &fraction, int additive);
    friend ProperFraction operator+(const ProperFraction &fraction1, const ProperFraction &fraction2);
    friend ProperFraction operator*(const ProperFraction &fraction, int multiplicative);
    friend ProperFraction operator*(const ProperFraction &fraction1, const ProperFraction &fraction2);
    friend ProperFraction operator/(const ProperFraction &fraction, int divider);
    friend ProperFraction operator/(const ProperFraction &fraction1, const ProperFraction &fraction2);
};