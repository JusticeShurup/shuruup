#include "BriefPrintVisitor.h"
void BriefPrintVisitor::StartVisit(){
    has_students = false;
}
void BriefPrintVisitor::VisitStudent(int number, Student *a){
    std::cout << number + 1 << " ";
    a -> printShort();
    has_students = true;
}
bool BriefPrintVisitor::getState(){
    bool state = has_students;
    return state;
}
void BriefPrintVisitor::finishVisit(){
    if (!has_students){
        std::cout << "No students in database" << std::endl;
    }
}