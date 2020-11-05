#include "Menu.h"
#include "MenuItem.h"
#include "SimpleMenuItem.h"
#include "student.h"
#include <vector>
#include <string>
#include "studentregistry.h"
#include "Visitors.h"
#include <stdexcept>
#include "Commands.h"
int main(){
    UpperCommands u;
    StudentRegistry *registry = StudentRegistry::getInstance();
    std::map<std::string, int> marks;
    marks["History"] = 5;
    std::map<std::string, int> marks1;
    marks1["Math"] = 2;
    marks1["History"] = 5;
    Student p("Oleg", "Grishin","Fazlovich", "Gum", marks);
    registry -> addStudent(&p);
    std::function<void (void)> f = UpperCommands::addStudentCommand;
    std::function<void (void)> f1 = UpperCommands::listStudentCommand;
    std::function<void (void)> f2 = UpperCommands::deleteStudentCommand;
    std::function<void (void)> f3 = UpperCommands::showHighArchieversCommand;
    std::function<void (void)> f4 = UpperCommands::showLowArchieversCommand;
    Menu b;
    Menu* q = b.addsubMenu("UpperCommands");
    SimpleMenuItem* o = q -> addItem("AddStudent", f);
    SimpleMenuItem* a = q -> addItem("ListStudents", f1);
    SimpleMenuItem* a1 = q -> addItem("DeleteStudent", f2);
    SimpleMenuItem* a2 = q -> addItem("HighArchievers", f3);
    SimpleMenuItem* a3 = q -> addItem("LowArchievers", f4);
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
