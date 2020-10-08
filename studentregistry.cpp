#include "studentregistry.h"
#include "student.h"
StudentRegistry::StudentRegistry(){}
void StudentRegistry::addStudent(Student *a){
    students.push_back(*a);
}
void StudentRegistry::removeStudent(Student *a){
    bool flag = true; 
    for(int i = 0; i < students.size(); i++){
        flag = true;
        if (a -> getFname() != students[i].getFname())
            flag = false;
        if (a -> getMname() != students[i].getMname())
            flag = false;
        if (a -> getLname() != students[i].getLname())
            flag = false;
        if (a -> getGroup() != students[i].getGroup())
            flag = false;
        if (a -> getMarks() != students[i].getMarks())
            flag = false;
        if (flag)
            students.erase(students.begin()+i);
    }   
}
void StudentRegistry::removeStudent(int index){
    students.erase(students.begin()+index);
}

