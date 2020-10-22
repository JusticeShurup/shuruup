#include "studentregistry.h"
#include "student.h"
#include "Visitors.h"
#include <stdexcept>
StudentRegistry *StudentRegistry::instance = nullptr;
StudentRegistry::StudentRegistry(){}
void StudentRegistry::addStudent(Student *a){
    students.push_back(a);
}
void StudentRegistry::removeStudent(Student *a){
    bool flag = true; 
    for(int i = 0; i < students.size(); i++){
        flag = true;
        if (a -> getFname() != students[i] -> getFname())
            flag = false;
        if (a -> getMname() != students[i] -> getMname())
            flag = false;
        if (a -> getLname() != students[i] -> getLname())
            flag = false;
        if (a -> getGroup() != students[i] -> getGroup())
            flag = false;
        if (a -> getMarks() != students[i] -> getMarks())
            flag = false;
        if (flag)
            students.erase(students.begin()+i);
    }   
}
StudentRegistry *StudentRegistry::getInstance(){
  if (!StudentRegistry::instance) {
    StudentRegistry::instance = new StudentRegistry;
  }
  return StudentRegistry::instance;
}
Student* StudentRegistry::getStudent(int index){
    if (index > students.size()) throw std::out_of_range("This student doesn't exist");
    return students[index];
}
int StudentRegistry::getStudentCount(){
    return students.size();
}
void StudentRegistry::removeStudent(int index){
    students.erase(students.begin()+index);
}
void StudentRegistry::visitStudents(StudentVisitor *visitor) {
  visitor->StartVisit();
  for (int i = 0; i < students.size(); i++) {
    visitor->VisitStudent(i, students[i]);
  }
  visitor->finishVisit();
}

