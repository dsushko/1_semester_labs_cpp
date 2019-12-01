#include "StudentAfterSecondSession.h"

StudentAfterSecondSession::StudentAfterSecondSession(char *name, int course, int group, int recordbook_number,
                                                     int *marks1, int *marks2) : StudentAfterFirstSession(name, course,
                                                                                                          group,
                                                                                                          recordbook_number,
                                                                                                          marks1) {
    for (int i = 0; i < 5; i++) {
        secondSessionMarks[i] = marks2[i];
    }
};
double StudentAfterSecondSession::CountAverageMark() {
    double result = 0;
    for (int i = 0; i < 4; i++) {
        result += firstSessionMarks[i];
    }
    for (int i = 0; i < 5; i++) {
        result += secondSessionMarks[i];
    }
    result /= (5 + 4);
    return result;
}
double StudentAfterSecondSession::CountAverageMark(int session) {
    double result = 0;
    if(session == 1) {
        for (int i = 0; i < 4; i++) {
            result += firstSessionMarks[i];
        }
        result /= 4;
        return result;
    } else
    if(session == 2) {
        for (int i = 0; i < 4; i++) {
            result += firstSessionMarks[i];
        }
        for (int i = 0; i < 5; i++) {
            result += secondSessionMarks[i];
        }
        result /= 9;
    }
        return result;
}
int *StudentAfterSecondSession::operator[](int session) {
    if (session == 2)
        return secondSessionMarks;
    else if (session == 1)
        return firstSessionMarks;
    else return nullptr;
}
std::ostream &operator<<(std::ostream &out, StudentAfterSecondSession &student) {
    out << "\n";
    out << "Student name: " << student.getName() << "\n";
    out << "Course: " << student.getCourse() << "\n";
    out << "Group: " << student.getGroup() << "\n";
    out << "Identificator: " << student.getIdentificator() << "\n";
    out << "Recordbook number: " << student.getRecordbookNumber() << "\n";
    out << "*******MARKS*******\n";
    out << "First session: ";
    for (int i = 0; i < 4; i++) {
        out << student[1][i] << " ";
    }
    out << "\n";
    out << "Second session: ";
    for (int i = 0; i < 5; i++) {
        out << student[2][i] << " ";
    }
    return out;
};