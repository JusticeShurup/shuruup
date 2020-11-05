#ifndef _STUDENTREGISTRY_H_
#define _STUDENTREGISTRY_H_
#include <iostream>
#include <vector>
#include "student.h"
#include "Visitors.h"
class StudentRegistry{ // StudentRegistry
    public:
    static StudentRegistry *getInstance();
    StudentRegistry();
    void addStudent(Student *a);
    void removeStudent(Student *a);
    void removeStudent(int number);
    Student* getStudent(int number);
    int getStudentCount();
    void visitStudents(StudentVisitor *);
    private:
    static StudentRegistry *instance;
    std::vector<Student *> students;
};
#endif