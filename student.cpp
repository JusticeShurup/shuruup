#include "student.h"
Student::Student(std::string firstname, std::string middlename, std::string lastname, std::string group, std::map<std::string, int> marks){
    first_name = firstname;
    middle_name = middlename;
    last_name = lastname;
    group_ = group;
    marks_ = marks;
}
void Student::printLong(){
    std::cout << first_name << std::endl;
    std::cout << middle_name << std::endl;
    std::cout << last_name << std::endl;
    std::cout << group_ << std::endl;
    for (auto m : marks_){
        std::cout << m.first << " " << m.second << std::endl;
    }
}
void Student::printShort(){
    std::cout << first_name << std::endl;
    std::cout << middle_name << std::endl;
    std::cout << last_name << std::endl;
}
void Student::printSubjects(){
    for (auto m : marks_){
        std::cout << m.first << " " << m.second << std::endl;
    }
}
std::string Student::getFname(){
    return first_name;
}
std::string Student::getMname(){
    return middle_name;
}
std::string Student::getLname(){
    return last_name;
}
std::string Student::getGroup(){
    return group_;
}
std::map<std::string, int> Student::getMarks(){
    return marks_;
}