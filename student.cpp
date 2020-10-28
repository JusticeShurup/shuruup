#include "student.h"
Student::Student(std::string firstname, std::string middlename, std::string lastname, std::string group, std::map<std::string, int> marks){
    first_name = firstname;
    middle_name = middlename;
    last_name = lastname;
    group_ = group;
    marks_ = marks;
}
void Student::printLong(){
    printShort();
    std::cout << group_ << " ";
    printSubjects();
}
void Student::printShort(){
    std::cout << first_name << " ";
    std::cout << middle_name << " ";
    std::cout << last_name << std::endl;
}
void Student::printSubjects(){
    for (auto m : marks_){
        std::cout << m.first << " " << m.second << std::endl;
    }
}