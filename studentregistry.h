#ifndef _STUDENTREGISTRY_H_
#define _STUDENTREGISTRY_H_
#include <iostream>
#include <vector>
#include "student.h"
class StudentRegistry{
public:
    static StudentRegistry *getInstance();
    StudentRegistry();
    void addStudent(Student *a);
    void removeStudent(Student *a);
    void removeStudent(int number);
    Student* getStudent(int number);
    int getStudentCount();
private:
    static StudentRegistry *instance;
    std::vector<Student> students;
};
#endif