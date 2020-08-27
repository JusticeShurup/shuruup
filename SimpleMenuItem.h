#ifndef _SIMPLEMENUITEM_H_
#define _SIMPLEMENUITEM_H_
#include "MenuItem.h"
#include <string>
#include <iostream>
#include <functional>
class SimpleMenuItem : public MenuItem{
    public: 
    SimpleMenuItem(std::string title, std::function<void (void)> f);
    void run() override;
    private:
    std::function<void (void)> f;
    
};
#endif