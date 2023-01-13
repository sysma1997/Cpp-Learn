#pragma once
#include <iostream>
#include <string>

class Contact
{
private:
    int age;
    std::string name;
    std::string number;

public:
    Contact();
    Contact(int age, std::string name, std::string number);

    int getAge();
    std::string getName();
    std::string getNumber();

    std::string toString();
};

void initArray();