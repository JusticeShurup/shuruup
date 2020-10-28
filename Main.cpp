#include "Menu.h"
#include "MenuItem.h"
#include "SimpleMenuItem.h"
#include "student.h"
#include <vector>
#include <string>
#include "studentregistry.h"
#include "Visitors.h"
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
        Marks[subject] = mark;
    }
    Student e(Fname, Mname, Lname, Group, Marks);
    StudentRegistry::getInstance() -> addStudent(&e);
}
int main(){
    StudentRegistry *registry = StudentRegistry::getInstance();
    std::map<std::string, int> marks;
    marks["History"] = 5;
    std::map<std::string, int> marks1;
    marks1["Math"] = 2;
    marks1["History"] = 5;
    std::function<void (void)> f;
    f = &AddStudentCommand;
    std::function<void (void)> n;
    n = &ListStudentCommand;
    Menu b;
    Menu* q = b.addsubMenu("something");
    SimpleMenuItem* o = b.addItem("AddStudent", f);
    SimpleMenuItem* a = b.addItem("ListStudents", n);
    b.run();
    Student p("Oleg", "Grishin","Fazlovich", "Gum", marks);
    Student p1("Kirill", "Machehin","Fazlovich", "Info", marks1);
    registry -> addStudent(&p);
    registry -> addStudent(&p1);
    StudentVisitor *visitor;
    StudentVisitor *ArchieversVisitor;
    visitor = new BriefPrintVisitor();
    ArchieversVisitor = new HighArchieversVisitor();
    registry -> visitStudents(visitor);
    //registry -> visitStudents(ArchieversVisitor);
    return 0;
}
