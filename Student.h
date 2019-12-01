#pragma once
#include <iostream>
#include <vector>

class Student {
private:
    int MakeIdentificator(char *name, int course, int group, int recordbook_number);
protected:
    char name[250];
    int course;
    int group;
    const int RECORDBOOK_NUMBER;
    const int IDENTIFICATOR;
    Student();
public:
    Student(char *name, int course, int group, int recordbook_number);

    Student(Student &student);

    char* getName();
    int getGroup();
    int getCourse();
    int getIdentificator();
    int getRecordbookNumber();

    void setName(char* name);
    void setGroup(int newGroup);
    void setCourse(int newCourse);

    virtual double CountAverageMark(int session){
        return 0;
    };
    virtual double CountAverageMark(){
        return 0.0;
    };
    virtual int* operator[](int session) {
        return nullptr;
    };
    friend std::ostream& operator<<(std::ostream &out, Student &student);
    friend void PrintGroupAverageAfterFirstSession(std::vector<Student*>* group);
};