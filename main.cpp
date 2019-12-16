#include <iostream>
#include <vector>
#include "Student.h"
#include "StudentAfterFirstSession.h"
#include "StudentAfterSecondSession.h"
#include "printAveragesFunctions.h"

int main() {

    int marks_dima_1[4] = {9,8,8,10};
    int marks_egor_1[4] = {4,5,6,7};
    int marks_petya_1[4] = {4,5,6,4};

    int marks_dima_2[5] = {8,7,7,9,4};
    int marks_egor_2[5] = {4,4,5,6,4};
    int marks_petya_2[5] = {4,4,5,4,4};

    auto* dima = new StudentAfterSecondSession("dima", 1, 4, 23214, marks_dima_1, marks_dima_2);
    auto* egor = new StudentAfterSecondSession("egor", 1, 4, 23220, marks_egor_1, marks_egor_2);
    auto* petya = new StudentAfterSecondSession("petya", 2, 3, 111111, marks_petya_1, marks_petya_2);
    std::vector<Student*> bsu;
    bsu.push_back(dima);
    bsu.push_back(egor);
    bsu.push_back(petya);

    std::cout << *dima << "\n" << *egor << "\n" << *petya << "\n\n";
    PrintGroupAverageAfterFirstSession(&bsu);
    std::cout << "\n";
    PrintGroupAverageAfterSecondSession(&bsu);

    return 0;
}