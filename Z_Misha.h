#ifndef _MISHA_H_
#define _MISHA_H_
#include <iostream>
class Misha{
    public:
    static Misha *getInstance(); 
    Misha(int age, int height, int weight);
    void talk(std::string words);
    private: 
    int age; 
    int height;
    int weight;
    const std::string name;
    const std::string surname;
    const std::string patronymic;
    bool pizdatiy;
    static Misha *instance;
};
#endif
