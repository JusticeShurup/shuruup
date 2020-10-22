#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <iostream>
#include <string>
#include <map>
class Student{
    public:
    Student(std::string firstname, std::string middlename, std::string lastname, std::string group, std::map<std::string, int> marks);
    void printLong();
    void printShort();
    void printSubjects();
    std::string first_name;
    std::string middle_name;
    std::string last_name;
    std::string group_;
    std::map<std::string, int> marks_;
};
#endif