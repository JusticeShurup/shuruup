#include "LowArchieversVisitor.h"
void LowArchieversVisitor::StartVisit(){
    has_students = false;
}
void LowArchieversVisitor::VisitStudent(int number, Student *a){
    std::map<std::string, int> &marks = a -> marks_;
    bool isExcellent = true;
    for (auto m : marks){
        if(m.second == 2){
            isExcellent = false;
            break;
        }
    }
    if (!isExcellent){
        a -> printShort();
    }
    has_students = true;
}
void LowArchieversVisitor::finishVisit(){
    if (!has_students){
        std::cout << "No students in database" << std::endl;
    }
}