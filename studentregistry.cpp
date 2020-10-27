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
    for(int i = 0; i < students.size(); i++){
        if (a-> first_name == students[i]-> first_name && a->middle_name == students[i]-> middle_name 
        && a -> last_name == students[i] -> last_name && a -> group_ == students[i] -> group_ && a -> marks_ == students[i] -> marks_){
          students.erase(students.begin() + i);
      }
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

