#include "HelpCommands.h"
#include "../studentregistry.h"
#include "../student.h"
#include "../EditContext.h"
#include "../Visitors.h"
bool HelpCommands::selectStudentCommand(){
    int number;
    StudentVisitor *detailedprintvisitor;
    detailedprintvisitor = new DetailedPrintVisitor;
    StudentRegistry::getInstance()->visitStudents(detailedprintvisitor);
    if (!detailedprintvisitor->getState()){
        std::cout << "You will return in submenu" << std::endl;
        return false;
    }else{ 
        std::cout << "Select student" << std::endl;
        std::cin >> number;
        if(number > StudentRegistry::getInstance()->getStudentCount()){
            std::cout << "Incorrect number" << std::endl;
            return false;
        }else{
            EditContext::getInstance()->student = StudentRegistry::getInstance()->getStudent(number - 1);
            return true;
        }
    }
}
void HelpCommands::showSelectedCommand(){
    EditContext::getInstance()->student->printLong();
}
void HelpCommands::deselectStudentCommand(){
    EditContext::getInstance()->student = nullptr;
}
void HelpCommands::editFirstNameCommand(){ 
    std::string name;
    std::cout << "Enter new name" << std::endl;
    std::cin >> name;
    EditContext::getInstance()->student->first_name = name; 
}
void HelpCommands::editMiddleNameCommand(){
    std::string surname;
    std::cout << "Enter new surname" << std::endl;
    std::cin >> surname;
    EditContext::getInstance()->student->middle_name = surname; 
}
void HelpCommands::editLastNameCommand(){ 
    std::string lastname;
    std::cout << "Enter new patronomyc" << std::endl;
    std::cin >> lastname;
    EditContext::getInstance()->student->last_name = lastname;
}
void HelpCommands::editGroupCommand(){
    std::string group;
    std::cout << "Enter new group" << std::endl;
    std::cin >> group;
    EditContext::getInstance()->student->group_ = group;
}
void HelpCommands::addMarkCommand(){
    std::string subject;
    int mark;
    std::cout << "Enter subject, then new mark" << std::endl;
    std::cin >> subject; std::cin >> mark;
    EditContext::getInstance()->student->marks_[subject] = mark;
}
void HelpCommands::editMarkCommand(){
    std::string subject;
    int mark;
    bool flag = false;
    EditContext::getInstance() -> student -> printSubjects();
    std::cout << "Enter subject, then new mark" << std::endl;
    std::cin >> subject; std::cin >> mark;
    for(auto m : EditContext::getInstance()->student->marks_){
        if (m.first == subject){
            flag = true;
        }
    }
    if (flag){
        EditContext::getInstance()->student->marks_[subject] = mark;
    }else{
        std::cout << "Has no subject" << std::endl;
    }
    
}
void HelpCommands::deleteMarkCommand(){
    std::string subject;
    int mark;
    std::cout << "Enter subject, then mark" << std::endl;
    std::cin >> subject; std::cin >> mark;
    // EditContext::getInstance()->student->marks_.erase(subject, mark);
    for(auto it = EditContext::getInstance()->student->marks_.begin(); it != EditContext::getInstance()->student->marks_.end(); ) {
        if(it->first  == subject && it -> second == mark)
            it = EditContext::getInstance()->student->marks_.erase(it);
        else
            ++it;
    }
}
void HelpCommands::clearMarksCommand(){
    EditContext::getInstance()->student->marks_.clear();
} 