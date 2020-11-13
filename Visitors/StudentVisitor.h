#ifndef _STUDENTVISITOR_H_
#define _STUDENTVISITOR_H_
#include "../student.h"
class StudentVisitor{ 
    public:
    virtual void StartVisit() = 0;
    virtual void VisitStudent(int number, Student *student) = 0;
    virtual void finishVisit() = 0;
    virtual bool getState() = 0;
};
#endif