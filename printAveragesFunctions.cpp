#include "printAveragesFunctions.h"
#include "Student.h"
#include <vector>

void PrintGroupAverageAfterFirstSession(std::vector<Student*>* group){
    double firstSessionAverage = 0;
    int n = group->size();
    for(int i = 0; i < n; i++){
        firstSessionAverage+=(*group)[i]->CountAverageMark(1);
    }
    std::cout << firstSessionAverage/n;
};
void PrintGroupAverageAfterSecondSession(std::vector<Student*>* group){
    double secondSessionAverage = 0;
    int n = group->size();
    for(int i = 0; i < n; i++){
        secondSessionAverage+= (*group)[i]->CountAverageMark(2);
    }
    std::cout << secondSessionAverage/n;
};


