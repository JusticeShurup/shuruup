#ifndef _BRIEF_PRINT_VISITOR_H_
#define _BRIEF_PRINT_VISITOR_H_
#include "StudentVisitor.h"
class BriefPrintVisitor : public StudentVisitor{
    public:
    void StartVisit() override;
    void VisitStudent(int number, Student *student) override;
    void finishVisit() override;
    private:
    bool has_students;
};
#endif