#pragma once

#include <iostream>
#include <string>
#include <json/json.h>

class Contact
{
    int id;
    std::string name;
    std::string email;
    std::string phone;

public:
    Contact();
    Contact(int id, std::string name, std::string email, std::string phone);

    int getId();
    std::string getName();
    std::string getEmail();
    std::string getPhone();

    Json::Value toJSON();
    std::string toString();
};