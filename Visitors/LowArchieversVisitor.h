#ifndef _LOW_ARCHIEVERS_VISITOR_H_
#define _LOW_ARCHIEVERS_VISITOR_H_
#include "StudentVisitor.h"
class LowArchieversVisitor : public StudentVisitor{ // Печатает неуспевающих
    public:
    void StartVisit() override;
    void VisitStudent(int number, Student *student) override;
    void finishVisit() override;
    private:
    bool has_students;
};
#endif