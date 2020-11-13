#include "Menu.h"
#include "MenuItem.h"
#include "EditContext.h"
#include "SimpleMenuItem.h"
#include "student.h"
#include <vector>
#include <string>
#include "studentregistry.h"
#include "Visitors.h"
#include <stdexcept>
#include "Commands.h"
int main(){
    StudentRegistry *registry = StudentRegistry::getInstance();
    EditContext *context = EditContext::getInstance();
    Menu b;
    Menu* q = b.addsubMenu("UpperCommands");
    Menu* q1 = b.addsubMenu("HelpCommands");
    std::function<bool(void)> h1 = HelpCommands::selectStudentCommand;
    //Команды без EditContext
    SimpleMenuItem* o = q -> addItem("Add student", UpperCommands::addStudentCommand);
    SimpleMenuItem* a = q -> addItem("List of students", UpperCommands::listStudentCommand);
    SimpleMenuItem* a1 = q -> addItem("Delete student", UpperCommands::deleteStudentCommand);
    SimpleMenuItem* a2 = q -> addItem("HighArchievers", UpperCommands::showHighArchieversCommand);
    SimpleMenuItem* a3 = q -> addItem("LowArchievers", UpperCommands::showLowArchieversCommand);
    //Команды с EditContext
    // std::function<void(void)> h2 = HelpCommands::showSelectedCommand; SimpleMenuItem* a5 = q1->addItem("Show selected student", h2);
    // std::function<void(void)> h3 = HelpCommands::deselectStudentCommand; SimpleMenuItem* a6 = q1->addItem("Deselect student", h3);
    SimpleMenuItem* a7 = q1->addItem("Edit first name student", HelpCommands::editFirstNameCommand);
    SimpleMenuItem* a8 = q1->addItem("Edit surname", HelpCommands::editMiddleNameCommand);
    SimpleMenuItem* a9 = q1->addItem("Edit patronymic", HelpCommands::editLastNameCommand);
    SimpleMenuItem* a10 = q1->addItem("Edit group", HelpCommands::editGroupCommand);
    SimpleMenuItem* a11 = q1->addItem("Edit Mark", HelpCommands::editMarkCommand);
    SimpleMenuItem* a12 = q1->addItem("Add mark", HelpCommands::addMarkCommand);
    SimpleMenuItem* a13 = q1->addItem("Delete mark", HelpCommands::deleteMarkCommand);
    SimpleMenuItem* a14 = q1->addItem("Clear marks", HelpCommands::clearMarksCommand);
    q1->setStartupCommand(h1);
    b.run();
    return 0;
}
