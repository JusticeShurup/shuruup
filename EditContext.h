#ifndef _EDIT_CONTEXT_H_
#define _EDIT_CONTEXT_H_
#include "student.h"
class EditContext{
    public:
    static EditContext *getInstance();
    Student student;
    private:
    EditContext();
    static EditContext *instance;
};
#endif