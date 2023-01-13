#include "array.h"

#include <iostream>
#include <sstream>
#include <string>

Contact::Contact()
{
    this->age = 0;
    this->name = "";
    this->number = "";
}
Contact::Contact(int age, std::string name, std::string number)
{
    this->age = age;
    this->name = name;
    this->number = number;
}
int Contact::getAge()
{
    return age;
}
std::string Contact::getName()
{
    return name;
}
std::string Contact::getNumber()
{
    return number;
}
std::string Contact::toString()
{
    std::stringstream stream;
    stream << "Name: " << name << ", Age: " << age << ", Number: " << number;

    return stream.str();
}

Contact getInputContact()
{
    int age{0};
    std::string name;
    std::string number;

    std::cout << "Insert name: ";
    std::getline(std::cin, name);
    std::cin.clear();
    std::cin.sync();
    std::cout << "Insert age: ";
    std::cin >> age;
    std::cin.clear();
    std::cin.sync();
    std::cout << "Insert Number: ";
    std::getline(std::cin, number);
    std::cin.clear();
    std::cin.sync();

    return {age, name, number};
}
void initArray()
{
    Contact contacts[10];

    std::cout << "Hello, your list contacts" << std::endl;

    while (true)
    {
        int option{0};

        std::cout << "Action: " << std::endl
                  << std::endl;
        std::cout << "1. Add" << std::endl;
        std::cout << "2. Edit" << std::endl;
        std::cout << "3. Search" << std::endl;
        std::cout << "4. Show all" << std::endl;
        std::cout << "5. Exit" << std::endl
                  << std::endl;
        std::cout << "Select action: ";
        std::cin >> option;
        std::cin.clear();
        std::cin.sync();
        std::cout << std::endl;

        if (option == 1)
        {
        }
        else if (option == 2)
        {
        }
        else if (option == 3)
        {
        }
        else if (option == 4)
        {
        }
        else if (option == 5)
            break;
        else
        {
            std::cout << "Option invalid, try again" << std::endl
                      << std::endl;
        }
    }
}