#include "MenuItem.h" 
#include <iostream>
MenuItem::MenuItem(std::string title){
    this -> title = title;
}
std::string MenuItem::getTitle(){
    return title;
}
void MenuItem::setTitle(std::string title){
    this -> title = title;
}

