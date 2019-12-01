#include "Student.h"

int Student::MakeIdentificator(char *name, int course, int group, int recordbook_number) {
    int identificator = 0;
    identificator += recordbook_number;
    identificator += group * 1000000;
    identificator += course * 100000000;
    int n = strlen(name);
    for (int i = 0; i < n; i++) {
        identificator += (int) name[i];
    }
    return identificator;
};
Student::Student() : IDENTIFICATOR(0), RECORDBOOK_NUMBER(0), course(0), group(0){
    strcpy(name, "unnamed");
};
Student::Student(char *name, int course, int group, int recordbook_number) : RECORDBOOK_NUMBER(recordbook_number),
                                                                            course(course),
                                                                            group(group),
                                                                            IDENTIFICATOR(MakeIdentificator(name,course,group,recordbook_number)) {
    strcpy_s(this->name, name);
}
Student::Student(Student &student) : IDENTIFICATOR(student.IDENTIFICATOR),
                                    RECORDBOOK_NUMBER(student.RECORDBOOK_NUMBER),
                                    course(student.course),
                                    group(student.group) {
    strcpy(name, student.name);
};
char* Student::getName(){
    return name;
};
int Student::getGroup(){
    return group;
};
int Student::getCourse(){
    return course;
};
int Student::getIdentificator(){
    return IDENTIFICATOR;
};
int Student::getRecordbookNumber(){
    return RECORDBOOK_NUMBER;
};
void Student::setName(char* name){
    strcpy(this->name, name);
}
void Student::setGroup(int newGroup){
    group = newGroup;
}
void Student::setCourse(int newCourse){
    course = newCourse;
}
std::ostream& operator<<(std::ostream &out, Student &student){
    out << "\n";
    out << "Student name: " << student.name << "\n";
    out << "Course: " << student.course << "\n";
    out << "Group: " << student.group << "\n";
    out << "Identificator: " << student.IDENTIFICATOR << "\n";
    out << "Recordbook number: " << student.RECORDBOOK_NUMBER << "\n";
    out << "*******MARKS*******\n";
    out << "No marks yet\n";
    return out;
};