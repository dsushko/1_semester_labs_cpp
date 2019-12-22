#include <iostream>
#include "fraction.h"

int main() {
    ProperFraction fraction1(1,3); //    1/3
    ProperFraction fraction2(4,5); //    4/5

    std::cout << fraction1; //    1/3
    std::cout << "\n";

    std::cout << fraction1.get_numerator(); //    1
    std::cout << "\n";
    std::cout << fraction1.get_denominator(); //    3

    std::cout << "\n" << fraction1 * 14; //    14/3 -> 4(2/3)

    std::cout << "\n" << fraction1 * fraction2; //    1/3 * 4/5 = (1*4)/(3*5)

    fraction1.multiply(14); //    changes original fraction, 1/3 -> 14/3
    std::cout << "\n";
    std::cout << fraction1; //    14/3 -> 4(2/3)

    fraction1.divide(14); //    14/3 -> 14/(3*14) -> 1/3
    fraction1.multiply(fraction2); //    1/3 -> (1*4)/(3*5) -> 4/15
    std::cout << "\n";
    std::cout << fraction1; //    4/15

    fraction1.add(5); //  4/15 -> 5 + 4/15 -> 5(4/15)
    std::cout << "\n";
    std::cout << fraction1; //    5(4/15)

    fraction1.add(-5); //    5(4/15) -> 5(4/15) + (-5) -> 4/15
    fraction1.divide(fraction2); //    4/15 -> 4/15 / 4/5 -> (4*5)/(15*4) -> 1/3
    std::cout << "\n";
    std::cout << fraction1; //     1/3

    fraction1.add(fraction2); //    1/3 -> 1/3 + 4/5 -> 5/15 + 12/15 -> 17/15
    std::cout << "\n";
    std::cout << fraction1; // 1(2/15)

    ProperFraction fractionCopy(fraction2);
    std::cout << "\n" << fractionCopy.get_numerator() << " " << fractionCopy.get_denominator() << "\n";
    std::cout << fractionCopy;

    return 0;
}