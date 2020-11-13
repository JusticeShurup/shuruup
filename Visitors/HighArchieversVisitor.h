#ifndef _HIGH_ARCHIEVERS_VISITOR_H_
#define _HIGH_ARCHIEVERS_VISITOR_H_
#include "StudentVisitor.h"
class HighArchieversVisitor : public StudentVisitor{ // печатает отличников
    public:
    void StartVisit() override;
    void VisitStudent(int number, Student *student) override;
    void finishVisit() override;
    bool getState() override;
    private:
    bool has_students;
};
#endif