#include "HelpCommands.h"
#include "../studentregistry.h"
#include "../student.h"
#include "../EditContext.h"
#include "../Visitors.h"
void HelpCommands::selectStudentCommand(){
    int number;
    StudentVisitor *detailedprintvisitor;
    detailedprintvisitor = new DetailedPrintVisitor;
    StudentRegistry::visitStudents(detailedprintvisitor); 
    std::cout << "Select student" << std::endl;
    std::cin >> number;
    EditContext::getInstance()->student = StudentRegistry::getInstance() -> getStudent(number); 
}
void HelpCommands::showSelectedCommand(){
    EditContext::getInstance()->student.printLong(); 
}
// void HelpCommands::deselectStudentCommand(){} // в разработке 
void HelpCommands::editFirstNameCommand(){ 
    std::string name;
    std::cout << "Enter new name" << std::endl;
    std::cin >> name;
    EditContext::getInstance() -> student.first_name = name; 
}
void HelpCommands::editMiddleNameCommand(){
    std::string surname;
    std::cout << "Enter new surname" << std::endl;
    std::cin >> surname;
    EditContext::getInstance() -> student.middle_name = surname; 
}
void HelpCommands::editLastNameCommand(){ 
    std::string lastname;
    std::cout << "Enter new patronomyc" << std::endl;
    std::cin >> lastname;
    EditContext::getInstance() -> student.last_name = lastname;
}
void HelpCommands::editGroupCommand(){
    std::string group;
    std::cout << "Enter new group" << std::endl;
    std::cin >> group;
    EditContext::getInstance() -> student.group_ = group;
}
void HelpCommands::addMarkCommand(){
    std::string subject;
    int mark;
    std::cout << "Enter subject, then new mark" << std::endl;
    std::cin >> subject; std::cin >> mark;
    EditContext::getInstance() -> student.marks_[subject] = mark;
}
void HelpCommands::editMarkCommand(){
    std::string subject;
    int mark;
    EditContext::getInstance() -> student.printSubjects();
    std::cout << "Enter subject, then new mark" << std::endl;
    std::cin >> subject; std::cin >> mark;
    EditContext::getInstance() -> student.marks_[subject] = mark;
}
// void HelpCommands::deleteMarkCommand(){} // в разработке
// void HelpCommands::clearMarksCommand(){} // в разработке