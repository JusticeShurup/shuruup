#ifndef _DETAILED_PRINT_VISITOR_H_
#define _DETAILED_PRINT_VISITOR_H_
#include "StudentVisitor.h"
class DetailedPrintVisitor : public StudentVisitor{ // печатает полный список студентов
    public:
    void StartVisit() override;
    void VisitStudent(int number, Student *a) override;
    void finishVisit() override;
    bool getState() override;
    private:
    bool has_students;
};
#endif