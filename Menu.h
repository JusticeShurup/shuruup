#include "MenuItem.h"
#include "SimpleMenuItem.h"
#include <iostream>
#include <vector>
#ifndef _MENU_H_
#define _MENU_H_
class Menu : public MenuItem {
    public: 
    Menu();
    void run() override;
    void printMenu();
    bool check(); //Проверка на выход из меню
    Menu* addsubMenu(std::string title);
    SimpleMenuItem* addItem(std::string title, std::function<void (void)> f);
    private:
    Menu(std::string title);
    std::vector<MenuItem *> listOfMenuItem;
    bool isSubMenu;
};
#endif