#include "Misha.h"
 Misha *Misha::instance = nullptr;
Misha *Misha::getInstance(){
  if (!Misha::instance) {
    Misha::instance = new StudentRegistry;
  }
  return StudentRegistry::instance;
}
Misha::Misha(int age, int height, int weight){
    this->age = age;
    this->height = height;
    this->weight = weight;
    pizdatiy = true;
    name = "Michail"; surname = "Grishin"; patronymic = "Grigorievich";
}
void::talk(std::string words){
    std::cout << "Misha say" << words << std::endl;
}
 
