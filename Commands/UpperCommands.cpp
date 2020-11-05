#include "UpperCommands.h"
#include "../studentregistry.h"
#include "../student.h"
#include "../Visitors.h"
void UpperCommands::listStudentCommand(){
    StudentVisitor *v;
    v = new DetailedPrintVisitor;
    StudentRegistry::getInstance() -> visitStudents(v);
}
void UpperCommands::addStudentCommand(){
    bool flag = true;
    std::string Fname; // Имя
    std::string Mname; // Фамилия 
    std::string Lname; // Отчество 
    std::string Group; // Группа 
    std::map<std::string, int> Marks; // Оценки
    std::string subject;
    int mark;
    std::cout << "Enter name" << std::endl;
    std::cin >> Fname;
    std::cout << "Enter surname" << std::endl;
    std::cin >> Mname;
    std::cout << "Enter patronymic" << std::endl;
    std::cin >> Lname;
    std::cout << "Enter group" << std::endl;
    std::cin >> Group;
    while(flag){
        std::cout << "Enter marks. First subject, then mark or enter exit" << std::endl;
        std::cin >> subject;
        if (subject == "exit" || subject == "Exit" || subject == " "){
            flag = false; 
            break;
        }
        std::cin >> mark;
        while(mark != 2 && mark != 3 && mark != 4 && mark != 5){
            std::cout << "out of range, try again" << std::endl;
            std::cin >> mark;
        }
        Marks[subject] = mark;
    }
    Student *e;
    e = new Student(Fname, Mname, Lname, Group, Marks);
    StudentRegistry::getInstance() -> addStudent(e);
}
void UpperCommands::deleteStudentCommand(){
    StudentVisitor *bprintvisitor;
    StudentVisitor *dprintvisitor;
    bprintvisitor = new BriefPrintVisitor(); // Visitor для 1 метода удаления
    dprintvisitor = new DetailedPrintVisitor(); // Visitor для 2 метода удаления
    int number;
    std::cout << "How will you delete?" << std::endl;
    std::cout << "1. Student number" << std::endl;
    std::cout << "2. Student data" << std::endl;
    std::cin >> number;
    while(number != 1 && number != 2){
        std::cout << "There is no such option. Enter again" << std::endl;
        std::cin >> number;
    } 
    if (number == 1){
        StudentRegistry::getInstance() -> visitStudents(bprintvisitor); // печать краткого списка для выбора
        std::cout << "Enter student number" << std::endl;
        std::cin >> number;
        StudentRegistry::getInstance() -> removeStudent(number);
    }else{
        StudentRegistry::getInstance() -> visitStudents(dprintvisitor); // печать полного списка 
        std::string Fname; // Имя
        std::string Mname; // Фамилия 
        std::string Lname; // Отчество 
        std::string Group; // Группа 
        std::map<std::string, int> Marks; // Оценки
        std::cout << "Enter name" << std::endl;
        std::cin >> Fname;
        std::cout << "Enter surname" << std::endl;
        std::cin >> Mname;
        std::cout << "Enter patronymic" << std::endl;
        std::cin >> Lname;
        std::cout << "Enter group" << std::endl;
        std::cin >> Group;
        Student *e;
        e = new Student(Fname, Mname, Lname, Group, Marks);
        StudentRegistry::getInstance() -> removeStudent(e);
    }
}
void UpperCommands::showHighArchieversCommand(){
    StudentVisitor *archieversvisitor;
    archieversvisitor = new HighArchieversVisitor();
    StudentRegistry::getInstance() -> visitStudents(archieversvisitor);
}
void UpperCommands::showLowArchieversCommand(){
    StudentVisitor *archieversvisitor;
    archieversvisitor = new LowArchieversVisitor();
    StudentRegistry::getInstance() -> visitStudents(archieversvisitor);
}