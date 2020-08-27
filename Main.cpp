#include "Menu.h"
#include "MenuItem.h"
#include "SimpleMenuItem.h"
#include <vector>
#include <string>
void test(){
    std::cout << "adad";
}
int main(){
    std::function<void (void)> f;
    std::function<void (void)> n;
    f = &test;
    SimpleMenuItem z("Star", n);
    Menu b;
    Menu* q = b.addsubMenu("something");
    SimpleMenuItem* a = b.addItem("Start", f);
    SimpleMenuItem* c = b.addItem("Star", n);
    SimpleMenuItem* j =  q -> addItem("aq", f);
    b.run();
}
