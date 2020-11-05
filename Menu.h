#include "MenuItem.h"
#include "SimpleMenuItem.h"
#include <iostream>
#include <vector>
#ifndef _MENU_H_
#define _MENU_H_
class Menu : public MenuItem {
    public: 
    Menu();
    void setStartupCommand(std::function<void(void)> command);
    void setBeforeSelectCommand(std::function<void(void)> command);
    void setTearDownCommand(std::function<void(void)> command);
    void run() override;
    void printMenu();
    bool check(); //Проверка на выход из меню
    Menu* addsubMenu(std::string title);
    SimpleMenuItem* addItem(std::string title, std::function<void (void)> f);
    private:
    std::function<void (void)> startup_command;
    std::function<void (void)> before_select_command;
    std::function<void (void)> tear_down_command;
    Menu(std::string title);
    std::vector<MenuItem *> listOfMenuItem;
    bool isSubMenu;
};
#endif