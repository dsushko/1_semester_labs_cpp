#include "StudentAfterFirstSession.h"

StudentAfterFirstSession::StudentAfterFirstSession(char *name, int course, int group, int recordbook_number,
                                                   int *marks1) : Student(name, course, group, recordbook_number) {
    for (int i = 0; i < 4; i++) {
        firstSessionMarks[i] = marks1[i];
    }
};
double StudentAfterFirstSession::CountAverageMark() {
    double result = 0;
    for (int i = 0; i < 4; i++) {
        std::cout << firstSessionMarks[i];
        result += firstSessionMarks[i];
    }
    result /= 4;
    return result;
}
double StudentAfterFirstSession::CountAverageMark(int session) {
    double result = 0;
    if(session == 1) {
        for (int i = 0; i < 4; i++) {
            std::cout << firstSessionMarks[i];
            result += firstSessionMarks[i];
        }
        result /= 4;
    }
        return result;
}
int *StudentAfterFirstSession::operator[](int session) {
    if (session == 1)
        return
                firstSessionMarks;
    else return nullptr;
}

std::ostream &operator<<(std::ostream &out, StudentAfterFirstSession &student) {
    out << "\n";
    out << "Student name: " << student.getName() << "\n";
    out << "Course: " << student.getCourse() << "\n";
    out << "Group: " << student.getGroup() << "\n";
    out << "Identificator: " << student.getIdentificator() << "\n";
    out << "Recordbook number: " << student.getRecordbookNumber() << "\n";
    out << "*******MARKS*******\n";
    out << "First session: ";
    for (int i = 0; i < 4; i++) {
        std::cout << student[1][i] << " ";
    }
    return out;
};