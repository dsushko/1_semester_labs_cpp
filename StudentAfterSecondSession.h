#pragma once
#include "StudentAfterFirstSession.h"
#include <vector>

class StudentAfterSecondSession : public StudentAfterFirstSession {
protected:
    int secondSessionMarks[5];
public:
    StudentAfterSecondSession(char* name, int course, int group, int recordbook_number, int* marks1, int* marks2);
    double CountAverageMark(int session) override ;
    double CountAverageMark() override ;
    int* operator[](int session) override ;
    friend std::ostream& operator<<(std::ostream &out, StudentAfterSecondSession &student);
};