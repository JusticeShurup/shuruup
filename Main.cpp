#include "Menu.h"
#include "MenuItem.h"
#include "SimpleMenuItem.h"
#include "student.h"
#include <vector>
#include <string>
#include "studentregistry.h"
#include "Visitors.h"
#include <stdexcept>
void ListStudentCommand(){
    StudentVisitor *v;
    v = new DetailedPrintVisitor;
    StudentRegistry::getInstance() -> visitStudents(v);
}
void AddStudentCommand(){
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
void DeleteStudentCommand(){
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
void ShowHighArchieversCommand(){
    StudentVisitor *archieversvisitor;
    archieversvisitor = new HighArchieversVisitor();
    StudentRegistry::getInstance() -> visitStudents(archieversvisitor);
}
void ShowLowArchieversCommand(){
    StudentVisitor *archieversvisitor;
    archieversvisitor = new LowArchieversVisitor();
    StudentRegistry::getInstance() -> visitStudents(archieversvisitor);
}
int main(){
    StudentRegistry *registry = StudentRegistry::getInstance();
    std::map<std::string, int> marks;
    marks["History"] = 5;
    std::map<std::string, int> marks1;
    marks1["Math"] = 2;
    marks1["History"] = 5;
    Student p("Oleg", "Grishin","Fazlovich", "Gum", marks);
    registry -> addStudent(&p);
    std::function<void (void)> f;
    f = &AddStudentCommand;
    std::function<void (void)> f1;
    f1 = &DeleteStudentCommand;
    std::function<void (void)> n;
    n = &ListStudentCommand;
    std::function<void (void)> f2;
    f2 = &ShowHighArchieversCommand;
    std::function<void (void)> f3;
    f3 = &ShowLowArchieversCommand;
    Menu b;
    Menu* q = b.addsubMenu("something");
    SimpleMenuItem* o = b.addItem("AddStudent", f);
    SimpleMenuItem* a = b.addItem("ListStudents", n);
    SimpleMenuItem* a1 = b.addItem("DeleteStudent", f1);
    SimpleMenuItem* a2 = b.addItem("HighArchievers", f2);
    SimpleMenuItem* a3 = b.addItem("LowArchievers", f3);
    b.run();
    Student p1("Kirill", "Machehin","Fazlovich", "Info", marks1);
    registry -> addStudent(&p1);
    StudentVisitor *ArchieversVisitor;
    StudentVisitor *visitor;
    visitor = new BriefPrintVisitor();
    ArchieversVisitor = new HighArchieversVisitor();
    registry -> visitStudents(visitor);
    //registry -> visitStudents(ArchieversVisitor);
    return 0;
}
