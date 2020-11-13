#include "MenuItem.h"
#include "SimpleMenuItem.h"
#include <iostream>
#include <vector>
#ifndef _MENU_H_
#define _MENU_H_
class Menu : public MenuItem {
    public: 
    Menu();
    void setStartupCommand(std::function<bool(void)> command);
    void setBeforeSelectCommand(std::function<void(void)> command);
    void setTearDownCommand(std::function<void(void)> command);
    void run() override;
    void printMenu();
    bool check(); //Проверка на выход из меню
    Menu* addsubMenu(std::string title);
    SimpleMenuItem* addItem(std::string title, std::function<void (void)> f);
    private:
    std::function<bool (void)> startup_command = nullptr;
    std::function<void (void)> before_select_command = nullptr;
    std::function<void (void)> tear_down_command = nullptr;
    Menu(std::string title);
    std::vector<MenuItem *> listOfMenuItem;
    bool isSubMenu;
};
#endif