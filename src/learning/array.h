#pragma once
#include <iostream>
#include <string>

class ContactArray
{
    int age;
    std::string name;
    std::string number;

public:
    ContactArray();
    ContactArray(int age, std::string name, std::string number);

    int getAge();
    std::string getName();
    std::string getNumber();

    std::string toString();
};

void initArray();