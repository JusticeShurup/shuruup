#include "Menu.h"
#include "MenuItem.h"
#include "SimpleMenuItem.h"
#include "student.h"
#include <vector>
#include <string>
#include "studentregistry.h"
#include "Visitors.h"
void test(){
    std::cout << "adad" << std::endl;
}
int main(){
    std::map<std::string, int> marks;
    marks["History"] = 5;
    std::map<std::string, int> marks1;
    marks1["Math"] = 2;
    marks1["History"] = 5;
    std::function<void (void)> f;
    f = &test;
    Menu b;
    Menu* q = b.addsubMenu("something");
    SimpleMenuItem* a = b.addItem("Start", f);
    SimpleMenuItem* c = b.addItem("Star", f);
    SimpleMenuItem* j =  q -> addItem("aq", f);
    b.run();
    Student p("Oleg", "Grishin","Fazlovich", "Gum", marks);
    Student p1("Kirill", "Machehin","Fazlovich", "Info", marks1);
    StudentRegistry *registry = StudentRegistry::getInstance();
    registry -> addStudent(&p);
    registry -> addStudent(&p1);
    registry->getStudent(0)->printLong();
    StudentVisitor *visitor;
    StudentVisitor *ArchieversVisitor;
    visitor = new BriefPrintVisitor();
    ArchieversVisitor = new HighArchieversVisitor();
    //registry -> visitStudents(visitor);
    registry -> visitStudents(ArchieversVisitor);

}
