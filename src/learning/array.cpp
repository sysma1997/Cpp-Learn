#include "array.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

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

    return Contact{age, name, number};
}
void add(std::vector<Contact> *contacts)
{
    Contact newContact{getInputContact()};

    contacts->push_back(newContact);
}
void showAll(std::vector<Contact> *contacts)
{
    for (int i = 0; i < contacts->size(); i++)
        std::cout << contacts->at(i).toString() << std::endl;
}
void initArray()
{
    std::vector<Contact> contacts;

    std::cout << "Hello, your list contacts" << std::endl;

    while (true)
    {
        int option{0};

        std::cout << "You have " << contacts.size() << " contacts." << std::endl;
        std::cout << "Action: " << std::endl
                  << std::endl;
        std::cout << "1. Add" << std::endl;
        std::cout << "2. Show all" << std::endl;
        std::cout << "3. Exit" << std::endl
                  << std::endl;
        std::cout << "Select action: ";
        std::cin >> option;
        std::cin.clear();
        std::cin.sync();
        std::cout << std::endl;

        if (option == 1)
            add(&contacts);
        else if (option == 2)
            showAll(&contacts);
        else if (option == 3)
            break;
        else
            std::cout << "Option invalid, try again" << std::endl;

        std::cout << std::endl;
    }
}