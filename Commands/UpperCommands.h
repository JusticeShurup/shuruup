#ifndef _UPPER_COMMANDS_H_
#define _UPPER_COMMANDS_H_
#include "../studentregistry.h"
#include "../student.h"
#include "../Visitors.h"
class UpperCommands{
    public:
    static void listStudentCommand();
    static void addStudentCommand();
    static void deleteStudentCommand();
    static void showHighArchieversCommand();
    static void showLowArchieversCommand();
};
#endif