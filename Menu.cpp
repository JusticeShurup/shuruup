#include "Menu.h"
#include <stdexcept>
Menu::Menu(std::string title) : MenuItem(title){
    isSubMenu = true;
}
Menu::Menu() : MenuItem(""){
    isSubMenu = false;
}
void Menu::printMenu(){
    std::cout << getTitle() << std::endl; 
    for (int i = 0; i < listOfMenuItem.size(); i++){
        std::cout << (i + 1) << ". " << listOfMenuItem[i] -> getTitle() << std::endl;    
    }
    if(isSubMenu){
        std::cout << listOfMenuItem.size() + 1 << ". Back" << std::endl;
    }else
        std::cout << listOfMenuItem.size() + 1 << ". Exit" << std::endl;
    
}
Menu* Menu::addsubMenu(std::string title){
    Menu* a = new Menu(title);
    listOfMenuItem.push_back(a);
    return a;
}
SimpleMenuItem* Menu::addItem(std::string title, std::function<void (void)> f){
    SimpleMenuItem* b = new SimpleMenuItem(title, f);
    listOfMenuItem.push_back(b);
    return b;
}
bool Menu::check(){
    int x;
    std::cin >> x;
    if (x == listOfMenuItem.size() + 1) return false;
    if (x > listOfMenuItem.size()){
        throw std::out_of_range("Incorrect number");
    }else if( x >= 0 && x <= listOfMenuItem.size()){
        listOfMenuItem[x-1] -> run();
    }
    return true;
}
void Menu::run(){
    bool flag = true;
    while(flag){
        printMenu();
        flag = check();
    }
}
void Menu::setStartupCommand(std::function<void (void)> command){
    startup_command = &command;
}
void Menu::setBeforeSelectCommand(std::function<void (void)> command){
    before_select_command = &command;  
} 
void Menu::setTearDownCommand(std::function<void (void)> command){
    tear_down_command = &command;
}