#include "DetailedPrintVisitor.h"
void DetailedPrintVisitor::StartVisit(){
    has_students = false;
}
void DetailedPrintVisitor::VisitStudent(int number, Student *b){
    std::cout << number + 1 << " ";
    b -> printLong();
    has_students = true;
}
void DetailedPrintVisitor::finishVisit(){
    if (!has_students){
        std::cout << "No students in database" << std::endl;
    }
}
bool DetailedPrintVisitor::getState(){
    bool state = has_students;
    return state;
}