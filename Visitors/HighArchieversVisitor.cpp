#include "HighArchieversVisitor.h"
void HighArchieversVisitor::StartVisit(){
    has_students = false;
}
void HighArchieversVisitor::VisitStudent(int number, Student *a){
    std::map<std::string, int> &marks = a -> marks_;
    bool isExcellent = true;
    for (auto m : marks){
        if (m.second != 5){
            isExcellent = false;
            break;
        }
    }
    if (isExcellent){
        a -> printShort();
    }
    has_students = true;
}
void HighArchieversVisitor::finishVisit(){
    if (!has_students){
        std::cout << "No students in database" << std::endl;
    }
}
bool HighArchieversVisitor::getState(){
    bool state = has_students;
    return state;
}