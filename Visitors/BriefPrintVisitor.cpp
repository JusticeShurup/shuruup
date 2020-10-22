#include "BriefPrintVisitor.h"
void BriefPrintVisitor::StartVisit(){
    has_students = false;
}
void BriefPrintVisitor::VisitStudent(int number, Student *a){
    std::cout << number << " " << std::endl;
    a -> printShort();
    has_students = true;
}
void BriefPrintVisitor::finishVisit(){
    if (!has_students){
        std::cout << "No students in database" << std::endl;
    }
}