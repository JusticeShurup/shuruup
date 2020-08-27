#include "SimpleMenuItem.h"
SimpleMenuItem::SimpleMenuItem(std::string title, std::function<void (void)> f) : MenuItem(title){
    this -> f = f;
}
void SimpleMenuItem::run(){
    f();
}