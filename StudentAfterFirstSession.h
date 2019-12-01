#pragma once

#include <vector>
#include "Student.h"

class StudentAfterFirstSession : public Student {
protected:
    int firstSessionMarks[4];
public:
    StudentAfterFirstSession(char* name, int course, int group, int recordbook_number, int* marks1);
    double CountAverageMark(int session) override ;
    double CountAverageMark() override ;
    int* operator[](int session) override ;
    friend std::ostream& operator<<(std::ostream &out, StudentAfterFirstSession &student);
};
