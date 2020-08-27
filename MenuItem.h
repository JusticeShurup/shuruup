#ifndef _MENUITEM_H_
#define _MENUITEM_H_
#include <string>
#include <iostream>
class MenuItem {
    public:
    MenuItem(std::string title);
    virtual void run() = 0;
    std::string getTitle();
    void setTitle(std::string title);
    private:
    std::string title;
};
#endif