#include "DetailedPrintVisitor.h"
void DetailedPrintVisitor::StartVisit(){
    has_students = false;
}
void DetailedPrintVisitor::VisitStudent(int number, Student *a){
    std::cout << number << " " << std::endl;
    a -> printLong();
    has_students = true;
}
void DetailedPrintVisitor::finishVisit(){
    if (!has_students){
        std::cout << "No students in database" << std::endl;
    }
}